#include "rocket_thread.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include "w3.h"

Rocket_thread::Rocket_thread()
{

}

void Rocket_thread::run()
{
#if 0
    QPainter painter(&W3::get_instance());
    QPixmap ro(":/pic/rocket.png");
    int ix = 500;
    int iy = 500;
    while(iy>0)
    {
        painter.drawPixmap(ix,iy,150,300, ro);
        iy -= 50;
        W3::get_instance().repaint();
        msleep(200);
    }


#endif

#if 1
    //W3::get_instance().set_rocket_label();
    //W3::get_instance().unset_msg_tb();
    qDebug() << "thread";
    msleep(200);
    //W3::get_instance().set_msg_tb();
    //W3::get_instance().unset_rocket_label();
#endif



#if 0
    //qDebug() << "oooo";
    QLabel* lll = new QLabel(W3::get_instance().get_msg_tb());
    //lll->setWindowFlag(Qt::WindowStaysOnTopHint);
    //lll->setPixmap(QPixmap(":/pic/rocket.png"));
    lll->setPixmap(QPixmap("/Users/yzh/Desktop/project/liveroom/client/pic/rocket.png"));
    //lll->setText("cncncncncn");
    int ix = 0;
    int iy = 500;
    lll->setGeometry(ix,iy,150,300);
    while(iy>0)
    {
        lll->move(ix,iy);
        iy -= 50;
        msleep(200);
    }
    lll->clear();
    lll->hide();
    lll->close();
    delete lll;
#endif
}
