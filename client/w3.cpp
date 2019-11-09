#include "w3.h"
#include "ui_w3.h"
#include <stdlib.h>
#include <QWaitCondition>
//extern int id_global;

W3::W3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W3)
{
    ui->setupUi(this);



    m_camera=new QCamera;//摄像头
    m_viewfinder=new QCameraViewfinder(this);
    m_imageCapture=new QCameraImageCapture(m_camera);//截图部件

    ui->layouto->setGeometry(QRect(50,50,300,300));

}

W3::~W3()
{
    delete ui;
}

W3 &W3::get_instance()
{
    static W3 instance;
    return instance;
}

void W3::start_camera_selfie()
{
    ui->layouto->addWidget(m_viewfinder);
    m_camera->setViewfinder(m_viewfinder);
    m_camera->start();
}

void W3::being_caster()
{
    m_is_caster = true;
}

void W3::being_audience()
{
    m_is_caster = false;
}

void W3::closeEvent(QCloseEvent *event)
{
    QCloseEvent* slience = event;
    event = slience;


    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = QUIT_ROOM_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.result = m_is_caster;
    pdu.room_id = m_room_id;
    pdu.isevent = true;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));

    //QWaitCondition wait;
    //wait.wait(1);
    //std::usleep(5000);
    //登出
    W1::get_instance().logout_fun();
    //向服务器发送离开room

}

int W3::get_room_id()
{
    return m_room_id;
}

void W3::set_room_id(int id)
{
    m_room_id = id;
}

bool W3::get_is_caster()
{
    return m_is_caster;
}

QCamera *W3::get_camera()
{
    return m_camera;
}

void W3::on_quit_pb_clicked()
{
    //向服务器发送离开room
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = QUIT_ROOM_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.result = m_is_caster;
    pdu.room_id = m_room_id;
    pdu.isevent = false;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));

}

void W3::on_send_pb_clicked()
{

}

void W3::on_rocket_pb_clicked()
{

}
