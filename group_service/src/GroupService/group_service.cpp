#include "group_service.h"

#define BUFF_SIZE 128

GroupService::GroupService() : stub_(new MyRpcChannel), master_("/GroupService")
{
    master_.start();
}

void GroupService::AddGroup(::google::protobuf::RpcController *controller,
                            const ::rj_GroupService::AddGroupRequest *request,
                            ::rj_GroupService::AddGroupResponse *response,
                            ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    rj_GroupServer::Request send_request;
    rj_GroupService::AddGroupResponse response;
    //重新序列化
    send_request.set_type("AddGroup");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("addgroup command send error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("addgroup command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    char recv_buf[BUFF_SIZE] = {0};
    int recv_size = recv(client_fd, recv_buf, BUFF_SIZE, 0);
    if (recv_size == -1)
    {
        //如果发生失败
        controller->SetFailed("addggroup command recv error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("addgroup command recv error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }
    response->ParseFromArray(recv_buf, recv_size);
    done->Run();
}

void GroupService::CreateGroup(::google::protobuf::RpcController *controller,
                               const ::rj_GroupService::CreateGroupRequest *request,
                               ::rj_GroupService::CreateGroupResponse *response,
                               ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    rj_GroupServer::Request send_request;

    //重新序列化
    send_request.set_type("CreateGroup");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("creategroup command send error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("creategroup command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    char recv_buf[BUFF_SIZE] = {0};
    if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("creategroup command recv error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("creategroup command recv error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    response->ParseFromString(recv_buf);
    done->Run();
}

void GroupService::QuitGroup(::google::protobuf::RpcController *controller,
                             const ::rj_GroupService::QuitGroupRequest *request,
                             ::google::protobuf::Empty *response,
                             ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    rj_GroupServer::Request send_request;

    //重新序列化
    send_request.set_type("QuitGroup");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("quitgroup command send error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("quitgroup command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }
    done->Run();
}

void GroupService::GetGroupUsers(::google::protobuf::RpcController *controller,
                                 const ::rj_GroupService::GetGroupUsersRequest *request,
                                 ::rj_GroupService::GetGroupUsersResponse *response,
                                 ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    rj_GroupServer::Request send_request;

    //重新序列化
    send_request.set_type("GetGroupUsers");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("get group users command send error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("get group users command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    char recv_buf[BUFF_SIZE] = {0};
    if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("get group users command recv error");
        //打印错误信息
        rj_log::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("get group users command recv error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    response->ParseFromString(recv_buf);
    done->Run();
}