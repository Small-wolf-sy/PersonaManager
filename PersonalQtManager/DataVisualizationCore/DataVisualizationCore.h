#pragma once

#include "datavisualizationcore_global.h"
#include "ArrayDataCollection.h"
#include <vector>
class DATAVISUALIZATIONCORE_TEMPLATE DataVisualizationCore
{
private:
	ArrayData<double> *_resourcedata;
public:
	DataVisualizationCore();
	DataVisualizationCore(int num,ArrayData<double>&ad)
	{
		_resourcedata = new ArrayData<double>(ad.getContent<double>());
		_num = num;
	};

	int _num;
};
