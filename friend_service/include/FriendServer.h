#pragma once
#include "FriendServer.pb.h"

#include <mytcp/Connection.h>
#include <mytcp/TcpServer.h>
#include <tcprpc/zkClient.h>
#include <SQL_pool/connect_pool.hpp>
#include <SQL_pool/connect.hpp>
#include <redis.h>
#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

class FriendServer
{
public:
    FriendServer(string ip, int port, string name);

public:
    //服务器运行
    void run();

    //读写事件回调函数
    void on_message(const spConnection conn, std::string& buf);

    //连接事件回调函数
    void on_connect(const spConnection conn);

public:
    //获取userid 用户的好友列表
    vector<std::string> get_friendlist(int userid);

    //获得userid用户信息
    User get_userinfo(int userid);

    //userid 的用户添加好友 friendid
    bool add_friend(int userid, int friendid);

    //删除userid用户的好友 friendid
    bool delete_friend(int userid, int friendid);

private:
    string ip_;
    int port_;
    RedisCli redis_client_;
    TcpServer server_;

    Connect_pool *pool_;
};