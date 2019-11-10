#ifndef DB_HANDLER_H
#define DB_HANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Db_handler
{
public:

    void init();

    static Db_handler* get_instance();
    void whenclose();
    int regist_db(const char* username, const char* password);
    int login_db(const char* username, const char* password, int& gid, float& gbalance);
    void logout_db(const int id);
    int topup_db(const int id, const float money ,float& gbalance);
    int get_balance_db(const int id, float& gbalance);
    int rocket_db(const int id);
private:
    Db_handler();
    static Db_handler* instance;
    QSqlDatabase m_db;
};


#endif // DB_HANDLER_H
