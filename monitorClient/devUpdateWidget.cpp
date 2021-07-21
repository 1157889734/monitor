#include "devUpdateWidget.h"
#include "ui_devUpdateWidget.h"
#include "debug.h"
#include "log.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QTextCodec>
#include <QDebug>

#define NVR_RESTART_PORT 11001
QButtonGroup *g_buttonGroup1 = NULL, *g_buttonGroup2 = NULL, *g_buttonGroup3 = NULL;
devUpdateWidget *g_devUpdateThis = NULL;
static int g_iVNum = 0;
//static int CreateServerRebootTcpSocket(char *pcIpaddr, unsigned short u16Port);

char *parseFileNameFromPath(char *pcSrcStr)     //根据导入文件路径全名解析得到单纯的导入文件名
{
    char *pcTmp = NULL;

	if (NULL == pcSrcStr)
	{
		return NULL;
	}
	
    pcTmp = strrchr(pcSrcStr, '/');
    if (NULL == pcTmp)
    {
        return NULL;
    }

	if (NULL == (pcTmp+1))
	{
		return NULL;
	}
    return pcTmp+1;
}

devUpdateWidget::devUpdateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devUpdateWidget)
{
	char acTimeStr[128] = {0};
    QDateTime current_date_time ;
	
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);

    usermanagePage = new userManage(this);
	usermanagePage->setGeometry(245, 189, usermanagePage->width(), usermanagePage->height());
    usermanagePage->hide();

    connect(ui->permissonManagePushButton, SIGNAL(clicked(bool)), this, SLOT(userManageSlot()));
    connect(ui->configFileSelectionPushButton, SIGNAL(clicked(bool)), this, SLOT(configFileSelectionSlot()));
    connect(ui->configFileImportPushButton, SIGNAL(clicked(bool)), this, SLOT(configFileImportSlot()));
    connect(this->usermanagePage, SIGNAL(SendEscape()), this, SLOT(closeUserManageWidget()));

    g_buttonGroup1 = new QButtonGroup();      //轮询时间设置单选按钮组成一组，以保证改组中的单选框同时只能选一个，同时与以下其他类别的单选框之间互不影响
    g_buttonGroup1->addButton(ui->pollingTimeSetRadioButton,1);
    g_buttonGroup1->addButton(ui->pollingTimeSetRadioButton_2,2);
    g_buttonGroup1->addButton(ui->pollingTimeSetRadioButton_3,3);
    g_buttonGroup1->addButton(ui->pollingTimeSetRadioButton_4,4);

    g_buttonGroup2 = new QButtonGroup();     //预置点返回时间设置单选按钮组成一组，以保证改组中的单选框同时只能选一个，同时与其他类别的单选框之间互不影响
    g_buttonGroup2->addButton(ui->presetReturnTimeSetRadioButton,1);
    g_buttonGroup2->addButton(ui->presetReturnTimeSetRadioButton_2,2);
    g_buttonGroup2->addButton(ui->presetReturnTimeSetRadioButton_3,3);
    g_buttonGroup2->addButton(ui->presetReturnTimeSetRadioButton_4,4);

	g_buttonGroup3 = new QButtonGroup(); 
	g_buttonGroup3->addButton(ui->setManalTimeRadioButton,0);
    g_buttonGroup3->addButton(ui->setSysTimeRadioButton,1);

    connect(g_buttonGroup1, SIGNAL(buttonClicked(int)), this, SLOT(pollingTimeChange(int)));     //单选按钮组按键信号连接响应槽函数
    connect(g_buttonGroup2, SIGNAL(buttonClicked(int)), this, SLOT(presetReturnTimeChange(int)));
	connect(ui->timeAdjustPushButton, SIGNAL(clicked(bool)), this, SLOT(setSystemTime()));     //校时
	connect(ui->imageParamSetPushButton, SIGNAL(clicked(bool)), this, SLOT(setCameraImageParamSlot()));     //图像参数设置

	ui->pollingTimeSetLineEdit->setValidator(new QIntValidator(1,24*3600,this));   //只能输入1-24*3600的整数，不能输入字母或其他数字
	ui->presetReturnTimeSetLineEdit->setValidator(new QIntValidator(1,24*60,this));
	ui->brightnessLineEdit->setValidator(new QIntValidator(0,255,this));
	ui->saturationLineEdit->setValidator(new QIntValidator(0,255,this));
	ui->contrastLineEdit->setValidator(new QIntValidator(0,255,this));

    p_ipmethod= new commonInputMethod();   //新建一个输入法类
    if (p_ipmethod != NULL)
    {
		connect(p_ipmethod, SIGNAL(exit()), this, SLOT(inputWidgetExitSlot()));
		connect(p_ipmethod, SIGNAL(enter()), this, SLOT(inputWidgetEnterSlot()));
		QWSServer::setCurrentInputMethod(p_ipmethod);    //设置该输入法为当前系统使用的输入法
	    p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod); //新建输入法内部的键盘输入窗体
	    if (p_ipmethod->p_inputwidget != NULL)
	    {
			p_ipmethod->p_inputwidget->setGeometry(231, 270, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
		    p_ipmethod->p_inputwidget->hide();   //键盘默认隐藏
			p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
	    }
    }

	/*创建时间设置子窗体，默认隐藏*/
    timeSetWidget = new timeSet(this);
    timeSetWidget->hide();
	connect(timeSetWidget, SIGNAL(timeSetSendMsg(QString,QString,QString,QString,QString,QString)), this, SLOT(timeSetRecvMsg(QString,QString,QString,QString,QString,QString)));  //时间设置窗体控件设置信号响应
	connect(ui->timeSetPushButton, SIGNAL(clicked(bool)), this, SLOT(openTimeSetWidgetSlot()));
	
	localSetWidget = new localSet(this);     //新建本地设置窗体
	localSetWidget->setGeometry(245, 189, localSetWidget->width(), localSetWidget->height());  
	localSetWidget->hide();
    connect(this->localSetWidget, SIGNAL(closeWidgetSignal()), this, SLOT(closeLocalSetWidget()));
	connect(this->localSetWidget, SIGNAL(timeManuelSetSignal()), this, SLOT(timeManuelSetSlot()));

	localSetPasswdConfirmWidget = new LocalsetPasswdConfirm(this);    //新建本地设置密码确认窗体
	localSetPasswdConfirmWidget->setGeometry(300, 270, localSetPasswdConfirmWidget->width(), localSetPasswdConfirmWidget->height());  
	localSetPasswdConfirmWidget->hide();
    connect(this->localSetPasswdConfirmWidget, SIGNAL(sendCloseSignal()), this, SLOT(closeLocalSetPasswdConfirmWidget()));
	connect(this->localSetPasswdConfirmWidget, SIGNAL(sendOkSignal()), this, SLOT(localSetPasswdOkCtrl()));	

	/*将文本输入框加入事件过滤器，方便获取到点击事件并弹出软键盘*/
    ui->pollingTimeSetLineEdit->installEventFilter(this);
    ui->presetReturnTimeSetLineEdit->installEventFilter(this);
    ui->brightnessLineEdit->installEventFilter(this);
    ui->saturationLineEdit->installEventFilter(this);
    ui->contrastLineEdit->installEventFilter(this);

    connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(setBrightnessLineEditValue(int)));
    connect(ui->saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(setSaturationLineEditValue(int)));
    connect(ui->contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(setContrastLineEditValue(int)));
    connect(ui->trainTypeSetPushButton, SIGNAL(clicked(bool)), this, SLOT(setTrainType()));
    connect(ui->localSetPushButton, SIGNAL(clicked(bool)), this, SLOT(devLocalSetSlot()));
	connect(ui->updateBeginPushButton, SIGNAL(clicked(bool)), this, SLOT(devUpdateSlot()));
	connect(ui->clientRebootPushButton, SIGNAL(clicked(bool)), this, SLOT(devRebootSlot()));
	//connect(ui->serverRebootPushButton, SIGNAL(clicked(bool)), this, SLOT(serverRebootSlot()));
	connect(ui->alarmPushButton, SIGNAL(clicked(bool)), this, SLOT(alarmPushButoonClickSlot()));   //报警按钮按键信号响应打开报警信息界面

	ui->alarmPushButton->setFocusPolicy(Qt::NoFocus);
		
	m_alarmHappenTimer = NULL;
	m_TrainType = "";
	m_pollingtTimeText = "";
	m_presetReturnTimeText = "";
	m_brightNessText = "128";
	m_saturationText = "128";
	m_contrastText = "128";
    setTrainTypeCombox();
    getTrainConfig();//获取车型配置信息，填充页面
    setPollingTimeRadioButton();  //设置轮询时间单选按钮组的样式
	setPresetReturnTimeRadioButton(); //设置预置点返回时间单选按钮组的样式
	
    current_date_time = QDateTime::currentDateTime();
	snprintf(acTimeStr, sizeof(acTimeStr), "%4d-%02d-%02d %02d:%02d:%02d", current_date_time.date().year(), current_date_time.date().month(), current_date_time.date().day(), current_date_time.time().hour(), current_date_time.time().minute(), current_date_time.time().second());
    ui->timeSetLineEdit->setText(QString(QLatin1String(acTimeStr)));

	g_devUpdateThis = this;
}

devUpdateWidget::~devUpdateWidget()
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "delete ~devUpdateWidget\n");
	
	if (usermanagePage != NULL)
	{
		delete usermanagePage;
		usermanagePage = NULL;
	}
	if (localSetWidget != NULL)
	{
		delete localSetWidget;
		localSetWidget = NULL;
	}
	if (localSetPasswdConfirmWidget != NULL)
	{
		delete localSetPasswdConfirmWidget;
		localSetPasswdConfirmWidget = NULL;
	}
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}
	delete g_buttonGroup1;
	g_buttonGroup1 = NULL;
	delete g_buttonGroup2;
	g_buttonGroup2 = NULL;
	delete g_buttonGroup3;
	g_buttonGroup3 = NULL;
	delete timeSetWidget;
	timeSetWidget = NULL;
    delete ui;
}

void devUpdateWidget::alarmPushButoonClickSlot()  //点击报警按钮的响应函数，删除报警定时器并恢复按钮为正常不闪烁样式
{
	emit alarmPushButoonClickSignal();
	if (m_alarmHappenTimer != NULL)
	{
		delete m_alarmHappenTimer;
		m_alarmHappenTimer = NULL;
	}
	ui->alarmPushButton->setChecked(false);

	g_iVNum = 0;
}

void devUpdateWidget::alarmHappenCtrlSlot()    //报警触发定时器处理函数，间隔的切换按钮样式，达到闪烁效果
{
	if (this->isHidden() != 1)
	{
		if (0 == g_iVNum%2)
		{
			ui->alarmPushButton->setChecked(true);
		}
		else
		{
			ui->alarmPushButton->setChecked(false);
		}
		g_iVNum++;
	}
}

void devUpdateWidget::alarmHappenSlot()    //报警触发的响应函数
{
	if (NULL == m_alarmHappenTimer)    //启动一个定时器，每500毫秒切换按钮样式，达到闪烁效果
	{
		m_alarmHappenTimer = new QTimer(this);
		connect(m_alarmHappenTimer,SIGNAL(timeout()), this,SLOT(alarmHappenCtrlSlot())); 
		m_alarmHappenTimer->start(500);
	}	
}

void devUpdateWidget::alarmClearSlot()     //报警清除的响应函数，删除报警定时器并恢复按钮为正常不闪烁样式
{
	if (m_alarmHappenTimer != NULL)
	{
		delete m_alarmHappenTimer;
		m_alarmHappenTimer = NULL;
	}
	ui->alarmPushButton->setChecked(false);

	g_iVNum = 0;
}


void devUpdateWidget::getTrainConfig()
{
    int i = 0;
    QString item = "";
	
    ui->carriageSelectionComboBox->setCurrentIndex(-1);
    ui->carriageSelectionComboBox->clear();

	char acTrainType[16] = {0};
	T_TRAIN_CONFIG tTrainConfigInfo;
	memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
	STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
	STATE_GetCurrentTrainType(acTrainType, sizeof(acTrainType));
	
	for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
	{
        item = "";
        item = QString::number(tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO);
        item += tr("号车厢");
        ui->carriageSelectionComboBox->addItem(item);
		m_Phandle[i] = STATE_GetNvrServerPmsgHandle(i);
	}
	
	for (i = 0; i < ui->trainTypeSetComboBox->count(); i++)
	{
		if (ui->trainTypeSetComboBox->itemText(i) == QString(QLatin1String(acTrainType)))
		{
			ui->trainTypeSetComboBox->setCurrentIndex(i);
			m_TrainType = ui->trainTypeSetComboBox->currentText();
			break;
		}
	}
}

void devUpdateWidget::setTrainType()
{
	char acUserType[16] = {0}, acTrainType[128] = {0};
	int iRet = 0;
	T_LOG_INFO tLogInfo;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget trainTypeSet button pressed!\n");
	
	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))   //操作员不能设置车型
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to set train type!\n");
		QMessageBox box(QMessageBox::Warning,QString::fromUtf8("提示"),QString::fromUtf8("无权限设置!"));     //新建消息提示框，提示错误信息
	    box.setStandardButtons (QMessageBox::Ok);   //设置提示框只有一个标准按钮
	    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     //将按钮显示改成"确 定"
	    box.exec();
	}
	else
	{
	    if (m_TrainType != ui->trainTypeSetComboBox->currentText())   //只有当车型选择被改变才进行设置
	    {
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget set train type will reboot client, confirm?\n");
	        QMessageBox msgBox(QMessageBox::Question,QString(tr("提示")),QString(tr("将重启使车型设置生效，是否继续？")));
	        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.button(QMessageBox::No)->setText("取 消");
	        iRet=msgBox.exec();
	        if(iRet != QMessageBox::Yes)
	        {
	            return;
	        }
			snprintf(acTrainType, sizeof(acTrainType), "%s", ui->trainTypeSetComboBox->currentText().toLatin1().data());
	        STATE_SetCurrentTrainType(acTrainType);
			DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] set currernt traintype to %s\n", __FUNCTION__, acTrainType);
		
			memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
			tLogInfo.iLogType = 0;
			snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "change traintype to %s and monitor Client reboot!", acTrainType);
			LOG_WriteLog(&tLogInfo);

	        QApplication *app;
	        app->exit();
	    }
	}
}

void devUpdateWidget::setTrainTypeCombox()     //读取系统配置文件，获取系统当前设置的车型，以使得车型设置下拉框显示的是当前系统车型
{
	T_TRAIN_TYPE_LIST tTrainTypeList;
	int iRet = 0, i = 0;
	
	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
	if (iRet < 0)
	{
		return;
	}
	
	for(i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
	}
}

void devUpdateWidget::setPollingTimeRadioButton()     //获取轮询时间，设置轮询时间单选按钮组的样式
{
	int iPollingTime = 0;
	iPollingTime = STATE_GetPollingTime();

	ui->pollingTimeSetLineEdit->setText(QString::number(iPollingTime));
	m_pollingtTimeText = ui->pollingTimeSetLineEdit->text();
	
	if (10 == iPollingTime)   //轮询时间为10秒，则第一个表示10秒的RadioButton被选中
	{
		ui->pollingTimeSetRadioButton->setChecked(true);
		ui->pollingTimeSetLineEdit->setReadOnly(true);
	}
	else if (20 == iPollingTime)
	{
		ui->pollingTimeSetRadioButton_2->setChecked(true);
		ui->pollingTimeSetLineEdit->setReadOnly(true);
	}
	else if (30 == iPollingTime)
	{
		ui->pollingTimeSetRadioButton_3->setChecked(true);
		ui->pollingTimeSetLineEdit->setReadOnly(true);
	}
	else
	{
		ui->pollingTimeSetRadioButton_4->setChecked(true);
		ui->pollingTimeSetLineEdit->setReadOnly(false);
	}
}

void devUpdateWidget::setPresetReturnTimeRadioButton()     //获取预置点返回时间，设置预置点返回时间单选按钮组的样式
{
	int iReturnTime = 0;
	iReturnTime = STATE_GetPresetReturnTime();

	ui->presetReturnTimeSetLineEdit->setText(QString::number(iReturnTime));
	m_presetReturnTimeText = ui->presetReturnTimeSetLineEdit->text();
	
	if (5 == iReturnTime)   //预置点返回时间为5分钟，则第一个表示5分钟的RadioButton被选中
	{
		ui->presetReturnTimeSetRadioButton->setChecked(true);
		ui->presetReturnTimeSetLineEdit->setReadOnly(true);
	}
	else if (10 == iReturnTime)
	{
		ui->presetReturnTimeSetRadioButton_2->setChecked(true);
		ui->presetReturnTimeSetLineEdit->setReadOnly(true);
	}
	else if (15 == iReturnTime)
	{
		ui->presetReturnTimeSetRadioButton_3->setChecked(true);
		ui->presetReturnTimeSetLineEdit->setReadOnly(true);
	}
	else
	{
		ui->presetReturnTimeSetRadioButton_4->setChecked(true);
		ui->presetReturnTimeSetLineEdit->setReadOnly(false);
	}
}

void devUpdateWidget::userManageSlot()  //点击用户管理按钮响应函数，弹出用户管理界面
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget userManage set button pressed!\n");

	if (usermanagePage == NULL)
    {
        usermanagePage = new userManage(this);
		usermanagePage->setGeometry(245, 189, usermanagePage->width(), usermanagePage->height());
        usermanagePage->show();
        connect(usermanagePage, SIGNAL(SendEscape()), this, SLOT(closeUserManageWidget()));
    }
	else
	{
		usermanagePage->show();
	}
}

void devUpdateWidget::configFileSelectionSlot()
{
	QString filename = "";
	char acUserType[64] = {0};
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget configFileSelection button pressed!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to select config file!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
		if (access("/mnt/usb/u/", F_OK) < 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget::%s %d not get USB device!\n",__FUNCTION__,__LINE__);
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			ui->clientRebootPushButton->setEnabled(true);
			return;
		}
		else
		{
			if (0 == STATE_FindUsbDev())   //这里处理一个特殊情况:U盘拔掉时umount失败，/mnt/usb/u/路径还存在，但是实际U盘是没有再插上的
			{
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget::%s %d not get USB device!\n",__FUNCTION__,__LINE__);
				QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
				msgBox.setStandardButtons(QMessageBox::Yes);
				msgBox.button(QMessageBox::Yes)->setText("确 定");
				msgBox.exec();
				ui->clientRebootPushButton->setEnabled(true);
		        return;
			}
		}

		if (STATE_ParseUsbLicense("/mnt/usb/u/") < 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget configFileSelection check License error!\n");
			QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("授权失败!"));     
		    box.setStandardButtons (QMessageBox::Ok);   
		    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
		    box.exec();
			return;
		}
	
		filename = QFileDialog::getOpenFileName(this, "打开文件", "/mnt/usb/u/", "ini文件(*.ini)");
	    if (!filename.isNull())
	    {
			//QMessageBox::information(this, "Document", "Has document", QMessageBox::Ok | QMessageBox::Cancel);
			ui->configFileDisplayLineEdit->setText(filename);
	    }
	}
}

void devUpdateWidget::configFileImportSlot()
{
	int iRet = 0;
	char *pcfileName = NULL;
	char acUserType[64] = {0};
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget configFileImport button pressed!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to import config file!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
		if (0 == strlen(ui->configFileDisplayLineEdit->text().toLatin1().data()))
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not select any config file!\n");
	        QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("请选择配置文件")));
	        msgBox.setStandardButtons(QMessageBox::Yes);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.exec();
			return;
		}
				
		pcfileName = parseFileNameFromPath(ui->configFileDisplayLineEdit->text().toLatin1().data());
		if (NULL == pcfileName)
		{
			return;
		}

		if (strncmp(pcfileName, "Station.ini", strlen(pcfileName)) != 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget select error config file!\n");
	        QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("配置文件选择错误")));
	        msgBox.setStandardButtons(QMessageBox::Yes);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.exec();
			return;
		}

		QMessageBox msgBox(QMessageBox::Question,QString(tr("提示")),QString(tr("确认导入配置文件？")));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.button(QMessageBox::No)->setText("取 消");
        iRet=msgBox.exec();
        if(iRet != QMessageBox::Yes)
        {
            return;
        }
		
		system("cp /mnt/usb/u/Station.ini /home/data/emuVideoMornitorClient/Station.ini");
		system("sync");

		QMessageBox msgBox2(QMessageBox::Information,QString(tr("注意")),QString(tr("导入成功，请拔出U盘!")));
		msgBox2.setStandardButtons(QMessageBox::Yes);
		msgBox2.button(QMessageBox::Yes)->setText("确 定");
		msgBox2.exec();
		return;
	}
}

void devUpdateWidget::closeUserManageWidget()
{
    if(NULL==this->usermanagePage)
    {
        return;
    }
    else
    {
        delete this->usermanagePage;
    }
    this->usermanagePage=NULL;
}

void devUpdateWidget::closeLocalSetPasswdConfirmWidget()
{
    if(NULL==localSetPasswdConfirmWidget)
    {
        return;
    }
    else
    {
        delete localSetPasswdConfirmWidget;
    }
    localSetPasswdConfirmWidget=NULL;
}

void devUpdateWidget::closeLocalSetWidget()
{
	//T_TRAIN_TYPE_LIST tTrainTypeList;
	//int iRet = 0, i = 0;
	//char acTrainType[16] = {0};
    if(NULL==localSetWidget)
    {
        return;
    }
    else
    {
        delete localSetWidget;
    }
    localSetWidget=NULL;

	/*
	ui->trainTypeSetComboBox->clear();
	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
	if (iRet < 0)
	{
		return;
	}
	for(i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
	}

	STATE_GetCurrentTrainType(acTrainType, sizeof(acTrainType));
	for (i = 0; i < ui->trainTypeSetComboBox->count(); i++)
	{
		if (ui->trainTypeSetComboBox->itemText(i) == QString(QLatin1String(acTrainType)))
		{
			ui->trainTypeSetComboBox->setCurrentIndex(i);
			m_TrainType = ui->trainTypeSetComboBox->currentText();
			break;
		}
	}
	*/
}

void devUpdateWidget::timeManuelSetSlot()
{
	emit systimeSetSignal();
}	

bool devUpdateWidget::eventFilter(QObject *target, QEvent *event)
{
    if (((target == ui->pollingTimeSetLineEdit) && (event->type() == QEvent::MouseButtonPress) && (false == ui->pollingTimeSetLineEdit->isReadOnly())) || 
		((target == ui->presetReturnTimeSetLineEdit) && (event->type() == QEvent::MouseButtonPress) && (false == ui->presetReturnTimeSetLineEdit->isReadOnly())) ||
		(((target == ui->brightnessLineEdit) || (target == ui->saturationLineEdit) || (target == ui->contrastLineEdit))&& (event->type() == QEvent::MouseButtonPress)))
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
			p_ipmethod->p_inputwidget->setGeometry(231, 270, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
            p_ipmethod->p_inputwidget->show();
        }
    }
    return QWidget::eventFilter(target, event);
}

void devUpdateWidget::setBrightnessLineEditValue(int value)
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set brightness to %d!\n", __FUNCTION__, value);
	#if 1
	float fBrightness = 0.00;
	int iBrightness = 0;
	fBrightness = 2.55 * value;
	iBrightness = (int)fBrightness;
	#else
	int iBrightness = 0;
	iBrightness = value;
	#endif
	
    ui->brightnessLineEdit->setText(QString::number(iBrightness));
	m_brightNessText = ui->brightnessLineEdit->text();
}

void devUpdateWidget::setSaturationLineEditValue(int value)
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set saturation to %d!\n", __FUNCTION__, value);
	#if 1
	float fSaturation = 0.00;
	int iSaturation = 0;
	fSaturation = 2.55 * value;
	iSaturation = (int)fSaturation;
	#else
	int iSaturation = 0;
	iSaturation = value;
	#endif
    ui->saturationLineEdit->setText(QString::number(iSaturation));
	m_saturationText = ui->saturationLineEdit->text();
}

void devUpdateWidget::setContrastLineEditValue(int value)
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set contrast to %d!\n", __FUNCTION__, value);
	#if 1
	float fContrast = 0.00;
	int iContrast = 0;
	fContrast = 2.55 * value;
	iContrast = (int)fContrast;
	#else
	int iContrast = 0;
	iContrast = value;
	#endif
    ui->contrastLineEdit->setText(QString::number(iContrast));
	m_contrastText = ui->contrastLineEdit->text();
}

void devUpdateWidget::pollingTimeChange(int iComboBoxId)     
{
	static int iOldId = 0;
	if (iComboBoxId != iOldId)
	{
		switch (iComboBoxId) //根据单选按钮组按键信号传入的单选按钮编号区分不同的单选按钮，做出不同的设置
		{
			case 1:
			{
				ui->pollingTimeSetLineEdit->setReadOnly(true);   //非自定义单选按钮被选中时，轮询时间设置输入框设置为只读
        		ui->pollingTimeSetLineEdit->setText("10");  
				break;
			}
			case 2:
			{
				ui->pollingTimeSetLineEdit->setReadOnly(true);
        		ui->pollingTimeSetLineEdit->setText("20");
				break;
			}
			case 3:
			{
				ui->pollingTimeSetLineEdit->setReadOnly(true);
        		ui->pollingTimeSetLineEdit->setText("30");
				break;
			}
			case 4:
			{
				ui->pollingTimeSetLineEdit->setReadOnly(false);    //自定义单选按钮被选中时，轮询时间设置输入框设置为可读写
				break;
			}
			default:
				break;
		}
		iOldId = iComboBoxId;
	}
	m_pollingtTimeText = ui->pollingTimeSetLineEdit->text();
}

void devUpdateWidget::presetReturnTimeChange(int iComboBoxId)
{
	static int iOldId = 0;
	if (iComboBoxId != iOldId)
	{
        switch (iComboBoxId)  //根据单选按钮组按键信号传入的单选按钮编号区分不同的单选按钮，做出不同的设
        {
			case 1:
			{
				ui->presetReturnTimeSetLineEdit->setReadOnly(true);    //非自定义单选按钮被选中时，预置点返回时间设置输入框设置为只读
        		ui->presetReturnTimeSetLineEdit->setText("5");
				break;
			}
			case 2:
			{
				ui->presetReturnTimeSetLineEdit->setReadOnly(true);
        		ui->presetReturnTimeSetLineEdit->setText("10");
				break;
			}
			case 3:
			{
				ui->presetReturnTimeSetLineEdit->setReadOnly(true);
        		ui->presetReturnTimeSetLineEdit->setText("15");
				break;
			}
			case 4:
			{
				ui->presetReturnTimeSetLineEdit->setReadOnly(false);   //自定义单选按钮被选中时，预置点返回时间设置输入框设置为可读写
				break;
			}
			default:
				break;
		}
		iOldId = iComboBoxId;
	}
	m_presetReturnTimeText = ui->presetReturnTimeSetLineEdit->text();
}

void devUpdateWidget::setSystemTime()
{
	char acUserType[64] = {0};
	int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, i = 0, iRet = 0;
	short yr = 0;
	char acTimeStr[256] = {0};
	T_TIME_INFO tTimeInfo;
	T_TRAIN_CONFIG tTrainConfigInfo;
	T_LOG_INFO tLogInfo;
	
	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget set sys time!\n");
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to set system time!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
        if (0 == g_buttonGroup3->checkedId())
        {
            DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget set rtc time!");
            DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] timeStr:%s\n", __FUNCTION__, ui->timeSetLineEdit->text().toLatin1().data());
			if (strlen(ui->timeSetLineEdit->text().toLatin1().data()) > 0)
			{
				sscanf(ui->timeSetLineEdit->text().toLatin1().data(), "%4d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &minute, &second);
			}
			DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] set time(%d-%d-%d %d:%d:%d)\n", __FUNCTION__, year, month, day, hour, minute, second);
            snprintf(acTimeStr, sizeof(acTimeStr), "rtc.exe -s \"%4d-%02d-%02d %02d:%02d:%02d\"", year, month, day, hour, minute, second);
            system(acTimeStr);
            system("rtc.exe -i");

            /*系统校时记录日志*/
            memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
            tLogInfo.iLogType = 0;
            snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "set local time %4d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
            LOG_WriteLog(&tLogInfo);

            ui->sysTimeAdjustLabel->setText(ui->timeSetLineEdit->text());
			emit systimeSetSignal();
        }
        else
        {
        	if (strlen(ui->sysTimeAdjustLabel->text().toLatin1().data()) > 0)
			{
				sscanf(ui->sysTimeAdjustLabel->text().toLatin1().data(), "%4d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &minute, &second);
						DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] set time(%d-%d-%d %d:%d:%d)\n", __FUNCTION__, year, month, day, hour, minute, second);
        	}
		}
		
		if (year >= 1970 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31) && 
			(hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) && (second >= 0 && second <= 59))
		{
			memset(&tTimeInfo, 0, sizeof(T_TIME_INFO));
			yr = year;
			tTimeInfo.year = htons(yr);
			tTimeInfo.mon = month;
			tTimeInfo.day = day;
			tTimeInfo.hour = hour;
			tTimeInfo.min = minute;
			tTimeInfo.sec = second;
			memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
			STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
			//printf("%d-%d-%d %d:%d:%d\n",timeInfo.year, (int)timeInfo.mon, (int)timeInfo.day, (int)timeInfo.hour, (int)timeInfo.min, (int)timeInfo.sec);
			for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
			{
				iRet = PMSG_SendPmsgData(m_Phandle[i], CLI_SERV_MSG_TYPE_CHECK_TIME, (char *)&tTimeInfo, sizeof(T_TIME_INFO));    //发送校时命令
				if (iRet < 0)
				{
					DebugPrint(DEBUG_UI_ERROR_PRINT, "PMSG_SendPmsgData CLI_SERV_MSG_TYPE_CHECK_TIME error!iRet=%d\n",iRet);
				}
				else
				{
					memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
					tLogInfo.iLogType = 0;
					snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "notify server %d Time Check OK, %4d-%02d-%02d %02d:%02d:%02d!", 100+tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO, year, month, day, hour, minute, second);
					LOG_WriteLog(&tLogInfo);

					QMessageBox box(QMessageBox::Information,QString::fromUtf8("注意"),QString::fromUtf8("校时成功!"));   
				    box.setStandardButtons (QMessageBox::Ok);   
				    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));    
				    box.exec();
				}
			}
		}
	}
}

void devUpdateWidget::inputWidgetExitSlot()
{
	int iTime = 0;
	
	if (true == ui->pollingTimeSetLineEdit->hasFocus())
	{
		iTime = atoi(m_pollingtTimeText.toLatin1().data());
		ui->pollingTimeSetLineEdit->setText(QString::number(iTime));
		STATE_SetPollingTime(iTime);
	}
	else if (true == ui->presetReturnTimeSetLineEdit->hasFocus())
	{
		iTime = atoi(m_presetReturnTimeText.toLatin1().data());
		ui->presetReturnTimeSetLineEdit->setText(QString::number(iTime));
		STATE_SetPresetReturnTime(iTime);
	}
	else if (true == ui->brightnessLineEdit->hasFocus())
	{
		ui->brightnessLineEdit->setText(m_brightNessText);
	}
	else if (true == ui->saturationLineEdit->hasFocus())
	{
		ui->saturationLineEdit->setText(m_saturationText);
	}
	else if (true == ui->contrastLineEdit->hasFocus())
	{
		ui->contrastLineEdit->setText(m_contrastText);
	}
}

void devUpdateWidget::inputWidgetEnterSlot()
{
	float fValue = 0.00;
	int iValue = 0;

	if (true == ui->pollingTimeSetLineEdit->hasFocus())
	{
		iValue = atoi(ui->pollingTimeSetLineEdit->text().toLatin1().data());

		DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set polling time to %d!\n",  __FUNCTION__, iValue);
		if (iValue <= 0)
		{
			iValue = atoi(m_pollingtTimeText.toLatin1().data());
			ui->pollingTimeSetLineEdit->setText(QString::number(iValue));
			return;
		}
		STATE_SetPollingTime(iValue);
		m_pollingtTimeText = ui->pollingTimeSetLineEdit->text();
	}
	else if (true == ui->presetReturnTimeSetLineEdit->hasFocus())
	{
		iValue = atoi(ui->presetReturnTimeSetLineEdit->text().toLatin1().data());
	
		DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s] devUpdateWidget set presetReturn time to %d!\n",  __FUNCTION__, iValue);

		if (iValue <= 0)
		{
			iValue = atoi(m_presetReturnTimeText.toLatin1().data());
			ui->presetReturnTimeSetLineEdit->setText(QString::number(iValue));
			return;
		}
		STATE_SetPresetReturnTime(iValue);
		m_presetReturnTimeText = ui->presetReturnTimeSetLineEdit->text();
	}
	else if (true == ui->brightnessLineEdit->hasFocus())
	{
		fValue = ui->brightnessLineEdit->text().toInt()/2.55;
		iValue = (int)fValue;
		DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set brightness to %d!\n", __FUNCTION__, iValue);

		if (iValue < 0)
		{
			iValue = atoi(m_brightNessText.toLatin1().data());
			ui->brightnessLineEdit->setText(QString::number(iValue));
			return;
		}
		disconnect(ui->brightnessSlider, SIGNAL(valueChanged(int)), 0, 0);   //设置滑动条之前先把滑动条的信号槽连接断掉，不让滑动条再设置LineEdit的值，以免因为误差再次改变LineEdit的值

		ui->brightnessSlider->setValue(iValue);
		connect(ui->brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(setBrightnessLineEditValue(int)));   //设置外之后恢复滑动条的信号槽连接
		
		m_brightNessText = ui->brightnessLineEdit->text();
	}
	else if (true == ui->saturationLineEdit->hasFocus())
	{
		fValue = ui->saturationLineEdit->text().toInt()/2.55;
		iValue = (int)fValue;
		DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set saturation to %d!\n", __FUNCTION__, iValue);

		if (iValue < 0)
		{
			iValue = atoi(m_saturationText.toLatin1().data());
			ui->saturationLineEdit->setText(QString::number(iValue));
			return;
		}
		disconnect(ui->saturationSlider, SIGNAL(valueChanged(int)), 0, 0);

		ui->saturationSlider->setValue(iValue);
		connect(ui->saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(setSaturationLineEditValue(int)));
		m_saturationText = ui->saturationLineEdit->text();
	}
	else if (true == ui->contrastLineEdit->hasFocus())
	{
		fValue = ui->contrastLineEdit->text().toInt()/2.55;
		iValue = (int)fValue;
		DebugPrint(DEBUG_UI_OPTION_PRINT, "[%s]devUpdateWidget set contrast to %d!\n", __FUNCTION__, iValue);

		if (iValue < 0)
		{
			iValue = atoi(m_contrastText.toLatin1().data());
			ui->contrastLineEdit->setText(QString::number(iValue));
			return;
		}
		disconnect(ui->contrastSlider, SIGNAL(valueChanged(int)), 0, 0);

		ui->contrastSlider->setValue(iValue);
		connect(ui->contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(setContrastLineEditValue(int)));
		m_contrastText = ui->contrastLineEdit->text();
	}
}


void devUpdateWidget::setCameraImageParamSlot()
{	
	int idex = 0, iRet = 0;
	char acUserType[64] = {0};
	T_PIC_ATTRIBUTE picParam;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget set camera image param!\n");
	
	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to set CameraImage Param!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
	    idex = ui->carriageSelectionComboBox->currentIndex();
		if (idex < 0)
		{
			return;
		}
			
		memset(&picParam, 0, sizeof(T_PIC_ATTRIBUTE));  
		picParam.iBrightness = ui->brightnessSlider->value();
		picParam.iSaturation = ui->saturationSlider->value();
		picParam.iContrast = ui->contrastSlider->value();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] send server%d's camera image param:(%d,%d,%d)\n", __FUNCTION__, idex+1, (int)picParam.iBrightness, (int)picParam.iSaturation, (int)picParam.iContrast);

		iRet = PMSG_SendPmsgData(m_Phandle[idex], CLI_SERV_MSG_TYPE_SET_PIC_ATTRIBUTE, (char *)&picParam, sizeof(T_PIC_ATTRIBUTE));    //发送设置图像效果参数命令
	    if (iRet < 0)
	    {
			DebugPrint(DEBUG_UI_ERROR_PRINT, "[%s] PMSG_SendPmsgData CLI_SERV_MSG_TYPE_SET_PIC_ATTRIBUTE error!iRet=%d,server=%d\n", __FUNCTION__, iRet, idex+1);
	    }
		QMessageBox box(QMessageBox::Information,QString::fromUtf8("注意"),QString::fromUtf8("图像参数设置成功!"));   
	    box.setStandardButtons (QMessageBox::Ok);   
	    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));    
	    box.exec();
	}
}

void devUpdateWidget::devUpdateSlot()
{
	int iRet = 0;
	char acLocalVersion[32] = {0}, acUpdateVersion[32] = {0};
	FILE *fp = NULL;
	char acUserType[64] = {0};
	T_LOG_INFO tLogInfo;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget update device!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to update device!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));   //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
		ui->updateStatueTextEdit->clear();
		ui->clientRebootPushButton->setEnabled(false);    //更新开始，设置重启按钮不可操作
			
		if (access("/mnt/usb/u/", F_OK) < 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget::%s %d not get USB device!\n",__FUNCTION__,__LINE__);
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
		    msgBox.setStandardButtons(QMessageBox::Yes);
		    msgBox.button(QMessageBox::Yes)->setText("确 定");
		    msgBox.exec();
			ui->clientRebootPushButton->setEnabled(true);
		    return;
		}
		else
		{
			if (0 == STATE_FindUsbDev())   //这里处理一个特殊情况:U盘拔掉时umount失败，/mnt/usb/u/路径还存在，但是实际U盘是没有再插上的
			{
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget::%s %d not get USB device!\n",__FUNCTION__,__LINE__);
				QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
				msgBox.setStandardButtons(QMessageBox::Yes);
				msgBox.button(QMessageBox::Yes)->setText("确 定");
				msgBox.exec();
				ui->clientRebootPushButton->setEnabled(true);
		        return;
			}
		}

		if (STATE_ParseUsbLicense("/mnt/usb/u/") < 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget update check License error!\n");
			QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("授权失败!"));     
		    box.setStandardButtons (QMessageBox::Ok);   
		    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
		    box.exec();
			return;
		}

		ui->updateStatueTextEdit->append(tr("发现USB，已准备好"));

		if ((access("/mnt/usb/u/mornitorapp.exe", F_OK) < 0) || (access("/mnt/usb/u/version.ini", F_OK) < 0))
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not find update file in USB device!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("U盘中未检测更新文件!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			ui->clientRebootPushButton->setEnabled(true);
			return;
		}

		fp = fopen("/mnt/usb/u/version.ini","rb");
		if (NULL == fp)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget open update file fail in USB device!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("U盘文件读取出错!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			ui->clientRebootPushButton->setEnabled(true);
			return;
		}
		iRet = fread(acUpdateVersion, 1, sizeof(acUpdateVersion), fp);
		if (iRet <= 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget read update file fail in USB device!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("U盘文件读取出错!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			fclose(fp);
			ui->clientRebootPushButton->setEnabled(true);
			return;
		}
		fclose(fp);

		STATE_GetSysVersion(acLocalVersion, sizeof(acLocalVersion));
		if (strlen(acLocalVersion) <= 0)
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget update file fail, can't get app version!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("升级失败，本地版本号获取失败!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
		}
		
		if (!strcmp(acLocalVersion, acUpdateVersion))
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget update file fail,update version is the same as the running app version!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到版本更新!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			ui->clientRebootPushButton->setEnabled(true);  
			return;
		}

		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "Update: old version:%s new version:%s", acLocalVersion, acUpdateVersion);
		LOG_WriteLog(&tLogInfo);
		
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] update device from version:%s to version:%s\n", __FUNCTION__, acLocalVersion, acUpdateVersion);
			
		ui->updateStatueTextEdit->append(tr("正在复制文件..."));

		if (access("/home/data/backup", F_OK) < 0)    
		{
			system("mkdir /home/data/backup");
		}

		system("cp /mnt/usb/u/mornitorapp.exe /home/data/emuVideoMornitorClient/mornitorapp.exe");
		system("sync");
	
		ui->updateStatueTextEdit->append(tr("复制文件完成"));
		ui->updateStatueTextEdit->append(tr("更新完成，请重启!"));
		ui->clientRebootPushButton->setEnabled(true);    //更新完成，恢复重启按钮可操作
	}
}

void devUpdateWidget::devRebootSlot()
{
	char acUserType[64] = {0};
	T_LOG_INFO tLogInfo;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget client reboot!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to reboot client!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "monitor Client reboot!");
		LOG_WriteLog(&tLogInfo);
			
		QApplication *app;
		app->exit();
	}
}

/*
void devUpdateWidget::serverRebootSlot()
{
	char acUserType[64] = {0}, acIpAddr[128] = {0}, acSendBuf[4] = {0};
	int iServerDex = 0, iRet = 0, iSockFd = 0;
	unsigned short sLen = 2, sMsgLen = 0;
	T_TRAIN_CONFIG tTrainConfigInfo;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget server reboot!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to reboot server!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}

	iServerDex = ui->devSelectionComboBox->currentIndex();
	if (iServerDex < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not select any nvr server!\n");
        QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("请选择相关服务器")));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.exec();
		return;
	}

	QMessageBox msgBox(QMessageBox::Question,QString(tr("提示")),QString(tr("确认重启服务器？")));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.button(QMessageBox::Yes)->setText("确 定");
    msgBox.button(QMessageBox::No)->setText("取 消");
    iRet=msgBox.exec();
    if(iRet != QMessageBox::Yes)
    {
        return;
    }
	
	memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
	STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
	snprintf(acIpAddr, sizeof(acIpAddr), "192.168.%d.81", tTrainConfigInfo.tNvrServerInfo[iServerDex].iCarriageNO+100);
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "devUpdateWidget reboot server ip:%s!\n",acIpAddr);

	iSockFd = CreateServerRebootTcpSocket(acIpAddr, NVR_RESTART_PORT);
	if (iSockFd > 0)
	{
		sMsgLen = htons(sLen);
		acSendBuf[0] = 0xFF;
		acSendBuf[1] = 0x08;
		memcpy(&acSendBuf[3], &sMsgLen, sizeof(sMsgLen));
		if (send(iSockFd, acSendBuf, sizeof(acSendBuf), 0) > 0)
		{
			QMessageBox msgBox(QMessageBox::Information,QString(tr("注意")),QString(tr("重启成功")));
	        msgBox.setStandardButtons(QMessageBox::Yes);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.exec();
			return;
		}
		else
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget:%s %d server reboot fail!\n",__FUNCTION__,__LINE__);
	        QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("重启失败")));
	        msgBox.setStandardButtons(QMessageBox::Yes);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.exec();
			return;
		}
	}
	else
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget:%s %d server reboot fail!\n",__FUNCTION__,__LINE__);
        QMessageBox msgBox(QMessageBox::Question,QString(tr("注意")),QString(tr("重启失败")));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.exec();
		return;
	}
}
*/

void devUpdateWidget::devLocalSetSlot()
{
	char acUserType[64] = {0};
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget local set button pressed!\n");

	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));
	if (!strcmp(acUserType, "operator"))	 //操作员无权校时
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget this user type has no right to set local config!\n");
		QMessageBox box(QMessageBox::Warning,tr("提示"),tr("无权限设置!"));	  //新建消息提示框，提示错误信息
		box.setStandardButtons (QMessageBox::Ok);	//设置提示框只有一个标准按钮
		box.setButtonText (QMessageBox::Ok,tr("确 定")); 	//将按钮显示改成"确 定"
		box.exec();
	}
	else
	{
		if (NULL == localSetPasswdConfirmWidget)
		{
			localSetPasswdConfirmWidget = new LocalsetPasswdConfirm(this);
			localSetPasswdConfirmWidget->setGeometry(300, 270, localSetPasswdConfirmWidget->width(), localSetPasswdConfirmWidget->height());
			connect(this->localSetPasswdConfirmWidget, SIGNAL(sendCloseSignal()), this, SLOT(closeLocalSetPasswdConfirmWidget()));
			connect(this->localSetPasswdConfirmWidget, SIGNAL(sendOkSignal()), this, SLOT(localSetPasswdOkCtrl()));	
		}
		localSetPasswdConfirmWidget->show();
	}
}

void devUpdateWidget::localSetPasswdOkCtrl()
{
	if (localSetPasswdConfirmWidget != NULL)
	{
		delete localSetPasswdConfirmWidget;
		localSetPasswdConfirmWidget=NULL;
    }

	if (NULL == localSetWidget)
	{
		localSetWidget = new localSet(this);
		localSetWidget->setGeometry(245, 189, localSetWidget->width(), localSetWidget->height());
		connect(localSetWidget, SIGNAL(closeWidgetSignal()), this, SLOT(closeLocalSetWidget()));
		connect(this->localSetWidget, SIGNAL(timeManuelSetSignal()), this, SLOT(timeManuelSetSlot()));
	}
	localSetWidget->show();
}

void devUpdateWidget::setTimeSignalCtrl()
{	
	char acTimeStr[128] = {0};
    QDateTime current_date_time ;
	
    current_date_time = QDateTime::currentDateTime();
	snprintf(acTimeStr, sizeof(acTimeStr), "%4d-%02d-%02d %02d:%02d:%02d", current_date_time.date().year(), current_date_time.date().month(), current_date_time.date().day(), current_date_time.time().hour(), current_date_time.time().minute(), current_date_time.time().second());
    ui->sysTimeAdjustLabel->setText(QString(QLatin1String(acTimeStr)));
	
    return;
}

void devUpdateWidget::openTimeSetWidgetSlot()
{
	QString timeStr = ui->sysTimeAdjustLabel->text();
	char acTimeStr[256] = {0};
	int iYear = 0, iMonth = 0, iDay = 0, iHour = 0, iMin = 0, iSec = 0;
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "devUpdateWidget timeSetPushButton pressed!\n");
	strcpy(acTimeStr, timeStr.toLatin1().data());
	if (strlen(acTimeStr) != 0)
	{
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] timeStr:%s!\n", __FUNCTION__, acTimeStr);
		sscanf(acTimeStr, "%4d-%02d-%02d %02d:%02d:%02d", &iYear, &iMonth, &iDay, &iHour, &iMin, &iSec);
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] %d-%d-%d %d:%d:%d!\n", __FUNCTION__, iYear, iMonth, iDay, iHour, iMin, iSec);
	}
    timeSetWidget->setGeometry(450, 257, timeSetWidget->width(), timeSetWidget->height());
	timeSetWidget->setTimeLabelText(iYear, iMonth, iDay, iHour, iMin, iSec);
    timeSetWidget->show();
}

void devUpdateWidget::timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec)    
{
    char timestr[128] = {0};
    snprintf(timestr, sizeof(timestr), "%s-%s-%s %s:%s:%s", year.toStdString().data(), month.toStdString().data(), day.toStdString().data(),
            hour.toStdString().data(), min.toStdString().data(), sec.toStdString().data());
    QString string = QString(QLatin1String(timestr)) ;
	ui->timeSetLineEdit->setText(string);
}

/*
int CreateServerRebootTcpSocket(char *pcIpaddr, unsigned short u16Port)
{
    int iSockfd = 0;
    int iRet = 0;
    struct sockaddr_in servaddr;
    struct timeval tv_out;

    iSockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (iSockfd < 0)
    {
        return -1;
    }
 
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    servaddr.sin_addr.s_addr = inet_addr(pcIpaddr);
    servaddr.sin_port = htons(u16Port);
   

    iRet = connect(iSockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (iRet < 0)
    {
        close(iSockfd);        
        return -1;
    }
    
    tv_out.tv_sec = 5;
    tv_out.tv_usec = 500;
    setsockopt(iSockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out));
    setsockopt(iSockfd, SOL_SOCKET, SO_SNDTIMEO, &tv_out, sizeof(tv_out));

    return iSockfd;
}
*/

