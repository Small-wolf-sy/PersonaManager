/********************************************************************************
** Form generated from reading UI file 'MemorGuiHp7440.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MEMORGUIHP7440_H
#define MEMORGUIHP7440_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemorGui
{
public:
    QGroupBox *groupOperation;
    QPushButton *searchButton;
    QPushButton *addButton;
    QFrame *memoryFrame;
    QPlainTextEdit *detailDesrciption;
    QTextEdit *memKey;
    QTextEdit *timeRecord;
    QDialogButtonBox *operateCheckBox;

    void setupUi(QWidget *MemorGui)
    {
        if (MemorGui->objectName().isEmpty())
            MemorGui->setObjectName(QStringLiteral("MemorGui"));
        MemorGui->resize(383, 306);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        MemorGui->setFont(font);
        groupOperation = new QGroupBox(MemorGui);
        groupOperation->setObjectName(QStringLiteral("groupOperation"));
        groupOperation->setGeometry(QRect(10, 10, 131, 101));
        searchButton = new QPushButton(groupOperation);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(30, 30, 75, 23));
        addButton = new QPushButton(groupOperation);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(30, 60, 75, 23));
        memoryFrame = new QFrame(MemorGui);
        memoryFrame->setObjectName(QStringLiteral("memoryFrame"));
        memoryFrame->setGeometry(QRect(160, 10, 221, 291));
        memoryFrame->setFrameShape(QFrame::StyledPanel);
        memoryFrame->setFrameShadow(QFrame::Raised);
        detailDesrciption = new QPlainTextEdit(memoryFrame);
        detailDesrciption->setObjectName(QStringLiteral("detailDesrciption"));
        detailDesrciption->setGeometry(QRect(30, 90, 161, 161));
        memKey = new QTextEdit(memoryFrame);
        memKey->setObjectName(QStringLiteral("memKey"));
        memKey->setGeometry(QRect(30, 10, 121, 31));
        timeRecord = new QTextEdit(memoryFrame);
        timeRecord->setObjectName(QStringLiteral("timeRecord"));
        timeRecord->setGeometry(QRect(30, 50, 121, 31));
        operateCheckBox = new QDialogButtonBox(memoryFrame);
        operateCheckBox->setObjectName(QStringLiteral("operateCheckBox"));
        operateCheckBox->setGeometry(QRect(30, 260, 156, 23));
        operateCheckBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(MemorGui);

        QMetaObject::connectSlotsByName(MemorGui);
    } // setupUi

    void retranslateUi(QWidget *MemorGui)
    {
        MemorGui->setWindowTitle(QApplication::translate("MemorGui", "MemorGui", Q_NULLPTR));
        groupOperation->setTitle(QApplication::translate("MemorGui", "Operation", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MemorGui", "Search", Q_NULLPTR));
        addButton->setText(QApplication::translate("MemorGui", "Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemorGui: public Ui_MemorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MEMORGUIHP7440_H
