#include "PersonalQtManager.h"
#include <QtWidgets/QApplication>
#include "memoryData.h"
#include <array>
using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PersonalQtManager w;
	//�ر�ʱ�Զ������ڴ�
	//w.setAttribute(Qt::WA_DeleteOnClose, true);
	a.setAttribute(Qt::AA_EnableHighDpiScaling);
	w.show();
	return a.exec();
}
