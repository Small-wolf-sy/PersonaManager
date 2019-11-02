#pragma once
#include <vector>
class DataBase {
//������private����Ȼ�������޷��޸�,�����������ʱû�б������������Գ����б�����
protected:
	int dim_x=1;
	int dim_y=1;
	//��������������ã������ⲿ��main���޷�����
public:
	//����Ԫ�صĸ���
	virtual int DIM_X() { return dim_x; };
	virtual int DIM_Y() { return dim_y; };
	virtual int count() { return dim_x*dim_y; }
	//��������,�麯������Ҫ������
	virtual bool insert(int x, int y,int num) = 0;
	virtual bool removeAt(int x , int y) = 0;
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
	bool insert(int x, int y, int num);
	//���ڸ��࣬�㶨Ϊ1*n�����飬�Ƴ�in_yλ�õ�����Ĭ���Ƴ����һ��
	bool removeAt(int x=0, int y=_data.size()-1);
	~ArrayData() {}
};
//���һ�������ݣ��洢��ά���飬ʵ���������ݵĴ洢
//������ΪM*N*Kά����
template<typename T>
class ArrayDataCollections:public DataBase {
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
	bool insert(int x, int y, int num);
	//���ڸ��࣬�㶨Ϊ1*n�����飬�Ƴ�in_yλ�õ���,Ĭ���Ƴ���һ�����һ��
	bool removeAt(int x=0, int y = _data.size() - 1);
	//��д����
	int count()override;
	//��д������������Ϊ��ͬ�е��в�ͬ��Ĭ�Ϸ��ص�һ��
	int DIM_Y(int index=0)override;
	~ArrayDataCollections(){}
};
