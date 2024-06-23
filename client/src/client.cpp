#include "client.h"
Client::Client(string ip_,int port_,int ev_nums,int timeout):ip(ip_),port(port_),event_nums(ev_nums),timeout_(timeout),inputbuffer_(new Buffer(0)),outputbuffer_(new Buffer(0)){

}

Client::~Client()
{
    if(!stop_){
        stop_=true;
    }
    close(clientfd);
    loop.join();
}

int Client::init()
{
    Logger::setLogFileName("./client.log");
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    setnonblocking(clientfd);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if(connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1){
        cout<<"connect false"<<endl;
        return -1;
    }

    epollfd=epoll_create(event_nums);
    if(epollfd<=0){
        printf("epoll created failed!\n");
        return -1;
    }
    epoll_event ev;
    ev.events=EPOLLIN&EPOLLET;
    if (epoll_ctl(epollfd,EPOLL_CTL_ADD,clientfd,&ev) < 0)
    {
        printf("[%s %d] Epoll add error!\n",__FUNCTION__,__LINE__);
        return -1;
    }
    stop_=false;
    loop=std::move(std::thread(&Client::epoll_loop));
}

void Client::send(string msg)
{
    outputbuffer_->append(msg.c_str(),msg.size());
    enablewriting();
}

void Client::sendmessage()
{
    int writen = ::send(clientfd, outputbuffer_->data(), outputbuffer_->size(), 0);           // 尝试把outputbuffer_中的数据全部发送出去。
    if (writen>0) outputbuffer_->erase(0,writen);                                        // 从outputbuffer_中删除已成功发送的字节数。
    LOG_INFO<<writen;
    // 如果发送缓冲区中没有数据了，表示数据已发送完成，不再关注写事件。
    if (outputbuffer_->size()==0) 
    {
        disablewriting();
    }
}

//后续可以考虑IO弄成线程池 不过因为这里客户端只建立一个连接，一个线程应该也足够了，没必要开多线程
void Client::onmessage()
{
    char buffer[1024];
    while(1){
        bzero(&buffer,sizeof(buffer));
        ssize_t nread = read(clientfd,buffer,sizeof(buffer));
        if(nread>0){
            inputbuffer_->append(buffer,nread);
            LOG_INFO("inputbuffer_ size :%d",inputbuffer_->size());
        }
        else if (nread == -1 && errno == EINTR) // 读取数据的时候被信号中断，继续读取。
        {  
            continue;
        }
        else if(nread == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){//读取完毕
            std::string message;
            while(true){
                if(inputbuffer_->pickmessage(message)==false){
                    break;
                }
                onmessagecb(message); //可以调用上层回调 处理聊天信息
            }
        }
        else if(nread == 0){
            LOG_WAR("server disconnected!");
            break;
        }

    }
}

void Client::enablereading()
{
    events|=EPOLLIN;
    epoll_event ev;
    ev.events=events;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,clientfd,&ev);

}

void Client::enablewriting()
{
    events|=EPOLLOUT;
    epoll_event ev;
    ev.events=events;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,clientfd,&ev);
}

void Client::disablewriting()
{
    events&=~EPOLLOUT;
    epoll_event ev;
    ev.events=events;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,clientfd,&ev);
}

void Client::epoll_loop()
{
    while(!stop_){
        int infds=epoll_wait(epollfd,events_,MAX_EVENT,timeout_);
        if(infds<0){
            perror("epoll_wait() failed");
            exit(-1);
        }
        if(infds==0){
            continue;
        }
        for(int i=0;i<infds;i++){
            uint32_t revents=events_[i].events;
            if(revents&EPOLLERR||revents&EPOLLHUP){
                printf("[%s %d] Epoll event error!\n",__FUNCTION__,__LINE__);
                close(events_[i].data.fd);
                continue;
            }
            if(revents&EPOLLOUT){
                sendmessage();
            }
            if(revents&EPOLLIN){
                onmessage();
            }
        }
    }
}

int Client::setnonblocking(int clientfd)
{
    int old_option=fcntl(clientfd,F_GETFL);
    if(old_option<0){
        printf("[%s:%d] fd[%d] getfl failed!",__FUNCTION__,__LINE__,clientfd);
        return -1;
    }
    int new_option=old_option|O_NONBLOCK;
    if(fcntl(clientfd,F_SETFL,new_option)<0){
        printf("[%s,%d] fd[%d] setfl failed!",__FUNCTION__,__LINE__,clientfd);
        return -1;
    }
    return old_option;
}

void Client::setonmessagecb(std::function<void(std::string &)> fn)
{
    onmessagecb = fn;
}
