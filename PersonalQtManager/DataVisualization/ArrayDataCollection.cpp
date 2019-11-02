#include "ArrayDataCollection.h"
template<typename T>
//һά�����������
bool ArrayData<T>::insert(int x, int y, int num)
{
	if (_data.size() >= y)
	{
		_data.insert(_data.begin() + y, num);
		return true;
	}
	return false;
}
//һά����ɾ������
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
//��ά�����������
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
//��ά����ɾ������
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
//��д���ظ���
template<typename T>
int ArrayDataCollections<T>::count()
{
	int temp = 0;
	for (int i = 0; i < _data.size(); i++)
	{
		temp += _data[i].count();
	}
}
//��ά���鷵���ض��е�����
template<typename T>
int ArrayDataCollections<T>::DIM_Y(int x)
{
	if (_data.size() >= x)
	{
		//�����ض��еĸ���
		ArrayData<T> ad = _data[x];
		return ad.count();
	}
	else
	{
		return -1;
	}
}