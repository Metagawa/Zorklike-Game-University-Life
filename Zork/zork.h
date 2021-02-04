#ifndef ZORK_H
#define ZORK_H

#include <QMainWindow>
#include "ZorkUL.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Zork; }
QT_END_NAMESPACE

class Zork : public QMainWindow
{
    Q_OBJECT

public:
    Zork(QWidget *parent = nullptr);
    ~Zork();

private slots:
    void on_welcomeButton_clicked();

private:
    Ui::Zork *ui;
    ZorkUL *zorkUL;

};
#endif // ZORK_H