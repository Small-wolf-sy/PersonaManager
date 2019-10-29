#include "PersonalQtManager.h"
#include <qsignalmapper.h>
using namespace std;
PersonalQtManager::PersonalQtManager(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("ManageSystem");
	QImage image;
	image.load("jpg/role.jpg");
	QPixmap pix;
	//时间的实时显示
	MyTimeThread *mt =new MyTimeThread(ui.timeLabel);
	//ui.timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
	mt->start();//启动线程
	//label位于frame内时，label的定位是内部坐标系
	ui.RolePicLabel->setGeometry(QRect(0, 0, ui.mainRoleFrame->width(), ui.mainRoleFrame->height()));
	ui.RolePicLabel->setPixmap(pix.fromImage(image));
	ui.RolePicLabel->setScaledContents(true);
	ui.RolePicLabel->show();
	//绑定事件
	//建立多套印射
	QSignalMapper *mSignalMapper = new QSignalMapper(this);
	connect(mSignalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(ClickEventFilter(QWidget*)));
	mSignalMapper->setMapping(ui.memorButton,ui.memorButton);
	connect(ui.memorButton, SIGNAL(clicked()), mSignalMapper, SLOT(map()));
	//建立窗体之间的传递
	//MemorGui *dlg = new MemorGui();
	//connect(this->memoryui, SIGNAL(closedSignals()), this, SLOT(ChildQwidgeEvent()));
	//connect(ui.memorButton, SIGNAL(clicked()), this, SLOT(MemoryButtonEvent()));
}
//子窗口关闭事件
void PersonalQtManager::ChildQwidgeEvent()
{
	//重置窗口,确保再次开启时不会出问题
	this->memoryui->destroyed();
	this->memoryui = NULL;
}

//记录功能激活事件
void PersonalQtManager::MemoryButtonEvent()
{
	if (this->memoryui == NULL)
	{
		//新建弹窗
		MemorGui *memoryui = new MemorGui();
		//窗体关闭时自动销毁内存
		memoryui->setAttribute(Qt::WA_DeleteOnClose, true);
		memoryui->show();
		this->memoryui = memoryui;
		connect(this->memoryui, SIGNAL(closedSignals()), this, SLOT(ChildQwidgeEvent()));
	}
	else
	{
		//不要重复点
		this->memoryui->showNormal();
	}
}

void PersonalQtManager::ClickEventFilter(QWidget* w)
{
	//获取按钮
	QPushButton* button = qobject_cast<QPushButton*>(w); 
	if (NULL != button) 
	{
		if (button->text()=="memorandum")
		{
			MemoryButtonEvent();
		}
		//QMessageBox::warning(NULL, tr("title"), tr("cancel"));
	}
}