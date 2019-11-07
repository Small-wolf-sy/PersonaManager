#pragma once
#include <string>
//#include <msxml.h>
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;
class XMLOperator
{
public:
	bool WriteLocalStorage();//往本地文件写记录
	bool ReadLocalStorage();//往本地文件读记录
	void XMLInitialLocalStorage(std::string path="E:\\");//初始化本地文件
	XMLOperator();
	~XMLOperator();
};

