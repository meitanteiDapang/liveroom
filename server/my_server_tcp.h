#ifndef MY_SERVER_TCP_H
#define MY_SERVER_TCP_H

#include <QTcpServer>
#include "my_socket_tcp.h"
#include <QVector>

class My_server_tcp : public QTcpServer
{
    Q_OBJECT
public:
    My_server_tcp();

    void incomingConnection(qintptr handle);

private:
    QVector<My_socket_tcp *> m_vec;
};

#endif // MY_SERVER_TCP_H
