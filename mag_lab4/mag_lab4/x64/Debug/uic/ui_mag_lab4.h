/********************************************************************************
** Form generated from reading UI file 'mag_lab4.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAG_LAB4_H
#define UI_MAG_LAB4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mag_lab4Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mag_lab4Class)
    {
        if (mag_lab4Class->objectName().isEmpty())
            mag_lab4Class->setObjectName(QString::fromUtf8("mag_lab4Class"));
        mag_lab4Class->resize(600, 400);
        menuBar = new QMenuBar(mag_lab4Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        mag_lab4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mag_lab4Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mag_lab4Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(mag_lab4Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mag_lab4Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mag_lab4Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mag_lab4Class->setStatusBar(statusBar);

        retranslateUi(mag_lab4Class);

        QMetaObject::connectSlotsByName(mag_lab4Class);
    } // setupUi

    void retranslateUi(QMainWindow *mag_lab4Class)
    {
        mag_lab4Class->setWindowTitle(QCoreApplication::translate("mag_lab4Class", "mag_lab4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mag_lab4Class: public Ui_mag_lab4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAG_LAB4_H
