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
	bool SearchLocalStorage();//�������ļ�����¼��������
	bool StorageCheck();//����Ƿ���ڱ����ļ����粻���ڣ��򴴽�
	XMLOperator(string path = "E:\\local_storage.xml");//����Ĭ�ϴ洢λ��
	void SetLocalFile(string path);
	~XMLOperator();
private:
	void XMLInitialLocalStorage(std::string path = "E:\\");//��ʼ�������ļ�
	string _localfile;
};

