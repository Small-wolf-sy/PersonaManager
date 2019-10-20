#pragma once
//���������ǿ��Ա���ͨ���ģ������Ǳ���
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
	//�����д����������
public slots:
	   void searchButtonClickEvent();
	   void addButtonClickEvent();
	   void inputFinishClickEvent();
	   void inputCancelClickEvent();
	   
private:
	Ui::MemorGui ui;
};
