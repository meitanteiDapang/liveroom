#ifndef W1_H
#define W1_H

#include <QWidget>
#include <QTcpSocket>
#include "protocol.h"
#include "common.h"

QT_BEGIN_NAMESPACE
namespace Ui { class W1; }
QT_END_NAMESPACE

class W1 : public QWidget
{
    Q_OBJECT

public:

    ~W1();

    void connect_to_server();
    static W1 &get_instance();
    QTcpSocket& get_socket_tcp();
    void reload_widget();
    int get_id();
    void set_id(int id);
    char* get_username();
    void set_username(char* username);
    void tell_udp_i_am_in();
    void tell_udp_caster_in();

public slots:
    void show_connect();
    void receive_msg();
    void logout_fun();


private slots:
    void on_login_pb_clicked();

    void on_regist_pb_clicked();

private:
    W1(QWidget *parent = nullptr);
    Ui::W1 *ui;
    QTcpSocket m_socket_tcp;
    int m_id;
    char m_username[32];

};
#endif // W1_H











