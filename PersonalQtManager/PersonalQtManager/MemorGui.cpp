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
	//������Ӱ�ť
	ui.addButton->setEnabled(false);
	ClearContext();
	ui.memKey->setEnabled(true);
	ui.operateCheckBox->setEnabled(true);
	Memory_state = abilityType::search_Activated;
}
//����¼�
void MemorGui::addButtonClickEvent()
{
	//����������ť
	ui.searchButton->setEnabled(false);
	ClearContext();
	SetMemEabled();
	Memory_state = abilityType::add_Activated;
}
//ȷ�������¼�
void MemorGui::inputFinishClickEvent()
{
	//��鵱ǰ״̬
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
//ȡ�������¼�
void MemorGui::inputCancelClickEvent()
{
	ClearContext();
	SetMemDiseabled();
	SetSearchAddEnabled();
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
//������������ӹ���
void MemorGui::SetSearchAddEnabled()
{
	ui.addButton->setEnabled(true);
	ui.searchButton->setEnabled(true);
	Memory_state = abilityType::none_Activated;
}
//���ر�ʱ�����߸������Ӵ��ڹر�
void MemorGui::closeEvent(QCloseEvent * event)
{
	emit closedSignals();
	//���ܹر��ź�
	event->accept();
}

