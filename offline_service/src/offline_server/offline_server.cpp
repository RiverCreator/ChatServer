#include "offline_server.h"

#define BUFF_SIZE 128

using namespace placeholders;

//初始化配置等信息
OfflineServer::OfflineServer(string ip, int port, string config_name):ip_(ip),port_(port),server_(ip,port,4)
{

    pool_ = Connect_pool::get_instance(config_name);
}

//开始服务
void OfflineServer::run()
{

    //连接事件回调函数，读写事件回调函数
    server_.setonmessagecb(bind(&OfflineServer::on_message, this, _1, _2));
    server_.setnewconnectioncb(bind(&OfflineServer::on_connect, this, _1));

    zk_client_.Start();
    string server_path = "/OfflineService";
    zk_client_.Create(server_path.c_str(), nullptr, 0);
    server_path += "/server";
    string host = ip_ + ":" + to_string(port_);
    zk_client_.Create(server_path.c_str(), host.c_str(), host.size(), ZOO_SEQUENCE);

    server_.start();
}

//读写事件回调函数
void OfflineServer::on_message(const spConnection conn, string& recv)
{
    rj_OfflineServer::Request request;
    request.ParseFromString(recv);
    if (request.type() == "WriteOffline")
    {
        //反序列化
        rj_OfflineServer::WriteOfflineRequest write_request;
        write_request.ParseFromString(request.request_msg());
        int friend_id = write_request.friend_id(); //接收方id
        int from_id = write_request.user_id(); //发送方id
        string msg = write_request.msg(); //离线信息

        //写入数据库
        write_offlineMsg(friend_id, from_id, msg);
    }
    else if (request.type() == "ReadOffline")
    {
        //反序列化
        rj_OfflineServer::ReadOfflineRequest read_request;
        read_request.ParseFromString(request.request_msg());
        int userid = read_request.myid();

        //执行业务
        vector<pair<int,string>> offline_msg = read_offlineMsg(userid); //表示从from_id 和msg

        //序列化
        rj_OfflineServer::ReadOfflineResponse response;
        for (int i = 0; i < offline_msg.size(); i++)
        {
            auto t=response.add_msgs();
            t->set_from_id(offline_msg[i].first);
            t->set_msg(offline_msg[i].second);
        }
        response.set_is_success(true);
        //信息发送
        string send = response.SerializeAsString();
        conn->send(send,send.size());
    }
}

//连接事件回调函数
void OfflineServer::on_connect(const spConnection conn)
{

}

//写离线消息
bool OfflineServer::write_offlineMsg(int friend_id, int from_id, string msg)
{
    //获取连接池连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into OfflineMessage values(%d, %d,'%s')", from_id, friend_id, msg.c_str());
    return conn->update(sql);
}

//读离线消息
vector<pair<int,string>> OfflineServer::read_offlineMsg(int myid)
{
    //获取连接池连接
    shared_ptr<Connect> conn = pool_->get_connect();

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select fromid, message from OfflineMessage where userid=%d", myid);
    MYSQL_RES *res = conn->query(sql);
    if(res==nullptr){
        return {};
    }
    MYSQL_ROW row;

    vector<pair<int,string>> ret;
    while (row = mysql_fetch_row(res))
    {
        ret.emplace_back(atoi(row[0]),row[1]);
    }

    mysql_free_result(res);

    //删除原来的离线消息
    memset(sql, 0, BUFF_SIZE);
    sprintf(sql, "delete from OfflineMessage where userid=%d", myid);
    conn->update(sql);
    return ret;
}
