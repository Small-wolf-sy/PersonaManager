#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;
//�������ڴ洢MemoryUI�е�ÿһ���¼�
class memoryData
{
public:
	memoryData();
	memoryData(vector<int>);
	memoryData(vector<int>, string);
	memoryData(vector<int>,string,string);
	~memoryData();
	//��������,����template���Ӷ�ȷ�����鳤��
	void SetDate(vector<int> input_vec=vector<int>(0,3));
	//����int*��������˷ѣ���˲��ø��ַ�ʽ
	vector<int> GetDate();
	//���ùؼ���
	void SetKey(string input_words = "default");
	string GetKey();
	//���ñ�����Ϣ
	void SetDetails(string input_details = "null");
	string GetDetails();
private:
	vector<int> _date;//����
	string key_words;//�����ؼ���
	string detailsDescript;//��ϸ����
};

