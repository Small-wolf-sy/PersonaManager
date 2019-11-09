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
	bool SearchLocalStorage();//往本地文件读记录进行搜索
	bool StorageCheck();//检测是否存在本地文件，如不存在，则创建
	XMLOperator(string path = "E:\\local_storage.xml");//设置默认存储位置
	void SetLocalFile(string path);
	~XMLOperator();
private:
	void XMLInitialLocalStorage(std::string path = "E:\\");//初始化本地文件
	string _localfile;
};

