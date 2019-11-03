#pragma once
#include <vector>
class DataBase {
	//不能用private，不然派生类无法修改,但很奇怪生成时没有报错，在其他测试程序中报错了
protected:
	int dim_x = 1;
	int dim_y = 1;
	//仅允许派生类调用，但在外部的main里无法调用
public:
	//返回元素的个数
	virtual int DIM_X() { return dim_x; };
	virtual int DIM_Y() { return dim_y; };
	virtual int count() { return dim_x*dim_y; }
	//操作函数,虚函数，需要自生成
	virtual bool insert(int x, int y, int num) { return false; };
	virtual bool removeAt(int x, int y) { return false; };
	virtual ~DataBase() {};
};
//用于存储1*N维数组
//typename T可为string，int，double等
template<typename T>
class ArrayData :public DataBase {
private:
	std::vector<T> _data;
public:
	//构造函数
	template<typename T>
	ArrayData(std::vector<T> t)
	{
		_data = t;
		dim_x = 1;
		dim_y = t.size();
	}
	//对于该类，恒定为1*n的数组，往in_y位置插入num
	bool insert(int x, int y, int num)override
	{
		if (_data.size() >= y)
		{
			_data.insert(_data.begin() + y, num);
			return true;
		}
		return false;
	}
	//对于该类，恒定为1*n的数组，移除in_y位置的数，默认移除最后一个
	bool removeAt(int x = 0, int y = _data.size() - 1)override
	{
		if (_data.size() >= y)
		{
			_data.erase(_data.begin() + y);
			return true;
		}
		return false;
	}
	//提取内部数据
	template<typename T>
	std::vector<T> getContent()
	{
		return _data;
	}
	~ArrayData() {}
};
//最高一级的数据，存储多维数组，实现所有数据的存储
//理论上为M*N*K维数组
template<typename T>
class ArrayDataCollections :public DataBase {
private:
	std::vector<ArrayData<T>> _data;
public:
	//构造函数
	ArrayDataCollections(std::vector<ArrayData<T>> datacollect)
	{
		_data = datacollect;
		dim_x = datacollect.size();
		dim_x = datacollect[0].count();//默认第一行
	}
	ArrayDataCollections(ArrayData<T> datacollect)
	{
		_data.push_back(datacollect);
	};
	//对于该类，恒定为1*n的数组，往in_y位置插入num
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
	//对于该类，恒定为1*n的数组，移除in_y位置的数,默认移除第一行最后一个
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
	//返回所有元素个数
	int count()override
	{
		int temp = 0;
		for (int i = 0; i < _data.size(); i++)
		{
			temp += _data[i].count();
		}
	}
	//重写返回列数，因为不同行的列不同，默认返回第一行
	int DIM_Y(int index = 0)override
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
	//提取内部数据
	template<typename T>
	std::vector<T> getContent()
	{
		return _data;
	}
	~ArrayDataCollections() {}
};
