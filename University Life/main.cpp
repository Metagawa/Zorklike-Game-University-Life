#include "uniZork.h"
#include <QApplication>
#include <QMutex>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QPixmap pixmap(":/new/images/images/splash.png");
  a.setOverrideCursor(QCursor(QPixmap(":/images/black-biro.png")));
  QSplashScreen splash(pixmap);
  splash.show();
  QTimer::singleShot(1500, &splash,
                     &QWidget::close); // keep displayed for 5 seconds
  Zork w;

  // splash.finish(&w);
  QMutex mut;
  mut.lock();
  mut.tryLock(1500);
  mut.unlock(); // I am not sure if this is a necessity
  w.show();
  return a.exec();
}
