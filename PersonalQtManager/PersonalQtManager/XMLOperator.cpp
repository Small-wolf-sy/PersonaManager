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

//TODO，写一个和XML读写相关的类进行查找
//写本地数据
bool XMLOperator::WriteLocalStorage()
{
	return false;
}
//读本地数据
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
	string xml_doc = "local_storage.xml";
	xml_doc = path + xml_doc;
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