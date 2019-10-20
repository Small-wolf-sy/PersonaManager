#include "MemorGui.h"

MemorGui::MemorGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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

}
//添加事件
void MemorGui::addButtonClickEvent()
{
}
//确认输入事件
void MemorGui::inputFinishClickEvent()
{
	QMessageBox::warning(NULL, tr("title"), tr("OK"));
}
//取消输入事件
void MemorGui::inputCancelClickEvent()
{
	QMessageBox::warning(NULL, tr("title"), tr("cancel"));
}
