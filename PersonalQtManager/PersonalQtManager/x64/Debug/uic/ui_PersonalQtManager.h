/********************************************************************************
** Form generated from reading UI file 'PersonalQtManager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALQTMANAGER_H
#define UI_PERSONALQTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalQtManagerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PersonalQtManagerClass)
    {
        if (PersonalQtManagerClass->objectName().isEmpty())
            PersonalQtManagerClass->setObjectName(QStringLiteral("PersonalQtManagerClass"));
        PersonalQtManagerClass->resize(600, 400);
        menuBar = new QMenuBar(PersonalQtManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PersonalQtManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PersonalQtManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PersonalQtManagerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PersonalQtManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PersonalQtManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PersonalQtManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PersonalQtManagerClass->setStatusBar(statusBar);

        retranslateUi(PersonalQtManagerClass);

        QMetaObject::connectSlotsByName(PersonalQtManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PersonalQtManagerClass)
    {
        PersonalQtManagerClass->setWindowTitle(QApplication::translate("PersonalQtManagerClass", "PersonalQtManager", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonalQtManagerClass: public Ui_PersonalQtManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALQTMANAGER_H
