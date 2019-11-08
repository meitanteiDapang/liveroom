#include "my_server_tcp.h"



My_server_tcp::My_server_tcp()
{

}

void My_server_tcp::incomingConnection(qintptr socketDescriptor)
{
    My_socket_tcp *comming_socket = new My_socket_tcp;
    comming_socket->setSocketDescriptor(socketDescriptor);
    m_vec.push_back(comming_socket);
}
