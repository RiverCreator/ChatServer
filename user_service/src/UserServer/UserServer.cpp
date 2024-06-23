#include "UserServer.h"

using namespace placeholders;

#define BUFF_SIZE 128

UserServer::UserServer(string& ip, int port, std::string& config) : stub_(new MyRpcChannel),friend_stub_(new MyRpcChannel),server_(ip, port, 4),threadpool_(3,"redis_worker")
{
    ip_ = ip;
    port_ = port;
    
    pool_ = Connect_pool::get_instance(config);
    bool ret=redis_client_.connect();
    if (nullptr == pool_)
    {
        rj_log::LogRequest request;
        request.set_name("UserServer");
        request.set_msg("create mysql pool error");
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
    if(!ret){
        rj_log::LogRequest request;
        request.set_name("UserServer");
        request.set_msg("create redis channel error");
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

void UserServer::run()
{
    //初始化网络层

    server_.setonmessagecb(bind(&UserServer::msg_callback, this, _1, _2));
    server_.setnewconnectioncb(bind(&UserServer::conn_callback, this, _1));

    //注册zookeeper节点
    ZkClient zk_client;
    zk_client.Start();
    string server_path = "/UserService";
    zk_client.Create(server_path.c_str(), nullptr, 0);
    server_path += "/server";
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "%s:%d", ip_.c_str(), port_);
    zk_client.Create(server_path.c_str(), buffer, strlen(buffer), ZOO_SEQUENCE);
    //开启事件循环
    server_.start();
}

//连接事件回调函数
void UserServer::msg_callback(const spConnection conn, std::string& message)
{
    //反序列化由UserService传过来的序列化数据
    LOG_INFO("come message!");
    rj_UserServer::Request request;
    request.ParseFromString(message);
    LOG_INFO<<request.type();
    //登录业务
    if (request.type() == "Login")
    {
        // 反序列化数据得到 id、password
        rj_UserServer::LoginRequest login_request;
        login_request.ParseFromString(request.request());
        int id = login_request.id();
        string password = login_request.password();

        //执行具体的Login方法，执行成功is_success被设置为true
        rj_UserServer::LoginResponse login_response;
        if (Login(id, password) == true)
        {
            login_response.set_is_success(true);
            //将朋友列表缓存到redis上。
            threadpool_.addtask(std::bind(&UserServer::UpdateRedis,this, id ,0));
        }
        else
        {
            login_response.set_is_success(false);
            rj_UserServer::ErrorMsg *msg = login_response.mutable_msg();
            msg->set_message("login error");
        }
        //序列化结果 并将结果返回
        string send = login_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "Register")  //注册业务
    {
        rj_UserServer::RegisterRequest register_request;
        register_request.ParseFromString(request.request());
        string name = register_request.name();
        string password = register_request.password();
        LOG_INFO<<name<<" "<<password;
        rj_UserServer::RegisterResponse register_response;
        int id = Register(name, password);
        if (id < 0)
        {
            register_response.set_is_success(false);
        }
        else
        {
            register_response.set_is_success(true);
            register_response.set_id(id);
        }
        string send = register_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "LogOut")  //注销业务
    {
        rj_UserServer::LogOutRequest out_request;
        out_request.ParseFromString(request.request());
        int id = out_request.id();
        LOG_INFO<<"LogOut:"<<id;
        LogOut(id);

        threadpool_.addtask(std::bind(&UserServer::UpdateRedis,this, id ,1));
    }
    else //其他业务，这里是没有，所以向LogServer服务器打印一条日志信息
    {
        rj_log::LogRequest request;
        request.set_name("UserServer");
        string message = "UserServer:";
        message += ip_.c_str();
        message += " not have this service!";
        request.set_msg(message);
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

//连接事件回调函数
void UserServer::conn_callback(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}

//登录
bool UserServer::Login(int id, string password)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select * from User where id=%d and password='%s'", id, password.c_str());
    MYSQL_RES *res = conn->query(sql);
    if (res == nullptr)
    {
        mysql_free_result(res);
        return false;
    }
    else
    {
        //释放结果，否则会失败
        mysql_free_result(res);
        //更新用户状态为在线
        memset(sql, 0, BUFF_SIZE);
        sprintf(sql, "update User set state='online' where id=%d;", id);
        if (false == conn->update(sql))
        {
            rj_log::LogRequest request;
            request.set_name("UserServer");
            request.set_msg(sql, strlen(sql));
            google::protobuf::Empty response;
            stub_.Log_ERROR(nullptr, &request, &response, nullptr);
            return false;
        }
        return true;
    }
}

//注销
void UserServer::LogOut(int id)
{
    //更新数据库User 状态为offline
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "update User set state='offline' where id=%d", id);
    LOG_INFO(sql);
    conn->update(sql);
}

//注册 成功返回注册的账户，失败返回-1
int UserServer::Register(string name, string password)
{
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into User(name,password) values('%s','%s')", name.c_str(), password.c_str());
    //cout << sql << endl;
    if (false == conn->update(sql))
    {
        rj_log::LogRequest request;
        request.set_name("UserServer");
        request.set_msg(sql, strlen(sql));
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &request, &em, nullptr);
        return false;
    }
    return mysql_insert_id(conn->get_connect());
}

//type 0 add 1 del
void UserServer::UpdateRedis(int id, int type){
    //从mysql上获得朋友列表
    if(type==0){
        shared_ptr<Connect> conn = pool_->get_connect();

        char sql[BUFF_SIZE] = {0};
        sprintf(sql, "select User.id,User.name from Friend,User where Friend.userid=%d and User.id=Friend.friendid",id);
        MYSQL_RES *res = conn->query(sql);
        vector<pair<int,string>> rec;
        if(res){ //查询结果不为空
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))!=NULL)
            {
                rec.emplace_back(atoi(row[0]),row[1]);
            }
            mysql_free_result(res);
        }
        LOG_WAR("login add friend list on redis?");
        redis_client_.add_friend_list(id, rec);
    }
    else{
        //删除好友列表
        if(!redis_client_.del_friend_list(id)){
            rj_log::LogRequest request;
            request.set_name("UserServer");
            char tmp[BUFF_SIZE];
            sprintf(tmp,"Del %d's friend list failed",id);
            request.set_msg(tmp);
            google::protobuf::Empty em;
            stub_.Log_ERROR(nullptr, &request, &em, nullptr);
        }
        
    }
}