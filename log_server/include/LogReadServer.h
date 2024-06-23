#pragma once
#include "LogRead.pb.h"
#include <mytcp/TcpServer.h>
#include <mytcp/Connection.h>
#include <mytcp/EventLoop.h>
#include <mylog/Logger.h>
#include <string>

using namespace std;

class LogSend
{
public:
    //开始服务
    LogSend(string ip,int port);
    void run();

    // 读取文件并发送信息，绑定到muduo的on_message
    void send_file(const spConnection conn, std::string& buf);

    // 关闭连接
    void handle_conn(const spConnection conn);

private:
    TcpServer server_;
};