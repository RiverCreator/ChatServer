#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include "ProxyServer.pb.h"
#include "UserService.pb.h"
#include "FriendService.pb.h"
#include "ChatServer.pb.h"
#include "OfflineService.pb.h"
#include "GroupService.pb.h"
#include <mytool/Buffer.h>
using namespace std;
#define MAX_EVENT 128
class Client{
public:
    //ip和port为server的ip和port
    Client(string ip,int port,int event_nums = MAX_EVENT,int timeout = 10*1000);
    //析构函数
    ~Client();
    //初始化clientfd，epollfd
    int init();
    void send(string msg); //供外部调用将信息存储在缓冲区
    void sendmessage(); //内部调用发送至服务端
    void onmessage(); //接收消息 这里直接显示数据 上层可以还有一层应用层对数据显示进行处理
    void enablereading();
    void enablewriting();
    void disablewriting();
    void epoll_loop();
    int setnonblocking(int clientfd);
    void setonmessagecb(std::function<void(std::string&)> fn);
private:
    std::string ip;
    int port;
    int event_nums;
    std::unique_ptr<Buffer> outputbuffer_; //发送缓冲区
    std::unique_ptr<Buffer> inputbuffer_; //接收缓冲区
    int clientfd; 
    int epollfd;
    uint32_t events;
    // uint32_t revents;
    struct epoll_event ev;
    struct epoll_event events_[MAX_EVENT]; //存发生的事件
    bool stop_;
    int timeout_; //epoll_wait超时时间
    std::thread loop;
    std::function<void(std::string&)> onmessagecb;
}; 