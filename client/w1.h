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

public slots:
    void show_connect();
    void receive_msg();



private slots:
    void on_login_pb_clicked();

    void on_regist_pb_clicked();

private:
    W1(QWidget *parent = nullptr);
    Ui::W1 *ui;
    QTcpSocket m_socket_tcp;
};
#endif // W1_H











