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

int Db_handler::login_db(const char *username, const char *password, int& gid)
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

    int id = query.value(0).toInt();//检测是否重复登录
    QVector<int>::iterator iter = W1::get_instance().get_online_user().begin();

    for( ;iter!=W1::get_instance().get_online_user().end(); iter++ )//已登录
    {
        if(id == *iter)
        {
            return 4;
        }
    }

    //准备登录，将在线名单放入链表中;
    W1::get_instance().get_online_user().push_back(id);
    gid = id;
    return 1;
}

void Db_handler::logout_db(const int id)
{
    QVector<int>::iterator iter = W1::get_instance().get_online_user().begin();
    int i = 0;
    for( ;iter!=W1::get_instance().get_online_user().end(); iter++ )//已登录
    {
        if(id == *iter)
        {

            W1::get_instance().get_online_user().remove(i);
            return;
        }
        i++;
    }
    return;//不存在,不过无所谓了。
}










