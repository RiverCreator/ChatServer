#include "FriendServer.h"

#define BUFF_SIZE 128

using namespace placeholders;

FriendServer::FriendServer(string ip, int port, string config_name):ip_(ip),port_(port),server_(ip_,port_,4)
{
    pool_ = Connect_pool::get_instance(config_name);
    redis_client_.connect();
}

//服务器运行
void FriendServer::run()
{
    // 注册zookeeper节点
    ZkClient client;
    client.Start();
    string server_path = "/FriendService";
    client.Create(server_path.c_str(), nullptr, 0);
    server_path +="/server";
    char data[BUFF_SIZE] = {0};
    sprintf(data, "%s:%d", ip_.c_str(), port_);
    client.Create(server_path.c_str(), data, strlen(data),ZOO_SEQUENCE);

    //绑定回调函数
    server_.setonmessagecb(bind(&FriendServer::on_message, this, _1, _2));
    server_.setnewconnectioncb(bind(&FriendServer::on_connect, this, _1));

    server_.start();
}

//读写事件回调函数
void FriendServer::on_message(const spConnection conn, std::string& recv)
{
    rj_FriendServer::Request request;
    request.ParseFromString(recv);
    if (request.type() == "GetFriendList")
    {
        //反序列化
        rj_FriendServer::FriendListRequest friendList_request;
        friendList_request.ParseFromString(request.request());
        int userid = friendList_request.id();
        //获取好友列表信息
        vector<std::string> users = get_friendlist(userid);
        //组织返回消息
        rj_FriendServer::FriendListResponse response;
        response.set_is_success(true);
        for (int i = 0; i < users.size(); ++i)
        {
            rj_FriendServer::FriendInfo *info = response.add_friends();
            std::string tmp=users[i];
            int tn=tmp.find('_');
            info->set_id(stoi(tmp.substr(0,tn+1)));
            info->set_name(tmp.substr(tn+1));
        }

        string send = response.SerializeAsString();
        conn->send(send, send.size());
    }
    else if (request.type() == "GetUserInfo")
    {
        //反序列化
        rj_FriendServer::UserInfoRequest user_request;
        user_request.ParseFromString(request.request());
        //序列化
        User user = get_userinfo(user_request.id());
        rj_FriendServer::FriendInfo info;
        info.set_id(user.get_id());
        info.set_name(user.get_name());
        //信息发送
        string send = info.SerializeAsString();
        conn->send(send, send.size());
    }
    else if (request.type() == "AddFriend")
    {
        //反序列化
        rj_FriendServer::AddFriendRequest add_request;
        add_request.ParseFromString(request.request());
        LOG_WAR("add_friend before");
        bool ret = add_friend(add_request.myid(), add_request.friendid());
        LOG_WAR("add_friend after");
        LOG_WAR<<ret;
        LOG_WAR("friend id:%d",add_request.friendid());
        if(ret){//如果mysql添加好友成功， 更新redis上对应的friend list set。
            if(redis_client_.is_exist(add_request.friendid())){
                User user = get_userinfo(add_request.myid());
                if(user.get_id()!=-1)
                    redis_client_.add_friend(add_request.friendid(),user.get_id(),user.get_name());
            }
            if(redis_client_.is_exist(add_request.myid())){
                LOG_WAR("%d add friend %d",add_request.myid(),add_request.friendid());
                User user = get_userinfo(add_request.friendid());
                LOG_WAR("user' name:%s",user.get_name().c_str());
                if(user.get_id()!=-1)
                    redis_client_.add_friend(add_request.myid(),user.get_id(),user.get_name());
            }
        }
        rj_FriendServer::AddFriendResponse response;
        response.set_is_success(ret);
        if(!ret){
            response.set_fail_msg("wrong add friend");
        }
        string send_str=response.SerializeAsString();
        conn->send(send_str, send_str.size());
    }
    else if (request.type() == "DeleteFriend")
    {
        //反序列化
        rj_FriendServer::DeleteFriendRequest del_request;
        del_request.ParseFromString(request.request());

        bool ret = delete_friend(del_request.myid(), del_request.friendid());
        if(ret){
            if(redis_client_.is_exist(del_request.friendid())){
                User user = get_userinfo(del_request.myid());
                redis_client_.del_friend(del_request.friendid(),user.get_id(),user.get_name());
            }
            if(redis_client_.is_exist(del_request.myid())){
                User user = get_userinfo(del_request.friendid());
                redis_client_.del_friend(del_request.myid(),user.get_id(),user.get_name());
            }
        }
        rj_FriendServer::DeleteFriendResponse response;
        response.set_is_success(ret);
        if(!ret){
            response.set_fail_msg("wrong delete friend");
        }
        string send_str=response.SerializeAsString();
        conn->send(send_str, send_str.size());
    }
}

//连接事件回调函数
void FriendServer::on_connect(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}

//获取userid 用户的好友列表
vector<std::string> FriendServer::get_friendlist(int userid)
{
    auto rec=redis_client_.get_friend_list(userid);
    // shared_ptr<Connect> conn = pool_->get_connect();

    // char sql[BUFF_SIZE] = {0};
    // sprintf(sql, "select User.id,User.name from Friend,User where Friend.userid=%d and User.id=Friend.friendid", userid);
    // MYSQL_RES *res = conn->query(sql);
    // MYSQL_ROW row;

    // vector<User> ret;
    // while (row = mysql_fetch_row(res))
    // {
    //     User user;
    //     user.set_id(atoi(row[0]));
    //     user.set_name(row[1]);
    //     ret.push_back(user);
    // }

    // mysql_free_result(res);
    return rec;
}

//获得userid用户信息
User FriendServer::get_userinfo(int userid)
{
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select name from User where id=%d", userid);
    MYSQL_RES *res = conn->query(sql);
    if (res == nullptr)
    {
        //没有的话返回id = -1
        User user;
        user.set_id(-1);
        return user;
    }
    User user;
    MYSQL_ROW row = mysql_fetch_row(res);
    user.set_id(userid);
    LOG_WAR("get user info %s",row[0]);
    user.set_name(row[0]);

    mysql_free_result(res);
    return user;
}

//userid 的用户添加好友 friendid
bool FriendServer::add_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};

    sprintf(sql, "insert into Friend values(%d,%d)", userid, friendid);
    bool ret = conn->update(sql);
    sprintf(sql, "insert into Friend values(%d,%d)", friendid, userid);
    bool ret2 = conn->update(sql);
    //因为可能会存在a加b，b也加a这种情况，可能导致第二句sql失败，而如果已经是好友了，两个语句都会失败
    return ret||ret2;
}

//删除userid用户的好友 friendid
bool FriendServer::delete_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from Friend where userid=%d and friendid=%d", userid, friendid);
    bool ret = conn->update(sql);
    sprintf(sql, "delete from Friend where userid=%d and friendid=%d", friendid, userid);
    bool ret2 = conn->update(sql);
    //和上同理
    return ret||ret2;
}