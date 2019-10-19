#include "PersonalQtManager.h"
#include <string>
using namespace std;
PersonalQtManager::PersonalQtManager(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("ManageSystem");
	QImage image;
	image.load("jpg/role.jpg");
	QPixmap pix;
	//labelλ��frame��ʱ��label�Ķ�λ���ڲ�����ϵ
	ui.RolePicLabel->setGeometry(QRect(0, 0, ui.mainRoleFrame->width(), ui.mainRoleFrame->height()));
	ui.RolePicLabel->setPixmap(pix.fromImage(image));
	ui.RolePicLabel->setScaledContents(true);
	ui.RolePicLabel->show();
	//���¼�
	connect(ui.memorButton, SIGNAL(clicked()), this, SLOT(MemoryButtonEvent()));
}
//��¼���ܼ����¼�
void PersonalQtManager::MemoryButtonEvent()
{
	//�½�����
	MemorGui *memoryui=new MemorGui();
	memoryui->show();
}
