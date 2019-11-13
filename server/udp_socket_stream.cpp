#include "udp_socket_stream.h"
#include "protocol.h"
#include <string.h>


Udp_socket_stream::Udp_socket_stream(QWidget *parent) : QWidget(parent)
{
    connect(&m_socket_udp, SIGNAL(readyRead()), this, SLOT(recv_msg()));
}

QUdpSocket &Udp_socket_stream::get_udp_socket()
{
    return m_socket_udp;
}


Udp_socket_stream& Udp_socket_stream::get_instance()
{
    static Udp_socket_stream instance;
    return instance;
}

//此udp只用来接受主播包与转发包
void Udp_socket_stream::recv_msg()
{
#if 1
    QByteArray buf;
    qint64 ret = 0;
    QHostAddress caster_address;
    unsigned short caster_port;
    //qDebug() << "############################";
    int i = 0;
    int caster_id = 0;
    int caster_room_id = 0;
    while (m_socket_udp.hasPendingDatagrams())
    {

        //这里转发应该是啥都不用干
        buf.resize(int(m_socket_udp.pendingDatagramSize()));
        ret = m_socket_udp.readDatagram(buf.data(), buf.size(), &caster_address, &caster_port);
        //qDebug() << "rsize=" << ret;
        //qDebug() <<"before" << caster_id << caster_room_id << "此时主播" << caster_address << caster_port;
        //Udp_socket::get_instance().test_show_vec();
        //转发开始,先获取主播id
        for(i = 0; i < Udp_socket::get_instance().get_vec().size(); i++)
        {

            if(caster_address == Udp_socket::get_instance().get_vec()[i]->addr &&
                    caster_port == Udp_socket::get_instance().get_vec()[i]->port)
            {
                caster_id = Udp_socket::get_instance().get_vec()[i]->id;
                caster_room_id = Udp_socket::get_instance().get_vec()[i]->room_id;
                break;
            }
        }
        qDebug() << "after" << caster_id << caster_room_id;
        //然后向房间里的人散播火种
        for(i = 0; i < Udp_socket::get_instance().get_vec().size(); i++)
        {
            if(caster_room_id == Udp_socket::get_instance().get_vec()[i]->room_id &&
                    Udp_socket::get_instance().get_vec()[i]->id !=
                    Udp_socket::get_instance().get_vec()[i]->room_id)
            {
                qDebug() << "send" << Udp_socket::get_instance().get_vec()[i]->addr
                         << Udp_socket::get_instance().get_vec()[i]->port;
                m_socket_udp.writeDatagram(buf.data(), buf.size(),
                    Udp_socket::get_instance().get_vec()[i]->addr,
                    Udp_socket::get_instance().get_vec()[i]->port);
            }
        }
    }
#endif

    //穿不过去，段错误

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
    static int ccc = 0;
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
        ccc++;
        if(updu.size != PIC_MAX_SIZE)
        {
            qDebug()<< m_vec[i]->addr << m_vec[i] -> port <<updu.size << updu.whole << ccc;
            ccc = 0;
        }
        Udp_socket::get_instance().get_udp_socket().writeDatagram((char*)(&updu)
                                                              , sizeof(Udp_pro), m_vec[i]->addr, m_vec[i]->port);
            //qDebug() << wtf;
    }
    //qDebug() <<"size" << m_vec.size();
#endif
}
