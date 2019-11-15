#include "w3.h"
#include "ui_w3.h"
#include <stdlib.h>
#include <QWaitCondition>
#include <QMessageBox>
#include <QCameraImageCapture>
#include <QBuffer>
#include <QTimer>
#include <QPainter>
#include <QPicture>


//#include

//extern int id_global;
extern bool arimashida;
extern QHostAddress my_ip;
extern unsigned short my_port;

void W3::when_captured(int id, QImage image)
{
    //ui->label->setPixmap(QPixmap::fromImage(image));//将图片打印至那个B之上
    //当接收到imagecaputred时，将QImage保存到picpic上
    //static int i = 0;
    //uchar *image_uchar = image.bits();
    //qDebug() << image.size();
    *m_pic_pic = QPixmap::fromImage(image).scaledToWidth(480,Qt::FastTransformation).scaledToWidth(480, Qt::SmoothTransformation);
    is_capture_done = true;
    //qDebug() << m_pic_pic->size();
    //emit go_on_process_picpic();

}

W3::W3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W3)
{
    ui->setupUi(this);
    m_room_id = 0;
    m_pic_pic = new QPixmap;
    m_thread = new My_thread;
    //存放要发送的屏幕数据
    m_bytearray = new QByteArray;
    m_buffer = new QBuffer(m_bytearray);
    m_rocket_label = new QLabel(this);
    //m_rocket_label->setText("这是火箭");
    m_rocket_label->resize(150,300);
    //m_rocket_label->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.png"));
    m_rocket_label->setPixmap(QPixmap(":/pic/rocket.png"));
    m_rocket_label->setScaledContents(true);
    m_rocket_label->hide();



    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnWidth(0, 225);
    ui->tableWidget->setColumnWidth(1, 225);
    m_rows_num = 0;
    QStringList header;
    header << "id" << "用户名";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //截图相关
#if 1
    //到达缓冲区
    m_camera=new QCamera;//摄像头
    m_viewfinder=new QCameraViewfinder(this);
    m_imageCapture=new QCameraImageCapture(m_camera);//截图部件


    m_imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);


    QImageEncoderSettings image_setting;
    image_setting.setResolution(480, 270);
    m_imageCapture->setEncodingSettings(image_setting);

#endif


#if 0
    //到达文件
    m_camera=new QCamera;//摄像头
    m_viewfinder=new QCameraViewfinder(this);
    m_imageCapture=new QCameraImageCapture(m_camera);//截图部件
    m_imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
#endif

    m_camera->setViewfinder(m_viewfinder);

    //connect(m_imageCapture, SIGNAL(imageCaptured(int id, const QImage& image)),
    //                    this, SLOT(when_captured()));
    connect(m_imageCapture, SIGNAL(imageCaptured(int, const QImage&)),
                            this, SLOT(when_captured(int, QImage)));

    connect(this, SIGNAL(please_stop_capture()), m_imageCapture, SLOT(cancelCapture()));
    connect(ui->msg_le, SIGNAL(returnPressed()), this, SLOT(on_send_pb_clicked()));

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
    ui->pic_label->hide();
    ui->layouto->addWidget(m_viewfinder);
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

    //qDebug() << "wtf1";

    //断开直播
    if(m_is_caster)
    {
        W3::get_instance().get_thread()->terminate();
        W3::get_instance().get_thread()->wait();
    }
    //qDebug() <<"wtf2";
    m_viewfinder->setParent(nullptr);
    //qDebug() <<"wtf3";
    m_camera->stop();
    //qDebug() <<"wtf4";
    emit please_stop_capture();

//    delete m_thread;
//    delete m_camera;
//    delete m_viewfinder;
//    delete m_imageCapture;


//    if(m_is_caster)
//    {
//        W3::get_instance().get_thread().exit();
//        if(!W3::get_instance().get_thread().wait(1))
//        {
//            W3::get_instance().get_thread().terminate();
//            W3::get_instance().get_thread().wait();
//        }
//    }
    //qDebug() << "wtf2";
    //告诉UDP 爷走了， 把爷删了
    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.is_getout = true;
    W3::get_instance().send_udp_to_server(&updu);
    //qDebug() << "wtf3";
    //告诉服务器，登出
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = QUIT_ROOM_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.result = m_is_caster;
    pdu.room_id = m_room_id;
    pdu.isevent = true;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
    //qDebug() << "wtf4";
    //QWaitCondition wait;
    //wait.wait(1);
    //std::usleep(5000);
    //登出
    W1::get_instance().logout_fun();
    //qDebug() << "wtf5";
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

void W3::add_chat_text(QString data)
{
    ui->msg_tb->append(data);
}

void W3::clear_chat_text()
{
    ui->msg_tb->clear();
}

QCameraViewfinder *W3::get_viewfinder()
{
    return m_viewfinder;
}

QString W3::get_room_name()
{
    return m_room_name;
}

void W3::set_room_name(QString room_name)
{
    m_room_name = room_name;
}

void W3::add_room_name_test(QString room_name)
{
    ui->msg_tb->append(QString("欢迎来到")+room_name+QString("的直播间"));
}

void W3::send_udp_to_server(Udp_pro* updu)
{
    //qDebug() << "send"<< updu->id;
    Udp_socket::get_instance().get_udp_socket().writeDatagram((char*)(updu), sizeof(Udp_pro),
                                                              QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort());
}

My_thread* W3::get_thread()
{
    return m_thread;
}

void W3::show_live_data(QByteArray b)
{
    //这边要改成把图片放上去，
    //add_chat_text(QString("%1").arg("nmsl"));
    if(m_pic_pic->loadFromData(b, "png"))
    {
        ui->pic_label->clear();
        ui->pic_label->setPixmap(*m_pic_pic);
        //ui->pic_label->setScaledContents(true);
    }
}

void W3::get_now_pic()
{
    //仅仅开始捕捉
    //qDebug() <<"capture";
    is_capture_done = false;
    m_imageCapture->capture();
}

void W3::modify_updu_to_have_picdata(Udp_pro &updu)
{
#if 0
    //将picpic保存到传进来的updu
    //static int i = 0;
    if(1)
    {
//        QByteArray ba;
//        QBuffer buffer(&ba);
//        buffer.open(QIODevice::WriteOnly);
//        m_pic_pic->save(&buffer, "PNG");
//        //qDebug() << buffer.buffer();
//        qDebug() << m_pic_pic->bits();
//        qDebug() << "wtf"<< buffer.buffer().toStdString().c_str();
//        ui->label->setPicture(QPicture(m_pic_pic));
//        i++;
        if(!m_pic_pic->isNull())
        {
            QByteArray ba;
            QBuffer buffer(&ba);
            buffer.open(QIODevice::WriteOnly);
            m_pic_pic->save(&buffer,"PNG",20);
            int whole = ba.size();
            updu.whole = whole;

            char* here_buf = new char[whole];
            memcpy(here_buf, ba, size_t(whole));

            //qDebug() << "主播" << whole;
            int send_times = whole / PIC_MAX_SIZE;
            int left = whole % PIC_MAX_SIZE;
            int count = 0;

            for(count = 0; count < send_times; count ++)
            {
                updu.is_end = false;
                updu.size = PIC_MAX_SIZE;
                memcpy(updu.data, here_buf+PIC_MAX_SIZE*count, PIC_MAX_SIZE);
                send_udp_to_server(&updu);
                //qDebug() << "send" << count << updu.size;
            }
            updu.size = left;
            updu.is_end = true;
            strcpy(updu.alala, "end");
            memcpy(updu.data, here_buf+PIC_MAX_SIZE*(send_times), (size_t)left);
            send_udp_to_server(&updu);
            qDebug() << "主播" << whole << count;
            //qDebug() << "send" << count << updu.size << updu.room_id << updu.is_caster;

            delete [] here_buf;
            //读图片成功了，再次借鉴
//            //ui->label->setScaledContents(true);
//            //ui->label->setPixmap(*m_pic_pic);
//            qDebug() << "modify" << m_pic_pic->size();
//            QByteArray ba;
//            QBuffer buffer(&ba);
//            buffer.open(QIODevice::WriteOnly);
//            m_pic_pic->save(&buffer,"PNG",20);

//            static QPixmap* here_pic_pic = new QPixmap;
//            char *b= new char[ba.size()];
//            memcpy(b, ba, ba.size());
//            QByteArray bb = QByteArray(b, ba.size());
//            here_pic_pic->loadFromData(bb);
//            ui->label->setPixmap(*here_pic_pic);

            //qDebug() << ba.size();
            //qDebug() << strlen(data);

        }
    }
#endif
}

void W3::better_go_out()
{
    //qDebug() <<"wtf2";
    m_viewfinder->setParent(nullptr);
    //qDebug() <<"wtf3";
    m_camera->stop();
    //qDebug() <<"wtf4";
    emit please_stop_capture();
}

//将pic分割并打包发送至udp port+1
void W3::pic_pic_handler_and_send()
{
    //处理图片并发送
#if 0
    while (true)
    {
        //已经获得图片啦
        m_buffer->open(QIODevice::ReadWrite);
        m_pic_pic->save(m_buffer, "png");

        qint64 ret = 0;
        qint64 iSended = 0;
        qint64 iLefted = m_bytearray->size();
        static const char *p = nullptr;
        p = m_bytearray->constData();
        qDebug() << "\n\n total size = " << iLefted;
        while(iLefted)
        {
            if (iLefted > PIC_MAX_SIZE)
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, PIC_MAX_SIZE
                            , QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            else
            {
                ret = Udp_socket::get_instance().get_udp_socket().
                        writeDatagram(p+iSended, iLefted
                            ,QHostAddress(IP_ADDRESS), QString(UDPPORT).toUShort() +1 );
            }
            if (0 == ret)
            {
                break;
            }
            else if (-1 == ret)
            {
                ret = 0;
            }
            else
            {
                iLefted -= ret;
                iSended += ret;
            }
            usleep(TIMER_TIME);
        }
        m_pByteArray->clear();

        qDebug() << "此次截屏总共发送的数据大小 = " << iSended;

        m_pUdpSocket->writeDatagram("end", 3, QHostAddress(m_strIp), m_usPort);
    }
#endif


#if 0
    //测试发送wtf
    *m_bytearray = QByteArray("wtf", 4);
    static const char *p = nullptr;
    p = m_bytearray->constData();
    Udp_socket::get_instance().get_udp_socket().
                                        writeDatagram(p, 4,
                                        QHostAddress(IP_ADDRESS),
                                        QString(UDPPORT).toUShort()+1);
#endif
}

void W3::show_danmu(QString data)
{

}

void W3::show_huojian()
{

//火箭火箭
#if 1
    m_timer_vec.clear();
    m_rocket_label->setParent(this);
    m_rocket_label->show();
    m_rocket_label->raise();
    m_ix = 500;
    m_iy = 500;
    m_rocket_label->move(m_ix, m_iy);
    QTimer* timer = new QTimer();
    m_timer_vec.push_back(timer);
    timer->start(ROCKET_INTERVAL);
    connect(timer, SIGNAL(timeout()), this , SLOT(rocket_move()));





    //m_rocket_label->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.jpg"));


    //ui->msg_tb->show();

#endif

//可行方案
#if 0

    //qDebug() << "oooo";
    //ui->msg_tb->hide();
    //ui->the_layout->addWidget(m_rocket_label);
    m_rocket_label->setParent(this);
    m_rocket_label->show();
    //m_rocket_label->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.jpg"));
    m_rocket_label->raise();
    int ix = 500;
    int iy = 500;
    while(iy>0)
    {
        m_rocket_label->move(ix,iy);
        update();
        iy -= 50;
        update();
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }

    m_rocket_label->setParent(nullptr);
    //ui->msg_tb->show();

#endif

#if 0
    //qDebug() << "oooo";
    //ui->msg_tb->hide();
    //ui->the_layout->addWidget(m_rocket_label);
    QLabel* rocket_label = new QLabel(this);
    rocket_label->setText("wtfffff");
    rocket_label->raise();
    int ix = 500;
    int iy = 500;
    while(iy>0)
    {
        rocket_label->move(ix, iy);
        rocket_label->raise();
        iy -= 5;
        update();
        QEventLoop loop;
        QTimer::singleShot(20, &loop, SLOT(quit()));
        loop.exec();
    }

    rocket_label->setParent(nullptr);
    delete rocket_label;
    //ui->msg_tb->show();

#endif

#if 0
    //qDebug() << "oooo";
    ui->msg_tb->hide();
    ui->the_layout->addWidget(m_rocket_label);
    m_rocket_label->raise();
    int ix = 0;
    int iy = 500;
    while(iy>0)
    {
        iy -= 50;
        update();
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }

    m_rocket_label->setParent(nullptr);
    ui->msg_tb->show();

#endif
#if 0
    QPainter painter(W3::get_instance().get_msg_tb());
    QPixmap ro(":/pic/rocket.png");
    int ix = 500;
    int iy = 500;
    while(iy>0)
    {
        painter.drawPixmap(ix,iy,150,300, ro);
        iy -= 50;
        update();
        W3::get_instance().repaint();
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }
#endif


#if 0
    int ix = 0;
    int iy = 500;

    m_rocket_label->setParent(ui->msg_tb);
    while(iy>0)
    {
        qDebug() << "iy" << iy;

        iy-= 50;
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }
    m_rocket_label->setParent(ui->msg_tb);
#endif


#if 0
    //qDebug() << "oooo";
    QLabel* lll = new QLabel(W3::get_instance().get_msg_tb());
    lll->raise();
    //lll->setPixmap(QPixmap(":/pic/rocket.png"));
    lll->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.png"));
    //lll->setText("cncncncncn");
    ui->pic_label->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.png"));
    int ix = 0;
    int iy = 500;
    lll->setGeometry(ix,iy,150,300);
    while(iy>0)
    {
        qDebug() << "iy" << iy;
        lll->move(ix,iy);
        iy -= 50;
        update();
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }
    lll->clear();
    lll->hide();
    lll->close();
    delete lll;
#endif

#if 0
    //改到线程去
    static Rocket_thread ooo;
    if(ooo.isRunning())
    {
        ooo.wait();
    }
    ooo.run();
#endif
}

void W3::load_people()
{
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.count = m_load_count;
    pdu.msg_type = RELOAD_PEOPLE_TYPE;
    pdu.room_id = m_room_id;
    //qDebug()<< "create_pb_clicked" << pdu.id;
    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
}

void W3::count_plus_plus()
{
    m_load_count++;
}

void W3::insert_into_table(Protocol& pdu)
{
    ui->tableWidget->setRowCount(pdu.count+1);
    QTableWidgetItem* ppid = new QTableWidgetItem;
    QTableWidgetItem* ppusername = new QTableWidgetItem;
    ppid->setText(QString("%1").arg(pdu.id));
    ppusername->setText(QString(pdu.username));
    ui->tableWidget->setItem(pdu.count, 0, ppid);
    ui->tableWidget->setItem(pdu.count,1, ppusername);

}

void W3::reload_people()
{
    ui->tableWidget->setRowCount(0);
    m_load_count = 0;
    load_people();
}

QTextBrowser *W3::get_msg_tb()
{
    return ui->msg_tb;
}

void W3::set_rocket_label()
{
    m_rocket_label->setParent(ui->msg_tb);
    m_rocket_label->setWindowFlag(Qt::WindowStaysOnTopHint);
}

void W3::unset_rocket_label()
{
    m_rocket_label->setParent(nullptr);
}

void W3::unset_msg_tb()
{
    ui->msg_tb->hide();
}


void W3::set_msg_tb()
{
    ui->msg_tb->show();
}



void W3::on_quit_pb_clicked()
{
    //if(m_is_caster)
    {
        ui->pic_label->show();
        m_viewfinder->setParent(nullptr);
        m_camera->stop();
        emit please_stop_capture();
    }
    //else //观众，做的,说个JB
    {
        //Udp_socket_audience::get_instance().get_udp_socket().close();
    }

    m_buffer->close();


    //delete m_viewfinder;

    //杀死线程，告诉线程结束
    arimashida = false;


    /*
    if(m_is_caster)
    {
        W3::get_instance().get_thread().exit();
        if(!W3::get_instance().get_thread().wait(1))
        {
            qDebug() << "wtf";
            W3::get_instance().get_thread().terminate();
            W3::get_instance().get_thread().wait();
        }
    }
    */

    //告诉UDP 爷走了， 把爷删了
    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.room_id = m_room_id;
    updu.is_getout = true;
    W3::get_instance().send_udp_to_server(&updu);

    W3::get_instance().clear_chat_text();

    //取消绑定
    //if(Udp_socket::get_instance().get_udp_socket().

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
    QString msg = ui->msg_le->text();
    if(msg.size() > 100)
    {
        QMessageBox::information(this, "发送", "请输入少于100字节");
        ui->msg_le->clear();
    }

    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = GROUP_CHAT_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.result = m_is_caster;
    pdu.room_id = m_room_id;
    strcpy(pdu.username, W1::get_instance().get_username());
    strcpy(pdu.data, msg.toStdString().c_str());

    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
    ui->msg_le->clear();
}

void W3::on_rocket_pb_clicked()
{
    Protocol pdu;
    memset(&pdu, 0 ,sizeof(pdu));
    pdu.msg_type = SEND_ROCKET_TYPE;
    pdu.id = W1::get_instance().get_id();
    pdu.result = m_is_caster;
    pdu.room_id = m_room_id;
    strcpy(pdu.username, W1::get_instance().get_username());

    W1::get_instance().get_socket_tcp().write((char*)&pdu, sizeof(pdu));
}

void W3::rocket_move()
{
    if(m_iy > 0)
    {
        m_rocket_label->move(m_ix,m_iy);
        update();
        m_iy -= 15;

        QTimer* timer = new QTimer();

        timer->start(ROCKET_INTERVAL);
        m_timer_vec.push_back(timer);
        connect(timer, SIGNAL(timeout()), this , SLOT(rocket_move()));


    }
    else
    {
        int len = m_timer_vec.size();
        for(int i = 0; i < len; i++)
        {
            delete m_timer_vec[i];
        }
        m_timer_vec.clear();
        m_rocket_label->setParent(nullptr);
    }
}









void W3::on_refresh_people_pb_clicked()
{
    reload_people();
}
