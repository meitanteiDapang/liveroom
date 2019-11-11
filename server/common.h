#ifndef COMMON_H
#define COMMON_H

#include <QMap>
#include <QVector>

#define IP_ADDRESS "127.0.0.1"
#define PORT "8888"
#define DB_PATH "/Users/yzh/Desktop/project/liveroom/server/liveroom.db"
#define INTERVAL 1000

#define RECEIVE true
#define SEND false


//for rooms list and people list in room
typedef QMap<int, QVector<int> > MAP;// first int for caster, qvector for audiences id
typedef QPair<int, QVector<int> > PAIR;



class common
{
public:
    common();
};

#endif // COMMON_H
