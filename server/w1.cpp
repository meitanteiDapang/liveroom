#include "w1.h"
#include "ui_w1.h"
#include <QDebug>

W1::W1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::W1)
{
    ui->setupUi(this);
    m_server.listen(QHostAddress(IP_ADDRESS), QString(PORT).toUShort());
    if(m_server.isListening())
    {
        ui->status_label->setText("监听中");
    }
    else
    {
        ui->status_label->setText("没有监听");
    }
}

W1::~W1()
{
    Db_handler::get_instance()->whenclose();
    //qDebug() << "123";
    delete ui;
    //qDebug() << "123";
}

W1 &W1::get_instance()
{
    static W1 instance;
    return instance;
}

My_server_tcp &W1::get_server_tcp()
{
    return m_server;
}

void W1::update_msg(QString msg)
{
    ui->tb->append(msg);
}

void W1::update_db_status(QString msg)
{
    ui->wft->setText(msg);
}

void W1::add_protocol_msg(Protocol &pdu, bool mode)
{
    if(mode)
    {
        QString data = QString("接收了,type为%1, username为%2, password为%3, "
                               "result为%4, data为%5\n").arg(pdu.msg_type)
                            .arg(pdu.username).arg(pdu.password)
                            .arg(pdu.result).arg(pdu.data);
        update_msg(data);
    }
    else
    {
        QString data = QString("发送了,type为%1"
                               "result为%2\n").arg(pdu.msg_type).arg(pdu.result);
        update_msg(data);
    }
}


































