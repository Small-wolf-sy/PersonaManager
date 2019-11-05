/********************************************************************************
** Form generated from reading UI file 'DataVisualWindowp16336.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DATAVISUALWINDOWP16336_H
#define DATAVISUALWINDOWP16336_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *mainFrame;
    QLabel *mainPicLabel;
    QGraphicsView *mainGraphicView;
    QDialogButtonBox *checkbuttonbox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 590);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QStringLiteral("mainFrame"));
        mainFrame->setGeometry(QRect(30, 0, 731, 511));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);
        mainPicLabel = new QLabel(mainFrame);
        mainPicLabel->setObjectName(QStringLiteral("mainPicLabel"));
        mainPicLabel->setGeometry(QRect(350, 220, 54, 12));
        mainGraphicView = new QGraphicsView(mainFrame);
        mainGraphicView->setObjectName(QStringLiteral("mainGraphicView"));
        mainGraphicView->setGeometry(QRect(0, 4, 731, 510));
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::NoBrush);
        mainGraphicView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::NoBrush);
        mainGraphicView->setForegroundBrush(brush1);
        checkbuttonbox = new QDialogButtonBox(centralwidget);
        checkbuttonbox->setObjectName(QStringLiteral("checkbuttonbox"));
        checkbuttonbox->setGeometry(QRect(600, 520, 156, 23));
        checkbuttonbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        mainPicLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATAVISUALWINDOWP16336_H
