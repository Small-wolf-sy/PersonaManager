#include "MemorGui.h"

MemorGui::MemorGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.timeRecord->setDisabled(true);
	ui.year_input->setDisabled(true);
	ui.day_input->setDisabled(true);
	ui.month_input->setDisabled(true);
	//设置tab快捷操作
	setTabOrder(ui.year_input,ui.month_input);
	setTabOrder(ui.month_input, ui.day_input);
	setTabOrder(ui.day_input, ui.detailDesrciption);
	//绑定添加按钮事件
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClickEvent()));
	//绑定搜索按钮事件
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClickEvent()));
	//绑定Qdialog按钮事件，accept和reject分别对应OK和Cancel
	connect(ui.operateCheckBox, SIGNAL(accepted()), this, SLOT(inputFinishClickEvent()));
	connect(ui.operateCheckBox, SIGNAL(rejected()), this, SLOT(inputCancelClickEvent()));
	//检查是否存在数据
	if (!data_operator.StorageCheck())
	{
		QMessageBox::warning(NULL, tr("information"), tr("Local Storage can't find,new created"));
	}
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
	try
	{
		switch (Memory_state)
		{
		case abilityType::add_Activated:
			QMessageBox::warning(NULL, tr("title"), tr("you used add ability"));
			AddActivated();
			break;
		case abilityType::search_Activated:
			QMessageBox::warning(NULL, tr("title"), tr("you used search ability"));
			SearchActivated(ui.memKey->toPlainText().toStdString());
			break;
		default:
			break;
		}
	}
	catch (exception e)
	{
		QMessageBox::warning(NULL, tr("systemWrong"), tr("ability-activated-failed"));
		SetMemDiseabled();
		SetSearchAddEnabled();
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
	ui.year_input->setEnabled(true);
	ui.day_input->setEnabled(true);
	ui.month_input->setEnabled(true);
	//timeRecord需要单独处理
	ui.timeRecord->setText(QTime::currentTime().toString("hh:mm:ss"));
}
//设置不可输入
void MemorGui::SetMemDiseabled()
{
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.year_input->setDisabled(true);
	ui.day_input->setDisabled(true);
	ui.month_input->setDisabled(true);
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
//读取当前数据并存储
void MemorGui::AddActivated()
{
	string key_words = ui.memKey->toPlainText().toStdString();
	if (key_words == "")
	{
		QMessageBox::warning(NULL, tr("warning"), tr("keywords must be told"));
		return;
	}
	string record_time = ui.timeRecord->toPlainText().toStdString();
	string descr = ui.detailDesrciption->toPlainText().toStdString();
	int year = atoi(ui.year_input->toPlainText().toStdString().c_str());
	int month = atoi(ui.month_input->toPlainText().toStdString().c_str());
	int day = atoi(ui.day_input->toPlainText().toStdString().c_str());
	vector<int> deadline = { year,month,day };
	memoryData addmem = memoryData(key_words,record_time,deadline,descr);
	data_operator.WriteLocalStorage(addmem);
	return;
}
//读取当前关键词并搜索
void MemorGui::SearchActivated(string keyword)
{
	memoryData md=data_operator.SearchLocalStorage(keyword);
	ui.timeRecord->setText(QString::fromStdString(md.GetRecord()));
	ui.detailDesrciption->setPlainText(QString::fromStdString(md.GetDetails()));
	vector<int> deadline = md.GetDeadLine();
	ui.year_input->setText(QString::fromStdString(std::to_string(deadline[0])));
	ui.month_input->setText(QString::fromStdString(std::to_string(deadline[1])));
	ui.day_input->setText(QString::fromStdString(std::to_string(deadline[2])));
	return;
}