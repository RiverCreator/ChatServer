#include "UserService.h"
#include <iostream>
#include <memory>
using namespace std;

#define BUFF_SIZE 256

UserService::UserService() : stub_(new MyRpcChannel), master_("/UserService")
{
    master_.start();
}

void UserService::Login(::google::protobuf::RpcController *controller,
                        const ::rj_UserService::LoginRequest *request,
                        ::rj_UserService::LoginResponse *response,
                        ::google::protobuf::Closure *done)
{
    master_.get_follow();
    rj_UserServer::Request login_request;
    login_request.set_type("Login");
    login_request.set_request(request->SerializeAsString());

    string send_str = login_request.SerializeAsString();
    //获取一个服务信息
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        //刷新服务列表
        master_.get_follow();
        sleep(1);
    }

    //发送信息
    send(client_fd, send_str.c_str(), send_str.size(), 0);

    //获取信息
    char recv_buf[BUFF_SIZE] = {0};
    recv(client_fd, recv_buf, BUFF_SIZE, 0);
    rj_UserServer::LoginResponse login_response;
    login_response.ParseFromString(recv_buf);
    response->set_is_success(login_response.is_success());

    close(client_fd);
    done->Run();
}
void UserService::Registe(::google::protobuf::RpcController *controller,
                          const ::rj_UserService::RegisterRequest *request,
                          ::rj_UserService::RegisterResponse *response,
                          ::google::protobuf::Closure *done)
{
    master_.get_follow();
    rj_UserServer::Request register_request;
    register_request.set_type("Register");
    register_request.set_request(request->SerializeAsString());

    string send_str = register_request.SerializeAsString();
    //获取一个服务信息
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        //刷新服务列表
        master_.get_follow();
        sleep(1);
    }

    //发送信息
    send(client_fd, send_str.c_str(), send_str.size(), 0);

    //获取信息
    char recv_buf[BUFF_SIZE] = {0};
    int recv_size=recv(client_fd, recv_buf, BUFF_SIZE, 0);
    rj_UserServer::RegisterResponse register_response;
    
    register_response.ParseFromArray(recv_buf,recv_size);
    response->set_id(register_response.id());
    response->set_is_success(register_response.is_success());
    int id=register_response.id();

    LOG_INFO<<id;

    close(client_fd);
    done->Run();
}
void UserService::LogOut(::google::protobuf::RpcController *controller,
                           const ::rj_UserService::LogOutRequest *request,
                           ::google::protobuf::Empty *response,
                           ::google::protobuf::Closure *done)
{
    LOG_INFO("into LogOut");
    master_.get_follow();
    rj_UserServer::Request logout_request;
    logout_request.set_type("LogOut");
    logout_request.set_request(request->SerializeAsString());

    string send_str = logout_request.SerializeAsString();
    //获取一个服务信息
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        //刷新服务列表
        master_.get_follow();
        sleep(1);
    }
    LOG_INFO("%d logout!",request->id());
    //发送信息
    int t=send(client_fd, send_str.c_str(), send_str.size(), 0);
    if(t<0){
        LOG_ERR("sent error");
    }
    LOG_INFO<<"sent "<<t;
    close(client_fd);
    done->Run();
}