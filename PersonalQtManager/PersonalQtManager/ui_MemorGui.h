/********************************************************************************
** Form generated from reading UI file 'MemorGuip16644.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MEMORGUIP16644_H
#define MEMORGUIP16644_H

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
    QGroupBox *groupBox;
    QLabel *yearlabel_3;
    QTextEdit *day_input;
    QTextEdit *month_input;
    QLabel *yearlabel_2;
    QTextEdit *year_input;
    QLabel *yearlabel;

    void setupUi(QWidget *MemorGui)
    {
        if (MemorGui->objectName().isEmpty())
            MemorGui->setObjectName(QStringLiteral("MemorGui"));
        MemorGui->resize(447, 429);
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
        memoryFrame->setGeometry(QRect(150, 20, 291, 401));
        memoryFrame->setFrameShape(QFrame::StyledPanel);
        memoryFrame->setFrameShadow(QFrame::Raised);
        detailDesrciption = new QPlainTextEdit(memoryFrame);
        detailDesrciption->setObjectName(QStringLiteral("detailDesrciption"));
        detailDesrciption->setGeometry(QRect(52, 170, 220, 181));
        memKey = new QTextEdit(memoryFrame);
        memKey->setObjectName(QStringLiteral("memKey"));
        memKey->setGeometry(QRect(100, 10, 121, 31));
        timeRecord = new QTextEdit(memoryFrame);
        timeRecord->setObjectName(QStringLiteral("timeRecord"));
        timeRecord->setGeometry(QRect(100, 50, 121, 31));
        operateCheckBox = new QDialogButtonBox(memoryFrame);
        operateCheckBox->setObjectName(QStringLiteral("operateCheckBox"));
        operateCheckBox->setGeometry(QRect(87, 359, 156, 23));
        operateCheckBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(memoryFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 31, 16));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(memoryFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 56, 91, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(memoryFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(12, 210, 30, 101));
        label_3->setFont(font1);
        label_3->setScaledContents(false);
        label_3->setWordWrap(false);
        groupBox = new QGroupBox(memoryFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 90, 251, 71));
        groupBox->setFont(font1);
        yearlabel_3 = new QLabel(groupBox);
        yearlabel_3->setObjectName(QStringLiteral("yearlabel_3"));
        yearlabel_3->setGeometry(QRect(173, 31, 40, 30));
        yearlabel_3->setFont(font1);
        day_input = new QTextEdit(groupBox);
        day_input->setObjectName(QStringLiteral("day_input"));
        day_input->setGeometry(QRect(200, 30, 41, 31));
        month_input = new QTextEdit(groupBox);
        month_input->setObjectName(QStringLiteral("month_input"));
        month_input->setGeometry(QRect(130, 30, 41, 31));
        yearlabel_2 = new QLabel(groupBox);
        yearlabel_2->setObjectName(QStringLiteral("yearlabel_2"));
        yearlabel_2->setGeometry(QRect(86, 36, 51, 21));
        yearlabel_2->setFont(font1);
        year_input = new QTextEdit(groupBox);
        year_input->setObjectName(QStringLiteral("year_input"));
        year_input->setGeometry(QRect(30, 30, 51, 31));
        yearlabel = new QLabel(groupBox);
        yearlabel->setObjectName(QStringLiteral("yearlabel"));
        yearlabel->setGeometry(QRect(0, 36, 31, 21));
        yearlabel->setFont(font1);

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
        label_2->setText(QApplication::translate("MemorGui", "RecordTime", Q_NULLPTR));
        label_3->setText(QApplication::translate("MemorGui", "Desc", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MemorGui", "DeadLine", Q_NULLPTR));
        yearlabel_3->setText(QApplication::translate("MemorGui", "day", Q_NULLPTR));
        yearlabel_2->setText(QApplication::translate("MemorGui", "month", Q_NULLPTR));
        yearlabel->setText(QApplication::translate("MemorGui", "Year", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemorGui: public Ui_MemorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MEMORGUIP16644_H
