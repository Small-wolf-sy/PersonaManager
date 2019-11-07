#pragma once
//明明程序是可以编译通过的，但就是报错
#include <QWidget>
#include <qmessagebox.h>
#include "ui_MemorGui.h"
#include "XMLOperator.h"
enum abilityType
{
	add_Activated,
	search_Activated,
	none_Activated
};
class MemorGui : public QWidget
{
	Q_OBJECT

public:
	MemorGui(QWidget *parent = Q_NULLPTR);
	~MemorGui();
	//设置状态
	abilityType Memory_state = abilityType::none_Activated;
	void ClearContext();
	void SetMemEabled();
	void SetMemDiseabled();
	void SetSearchAddEnabled();
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
	XMLOperator data_operator;
	void AddActivated();//执行添加操作并反馈
	void SearchActivated();//执行搜索操作并反馈
};
