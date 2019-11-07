#include "XMLOperator.h"
#include <time.h>
#include <fstream>
XMLOperator::XMLOperator(string path)
{
	_localfile = path;
}
//�޸Ĵ洢·��
void XMLOperator::SetLocalFile(string path)
{
	_localfile = path;
}

XMLOperator::~XMLOperator()
{
}

//TODO��дһ����XML��д��ص�����в���
//д��������
bool XMLOperator::WriteLocalStorage()
{
	return false;
}
//����������
bool XMLOperator::SearchLocalStorage()
{
	return false;
}

bool XMLOperator::StorageCheck()
{
	fstream _file;
	_file.open(_localfile, ios::in);
	if (!_file)
	{
		XMLInitialLocalStorage();
		return false;
	}
	else
	{
		return true;
	}
}

//��ʼ������ȷ��XML�ļ�
void XMLOperator::XMLInitialLocalStorage(string path)
{
	// �½�һ�����ĵ�����ʾ������xml��,Ϊ�˱�����msxml��ͻ����������tinyXMLDocument
	tinyxml2::TinyXMLDocument xmlDoc;

	// �½ڵ�
	XMLNode * pRoot = xmlDoc.NewElement("Default");

	// ���뵽xmlDoc�ĵ�һ���ڵ㣨���ڵ㣩
	xmlDoc.InsertFirstChild(pRoot);

	// �½�һ��Ԫ��
	XMLElement *pElement = xmlDoc.NewElement("CreateInformation");
	XMLElement *pnewElement = xmlDoc.NewElement("CreateTime");
	// ���ø�Ԫ�أ��ڵ㣩��ֵ
	pElement->SetText("LocalMemoryStorageCreated");
	//��ȡ����ʱ��
	time_t rawtime;
	time(&rawtime);
	struct tm *ptminfo;
	ptminfo = localtime(&rawtime);
	// ���ø�Ԫ�ص����ԣ�����)
	//��
	XMLElement *time_element = xmlDoc.NewElement("year");
	time_element->SetText(ptminfo->tm_year + 1900);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("month");
	time_element->SetText(ptminfo->tm_mon + 1);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("day");
	time_element->SetText(ptminfo->tm_mday);
	pnewElement->InsertEndChild(time_element);
	//����
	time_element = xmlDoc.NewElement("week");
	char* week;
	switch (ptminfo->tm_wday)
	{
	case 1:
		week = "Monday";
		break;
	case 2:
		week = "Tuesday";
		break;
	case 3:
		week = "Wednesday";
		break;
	case 4:
		week = "Thursday";
		break;
	case 5:
		week = "Friday";
		break;
	case 6:
		week = "Saturday";
		break;
	case 7:
		week = "Sunday";
		break;
	}
	time_element->SetText(week);
	pnewElement->InsertEndChild(time_element);
	//ʱ
	time_element = xmlDoc.NewElement("hour");
	time_element->SetText(ptminfo->tm_hour);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("min");
	time_element->SetText(ptminfo->tm_min);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("second");
	time_element->SetText(ptminfo->tm_sec);
	pnewElement->InsertEndChild(time_element);

	// ���ýڵ���ӵ�pRoot�ڵ���("Root")
	pElement->InsertEndChild(pnewElement);
	pRoot->InsertEndChild(pElement);

	// �����ļ�
	string xml_doc = "local_storage.xml";
	xml_doc = path + xml_doc;
	XMLError eResult = xmlDoc.SaveFile(xml_doc.data());

	//// ָ���µĽڵ�
	//pElement = xmlDoc.NewElement("FloatValue");

	//// ��ӵ�pRoot�ڵ㣨����������ӣ�
	//pRoot->InsertEndChild(pElement);

	//// �½�һ���ڵ�
	//XMLElement *pNewElement = xmlDoc.NewElement("value1");

	//// ���ýڵ��ֵ
	//pNewElement->SetText(1.0);

	//// ���ýڵ���ӵ�pElement�ڵ���("FloatValue")
	//pElement->InsertFirstChild(pNewElement);

	//// ָ���µĽڵ�
	//pNewElement = xmlDoc.NewElement("value2");

	//// ���ýڵ��ֵ
	//pNewElement->SetText(2.0);

	//// ���ýڵ���뵽pElement�ڵ��£������������)
	//pElement->InsertEndChild(pNewElement);

	/*����Ч��
	<?xml version="1.0"?>
	-<Root>
	<IntValue key="hello" year="2017">10</IntValue>
	-<FloatValue>
	<value1>1</value1>
	<value2>2</value2>
	</FloatValue>
	</Root>
	*/
}