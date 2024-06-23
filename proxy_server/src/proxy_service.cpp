#include "proxy_service.h"

using namespace placeholders;

ProxyService::ProxyService() : master_("/ChatService"),
                               log_stub_(new MyRpcChannel),
                               friend_stub_(new MyRpcChannel),
                               user_stub_(new MyRpcChannel),
                               offline_stub_(new MyRpcChannel),
                               group_stub_(new MyRpcChannel)
{
    msg_handler_map_.insert({"Login", bind(&ProxyService::login, this, _1, _2)});
    msg_handler_map_.insert({"Regist", bind(&ProxyService::regist, this, _1, _2)});
    msg_handler_map_.insert({"LogOut", bind(&ProxyService::logout, this, _1, _2)});
    msg_handler_map_.insert({"AddFriend", bind(&ProxyService::add_friend, this, _1, _2)});
    msg_handler_map_.insert({"DeleteFriend", bind(&ProxyService::delete_friend, this, _1, _2)});
    msg_handler_map_.insert({"GetUserInfo", bind(&ProxyService::get_userInfo, this, _1, _2)});
    msg_handler_map_.insert({"GetFriendList", bind(&ProxyService::get_friendList, this, _1, _2)});
    msg_handler_map_.insert({"ReadOfflineMsg", bind(&ProxyService::read_offlineMsg, this, _1, _2)});
    msg_handler_map_.insert({"CreateGroup", bind(&ProxyService::create_group, this, _1, _2)});
    msg_handler_map_.insert({"QuitGroup", bind(&ProxyService::quit_group, this, _1, _2)});
    msg_handler_map_.insert({"AddGroup", bind(&ProxyService::add_group, this, _1, _2)});
    msg_handler_map_.insert({"GetGroupUserInfo",bind(&ProxyService::get_groupUsers,this, _1, _2)});
    msg_handler_map_.insert({"ConveyMsg", bind(&ProxyService::convey_msg, this, _1, _2)});
    msg_handler_map_.insert({"ChatMsg", bind(&ProxyService::chat_msg, this, _1, _2)});
    msg_handler_map_.insert({"ChatGroup",bind(&ProxyService::chat_group,this, _1, _2)});
    master_.start();
    bool ret = redis_client_.connect();
    if(!ret){
        rj_log::LogRequest request;
        request.set_name("ProxyServer");
        request.set_msg("create redis channel error");
        log_stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

//登录
void ProxyService::login(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_UserService::LoginRequest login_request;
    login_request.ParseFromString(recv_buf);

    //执行
    rj_UserService::LoginResponse response;
    user_stub_.Login(nullptr, &login_request, &response, nullptr);

    //在redis上记录此用户
    RpcConfig configure = RpcApp::GetInstance().GetConfig();
    string ip = configure.Load("server_ip");
    int port = atoi(configure.Load("server_port").c_str());
    LOG_INFO("id=%d %s:%d",login_request.id(),ip.c_str(),port);
    bool ret=redis_client_.set_host(login_request.id(), ip + ":" + to_string(port));
    if(!ret){
        LOG_INFO("redis set host failed");
    }
    //添加此用户到user map表中
    {
        lock_guard<mutex> lock(mutex_);
        use_connection_map_.insert({login_request.id(), conn});
    }
    LOG_INFO("login response: %d",response.is_success());
    //序列化并发送
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse proxy_response;
    proxy_response.set_type("LoginResponse");
    proxy_response.set_response_msg(send_str);
    string send_response = proxy_response.SerializeAsString();
    conn->send(send_response,send_response.size());
}

//注册
void ProxyService::regist(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_UserService::RegisterRequest regist_request;
    regist_request.ParseFromString(recv_buf);

    //执行
    rj_UserService::RegisterResponse response;
    rj_Proxy::ProxyResponse p_response;
    user_stub_.Registe(nullptr, &regist_request, &response, nullptr);
    //序列化并发送
    LOG_INFO<<response.id();
    LOG_INFO<<response.is_success();
    string send_str = response.SerializeAsString();
    LOG_INFO<<send_str<<send_str.size();
    p_response.set_type("RegisterResponse");
    p_response.set_response_msg(send_str);
    string send_p = p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//注销业务
void ProxyService::logout(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_UserService::LogOutRequest request;
    request.ParseFromString(recv_buf);
    LOG_INFO("into logut?");
    //执行
    google::protobuf::Empty em;
    MyRpcController controller;
    user_stub_.LogOut(&controller, &request, &em, nullptr);
    LOG_INFO<<controller.ErrorText();
    redis_client_.del_host(request.id());
    {
        lock_guard<mutex> lock(mutex_);
        use_connection_map_.erase(request.id());
    }
    LOG_INFO("logout handle ok?");
}

//添加好友业务
void ProxyService::add_friend(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_FriendService::AddFriendRequest request;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    rj_FriendService::AddFriendResponse response;
    friend_stub_.AddFriend(&controller, &request, &response, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText(),controller.ErrorText().size());
    }
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("AddFriendResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//删除好友
void ProxyService::delete_friend(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_FriendService::DeleteFriendRequest request;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    rj_FriendService::DeleteFriendResponse response;
    friend_stub_.DeleteFriend(&controller, &request, &response, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText(),controller.ErrorText().size());
    }
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("DeleteFriendResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//获取用户信息
void ProxyService::get_userInfo(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_FriendService::UserInfoRequest request;
    request.ParseFromString(recv_buf);

    //执行
    rj_FriendService::UserInfoReponse response;
    friend_stub_.GetUserInfo(nullptr, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("UserInfoReponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//获取好友列表
void ProxyService::get_friendList(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_FriendService::FriendListRequest request;
    request.ParseFromString(recv_buf);

    //执行
    rj_FriendService::FriendListResponse response;
    friend_stub_.GetFriendList(nullptr, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("FriendListResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//读取离线消息
void ProxyService::read_offlineMsg(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_OfflineService::ReadOfflineRequest request;
    request.ParseFromString(recv_buf);

    //执行
    rj_OfflineService::ReadOfflineResponse response;
    MyRpcController controller;
    offline_stub_.ReadOffline(&controller, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("ReadOfflineResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
    
}

//创建 群组
void ProxyService::create_group(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_GroupService::CreateGroupRequest request;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    rj_GroupService::CreateGroupResponse response;
    group_stub_.CreateGroup(&controller, &request, &response, nullptr);

    //序列化
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("CreateGroupResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//加入群组 如果要验证的话可以将加群组请求 发送给管理员和群主 否则直接加入群组
void ProxyService::add_group(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_GroupService::AddGroupRequest request;
    rj_GroupService::AddGroupResponse response;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    group_stub_.AddGroup(&controller, &request, &response, nullptr);
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("AddGroupResponse");
    //判断执行结果
    if (controller.Failed())
    {
        p_response.set_response_msg(controller.ErrorText());
        string send_str = response.SerializeAsString();
        conn->send(send_str,send_str.size());
    }
    else{
        p_response.set_response_msg(response.SerializeAsString());
        string send_str = p_response.SerializeAsString();
        conn->send(send_str,send_str.size());
    }
}

//退出群
void ProxyService::quit_group(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_GroupService::QuitGroupRequest request;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    google::protobuf::Empty em;
    group_stub_.QuitGroup(&controller, &request, &em, nullptr);
    //判断执行结果
    if (controller.Failed())
    {
        rj_Proxy::ProxyResponse response;
        response.set_type("QuitGroupResponse");
        response.set_response_msg(controller.ErrorText());
        string send_str = response.SerializeAsString();
        conn->send(send_str,send_str.size());
    }
}

//获得群用户信息
void ProxyService::get_groupUsers(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_GroupService::GetGroupUsersRequest request;
    request.ParseFromString(recv_buf);

    //执行
    MyRpcController controller;
    rj_GroupService::GetGroupUsersResponse response;
    group_stub_.GetGroupUsers(&controller, &request, &response, nullptr);

    //序列化
    string send_str = response.SerializeAsString();
    rj_Proxy::ProxyResponse p_response;
    p_response.set_type("GetGroupUsersResponse");
    p_response.set_response_msg(send_str);
    string send_p=p_response.SerializeAsString();
    conn->send(send_p,send_p.size());
}

//转发而来的消息
void ProxyService::convey_msg(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);

    rj_Proxy::ProxyResponse response;
    response.set_type("ChatMsg");
    response.set_response_msg(request.msg());

    int id = request.to_id();
    {
        lock_guard<mutex> lock(mutex_);
        auto it = use_connection_map_.find(id);
        auto client_conn = it->second;
        std::string tmp=response.SerializeAsString();
        client_conn->send(tmp,tmp.size());
    }
}

//聊天消息
void ProxyService::chat_msg(const spConnection conn, string &recv_buf)
{
    //反序列化
    rj_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);
    int id = request.to_id();
    std::unordered_map<int, spConnection>::iterator it;
    {
        lock_guard<mutex> lock(mutex_);
        it = use_connection_map_.find(id);
    }
    //不在此服务器上 转发到ChatServer来进行处理
    if (it == use_connection_map_.end())
    {
        //刷新服务器连接
        master_.get_follow();
        //获取一个与转发服务器交互的可以连接
        int client_fd;
        while ((client_fd = master_.get_service()) == -1)
        {
            master_.get_follow();
            sleep(1);
        }
        LOG_WAR("send msg to chatserver fd:%d",client_fd);
        int send_size=send(client_fd, recv_buf.c_str(), recv_buf.size(), 0);
        if(send_size==-1){
            LOG_ERR << "Error occurred: " << strerror(errno);
        }
        LOG_WAR("sent %d",send_size);
    }
    else
    {
        rj_Proxy::ProxyResponse response;
        response.set_type("ChatMsg");
        response.set_response_msg(recv_buf);
        string send_str = response.SerializeAsString();
        it->second->send(send_str,send_str.size());
    }
}

void ProxyService::chat_group(const spConnection conn, string &recv_buf){
    rj_ChatServer::GroupRequest request;
    request.ParseFromString(recv_buf);
    int group_id = request.group_id();
    int from_id = request.from_id();
    //请求获取组用户成员
    rj_GroupService::GetGroupUsersRequest g_request;
    rj_GroupService::GetGroupUsersResponse g_response;
    MyRpcController controller;
    g_request.set_group_id(group_id);
    group_stub_.GetGroupUsers(&controller,&g_request,&g_response,nullptr);

    for(int i=0;i<g_response.users_size();i++){
        int id = g_response.users(i).id();
        if(id==from_id)
            continue;
        rj_ChatServer::MsgRequest msg_request;
        msg_request.set_from_id(from_id);
        msg_request.set_to_id(id);
        msg_request.set_msg(request.msg());
        auto it = use_connection_map_.find(id);
        string send_str=msg_request.SerializeAsString();
        //不在此服务器上
        if (it == use_connection_map_.end())
        {
            //刷新服务器连接
            master_.get_follow();
            //获取一个与转发服务器交互的可以连接
            int client_fd;
            while ((client_fd = master_.get_service()) == -1)
            {
                master_.get_follow();
                sleep(1);
            }
            send(client_fd, send_str.c_str(),send_str.size(), 0);
        }
        else
        {
            rj_Proxy::ProxyResponse response;
            response.set_type("ChatMsg");
            response.set_response_msg(recv_buf);
            string send_str = response.SerializeAsString();
            it->second->send(send_str,send_str.size());
        }
    }

}

//获得消息对应的处理器
MsgHandler ProxyService::get_handler(string msg_type)
{
    //记录错误日志，msgid没有对应的事件处理回调
    auto it = msg_handler_map_.find(msg_type);
    //如果没有对应的msgid
    if (it == msg_handler_map_.end())
    {
        //返回一个默认处理器，打印错误日志
        rj_log::LogRequest request;
        request.set_name("ProxyService");
        request.set_msg("have this service: " + msg_type);
        google::protobuf::Empty em;
        MyRpcController controller;
        log_stub_.Log_ERROR(&controller, &request, &em, nullptr);

        return [=](const spConnection conn, string &recv_buf) {
        };
    }
    else
    {
        return msg_handler_map_[msg_type];
    }
}

//处理客户端异常退出
void ProxyService::client_close_exception(const spConnection conn)
{
    //1.删除user_map    2.用户改为offline   3.线程安全 4.删除redis上的信息
    {
        lock_guard<mutex> lock(mutex_);
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            if (it->second == conn)
            {
                redis_client_.del_host(it->first);
                it = use_connection_map_.erase(it);
                break;
            }
        }
    }
}

//服务器异常，业务重置
void ProxyService::reset()
{
    //序列化客户端收到的语句
    rj_Proxy::ProxyResponse response;
    response.set_type("LogOut");
    response.set_response_msg("server crash");
    string send_str = response.SerializeAsString();

    {
        lock_guard<mutex> lock(mutex_);
        //重置所有用户为下线状态
        rj_UserService::LogOutRequest request;
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            request.set_id(it->first);

            //在redis上删除用户
            redis_client_.del_host(it->first);

            google::protobuf::Empty em;
            std::string t=em.SerializeAsString();
            LOG_INFO("em size:%d",t.size());
            MyRpcController controller;
            user_stub_.LogOut(&controller, &request, &em, nullptr);

            it->second->send(send_str,send_str.size());
        }
    }
    //清空map
    use_connection_map_.clear();
}
