#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;
//该类用于存储MemoryUI中的每一个事件
class memoryData
{
public:
	memoryData(string, string);//已知关键词与记录时间
	memoryData(string, string, vector<int>);//关键词、记录时间、截止时间
	memoryData(string, string, vector<int>,string);//关键词、记录时间、截止时间、详细说明
	~memoryData();
	//设置日期,利用template，从而确定数组长度
	void SetDeadLine(vector<int> input_vec=vector<int>(0,3));
	//采用int*容易造成浪费，因此采用该种方式
	vector<int> GetDeadLine();
	//设置关键词
	void SetKey(string input_words = "default");
	string GetKey();
	//设置备忘信息
	void SetDetails(string input_details = "null");
	string GetDetails();
	string GetRecord();
private:
	vector<int> _deadline;//截止日期
	string _recordtime;//记录日期
	string key_words;//搜索关键词
	string detailsDescript;//详细内容
};

