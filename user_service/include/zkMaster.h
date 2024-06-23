#pragma once

#include <tcprpc/RpcApp.h>
#include <tcprpc/RpcConfig.h>
#include <zookeeper/zookeeper.h>
#include <mylog/Logger.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <semaphore.h>

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <map>

class ZkMaster{
public:
    ZkMaster(std::string path);
    ~ZkMaster();
    /**
     * @brief 建立与zkserver的连接
     * 
     * @return true 启动成功
     * @return false 启动失败
     */
    bool start();
    /**
     * @brief 创建指定名字的节点
     * @param master_name 节点的名称
     * @return true 创建成功
     * @return false 创建失败
     */
    bool create_master(std::string master_name);
    /**
     * @brief 重新获取path下的服务节点
     * 
     * @return true 
     * @return false 
     */
    void get_follow();
    /**
     * @brief 获取指定节点中的数据
     * 
     * @param path 节点路径
     * @return std::string 存储的字符串数据 为ip:port
     */
    std::string get_znode_data(std::string path);
    /**
     * @brief 获取一个服务节点，建立好socket连接，返回fd
     * 
     * @return int 为建立好连接的socket fd
     */
    int get_service();
private:
    zhandle_t *zkhandle_; //zookeeper句柄
    //std::map<std::string, std::string> followers_; //存储从节点 
    std::vector<std::string> followers_; //存储从节点 
    int current_service_; //当前该是哪个节点服务
    int total_services_;  //总共有多少节点服务

    std::string path_;   //当前服务路径

    std::mutex mutex_;
};