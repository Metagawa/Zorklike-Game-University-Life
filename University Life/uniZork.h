#ifndef UNIZORK_H
#define UNIZORK_H

#include "character.h"
#include "eventlist.h"
#include "ramblelist.h"
#include "times.h"
#include "uniLife.h"
#include <QMainWindow>
#include <QStringList>
#include <string>
using namespace std;
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

  void on_examineButton_clicked();

  void on_infoButton_clicked();

  void on_mapButton_clicked();

  void on_actButton_clicked();

  void on_quitButton_clicked();

  void on_goToExplore_clicked();

  void on_quitButton_2_clicked();

  void on_quitCancel_clicked();

  void on_quitConfirm_clicked();

  void on_option_1_clicked();

  void on_option_2_clicked();

  void on_notebookButton_clicked();

private:
  Ui::Zork *ui;
  UniLife *uniLife;
  vector<string> *textDayList;
  Times *time;
  void updatePositionAfterMoving();
  void updateOnChangeStackPaneIndex();
  void updateDisabledDirections();
  void eventStart();
  string getRoomName(string s);
  string eventExistsText;
  EventList *eventList;
  RambleList *rambleList;
  Ramble *currentRamble;
  Event *currentEvent;
  void updateNumberOfOptions();
  void updateLocation();
  void updateNotebookDuringEvent(QString text);
  void interactChance();
  bool interactEnabled = false;
  Character *tim;
};
#endif // UNIZORK_H
