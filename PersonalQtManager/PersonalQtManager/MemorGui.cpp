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
	//����tab��ݲ���
	setTabOrder(ui.year_input,ui.month_input);
	setTabOrder(ui.month_input, ui.day_input);
	setTabOrder(ui.day_input, ui.detailDesrciption);
	//����Ӱ�ť�¼�
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButtonClickEvent()));
	//��������ť�¼�
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClickEvent()));
	//��Qdialog��ť�¼���accept��reject�ֱ��ӦOK��Cancel
	connect(ui.operateCheckBox, SIGNAL(accepted()), this, SLOT(inputFinishClickEvent()));
	connect(ui.operateCheckBox, SIGNAL(rejected()), this, SLOT(inputCancelClickEvent()));
	//����Ƿ��������
	if (!data_operator.StorageCheck())
	{
		QMessageBox::warning(NULL, tr("information"), tr("Local Storage can't find,new created"));
	}
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
	ui.year_input->setEnabled(true);
	ui.day_input->setEnabled(true);
	ui.month_input->setEnabled(true);
	//timeRecord��Ҫ��������
	ui.timeRecord->setText(QTime::currentTime().toString("hh:mm:ss"));
}
//���ò�������
void MemorGui::SetMemDiseabled()
{
	ui.detailDesrciption->setDisabled(true);
	ui.memKey->setDisabled(true);
	ui.operateCheckBox->setDisabled(true);
	ui.year_input->setDisabled(true);
	ui.day_input->setDisabled(true);
	ui.month_input->setDisabled(true);
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
//��ȡ��ǰ���ݲ��洢
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
//��ȡ��ǰ�ؼ��ʲ�����
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