/********************************************************************************
** Form generated from reading UI file 'mag_lab7.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAG_LAB7_H
#define UI_MAG_LAB7_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mag_lab7Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mag_lab7Class)
    {
        if (mag_lab7Class->objectName().isEmpty())
            mag_lab7Class->setObjectName("mag_lab7Class");
        mag_lab7Class->resize(600, 400);
        menuBar = new QMenuBar(mag_lab7Class);
        menuBar->setObjectName("menuBar");
        mag_lab7Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mag_lab7Class);
        mainToolBar->setObjectName("mainToolBar");
        mag_lab7Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(mag_lab7Class);
        centralWidget->setObjectName("centralWidget");
        mag_lab7Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mag_lab7Class);
        statusBar->setObjectName("statusBar");
        mag_lab7Class->setStatusBar(statusBar);

        retranslateUi(mag_lab7Class);

        QMetaObject::connectSlotsByName(mag_lab7Class);
    } // setupUi

    void retranslateUi(QMainWindow *mag_lab7Class)
    {
        mag_lab7Class->setWindowTitle(QCoreApplication::translate("mag_lab7Class", "mag_lab7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mag_lab7Class: public Ui_mag_lab7Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAG_LAB7_H
