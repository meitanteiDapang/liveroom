#include "my_socket_tcp.h"
#include "w1.h"
#include <string.h>
#include <QVector>

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
    ret = Db_handler::get_instance()->login_db(pdu.username, pdu.password, pdu.id, pdu.balance);

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

void My_socket_tcp::logout_handler(Protocol &pdu)
{
    Db_handler::get_instance()->logout_db(pdu.id);
}

void My_socket_tcp::create_handler(Protocol &pdu)
{
    pdu.msg_type = CREATE_TYPE + ADD_RETURN;
    MAP::iterator iter = W1::get_instance().get_rooms().find(pdu.id);
    if(iter != W1::get_instance().get_rooms().end())//找到存在了
    {
        pdu.result = false;
        pdu.room_id = pdu.id;
        strcpy(pdu.data, "已经创建了房间00");
        return;
    }
    else
    {
        pdu.result = true;
        pdu.room_id = pdu.id;
        QVector<int> here;
        here.push_back(pdu.id);
        W1::get_instance().get_rooms().insert(pdu.id, here);
    }

}

void My_socket_tcp::quit_room_handler(Protocol &pdu)
{
    //qDebug() <<W1::get_instance().get_rooms().begin().key() <<  W1::get_instance().get_rooms().begin().value();
    //qDebug() << pdu.result << pdu.room_id;
    qDebug() << pdu.isevent;
    if(pdu.result)//is_caster?
    {
        MAP::iterator iter = W1::get_instance().get_rooms().find(pdu.room_id);
        if(iter != W1::get_instance().get_rooms().end())//找到存在了
        {
            //qDebug() << 1 << pdu.msg_type;
            //先向所有观众发送滚信号

            QVector<int>::iterator hereit = iter->begin();
            hereit++;//跳过主播
            for(;hereit!= iter->end();hereit++)
            {
                //qDebug() << 2 << pdu.msg_type;
                pdu.msg_type = CASTER_QUIT_TYPE+ADD_RETURN;//203
                strcpy(pdu.data, "主播已经滚啦!!");
                W1::get_instance().add_protocol_msg(pdu, SEND);
                write((char*)&pdu, sizeof(pdu));
            }
            pdu.msg_type = QUIT_ROOM_TYPE+ADD_RETURN; //202
            //qDebug() << 3 << pdu.msg_type;
            W1::get_instance().cancle_room(pdu.room_id);
            pdu.result = true;
        }
        else
        {
            pdu.msg_type = QUIT_ROOM_TYPE+ADD_RETURN; //202
            //qDebug() << 4 << pdu.msg_type;
            pdu.result = false;
            strcpy(pdu.data, "无法退出，迷之错误");
        }
    }
    else//观众主动退出
    {

    }

}

void My_socket_tcp::load_list_handler(Protocol& pdu)
{
    pdu.msg_type = RELOAD_LIST_TYPE + ADD_RETURN;
    //qDebug() << W1::get_instance().get_rooms().size() << pdu.count;
    if(pdu.count < W1::get_instance().get_rooms().size())
    {
        pdu.result = true;
        MAP::iterator iter = W1::get_instance().get_rooms().begin();
        int i = 0;
        for(i = 0; i < pdu.count; i++)
        {
            iter++;
        }
        pdu.room_id = (*iter)[0];
        pdu.num = iter->size() - 1;
    }
    else
    {
        pdu.result = false;
    }
}

void My_socket_tcp::topup_handler(Protocol &pdu)
{
    pdu.msg_type = TOPUP_TYPE+ADD_RETURN;
    int ret = 1;
    float now_balance;
    ret = Db_handler::get_instance()->topup_db(pdu.id, pdu.money, now_balance);

    switch(ret)
    {
        case 1: //充值成功
            pdu.result = true;
            pdu.balance = now_balance;
            //qDebug() << "topuph" << pdu.balance;
            break;
        case 2:
            pdu.result = false;
            strcpy(pdu.data, "找不到用户，迷之错误");
            break;
        default:
            break;
    }
}


void My_socket_tcp::receive_msg()
{
    Protocol pdu;
    memset(&pdu, 0, sizeof(pdu));

    while(read((char*)&pdu, sizeof(pdu)))
    //qDebug() << pdu.msg_type;
    {
        W1::get_instance().add_protocol_msg(pdu, RECEIVE);
        switch (pdu.msg_type)
        {
        case REGIST_TYPE:   //注册
            regist_handler(pdu);
            break;
        case LOGIN_TYPE:  //登录
            login_handler(pdu);
            break;
        case LOGOUT_TYPE:  //登录
            logout_handler(pdu);
            break;
        case CREATE_TYPE:
            //qDebug() << "switch" << pdu.id;
            create_handler(pdu);
            break;
        case QUIT_ROOM_TYPE:
            //qDebug() << "before" << pdu.isevent;
            quit_room_handler(pdu);
            //qDebug() << "before" << pdu.isevent;
            break;
        case RELOAD_LIST_TYPE:
            load_list_handler(pdu);
            break;
        case TOPUP_TYPE:
            topup_handler(pdu);
            break;
        case 10000002:

            break;
        case 10000003:

            break;
        case 10000004:

            break;
        case 10000005:

            break;
        default:
            break;
        }
        W1::get_instance().add_protocol_msg(pdu, SEND);
        write((char*)&pdu, sizeof(pdu));
    }
}
