#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H


#include <QWidget>
#include <QUdpSocket>
#include <QVector>




struct ClientInfo
{
    int id;
    int room_id;
    QHostAddress addr;
    quint16 port;
};

class Udp_socket : public QWidget
{
    Q_OBJECT

public:
    Udp_socket(QWidget *parent = nullptr);
    static Udp_socket& get_instance();
    QUdpSocket& get_udp_socket();

public slots:
    void recv_msg();
private slots:


private:
    QUdpSocket m_socket_udp;
    //QVector<ClientInfo*> m_vec;
};

#endif // UDP_SOCKET_H
