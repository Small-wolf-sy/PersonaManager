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

#endif
