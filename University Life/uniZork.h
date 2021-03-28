#ifndef UNIZORK_H
#define UNIZORK_H

#include "uniLife.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Zork;
}
QT_END_NAMESPACE

class Zork : public QMainWindow {
  Q_OBJECT

public:
  Zork(QWidget *parent = nullptr);
  ~Zork();

private slots:

  void on_northButton_clicked();

  void on_eastButton_clicked();

  void on_westButton_clicked();

  void on_southButton_clicked();

  void on_takeButton_clicked();

  void on_infoButton_clicked();

  void on_mapButton_clicked();

  void on_putButton_clicked();

  void on_quitButton_clicked();

  void on_goToExplore_clicked();

  void update_splash();

private:
  Ui::Zork *ui;
  UniLife *uniLife;
  void updatePositionAfterMoving();
};
#endif // UNIZORK_H
