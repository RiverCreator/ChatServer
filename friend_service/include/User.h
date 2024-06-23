#include <string>
class User
{
public:
    //设置用户id
    void set_id(int id) { id_ = id; }

    //设置用户名
    void set_name(std::string name) { name_ = name; }

    //获得用户id
    int get_id() { return id_; }

    //获得用户名
    std::string get_name() { return name_; }

private:
    int id_;
    std::string name_;
};
