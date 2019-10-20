#include "memoryData.h"

//构造函数
memoryData::memoryData()
{
}
memoryData::memoryData(vector<int> date)
{
	_date = date;
}
memoryData::memoryData(vector<int>date,string key)
{
	_date = date;
	key_words = key;
}
memoryData::memoryData(vector<int>date,string key,string description)
{
	_date = date;
	key_words = key;
	detailsDescript = description;
}
memoryData::~memoryData()
{
}
//设置日期
void memoryData::SetDate(vector<int> input_vec)
{
	//此时自动创建了新的，即使在调用函数界面修改了input_vec，_date并不会改变
	_date = input_vec;
}
//获取时期
vector<int> memoryData::GetDate()
{
	return _date;
}
//设置关键词
void memoryData::SetKey(string input_words)
{
	this->key_words = input_words;
}
//获取关键词
string memoryData::GetKey()
{
	return this->key_words;
}
//设置备忘录内容
void memoryData::SetDetails(string input_details)
{
	this->detailsDescript = input_details;
}
//获取备忘录内容
string memoryData::GetDetails()
{
	return this->detailsDescript;
}
