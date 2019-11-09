#ifndef W2_H
#define W2_H

#include <QWidget>
#include "w1.h"
#include <QStringListModel>
#include <QValidator>

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

    virtual void closeEvent(QCloseEvent *event);
    void set_username_label(char* username);
    void set_balance_label(float balance);
    void load_room_list();
    void insert_lv(QString ddd);
    void count_list_plus_plus();
    void set_count_list_zero();
    void clear_stringlist();
    void reload_stringlist();
    void clear_money_le();

private slots:
    void on_refresh_pb_clicked();

    void on_create_pb_clicked();

    void on_topup_pb_clicked();

    void on_quit_pb_clicked();

    void on_lv_doubleClicked(const QModelIndex &index);

private:
    Ui::W2 *ui;
    int m_count_list;
    QStringListModel* m_lm;
    QStringList *m_stringlist;
    QDoubleValidator *m_validator;
};

#endif // W2_H
