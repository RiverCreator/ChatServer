#include "OfflineServer.pb.h"

#include <tcprpc/zkClient.h>

#include <SQL_pool/connect_pool.hpp>

#include <mytcp/Connection.h>
#include <mytcp/TcpServer.h>
#include <SQL_pool/connect.hpp>

#include <string>
#include <vector>
#include <memory>
using namespace std;

class OfflineServer
{
public:
    //初始化配置等信息
    OfflineServer(string ip, int port, string config_name);

    //开始服务
    void run();

    //读写事件回调函数
    void on_message(const spConnection conn, std::string& buf);

    //连接事件回调函数
    void on_connect(const spConnection conn);

public:
    //写离线消息
    bool write_offlineMsg(int friend_id, int from_id, string msg);
    //读离线消息
    vector<pair<int,string>> read_offlineMsg(int myid);

private:
    string ip_; //服务器ip和port
    int port_;

    TcpServer server_;

    ZkClient zk_client_; //zkclient客户端

    Connect_pool *pool_; //连接池
};