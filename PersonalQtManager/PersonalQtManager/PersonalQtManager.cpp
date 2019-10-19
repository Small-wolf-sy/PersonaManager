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
	//label位于frame内时，label的定位是内部坐标系
	ui.RolePicLabel->setGeometry(QRect(0, 0, ui.mainRoleFrame->width(), ui.mainRoleFrame->height()));
	ui.RolePicLabel->setPixmap(pix.fromImage(image));
	ui.RolePicLabel->setScaledContents(true);
	ui.RolePicLabel->show();
	//绑定事件
	connect(ui.memorButton, SIGNAL(clicked()), this, SLOT(MemoryButtonEvent()));
}
//记录功能激活事件
void PersonalQtManager::MemoryButtonEvent()
{
	//新建弹窗
	MemorGui *memoryui=new MemorGui();
	memoryui->show();
}
