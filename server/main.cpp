#include "w1.h"
#include "db_handler.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Db_handler::get_instance()->init();
    W1::get_instance().show();
    return a.exec();
}
