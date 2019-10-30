/********************************************************************************
** Form generated from reading UI file 'PersonalQtManagerHp6736.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PERSONALQTMANAGERHP6736_H
#define PERSONALQTMANAGERHP6736_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *StatusBox;
    QLabel *timeLabel;
    QLabel *CpuLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PersonalQtManagerClass)
    {
        if (PersonalQtManagerClass->objectName().isEmpty())
            PersonalQtManagerClass->setObjectName(QStringLiteral("PersonalQtManagerClass"));
        PersonalQtManagerClass->resize(446, 384);
        centralWidget = new QWidget(PersonalQtManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainRoleFrame = new QFrame(centralWidget);
        mainRoleFrame->setObjectName(QStringLiteral("mainRoleFrame"));
        mainRoleFrame->setGeometry(QRect(190, 10, 251, 281));
        mainRoleFrame->setFrameShape(QFrame::StyledPanel);
        mainRoleFrame->setFrameShadow(QFrame::Raised);
        RolePicLabel = new QLabel(mainRoleFrame);
        RolePicLabel->setObjectName(QStringLiteral("RolePicLabel"));
        RolePicLabel->setGeometry(QRect(50, 60, 161, 161));
        RolePicLabel->setAcceptDrops(false);
        memorButton = new QPushButton(centralWidget);
        memorButton->setObjectName(QStringLiteral("memorButton"));
        memorButton->setGeometry(QRect(30, 10, 101, 31));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        memorButton->setFont(font);
        StatusBox = new QGroupBox(centralWidget);
        StatusBox->setObjectName(QStringLiteral("StatusBox"));
        StatusBox->setGeometry(QRect(0, 240, 161, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        StatusBox->setFont(font1);
        timeLabel = new QLabel(StatusBox);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(30, 20, 101, 20));
        timeLabel->setFont(font1);
        CpuLabel = new QLabel(StatusBox);
        CpuLabel->setObjectName(QStringLiteral("CpuLabel"));
        CpuLabel->setGeometry(QRect(40, 50, 54, 12));
        PersonalQtManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PersonalQtManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 446, 23));
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
        StatusBox->setTitle(QApplication::translate("PersonalQtManagerClass", "Status", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("PersonalQtManagerClass", "timeLabel", Q_NULLPTR));
        CpuLabel->setText(QApplication::translate("PersonalQtManagerClass", "CPU", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonalQtManagerClass: public Ui_PersonalQtManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PERSONALQTMANAGERHP6736_H
