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
	void closeEvent(QCloseEvent *event);//��д�ر��¼�
	public slots:
	void MemoryButtonEvent();
	void ClickEventFilter(QWidget*);//δ����԰�ť�¼���ͳһ�������ɸѡ����İ�ť�¼���������ÿһ������Ҫдһ��
private:
	void ThreadStart();
	Ui::PersonalQtManagerClass ui;
	MemorGui *memoryui = NULL;
	MyTimeThread *mt=new MyTimeThread();
	MyCPUThread *mc = new MyCPUThread();
	private slots:
	void ChildQwidgeEvent();
};
