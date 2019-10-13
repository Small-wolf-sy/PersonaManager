#pragma once
//本头文件存储常用的排序程序
class SortArrays
{
public:
	//快速排序
	template<typename T>
	void SortQuickMethod(T &t, int start_index, int end_index);
	//冒泡排序
	template<typename T>
	void SortBubbleMethod(T &t, int num);
	//选择排序
	template<typename T>
	void SortChooseMethod(T &t, int num);
	SortArrays();
	~SortArrays();
};
//冒泡排序（每次循环将最大的数放在后头）
template<typename T>
void SortArrays::SortBubbleMethod(T &t, int num)
{
	bool flag = true;
	int cnt = 0;
	while (flag)
	{
		flag = false;
		//不断地替换
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
//快速排序（基于迭代）
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

//选择排序（每次循环将最小的数放在前头）
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