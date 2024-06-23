#include "UserServer.h"
#include <tcprpc/RpcApp.h>
#include <cstdlib>
int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcConfig &configure = RpcApp::GetInstance().GetConfig();
    Logger::setLogFileName("./UserServer.log");
    string ip = configure.Load("server_ip");
    int port = atoi(configure.Load("server_port").c_str());
    string mysql_config=configure.Load("mysql_config");
    UserServer server(ip, port, mysql_config);
    server.run();
}