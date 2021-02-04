#include "zork.h"
#include "ui_zork.h"

Zork::Zork(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zork)
{
    ui->setupUi(this);
    zorkUL = new ZorkUL();
    zorkUL->printWelcome();
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
