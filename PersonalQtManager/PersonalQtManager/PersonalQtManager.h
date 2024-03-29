#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PersonalQtManager.h"
#include "MemorGui.h"
#include "MyThread.h"
//#include "VisualDialog.h"

class PersonalQtManager : public QMainWindow
{
	Q_OBJECT

public:
	PersonalQtManager(QWidget *parent = Q_NULLPTR);
	void closeEvent(QCloseEvent *event);//重写关闭事件
	public slots:
	void MemoryButtonEvent();
	void DataVisualEvent();
	void ClickEventFilter(QWidget*);//未来针对按钮事件，统一用这个来筛选具体的按钮事件，而不是每一个都需要写一遍
private:
	void ThreadStart();
	Ui::PersonalQtManagerClass ui;
	MemorGui *memoryui = NULL;
	MyTimeThread *mt=new MyTimeThread();
	MyCPUThread *mc = new MyCPUThread();
	private slots:
	void ChildQwidgeEvent();
};
