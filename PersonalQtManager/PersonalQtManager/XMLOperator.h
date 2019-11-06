#pragma once
class XMLOperator
{
public:
	bool WriteLocalStorage();//往本地文件写记录
	bool ReadLocalStorage();//往本地文件读记录
	XMLOperator();
	~XMLOperator();
};

