#ifndef UNIZORK_H
#define UNIZORK_H

#include "character.h"
#include "eventlist.h"
#include "ramblelist.h"
#include "times.h"
#include "uniLife.h"
#include <QMainWindow>
#include <QStringList>
#include <exception>
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
  template <typename T> void debugMini(const T x) { //example of template function
    cout << "The string value of X is " << x << endl;
  }

  template <typename T> void debug(const T x) { //example of template function
    cout << "Name of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The compiler gives a __cplusplus value of " << __cplusplus << endl;
    debugMini(x);
  }
  Zork(QWidget *parent = nullptr);
  ~Zork();

  class exceptionZork : public exception {}; //example of exception class
  template <class T> class TemplatePair {
    T pair[2];

  public:
    TemplatePair(T one, T two) { //example of template class
      pair[0] = one;
      pair[1] = two;
    }
    void printPair() {
      cout << "value 1 is: " << pair[0] << endl;
      cout << "value 2 is: " << pair[1] << endl;
    }
    T getFirst() { return pair[0]; }
    T getSecond() { return pair[1]; }
  };

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
  void eventStartSpecific();
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
  Character *charname;
};
#endif // UNIZORK_H
