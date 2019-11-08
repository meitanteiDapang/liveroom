#include "my_socket_tcp.h"
#include "w1.h"
#include <string.h>

My_socket_tcp::My_socket_tcp()
{
    connect(this, SIGNAL(readyRead())
            , this, SLOT(receive_msg()));
}

void My_socket_tcp::regist_handler(Protocol& pdu)
{
    pdu.msg_type = REGIST_TYPE+ADD_RETURN;
    int ret = 1;
    ret = Db_handler::get_instance()->regist_db(pdu.username, pdu.password);

    switch(ret)
    {
        case 1: //注册成功
            pdu.result = true;
            break;
        case 2: //用户名重复,请换个用户名
            //qDebug() << "wfff";
            pdu.result = false;
            strcpy(pdu.data,"用户名重复，请换个用户名");
            break;
        default:
            break;
    }
}

void My_socket_tcp::login_handler(Protocol &pdu)
{

    pdu.msg_type = LOGIN_TYPE + ADD_RETURN;
    int ret = 1;
    ret = Db_handler::get_instance()->login_db(pdu.username, pdu.password);

    switch(ret)
    {
        case 1: //登录成功
            pdu.result = true;
            break;
        case 2: //用户名
            pdu.result = false;
            strcpy(pdu.data,"用户名不存在");
            break;
        case 3: //密码
            pdu.result = false;
            strcpy(pdu.data,"密码错误");
            break;
        case 4: //密码
            pdu.result = false;
            strcpy(pdu.data,"账户已登录");
            break;
        default:
            break;
    }

}

void My_socket_tcp::receive_msg()
{
    Protocol pdu;
    memset(&pdu, 0, sizeof(pdu));

    read((char*)&pdu, sizeof(pdu));
    //qDebug() << pdu.msg_type;
    W1::get_instance().add_protocol_msg(pdu, RECEIVE);
    switch (pdu.msg_type)
    {
    case REGIST_TYPE:   //注册
        regist_handler(pdu);
        break;
    case LOGIN_TYPE:  //登录
        login_handler(pdu);
        break;
    case 2:

        break;
    default:
        break;
    }
    W1::get_instance().add_protocol_msg(pdu, SEND);
    write((char*)&pdu, sizeof(pdu));
}
