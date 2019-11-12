#include <protocol.h>
#include "w3.h"
#include <QDebug>
#include "udp_socket_audience.h"

Udp_socket_audience::Udp_socket_audience(QWidget *parent) : QWidget(parent)
{
    connect(&m_socket_udp, SIGNAL(readyRead()), this, SLOT(recv_msg()));
}

QUdpSocket &Udp_socket_audience::get_udp_socket()
{
    return m_socket_udp;
}

//将线程分离

Udp_socket_audience& Udp_socket_audience::get_instance()
{
    static Udp_socket_audience instance;
    return instance;
}


void Udp_socket_audience::recv_msg()
{
#if 0
    QByteArray buf;
    qint64 ret = 0;
    int geshu = 0;
    Udp_pro* updu = nullptr;

    qDebug() << "############################";
    while (m_socket_udp.hasPendingDatagrams())
    {
        buf.resize(int(m_socket_udp.pendingDatagramSize()));
        ret = m_socket_udp.readDatagram(buf.data(), buf.size());
        qDebug() << "rsize=" << ret;
        geshu = int(ret) / int(sizeof(Udp_pro));
        int i = 0;
        for(i = 0; i < geshu; i++)
        {
            updu = (Udp_pro*)((buf).data());

        }
    }
#endif
//    qDebug() << "123123123123";

//    int i = 0;
//    Udp_pro updu;
//    QHostAddress client_host;
//    quint16 client_port;

//    m_socket_udp.readDatagram((char*)(&updu), sizeof(Udp_pro), &client_host, &client_port);
//    char* new_pic = new char[updu.whole+100];



//    static int a = 0;
//    while(updu.size == PIC_MAX_SIZE)
//    {
//        qDebug() << a;
//        a++;
//        memcpy(new_pic + i*PIC_MAX_SIZE, updu.data, size_t(updu.size));
//        m_socket_udp.readDatagram((char*)(&updu), sizeof(Udp_pro), &client_host, &client_port);
//        i++;
//    }
//    memcpy(new_pic + i*PIC_MAX_SIZE, updu.data, size_t(updu.size));

//    //qDebug() << "wawawa"<<updu.id;
//    //将数据用起来，显示起来
//    QByteArray b = QByteArray(new_pic, updu.whole);
//    qDebug() <<"haha";
//    W3::get_instance().show_live_data(b);
//    qDebug() << "wtf";

}


