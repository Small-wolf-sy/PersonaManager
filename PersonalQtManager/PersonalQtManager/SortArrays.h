#pragma once
//��ͷ�ļ��洢���õ��������
class SortArrays
{
public:
	//��������
	template<typename T>
	void SortQuickMethod(T &t, int start_index, int end_index);
	//ð������
	template<typename T>
	void SortBubbleMethod(T &t, int num);
	//ѡ������
	template<typename T>
	void SortChooseMethod(T &t, int num);
	SortArrays();
	~SortArrays();
};
//ð������ÿ��ѭ�������������ں�ͷ��
template<typename T>
void SortArrays::SortBubbleMethod(T &t, int num)
{
	bool flag = true;
	int cnt = 0;
	while (flag)
	{
		flag = false;
		//���ϵ��滻
		for (int i = 1; i < num - cnt; i++)
		{
			if (t[i] < t[i - 1])
			{
				int temp = t[i];
				t[i] = t[i - 1];
				t[i - 1] = temp;
				flag = true;
			}
		}
		cnt++;
	}
}
//�������򣨻��ڵ�����
template<typename T>
void SortArrays::SortQuickMethod(T &t, int start_index, int end_index)
{
	if (start_index >= end_index)
	{
		return;
	}
	int search_end = end_index;
	int search_start = start_index;
	while (search_start != search_end)
	{
		for (int i = search_end; i >= search_start; i--)
		{
			if (i == search_start)
			{
				search_end = search_start;
				break;
			}
			if (t[i] < t[search_start])
			{
				int temp = t[search_start];
				t[search_start] = t[i];
				t[i] = temp;
				search_end = i;
				break;
			}
		}
		for (int i = search_start; i <= search_end; i++)
		{
			if (i == search_end)
			{
				search_start = search_end;
				break;
			}
			if (t[i] > t[search_end])
			{
				int temp = t[search_end];
				t[search_end] = t[i];
				t[i] = temp;
				search_start = i;
				break;
			}
		}
	}
	SortQuickMethod(t, start_index, search_end - 1);
	SortQuickMethod(t, search_end + 1, end_index);
}

//ѡ������ÿ��ѭ������С��������ǰͷ��
template<typename T>
void SortArrays::SortChooseMethod(T &t, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (t[i] > t[j])
			{
				int temp = t[j];
				t[j] = t[i];
				t[i] = temp;
			}
		}
	}
}

SortArrays::SortArrays()
{
}

SortArrays::~SortArrays()
{
}