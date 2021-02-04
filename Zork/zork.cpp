#include "zork.h"
#include "ui_zork.h"

Zork::Zork(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zork)
{
    ui->setupUi(this);
    zorkUL = new ZorkUL();
}

Zork::~Zork()
{
    delete ui;
}


void Zork::on_welcomeButton_clicked()
{
    zorkUL->printWelcome();
}
