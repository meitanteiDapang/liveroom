#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>

class My_thread : public QThread
{
    Q_OBJECT
public:
    My_thread();
    void run();

signals:

};

#endif // MY_THREAD_H
