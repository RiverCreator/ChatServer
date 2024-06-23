#pragma once

#include "LogServer.pb.h"
#include "FriendServer.pb.h"
#include "FriendService.pb.h"
#include "zkMaster.h"

#include <google/protobuf/empty.pb.h>
#include <google/protobuf/service.h>
#include <tcprpc/RpcChannel.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>

using namespace std;

class FriendService : public rj_FriendService::FriendServiceRpc
{
public:
    FriendService();

public:
    //获取好友列表
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::rj_FriendService::FriendListRequest *request,
                       ::rj_FriendService::FriendListResponse *response,
                       ::google::protobuf::Closure *done);

    //获得用户信息
    void GetUserInfo(::google::protobuf::RpcController *controller,
                     const ::rj_FriendService::UserInfoRequest *request,
                     ::rj_FriendService::UserInfoReponse *response,
                     ::google::protobuf::Closure *done);

    //添加好友
    void AddFriend(::google::protobuf::RpcController *controller,
                   const ::rj_FriendService::AddFriendRequest *request,
                   rj_FriendService::AddFriendResponse *response,
                   ::google::protobuf::Closure *done);

    //删除好友
    void DeleteFriend(::google::protobuf::RpcController *controller,
                      const ::rj_FriendService::DeleteFriendRequest *request,
                      rj_FriendService::DeleteFriendResponse *response,
                      ::google::protobuf::Closure *done);

private:
    rj_log::LogServerRpc_Stub log_stub_;
    ZkMaster master_;
};