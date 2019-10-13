#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PersonalQtManager.h"

class PersonalQtManager : public QMainWindow
{
	Q_OBJECT

public:
	PersonalQtManager(QWidget *parent = Q_NULLPTR);

private:
	Ui::PersonalQtManagerClass ui;
};
