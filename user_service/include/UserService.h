#pragma once
#include "LogServer.pb.h"
#include "UserService.pb.h"
#include "UserServer.pb.h"
#include "zkMaster.h"

#include <mysql/mysql.h>
#include <tcprpc/RpcChannel.h>
#include <google/protobuf/service.h>
#include <string>

using namespace std;

class UserService : public rj_UserService::UserServiceRpc
{
public:
    UserService();

public:
    void Login(::google::protobuf::RpcController *controller,
               const ::rj_UserService::LoginRequest *request,
               ::rj_UserService::LoginResponse *response,
               ::google::protobuf::Closure *done);
    void Registe(::google::protobuf::RpcController *controller,
                 const ::rj_UserService::RegisterRequest *request,
                 ::rj_UserService::RegisterResponse *response,
                 ::google::protobuf::Closure *done);
    void LogOut(::google::protobuf::RpcController *controller,
                  const ::rj_UserService::LogOutRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done);

private:
    rj_log::LogServerRpc_Stub stub_; //日志服务器桩类
    ZkMaster master_;
};