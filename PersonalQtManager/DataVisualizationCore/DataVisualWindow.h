#pragma once
#include <QWidget>
#include "ui_DataVisualWindow.h"
class  DataVisualWindow :public QMainWindow
{
	Q_OBJECT

public:
	DataVisualWindow(QMainWindow *parent = Q_NULLPTR);
	~DataVisualWindow();
private:
	Ui::MainWindow ui;
	private slots:
	void saveButtonClickEvent();
	void clearButtonClickEvent();
};