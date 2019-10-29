#include "MemorGui.h"

MemorGui::MemorGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.timeRecord->setDisabled(true);
	//绑定添加按钮事件
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClickEvent()));
	//绑定搜索按钮事件
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClickEvent()));
	//绑定Qdialog按钮事件，accept和reject分别对应OK和Cancel
	connect(ui.operateCheckBox, SIGNAL(accepted()), this, SLOT(inputFinishClickEvent()));
	connect(ui.operateCheckBox, SIGNAL(rejected()), this, SLOT(inputCancelClickEvent()));
}

MemorGui::~MemorGui()
{
}
//搜索事件
void MemorGui::searchButtonClickEvent()
{
	ClearContext();
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
}
//添加事件
void MemorGui::addButtonClickEvent()
{
	ClearContext();
	SetMemEabled();
}
//确认输入事件
void MemorGui::inputFinishClickEvent()
{
	SetMemDiseabled();
	//QMessageBox::warning(NULL, tr("title"), tr("OK"));
}
//取消输入事件
void MemorGui::inputCancelClickEvent()
{
	ClearContext();
	SetMemDiseabled();
	//QMessageBox::warning(NULL, tr("title"), tr("cancel"));
}
//清空文字内容
void MemorGui::ClearContext()
{
	ui.detailDesrciption->clear();
	ui.memKey->clear();
	ui.timeRecord->clear();
}
//设置可输入
void MemorGui::SetMemEabled()
{
	ui.detailDesrciption->setEnabled(true);
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
	ui.timeRecord->setEnabled(true);

}
//设置不可输入
void MemorGui::SetMemDiseabled()
{
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.timeRecord->setDisabled(true);
}

//当关闭时，告诉父窗口子窗口关闭
void MemorGui::closeEvent(QCloseEvent * event)
{
	emit closedSignals();
	//接受关闭信号
	event->accept();
}
