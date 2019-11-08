#ifndef W1_H
#define W1_H

#include <QWidget>
#include "my_server_tcp.h"
#include "db_handler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class W1; }
QT_END_NAMESPACE

class W1 : public QWidget
{
    Q_OBJECT

public:
    W1(QWidget *parent = nullptr);
    ~W1();

    static W1 &get_instance();
    My_server_tcp &get_server_tcp();

    void update_msg(QString msg);
    void update_db_status(QString msg);

    void add_protocol_msg(Protocol& pdu, bool mode);

private:
    Ui::W1 *ui;
    My_server_tcp m_server;
};
#endif // W1_H
