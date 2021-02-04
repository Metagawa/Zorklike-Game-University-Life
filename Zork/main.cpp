#include "zork.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Zork w;
    w.show();
    return a.exec();
}
