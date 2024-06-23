#pragma once
#include "LogServer.pb.h"
#include "UserServer.pb.h"
#include "FriendService.pb.h"
#include <SQL_pool/connect_pool.hpp>

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcController.h>
#include <tcprpc/RpcChannel.h>
#include <mytool/ThreadPool.h>
#include <mytcp/Connection.h>
#include <mytcp/TcpServer.h>

#include "redis.h"
#include <string>
#include <memory>
#include <functional>

using namespace std;
class UserServer
{
public:
    UserServer(string& ip,int port, std::string& config);

    //服务启动
    void run();

    //读写事件回调函数
    void msg_callback(const spConnection conn,std::string& buf);

    //连接事件回调函数
    void conn_callback(const spConnection conn);
public:
    //登录
    bool Login(int id, string password);

    //注销
    void LogOut(int id);

    //注册 成功返回注册的账户，失败返回-1
    int Register(string name, string password);

    //更新redis type为0表示login 需要将friendlist添加到redis上，type为1表示。删除redis上id对应的friend_list
    void UpdateRedis(int id, int type);

private:
    string ip_;
    int port_;
    RedisCli redis_client_; //连接redis服务器
    Connect_pool *pool_; //数据库连接池
    TcpServer server_;
    ThreadPool threadpool_;
    rj_log::LogServerRpc_Stub stub_;
    rj_FriendService::FriendServiceRpc_Stub friend_stub_;
};
