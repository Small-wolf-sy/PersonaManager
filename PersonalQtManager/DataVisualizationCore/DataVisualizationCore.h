#pragma once

#include "datavisualizationcore_global.h"
#include "ArrayDataCollection.h"
#include "DataVisualWindow.h"
#include <vector>
class DATAVISUALIZATIONCORE_TEMPLATE DataVisualizationCore
{
private:
	ArrayData<double> *_resourcedata;
	DataVisualWindow *mainWindow;
public:
	
	DataVisualizationCore();
	DataVisualizationCore(int num,ArrayData<double>&ad)
	{
		_resourcedata = new ArrayData<double>(ad.getContent<double>());
		_num = num;
		//�����������ʾ
		mainWindow = new DataVisualWindow();
		//mainWindow->show();
	};
	int _num;
	void StartWindow();
};
