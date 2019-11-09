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
	////labelλ��frame��ʱ��label�Ķ�λ���ڲ�����ϵ
	//ui.mainPicLabel->setGeometry(QRect(0, 0, ui.mainFrame->width(), ui.mainFrame->height()));
	//ui.mainPicLabel->setPixmap(pix.fromImage(image));
	//ui.mainPicLabel->setScaledContents(true);
	//ui.mainPicLabel->show();
	//��һ����ʽ��ʾ
	QGraphicsScene *scene = new QGraphicsScene;
	//scene->setSceneRect(QRect(0, 0, ui.mainFrame->width(), ui.mainFrame->height()));
	scene->addPixmap(pix.fromImage(image));
	//ui.mainGraphicView->setScene(scene);
	connect(ui.checkbuttonbox, SIGNAL(accepted()), this, SLOT(saveButtonClickEvent()));
	connect(ui.checkbuttonbox, SIGNAL(rejected()), this, SLOT(clearButtonClickEvent()));
	connect(ui.exampleButton, SIGNAL(clicked()), this, SLOT(exampleClickEvent()));
}
DataVisualWindow::~DataVisualWindow()
{
}

void DataVisualWindow::saveButtonClickEvent()
{
	QImage pixmap(ui.mainGraphicView->size(), QImage::Format_RGB32);
	QPainter qpainter(&pixmap);
	qpainter.setRenderHint(QPainter::Antialiasing);
	ui.mainGraphicView->render(&qpainter);
	qpainter.end();
	pixmap.save("E:\\test.jpg");
}

void DataVisualWindow::clearButtonClickEvent()
{
	//���mainGraphicView�����ڵ�����Ԫ��
	QLayoutItem *child;
	while ((child = ui.mainGraphicView->layout()->takeAt(0)) != 0)
	{
		//setParentΪNULL����ֹɾ��֮����治��ʧ,��Ȼɾ���˻��ƵĽ��滹��
		if (child->widget())
		{
			child->widget()->setParent(NULL);
		}
		delete child;
	}
}
//����Ч��ͼ
void DataVisualWindow::exampleClickEvent()
{
	QBarSet *exper1 = new QBarSet("The length of tool path");
	exper1->setLabelColor(QColor(0, 0, 0));
	QBarSet *exper2 = new QBarSet("Processing time");
	exper2->setLabelColor(QColor(96, 0, 0));
	*exper1 << 12448.5 << 974.401 << 985.913;
	*exper2 << 1220.4<< 974.401 << 215.4;

	QBarSeries *series = new QBarSeries();
	series->setLabelsVisible(true);
	series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
	series->append(exper1);
	series->append(exper2);

	QChart *chart = new QChart();
	chart->addSeries(series);   //������״ͼ
	chart->setTitle("The compare of experiment result");
	chart->setAnimationOptions(QChart::SeriesAnimations);

	//X���±�
	QStringList categories;
	categories << "Experiment NO.1" << "Experiment NO.2" << "Experiment NO.3";
	QBarCategoryAxis *axisX = new QBarCategoryAxis();
	axisX->append(categories);
	chart->setAxisX(axisX, series);

	//Y�����÷�Χ
	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 13000);
	chart->setAxisY(axisY, series);

	////ͼ��
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	QFont font;
	font.setPointSize(25);
	font.setPixelSize(40);
	chart->setFont(font);

	//�Ῠ��
	//chart->zoomIn(ui.mainGraphicView->geometry());

	//��ʾЧ��ͼ�ķ�����Ŀǰ�ҵ���Ψһ���õ�һ�֣�Widget�Ѿ�ʧ��
	QChartView *chartView = new QChartView(chart);//����QChartView ������ʵ��������chart
	QGridLayout *baseLayout = new QGridLayout(); //������ʾ���������񲼾�
	chartView->setFont(font);
	baseLayout->addWidget(chartView, 1, 0);
	chartView->setAutoFillBackground(true);

	QSize cs=chartView->size();
	QSizeF cst = chart->size();
	/*QPixmap pixmap(chartView->size(), QImage::Format_RGB32);*/
	//���ͼ�chart�����ر�С
	QPixmap pixmap(640,480);
	QPainter qpainter(&pixmap);
	qpainter.setRenderHint(QPainter::Antialiasing);
	chartView->render(&qpainter);
	qpainter.end();
	pixmap.save("E:\\test.jpg");

	ui.mainGraphicView->setAutoFillBackground(true);
	ui.mainGraphicView->setLayout(baseLayout);
}

/*
//��ʾ����Ч��
void DataVisualWindow::exampleClickEvent()
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

//��5�����ݼ�������״ͼ������
QBarSeries *series = new QBarSeries();
series->setLabelsVisible(true);
series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
series->append(set0);
series->append(set1);
series->append(set2);
series->append(set3);
series->append(set4);

////����һ��ͼ�����ע�⣬����ʵ��QGraphicsWidget������
QChart *chart = new QChart();
chart->addSeries(series);   //������״ͼ
chart->setTitle("Simple barchart example");
chart->setAnimationOptions(QChart::SeriesAnimations);

//X���±�
QStringList categories;
categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
QBarCategoryAxis *axisX = new QBarCategoryAxis();
axisX->append(categories);
chart->setAxisX(axisX, series);

//Y�����÷�Χ
QValueAxis * axisY = new QValueAxis();
axisY->setRange(0, 20);
chart->setAxisY(axisY, series);

////ͼ��
chart->legend()->setVisible(true);
chart->legend()->setAlignment(Qt::AlignBottom);
//��ʾЧ��ͼ�ķ�����Ŀǰ�ҵ���Ψһ���õ�һ�֣�Widget�Ѿ�ʧ��
QChartView *chartView = new QChartView(chart);//����QChartView ������ʵ��������chart
QGridLayout *baseLayout = new QGridLayout(); //������ʾ���������񲼾�
baseLayout->addWidget(chartView, 1, 0);
ui.mainGraphicView->setAutoFillBackground(true);
ui.mainGraphicView->setLayout(baseLayout);
}
*/

