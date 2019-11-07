#include "XMLOperator.h"

XMLOperator::XMLOperator()
{
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
bool XMLOperator::ReadLocalStorage()
{
	return false;
}

//初始化程序，确定XML文件
void XMLOperator::XMLInitialLocalStorage(string path)
{
	// 新建一个空文档（表示完整的xml）
	tinyxml2::XMLDocument xmlDoc;

	// 新节点
	XMLNode * pRoot = xmlDoc.NewElement("Root");

	// 插入到xmlDoc的第一个节点（根节点）
	xmlDoc.InsertFirstChild(pRoot);

	// 新建一个元素
	XMLElement *pElement = xmlDoc.NewElement("IntValue");

	// 设置该元素（节点）的值
	pElement->SetText(10);

	// 设置该元素的属性（重载）
	pElement->SetAttribute("year", 2017);
	pElement->SetAttribute("key", "hello");

	// 将该节点添加到pRoot节点下("Root")
	pRoot->InsertEndChild(pElement);

	// 指向新的节点
	pElement = xmlDoc.NewElement("FloatValue");

	// 添加到pRoot节点（依次向下添加）
	pRoot->InsertEndChild(pElement);

	// 新建一个节点
	XMLElement *pNewElement = xmlDoc.NewElement("value1");

	// 设置节点的值
	pNewElement->SetText(1.0);

	// 将该节点添加到pElement节点下("FloatValue")
	pElement->InsertFirstChild(pNewElement);

	// 指向新的节点
	pNewElement = xmlDoc.NewElement("value2");

	// 设置节点的值
	pNewElement->SetText(2.0);

	// 将该节点插入到pElement节点下（依次向下添加)
	pElement->InsertEndChild(pNewElement);

	// 保存文件
	XMLError eResult = xmlDoc.SaveFile("test.xml");
}