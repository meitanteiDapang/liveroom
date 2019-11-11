#ifndef UDP_SOCKET_AUDIENCE_H
#define UDP_SOCKET_AUDIENCE_H


#include <QWidget>
#include <QUdpSocket>
#include <QVector>
#include "udp_socket.h"





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
    QUdpSocket m_socket_udp;
    //QVector<ClientInfo*> m_vec;
};

#endif // UDP_SOCKET_AUDIENCE_H
