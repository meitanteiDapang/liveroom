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

void My_thread::oklala()
{

}

void My_thread::run()
{

#if 1
    while (true)
    {
        W3::get_instance().get_now_pic();
        //我们需要在图片截图已经保存完成后再进行下面操作，要不然画面会卡

        while(W3::get_instance().is_capture_done)
        {
            usleep(TIMER_TIME);
        }
        msleep(200);
        //已经获得图片啦
        W3::get_instance().m_buffer->open(QIODevice::ReadWrite);
        W3::get_instance().m_pic_pic->save(W3::get_instance().m_buffer, "png");

        qint64 ret = 0;
        qint64 iSended = 0;
        qint64 iLefted = W3::get_instance().m_bytearray->size();
        static const char *p = nullptr;
        p = W3::get_instance().m_bytearray->constData();
        //qDebug() << "\n\n total size = " << iLefted;
        while(iLefted)
        {
            if (iLefted > PIC_MAX_SIZE)
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, PIC_MAX_SIZE
                            , QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            else
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, iLefted
                            ,QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            if (0 == ret)
            {
                break;
            }
            else if (-1 == ret)
            {
                ret = 0;
            }
            else
            {
                iLefted -= ret;
                iSended += ret;
            }
            usleep(TIMER_TIME);
        }
        W3::get_instance().m_bytearray->clear();

        //qDebug() << "my_thread此次截屏总共发送的数据大小 = " << iSended;

        Udp_socket::get_instance().get_udp_socket().
                                writeDatagram("end", 3
                                    ,QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
        if(!arimashida)
        {
            break;
        }
    }

#endif


#if 1
    while (true)
    {
        W3::get_instance().get_now_pic();
        msleep(2500);
        //已经获得图片啦
        W3::get_instance().m_buffer->open(QIODevice::ReadWrite);
        W3::get_instance().m_pic_pic->save(W3::get_instance().m_buffer, "png");

        qint64 ret = 0;
        qint64 iSended = 0;
        qint64 iLefted = W3::get_instance().m_bytearray->size();
        static const char *p = nullptr;
        p = W3::get_instance().m_bytearray->constData();
        //qDebug() << "\n\n total size = " << iLefted;
        while(iLefted)
        {
            if (iLefted > PIC_MAX_SIZE)
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, PIC_MAX_SIZE
                            , QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            else
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, iLefted
                            ,QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            if (0 == ret)
            {
                break;
            }
            else if (-1 == ret)
            {
                ret = 0;
            }
            else
            {
                iLefted -= ret;
                iSended += ret;
            }
            usleep(TIMER_TIME);
        }
        W3::get_instance().m_bytearray->clear();

        //qDebug() << "my_thread此次截屏总共发送的数据大小 = " << iSended;

        Udp_socket::get_instance().get_udp_socket().
                                writeDatagram("end", 3
                                    ,QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
        if(!arimashida)
        {
            break;
        }
    }

#endif


#if 0
    while(true)
    {
        //捕捉图像保存在W3的pic_pic里
        W3::get_instance().get_now_pic();

        //将pic_pic分解，发送往服务器端
        W3::get_instance().pic_pic_handler_and_send();

        msleep(INTERVAL);
        if(!arimashida)
        {
            //qDebug() << "arimashida false";
            break;
        }
    }
#endif

#if 0
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
#endif

}



void My_thread::fuck()
{
    //无效函数
//    //准备基础信息
//    Udp_pro updu;
//    memset(&updu, 0, sizeof(Udp_pro));
//    updu.id = W1::get_instance().get_id();
//    updu.room_id = updu.id;
//    strcpy(updu.username, W1::get_instance().get_username());
//    updu.is_caster = true;//这是主播流
//    updu.is_getout = false;


//    //获得直播图片
////    while(true)
////    {
////        W3::get_instance().get_now_pic(updu);
////        W3::get_instance().send_udp_to_server(&updu);
////        msleep(INTERVAL);
////    }

//    //捕捉图像
//    W3::get_instance().get_now_pic();

//    //将图像保存在updu里
//    W3::get_instance().modify_updu_to_have_picdata(updu);

//    //发送至服务器,并到上面了
//    //W3::get_instance().send_udp_to_server(&updu);
//    msleep(INTERVAL);
}
