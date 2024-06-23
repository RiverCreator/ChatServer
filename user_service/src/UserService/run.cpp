#include "UserService.h"

#include <tcprpc/RpcProvider.h>
#include <tcprpc/RpcApp.h>
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
    RpcApp::Init(argc, argv);
    RpcProvider provider;
    Logger::setLogFileName("./UserService.log");
    provider.NotifyService(new UserService);
    provider.Run();
    return 0;
}