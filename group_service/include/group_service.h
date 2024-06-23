#include "LogServer.pb.h"
#include "GroupServer.pb.h"
#include "GroupService.pb.h"

#include "zkMaster.h"

#include <google/protobuf/service.h>
#include <tcprpc/RpcChannel.h>
#include <tcprpc/RpcController.h>

#include <string>

using namespace std;

class GroupService : public rj_GroupService::GroupServiceRpc
{
public:
    GroupService();

public:
    void AddGroup(::google::protobuf::RpcController *controller,
                  const ::rj_GroupService::AddGroupRequest *request,
                  ::rj_GroupService::AddGroupResponse *response,
                  ::google::protobuf::Closure *done);
    void CreateGroup(::google::protobuf::RpcController *controller,
                     const ::rj_GroupService::CreateGroupRequest *request,
                     ::rj_GroupService::CreateGroupResponse *response,
                     ::google::protobuf::Closure *done);
    void QuitGroup(::google::protobuf::RpcController *controller,
                   const ::rj_GroupService::QuitGroupRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done);
    void GetGroupUsers(::google::protobuf::RpcController *controller,
                       const ::rj_GroupService::GetGroupUsersRequest *request,
                       ::rj_GroupService::GetGroupUsersResponse *response,
                       ::google::protobuf::Closure *done);

private:
    rj_log::LogServerRpc_Stub stub_;

    ZkMaster master_;
};