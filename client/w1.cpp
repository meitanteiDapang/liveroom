#include "w1.h"
#include "ui_w1.h"

#include <QMessageBox>
#include <QHostAddress>
#include "w2.h"
#include <string.h>
#include <QDebug>

#include "w3.h"

//int m_id = 0;

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

 int W1::get_id()
 {
     return m_id;
 }

 void W1::set_id(int id)
 {
    m_id = id;
 }

 char* W1::get_username()
 {
    return m_username;
 }

 void W1::set_username(char* username)
 {
    strcpy(m_username, username);
 }



void W1::show_connect()
{
    if(m_socket_tcp.isOpen())
    ui->wft->setText(QString("已连接至服务器!anshinshiroyo"));
}

void W1::receive_msg()
{
    Protocol pdu;
    while(m_socket_tcp.read((char*)&pdu, sizeof(pdu)))
    {
        switch (pdu.msg_type) {
        case REGIST_TYPE+ADD_RETURN://注册
            if (pdu.result)
            {
                QMessageBox::information(this, "注册", "注册成功");
            }
            else
            {
                QMessageBox::critical(this, "注册", QString(pdu.data));
            }
            break;
        case LOGIN_TYPE+ADD_RETURN://登录啦
            if (pdu.result)
            {

                m_id = pdu.id;
                hide();
                set_username(pdu.username);
                W2::get_instance().set_username_label(pdu.username);
                W2::get_instance().set_balance_label(pdu.balance);
                W2::get_instance().reload_stringlist();
                W2::get_instance().show();
            }
            else
            {
                QMessageBox::critical(this, "登录", QString(pdu.data));
            }
            break;
        case CREATE_TYPE+ADD_RETURN:
            if(pdu.result)
            {
                W3::get_instance().being_caster();
                W3::get_instance().set_room_id(pdu.room_id);
                W3::get_instance().show();
                W2::get_instance().hide();
                W3::get_instance().start_camera_selfie();
                W3::get_instance().get_viewfinder()->show();

                //直播推流相关
            }
            else
            {
                QMessageBox::critical(this, "创建房间", QString(pdu.data));
            }
            break;
        case CASTER_QUIT_TYPE+ADD_RETURN://观众被动退出
            if(pdu.room_id == W3::get_instance().get_room_id() && !(W3::get_instance().get_is_caster()))
            {
                QMessageBox::information(this, "主播退出", pdu.data);
                //开始退出
                W3::get_instance().set_room_id(0);
                W3::get_instance().hide();


                W2::get_instance().reload_stringlist();
                W2::get_instance().reload_balance();
                W2::get_instance().show();

            }

            break;
        case QUIT_ROOM_TYPE+ADD_RETURN:
            if(W3::get_instance().get_is_caster())//主播退出
            {
                if(pdu.result)
                {
                    W3::get_instance().get_camera()->stop();
                    W3::get_instance().get_viewfinder()->hide();
                    if(!pdu.isevent)
                    {
                        W2::get_instance().reload_stringlist();
                        W2::get_instance().reload_balance();
                        W2::get_instance().set_balance_label(pdu.balance);
                        W2::get_instance().show();//看下是不是选用哪种状态
                        W3::get_instance().hide();
                        W3::get_instance().set_room_id(0);

                    }
                }
                else
                {
                    QMessageBox::critical(this, "退出房间", QString(pdu.data));
                }
            }
            else//观众主动退出
            {
                W3::get_instance().set_room_id(0);
                W3::get_instance().hide();


                W2::get_instance().reload_stringlist();
                W2::get_instance().reload_balance();
                W2::get_instance().show();
            }
            break;
        case RELOAD_LIST_TYPE+ADD_RETURN:
            if(pdu.result)
            {
                W2::get_instance().insert_lv(QString("%1").arg(pdu.room_id));
                W2::get_instance().count_list_plus_plus();
                W2::get_instance().load_room_list();

            }
            else//读完啦，没啦
            {

            }
            break;
        case TOPUP_TYPE+ADD_RETURN:
            if(pdu.result)//充值成功
            {
                //qDebug() << "case" << pdu.balance;
                QMessageBox::information(this, "充值", "充值成功");
                W2::get_instance().set_balance_label(pdu.balance);
                W2::get_instance().clear_money_le();

            }
            else//充值失败
            {
                QMessageBox::information(this, "充值", QString(pdu.data));
            }
            break;
        case ENTER_ROOM_TYPE+ADD_RETURN:

            if(pdu.result)//允许进入
            {
                W2::get_instance().hide();

                //直播相关启动收流
                W3::get_instance().being_audience();
                W3::get_instance().set_room_id(pdu.room_id);
                W3::get_instance().show();
            }
            else//不允许进入
            {
                QMessageBox::information(this, "进入房间", QString(pdu.data));
            }
            break;
        case GROUP_CHAT_TYPE+ADD_RETURN:
            if(pdu.room_id == W3::get_instance().get_room_id())//判断自己是否在指定房间内，解释请参考服务器端相关注释
            {
                char data[192];
                sprintf(data, "%s:%s", pdu.username, pdu.data);
                W3::get_instance().add_chat_text(QString(data));
            }
            break;
        case GET_BALANCE_TYPE+ADD_RETURN:
            if(pdu.result)//显示成功，always
            {
                //qDebug() << "case" << pdu.balance;
                //QMessageBox::information(this, "充值", "充值成功");
                W2::get_instance().set_balance_label(pdu.balance);
                W2::get_instance().clear_money_le();
            }
            else//显示失败，迷
            {
                //QMessageBox::information(this, "充值", QString(pdu.data));
            }
            break;
        case SEND_ROCKET_TYPE+ADD_RETURN:
            if(pdu.result)
            {
                //发送成功了，不用显示
            }
            else//发送火箭失败
            {
                QMessageBox::information(this, "发送火箭", QString(pdu.data));
            }

            break;
        case COMMING_ROCKET_TYPE+ADD_RETURN://有人发火箭
            if(pdu.room_id == W3::get_instance().get_room_id())
            {
                char data[192];
                sprintf(data, "%s发送了一个火箭", pdu.username);
                W3::get_instance().add_chat_text(QString(data));
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}

void W1::logout_fun()
{
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = LOGOUT_TYPE;
    pdu.id = m_id;
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
        pdu.msg_type = REGIST_TYPE;
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
