#include "uniZork.h"
#include "ui_uniZork.h"
#include <QDesktopWidget>
#include <QScrollBar>
#include <QStringList>
#include <QStyle>
#include <QTabBar>
#include <QTabWidget>
#include <iostream>
using namespace std;
Zork::Zork(QWidget *parent) : QMainWindow(parent), ui(new Ui::Zork) {
  ui->setupUi(this);
  this->setWindowTitle("Univeristy Life");
  updateOnChangeStackPaneIndex();
  uniLife = new UniLife();
  uniLife->printWelcome();
  time = new Times();
  textDayList = new vector<string>({"", "", "", "", "", "", ""});
  QFontDatabase::addApplicationFont(":/barbies-jalous-sisters.handwriting.ttf");
  QFont grafiti("Barbies Jalous Sisters", 14, QFont::Normal);
  string welcomeText = "start \ninfo for help\n\n" +
                       uniLife->currentRoom->longDescription() + "\n";
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
  ui->polaroidLabel->setText(QString::fromStdString(
      getRoomName(uniLife->currentRoom->shortDescription())));
}
void Zork::updateOnChangeStackPaneIndex() {
  if (ui->stackedWidget->currentIndex() == 0) {
    ui->centralwidget->setStyleSheet(
        "QWidget #centralwidget {\n	background-image: "
        "url(:/new/images/images/desktop.png);\n\n}");
    ui->spiral->show();
    ui->watch->show();
    ui->lcdNumber->show();
  } else {
    ui->spiral->hide();
    ui->centralwidget->setStyleSheet("");
    ui->watch->hide();
    ui->lcdNumber->hide();
  }
}

string Zork::getRoomName(string s) {

  if (s == "a") {
    return "Gym";
  } else if (s == "f") {
    return "Business room";
  }
  return "Unknown";
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

    pte->setStyleSheet("border: 0;background-color: rgb(255, 255, "
                       "255);background-image:url(:/new/images/images/"
                       "lines.png);padding-left: 10;");

    pte->setFont(QFont("MV Boli", 12));
    pte->setReadOnly(true);
    pte->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // pte->setGeometry(25, 0, 426, 342);
    //  pte->move(x() - ((25 - width()) / 2), y() - ((0 - height()) / 2));
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

  // update image for room
  if (uniLife->currentRoom->shortDescription() == "a") {
    ui->imageBackground->setPixmap(QPixmap(":/new/images/images/gym-room.png"));
  } else if (uniLife->currentRoom->shortDescription() == "f") {
    ui->imageBackground->setPixmap(
        QPixmap(":/new/images/images/business-room.png"));
  }
  ui->polaroidLabel->setText(QString::fromStdString(
      getRoomName(uniLife->currentRoom->shortDescription())));
}

void Zork::on_northButton_clicked() {
  Command *northCommand = new Command("go", "north");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_eastButton_clicked() {
  Command *northCommand = new Command("go", "east");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_westButton_clicked() {
  Command *northCommand = new Command("go", "west");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_southButton_clicked() {
  Command *northCommand = new Command("go", "south");
  uniLife->processCommand(*northCommand);
  updatePositionAfterMoving();
}

void Zork::on_takeButton_clicked() {
  Command *takeCommand = new Command("take", "x");
  uniLife->processCommand(*takeCommand);
}

void Zork::on_infoButton_clicked() {
  Command *infoCommand = new Command("info", "");
  uniLife->processCommand(*infoCommand);
}

void Zork::on_mapButton_clicked() {
  Command *mapCommand = new Command("map", "");
  uniLife->processCommand(*mapCommand);
}

void Zork::on_putButton_clicked() {
  Command *putCommand = new Command("put", "x");
  uniLife->processCommand(*putCommand);
}

void Zork::on_quitButton_clicked() { QApplication::quit(); }

void Zork::on_goToExplore_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  updateOnChangeStackPaneIndex();
}
