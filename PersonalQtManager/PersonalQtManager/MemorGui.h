#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include "ui_MemorGui.h"

class MemorGui : public QWidget
{
	Q_OBJECT

public:
	MemorGui(QWidget *parent = Q_NULLPTR);
	~MemorGui();
public slots:
	   void searchButtonClickEvent();
	   void addButtonClickEvent();
	   void inputFinishClickEvent();
	   void inputCancelClickEvent();
private:
	Ui::MemorGui ui;
};
