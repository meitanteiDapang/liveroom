#ifndef UDP_SOCKET_AUDIENCE_H
#define UDP_SOCKET_AUDIENCE_H


#include <QWidget>
#include <QUdpSocket>
#include <QVector>
#include "udp_socket.h"


//作为观众进入房间时，使用此socket向服务器发送信息并注册
//同时接受服务器转发的视频流，并处理流数据 展示在W3 中


class Udp_socket_audience : public QWidget
{
    Q_OBJECT

public:
    Udp_socket_audience(QWidget *parent = nullptr);
    static Udp_socket_audience& get_instance();
    QUdpSocket& get_udp_socket();

public slots:
    void recv_msg();
private slots:


private:
    QByteArray m_storeRecvMsg;
    QUdpSocket m_socket_udp;
    //QVector<ClientInfo*> m_vec;
};

#endif // UDP_SOCKET_AUDIENCE_H
