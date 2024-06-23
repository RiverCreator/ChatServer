#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcProvider.h>

#include "offline_service.h"

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcProvider provider;
    Logger::setLogFileName("./offline_service.log");
    provider.NotifyService(new OfflineService);
    provider.Run();
    return 0;
}