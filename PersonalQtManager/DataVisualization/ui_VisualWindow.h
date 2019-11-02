/********************************************************************************
** Form generated from reading UI file 'VisualWindowHp8796.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VISUALWINDOWHP8796_H
#define VISUALWINDOWHP8796_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QFrame *GraphicFrame;
    QFrame *line;

    void setupUi(QDialog *VisualDialog)
    {
        if (VisualDialog->objectName().isEmpty())
            VisualDialog->setObjectName(QStringLiteral("VisualDialog"));
        VisualDialog->resize(652, 511);
        layoutWidget = new QWidget(VisualDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 470, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        saveButton->setFont(font);

        hboxLayout->addWidget(saveButton);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setFont(font);

        hboxLayout->addWidget(clearButton);

        GraphicFrame = new QFrame(VisualDialog);
        GraphicFrame->setObjectName(QStringLiteral("GraphicFrame"));
        GraphicFrame->setGeometry(QRect(10, 40, 631, 421));
        GraphicFrame->setFrameShape(QFrame::StyledPanel);
        GraphicFrame->setFrameShadow(QFrame::Raised);
        line = new QFrame(VisualDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 20, 651, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        GraphicFrame->raise();
        layoutWidget->raise();
        line->raise();

        retranslateUi(VisualDialog);
        QObject::connect(saveButton, SIGNAL(clicked()), VisualDialog, SLOT(accept()));
        QObject::connect(clearButton, SIGNAL(clicked()), VisualDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VisualDialog);
    } // setupUi

    void retranslateUi(QDialog *VisualDialog)
    {
        VisualDialog->setWindowTitle(QApplication::translate("VisualDialog", "Dialog", Q_NULLPTR));
        saveButton->setText(QApplication::translate("VisualDialog", "Save", Q_NULLPTR));
        clearButton->setText(QApplication::translate("VisualDialog", "Clear", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VisualDialog: public Ui_VisualDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VISUALWINDOWHP8796_H
