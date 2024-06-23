#include "LogServer.h"

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcProvider.h>
#include <tcprpc/RpcController.h>

int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);

    RpcProvider provider;
    provider.NotifyService(new LogServer);
    provider.Run();
    return 0;
}