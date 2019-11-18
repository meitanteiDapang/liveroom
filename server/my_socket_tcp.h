#ifndef MY_SOCKET_TCP_H
#define MY_SOCKET_TCP_H

#include <QTcpSocket>
#include "protocol.h"
#include "common.h"

//作为对应每一个客户端的tcp socket，集中处理所有从对应客户端发来的tcp请求

class My_socket_tcp:public QTcpSocket
{
    Q_OBJECT
public :
    My_socket_tcp();

    void regist_handler(Protocol& pdu);
    void login_handler(Protocol& pdu);
    void logout_handler(Protocol& pdu);
    void create_handler(Protocol& pdu);
    void quit_room_handler(Protocol& pdu);
    void load_list_handler(Protocol& pdu);
    void topup_handler(Protocol& pdu);
    void enter_room_handler(Protocol& pdu);
    void group_chat_handler(Protocol& pdu, bool& hei);
    void get_balance_handler(Protocol& pdu);
    void rocket_handler(Protocol& pdu);
    void reload_people_handler(Protocol& pdu);

public slots:
    void receive_msg();

};

#endif // MY_SOCKET_TCP_H
