#include "uniZork.h"
#include <QApplication>
#include <QMutex>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
  //sets a new QApplication with the passed arguments
  QApplication a(argc, argv);
  //creates a pixmap for the splash screen and sets it
  QPixmap pixmap(":/images/misc/splash.png");
  QSplashScreen splash(pixmap);
  //displays the splash screen on launch for 1.5 seconds
  splash.show();
  QTimer::singleShot(1500, &splash, &QWidget::close);
  //creates a new Zork window
  Zork w;
  //locks the thread so that the game window doesn't appear behind the splash screen
  QMutex mut;
  mut.lock();
  mut.tryLock(1500);
  //unlocks the thread and shows the game window
  mut.unlock();
  w.show();
  //sets a custom cursor
  a.setOverrideCursor(QCursor(QPixmap(":/images/misc/black-biro.png")));
  return a.exec();
}
