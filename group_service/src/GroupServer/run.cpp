#include "group_server.h"

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcConfig configure = RpcApp::GetConfig();
    string ip = configure.Load("server_ip");
    int port = atoi(configure.Load("server_port").c_str());
    string mysql_config=configure.Load("mysql_config");
    GroupServer server(ip, port, mysql_config);
    server.run();
    return 0;
}