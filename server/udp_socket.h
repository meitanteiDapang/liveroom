#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H


#include <QWidget>
#include <QUdpSocket>
#include <QVector>


//作为 a号端口, 客户端 发来的udp_pro，将他们的clientinfo 收集在vector中，完成在线的客户端的
//udp ip与端口的收集与处理


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
    QVector<ClientInfo*>& get_vec();
    void test_show_vec();

public slots:
    void recv_msg();
private slots:


private:
    QUdpSocket m_socket_udp;
    QVector<ClientInfo*> m_vec;

};

#endif // UDP_SOCKET_H
