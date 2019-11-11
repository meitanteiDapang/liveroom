#include "my_thread_audience_read.h"
#include "udp_socket.h"
#include "w1.h"
#include "w2.h"
#include "w3.h"
#include "protocol.h"

//暂时弃用

My_thread_audience_read::My_thread_audience_read()
{

}

void My_thread_audience_read::run()
{
    while(true)
    {
        qDebug() << "123123123123";
        //只有观众会收到这个包哦
        qint64 size = Udp_socket::get_instance().get_udp_socket().bytesAvailable();
        if(size != sizeof(Udp_pro) || size == 0)
        {
            qDebug() << "非法包";
            return;
        }
        else
        {
            //qDebug() << "正常包";
        }
        //QByteArray data;
        //data.resize(int(size));

        Udp_pro updu;

        QHostAddress client_host;
        quint16 client_port;
        qDebug() << "122222非法包";
        Udp_socket::get_instance().get_udp_socket().readDatagram((char*)(&updu), size, &client_host, &client_port);

        qDebug() << "wawawa"<<updu.id;
        //将数据用起来，显示起来
        W3::get_instance().add_chat_text(QString("%1").arg(updu.id));
        msleep(1000);
    }
}
