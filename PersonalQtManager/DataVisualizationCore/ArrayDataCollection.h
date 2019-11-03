#pragma once
#include <vector>
class DataBase {
	//������private����Ȼ�������޷��޸�,�����������ʱû�б������������Գ����б�����
protected:
	int dim_x = 1;
	int dim_y = 1;
	//��������������ã������ⲿ��main���޷�����
public:
	//����Ԫ�صĸ���
	virtual int DIM_X() { return dim_x; };
	virtual int DIM_Y() { return dim_y; };
	virtual int count() { return dim_x*dim_y; }
	//��������,�麯������Ҫ������
	virtual bool insert(int x, int y, int num) { return false; };
	virtual bool removeAt(int x, int y) { return false; };
	virtual ~DataBase() {};
};
//���ڴ洢1*Nά����
//typename T��Ϊstring��int��double��
template<typename T>
class ArrayData :public DataBase {
private:
	std::vector<T> _data;
public:
	//���캯��
	template<typename T>
	ArrayData(std::vector<T> t)
	{
		_data = t;
		dim_x = 1;
		dim_y = t.size();
	}
	//���ڸ��࣬�㶨Ϊ1*n�����飬��in_yλ�ò���num
	bool insert(int x, int y, int num)override
	{
		if (_data.size() >= y)
		{
			_data.insert(_data.begin() + y, num);
			return true;
		}
		return false;
	}
	//���ڸ��࣬�㶨Ϊ1*n�����飬�Ƴ�in_yλ�õ�����Ĭ���Ƴ����һ��
	bool removeAt(int x = 0, int y = _data.size() - 1)override
	{
		if (_data.size() >= y)
		{
			_data.erase(_data.begin() + y);
			return true;
		}
		return false;
	}
	//��ȡ�ڲ�����
	template<typename T>
	std::vector<T> getContent()
	{
		return _data;
	}
	~ArrayData() {}
};
//���һ�������ݣ��洢��ά���飬ʵ���������ݵĴ洢
//������ΪM*N*Kά����
template<typename T>
class ArrayDataCollections :public DataBase {
private:
	std::vector<ArrayData<T>> _data;
public:
	//���캯��
	ArrayDataCollections(std::vector<ArrayData<T>> datacollect)
	{
		_data = datacollect;
		dim_x = datacollect.size();
		dim_x = datacollect[0].count();//Ĭ�ϵ�һ��
	}
	ArrayDataCollections(ArrayData<T> datacollect)
	{
		_data.push_back(datacollect);
	};
	//���ڸ��࣬�㶨Ϊ1*n�����飬��in_yλ�ò���num
	bool insert(int x, int y, int num)override
	{
		if (_data.size() >= x)
		{
			return _data[x].insert(0, y, num);
		}
		else
		{
			return false;
		}
	}
	//���ڸ��࣬�㶨Ϊ1*n�����飬�Ƴ�in_yλ�õ���,Ĭ���Ƴ���һ�����һ��
	bool removeAt(int x = 0, int y = _data.size() - 1)override
	{
		if (_data.size() >= x)
		{
			return _data[x].removeAt(0, y, num);
		}
		else
		{
			return false;
		}
	}
	//��������Ԫ�ظ���
	int count()override
	{
		int temp = 0;
		for (int i = 0; i < _data.size(); i++)
		{
			temp += _data[i].count();
		}
	}
	//��д������������Ϊ��ͬ�е��в�ͬ��Ĭ�Ϸ��ص�һ��
	int DIM_Y(int index = 0)override
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
	//��ȡ�ڲ�����
	template<typename T>
	std::vector<T> getContent()
	{
		return _data;
	}
	~ArrayDataCollections() {}
};
