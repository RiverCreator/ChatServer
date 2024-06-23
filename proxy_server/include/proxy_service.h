#pragma once

#include "LogServer.pb.h"
#include "ChatServer.pb.h"
#include "UserService.pb.h"
#include "FriendService.pb.h"
#include "GroupService.pb.h"
#include "OfflineService.pb.h"

#include "redis.h"
#include "proxy_server.h"
#include "zkMaster.h"

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>
#include <tcprpc/RpcController.h>
#include <tcprpc/RpcChannel.h>

#include <unordered_map>
#include <functional>
#include <string>
#include <mutex>

using MsgHandler = function<void(const spConnection conn, std::string &recv_str)>;

//单例设计
class ProxyService
{
public:
    static ProxyService &get_instance()
    {
        static ProxyService service;
        return service;
    }

public:
    //登录
    void login(const spConnection conn, std::string &recv_buf);

    //注册
    void regist(const spConnection conn, std::string &recv_buf);

    //注销业务
    void logout(const spConnection conn, std::string &recv_buf);

    //一对一聊天业务
    void one_chat(const spConnection conn, std::string &recv_buf);

    //添加好友业务
    void add_friend(const spConnection conn, std::string &recv_buf);

    //删除好友
    void delete_friend(const spConnection conn, std::string &recv_buf);

    //获取用户信息
    void get_userInfo(const spConnection conn, std::string &recv_buf);

    //获取好友列表
    void get_friendList(const spConnection conn, std::string &recv_buf);

    //读取离线消息
    void read_offlineMsg(const spConnection conn, std::string &recv_buf);

    //创建 群组
    void create_group(const spConnection conn, std::string &recv_buf);

    //加入群组
    void add_group(const spConnection conn, std::string &recv_buf);

    //退出群
    void quit_group(const spConnection conn, std::string &recv_buf);

    //获得群用户信息
    void get_groupUsers(const spConnection conn, std::string &recv_buf);

    //聊天消息
    void chat_msg(const spConnection conn, std::string &recv_buf);

    //转发而来的消息
    void convey_msg(const spConnection conn, std::string &recv_buf);

    //群组聊天
    void chat_group(const spConnection conn, std::string &recv_buf);
public:
    //获得消息对应的处理器
    MsgHandler get_handler(std::string msg_type);

    //处理客户端异常退出
    void client_close_exception(const spConnection conn);

    //服务器异常，业务重置
    void reset();

private:
    ProxyService();

private:
    ProxyService(const ProxyService &) = delete;
    ProxyService &operator=(ProxyService &) = delete;

private:
    std::unordered_map<string, MsgHandler> msg_handler_map_; //存储事件及事件对应的回调函数

    std::unordered_map<int, spConnection> use_connection_map_; //存储登录用户，及对应tcpptr信息
    std::mutex mutex_;                                                         //保护上一个的线程安全
private:
    RedisCli redis_client_; //连接redis服务器

    ZkMaster master_; //连接zookeeper服务器
private:
    rj_GroupService::GroupServiceRpc_Stub group_stub_;
    rj_UserService::UserServiceRpc_Stub user_stub_;
    rj_FriendService::FriendServiceRpc_Stub friend_stub_;
    rj_OfflineService::OfflineServiceRpc_Stub offline_stub_;
    rj_log::LogServerRpc_Stub log_stub_;
};