#ifndef ROCKET_THREAD_H
#define ROCKET_THREAD_H

#include <QThread>


class Rocket_thread : public QThread
{
    Q_OBJECT
public:
    Rocket_thread();
    void run();

};

#endif // ROCKET_THREAD_H
