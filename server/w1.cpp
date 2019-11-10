#include "w1.h"
#include "ui_w1.h"
#include <QDebug>

W1::W1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::W1)
{
    ui->setupUi(this);

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
    return My_server_tcp::get_instance();
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
                               "result为%4, data为%5,id:%6,roomid:%7,"
                               "balance:%8, count:%9, num:%10, isevent:%11\n").arg(pdu.msg_type)
                            .arg(pdu.username).arg(pdu.password)
                            .arg(pdu.result).arg(pdu.data).arg(pdu.id)
                            .arg(pdu.room_id).arg(double(pdu.balance)).arg(pdu.count)
                            .arg(pdu.num).arg(pdu.isevent);
        update_msg(data);
    }
    else
    {
        QString data = QString("-----------发送了,type为%1, username为%2, password为%3, "
                               "result为%4, data为%5,id:%6,roomid:%7,"
                               "balance:%8, count:%9, num:%10, isevent:%11\n").arg(pdu.msg_type)
                            .arg(pdu.username).arg(pdu.password)
                            .arg(pdu.result).arg(pdu.data).arg(pdu.id)
                            .arg(pdu.room_id).arg(double(pdu.balance)).arg(pdu.count)
                            .arg(pdu.num).arg(pdu.isevent);
        update_msg(data);
    }
}

QVector<int> &W1::get_online_user()
{
    return m_online_user;
}

MAP &W1::get_rooms()
{
    return m_rooms;
}

void W1::cancle_room(int room_id)
{
    m_rooms.remove(room_id);
}


void W1::on_pushButton_clicked()
{

    My_server_tcp::get_instance().listen(QHostAddress(ui->ip_le->text()), QString(ui->port_le->text()).toUShort());
    if(My_server_tcp::get_instance().isListening())
    {
        ui->status_label->setText("监听中");
    }
    else
    {
        ui->status_label->setText("没有监听");
    }
}

































