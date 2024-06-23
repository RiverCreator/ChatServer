#pragma once

#include <mytcp/EventLoop.h>
#include <mytcp/TcpServer.h>
#include <mytcp/Connection.h>
//#include <mytcp/Timestamp.h>

#include "proxy_service.h"
#include "ProxyServer.pb.h"

#include <string>
#include <functional>
#include <mylog/Logger.h>
using namespace std;

class ProxyServer
{
public:
    //初始化服务器信息
    ProxyServer(std::string& ip, uint16_t port);

    //代理服务器开始工作
    void start();

    //连接事件的回调函数
    void on_connect(const spConnection conn);

    //读写事件回调函数
    void on_message(const spConnection conn, std::string&);

    //关闭事件回调函数
    void handle_close(const spConnection conn);

    void Stop();
private:
    TcpServer server_; //server对象
};