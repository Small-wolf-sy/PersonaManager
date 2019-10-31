#pragma once
//明明程序是可以编译通过的，但就是报错
#include <QWidget>
#include <qmessagebox.h>
#include "ui_MemorGui.h"

class MemorGui : public QWidget
{
	Q_OBJECT

public:
	MemorGui(QWidget *parent = Q_NULLPTR);
	~MemorGui();
	void ClearContext();
	void SetMemEabled();
	void SetMemDiseabled();
	void closeEvent(QCloseEvent *event);//重写关闭事件
	//清空填写的所有内容
	signals:
	void closedSignals();
	public slots:
	   void searchButtonClickEvent();
	   void addButtonClickEvent();
	   void inputFinishClickEvent();
	   void inputCancelClickEvent();  
private:
	Ui::MemorGui ui;
};
