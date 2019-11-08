#ifndef MY_SOCKET_TCP_H
#define MY_SOCKET_TCP_H

#include <QTcpSocket>
#include "protocol.h"
#include "common.h"


class My_socket_tcp:public QTcpSocket
{
    Q_OBJECT
public :
    My_socket_tcp();

    void regist_handler(Protocol& pdu);
    void login_handler(Protocol& pdu);

public slots:
    void receive_msg();

};

#endif // MY_SOCKET_TCP_H
