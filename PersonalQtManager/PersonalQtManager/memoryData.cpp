#include "memoryData.h"

//���캯��
memoryData::memoryData()
{
}
memoryData::memoryData(vector<int> date)
{
	_date = date;
}
memoryData::memoryData(vector<int>date,string key)
{
	_date = date;
	key_words = key;
}
memoryData::memoryData(vector<int>date,string key,string description)
{
	_date = date;
	key_words = key;
	detailsDescript = description;
}
memoryData::~memoryData()
{
}
//��������
void memoryData::SetDate(vector<int> input_vec)
{
	//��ʱ�Զ��������µģ���ʹ�ڵ��ú��������޸���input_vec��_date������ı�
	_date = input_vec;
}
//��ȡʱ��
vector<int> memoryData::GetDate()
{
	return _date;
}
//���ùؼ���
void memoryData::SetKey(string input_words)
{
	this->key_words = input_words;
}
//��ȡ�ؼ���
string memoryData::GetKey()
{
	return this->key_words;
}
//���ñ���¼����
void memoryData::SetDetails(string input_details)
{
	this->detailsDescript = input_details;
}
//��ȡ����¼����
string memoryData::GetDetails()
{
	return this->detailsDescript;
}
