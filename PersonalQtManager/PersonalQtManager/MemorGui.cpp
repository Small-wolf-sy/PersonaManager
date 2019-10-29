#include "MemorGui.h"

MemorGui::MemorGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.timeRecord->setDisabled(true);
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
	ClearContext();
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
}
//����¼�
void MemorGui::addButtonClickEvent()
{
	ClearContext();
	SetMemEabled();
}
//ȷ�������¼�
void MemorGui::inputFinishClickEvent()
{
	SetMemDiseabled();
	//QMessageBox::warning(NULL, tr("title"), tr("OK"));
}
//ȡ�������¼�
void MemorGui::inputCancelClickEvent()
{
	ClearContext();
	SetMemDiseabled();
	//QMessageBox::warning(NULL, tr("title"), tr("cancel"));
}
//�����������
void MemorGui::ClearContext()
{
	ui.detailDesrciption->clear();
	ui.memKey->clear();
	ui.timeRecord->clear();
}
//���ÿ�����
void MemorGui::SetMemEabled()
{
	ui.detailDesrciption->setEnabled(true);
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
	ui.timeRecord->setEnabled(true);

}
//���ò�������
void MemorGui::SetMemDiseabled()
{
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.timeRecord->setDisabled(true);
}

//���ر�ʱ�����߸������Ӵ��ڹر�
void MemorGui::closeEvent(QCloseEvent * event)
{
	emit closedSignals();
	//���ܹر��ź�
	event->accept();
}
