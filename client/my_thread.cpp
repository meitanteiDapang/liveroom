#include "my_thread.h"
#include "udp_socket.h"
#include "w1.h"
#include "w2.h"
#include "w3.h"
#include "protocol.h"
#include "common.h"
#include <QEventLoop>
#include <QTimer>

bool arimashida = true;

My_thread::My_thread()
{
    //connect(this, SIGNAL(go_on_process_picpic()), &m_loop, SLOT(quit()));
}

void My_thread::run()
{
//    QEventLoop loop;
//    QTimer* timer = new QTimer(this);
//    timer->setInterval(INTERVAL);
//    loop.exec();
//    qDebug() << "sa";

    //准备基础信息
    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.room_id = updu.id;
    strcpy(updu.username, W1::get_instance().get_username());
    updu.is_caster = true;//这是主播流
    updu.is_getout = false;


    //获得直播图片
    while(true)
    {
        //捕捉图像
        W3::get_instance().get_now_pic();

        //m_loop.exec();
        //将图像保存在updu里
        W3::get_instance().modify_updu_to_have_picdata(updu);

        //发送至服务器
        //W3::get_instance().send_udp_to_server(&updu);
        msleep(INTERVAL);
        if(!arimashida)
        {
            //qDebug() << "arimashida false";
            break;
        }
    }


}

void My_thread::fuck()
{
    //准备基础信息
    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.room_id = updu.id;
    strcpy(updu.username, W1::get_instance().get_username());
    updu.is_caster = true;//这是主播流
    updu.is_getout = false;


    //获得直播图片
//    while(true)
//    {
//        W3::get_instance().get_now_pic(updu);
//        W3::get_instance().send_udp_to_server(&updu);
//        msleep(INTERVAL);
//    }

    //捕捉图像
    W3::get_instance().get_now_pic();

    //将图像保存在updu里
    W3::get_instance().modify_updu_to_have_picdata(updu);

    //发送至服务器,并到上面了
    //W3::get_instance().send_udp_to_server(&updu);
    msleep(INTERVAL);
}
