#pragma once

#include <QWidget>
#include "ui_MemorGui.h"

class MemorGui : public QWidget
{
	Q_OBJECT

public:
	MemorGui(QWidget *parent = Q_NULLPTR);
	~MemorGui();
private:
	Ui::MemorGui ui;
};
