#include "XMLOperator.h"
#include <time.h>
#include <fstream>
XMLOperator::XMLOperator(string path)
{
	_localfile = path;
}
//修改存储路径
void XMLOperator::SetLocalFile(string path)
{
	_localfile = path;
}

XMLOperator::~XMLOperator()
{
}

//添加新的待检测备忘录
bool XMLOperator::WriteLocalStorage(memoryData md)
{
	//string path = "E:\\local_storage.xml";
	// 新建一个空文档（表示完整的xml）,为了避免与msxml冲突，重命名了tinyXMLDocument
	tinyxml2::TinyXMLDocument xmlDoc=new TinyXMLDocument();
	xmlDoc.LoadFile(_localfile.c_str());
	// 获取根节点，从而对数据进行更新存储
	XMLNode * pRoot = xmlDoc.RootElement();

	// 新建一个元素,最好就以关键词作为节点名，设置关键字
	XMLElement *pElement = xmlDoc.NewElement(md.GetKey().c_str());
	//设置记录时间
	XMLElement *recordElement= xmlDoc.NewElement("RecordTime");
	recordElement->SetText(md.GetRecord().c_str());
	pElement->InsertEndChild(recordElement);
	//截止时间
	XMLElement *pnewElement = xmlDoc.NewElement("DeadLine");
	//年
	XMLElement *time_element = xmlDoc.NewElement("year");
	time_element->SetText(md.GetDeadLine()[0]);
	pnewElement->InsertEndChild(time_element);
	//月
	time_element = xmlDoc.NewElement("month");
	time_element->SetText(md.GetDeadLine()[1]);
	pnewElement->InsertEndChild(time_element);
	//日
	time_element = xmlDoc.NewElement("day");
	time_element->SetText(md.GetDeadLine()[2]);
	pnewElement->InsertEndChild(time_element);
	// 将该节点添加到pRoot节点下("Root")
	pElement->InsertEndChild(pnewElement);

	//插入详细记录
	XMLElement *descriElement = xmlDoc.NewElement("Description");
	descriElement->SetText(md.GetDetails().c_str());
	pElement->InsertEndChild(descriElement);
	//放入总节点
	pRoot->InsertEndChild(pElement);
	// 保存文件
	//string xml_doc = path;
	XMLError eResult = xmlDoc.SaveFile(_localfile.data());
	return false;
}
//搜索本地结果
memoryData XMLOperator::SearchLocalStorage(string keyword)
{
	memoryData md;
	tinyxml2::TinyXMLDocument xmlDoc = new TinyXMLDocument();
	xmlDoc.LoadFile(_localfile.c_str());
	// 获取根节点，从而对数据进行更新存储
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
//实现搜索所得的节点与memoryData之间的转换
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
//检测本地是否存在待检测数据
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
//初始化程序，确定XML文件
void XMLOperator::XMLInitialLocalStorage(string path)
{
	// 新建一个空文档（表示完整的xml）,为了避免与msxml冲突，重命名了tinyXMLDocument
	tinyxml2::TinyXMLDocument xmlDoc;

	// 新节点
	XMLNode * pRoot = xmlDoc.NewElement("Default");

	// 插入到xmlDoc的第一个节点（根节点）
	xmlDoc.InsertFirstChild(pRoot);

	// 新建一个元素
	XMLElement *pElement = xmlDoc.NewElement("CreateInformation");
	XMLElement *pnewElement = xmlDoc.NewElement("CreateTime");
	// 设置该元素（节点）的值
	pElement->SetText("LocalMemoryStorageCreated");
	//获取创建时间
	time_t rawtime;
	time(&rawtime);
	struct tm *ptminfo;
	ptminfo = localtime(&rawtime);
	// 设置该元素的属性（重载)
	//年
	XMLElement *time_element = xmlDoc.NewElement("year");
	time_element->SetText(ptminfo->tm_year + 1900);
	pnewElement->InsertEndChild(time_element);
	//月
	time_element = xmlDoc.NewElement("month");
	time_element->SetText(ptminfo->tm_mon + 1);
	pnewElement->InsertEndChild(time_element);
	//日
	time_element = xmlDoc.NewElement("day");
	time_element->SetText(ptminfo->tm_mday);
	pnewElement->InsertEndChild(time_element);
	//星期
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
	//时
	time_element = xmlDoc.NewElement("hour");
	time_element->SetText(ptminfo->tm_hour);
	pnewElement->InsertEndChild(time_element);
	//分
	time_element = xmlDoc.NewElement("min");
	time_element->SetText(ptminfo->tm_min);
	pnewElement->InsertEndChild(time_element);
	//秒
	time_element = xmlDoc.NewElement("second");
	time_element->SetText(ptminfo->tm_sec);
	pnewElement->InsertEndChild(time_element);

	// 将该节点添加到pRoot节点下("Root")
	pElement->InsertEndChild(pnewElement);
	pRoot->InsertEndChild(pElement);

	// 保存文件
	string xml_doc = path;
	XMLError eResult = xmlDoc.SaveFile(xml_doc.data());

	//// 指向新的节点
	//pElement = xmlDoc.NewElement("FloatValue");

	//// 添加到pRoot节点（依次向下添加）
	//pRoot->InsertEndChild(pElement);

	//// 新建一个节点
	//XMLElement *pNewElement = xmlDoc.NewElement("value1");

	//// 设置节点的值
	//pNewElement->SetText(1.0);

	//// 将该节点添加到pElement节点下("FloatValue")
	//pElement->InsertFirstChild(pNewElement);

	//// 指向新的节点
	//pNewElement = xmlDoc.NewElement("value2");

	//// 设置节点的值
	//pNewElement->SetText(2.0);

	//// 将该节点插入到pElement节点下（依次向下添加)
	//pElement->InsertEndChild(pNewElement);

	/*最终效果
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