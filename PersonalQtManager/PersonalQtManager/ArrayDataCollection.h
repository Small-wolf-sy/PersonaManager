#pragma once
#include <vector>
class DataBase {
//不能用private，不然派生类无法修改,但很奇怪生成时没有报错，在其他测试程序中报错了
protected:
	int dim_x=1;
	int dim_y=1;
	//仅允许派生类调用，但在外部的main里无法调用
public:
	//返回元素的个数
	virtual int DIM_X() { return dim_x; };
	virtual int DIM_Y() { return dim_y; };
	virtual int count() { return dim_x*dim_y; }
	//操作函数,虚函数，需要自生成
	virtual bool insert(int x, int y,int num) = 0;
	virtual bool removeAt(int x , int y) = 0;
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
	bool insert(int x, int y, int num);
	//对于该类，恒定为1*n的数组，移除in_y位置的数，默认移除最后一个
	bool removeAt(int x=0, int y=_data.size()-1);
	~ArrayData() {}
};
//最高一级的数据，存储多维数组，实现所有数据的存储
//理论上为M*N*K维数组
template<typename T>
class ArrayDataCollections:public DataBase {
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
	bool insert(int x, int y, int num);
	//对于该类，恒定为1*n的数组，移除in_y位置的数,默认移除第一行最后一个
	bool removeAt(int x=0, int y = _data.size() - 1);
	//重写个数
	int count()override;
	//重写返回列数，因为不同行的列不同，默认返回第一行
	int DIM_Y(int index=0)override;
	~ArrayDataCollections(){}
};
