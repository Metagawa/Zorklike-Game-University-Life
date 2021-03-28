#include "uniZork.h"
#include <QApplication>
#include <QMutex>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QPixmap pixmap(":/new/images/images/splash.png");
  QSplashScreen splash(pixmap);
  splash.show();
  QTimer::singleShot(5000, &splash,
                     &QWidget::close); // keep displayed for 5 seconds
  Zork w;

  // splash.finish(&w);
  QMutex mut;
  mut.lock();
  mut.tryLock(5000);
  mut.unlock(); // I am not sure if this is a necessity
  w.show();
  return a.exec();
}
