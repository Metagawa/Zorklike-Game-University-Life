/********************************************************************************
** Form generated from reading UI file 'zork.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZORK_H
#define UI_ZORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zork
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *welcomeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Zork)
    {
        if (Zork->objectName().isEmpty())
            Zork->setObjectName(QString::fromUtf8("Zork"));
        Zork->resize(800, 600);
        centralwidget = new QWidget(Zork);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        welcomeButton = new QPushButton(centralwidget);
        welcomeButton->setObjectName(QString::fromUtf8("welcomeButton"));

        gridLayout->addWidget(welcomeButton, 0, 0, 1, 1);

        Zork->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Zork);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Zork->setMenuBar(menubar);
        statusbar = new QStatusBar(Zork);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Zork->setStatusBar(statusbar);

        retranslateUi(Zork);

        QMetaObject::connectSlotsByName(Zork);
    } // setupUi

    void retranslateUi(QMainWindow *Zork)
    {
        Zork->setWindowTitle(QCoreApplication::translate("Zork", "Zork", nullptr));
        welcomeButton->setText(QCoreApplication::translate("Zork", "Print Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zork: public Ui_Zork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZORK_H
