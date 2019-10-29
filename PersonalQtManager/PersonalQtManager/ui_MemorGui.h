/********************************************************************************
** Form generated from reading UI file 'MemorGuiHp2560.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MEMORGUIHP2560_H
#define MEMORGUIHP2560_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

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
        detailDesrciption->setGeometry(QRect(47, 90, 160, 161));
        memKey = new QTextEdit(memoryFrame);
        memKey->setObjectName(QStringLiteral("memKey"));
        memKey->setGeometry(QRect(47, 10, 121, 31));
        timeRecord = new QTextEdit(memoryFrame);
        timeRecord->setObjectName(QStringLiteral("timeRecord"));
        timeRecord->setGeometry(QRect(47, 50, 121, 31));
        operateCheckBox = new QDialogButtonBox(memoryFrame);
        operateCheckBox->setObjectName(QStringLiteral("operateCheckBox"));
        operateCheckBox->setGeometry(QRect(47, 260, 156, 23));
        operateCheckBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(memoryFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 31, 16));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(memoryFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 31, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(memoryFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 31, 101));
        label_3->setFont(font1);
        label_3->setScaledContents(false);
        label_3->setWordWrap(false);

        retranslateUi(MemorGui);

        QMetaObject::connectSlotsByName(MemorGui);
    } // setupUi

    void retranslateUi(QWidget *MemorGui)
    {
        MemorGui->setWindowTitle(QApplication::translate("MemorGui", "MemorGui", Q_NULLPTR));
        groupOperation->setTitle(QApplication::translate("MemorGui", "Operation", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MemorGui", "Search", Q_NULLPTR));
        addButton->setText(QApplication::translate("MemorGui", "Add", Q_NULLPTR));
        label->setText(QApplication::translate("MemorGui", "Key", Q_NULLPTR));
        label_2->setText(QApplication::translate("MemorGui", "time", Q_NULLPTR));
        label_3->setText(QApplication::translate("MemorGui", "Desc", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemorGui: public Ui_MemorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MEMORGUIHP2560_H
