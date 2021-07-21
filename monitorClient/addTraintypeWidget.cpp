#include "addTraintypeWidget.h"
#include "ui_addTraintypeWidget.h"
#include "state.h"
#include "debug.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QString>
#include <stdio.h>
#include <ctype.h>

QButtonGroup *g_groupsetButtonGroup = NULL;

addTrainTypeWidget::addTrainTypeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addTrainTypeWidget)
{
    ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);  

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);

    p_ipmethod= new commonInputMethod();
	if (p_ipmethod != NULL)
	{
		QWSServer::setCurrentInputMethod(p_ipmethod);
	    p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->setGeometry(231, 440, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
		    p_ipmethod->p_inputwidget->hide();
			p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
		}
	}

    ui->trainTypeNameLineEdit->installEventFilter(this);

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(closeWidgetSlot()));
    connect(ui->confirmPushButton, SIGNAL(clicked(bool)), this, SLOT(confirmSlot()));
    connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(cancleSlot()));
	connect(ui->serverNumComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serverNumChangeSlot()));

	g_groupsetButtonGroup = new QButtonGroup();      //编组设置单选按钮组成一组，方便检测编组设置的选择
    g_groupsetButtonGroup->addButton(ui->groupSetRadioButton,1);
    g_groupsetButtonGroup->addButton(ui->groupSetRadioButton_2,2);
	connect(g_groupsetButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(groupSetChange(int)));     //单选按钮组按键信号连接响应槽函数
}

addTrainTypeWidget::~addTrainTypeWidget()
{
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}
	delete g_groupsetButtonGroup;
	g_groupsetButtonGroup = NULL;
    delete ui;
}

void addTrainTypeWidget::closeWidgetSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}

void addTrainTypeWidget::confirmSlot()
{
	char acTrainTypeName[256] = {0};
	char acLineStr[256] = {0};
	char acTrainType[32] = {0};
	int iNvrServerNum = 0, iTrainTypeNum = 0, i = 0, iLen = 0;
	int iServerCarriageNo1 = -1, iServerCarriageNo2 = -2, iServerCarriageNo3 = -3, iServerCarriageNo4 = -4;
	int iServerPvmsCarNo1 = -1, iServerPvmsCarNo2 = -2, iServerPvmsCarNo3 = -3, iServerPvmsCarNo4 = -4;
	FILE *pNewConfigFile = NULL;
	T_TRAIN_TYPE_LIST tTrainTypeList;

	ui->trainTypeNameWarnLabel->setText("");
		
	if (ui->trainTypeNameLineEdit->text() == "")
	{
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->hide();
		}
		ui->trainTypeNameWarnLabel->setText(QObject::tr("*车型名不能为空"));
		ui->trainTypeNameWarnLabel->setFocus();
		return;
	}

	snprintf(acLineStr, sizeof(acLineStr), "%s",ui->trainTypeNameLineEdit->text().toLatin1().data());
	iLen = strlen(acLineStr);
	for (i = 0; i < iLen; i++)	  //判断文件名是否只包含有字母和数字
	{
		if (0 == isalnum(acLineStr[i]))
		{
			ui->trainTypeNameWarnLabel->setText(QObject::tr("*车型名包含非正常字符"));
			ui->trainTypeNameWarnLabel->setFocus();
			return;
		}
	}

	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    STATE_GetTrainTypeList(&tTrainTypeList);
	for (i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		if (!strcmp(acLineStr, tTrainTypeList.acTrainTypeName[i]))
		{
			ui->trainTypeNameWarnLabel->setText(QObject::tr("*该车型名的车型已存在"));
			ui->trainTypeNameWarnLabel->setFocus();
			return;
		}
	}

	iNvrServerNum = atoi(ui->serverNumComboBox->currentText().toLatin1().data());
	for (i = 0; i < iNvrServerNum; i++)
	{
		if (0 == i)
		{
			iServerCarriageNo1 = atoi(ui->firstServerCarNoComboBox->currentText().toLatin1().data());
			iServerPvmsCarNo1 = atoi(ui->firstServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
		else if (1 == i)
		{
			iServerCarriageNo2 = atoi(ui->secondServerCarNoComboBox->currentText().toLatin1().data());
			iServerPvmsCarNo2 = atoi(ui->secondServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
		else if (2 == i)
		{
			iServerCarriageNo3 = atoi(ui->thirdServerCarNoComboBox->currentText().toLatin1().data());
			iServerPvmsCarNo3 = atoi(ui->thirdServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
		else if (3 == i)
		{
			iServerCarriageNo4 = atoi(ui->fourthServerCarNoComboBox->currentText().toLatin1().data());
			iServerPvmsCarNo4 = atoi(ui->fourthServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
	}

	if (iServerCarriageNo1 == iServerCarriageNo2 ||iServerCarriageNo1 == iServerCarriageNo3 ||
		iServerCarriageNo1 == iServerCarriageNo4 ||iServerCarriageNo2 == iServerCarriageNo3 ||
		iServerCarriageNo2 == iServerCarriageNo4 ||iServerCarriageNo3 == iServerCarriageNo4)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "addTrainTypeWidget can not set the same server carriageNo!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("不能设置相同的服务器车厢号!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}

	if (iServerPvmsCarNo1 == iServerPvmsCarNo2 ||iServerPvmsCarNo1 == iServerPvmsCarNo3 ||
		iServerPvmsCarNo1 == iServerPvmsCarNo4 ||iServerPvmsCarNo2 == iServerPvmsCarNo3 ||
		iServerPvmsCarNo2 == iServerPvmsCarNo4 ||iServerPvmsCarNo3 == iServerPvmsCarNo4)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "addTrainTypeWidget can not set the same pvms carriageNo!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("不能设置相同的受电弓车厢号!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}

	strcpy(acTrainTypeName, "/home/data/emuVideoMornitorClient/cfg/");
	strncat(acTrainTypeName, ui->trainTypeNameLineEdit->text().toLatin1().data(), strlen(ui->trainTypeNameLineEdit->text().toLatin1().data()));
	strcat(acTrainTypeName, ".ini");
	pNewConfigFile = fopen(acTrainTypeName, "wb");
	if (NULL == pNewConfigFile)
	{
		return;
	}

	iTrainTypeNum = STATE_GetTrainTypeNum();
	STATE_GetLastTrainType(acTrainType, sizeof(acTrainType));
	memset(acTrainTypeName, 0, sizeof(acTrainTypeName));
	snprintf(acTrainTypeName, sizeof(acTrainTypeName), "%s\nTrainType%d=%s",acTrainType, iTrainTypeNum+1, ui->trainTypeNameLineEdit->text().toLatin1().data());
	STATE_addTrainType(acTrainTypeName);	
	STATE_SetTrainTypeNum(iTrainTypeNum+1);
	
	memset(acLineStr, 0, sizeof(acLineStr));
	snprintf(acLineStr, sizeof(acLineStr), "[PVSM_TRAIN]\n");
	fputs(acLineStr, pNewConfigFile);

	memset(acLineStr, 0, sizeof(acLineStr));
	snprintf(acLineStr, sizeof(acLineStr), "NVRCount=%d\n", iNvrServerNum);
	fputs(acLineStr, pNewConfigFile);

	memset(acLineStr, 0, sizeof(acLineStr));
	if (1 == g_groupsetButtonGroup->checkedId())
	{
		snprintf(acLineStr, sizeof(acLineStr), "FormationType=%d\n\n\n", 1);
	}
	else if (2 == g_groupsetButtonGroup->checkedId())
	{
		snprintf(acLineStr, sizeof(acLineStr), "FormationType=%d\n\n\n", 2);
	}
	fputs(acLineStr, pNewConfigFile);

	for (i = 0; i < iNvrServerNum; i++)
	{
		memset(acLineStr, 0, sizeof(acLineStr));
		snprintf(acLineStr, sizeof(acLineStr), "[PVMS_NVR%d]\n", i+1);
		fputs(acLineStr, pNewConfigFile);

		if (0 == i)
		{
			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "NVRCarriageNO=%s\n", ui->firstServerCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCameraNum=%s\n", ui->firstServerPvmsNumComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCarriageNO=%s\n\n\n", ui->firstServerPvmsCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);
		}

		else if (1 == i)
		{
			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "NVRCarriageNO=%s\n", ui->secondServerCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCameraNum=%s\n", ui->secondServerPvmsNumComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCarriageNO=%s\n\n\n", ui->secondServerPvmsCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);
		}
		else if (2 == i)
		{
			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "NVRCarriageNO=%s\n", ui->thirdServerCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCameraNum=%s\n", ui->thirdServerPvmsNumComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCarriageNO=%s\n\n\n", ui->thirdServerPvmsCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);
		}
		else if (3 == i)
		{
			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "NVRCarriageNO=%s\n", ui->fourthServerCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCameraNum=%s\n", ui->fourthServerPvmsNumComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);

			memset(acLineStr, 0, sizeof(acLineStr));
			snprintf(acLineStr, sizeof(acLineStr), "PvmsCarriageNO=%s\n\n\n", ui->fourthServerPvmsCarNoComboBox->currentText().toLatin1().data());
			fputs(acLineStr, pNewConfigFile);
		}
	}

	fclose(pNewConfigFile);
	emit sendCloseMsg();
}


void addTrainTypeWidget::cancleSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}


bool addTrainTypeWidget::eventFilter(QObject *target, QEvent *event)
{
    if ((target == ui->trainTypeNameLineEdit) && (event->type() == QEvent::MouseButtonPress))
    {
        QMouseEvent *me = (QMouseEvent *)event;
        if (me->button() == Qt::LeftButton)
        {
        	if (NULL == p_ipmethod)
			{
				p_ipmethod= new commonInputMethod();
				if (NULL == p_ipmethod)
				{
					return QWidget::eventFilter(target, event);
				}
				QWSServer::setCurrentInputMethod(p_ipmethod);
				if (NULL == p_ipmethod->p_inputwidget)
				{
					p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
					if (NULL == p_ipmethod->p_inputwidget)
					{
						return QWidget::eventFilter(target, event);
					}
					p_ipmethod->setConnect();
    				p_ipmethod->setMapping();
				}
			}
			else
			{
				if (NULL == p_ipmethod->p_inputwidget)
				{
					p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
					if (NULL == p_ipmethod->p_inputwidget)
					{
						return QWidget::eventFilter(target, event);
					}
					p_ipmethod->setConnect();
	    			p_ipmethod->setMapping();
				}
			}
			p_ipmethod->p_inputwidget->setGeometry(231, 440, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
            p_ipmethod->p_inputwidget->show();
        }
        ui->trainTypeNameLineEdit->setText("");
        ui->trainTypeNameLineEdit->setStyleSheet("QLineEdit{color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);}");
    }
        
    return QWidget::eventFilter(target, event);
}

void addTrainTypeWidget::groupSetChange(int iComboBoxId)
{
	static int iOldId = 0;
	int i = 0;
	if (iComboBoxId != iOldId)
	{
		switch (iComboBoxId) //根据单选按钮组按键信号传入的单选按钮编号区分不同的单选按钮，做出不同的设置
		{
			case 1:
			{
				ui->firstServerCarNoComboBox->clear();
				ui->firstServerPvmsCarNoComboBox->clear();
				ui->secondServerCarNoComboBox->clear();
				ui->secondServerPvmsCarNoComboBox->clear();
				ui->thirdServerCarNoComboBox->clear();
				ui->thirdServerPvmsCarNoComboBox->clear();
				ui->fourthServerCarNoComboBox->clear();
				ui->fourthServerPvmsCarNoComboBox->clear();
				for(i = 0; i < 8; i++)
				{
					ui->firstServerCarNoComboBox->addItem(QString::number(i+1));
					ui->firstServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->secondServerCarNoComboBox->addItem(QString::number(i+1));
					ui->secondServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->thirdServerCarNoComboBox->addItem(QString::number(i+1));
					ui->thirdServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->fourthServerCarNoComboBox->addItem(QString::number(i+1));
					ui->fourthServerPvmsCarNoComboBox->addItem(QString::number(i+1));
				}
				break;
			}
			case 2:
			{
				ui->firstServerCarNoComboBox->clear();
				ui->firstServerPvmsCarNoComboBox->clear();
				ui->secondServerCarNoComboBox->clear();
				ui->secondServerPvmsCarNoComboBox->clear();
				ui->thirdServerCarNoComboBox->clear();
				ui->thirdServerPvmsCarNoComboBox->clear();
				ui->fourthServerCarNoComboBox->clear();
				ui->fourthServerPvmsCarNoComboBox->clear();
				for(i = 0; i < 16; i++)
				{
					ui->firstServerCarNoComboBox->addItem(QString::number(i+1));
					ui->firstServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->secondServerCarNoComboBox->addItem(QString::number(i+1));
					ui->secondServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->thirdServerCarNoComboBox->addItem(QString::number(i+1));
					ui->thirdServerPvmsCarNoComboBox->addItem(QString::number(i+1));
					ui->fourthServerCarNoComboBox->addItem(QString::number(i+1));
					ui->fourthServerPvmsCarNoComboBox->addItem(QString::number(i+1));
				}
				break;
			}
			default:
				break;
		}
		iOldId = iComboBoxId;
	}
}

void addTrainTypeWidget::serverNumChangeSlot()
{
	int idex = 0, i = 0;

	idex = ui->serverNumComboBox->currentIndex();
	if (0 == idex)
	{
		ui->firstServerInfoGroupBox->setEnabled(true);
		ui->secondServerInfoGroupBox->setEnabled(false);
		ui->thirdServerInfoGroupBox->setEnabled(false);
		ui->fourthServerInfoGroupBox->setEnabled(false);

		ui->firstServerPvmsNumComboBox->clear();
		for(i = 0; i < 2; i++)
		{
			ui->firstServerPvmsNumComboBox->addItem(QString::number(i+1));
		}
	}
	else if (1 == idex)
	{
		ui->firstServerInfoGroupBox->setEnabled(true);
		ui->secondServerInfoGroupBox->setEnabled(true);
		ui->thirdServerInfoGroupBox->setEnabled(false);
		ui->fourthServerInfoGroupBox->setEnabled(false);

		ui->firstServerPvmsNumComboBox->clear();
		ui->secondServerPvmsNumComboBox->clear();
		for(i = 0; i < 2; i++)
		{
			ui->firstServerPvmsNumComboBox->addItem(QString::number(i+1));
			ui->secondServerPvmsNumComboBox->addItem(QString::number(i+1));
		}
	}
	else if (2 == idex)
	{
		ui->firstServerInfoGroupBox->setEnabled(true);
		ui->secondServerInfoGroupBox->setEnabled(true);
		ui->thirdServerInfoGroupBox->setEnabled(true);
		ui->fourthServerInfoGroupBox->setEnabled(true);

		ui->firstServerPvmsNumComboBox->clear();
		ui->secondServerPvmsNumComboBox->clear();
		ui->thirdServerPvmsNumComboBox->clear();
		ui->fourthServerPvmsNumComboBox->clear();
		for(i = 0; i < 1; i++)
		{
			ui->firstServerPvmsNumComboBox->addItem(QString::number(i+1));
			ui->secondServerPvmsNumComboBox->addItem(QString::number(i+1));
			ui->thirdServerPvmsNumComboBox->addItem(QString::number(i+1));
			ui->fourthServerPvmsNumComboBox->addItem(QString::number(i+1));
		}
	}
}


