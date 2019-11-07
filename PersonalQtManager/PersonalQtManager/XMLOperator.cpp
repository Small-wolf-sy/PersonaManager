#include "XMLOperator.h"

XMLOperator::XMLOperator()
{
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
bool XMLOperator::ReadLocalStorage()
{
	return false;
}

//��ʼ������ȷ��XML�ļ�
void XMLOperator::XMLInitialLocalStorage(string path)
{
	// �½�һ�����ĵ�����ʾ������xml��,Ϊ�˱�����msxml��ͻ����������tinyXMLDocument
	tinyxml2::TinyXMLDocument xmlDoc;

	// �½ڵ�
	XMLNode * pRoot = xmlDoc.NewElement("Root");

	// ���뵽xmlDoc�ĵ�һ���ڵ㣨���ڵ㣩
	xmlDoc.InsertFirstChild(pRoot);

	// �½�һ��Ԫ��
	XMLElement *pElement = xmlDoc.NewElement("IntValue");

	// ���ø�Ԫ�أ��ڵ㣩��ֵ
	pElement->SetText(10);

	// ���ø�Ԫ�ص����ԣ����أ�
	pElement->SetAttribute("year", 2017);
	pElement->SetAttribute("key", "hello");

	// ���ýڵ���ӵ�pRoot�ڵ���("Root")
	pRoot->InsertEndChild(pElement);

	// ָ���µĽڵ�
	pElement = xmlDoc.NewElement("FloatValue");

	// ��ӵ�pRoot�ڵ㣨����������ӣ�
	pRoot->InsertEndChild(pElement);

	// �½�һ���ڵ�
	XMLElement *pNewElement = xmlDoc.NewElement("value1");

	// ���ýڵ��ֵ
	pNewElement->SetText(1.0);

	// ���ýڵ���ӵ�pElement�ڵ���("FloatValue")
	pElement->InsertFirstChild(pNewElement);

	// ָ���µĽڵ�
	pNewElement = xmlDoc.NewElement("value2");

	// ���ýڵ��ֵ
	pNewElement->SetText(2.0);

	// ���ýڵ���뵽pElement�ڵ��£������������)
	pElement->InsertEndChild(pNewElement);

	// �����ļ�
	string xml_doc = "test.xml";
	xml_doc = path + xml_doc;
	XMLError eResult = xmlDoc.SaveFile(xml_doc.data());

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