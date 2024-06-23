#pragma once

#include "redis.h"
#include "LogServer.pb.h"
#include "ChatServer.pb.h"
#include "ProxyServer.pb.h"
#include "OfflineService.pb.h"

#include <google/protobuf/empty.pb.h>
#include <tcprpc/RpcChannel.h>
#include <tcprpc/RpcController.h>
#include <tcprpc/RpcConfig.h>

#include <mytcp/EventLoop.h>
#include <mytcp/TcpServer.h>
#include <mytcp/Connection.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unordered_map>
#include <functional>
#include <string>

using namespace std;
class ChatServer
{
public:
    ChatServer(std::string& ip, int port);

    //开启服务
    void run();

    //连接事件回调函数
    void on_message(const spConnection conn, std::string& recv_buf);

    //连接事件回调函数
    void on_connect(const spConnection conn);

    //根据host建立连接
    int establish_connection(string host);

private:
    ZkClient zk_client_;
    RedisCli redis_client_;

    TcpServer server_; //server实例

    //存储抽象服务节点chatservice及与其连接对应的socket
    unordered_map<string, int> channel_map_;

    rj_log::LogServerRpc_Stub log_stub_;
    rj_OfflineService::OfflineServiceRpc_Stub offline_stub_;
};