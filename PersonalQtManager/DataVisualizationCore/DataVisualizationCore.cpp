#include "stdafx.h"
#include "DataVisualizationCore.h"
//template<typename T>
//DataVisualizationCore<T>::DataVisualizationCore()
//{
//	num = 4;
//}
DataVisualizationCore::DataVisualizationCore()
{
	std::vector<double> data = { 1,2,3,4,5,6 };
	_resourcedata = new ArrayData<double>(data);
	_num = 4;
	mainWindow = new DataVisualWindow();
}
//显示主界面
void DataVisualizationCore::StartWindow()
{
	this->mainWindow->show();
}
