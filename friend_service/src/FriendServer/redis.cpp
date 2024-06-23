#include "redis.h"

#include <iostream>

//初始化redis连接信息
RedisCli::RedisCli()
{
    RpcConfig configure = RpcApp::GetConfig();
    ip_ = configure.Load("redis_ip");
    port_ = atoi(configure.Load("redis_port").c_str());
}

//释放连接
RedisCli::~RedisCli()
{
    redisFree(get_channel_);
    redisFree(set_channel_);
}

//初始化get_channel、set_channel连接
bool RedisCli::connect()
{
    get_channel_ = redisConnect(ip_.c_str(), port_);
    if (get_channel_ == nullptr)
    {
        return false;
    }

    set_channel_ = redisConnect(ip_.c_str(), port_);
    if (set_channel_ == nullptr)
    {
        return false;
    }

    return true;
}

//判断某个账号是否在线
bool RedisCli::is_exist(int id)
{
    LOG_WAR("redisCli is_exist");
    if (get_host(id) == "")
    {
        return false;
    }
    else
    {
        return true;
    }
}

//根据账户得到它上线的服务器
string RedisCli::get_host(int id)
{
    LOG_WAR("redisCli get_host %d",id);
    redisReply *reply = (redisReply *)redisCommand(get_channel_, "get %d", id);
    if (reply == nullptr||reply->str==nullptr)
    {
        LOG_WAR("redisCli get_host reply is nullptr");
        return "";
    }
    string result = reply->str;
    freeReplyObject(reply);

    return result;
}

//设置账户及其登录的服务器
bool RedisCli::set_host(int id, string host)
{
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "set %d %s", id, host.c_str());
    if (reply == nullptr)
    {
        return false;
    }
    freeReplyObject(reply);
    return true;
}

//删除用户的信息
bool RedisCli::del_host(int id)
{
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "del %d",id);
    if (reply == nullptr)
    {
        return false;
    }
    freeReplyObject(reply);
    return true;
}

//把好友列表加入到redis上 存为hset
bool RedisCli::add_friend_list(int id, std::vector<pair<int,std::string>>& rec){
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "sadd %d_fl");
    freeReplyObject(reply);
    for(auto &c:rec){
        redisReply *reply = (redisReply *)redisCommand(set_channel_, "sadd %d_fl %d_%s",id,c.first,c.second);
        freeReplyObject(reply);
    }
    return true;
}

bool RedisCli::del_friend_list(int id){
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "del %d_fl",id);
    if (reply == nullptr)
    {
        return false;
    }
    freeReplyObject(reply);
    return true;
}

std::vector<std::string> RedisCli::get_friend_list(int id){
    redisReply *reply = (redisReply *)redisCommand(get_channel_, "smembers %d_fl", id, sizeof(id));
    if(!reply)
        return {};
    std::vector<std::string> res;
    for(int i=0;i<reply->elements;i++){
        redisReply *element = reply->element[i];
        if (element->type == REDIS_REPLY_STRING) {
            res.emplace_back(element->str);
        }
    }
    freeReplyObject(reply);
    return res;
}

bool RedisCli::add_friend(int myid,int friendid,string name){
    if(this->is_exist(myid)){
        redisReply *reply = (redisReply *)redisCommand(set_channel_, "sadd %d_fl %d_%s",myid,friendid, name.c_str());
        freeReplyObject(reply);
    }
    return true;
}

bool RedisCli::del_friend(int myid, int friendid, string name){
    if(this->is_exist(myid)){
        redisReply *reply = (redisReply *)redisCommand(set_channel_, "srem %d_fl %d_%s",myid,friendid, name.c_str());
        freeReplyObject(reply);
    }
    return true;
}