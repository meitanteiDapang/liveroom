#ifndef W2_H
#define W2_H

#include <QWidget>
#include "w1.h"

namespace Ui {
class W2;
}

class W2 : public QWidget
{
    Q_OBJECT

public:
    explicit W2(QWidget *parent = nullptr);
    ~W2();
    static W2 &get_instance();
private slots:
    void on_refresh_pb_clicked();

    void on_create_pb_clicked();

    void on_topup_pb_clicked();

    void on_quit_pb_clicked();

private:
    Ui::W2 *ui;
};

#endif // W2_H
