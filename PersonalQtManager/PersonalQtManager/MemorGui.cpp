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
	//冻结添加按钮
	ui.addButton->setEnabled(false);
	ClearContext();
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
	Memory_state = abilityType::search_Activated;
}
//添加事件
void MemorGui::addButtonClickEvent()
{
	//冻结搜索按钮
	ui.searchButton->setEnabled(false);
	ClearContext();
	SetMemEabled();
	Memory_state = abilityType::add_Activated;
}
//确认输入事件
void MemorGui::inputFinishClickEvent()
{
	//检查当前状态
	switch (Memory_state)
	{
	case abilityType::add_Activated:
		QMessageBox::warning(NULL, tr("title"), tr("you used add ability"));
		break;
	case abilityType::search_Activated:
		QMessageBox::warning(NULL, tr("title"), tr("you used search ability"));
		break;
	default:
		break;
	}
	SetMemDiseabled();
	SetSearchAddEnabled();
}
//取消输入事件
void MemorGui::inputCancelClickEvent()
{
	ClearContext();
	SetMemDiseabled();
	SetSearchAddEnabled();
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
//激活搜索和添加功能
void MemorGui::SetSearchAddEnabled()
{
	ui.addButton->setEnabled(true);
	ui.searchButton->setEnabled(true);
	Memory_state = abilityType::none_Activated;
}
//当关闭时，告诉父窗口子窗口关闭
void MemorGui::closeEvent(QCloseEvent * event)
{
	emit closedSignals();
	//接受关闭信号
	event->accept();
}

