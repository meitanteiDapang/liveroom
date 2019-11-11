#ifndef MY_THREAD_AUDIENCE_READ_H
#define MY_THREAD_AUDIENCE_READ_H


#include <QThread>

class My_thread_audience_read : public QThread
{
    Q_OBJECT
public:
    My_thread_audience_read();
    void run();

signals:

};


#endif // MY_THREAD_AUDIENCE_READ_H
