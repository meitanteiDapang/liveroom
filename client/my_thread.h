#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>
#include <QEventLoop>


//作为主播发送视频流时将使用此线程


class My_thread : public QThread
{
    Q_OBJECT
public:
    My_thread();
    void run();
    QEventLoop m_loop;
    void oklala();
public slots:
    void fuck();

signals:

};

#endif // MY_THREAD_H
