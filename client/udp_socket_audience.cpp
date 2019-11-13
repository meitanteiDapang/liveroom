#include <protocol.h>
#include "w3.h"
#include <QDebug>
#include "udp_socket_audience.h"

extern QHostAddress my_ip;
extern unsigned short my_port;

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

//接受服务器的图片流
    //好好看一下
#if 1
    QByteArray buf;
    qint64 ret = 0;
    //qDebug() << "############################";
    while (m_socket_udp.hasPendingDatagrams())
    {
        buf.resize(int(m_socket_udp.pendingDatagramSize()));
        ret = m_socket_udp.readDatagram(buf.data(), buf.size());
        //qDebug() << "rsize=" << ret;

        if ("end" == buf.toStdString())
        {
            //qDebug() << "data=" << buf;
            //qDebug() << "map size: " << m_storeRecvMsg.size();
            //            QBuffer buffer(&m_storeRecvMsg);
            //            buffer.open(QIODevice::ReadOnly);
            //            QImageReader read(&buffer, "png");
            //            QImage image = read.read();
            //            m_pMapLab->clear();
            //            m_pMapLab->setPixmap(QPixmap::fromImage(image));
            //            m_pMapLab->setScaledContents(true);



            W3::get_instance().show_live_data(m_storeRecvMsg);

            m_storeRecvMsg.clear();
        }
        else
        {

            m_storeRecvMsg.append(buf.data(), int(ret));

        }
        buf.clear();
    }

#endif


#if 0
    QByteArray buf;
    qint64 ret = 0;
    qDebug() << "############################";
    while (m_socket_udp.hasPendingDatagrams())
    {
        buf.resize(int(m_socket_udp.pendingDatagramSize()));
        ret = m_socket_udp.readDatagram(buf.data(), buf.size());
        qDebug() << "rsize=" << ret;
        W3::get_instance().add_chat_text(QString(buf.toStdString().c_str()));

        buf.clear();
    }
#endif

#if 0
    QByteArray buf;
    qint64 ret = 0;
    qDebug() << "############################";
    while (m_pUdpSocket->hasPendingDatagrams())
    {
        buf.resize(m_pUdpSocket->pendingDatagramSize());
        ret = m_pUdpSocket->readDatagram(buf.data(), buf.size());
        qDebug() << "rsize=" << ret;

        if ("end" == buf.toStdString())
        {
            qDebug() << "data=" << buf;
            qDebug() << "map size: " << m_storeRecvMsg.size();
            //            QBuffer buffer(&m_storeRecvMsg);
            //            buffer.open(QIODevice::ReadOnly);
            //            QImageReader read(&buffer, "png");
            //            QImage image = read.read();
            //            m_pMapLab->clear();
            //            m_pMapLab->setPixmap(QPixmap::fromImage(image));
            //            m_pMapLab->setScaledContents(true);



            QPixmap pixmap;
            if (pixmap.loadFromData(m_storeRecvMsg, "png"))
            {
                m_pMapLab->clear();
                m_pMapLab->setPixmap(pixmap);
                m_pMapLab->setScaledContents(true);
            }

            m_storeRecvMsg.clear();
        }
        else
        {

            m_storeRecvMsg.append(buf.data(), ret);

        }
        buf.clear();
    }
#endif


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


