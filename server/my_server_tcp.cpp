#include "my_server_tcp.h"
#include "w1.h"




My_server_tcp::My_server_tcp()
{

}

void My_server_tcp::incomingConnection(qintptr socketDescriptor)
{
    My_socket_tcp *comming_socket = new My_socket_tcp;
    comming_socket->setSocketDescriptor(socketDescriptor);
    m_vec.push_back(comming_socket);
}

My_server_tcp &My_server_tcp::get_instance()
{
    static My_server_tcp here;
    return here;
}

QVector<My_socket_tcp *> My_server_tcp::get_socket_vec()
{
    return m_vec;
}

void My_server_tcp::to_all(Protocol &pdu)
{
    int i = 0;
    for(i = 0; i < get_socket_vec().size();i++)
    {
        //qDebug() << "i" << i;
        W1::get_instance().add_protocol_msg(pdu, SEND);
        My_server_tcp::get_instance().get_socket_vec()[i]->write((char*)&pdu, sizeof(pdu));
    }
}
