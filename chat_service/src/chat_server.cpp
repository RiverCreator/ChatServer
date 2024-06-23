#include "chat_server.h"

#include <iostream>
using namespace placeholders;

#define BUFF_SIZE 128

ChatServer::ChatServer(std::string& ip, int port) :server_(ip,port,4),log_stub_(new MyRpcChannel),offline_stub_(new MyRpcChannel)
{
}

//开启服务
void ChatServer::run()
{
    //初始化服务器信息

    // 设置回调函数
    server_.setonmessagecb(bind(&ChatServer::on_message, this, _1, _2));
    server_.setnewconnectioncb(bind(&ChatServer::on_connect, this, _1));

    //连接redis服务器
    redis_client_.connect();

    //初始化zookeeper配置中心并注册节点
    zk_client_.Start();
    string zk_path = "/ChatService";
    zk_client_.Create(zk_path.c_str(), nullptr, 0);
    zk_path += "/server";
    std::string ip = RpcApp::GetConfig().Load("server_ip");
    std::string port = RpcApp::GetConfig().Load("server_port");
    string zk_data = ip + ":" + port;
    zk_client_.Create(zk_path.c_str(), zk_data.c_str(),zk_data.size(), ZOO_EPHEMERAL);

    server_.start();
}

//连接事件回调函数
void ChatServer::on_message(const spConnection conn, std::string& recv_str)
{
    //反序列化
    rj_ChatServer::MsgRequest request;
    request.ParseFromString(recv_str);

    //得到用户登录的服务器ip地址
    string host = redis_client_.get_host(request.to_id());
    //如果当前用户没登陆,写入离线消息
    if (host == "")
    {
        rj_OfflineService::WriteOfflineRequest write_request;
        write_request.set_friend_id(request.to_id());
        write_request.set_user_id(request.from_id());
        write_request.set_msg(request.msg());
        google::protobuf::Empty em;
        MyRpcController controller;
        offline_stub_.WriteOffline(&controller, &write_request, &em, nullptr);
        return;
    }

    auto it = channel_map_.find(host);
    if (it == channel_map_.end()) //记录里面没有这个链接
    {
        int cliend_fd = establish_connection(host);
        channel_map_[host] = cliend_fd;
    }

    //序列化
    rj_Proxy::ProxyMessage proxy_request;
    proxy_request.set_type("ConveyMsg");
    proxy_request.set_request_msg(recv_str);

    string send_str = proxy_request.SerializeAsString();
    //转发此信息
    auto channel = channel_map_.find(host);
    int fd = channel->second;
    if (send(fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印错误日志
        rj_log::LogRequest log_request;
        log_request.set_name("ChatServer " + host);
        char error_buffer[BUFF_SIZE] = {0};
        sprintf(error_buffer, "send error ,errno:%d", errno);
        log_request.set_msg(error_buffer);
        google::protobuf::Empty em;
        log_stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }
}

//连接事件回调函数
void ChatServer::on_connect(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}

//根据host建立连接
int ChatServer::establish_connection(string host)
{
    //解析ip和port
    int index = host.find(":");
    string ip = host.substr(0, index);
    int port = atoi(host.substr(index + 1, host.size() - index).c_str());

    //创建socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        //打印错误日志
        rj_log::LogRequest request;
        request.set_name("ChatServer " + host);
        request.set_msg("create client fd error");
        google::protobuf::Empty em;
        log_stub_.Log_ERROR(nullptr, &request, &em, nullptr);

        close(client_fd);
        return -1;
    }

    //配置服务器信息
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    //连接
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        //打印错误日志
        rj_log::LogRequest request;
        request.set_name("ChatServer " + host);
        request.set_msg("establish connect error");
        google::protobuf::Empty em;
        log_stub_.Log_ERROR(nullptr, &request, &em, nullptr);

        close(client_fd);
        return -1;
    }
    return client_fd;
}