#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;
//�������ڴ洢MemoryUI�е�ÿһ���¼�
class memoryData
{
public:
	memoryData(string, string);//��֪�ؼ������¼ʱ��
	memoryData(string, string, vector<int>);//�ؼ��ʡ���¼ʱ�䡢��ֹʱ��
	memoryData(string, string, vector<int>,string);//�ؼ��ʡ���¼ʱ�䡢��ֹʱ�䡢��ϸ˵��
	~memoryData();
	//��������,����template���Ӷ�ȷ�����鳤��
	void SetDeadLine(vector<int> input_vec=vector<int>(0,3));
	//����int*��������˷ѣ���˲��ø��ַ�ʽ
	vector<int> GetDeadLine();
	//���ùؼ���
	void SetKey(string input_words = "default");
	string GetKey();
	//���ñ�����Ϣ
	void SetDetails(string input_details = "null");
	string GetDetails();
	string GetRecord();
private:
	vector<int> _deadline;//��ֹ����
	string _recordtime;//��¼����
	string key_words;//�����ؼ���
	string detailsDescript;//��ϸ����
};

