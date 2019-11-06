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
