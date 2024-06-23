#include "mychat.h"

MyChat::MyChat(string ip,int port):client(ip,port)
{
    client.setonmessagecb(std::bind(&MyChat::OnResponse,this,std::placeholders::_1));
}

MyChat::~MyChat()
{
    Logout();
}

void MyChat::main_loop()
{
    int flag=client.init();
    if(flag == -1)
        return;
    while(1){//进入循环

    }
}

void MyChat::Registe(string name,string password)
{
    rj_Proxy::ProxyMessage request;
    rj_UserService::RegisterRequest r_request;
    r_request.set_name(name);
    r_request.set_password(password);
    string r_requets_str = r_request.SerializeAsString();
    request.set_type("Regist");
    request.set_request_msg(r_requets_str);
    string send_str = request.SerializeAsString();
    client.send(send_str);
}

void MyChat::GetUserInfo()
{

}

void MyChat::AddFriend()
{

}

void MyChat::OnResponse(string &msg)
{
    rj_Proxy::ProxyResponse response;
    response.ParseFromString(msg);
    string op = response.type();
    if(op == "ChatMsg"){

    }
    else if(op == ""){
 
    }
    else if(){
        
    }
}
