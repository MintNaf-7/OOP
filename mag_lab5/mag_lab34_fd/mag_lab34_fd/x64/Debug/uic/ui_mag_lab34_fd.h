/********************************************************************************
** Form generated from reading UI file 'mag_lab34_fd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAG_LAB34_FD_H
#define UI_MAG_LAB34_FD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mag_lab34_fdClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mag_lab34_fdClass)
    {
        if (mag_lab34_fdClass->objectName().isEmpty())
            mag_lab34_fdClass->setObjectName(QString::fromUtf8("mag_lab34_fdClass"));
        mag_lab34_fdClass->resize(600, 400);
        menuBar = new QMenuBar(mag_lab34_fdClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        mag_lab34_fdClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mag_lab34_fdClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mag_lab34_fdClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(mag_lab34_fdClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mag_lab34_fdClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mag_lab34_fdClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mag_lab34_fdClass->setStatusBar(statusBar);

        retranslateUi(mag_lab34_fdClass);

        QMetaObject::connectSlotsByName(mag_lab34_fdClass);
    } // setupUi

    void retranslateUi(QMainWindow *mag_lab34_fdClass)
    {
        mag_lab34_fdClass->setWindowTitle(QCoreApplication::translate("mag_lab34_fdClass", "mag_lab34_fd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mag_lab34_fdClass: public Ui_mag_lab34_fdClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAG_LAB34_FD_H
