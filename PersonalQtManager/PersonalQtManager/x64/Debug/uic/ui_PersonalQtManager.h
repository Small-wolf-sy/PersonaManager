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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalQtManagerClass
{
public:
    QWidget *centralWidget;
    QFrame *mainRoleFrame;
    QLabel *RolePicLabel;
    QPushButton *memorButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PersonalQtManagerClass)
    {
        if (PersonalQtManagerClass->objectName().isEmpty())
            PersonalQtManagerClass->setObjectName(QStringLiteral("PersonalQtManagerClass"));
        PersonalQtManagerClass->resize(488, 374);
        centralWidget = new QWidget(PersonalQtManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainRoleFrame = new QFrame(centralWidget);
        mainRoleFrame->setObjectName(QStringLiteral("mainRoleFrame"));
        mainRoleFrame->setGeometry(QRect(180, 20, 251, 281));
        mainRoleFrame->setFrameShape(QFrame::StyledPanel);
        mainRoleFrame->setFrameShadow(QFrame::Raised);
        RolePicLabel = new QLabel(mainRoleFrame);
        RolePicLabel->setObjectName(QStringLiteral("RolePicLabel"));
        RolePicLabel->setGeometry(QRect(50, 60, 161, 161));
        RolePicLabel->setAcceptDrops(false);
        memorButton = new QPushButton(centralWidget);
        memorButton->setObjectName(QStringLiteral("memorButton"));
        memorButton->setGeometry(QRect(30, 20, 101, 31));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        memorButton->setFont(font);
        PersonalQtManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PersonalQtManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 488, 23));
        PersonalQtManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PersonalQtManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PersonalQtManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PersonalQtManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PersonalQtManagerClass->setStatusBar(statusBar);

        retranslateUi(PersonalQtManagerClass);

        QMetaObject::connectSlotsByName(PersonalQtManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PersonalQtManagerClass)
    {
        PersonalQtManagerClass->setWindowTitle(QApplication::translate("PersonalQtManagerClass", "PersonalQtManager", Q_NULLPTR));
        RolePicLabel->setText(QString());
        memorButton->setText(QApplication::translate("PersonalQtManagerClass", "memorandum", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonalQtManagerClass: public Ui_PersonalQtManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALQTMANAGER_H
