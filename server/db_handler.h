#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

//服务器端的数据库处理文件， 所有需要数据库处理的过程都在这边被封装成函数

class Db_handler
{
public:

    void init();

    static Db_handler* get_instance();
    void whenclose();
    int regist_db(const char* username, const char* password);
    int login_db(const char* username, const char* password, int& gid, float& gbalance, int& gcredit);
    void logout_db(const int id);
    int topup_db(const int id, const float money ,float& gbalance);
    int get_balance_db(const int id, float& gbalance, int& gcredit);
    int rocket_db(const int id, const int room_id);
    int get_roomname_by_id(const int id, char* username);


private:
    Db_handler();
    static Db_handler* instance;
    QSqlDatabase m_db;
};


#endif // DB_HANDLER_H
