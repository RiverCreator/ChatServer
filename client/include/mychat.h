#include "client.h"



class MyChat{
public:
    MyChat(string ip,int port);
    ~MyChat();
    //循环，为主要操作逻辑
    void main_loop();
    //
    void Login(int id,string password);
    void Logout();
    void Registe(string name,string password);
    void GetUserInfo();
    void AddFriend();
    void DeleteFriend();
    void GetFriend();
    void AddGroup();
    void Chat();
    void ReadOffline();
    void CreateGroup();
    void GetGroupUser();
    void OnResponse(string& msg);
private:
    Client client;
    int curid; //当前用户id 
    unordered_map<string,int> groups; //映射群组名字与id
};