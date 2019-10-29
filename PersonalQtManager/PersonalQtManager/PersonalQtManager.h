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
	void ClickEventFilter(QWidget*);//δ����԰�ť�¼���ͳһ�������ɸѡ����İ�ť�¼���������ÿһ������Ҫдһ��
private:
	Ui::PersonalQtManagerClass ui;
	MemorGui *memoryui = NULL;
	private slots:
	void ChildQwidgeEvent();

};
