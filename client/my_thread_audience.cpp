#include "my_thread.h"
#include "udp_socket.h"
#include "w1.h"
#include "w2.h"
#include "w3.h"
#include "protocol.h"

//暂时弃用

My_thread_audience::My_thread_audience()
{

}

void My_thread_audience::run()
{

    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.room_id = W3::get_instance().get_room_id();
    strcpy(updu.username, W1::get_instance().get_username());
    updu.is_caster = false;

    //qDebug() << "audience ready" << updu.id << updu.room_id << updu.is_caster;
    W3::get_instance().send_udp_to_server(&updu);
    //qDebug() << "audience ready" << updu.id << updu.room_id << updu.is_caster;

//    while(true)
//    {
//        qDebug() << "123123123123";
//        //只有观众会收到这个包哦
//        qint64 size = Udp_socket::get_instance().get_udp_socket().bytesAvailable();
//        if(size != sizeof(Udp_pro))
//        {
//            //qDebug() << "非法包";
//            return;
//        }
//        else
//        {
//            //qDebug() << "正常包";
//        }
//        //QByteArray data;
//        //data.resize(int(size));

//        Udp_pro updu;

//        QHostAddress client_host;
//        quint16 client_port;
//        Udp_socket::get_instance().get_udp_socket().readDatagram((char*)(&updu), size, &client_host, &client_port);

//        qDebug() << "wawawa"<<updu.id;
//        //将数据用起来，显示起来
//        W3::get_instance().add_chat_text(QString("%1").arg(updu.id));
//        msleep(1000);
//    }
}
