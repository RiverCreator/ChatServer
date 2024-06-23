#include "LogReadServer.h"
#include "LogRead.pb.h"
#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
using namespace placeholders;

#define SEND_SIZE 256

LogSend::LogSend(string ip, int port):server_(ip,port,2){

}
//开始服务
void LogSend::run()
{
    server_.setonmessagecb(std::bind(&LogSend::send_file, this, _1, _2));
    server_.setnewconnectioncb(std::bind(&LogSend::handle_conn, this, _1));

    server_.start();
}

// 读取文件并发送信息，绑定到muduo的on_message
void LogSend::send_file(const spConnection conn,std::string& recv)
{
    rj_logread::LogReadRequest request;
    request.ParseFromString(recv);

    string file_path = "../log/";
    file_path += request.node_name();
    file_path += "/";
    file_path += request.time()+"_log.txt";
    cout << file_path << endl;

    rj_logread::LogReadResponse response;
    int count = 1;
    char send_buf[SEND_SIZE] = {0};
    FILE *fp = fopen(file_path.c_str(), "r");
    while (!feof(fp))
    {
        memset(send_buf, 0, SEND_SIZE);
        fgets(send_buf, SEND_SIZE, fp);
        response.set_serial(count++);
        response.set_is_end(false);
        response.set_msg(send_buf);

        string send_str;
        response.SerializePartialToString(&send_str);
        conn->send(send_str.c_str(), send_str.size());
    }

    response.set_serial(count++);
    response.set_is_end(true);

    string send_str;
    response.SerializePartialToString(&send_str);
    conn->send(send_str.c_str(), send_str.size());
}


void LogSend::handle_conn(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}