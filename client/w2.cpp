#include "w2.h"
#include "ui_w2.h"
#include "w1.h"
#include "w3.h"

W2::W2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W2)
{
    ui->setupUi(this);
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

void W2::on_refresh_pb_clicked()
{

}

void W2::on_create_pb_clicked()
{
    W3::get_instance().being_caster();
    W3::get_instance().show();
    hide();
    W3::get_instance().start_camera_selfie();
}

void W2::on_topup_pb_clicked()
{

}

void W2::on_quit_pb_clicked()
{

}
