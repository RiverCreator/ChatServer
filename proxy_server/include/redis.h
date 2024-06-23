#pragma once

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>
#include <hiredis/hiredis.h>
#include <vector>
#include <string>

using namespace std;

class RedisCli
{
public:
    //初始化redis连接信息
    RedisCli();

    //释放连接
    ~RedisCli();

    //初始化get_channel、set_channel连接
    bool connect();

    //判断某个账号是否在线
    bool is_exist(int id);

    //根据账户得到它上线的服务器
    string get_host(int id);

    //设置账户及其登录的服务器
    bool set_host(int id, string host);

    //删除用户的信息
    bool del_host(int id);

    //向redis中添加用好友列表
    bool add_friend_list(int id, std::vector<pair<int,std::string>>& rec);

    //删除好友列表
    bool del_friend_list(int id);

    //获取好友列表
    std::vector<std::string> get_friend_list(int id);

    //在myid的集合下添加friendid
    bool add_friend(int myid, int friendid, string name);

    bool del_friend(int myid,int friendid, string name);
private:
    redisContext *get_channel_;
    redisContext *set_channel_;

    string ip_;
    int port_;
};