#include "FriendService.h"

#define BUFF_SIZE 256

FriendService::FriendService() : log_stub_(new MyRpcChannel), master_("/FriendService")
{
    master_.start();
}

//获取好友列表
void FriendService::GetFriendList(::google::protobuf::RpcController *controller,
                                  const ::rj_FriendService::FriendListRequest *request,
                                  ::rj_FriendService::FriendListResponse *response,
                                  ::google::protobuf::Closure *done)
{
    //刷新zookeeper列表
    master_.get_follow();
    //反序列化
    rj_FriendServer::Request ser_request;
    ser_request.set_type("GetFriendList");
    ser_request.set_request(request->SerializeAsString());

    //获得一个可用的连接
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    //发送任务信息
    string send_str = ser_request.SerializeAsString();
    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("send error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);

        response->set_is_success(false);
        done->Run();
        return;
    }

    // 获取返回信息
    char recv_buf[BUFF_SIZE] = {0};
    if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("recv error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);

        response->set_is_success(false);
        done->Run();
        return;
    }

    response->ParseFromString(recv_buf);
    close(client_fd);
    done->Run();
}

//获得用户信息
void FriendService::GetUserInfo(::google::protobuf::RpcController *controller,
                                const ::rj_FriendService::UserInfoRequest *request,
                                ::rj_FriendService::UserInfoReponse *response,
                                ::google::protobuf::Closure *done)
{
    //刷新zookeeper列表
    master_.get_follow();
    //反序列化
    rj_FriendServer::Request ser_request;
    ser_request.set_type("GetUserInfo");
    ser_request.set_request(request->SerializeAsString());

    //获得一个可用的连接
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    //发送任务信息
    string send_str = ser_request.SerializeAsString();
    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("send error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);

        controller->SetFailed("send error");
        done->Run();
        return;
    }

    // 获取返回信息
    char recv_buf[BUFF_SIZE] = {0};
    if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("recv error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);

        controller->SetFailed("recv error");
        done->Run();
        return;
    }

    response->ParseFromString(recv_buf);
    close(client_fd);
    done->Run();
}

//添加好友
void FriendService::AddFriend(::google::protobuf::RpcController *controller,
                              const ::rj_FriendService::AddFriendRequest *request,
                              rj_FriendService::AddFriendResponse *response,
                              ::google::protobuf::Closure *done)
{
    //刷新zookeeper列表
    master_.get_follow();
    //反序列化
    rj_FriendServer::Request ser_request;
    ser_request.set_type("AddFriend");
    ser_request.set_request(request->SerializeAsString());

    //获得一个可用的连接
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    //发送任务信息
    string send_str = ser_request.SerializeAsString();
    int send_size=send(client_fd, send_str.c_str(), send_str.size(), 0);
    if ( send_size== -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("add send error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);
        response->set_is_success(false);
        response->set_fail_msg("send error");
        controller->SetFailed("add send error");
        done->Run();
        return;
    }
    LOG_INFO("sent %d",send_size);
    // 获取返回信息

    char recv_buf[BUFF_SIZE] = {0};
    int recv_size=recv(client_fd, recv_buf, BUFF_SIZE, 0);
    if (recv_size == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("add recv error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);
        response->set_is_success(false);
        response->set_fail_msg("recv error");
        controller->SetFailed("add recv error");
        done->Run();
        return;
    }
    LOG_WAR("Friend service addfriend get response size:%d",recv_size);
    rj_FriendService::AddFriendResponse tmp;
    tmp.ParseFromArray(recv_buf,recv_size);
    response->set_is_success(tmp.is_success());
    response->set_fail_msg(tmp.fail_msg());
    close(client_fd);
    done->Run();
}

//删除好友
void FriendService::DeleteFriend(::google::protobuf::RpcController *controller,
                                 const ::rj_FriendService::DeleteFriendRequest *request,
                                 ::rj_FriendService::DeleteFriendResponse *response,
                                 ::google::protobuf::Closure *done)
{
    //刷新zookeeper列表
    master_.get_follow();
    //反序列化
    rj_FriendServer::Request ser_request;
    ser_request.set_type("DeleteFriend");
    ser_request.set_request(request->SerializeAsString());

    //获得一个可用的连接
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    //发送任务信息
    string send_str = ser_request.SerializeAsString();
    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("del send error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);

        controller->SetFailed("del send error");
        done->Run();
        return;
    }
    LOG_WAR("delete friend send to server!");
    char recv_buf[BUFF_SIZE] = {0};
    int recv_size=recv(client_fd, recv_buf, BUFF_SIZE, 0);
    if (recv_size == -1)
    {
        //打印日志
        rj_log::LogRequest log_request;
        log_request.set_name("FriendService");
        log_request.set_msg("del recv error");
        google::protobuf::Empty em_response;
        log_stub_.Log_ERROR(nullptr, &log_request, &em_response, nullptr);
        response->set_is_success(false);
        response->set_fail_msg("recv error");
        controller->SetFailed("del recv error");
        done->Run();
        return;
    }
    LOG_WAR("delete friend recv from server");
    rj_FriendService::DeleteFriendResponse tmp;
    tmp.ParseFromArray(recv_buf,recv_size);
    response->set_is_success(tmp.is_success());
    response->set_fail_msg(tmp.fail_msg());

    close(client_fd);
    done->Run();
}