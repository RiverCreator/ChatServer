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
#include "ProxyServer.pb.h"
#include "UserService.pb.h"
#include "FriendService.pb.h"
#include "ChatServer.pb.h"
#include "OfflineService.pb.h"
#include "GroupService.pb.h"
using namespace std;
#define MAX_EVENT 128
int clientfd;
int id;

int setnonblocking(int fd){
    int old_option=fcntl(fd,F_GETFL);
    if(old_option<0){
        printf("[%s:%d] fd[%d] getfl failed!",__FUNCTION__,__LINE__,fd);
        return -1;
    }
    int new_option=old_option|O_NONBLOCK;
    if(fcntl(fd,F_SETFL,new_option)<0){
        printf("[%s,%d] fd[%d] setfl failed!",__FUNCTION__,__LINE__,fd);
        return -1;
    }
    return old_option;
}

void LogoutTest(int ,int);
int RegistTest(int clientfd){
    rj_Proxy::ProxyMessage request;
    rj_UserService::RegisterRequest r_request;
    r_request.set_name("rjiang");
    r_request.set_password("273068");
    string r_requets_str = r_request.SerializeAsString();
    request.set_type("Regist");
    request.set_request_msg(r_requets_str);
    string send_str = request.SerializeAsString();
    if(send(clientfd, send_str.c_str(), send_str.size(), 0)==-1){
        cout<<"send error "<<endl;
        return -1;
    }
    rj_UserService::RegisterResponse r_response;
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    r_response.ParseFromArray(recv_buf,recv_size);
    if(r_response.is_success()){
        cout<<r_response.id()<<endl;
        return r_response.id();
    }
    else{
        cout<<"regist failed!"<<endl;
        return -1;
    }

}

void LoginTest(int clientfd,int id){
    rj_Proxy::ProxyMessage request;
    rj_UserService::LoginRequest l_request;
    l_request.set_id(id);
    l_request.set_password("273068");
    string l_requets_str = l_request.SerializeAsString();
    request.set_type("Login");
    request.set_request_msg(l_requets_str);
    string send_str = request.SerializeAsString();
    if(send(clientfd, send_str.c_str(), send_str.size(), 0)==-1){
        cout<<"send error "<<endl;
        return;
    }

    rj_UserService::LoginResponse r_response;
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    cout<<recv_size<<endl;
    r_response.ParseFromArray(recv_buf,recv_size);
    if(!r_response.is_success()){
        string msg=r_response.msg().message();
        cout<<msg<<endl;
    }
    else{
        cout<<"Login ok!"<<endl;
    }
    cin.get();
}

void GetUserInfoTest(int clientfd,int id){
    rj_FriendService::UserInfoRequest get_request;
    rj_FriendService::UserInfoReponse get_response;
    get_request.set_id(id);
    string get_request_str=get_request.SerializeAsString();
    
    rj_Proxy::ProxyMessage request;
    request.set_type("GetUserInfo");
    request.set_request_msg(get_request_str);
    string send_str = request.SerializeAsString();
    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    //response
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    cout<<recv_size<<endl;
    get_response.ParseFromArray(recv_buf,recv_size);
    
    cout<<get_response.id()<<endl;
    cout<<get_response.name()<<endl;
    cout<<"get userinfo ok"<<endl;
    cin.get();
}


void AddFriendTest(int clientfd,int myid,int friendid){
    rj_FriendService::AddFriendRequest add_request;
    rj_FriendService::AddFriendResponse add_response;
    add_request.set_myid(myid);
    add_request.set_friendid(friendid);
    string add_request_str = add_request.SerializeAsString();

    rj_Proxy::ProxyMessage request;
    request.set_type("AddFriend");
    request.set_request_msg(add_request_str);
    string send_str = request.SerializeAsString();
    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    //response
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    cout<<recv_size<<endl;
    add_response.ParseFromArray(recv_buf,recv_size);
    if(!add_response.is_success()){
        string msg=add_response.fail_msg();
        cout<<msg<<endl;
    }
    else{
        cout<<"add friend ok!"<<endl;
    }
    cin.get();
}

void GetFriendListTest(int clientfd,int id){
    rj_FriendService::FriendListRequest list_request;
    rj_FriendService::FriendListResponse list_response;
    list_request.set_id(id);
    string list_request_str=list_request.SerializeAsString();

    rj_Proxy::ProxyMessage request;
    request.set_type("GetFriendList");
    request.set_request_msg(list_request_str);
    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    //response
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    cout<<recv_size<<endl;
    list_response.ParseFromArray(recv_buf,recv_size);
    if(!list_response.is_success()){
        cout<<"get friendlist failed"<<endl;
    }
    cout<<"friend list:"<<endl;
    for(int i=0;i<list_response.friends_size();i++){
        cout<<list_response.friends(i).id()<<endl;
        cout<<list_response.friends(i).name()<<endl;
    }
    cin.get();
}

void DeleteFriendTest(int clientfd,int myid,int friendid){
    rj_FriendService::DeleteFriendRequest del_request;
    rj_FriendService::DeleteFriendResponse del_response;
    del_request.set_myid(myid);
    del_request.set_friendid(friendid);
    string del_request_str = del_request.SerializeAsString();

    rj_Proxy::ProxyMessage request;
    request.set_type("DeleteFriend");
    request.set_request_msg(del_request_str);
    string send_str = request.SerializeAsString();


    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    //response
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    cout<<recv_size<<endl;
    del_response.ParseFromArray(recv_buf,recv_size);
    if(!del_response.is_success()){
        string msg=del_response.fail_msg();
        cout<<msg<<endl;
    }
    else{
        cout<<"del friend ok!"<<endl;
    }
    cin.get();
}

void ChatSendTest(int clientfd,int id,int toid,string msg){
    rj_Proxy::ProxyMessage request;
    rj_ChatServer::MsgRequest msg_request;
    msg_request.set_from_id(id);
    msg_request.set_to_id(toid);
    msg_request.set_msg(msg);
    string msg_request_str=msg_request.SerializeAsString();

    request.set_type("ChatMsg");
    request.set_request_msg(msg_request_str);
    string send_str = request.SerializeAsString();
    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    cout<<"sent :"<<t<<endl;
}

void ChatRecvTest(int clientfd){
    char recv_buf[1024] = {0};
    int recv_size = recv(clientfd, recv_buf, 1024, 0);
    if (recv_size < 0){
        cout<<"recv error"<<endl;
    }
    rj_ChatServer::MsgRequest msg_request;
    msg_request.ParseFromArray(recv_buf,recv_size);
    cout<<"from "<<msg_request.from_id()<<endl;
    cout<<"get message :"<<msg_request.msg()<<endl;
}

void ReadOfflineMsgTest(int clientfd,int id){
    rj_Proxy::ProxyMessage request;
    rj_OfflineService::ReadOfflineRequest r_request;
    r_request.set_myid(id);
    string r_request_str = r_request.SerializeAsString();
    request.set_type("ReadOfflineMsg");
    request.set_request_msg(r_request_str);
    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    
    rj_OfflineService::ReadOfflineResponse response;
    char recv_buf[1024];
    int recv_size=recv(clientfd,recv_buf,1024,0);
    if(recv_size==-1){
        cout<<"read offline msg falied"<<endl;
    }
    response.ParseFromArray(recv_buf,recv_size);
    if(!response.is_success()){
        cout<<"get offline msg failed"<<endl;
    }
    for(int i=0;i<response.msgs_size();i++){
        cout<<"from "<<response.msgs(i).from_id()<<endl;
        cout<<"get offline msg "<<response.msgs(i).msg()<<endl;
    }
}

void CreateGroupTest(int clientfd,int id){
    string group_name="group_test";
    rj_GroupService::CreateGroupRequest c_request;
    rj_Proxy::ProxyMessage request;
    c_request.set_group_name(group_name);
    c_request.set_userid(id);
    c_request.set_group_desc("only test");
    string c_request_str = c_request.SerializeAsString();
    request.set_type("CreateGroup");
    request.set_request_msg(c_request_str);
    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    
    rj_GroupService::CreateGroupResponse response;
    char recv_buf[1024];
    int recv_size=recv(clientfd,recv_buf,1024,0);
    if(recv_size==-1){
        cout<<"read offline msg falied"<<endl;
    }
    response.ParseFromArray(recv_buf,recv_size);
    cout<<"create group succees!"<<endl;
    cout<<"group id is "<<response.grouid()<<endl;
    cin.get();
}

void AddGroupTest(int clientfd,int id,int groupid){
    rj_GroupService::AddGroupRequest a_request;
    rj_Proxy::ProxyMessage request;
    a_request.set_userid(id);
    a_request.set_group_id(groupid);
    string a_request_str=a_request.SerializeAsString();
    request.set_type("AddGroup");
    request.set_request_msg(a_request_str);

    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    
}

void GetGroupUsersTest(int clientfd,int groupid){
    rj_GroupService::GetGroupUsersRequest g_request;
    rj_Proxy::ProxyMessage request;
    g_request.set_group_id(groupid);
    string g_request_str=g_request.SerializeAsString();
    request.set_type("GetGroupUserInfo");
    request.set_request_msg(g_request_str);

    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }

    rj_GroupService::GetGroupUsersResponse response;
    char recv_buf[1024];
    int recv_size=recv(clientfd,recv_buf,1024,0);
    if(recv_size==-1){
        cout<<"read offline msg falied"<<endl;
    }
    response.ParseFromArray(recv_buf,recv_size);
    if(!response.is_success()){
        cout<<"get group users failed"<<endl;
    }
    for(int i=0;i<response.users_size();i++){
        cout<<"id "<<response.users(i).id()<<endl;
        cout<<"name "<<response.users(i).name()<<endl;
    }
}

void ChatGroupTest(int clientfd,int id,int groupid,string msg){
    rj_ChatServer::GroupRequest c_requset;
    rj_Proxy::ProxyMessage request;
    c_requset.set_from_id(id);
    c_requset.set_group_id(groupid);
    c_requset.set_msg(msg);
    string c_requset_str=c_requset.SerializeAsString();
    
    request.set_type("ChatGroup");
    request.set_request_msg(c_requset_str);

    string send_str = request.SerializeAsString();
    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    cout<<"sent :"<<t<<endl;
}

void QuitGroupTest(int clientfd,int id,int groupid){
    rj_GroupService::QuitGroupRequest q_request;
    rj_Proxy::ProxyMessage request;
    q_request.set_userid(id);
    q_request.set_groupid(groupid);
    string q_request_str=q_request.SerializeAsString();
    request.set_type("QuitGroup");
    request.set_request_msg(q_request_str);

    string send_str = request.SerializeAsString();

    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    cout<<"quit group "<<groupid<<endl;
}

void LogoutTest(int clientfd,int id){
    rj_Proxy::ProxyMessage request;
    rj_UserService::LogOutRequest l_request;
    l_request.set_id(id);
    string l_requets_str = l_request.SerializeAsString();

    request.set_type("LogOut");
    request.set_request_msg(l_requets_str);
    string send_str = request.SerializeAsString();
    int t=send(clientfd, send_str.c_str(), send_str.size(), 0);
    if(t ==-1){
        cout<<"send error "<<endl;
        return;
    }
    cout<<"sent "<<t<<endl;
    cout<<"Logout"<<endl;
}

int get_connect(string ip,int port){
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    setnonblocking(clientfd);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if(connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1){
        cout<<"connect false"<<endl;
        return -1;
    }
    return clientfd;
}

void reset_handler(int)
{
    LogoutTest(clientfd,id);
    cout<<"logout ok"<<endl;
    exit(0);
}

void epoll_loop(int clientfd){
    int epollfd;
    struct epoll_event ev;
    struct epoll_event events[MAX_EVENT];

    epollfd=epoll_create(MAX_EVENT);
    if(epollfd <= 0){
        printf("epoll created failed!\n");
        return;
    }
    ev.data.fd=clientfd;        
    ev.events=EPOLLIN|EPOLLET|EPOLLOUT;     
    if (epoll_ctl(epollfd,EPOLL_CTL_ADD,clientfd,events) < 0)
    {
        printf("[%s %d] Epoll ctl error!\n",__FUNCTION__,__LINE__);
        return;
    }

    while(1){
        int eventnum=epoll_wait(epollfd,&ev,MAX_EVENT,-1);
        for(int i=0;i<eventnum;i++){
            if(events[i].events&EPOLLERR||events[i].events&EPOLLHUP){
                printf("[%s %d] Epoll event error!\n",__FUNCTION__,__LINE__);
                close(events[i].data.fd);
                continue;
            }
            if(events[i].events&EPOLLOUT){

            }
            else if(events[i].events&EPOLLIN){

            }
        }
        printf("epoll");
    }
}

int main(int argc, char **argv){
    if(argc<2){
        cout<<"./Client id frined_id"<<endl;
        return 0;
    }
    id=atoi(argv[1]);
    //int friend_id=atoi(argv[2]);
    string ip="192.168.203.128";
    int port=6051;
    clientfd=get_connect(ip,port);

    signal(SIGINT, reset_handler);

    int id=RegistTest(clientfd);
    LoginTest(clientfd,id);
    //CreateGroupTest(clientfd,id);
    while(1){
        //send toid msg
        string str;
        getline(cin,str);
        string op=str.substr(0,4);
        cout<<"cur op:"<<op<<endl;
        if(op=="quit"){
            break;
        }
        else if(op=="send"){
            int toid=stoi(str.substr(5,1));
            string msg=str.substr(7,str.size()-7);
            ChatSendTest(clientfd,id,toid,msg);
        }
        else if(op=="recv"){
            ChatRecvTest(clientfd);
        }
        else if(op=="reco"){
            ReadOfflineMsgTest(clientfd,id);
        }
        else if(op=="addg"){
            AddGroupTest(clientfd,id,2);
        }
        else if(op=="delg"){
            QuitGroupTest(clientfd,id,2);
        }
        else if(op=="getg"){
            GetGroupUsersTest(clientfd,2);
        }
        else if(op=="sndg"){
            int toid=stoi(str.substr(5,1));
            string msg=str.substr(7,str.size()-7);
            ChatGroupTest(clientfd,id,toid,msg);
        }
        cout<<"next op"<<endl;
    }
    // GetUserInfoTest(clientfd,friend_id);
    // AddFriendTest(clientfd,id,friend_id);
    // GetFriendListTest(clientfd,id);
    // DeleteFriendTest(clientfd,id,friend_id);
    // GetFriendListTest(clientfd,id);
    LogoutTest(clientfd,id);
    close(clientfd);
    return 0;
}