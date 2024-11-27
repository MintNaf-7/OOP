/********************************************************************************
** Form generated from reading UI file 'Demo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DemoClass)
    {
        if (DemoClass->objectName().isEmpty())
            DemoClass->setObjectName(QString::fromUtf8("DemoClass"));
        DemoClass->resize(600, 400);
        menuBar = new QMenuBar(DemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DemoClass->setStatusBar(statusBar);

        retranslateUi(DemoClass);

        QMetaObject::connectSlotsByName(DemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *DemoClass)
    {
        DemoClass->setWindowTitle(QCoreApplication::translate("DemoClass", "Demo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DemoClass: public Ui_DemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
