//#pragma once
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <qthread.h>
#include <QtWidgets/QLabel>
#include <windows.h>
#include <QTime>
//���ڼ�ʱʱ����ֳ�
class MyTimeThread:public QThread
{
public:
	//����������ʱ��
	MyTimeThread(QLabel *label) {
		_label = label;
	}
	~MyTimeThread() {

	}
	void run()//��д
	{
		while (true)
		{
			Sleep(1000);
			_label->setText(QTime::currentTime().toString("hh:mm:ss"));
		}
	}
private:
	QLabel *_label;
};
//����ȷ��CPU��ʹ�����
class MyCPUThread :public QThread
{
public:
	//���������ı�ǩ
	MyCPUThread(QLabel *label) {
		_label = label;
	}
	~MyCPUThread() {

	}
	void run()//��д
	{
		BOOL res;
		FILETIME preidleTime;
		FILETIME prekernelTime;
		FILETIME preuserTime;
		FILETIME idleTime;
		FILETIME kernelTime;
		FILETIME userTime;
		while (true)
		{
			Sleep(1000);
			res = GetSystemTimes(&idleTime, &kernelTime, &userTime);

			__int64 idle = CompareFileTime(preidleTime, idleTime);
			__int64 kernel = CompareFileTime(prekernelTime, kernelTime);
			__int64 user = CompareFileTime(preuserTime, userTime);

			__int64 cpu = (kernel + user - idle) * 100 / (kernel + user);
			__int64 cpuidle = (idle) * 100 / (kernel + user);
			std::string cpu_result;
			cpu_result= "CPU������:";
			cpu_result += std::to_string(cpu)+"% CPU������:"+ std::to_string(cpuidle);
			cpu_result += "%";
			_label->setText(QString::fromStdString(cpu_result));
			preidleTime = idleTime;
			prekernelTime = kernelTime;
			preuserTime = userTime;
		}
	}
private:
	QLabel *_label;
	__int64 CompareFileTime(FILETIME time1, FILETIME time2)
	{
		__int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime;
		__int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime;

		return (b - a);
	}
};
#endif
