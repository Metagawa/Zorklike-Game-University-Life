#include "uniZork.h"
#include "event.h"
#include "eventlist.h"
#include "ui_uniZork.h"
#include <QDesktopWidget>
#include <QMovie>
#include <QScrollBar>
#include <QSound>
#include <QStringList>
#include <QStyle>
#include <QTabBar>
#include <QTabWidget>
#include <Qt>
#include <QtCore>
#include <iostream>
using namespace std;
bool mapIsHidden = true;
QSound scratchSfx(":/sfx/scratch.wav");
QSound crumpleSfx(":/sfx/crumple.wav");

Zork::Zork(QWidget *parent) : QMainWindow(parent), ui(new Ui::Zork) {
  eventList = new EventList();
  ui->setupUi(this);
  this->setWindowTitle("University Life");
  ui->quitOverlay->hide();
  ui->lasso->hide();
  // ui->quitButton->hide();
  // ui->quitButton_2->hide();
  ui->quitSheet->hide();
  ui->map->hide();
  updateOnChangeStackPaneIndex();
  uniLife = new UniLife();
  time = new Times();
  textDayList = new vector<string>({"", "", "", "", "", "", ""});
  QFontDatabase::addApplicationFont(":/barbies-jalous-sisters.handwriting.ttf");
  QFont grafiti("Barbies Jalous Sisters", 14, QFont::Normal);
  QFontDatabase::addApplicationFont("  :/fonts/Graduate-Regular.ttf");
  QFont graduate("Graduate", 14, QFont::Normal);

  string welcomeText = "Welcome to University Life!\n\n";
  (*textDayList)[0] = (welcomeText);
  ui->plainTextEdit->setPlainText(QString::fromStdString((*textDayList)[0]));
  // ui->plainTextEdit->setStyleSheet("color: blue;");
  ui->plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  // change tab text to Day 1
  // ui->tabWidget->setTabText(0, "Monday");
  // remove tab 2
  // ui->tabWidget->removeTab(1);
  ui->stackedWidget->setCurrentIndex(1);
  updateOnChangeStackPaneIndex();
  ui->lcdNumber->display(QString::fromStdString(time->getTimeString()));
  ui->polaroidLabel->setText(
      QString::fromStdString(uniLife->currentRoom->shortDescription()));

  // update disable buttons
  updateDisabledDirections();
}
void Zork::updateOnChangeStackPaneIndex() {
  if (ui->stackedWidget->currentIndex() == 0) {
    ui->spiral->show();
    ui->watch->show();
    ui->lcdNumber->show();
    ui->mainMenuScreen->hide();

  } else if (ui->stackedWidget->currentIndex() == 1) {
    ui->mainMenuScreen->show();
    ui->spiral->hide();
    ui->watch->hide();
    ui->lcdNumber->hide();
  } else if (ui->stackedWidget->currentIndex() == 2) {
    ui->mainMenuScreen->hide();
    ui->spiral->hide();
    ui->watch->hide();
    ui->lcdNumber->hide();
  }
}

void Zork::updateDisabledDirections() {
  ui->plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
  // get exits
  ui->northButton->setDisabled(false);
  ui->southButton->setDisabled(false);
  ui->eastButton->setDisabled(false);
  ui->westButton->setDisabled(false);
  if (uniLife->currentRoom->nextRoom("north") == NULL) {
    ui->northButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("south") == NULL) {
    ui->southButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("east") == NULL) {
    ui->eastButton->setDisabled(true);
  }
  if (uniLife->currentRoom->nextRoom("west") == NULL) {
    ui->westButton->setDisabled(true);
  }
}
void Zork::eventStart() {
  // for debug ONLY/ add more functionality to determine what event
  currentEvent = eventList->getRandomEvent();

  // sets the event scene stacked widget page

  ui->stackedWidget->setCurrentIndex(2);

  // sets the eventText box equal to the event dialogue.
  // QString::fromStdString(uniLife->currentRoom->longDescription()); is dummy
  // code and needs to be replaced for proper functionality.
  QString currentEventText = QString::fromStdString(currentEvent->text);
  ui->eventText->setPlainText(currentEventText);

  // sets options equal to event options
  // QString::fromStdString(uniLife->currentRoom->longDescription()); is dummy
  // code and needs to be replaced for proper functionality.
  QString currentEventOption1 =
      QString::fromStdString(currentEvent->leftOptiontext);
  ui->option_1->setText(currentEventOption1);

  QString currentEventOption2 =
      QString::fromStdString(currentEvent->rightOptiontext);
  ui->option_2->setText(currentEventOption2);

  // update background image based on room
  bool isRaining = time->isRaining();
  if (time->isDayTime() && !isRaining) {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getDayClear())));
  } else if (time->isDayTime() && isRaining) {
    QMovie *movie =
        new QMovie(QString::fromStdString(uniLife->currentRoom->getDayRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  } else if (!time->isDayTime() && !isRaining) {
    ui->imageBackground_2->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getNightClear())));
  } else if (!time->isDayTime() && isRaining) {
    QMovie *movie = new QMovie(
        QString::fromStdString(uniLife->currentRoom->getNightRain()));
    ui->imageBackground_2->setMovie(movie);
    movie->start();
  }
  // calls updateOnChangeStackPaneIndex so that ui elements are hidden
  // correctly.
  updateOnChangeStackPaneIndex();

  // scene end
  /*
ui->stackedWidget->setCurrentIndex(0);
updateOnChangeStackPaneIndex();*/
}
Zork::~Zork() { delete ui; }

void Zork::updatePositionAfterMoving() {

  ui->tabWidget->setCurrentIndex(time->getDayNum());
  bool itsABrandNewDay = time->advanceTime();
  if (itsABrandNewDay) {
    auto w = new QWidget;
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setSpacing(0);
    QSpacerItem *item =
        new QSpacerItem(13, 0, QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addSpacerItem(item);
    hlayout->setMargin(0);
    // ui->tabWidget->widget(time->getDayNum())->show();
    int tabIndex = time->getDayNum();
    QPlainTextEdit *pte = new QPlainTextEdit();

    pte->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, "
        "255);background-image:url(:/images/misc/lines.png);padding-left: 10;");

    pte->setFont(QFont("MV Boli", 12));
    pte->setReadOnly(true);
    pte->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // pte->setGeometry(25, 0, 426, 342);
    //  pte->move(x()-((25-width()) / 2), y()-((0-height()) / 2));
    pte->setTextInteractionFlags(Qt::NoTextInteraction);

    hlayout->addSpacerItem(item);
    hlayout->addWidget(pte);
    w->setLayout(hlayout);
    ui->tabWidget->insertTab(
        tabIndex, w, QString::fromStdString(time->getDayString(tabIndex)));
    // ui->tabWidget->widget(tabIndex)->hide();
    ui->tabWidget->setCurrentIndex(time->getDayNum());
  }
  ui->lcdNumber->display(QString::fromStdString(time->getTimeString()));

  if (time->getDayNum() == 0) {
    QString currentPlainText =
        ui->plainTextEdit->toPlainText() + QString::fromStdString("\n") +
        QString::fromStdString(uniLife->currentRoom->longDescription() + "\n");

    ui->plainTextEdit->setPlainText(currentPlainText);
    // Puts the scroll bar to the bottom as setting the text moves it back to
    // the top
    ui->plainTextEdit->moveCursor(QTextCursor::End);
    ui->plainTextEdit->ensureCursorVisible();
  } else {
    QPlainTextEdit *qpte =
        ui->tabWidget->currentWidget()->findChild<QPlainTextEdit *>();
    // QPlainTextEdit *qpte =
    // qobject_cast<QPlainTextEdit *>(ui->tabWidget->currentWidget());
    QString currentPlainText =
        qpte->toPlainText() + QString::fromStdString("\n") +
        QString::fromStdString(uniLife->currentRoom->longDescription() + "\n");
    qpte->setPlainText(currentPlainText);
    qpte->moveCursor(QTextCursor::End);
    qpte->ensureCursorVisible();
  }

  // Disables movement buttons based on if movement in that direction is
  // possible or not
  updateDisabledDirections();

  // update image for room
  bool isRaining = time->isRaining();
  if (time->isDayTime() && !isRaining) {
    ui->imageBackground->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getDayClear())));
  } else if (time->isDayTime() && isRaining) {
    QMovie *movie =
        new QMovie(QString::fromStdString(uniLife->currentRoom->getDayRain()));
    ui->imageBackground->setMovie(movie);
    movie->start();
  } else if (!time->isDayTime() && !isRaining) {
    ui->imageBackground->setPixmap(
        QPixmap(QString::fromStdString(uniLife->currentRoom->getNightClear())));
  } else if (!time->isDayTime() && isRaining) {
    QMovie *movie = new QMovie(
        QString::fromStdString(uniLife->currentRoom->getNightRain()));
    ui->imageBackground->setMovie(movie);
    movie->start();
  }

  ui->polaroidLabel->setText(
      QString::fromStdString(uniLife->currentRoom->shortDescription()));
}

void Zork::on_northButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();

  Command *northCommand = new Command("go", "north");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_eastButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();

  Command *northCommand = new Command("go", "east");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_westButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();

  Command *northCommand = new Command("go", "west");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_southButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();

  Command *northCommand = new Command("go", "south");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_examineButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();
}

void Zork::on_infoButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();
}

void Zork::on_mapButton_clicked() {

  scratchSfx.stop();
  scratchSfx.play();

  if (mapIsHidden) {
    ui->lasso->show();
    ui->lasso->setGeometry(uniLife->currentRoom->getLassoX(),
                           uniLife->currentRoom->getLassoY(), 50, 50);
    ui->northButton->setDisabled(true);
    ui->southButton->setDisabled(true);
    ui->eastButton->setDisabled(true);
    ui->westButton->setDisabled(true);
    ui->actButton->setDisabled(true);
    ui->examineButton->setDisabled(true);
    ui->quitButton->setDisabled(true);
    ui->infoButton->setDisabled(true);
    ui->map->show();
    ui->plainTextEdit->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, 255);background-image: "
        "url(:/images/misc/lines.png);padding-left: 10; color: "
        "rgba(0,0,0,0)");
    mapIsHidden = false;

    for (int i = 1; i < ui->tabWidget->count(); i++) {
      QPlainTextEdit *qpte =
          ui->tabWidget->widget(i)->findChild<QPlainTextEdit *>();
      qpte->setStyleSheet(
          "border: 0;background-color: rgb(255, 255, 255);background-image: "
          "url(:/images/misc/lines.png);padding-left: 10; color: "
          "rgba(0,0,0,0)");
    }
    QString tabStyle =
        "QTabBar::tab{min-width: "
        "0px;max-width: 0px; color: rgba(0,0,0,0);background-color: "
        "rgba(0,0,0,0);border: none;"
        "padding-bottom:14px;}";
    ui->tabWidget->setStyleSheet(tabStyle);

  } else {
    ui->lasso->hide();
    updateDisabledDirections();
    ui->actButton->setDisabled(false);
    ui->examineButton->setDisabled(false);
    ui->quitButton->setDisabled(false);
    ui->infoButton->setDisabled(false);

    ui->map->hide();
    mapIsHidden = true;
    ui->plainTextEdit->setStyleSheet(
        "border: 0;background-color: rgb(255, 255, 255);background-image: "
        "url(:/images/misc/lines.png);padding-left: 10; color: ");

    for (int i = 1; i < ui->tabWidget->count(); i++) {
      QPlainTextEdit *qpte =
          ui->tabWidget->widget(i)->findChild<QPlainTextEdit *>();
      qpte->setStyleSheet(
          "border: 0;background-color: rgb(255, 255, 255);background-image: "
          "url(:/images/misc/lines.png);padding-left: 10; color: ");
    }
    QString tabStyle = "QTabBar::tab{"
                       "background-color:rgb(255, 255, 127);border -"
                       "bottom:1px dotted Grey;"
                       "border-top:1px solid LightGrey;"
                       "border-left:1px solid LightGrey;"
                       "border-right:1px solid LightGrey;"
                       "color:"
                       "rgb(0, 0, 0);"
                       "margin-right:2px;"
                       "padding-top:5px;"
                       "padding-bottom:5px;"
                       "padding-right:10px;"
                       " padding-left:10px;"
                       "}"

                       "QTabBar::tab:enabled{"
                       "background-color:rgb(255, 255, 127);"
                       "border-bottom:1px dotted Grey;"
                       "border-top:1px solid LightGrey;"
                       "border-left:1px solid LightGrey;"
                       "border-right:1px solid LightGrey;"
                       "color:"
                       "rgb(0, 0, 0);"
                       "margin-right:2px;"
                       "padding-top:5px;"
                       "padding-bottom:5px;"
                       "padding-right:10px;"
                       "padding-left:10px;"
                       "}"
                       "QTabBar::tab:selected{"
                       "background-color:rgb(100, 255, 100);"
                       "padding-bottom:8px;"
                       "border-bottom:none;"

                       "}";
    ui->tabWidget->setStyleSheet(tabStyle);
  }
}

void Zork::on_actButton_clicked() {
  scratchSfx.stop();
  scratchSfx.play();
  eventStart();
}

void Zork::on_quitButton_clicked() {
  crumpleSfx.stop();
  crumpleSfx.play();
  // disable all buttons
  ui->northButton->setDisabled(true);
  ui->southButton->setDisabled(true);
  ui->eastButton->setDisabled(true);
  ui->westButton->setDisabled(true);
  ui->actButton->setDisabled(true);
  ui->examineButton->setDisabled(true);
  ui->quitButton->setDisabled(true);
  ui->infoButton->setDisabled(true);
  ui->mapButton->setDisabled(true);
  ui->quitOverlay->show();

  ui->quitSheet->show();
}

void Zork::on_goToExplore_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  updatePositionAfterMoving();
  updateOnChangeStackPaneIndex();
}

void Zork::on_quitButton_2_clicked() {
  crumpleSfx.stop();
  crumpleSfx.play();
  ui->quitOverlay->show();
  ui->quitSheet->show();
}

void Zork::on_quitCancel_clicked() {
  crumpleSfx.stop();
  crumpleSfx.play();
  updateDisabledDirections();
  ui->actButton->setDisabled(false);
  ui->examineButton->setDisabled(false);
  ui->quitButton->setDisabled(false);
  ui->infoButton->setDisabled(false);
  ui->quitOverlay->hide();
  ui->quitSheet->hide();
}

void Zork::on_quitConfirm_clicked() { QApplication::quit(); }

// for debug ONLY/ replace with a call to an event outcome
void Zork::on_option_1_clicked() {
  if (currentEvent->leftOption == NULL) {
    ui->stackedWidget->setCurrentIndex(0);
    updateOnChangeStackPaneIndex();
    return;
  }
  currentEvent = currentEvent->leftOption;
  QString currentEventText = QString::fromStdString(currentEvent->text);
  ui->eventText->setPlainText(currentEventText);

  QString currentEventOption1 =
      QString::fromStdString(currentEvent->leftOptiontext);
  ui->option_1->setText(currentEventOption1);

  QString currentEventOption2 =
      QString::fromStdString(currentEvent->rightOptiontext);
  ui->option_2->setText(currentEventOption2);
}

void Zork::on_option_2_clicked() {
  if (currentEvent == NULL || currentEvent->rightOption == NULL) {
    ui->stackedWidget->setCurrentIndex(0);
    updateOnChangeStackPaneIndex();
    return;
  }

  Event *now = currentEvent->rightOption;

  QString currentEventText = QString::fromStdString(now->text);
  ui->eventText->setPlainText(currentEventText);

  QString currentEventOption1 = QString::fromStdString(now->leftOptiontext);
  ui->option_1->setText(currentEventOption1);

  QString currentEventOption2 = QString::fromStdString(now->rightOptiontext);
  ui->option_2->setText(currentEventOption2);
}
