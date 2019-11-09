#include "w2.h"
#include "ui_w2.h"
#include "w1.h"
#include "w3.h"

//extern int id_global;

W2::W2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W2)
{
    ui->setupUi(this);
    m_count_list = 0;
    m_lm = new QStringListModel;
    m_stringlist = new QStringList;
    ui->lv->setModel(m_lm);
    ui->lv->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_validator = new QDoubleValidator(0.1, 1000, 2 ,this);
    m_validator->setNotation(QDoubleValidator::StandardNotation);
    ui->money_le->setValidator(m_validator);
}

W2::~W2()
{
    delete ui;
}

W2 &W2::get_instance()
{
    static W2 instance;
    return instance;
}

void W2::closeEvent(QCloseEvent *event)
{
    QCloseEvent* slience = event;
    event = slience;
    W1::get_instance().logout_fun();
}

void W2::set_username_label(char *username)
{
    ui->username_label->setText(QString(username));
}

void W2::set_balance_label(float balance)
{
//    char data[64];
//    sprintf(data, "%12f", double(balance));
//    ui->balance_lb->setText(QString(data));
    ui->balance_lb->setText(QString("%1").arg(double(balance)));
}

void W2::load_room_list()
{
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.count = m_count_list;
    pdu.msg_type = RELOAD_LIST_TYPE;
    pdu.id = W1::get_instance().get_id();
    //qDebug()<< "create_pb_clicked" << pdu.id;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
}

void W2::insert_lv(QString ddd)
{
//    QModelIndex index = ui->lv->currentIndex();
//    m_lm.insertRows(index.row(), 1);
//    m_lm.setData(index, ddd);
//    ui->lv->edit(index);
    *m_stringlist << ddd;
    m_lm->setStringList(*m_stringlist);
    ui->lv->setModel(m_lm);

}

void W2::count_list_plus_plus()
{
    m_count_list++;
}

void W2::set_count_list_zero()
{
    m_count_list = 0;
}

void W2::clear_stringlist()
{
    m_stringlist->clear();
}

void W2::reload_stringlist()
{
    clear_stringlist();
    set_count_list_zero();
    load_room_list();
}

void W2::clear_money_le()
{
    ui->money_le->setText("");
}

void W2::on_refresh_pb_clicked()
{
    reload_stringlist();
}

void W2::on_create_pb_clicked()
{


    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = CREATE_TYPE;
    pdu.id = W1::get_instance().get_id();
    //qDebug()<< "create_pb_clicked" << pdu.id;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));


}

void W2::on_topup_pb_clicked()
{
    float money = ui->money_le->text().toFloat();
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = TOPUP_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.money = money;
    //qDebug()<< "create_pb_clicked" << pdu.id;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
}

void W2::on_quit_pb_clicked()
{

    W1::get_instance().logout_fun();
    hide();
    W1::get_instance().reload_widget();
    W1::get_instance().show();
}

void W2::on_lv_doubleClicked(const QModelIndex &index)
{

}
