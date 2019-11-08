#include "db_handler.h"
#include "w1.h"
#include <QDebug>

Db_handler::Db_handler()
{

}

void Db_handler::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName("127.0.0.1");
    m_db.setDatabaseName(DB_PATH);
    bool ok = m_db.open();
    if (ok)
    {
        W1::get_instance().update_db_status(QString("连接成功"));
    }
    else
    {
        W1::get_instance().update_db_status(QString("连接成功"));
    }
}

Db_handler* Db_handler::get_instance()
{
    if(instance == nullptr)
    {
        instance = new Db_handler;
    }
    return instance;
}

Db_handler* Db_handler::instance = nullptr;


void Db_handler::whenclose()
{
    m_db.close();
    if(!m_db.isOpen())
    {
        //qDebug() << "wtf";
    }
}

int Db_handler::regist_db(const char *username, const char *password)
{
    QSqlQuery query;
    QString str=QString("select * from user where username=\"%1\"").
                    arg(username);
    query.exec(str);

    qDebug() << query.value(2) << query.value(1) ;

    if(query.first())
    {
        //qDebug() << "en?";
        return 2;//
    }
    else
    {
        //qDebug() << "en!";
        str=QString("INSERT INTO user (username, password) VALUES(\"%1\", \"%2\")")
                    .arg(username).arg(password);
        query.exec(str);
        return 1;
    }
}

int Db_handler::login_db(const char *username, const char *password)
{
    QSqlQuery query;
    QString str=QString("select * from user where username=\"%1\"").
                    arg(username);
    query.exec(str);

    if(!query.first())//用户名不存在
    {
        return 2;
    }
    //qDebug() << query.value(3) << query.value(0) <<query.value(1) << query.value(2);
    if(0 != strcmp(password, query.value(2).toString().toStdString().c_str()))
    {
        return 3; //密码错误
    }

    if(0 != query.value(3)) //已登录
    {
        //--------------------还需要增加登录标志-------------------------
        return 4;
    }

    return 1;
}










