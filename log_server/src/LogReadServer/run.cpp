#include "LogReadServer.h"
#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>
#include <cstdlib>

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcConfig &configure = RpcApp::GetInstance().GetConfig();
    string ip = configure.Load("LogSend_ip");
    int port = atoi(configure.Load("LogSend_port").c_str());

    LogSend server(ip,port);
    server.run();
    return 0;
}