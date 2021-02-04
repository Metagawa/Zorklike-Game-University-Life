#include "zork.h"
#include "ui_zork.h"

Zork::Zork(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zork)
{
    ui->setupUi(this);
    zorkUL = new ZorkUL();
    zorkUL->printWelcome();
    string welcomeText = "start \ninfo for help\n\n"+ zorkUL->currentRoom->longDescription();
    ui->plainTextEdit->setPlainText(QString::fromStdString(welcomeText));
}

Zork::~Zork()
{
    delete ui;
}




void Zork::on_northButton_clicked()
{
    Command *northCommand = new Command("go", "north");
    zorkUL->processCommand(*northCommand);
}

void Zork::on_eastButton_clicked()
{
    Command *northCommand = new Command("go", "east");
    zorkUL->processCommand(*northCommand);
}

void Zork::on_westButton_clicked()
{
    Command *northCommand = new Command("go", "west");
    zorkUL->processCommand(*northCommand);
}

void Zork::on_southButton_clicked()
{
    Command *northCommand = new Command("go", "south");
    zorkUL->processCommand(*northCommand);
}

void Zork::on_takeButton_clicked()
{
    Command *takeCommand = new Command("take", "x");
    zorkUL->processCommand(*takeCommand);
}

void Zork::on_infoButton_clicked()
{
    Command *infoCommand = new Command("info","");
    zorkUL->processCommand(*infoCommand);
}


void Zork::on_mapButton_clicked()
{
    Command *mapCommand = new Command("map","");
    zorkUL->processCommand(*mapCommand);
}

void Zork::on_putButton_clicked()
{
    Command *putCommand = new Command("put", "x");
    zorkUL->processCommand(*putCommand);
}

void Zork::on_quitButton_clicked()
{
    QApplication::quit();

}
