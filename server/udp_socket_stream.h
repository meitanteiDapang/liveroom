#ifndef UDP_SOCKET_STREAM_H
#define UDP_SOCKET_STREAM_H

#include <QWidget>
#include "udp_socket.h"

class Udp_socket_stream : public QWidget
{
    Q_OBJECT

public:
    Udp_socket_stream(QWidget *parent = nullptr);
    static Udp_socket_stream& get_instance();
    QUdpSocket& get_udp_socket();

public slots:
    void recv_msg();
private slots:


private:
    QUdpSocket m_socket_udp;

};

#endif // UDP_SOCKET_STREAM_H
