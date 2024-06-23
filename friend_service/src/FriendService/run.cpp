#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcProvider.h>
#include "FriendService.h"

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcProvider provider;
    Logger::setLogFileName("./FriendService.log");
    provider.NotifyService(new FriendService);
    provider.Run();
    return 0;
}