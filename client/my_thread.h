#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>
#include <QEventLoop>
class My_thread : public QThread
{
    Q_OBJECT
public:
    My_thread();
    void run();
    QEventLoop m_loop;
public slots:
    void fuck();

signals:

};

#endif // MY_THREAD_H
