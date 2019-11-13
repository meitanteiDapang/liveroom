#include "udp_socket.h"
#include <protocol.h>
#include "w3.h"
#include <QDebug>

QHostAddress my_ip = QHostAddress("127.0.0.1");
unsigned short my_port = 0;
Udp_socket::Udp_socket(QWidget *parent) : QWidget(parent)
{
    connect(&m_socket_udp, SIGNAL(readyRead()), this, SLOT(recv_msg()));
}

QUdpSocket &Udp_socket::get_udp_socket()
{
    return m_socket_udp;
}

Udp_socket& Udp_socket::get_instance()
{
    static Udp_socket instance;
    return instance;
}


void Udp_socket::recv_msg()
{
    qDebug() <<"hahaha";
#if 0
    //主播不会收udp包
    qDebug() << "123123123123";
    //只有观众会收到这个包哦
    qint64 size = m_socket_udp.bytesAvailable();
    if(size != sizeof(Udp_pro))
    {
        //qDebug() << "非法包";
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
    m_socket_udp.readDatagram((char*)(&updu), size, &client_host, &client_port);
    qDebug() << updu.size ;
    //qDebug() << "wawawa"<<updu.id;
    //将数据用起来，显示起来
    QByteArray b("123",3);
    W3::get_instance().show_live_data(b);
#endif
}


