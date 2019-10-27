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

#endif
