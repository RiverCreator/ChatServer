#include <tcprpc/zkClient.h>
#include "GroupServer.pb.h"

#include <SQL_pool/connect_pool.hpp>

#include <mytcp/Connection.h>
#include <mytcp/TcpServer.h>
#include <SQL_pool/connect.hpp>

#include <string>
#include <memory>
#include <vector>
#include <functional>
#include "User.h"
using namespace std;

class GroupServer
{
public:
    //初始化server信息
    GroupServer(string ip, int port, string config_name);

    //开始运行服务
    void run();

    //绑定连接事件
    void on_connet(const spConnection conn);

    //绑定连接读写事件
    void on_message(const spConnection conn,std::string& buf);

public:
    //将userid所代表的用户添加到groupid的群里
    bool add_group(int userid, int groupid,string role="normal");

    //创建群，群名为group_name,返回群号
    int create_group(int userid, string group_name,string group_desc);

    //在groupid的群里删除userid这一列
    bool quit_group(int userid, int groupid);

    //得到群组里所有用户的信息
    vector<User> get_group_users(int groupid);

private:
    string ip_; //IP地址
    int port_;  //端口号

    TcpServer server_;

    ZkClient zk_client_; //和zookeeper的连接句柄

    Connect_pool *pool_; //指向连接池的指针
};