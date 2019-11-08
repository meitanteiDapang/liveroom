#include "w1.h"
#include "ui_w1.h"

#include <QMessageBox>
#include <QHostAddress>
#include "w2.h"
#include <string.h>
#include <QDebug>

static int id_global = 0;

W1::W1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::W1)
{
    ui->setupUi(this);

    //连接至服务器
    connect_to_server();

    //槽函数connect 连接connected信号与readready信号
    connect(&m_socket_tcp, SIGNAL(connected())
            , this, SLOT(show_connect()));
    connect(&m_socket_tcp, SIGNAL(readyRead())
            , this, SLOT(receive_msg()));

    connect(ui->password_le,SIGNAL(returnPressed()), this, SLOT(on_login_pb_clicked()));
}

W1::~W1()
{
    delete ui;
}

void W1::connect_to_server()
{
    m_socket_tcp.connectToHost(QHostAddress(IP_ADDRESS), QString(PORT).toUShort());
}

 W1 &W1::get_instance()
{
     static W1 instance;
     return instance;
 }

 QTcpSocket &W1::get_socket_tcp()
 {
     return m_socket_tcp;
 }

 void W1::reload_widget()
 {
    ui->password_le->clear();
 }

void W1::show_connect()
{
    if(m_socket_tcp.isOpen())
    ui->wft->setText(QString("已连接至服务器!anshinshiroyo"));
}

void W1::receive_msg()
{
    Protocol pdu;
    m_socket_tcp.read((char*)&pdu, sizeof(pdu));
    //qDebug() << pdu.msg_type << "ggg" << pdu.result;

    switch (pdu.msg_type) {
    case REGIST_TYPE+ADD_RETURN:
        if (pdu.result)
        {
            QMessageBox::information(this, "注册", "注册成功");
        }
        else
        {
            QMessageBox::critical(this, "注册", QString(pdu.data));
        }
        break;
    case LOGIN_TYPE+ADD_RETURN:
        if (pdu.result)
        {
            QMessageBox::information(this, "登录", "登录成功");
            id_global = pdu.id;
            hide();
            W2::get_instance().show();
        }
        else
        {
            QMessageBox::critical(this, "登录", QString(pdu.data));
        }
        break;
    case 101:
        break;
    case 2:
        break;
    default:
        break;
    }
}

void W1::logout_fun()
{
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = LOGOUT_TYPE;
    pdu.id = id_global;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
}


void W1::on_login_pb_clicked()
{
    QString usr = ui->username_le->text();
    QString pwd = ui->password_le->text();
    if (!usr.isEmpty() && !pwd.isEmpty())
    {
        Protocol pdu;
        memset(&pdu, 0 ,sizeof(pdu));
        pdu.msg_type = LOGIN_TYPE;
        strcpy(pdu.username, usr.toStdString().c_str());
        strcpy(pdu.password, pwd.toStdString().c_str());
        m_socket_tcp.write((char*)&pdu, sizeof(pdu));
        //qDebug() << ret;
    }
    else
    {
        QMessageBox::information(this, "注册",QString("这俩可不能为空"));
    }
}

void W1::on_regist_pb_clicked()
{
    QString usr = ui->username_le->text();
    QString pwd = ui->password_le->text();
    if (!usr.isEmpty() && !pwd.isEmpty())
    {
        Protocol pdu;
        memset(&pdu, 0 ,sizeof(pdu));
        pdu.msg_type = LOGOUT_TYPE;

        m_socket_tcp.write((char*)&pdu, sizeof(pdu));
        //qDebug() << ret;
    }
    else
    {
        QMessageBox::information(this, "注册",QString("这俩可不能为空"));
    }

}
