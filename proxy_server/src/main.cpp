#include <signal.h>

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>

#include "proxy_service.h"
using namespace std;
ProxyServer* server_;
//处理服务器ctrl+c结束后，重置user的状态信息
void reset_handler(int)
{
    ProxyService::get_instance().reset();
    server_->Stop();
    LOG_WAR("server已停止。");
    if(server_)
        delete server_;
    LOG_WAR("delete server。");
    exit(0);
}

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcConfig &configure = RpcApp::GetInstance().GetConfig();
    string ip = configure.Load("server_ip");
    int port = atoi(configure.Load("server_port").c_str());

    signal(SIGINT, reset_handler);

    //初始化zookeeper的连接
    ProxyService::get_instance();
    
    server_=new ProxyServer(ip, port);

    server_->start();

    return 0;
}