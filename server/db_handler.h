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
    int login_db(const char* username, const char* password);
private:
    Db_handler();
    static Db_handler* instance;
    QSqlDatabase m_db;
};


#endif // DB_HANDLER_H
