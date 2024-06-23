#include "chat_server.h"
#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcConfig configure = RpcApp::GetConfig();
    string ip = configure.Load("server_ip");
    int port = atoi(configure.Load("server_port").c_str());
    std::cout<<configure.Load("zookeeper_port")<<std::endl;
    ChatServer server(ip,port);
    server.run();
}