#include "w1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    W1::get_instance().show();
    return a.exec();
}



