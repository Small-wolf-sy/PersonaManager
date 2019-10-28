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
	//ʱ���ʵʱ��ʾ
	MyTimeThread *mt =new MyTimeThread(ui.timeLabel);
	//ui.timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
	mt->start();//�����߳�
	//labelλ��frame��ʱ��label�Ķ�λ���ڲ�����ϵ
	ui.RolePicLabel->setGeometry(QRect(0, 0, ui.mainRoleFrame->width(), ui.mainRoleFrame->height()));
	ui.RolePicLabel->setPixmap(pix.fromImage(image));
	ui.RolePicLabel->setScaledContents(true);
	ui.RolePicLabel->show();
	//���¼�
	//��������ӡ��
	QSignalMapper *mSignalMapper = new QSignalMapper(this);
	connect(mSignalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(ClickEventFilter(QWidget*)));
	mSignalMapper->setMapping(ui.memorButton,ui.memorButton);
	connect(ui.memorButton, SIGNAL(clicked()), mSignalMapper, SLOT(map()));
	//connect(ui.memorButton, SIGNAL(clicked()), this, SLOT(MemoryButtonEvent()));
}
//��¼���ܼ����¼�
void PersonalQtManager::MemoryButtonEvent()
{
	//�½�����
	MemorGui *memoryui=new MemorGui();
	//����ر�ʱ�Զ������ڴ�
	memoryui->setAttribute(Qt::WA_DeleteOnClose, true);
	memoryui->show();
}

void PersonalQtManager::ClickEventFilter(QWidget* w)
{
	//��ȡ��ť
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