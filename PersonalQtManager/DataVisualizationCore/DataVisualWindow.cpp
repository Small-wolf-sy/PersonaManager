#include "stdafx.h"
#include "DataVisualWindow.h"
#include <qmessagebox.h>
#include <QtCharts\qchart.h>
#include <QtCharts\qbarset.h>
#include <QtCharts\qbarseries.h>
#include <QtCharts\qbarcategoryaxis.h>
#include <QtCharts\qvalueaxis.h>
#include <QtCharts\qchartview.h>
#include <qgridlayout.h>
using namespace QtCharts;
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
	////QMessageBox::warning(NULL, tr("title"), tr("OK"));
	QBarSet *set0 = new QBarSet("Jane"); set0->setLabelColor(QColor(0, 0, 0));
	QBarSet *set1 = new QBarSet("John"); set1->setLabelColor(QColor(96, 0, 0));
	QBarSet *set2 = new QBarSet("Axel"); set2->setLabelColor(QColor(0, 96, 0));
	QBarSet *set3 = new QBarSet("Mary"); set3->setLabelColor(QColor(0, 0, 96));
	QBarSet *set4 = new QBarSet("Sama"); set4->setLabelColor(QColor(0, 96, 96));
	*set0 << 1 << 2 << 3 << 4 << 5 << 6;
	*set1 << 5 << 0 << 0 << 4 << 0 << 7;
	*set2 << 3 << 5 << 8 << 13 << 8 << 5;
	*set3 << 5 << 6 << 7 << 3 << 4 << 5;
	*set4 << 9 << 7 << 5 << 3 << 1 << 2;

	//把5个数据集放入柱状图主题里
	QBarSeries *series = new QBarSeries();
	series->setLabelsVisible(true);
	series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
	series->append(set0);
	series->append(set1);
	series->append(set2);
	series->append(set3);
	series->append(set4);

	////产生一个图标对象，注意，它其实是QGraphicsWidget的子类
	QChart *chart = new QChart();
	chart->addSeries(series);   //加入柱状图
	chart->setTitle("Simple barchart example");
	chart->setAnimationOptions(QChart::SeriesAnimations);

	//X轴下标
	QStringList categories;
	categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
	QBarCategoryAxis *axisX = new QBarCategoryAxis();
	axisX->append(categories);
	chart->setAxisX(axisX, series);

	//Y轴设置范围
	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 20);
	chart->setAxisY(axisY, series);

	////图例
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	//显示效果图的方法：目前找到的唯一能用的一种，Widget已经失败
	QChartView *chartView = new QChartView(chart);//声明QChartView 并创建实例，加载chart
	QGridLayout *baseLayout = new QGridLayout(); //便于显示，创建网格布局
	baseLayout->addWidget(chartView, 1, 0);
	ui.mainGraphicView->setLayout(baseLayout);
}

void DataVisualWindow::clearButtonClickEvent()
{
}
