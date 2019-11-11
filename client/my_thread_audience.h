#ifndef MY_THREAD_AUDIENCE_H
#define MY_THREAD_AUDIENCE_H

#include <QThread>

class My_thread_audience : public QThread
{
    Q_OBJECT
public:
    My_thread_audience();
    void run();

signals:

};

#endif // MY_THREAD_H
