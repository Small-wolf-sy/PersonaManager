#include "PersonalQtManager.h"
#include <QtWidgets/QApplication>
#include <memoryData.h>
#include <array>
using namespace std;
int main(int argc, char *argv[])
{
	//memoryData md;
	//vector<int> arr = {  1,3,5,7,9  };
	//md.SetDate(arr);
	//vector<int>test = md.GetDate();
	//return 0;
	QApplication a(argc, argv);
	PersonalQtManager w;
	w.show();
	return a.exec();
}
