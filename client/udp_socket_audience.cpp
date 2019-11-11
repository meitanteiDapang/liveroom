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
    //qDebug() << "123123123123";
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

    //qDebug() << "wawawa"<<updu.id;
    //将数据用起来，显示起来
    W3::get_instance().show_live_data(updu);

}


