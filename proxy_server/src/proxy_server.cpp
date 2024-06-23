#include "proxy_server.h"
#include <stdlib.h>
using namespace placeholders;
//初始化服务器信息
ProxyServer::ProxyServer(std::string& ip, uint16_t port):server_(ip, port, 4)
{
    //注册连接事件回调函数
    server_.setonmessagecb(std::bind(&ProxyServer::on_message, this, _1, _2));
    //注册连接事件回调函数
    server_.setnewconnectioncb(std::bind(&ProxyServer::on_connect, this, _1));
    //注册关闭事件回调函数
    server_.setcloseconnectioncb(std::bind(&ProxyServer::handle_close,this,_1));
}

//代理服务器开始工作
void ProxyServer::start()
{
    server_.start();
}

void ProxyServer::Stop(){
    server_.stop();
}
//连接事件的回调函数
void ProxyServer::on_connect(const spConnection conn)
{
    LOG_INFO("%s new connection(fd=%d,ip=%s,port=%d) ok.\n",Timestamp::now().tostring().c_str(),conn->fd(),conn->ip().c_str(),conn->port());
}

//读写事件回调函数
void ProxyServer::on_message(const spConnection conn, std::string& msg)
{
    //反序列化
    LOG_INFO("come message!");
    rj_Proxy::ProxyMessage request;
    request.ParseFromString(msg);
    LOG_INFO<<"proxy on message:"<<request.type();
    //获取对应的处理器并执行
    auto msg_handler = ProxyService::get_instance().get_handler(request.type());
    string str = request.request_msg();
    msg_handler(conn, str);
}

void ProxyServer::handle_close(const spConnection conn)
{    
    LOG_INFO("client exit");
}