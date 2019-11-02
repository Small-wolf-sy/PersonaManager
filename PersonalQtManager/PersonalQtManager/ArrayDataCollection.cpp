#include "ArrayDataCollection.h"
template<typename T>
//一维数组插入数据
bool ArrayData<T>::insert(int x, int y, int num)
{
	if (_data.size() >= y)
	{
		_data.insert(_data.begin() + y, num);
		return true;
	}
	return false;
}
//一维数组删除数据
template<typename T>
bool ArrayData<T>::removeAt(int x, int y)
{
	if (_data.size() >= y)
	{
		_data.erase(_data.begin() + y);
		return true;
	}
	return false;
}
//多维数组插入数据
template<typename T>
bool ArrayDataCollections<T>::insert(int x, int y, int num)
{
	if (_data.size() >= x)
	{
		return _data[x].insert(0,y, num);
	}
	else
	{
		return false;
	}

}
//多维数组删除数据
template<typename T>
bool ArrayDataCollections<T>::removeAt(int x, int y)
{
	if (_data.size() >= x)
	{
		return _data[x].removeAt(0,y, num);
	}
	else
	{
		return false;
	}
}
//重写返回个数
template<typename T>
int ArrayDataCollections<T>::count()
{
	int temp = 0;
	for (int i = 0; i < _data.size(); i++)
	{
		temp += _data[i].count();
	}
}
//多维数组返回特定行的数组
template<typename T>
int ArrayDataCollections<T>::DIM_Y(int x)
{
	if (_data.size() >= x)
	{
		//返回特定行的个数
		ArrayData<T> ad = _data[x];
		return ad.count();
	}
	else
	{
		return -1;
	}
}