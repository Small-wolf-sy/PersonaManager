#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PersonalQtManager.h"
#include "MemorGui.h"
#include "MyThread.h"

class PersonalQtManager : public QMainWindow
{
	Q_OBJECT

public:
	PersonalQtManager(QWidget *parent = Q_NULLPTR);
	public slots:
	void MemoryButtonEvent();
	//signals:
	//void timeShow();
private:
	Ui::PersonalQtManagerClass ui;
	Ui::MemorGui memoryui;
};
