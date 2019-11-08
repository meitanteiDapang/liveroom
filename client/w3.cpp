#include "w3.h"
#include "ui_w3.h"


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

void W3::on_quit_pb_clicked()
{
    //还需要向服务器发送离开room
    if(m_is_caster)
    {
        m_camera->stop();
    }
    W2::get_instance().show();
    hide();
}
