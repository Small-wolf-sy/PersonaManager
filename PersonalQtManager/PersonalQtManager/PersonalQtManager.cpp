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
	//各种显示效果的线程启动
	ThreadStart();
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
}
//子窗口关闭事件
void PersonalQtManager::ChildQwidgeEvent()
{
	//重置窗口,确保再次开启时不会出问题
	this->memoryui->destroyed();
	this->memoryui = NULL;//重新指向空指针，确保后续不会发生地址错误
}

void PersonalQtManager::ThreadStart()
{
	mt->SetLabel(ui.timeLabel);
	mt->start();//启动线程
	//隐藏CPUlabel，暂时不需要上线这个功能
	//ui.CPULabel->setAttribute(Qt::WA_TranslucentBackground);
	ui.CPULabel->setText("");
	ui.CPULabel->setEnabled(false);
	//mc->SetLabel(ui.CPULabel);
	//mc->start();
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
		//确保不会重复打开，如果缩小化使其正常显示
		this->memoryui->showNormal();
	}
}

//窗口关闭
void PersonalQtManager::closeEvent(QCloseEvent * event)
{
	//停止线程，避免窗口关闭时线程仍然在执行
	mt->quit();
	//mc->quit();
	event->accept();
}

void PersonalQtManager::ClickEventFilter(QWidget* w)
{
	//获取按钮
	QPushButton* button = qobject_cast<QPushButton*>(w); 
	if (NULL != button) 
	{
		//检测到是记事本按钮
		if (button->text()=="memorandum")
		{
			MemoryButtonEvent();
		}
		//QMessageBox::warning(NULL, tr("title"), tr("cancel"));
	}
}