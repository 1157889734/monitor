#include "editTraintypeWidget.h"
#include "ui_editTraintypeWidget.h"
#include "state.h"
#include "debug.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QString>
#include <stdio.h>

QButtonGroup *g_groupSetButtonGroup = NULL;


editTraintypeWidget::editTraintypeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editTraintypeWidget)
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

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(closeWidgetSlot()));
    connect(ui->confirmPushButton, SIGNAL(clicked(bool)), this, SLOT(confirmSlot()));
    connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(cancleSlot()));
	connect(ui->serverNumComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(serverNumChangeSlot()));

	g_groupSetButtonGroup = new QButtonGroup();      //编组设置单选按钮组成一组，方便检测编组设置的选择
    g_groupSetButtonGroup->addButton(ui->groupSetRadioButton,1);
    g_groupSetButtonGroup->addButton(ui->groupSetRadioButton_2,2);
	connect(g_groupSetButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(groupSetChange(int)));     //单选按钮组按键信号连接响应槽函数

	ui->trainTypeNameLineEdit->installEventFilter(this);
	memset(&m_acTrainType, 0, sizeof(m_acTrainType));
}

editTraintypeWidget::~editTraintypeWidget()
{
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}
	delete g_groupSetButtonGroup;
	g_groupSetButtonGroup = NULL;
    delete ui;
}

void editTraintypeWidget::pageLoadSlot(char *pcTrainType)
{
	int iRet = 0, i = 0;
	T_TRAIN_CONFIG stTrainTypeConfig;
	if (NULL == pcTrainType)
	{	
		return;
	}
	ui->trainTypeNameLineEdit->setText(QString(QLatin1String(pcTrainType)));
	strncpy(m_acTrainType, pcTrainType, sizeof(m_acTrainType));

	iRet = STATE_GetTrainConfigInfo(pcTrainType, &stTrainTypeConfig);
	if (iRet < 0)
	{
		return;
	}
	if (1 == stTrainTypeConfig.iFormationType)
	{
        ui->groupSetRadioButton->setChecked(true);
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
	}
	else
	{
		ui->groupSetRadioButton_2->setChecked(true);
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
	}

	if (1 == stTrainTypeConfig.iNvrServerCount)
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

		ui->serverNumComboBox->setCurrentIndex(0);
		ui->firstServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iCarriageNO-1);
		ui->firstServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCameraNum-1);
		ui->firstServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCarriageNO-1);
	}
	else if (2 == stTrainTypeConfig.iNvrServerCount)
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
		ui->serverNumComboBox->setCurrentIndex(1);
		ui->firstServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iCarriageNO-1);
		ui->secondServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iCarriageNO-1);
		ui->firstServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCameraNum-1);
		ui->secondServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iPvmsCameraNum-1);
		ui->firstServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCarriageNO-1);
		ui->secondServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iPvmsCarriageNO-1);
	}
	else
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
		ui->serverNumComboBox->setCurrentIndex(2);
		ui->firstServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iCarriageNO-1);
		ui->secondServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iCarriageNO-1);
		ui->thirdServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[2].iCarriageNO-1);
		ui->fourthServerCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[3].iCarriageNO-1);
		ui->firstServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCameraNum-1);
		ui->secondServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iPvmsCameraNum-1);
		ui->thirdServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[2].iPvmsCameraNum-1);
		ui->fourthServerPvmsNumComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[3].iPvmsCameraNum-1);
		ui->firstServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[0].iPvmsCarriageNO-1);
		ui->secondServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[1].iPvmsCarriageNO-1);
		ui->thirdServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[2].iPvmsCarriageNO-1);
		ui->fourthServerPvmsCarNoComboBox->setCurrentIndex(stTrainTypeConfig.tNvrServerInfo[3].iPvmsCarriageNO-1);
	}
	

	this->show();
}


void editTraintypeWidget::closeWidgetSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}

void editTraintypeWidget::confirmSlot()
{
	char acLineStr[256] = {0};
	int i = 0, iLen = 0;
	T_TRAIN_CONFIG stTrainConfigInfo;
	T_TRAIN_TYPE_LIST stTrainTypeList;

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

	memset(&stTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
	for (i = 0; i < 4; i++)
	{
		stTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO -= i;	 
		stTrainConfigInfo.tNvrServerInfo[i].iCarriageNO -= i;    
	}
	stTrainConfigInfo.iNvrServerCount = atoi(ui->serverNumComboBox->currentText().toLatin1().data());

	if (1 == g_groupSetButtonGroup->checkedId())
	{
		stTrainConfigInfo.iFormationType = 1;
	}
	else if (2 == g_groupSetButtonGroup->checkedId())
	{
		stTrainConfigInfo.iFormationType = 2;
	}

	for (i = 0; i < stTrainConfigInfo.iNvrServerCount; i++)
	{
		if (0 == i)
		{
			stTrainConfigInfo.tNvrServerInfo[i].iCarriageNO = atoi(ui->firstServerCarNoComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum = atoi(ui->firstServerPvmsNumComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO = atoi(ui->firstServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}

		else if (1 == i)
		{
			stTrainConfigInfo.tNvrServerInfo[i].iCarriageNO = atoi(ui->secondServerCarNoComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum = atoi(ui->secondServerPvmsNumComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO = atoi(ui->secondServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
		else if (2 == i)
		{
			stTrainConfigInfo.tNvrServerInfo[i].iCarriageNO = atoi(ui->thirdServerCarNoComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum = atoi(ui->thirdServerPvmsNumComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO = atoi(ui->thirdServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
		else if (3 == i)
		{
			stTrainConfigInfo.tNvrServerInfo[i].iCarriageNO = atoi(ui->fourthServerCarNoComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum = atoi(ui->fourthServerPvmsNumComboBox->currentText().toLatin1().data());
			stTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO = atoi(ui->fourthServerPvmsCarNoComboBox->currentText().toLatin1().data());
		}
	}

	if (stTrainConfigInfo.tNvrServerInfo[0].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[1].iCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[0].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[2].iCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[0].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[1].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[2].iCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[1].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[2].iCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iCarriageNO)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "editTraintypeWidget can not set the same server carriageNo!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("不能设置相同的服务器车厢号!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}

	if (stTrainConfigInfo.tNvrServerInfo[0].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[1].iPvmsCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[0].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[2].iPvmsCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[0].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iPvmsCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[1].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[2].iPvmsCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[1].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iPvmsCarriageNO ||
		stTrainConfigInfo.tNvrServerInfo[2].iPvmsCarriageNO == stTrainConfigInfo.tNvrServerInfo[3].iPvmsCarriageNO)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "editTraintypeWidget can not set the same pvms carriageNo!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("不能设置相同的受电弓车厢号!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}
	
	STATE_SetTrainConfigInfo(m_acTrainType, stTrainConfigInfo);

	if (strcmp(m_acTrainType, ui->trainTypeNameLineEdit->text().toLatin1().data()))
	{
		memset(&stTrainTypeList, 0, sizeof(T_TRAIN_TYPE_LIST));
		STATE_GetTrainTypeList(&stTrainTypeList);
		for (i = 0; i < stTrainTypeList.iTypeNum; i++)
		{
			if (!strcmp(m_acTrainType, stTrainTypeList.acTrainTypeName[i]))
			{
				strncpy(stTrainTypeList.acTrainTypeName[i], ui->trainTypeNameLineEdit->text().toLatin1().data(), sizeof(stTrainTypeList.acTrainTypeName[i]));
				break;
			}
		}
		STATE_SetTrainTypeList(stTrainTypeList);

		STATE_SetCurrentTrainType(ui->trainTypeNameLineEdit->text().toLatin1().data());
		memset(acLineStr, 0, sizeof(acLineStr));
		snprintf(acLineStr, sizeof(acLineStr), "mv cfg/%s.ini cfg/%s.ini", m_acTrainType, ui->trainTypeNameLineEdit->text().toLatin1().data());
		system(acLineStr);
		system("sync");
	}

	QMessageBox msgBox(QMessageBox::Information,QString(tr("注意")),QString(tr("车型配置已修改，重启后生效!")));
	msgBox.setStandardButtons(QMessageBox::Yes);
	msgBox.button(QMessageBox::Yes)->setText("确 定");
	msgBox.exec();
	
	emit sendCloseMsg();
}

void editTraintypeWidget::cancleSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}

bool editTraintypeWidget::eventFilter(QObject *target, QEvent *event)
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
    }
        
    return QWidget::eventFilter(target, event);
}


void editTraintypeWidget::groupSetChange(int iComboBoxId)
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

void editTraintypeWidget::serverNumChangeSlot()
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

