#include "MemorGui.h"

MemorGui::MemorGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//����Ӱ�ť�¼�
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClickEvent()));
	//��������ť�¼�
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClickEvent()));
	//��Qdialog��ť�¼���accept��reject�ֱ��ӦOK��Cancel
	connect(ui.operateCheckBox, SIGNAL(accepted()), this, SLOT(inputFinishClickEvent()));
	connect(ui.operateCheckBox, SIGNAL(rejected()), this, SLOT(inputCancelClickEvent()));
}

MemorGui::~MemorGui()
{
}
//�����¼�
void MemorGui::searchButtonClickEvent()
{

}
//����¼�
void MemorGui::addButtonClickEvent()
{
}
//ȷ�������¼�
void MemorGui::inputFinishClickEvent()
{
	QMessageBox::warning(NULL, tr("title"), tr("OK"));
}
//ȡ�������¼�
void MemorGui::inputCancelClickEvent()
{
	QMessageBox::warning(NULL, tr("title"), tr("cancel"));
}
