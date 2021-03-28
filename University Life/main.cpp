#include "uniZork.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/new/images/images/splash.png");
    QSplashScreen splash(pixmap);
        splash.show();
    Zork w;
    w.show();
        splash.finish(&w);
    return a.exec();
}
