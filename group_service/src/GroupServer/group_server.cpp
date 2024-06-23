#include "group_server.h"

#define BUFF_SIZE 128

using namespace placeholders;

//初始化server信息
GroupServer::GroupServer(string ip, int port, string config_name):ip_(ip),port_(port),server_(ip,port,4)
{
    ip_ = ip;
    port_ = port;

    pool_ = Connect_pool::get_instance(config_name);
}

//开始运行服务
void GroupServer::run()
{

    //连接事件回调函数，读写事件回调函数
    server_.setonmessagecb(bind(&GroupServer::on_message, this, _1, _2));
    server_.setnewconnectioncb(bind(&GroupServer::on_connet, this, _1));

    zk_client_.Start();
    string server_path = "/GroupService";
    zk_client_.Create(server_path.c_str(), nullptr, 0);
    server_path += "/server";
    string host = ip_ + ":" + to_string(port_);
    zk_client_.Create(server_path.c_str(), host.c_str(), host.size(), ZOO_SEQUENCE);

    server_.start();
}

//绑定连接事件
void GroupServer::on_connet(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}

//绑定连接读写事件
void GroupServer::on_message(const spConnection conn, std::string& recv_str)
{
    //反序列化
    rj_GroupServer::Request request;
    request.ParseFromString(recv_str);

    //判断业务逻辑 
    if (request.type() == "AddGroup")
    {
        //TODO 加入鉴权，以及是否存在group（这里直接加入fk来保证insert时group存在）
        rj_GroupServer::AddGroupRequest add_request;
        rj_GroupServer::AddGroupResponse add_response;
        add_request.ParseFromString(request.request_msg());
        int userid = add_request.userid();
        int groupid = add_request.group_id();

        bool ret = add_group(userid, groupid);
        if(ret){
            add_response.set_is_success(true);
            add_response.set_group_id(groupid);
            add_response.set_vertify(false);
            add_response.set_error_msg("");
        }
        else{
            add_response.set_is_success(false);
            add_response.set_group_id(groupid);
            add_response.set_vertify(false);
            add_response.set_error_msg("group not exists!");
        }
    }
    else if (request.type() == "QuitGroup")
    {
        rj_GroupServer::QuitGroupRequest quit_request;
        quit_request.ParseFromString(request.request_msg());
        int userid = quit_request.userid();
        int groupid = quit_request.groupid();

        quit_group(userid, groupid);
    }
    else if (request.type() == "CreateGroup")
    {
        rj_GroupServer::CreateGroupRequest create_request;
        create_request.ParseFromString(request.request_msg());
        int userid = create_request.userid();
        string group_name = create_request.group_name();
        string group_desc = create_request.group_desc();
        int groupid = create_group(userid, group_name,group_desc);
        if (groupid != -1)
        {
            add_group(userid, groupid,"creator");
            rj_GroupServer::CreateGroupResponse response;
            response.set_grouid(groupid);
            string send_str=response.SerializeAsString();
            conn->send(send_str, send_str.size());
        }
    }
    else if (request.type() == "GetGroupUsers")
    {
        rj_GroupServer::GetGroupUsersRequest get_request;
        get_request.ParseFromString(request.request_msg());

        int groupid = get_request.group_id();
        vector<User> users = get_group_users(groupid);
        rj_GroupServer::GetGroupUsersResponse get_response;
        rj_GroupServer::UserInfo *user = nullptr;
        for (int i = 0; i < users.size(); i++)
        {
            user = get_response.add_users();
            user->set_id(users[i].get_id());
            user->set_name(users[i].get_name());
        }
        get_response.set_is_success(true);
        string send_str=get_response.SerializeAsString();
        conn->send(send_str, send_str.size());
        return;
    }
}

//将userid所代表的用户添加到groupid的群里
bool GroupServer::add_group(int userid, int groupid,string role)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into GroupUser values(%d,%d,'%s')", groupid, userid, role.c_str());
    return conn->update(sql);
}

//创建群，群名为group_name,返回群号
int GroupServer::create_group(int userid, string group_name, string group_desc)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织并执行sql语句
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into AllGroup(groupname,groupdesc) values('%s','%s')", group_name.c_str(),group_desc.c_str());
    conn->update(sql);

    return mysql_insert_id(conn->get_connect());
}

//在groupid的群里删除userid这一列
bool GroupServer::quit_group(int userid, int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from GroupUser where userid=%d and groupid=%d", userid, groupid);
    return conn->update(sql);
}

//得到群组里所有用户的信息
vector<User> GroupServer::get_group_users(int groupid)
{
    //从连接池中取出一条连接
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select User.id,User.name from User,GroupUser where GroupUser.groupid=%d and GroupUser.userid=User.id", groupid);
    MYSQL_RES *res = conn->query(sql);
    MYSQL_ROW row;

    vector<User> ret;
    while (row = mysql_fetch_row(res))
    {
        User user;
        user.set_id(atoi(row[0]));
        user.set_name(row[1]);
        ret.push_back(user);
    }

    mysql_free_result(res);
    return ret;
}