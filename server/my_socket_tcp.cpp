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
    ret = Db_handler::get_instance()->login_db(pdu.username, pdu.password, pdu.id, pdu.balance, pdu.credit);

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
    pdu.msg_type = LOGOUT_TYPE+ADD_RETURN;
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
        //strcpy(pdu.roomname, pdu.roomname);
        QVector<int> here;
        here.push_back(pdu.id);
        W1::get_instance().get_rooms().insert(pdu.id, here);
    }

}

void My_socket_tcp::quit_room_handler(Protocol &pdu)
{
    //qDebug() <<W1::get_instance().get_rooms().begin().key() <<  W1::get_instance().get_rooms().begin().value();
    //qDebug() << pdu.result << pdu.room_id;
    //qDebug() << pdu.isevent;
    if(pdu.result)//is_caster?
    {
        MAP::iterator iter = W1::get_instance().get_rooms().find(pdu.room_id);
        int room_id = pdu.room_id;
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
                pdu.room_id = room_id;//告诉观众是哪个主播滚了
                My_server_tcp::get_instance().to_all(pdu);
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
        pdu.msg_type = QUIT_ROOM_TYPE+ADD_RETURN;
        MAP::iterator iter = W1::get_instance().get_rooms().find(pdu.room_id);
        //int room_id = pdu.room_id;
        if(iter != W1::get_instance().get_rooms().end())//找到存在了
        {
            iter->removeAll(pdu.id);//OK吗
        }
        else
        {
            //不可能发生
        }
        pdu.result = true;
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

void My_socket_tcp::enter_room_handler(Protocol &pdu)
{
    pdu.msg_type = ENTER_ROOM_TYPE+ADD_RETURN;
    MAP::iterator iter = W1::get_instance().get_rooms().find(pdu.room_id);
    //qDebug() << 1;
    if(iter != W1::get_instance().get_rooms().end())//找到存在了
    {
        //先向房间内其他用户发布有人来了信息
        //qDebug() << 2;
        pdu.msg_type = GROUP_CHAT_TYPE+ADD_RETURN;
        sprintf(pdu.data, "欢迎%s进入直播间", pdu.username);
        strcpy(pdu.username, "system");//这两条顺序很重要，不然username会被覆盖掉
        int room_id = pdu.room_id;//防止以后有改动，先写这
        /*
            这里遍历所有的socket_tcp都给他发过去，到了客户端匹配room_id，再看是否显现。
            更好的方法是，登录的时候在服务器将socket与id匹配，不过这边由于登录登出都已经
            写好了，就不那样写了！！！
         */
        //qDebug() << 3;

        My_server_tcp::get_instance().to_all(pdu);


//        QVector<My_socket_tcp* >::iterator socketit = My_server_tcp::get_instance()
//                                        .get_socket_vec().begin();
//        for(;socketit !=  My_server_tcp::get_instance()
//            .get_socket_vec().end();socketit++)
//        {
//            qDebug() << 4;
//            W1::get_instance().add_protocol_msg(pdu, SEND);
//            qDebug() << 6;
//            (*socketit)->write((char*)&pdu, sizeof(pdu));
//        }

        //qDebug() << 5;
        memset(&pdu, 0, sizeof(pdu));
        //最后向刚进入房间用户发送包包
        pdu.msg_type = ENTER_ROOM_TYPE+ADD_RETURN;
        pdu.result = true;
        pdu.room_id = room_id;
        iter->push_back(pdu.id);
        Db_handler::get_instance()->get_roomname_by_id(pdu.room_id, pdu.roomname);
    }
    else
    {
        pdu.result = false;
        strcpy(pdu.data, "房间不存在，主播可能已经下播，请刷新重试");
    }
}

void My_socket_tcp::group_chat_handler(Protocol &pdu, bool& hei)
{
    pdu.msg_type = GROUP_CHAT_TYPE+ADD_RETURN;
    My_server_tcp::get_instance().to_all(pdu);
    hei = false;
}

void My_socket_tcp::get_balance_handler(Protocol &pdu)
{
    pdu.msg_type = GET_BALANCE_TYPE+ADD_RETURN;
    int ret = 1;
    float now_balance;
    int now_credit;
    ret = Db_handler::get_instance()->get_balance_db(pdu.id, now_balance, now_credit);
    if(ret == 1)
    {
        pdu.result = true;
        pdu.balance = now_balance;
        pdu.credit = now_credit;
    }
    else
    {
        pdu.result = false;
        strcpy(pdu.data, "找不到id,非法id迷之错误");
    }
}

void My_socket_tcp::rocket_handler(Protocol &pdu)
{


    int ret = 1;
    if(pdu.id == pdu.room_id)//给自己发火箭不行
    {
        pdu.result = false;
        pdu.msg_type = SEND_ROCKET_TYPE+ADD_RETURN;
        strcpy(pdu.data, "不能给自己发火箭");
        return;
    }

    ret = Db_handler::get_instance()->rocket_db(pdu.id, pdu.room_id);
    if(ret == 1)
    {
        pdu.msg_type = COMMING_ROCKET_TYPE+ADD_RETURN;
        My_server_tcp::get_instance().to_all(pdu);
        pdu.result = true;
    }
    else if(ret == 3)
    {
        pdu.result = false;
        strcpy(pdu.data, "钱不够，穷逼");
    }
    else
    {
        pdu.result = false;
        strcpy(pdu.data, "非法id，迷之错误");
    }
    pdu.msg_type = SEND_ROCKET_TYPE+ADD_RETURN;
}

void My_socket_tcp::receive_msg()
{
    Protocol pdu;
    memset(&pdu, 0, sizeof(pdu));
    bool hei;
    while(read((char*)&pdu, sizeof(pdu)))
    //qDebug() << pdu.msg_type;
    {
        hei = true;
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
        case ENTER_ROOM_TYPE://观众啦
            //qDebug() << pdu.room_id;
            //qDebug() << pdu.username;
            enter_room_handler(pdu);
            break;
        case GROUP_CHAT_TYPE:
            group_chat_handler(pdu, hei);
            break;
        case GET_BALANCE_TYPE:
            get_balance_handler(pdu);

            break;
        case SEND_ROCKET_TYPE:
            rocket_handler(pdu);
            break;
        case 10000001:

            break;
        case 10000006:

            break;
        case 10000007:

            break;
        case 10000008:

            break;
        default:
            break;
        }
        if(hei)
        {
            W1::get_instance().add_protocol_msg(pdu, SEND);
            write((char*)&pdu, sizeof(pdu));
        }
    }
}
