#include "memoryData.h"

//构造函数
memoryData::memoryData(string keywords, string recordtime)
{
	key_words = keywords;
	_recordtime = recordtime;
}
memoryData::memoryData(string keywords, string recordtime,vector<int> deadline)
{
	key_words = keywords;
	_recordtime = recordtime;
	_deadline = deadline;
}

memoryData::memoryData(string keywords, string recordtime, vector<int> deadline,string description)
{
	key_words = keywords;
	_recordtime = recordtime;
	_deadline = deadline;
	detailsDescript = description;
}
memoryData::~memoryData()
{
}
//设置截止时间
void memoryData::SetDeadLine(vector<int> input_vec)
{
	//此时自动创建了新的，即使在调用函数界面修改了input_vec，_deadline并不会改变
	_deadline = input_vec;
}
//设置截止时间
vector<int> memoryData::GetDeadLine()
{
	return _deadline;
}
//获取记录时间，无法修改
string memoryData::GetRecord()
{
	return this->_recordtime;
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
