#include "udp_socket.h"
#include "protocol.h"
#include <string.h>


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
    //qint64 size = m_socket_udp.bytesAvailable();
    //bool is_pic_pic = (size!=sizeof(Udp_pro));

    //qDebug() << "开始读";
    Udp_pro updu;
    QHostAddress client_host;
    quint16 client_port;
    m_socket_udp.readDatagram((char*)(&updu), sizeof(Udp_pro), &client_host, &client_port);

    int i = 0;
    if(updu.is_getout)
    {
        for(i = 0; i <m_vec.size(); i++)
        {
            if(updu.id == m_vec[i]->id)
            {

                delete m_vec[i];
                m_vec.remove(i);
                //qDebug() <<"delete"  << m_vec.size();
            }
        }
        return;
    }
    //看下是不是老udp用户

    for(i = 0; i < m_vec.size(); i++)
    {
        if(client_host.toString() == m_vec[i]->addr.toString() && client_port == m_vec[i]->port
                )
        {
            break;
        }
    }
    //插入
    if(i == m_vec.size())
    {
        qDebug() << updu.id << updu.room_id << updu.is_caster << client_port;
        ClientInfo* p_clientinfo = new ClientInfo;
        p_clientinfo->id = updu.id;
        p_clientinfo->room_id = updu.room_id;
        p_clientinfo->addr = client_host;
        p_clientinfo->port = client_port;
        m_vec.push_back(p_clientinfo);
        //qDebug() << "hei";
    }

    //如果不是主播的发送，仅仅建立连接就返回，啥都不干，说你妈呢
    if(!updu.is_caster)
    {
        return;
    }
    //开始处理,群发给所有B
    //qDebug() << updu.id;
    int vsize = m_vec.size();
    i = 0;
    for(i = 0; i < vsize; i++)
    {
        if(updu.room_id != m_vec[i]->room_id)
        {
            //如果不是在这个房间内，跳过
            continue;
        }
        if(updu.id == m_vec[i]->id)
        {
            //是主播跳过
            //qDebug() << updu.id;
            continue;
        }
        qDebug()<< m_vec[i]->addr << m_vec[i] -> port;
        //qint64 wtf =
        Udp_socket::get_instance().get_udp_socket().writeDatagram((char*)(&updu)
                                                                  , sizeof(Udp_pro), m_vec[i]->addr, m_vec[i]->port);
        //qDebug() << wtf;
    }
    //qDebug() <<"size" << m_vec.size();



}
