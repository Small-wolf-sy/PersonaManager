#pragma once
#include <string>
//#include <msxml.h>
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;
class XMLOperator
{
public:
	bool WriteLocalStorage();//�������ļ�д��¼
	bool ReadLocalStorage();//�������ļ�����¼
	void XMLInitialLocalStorage(std::string path="E:\\");//��ʼ�������ļ�
	XMLOperator();
	~XMLOperator();
};

