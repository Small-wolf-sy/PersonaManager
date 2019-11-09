#include "memoryData.h"

//���캯��
memoryData::memoryData(string keywords, string recordtime)
{
	key_words = keywords;
	_recordtime = recordtime;
}
memoryData::memoryData(string keywords, string recordtime,vector<int> deadline)
{
	key_words = keywords;
	_recordtime = recordtime;
	_deadline = deadline;
}

memoryData::memoryData(string keywords, string recordtime, vector<int> deadline,string description)
{
	key_words = keywords;
	_recordtime = recordtime;
	_deadline = deadline;
	detailsDescript = description;
}
memoryData::~memoryData()
{
}
//���ý�ֹʱ��
void memoryData::SetDeadLine(vector<int> input_vec)
{
	//��ʱ�Զ��������µģ���ʹ�ڵ��ú��������޸���input_vec��_deadline������ı�
	_deadline = input_vec;
}
//���ý�ֹʱ��
vector<int> memoryData::GetDeadLine()
{
	return _deadline;
}
//��ȡ��¼ʱ�䣬�޷��޸�
string memoryData::GetRecord()
{
	return this->_recordtime;
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
