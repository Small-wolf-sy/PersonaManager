#include "stdafx.h"
#include "DataVisualWindow.h"
#include <qmessagebox.h>
DataVisualWindow::DataVisualWindow(QMainWindow *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("DataVisualSysteam");
	QImage image;
	image.load("jpg/role.jpg");
	QPixmap pix;
	//label位于frame内时，label的定位是内部坐标系
	ui.mainPicLabel->setGeometry(QRect(0, 0, ui.mainFrame->width(), ui.mainFrame->height()));
	ui.mainPicLabel->setPixmap(pix.fromImage(image));
	ui.mainPicLabel->setScaledContents(true);
	ui.mainPicLabel->show();
	connect(ui.checkbuttonbox, SIGNAL(accepted()), this, SLOT(saveButtonClickEvent()));
	connect(ui.checkbuttonbox, SIGNAL(rejected()), this, SLOT(clearButtonClickEvent()));
}
DataVisualWindow::~DataVisualWindow()
{
}

void DataVisualWindow::saveButtonClickEvent()
{
	QMessageBox::warning(NULL, tr("title"), tr("OK"));
}

void DataVisualWindow::clearButtonClickEvent()
{
}
