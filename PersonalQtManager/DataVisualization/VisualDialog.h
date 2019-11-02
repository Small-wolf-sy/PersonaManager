#pragma once
//#include <QWidget>
#include "datavisualization_global.h"
#include "ui_VisualWindow.h"
#include "ArrayDataCollection.h"
class VisualDialog : public QWidget
{
	Q_OBJECT

public:
	VisualDialog(QWidget *parent = Q_NULLPTR);
	~VisualDialog();
signals:
	void closedSignals();
	public slots:
	//void searchButtonClickEvent();
	//void addButtonClickEvent();
	//void inputFinishClickEvent();
	//void inputCancelClickEvent();
private:
	Ui::VisualDialog ui;
};
