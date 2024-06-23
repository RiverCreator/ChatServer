#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcProvider.h>

#include "group_service.h"

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcProvider provider;
    provider.NotifyService(new GroupService);
    provider.Run();
    return 0;
}