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

//����µĴ���ⱸ��¼
bool XMLOperator::WriteLocalStorage(memoryData md)
{
	//string path = "E:\\local_storage.xml";
	// �½�һ�����ĵ�����ʾ������xml��,Ϊ�˱�����msxml��ͻ����������tinyXMLDocument
	tinyxml2::TinyXMLDocument xmlDoc=new TinyXMLDocument();
	xmlDoc.LoadFile(_localfile.c_str());
	// ��ȡ���ڵ㣬�Ӷ������ݽ��и��´洢
	XMLNode * pRoot = xmlDoc.RootElement();

	// �½�һ��Ԫ��,��þ��Թؼ�����Ϊ�ڵ��������ùؼ���
	XMLElement *pElement = xmlDoc.NewElement(md.GetKey().c_str());
	//���ü�¼ʱ��
	XMLElement *recordElement= xmlDoc.NewElement("RecordTime");
	recordElement->SetText(md.GetRecord().c_str());
	pElement->InsertEndChild(recordElement);
	//��ֹʱ��
	XMLElement *pnewElement = xmlDoc.NewElement("DeadLine");
	//��
	XMLElement *time_element = xmlDoc.NewElement("year");
	time_element->SetText(md.GetDeadLine()[0]);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("month");
	time_element->SetText(md.GetDeadLine()[1]);
	pnewElement->InsertEndChild(time_element);
	//��
	time_element = xmlDoc.NewElement("day");
	time_element->SetText(md.GetDeadLine()[2]);
	pnewElement->InsertEndChild(time_element);
	// ���ýڵ���ӵ�pRoot�ڵ���("Root")
	pElement->InsertEndChild(pnewElement);

	//������ϸ��¼
	XMLElement *descriElement = xmlDoc.NewElement("Description");
	descriElement->SetText(md.GetDetails().c_str());
	pElement->InsertEndChild(descriElement);
	//�����ܽڵ�
	pRoot->InsertEndChild(pElement);
	// �����ļ�
	//string xml_doc = path;
	XMLError eResult = xmlDoc.SaveFile(_localfile.data());
	return false;
}
//�������ؽ��
memoryData XMLOperator::SearchLocalStorage(string keyword)
{
	memoryData md;
	tinyxml2::TinyXMLDocument xmlDoc = new TinyXMLDocument();
	xmlDoc.LoadFile(_localfile.c_str());
	// ��ȡ���ڵ㣬�Ӷ������ݽ��и��´洢
	XMLNode * pRoot = xmlDoc.RootElement();
	XMLElement *StuElement = pRoot->FirstChildElement();
	while(true)
	{	
		if (StuElement == NULL)
		{
			break;
		}
	    if (StuElement->Name()==keyword)
		{
			ConvertXML(md,StuElement);
			break;
		}
		else
		{
			StuElement = StuElement->NextSiblingElement();
		}
	}
	return md;
}
//ʵ���������õĽڵ���memoryData֮���ת��
void XMLOperator::ConvertXML(memoryData &md,XMLElement *targetElement)
{
	md.SetKey(targetElement->Name());
	XMLElement *RecordTime = targetElement->FirstChildElement();
	md.SetRecord(RecordTime->GetText());
	XMLElement *deadline = RecordTime->NextSiblingElement();
	XMLElement *year_xml = deadline->FirstChildElement();
	XMLElement *month_xml = year_xml->NextSiblingElement();
	XMLElement *day_xml = month_xml->NextSiblingElement();
	int year = atoi(year_xml->GetText());
	int month = atoi(month_xml->GetText());
	int day = atoi(day_xml->GetText());
	vector<int> xml_deadlinerecord = { year,month,day };
	md.SetDeadLine(xml_deadlinerecord);
	XMLElement *description = deadline->NextSiblingElement();
	md.SetDetails(description->GetText());
}
//��Ȿ���Ƿ���ڴ��������
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
	string xml_doc = path;
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