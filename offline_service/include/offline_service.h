#include "LogServer.pb.h"
#include "OfflineServer.pb.h"
#include "OfflineService.pb.h"

#include "zkMaster.h"

#include <google/protobuf/service.h>
#include <tcprpc/RpcChannel.h>
#include <tcprpc/RpcController.h>

#include <string>

using namespace std;
class OfflineService : public rj_OfflineService::OfflineServiceRpc
{
public:
    OfflineService();

public:
    void WriteOffline(::google::protobuf::RpcController *controller,
                      const ::rj_OfflineService::WriteOfflineRequest *request,
                      ::google::protobuf::Empty *response,
                      ::google::protobuf::Closure *done);
    void ReadOffline(::google::protobuf::RpcController *controller,
                     const ::rj_OfflineService::ReadOfflineRequest *request,
                     ::rj_OfflineService::ReadOfflineResponse *response,
                     ::google::protobuf::Closure *done);

private:
    rj_log::LogServerRpc_Stub stub_;

    ZkMaster master_;
};