#pragma once
//���������ǿ��Ա���ͨ���ģ������Ǳ���
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
	//����״̬
	abilityType Memory_state = abilityType::none_Activated;
	void ClearContext();
	void SetMemEabled();
	void SetMemDiseabled();
	void SetSearchAddEnabled();
	void closeEvent(QCloseEvent *event);//��д�ر��¼�
	//�����д����������
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
	void AddActivated();//ִ����Ӳ���������
	void SearchActivated();//ִ����������������
};
