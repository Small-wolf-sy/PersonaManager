//#pragma once
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <qthread.h>
#include <QtWidgets/QLabel>
#include <windows.h>
#include <QTime>
//用于计时时间的现成
class MyTimeThread:public QThread
{
public:
	//设置所属的时间
	MyTimeThread(QLabel *label) {
		_label = label;
	}
	~MyTimeThread() {

	}
	void run()//重写
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
//用于确认CPU的使用情况
class MyCPUThread :public QThread
{
public:
	//设置所属的标签
	MyCPUThread(QLabel *label) {
		_label = label;
	}
	~MyCPUThread() {

	}
	void run()//重写
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
			cpu_result= "CPU利用率:";
			cpu_result += std::to_string(cpu)+"% CPU空闲率:"+ std::to_string(cpuidle);
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
