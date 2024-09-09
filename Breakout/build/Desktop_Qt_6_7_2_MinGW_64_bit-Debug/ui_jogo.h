/********************************************************************************
** Form generated from reading UI file 'jogo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOGO_H
#define UI_JOGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jogo
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Jogo)
    {
        if (Jogo->objectName().isEmpty())
            Jogo->setObjectName("Jogo");
        Jogo->resize(800, 600);
        centralwidget = new QWidget(Jogo);
        centralwidget->setObjectName("centralwidget");
        Jogo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Jogo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Jogo->setMenuBar(menubar);
        statusbar = new QStatusBar(Jogo);
        statusbar->setObjectName("statusbar");
        Jogo->setStatusBar(statusbar);

        retranslateUi(Jogo);

        QMetaObject::connectSlotsByName(Jogo);
    } // setupUi

    void retranslateUi(QMainWindow *Jogo)
    {
        Jogo->setWindowTitle(QCoreApplication::translate("Jogo", "Jogo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Jogo: public Ui_Jogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOGO_H
