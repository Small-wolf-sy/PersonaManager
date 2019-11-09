#pragma once
#include <string>
//#include <msxml.h>
#include "tinyxml2.h"
#include "memoryData.h"
using namespace tinyxml2;
using namespace std;
class XMLOperator
{
public:
	bool WriteLocalStorage(memoryData md);//�������ļ�д��¼
	memoryData SearchLocalStorage(string keyword);//�������ļ�����¼��������
	bool StorageCheck();//����Ƿ���ڱ����ļ����粻���ڣ��򴴽�
	XMLOperator(string path = "E:\\local_storage.xml");//����Ĭ�ϴ洢λ��
	void SetLocalFile(string path);
	~XMLOperator();
private:
	void XMLInitialLocalStorage(std::string path = "E:\\local_storage.xml");//��ʼ�������ļ�
	void XMLOperator::ConvertXML(memoryData &md, XMLElement *targetElement);
	string _localfile;
};

