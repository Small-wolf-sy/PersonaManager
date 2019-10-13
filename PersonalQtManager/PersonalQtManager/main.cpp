#include "PersonalQtManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PersonalQtManager w;
	w.show();
	return a.exec();
}
