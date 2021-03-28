#include "uniZork.h"
#include "ui_uniZork.h"
#include <QScrollBar>
#include <QTabBar>
#include <QTabWidget>
Zork::Zork(QWidget *parent) : QMainWindow(parent), ui(new Ui::Zork) {
  ui->setupUi(this);
  updateOnChangeStackPaneIndex();
  uniLife = new UniLife();
  uniLife->printWelcome();
  string welcomeText = "start \ninfo for help\n\n" +
                       uniLife->currentRoom->longDescription() + "\n";
  ui->plainTextEdit->setPlainText(QString::fromStdString(welcomeText));
  // ui->plainTextEdit->setStyleSheet("color: blue;");
  ui->plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  // change tab text to Day 1
  ui->tabWidget->setTabText(0, "Monday");
  // remove tab 2
  ui->tabWidget->removeTab(1);
  ui->stackedWidget->setCurrentIndex(1);
  updateOnChangeStackPaneIndex();
}
void Zork::updateOnChangeStackPaneIndex() {
  if (ui->stackedWidget->currentIndex() == 0) {
    ui->spiral->show();
  } else {
    ui->spiral->hide();
  }
}

Zork::~Zork() { delete ui; }

void Zork::updatePositionAfterMoving() {
  QString currentPlainText =
      ui->plainTextEdit->toPlainText() + QString::fromStdString("\n") +
      QString::fromStdString(uniLife->currentRoom->longDescription() + "\n");

  ui->plainTextEdit->setPlainText(currentPlainText);

  // Puts the scroll bar to the bottom as setting the text moves it back to the
  // top
  ui->plainTextEdit->moveCursor(QTextCursor::End);
  ui->plainTextEdit->ensureCursorVisible();

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
