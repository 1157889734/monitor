#include "localSet.h"
#include "ui_localSet.h"
#include "state.h"
#include "fileConfig.h"
#include "debug.h"
#include "log.h"
#include <dirent.h>
#include <stdio.h>
#include <ctype.h>
#include <QTextCodec>
#include <QDateTime>
#include <QObject>
#include <QMessageBox>

//#define MAX_TRAINTYPE_NUM  64   //最大车型数

localSet::localSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::localSet)
{
	char acTimestr[128] = {0}, acAddrStr[128] = {0};
	int iTmp1 = 0, iTmp2 = 0, iTmp3 = 0, iTmp4 = 0;
	QString string = "";
	T_PIS_INFO tPisInfo;
    ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setWindowModality(Qt::WindowModal);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);

	ui->timeSetPushButton->setFocusPolicy(Qt::NoFocus);
	ui->confirmPushButton->setFocusPolicy(Qt::NoFocus);
	ui->canclePushButton->setFocusPolicy(Qt::NoFocus);

	m_widgetWidth = this->width();
	m_widgetHeight = this->height();
	m_tabWidgetPageIdex = 0;

	/*创建时间设置子窗体，默认隐藏*/
    timeSetWidget = new timeSet(this);
    timeSetWidget->hide();

	p_ipmethod= new commonInputMethod();
	if (p_ipmethod != NULL)
	{
		QWSServer::setCurrentInputMethod(p_ipmethod);
	    p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
		if (p_ipmethod->p_inputwidget != NULL)
		{
		    p_ipmethod->p_inputwidget->hide();
			p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
		}
	}

	m_ipLineEdit = new iplineedit(this);
	m_ipLineEdit->setGeometry(238, 100, 132, 29);
	m_ipLineEdit->hide();
	m_ipLineEdit->setObjectName(tr("ipAddrLineEdit"));
	m_ipLineEdit->setStyleSheet("border:none;");
	m_gatewayLineEdit = new iplineedit(this);
	m_gatewayLineEdit->setGeometry(238, 206, 132, 29);
	m_gatewayLineEdit->hide();
	m_gatewayLineEdit->setObjectName(tr("gateWayLineEdit"));
	m_gatewayLineEdit->setStyleSheet("border:none;");
	m_netmaskLineEdit = new netmasklineedit(this);
	m_netmaskLineEdit->setGeometry(238, 153, 132, 29);
	m_netmaskLineEdit->hide();
	m_netmaskLineEdit->setObjectName(tr("netMaskLineEdit"));
	m_netmaskLineEdit->setStyleSheet("border:none;");
	m_pisServerIpLineEdit = new iplineedit(this);
	m_pisServerIpLineEdit->setGeometry(238, 134, 132, 29);
	m_pisServerIpLineEdit->hide();
	m_pisServerIpLineEdit->setObjectName(tr("pisServerIpAddrLineEdit"));
	m_pisServerIpLineEdit->setStyleSheet("border:none;");
	
	STATE_GetIpAddr(acAddrStr, sizeof(acAddrStr));
	if (0 != strlen(acAddrStr))
	{
		sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
	}
	m_ipLineEdit->m_ipPart1->setText(QString::number(iTmp1));
	m_ipLineEdit->m_ipPart2->setText(QString::number(iTmp2));
	m_ipLineEdit->m_ipPart3->setText(QString::number(iTmp3));
	m_ipLineEdit->m_ipPart4->setText(QString::number(iTmp4));

	memset(acAddrStr, 0, sizeof(acAddrStr));
	STATE_GetNetMask(acAddrStr, sizeof(acAddrStr));
	if (0 != strlen(acAddrStr))
	{
		sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
	}
	m_netmaskLineEdit->m_ipPart1->setText(QString::number(iTmp1));
	m_netmaskLineEdit->m_ipPart2->setText(QString::number(iTmp2));
	m_netmaskLineEdit->m_ipPart3->setText(QString::number(iTmp3));
	m_netmaskLineEdit->m_ipPart4->setText(QString::number(iTmp4));

	memset(acAddrStr, 0, sizeof(acAddrStr));
	STATE_GetGateWay(acAddrStr, sizeof(acAddrStr));
	if (0 != strlen(acAddrStr))
	{
		sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
	}
	m_gatewayLineEdit->m_ipPart1->setText(QString::number(iTmp1));
	m_gatewayLineEdit->m_ipPart2->setText(QString::number(iTmp2));
	m_gatewayLineEdit->m_ipPart3->setText(QString::number(iTmp3));
	m_gatewayLineEdit->m_ipPart4->setText(QString::number(iTmp4));

	memset(&tPisInfo, 0, sizeof(T_PIS_INFO));
	STATE_GetPisConfigInfo(&tPisInfo);
	if (0 != strlen(tPisInfo.acIpAddr))
	{
		sscanf(tPisInfo.acIpAddr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
	}
	m_pisServerIpLineEdit->m_ipPart1->setText(QString::number(iTmp1));
	m_pisServerIpLineEdit->m_ipPart2->setText(QString::number(iTmp2));
	m_pisServerIpLineEdit->m_ipPart3->setText(QString::number(iTmp3));
	m_pisServerIpLineEdit->m_ipPart4->setText(QString::number(iTmp4));
	ui->pisServerPortLineEdit->setText(QString::number(tPisInfo.iPort));

	//ui->trainTypeAddPushButton->setFocusPolicy(Qt::NoFocus);
	//ui->trainTypeDelPushButton->setFocusPolicy(Qt::NoFocus);
	ui->trainTypeEditPushButton->setFocusPolicy(Qt::NoFocus);

	ui->trainTypeTableWidget->setFocusPolicy(Qt::NoFocus);
	ui->trainTypeTableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->trainTypeTableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->trainTypeTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->trainTypeTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->trainTypeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
    ui->trainTypeTableWidget->setAlternatingRowColors(true);                        //设置隔一行变一颜色，即：一灰一白 
	
    QDateTime time = QDateTime::currentDateTime();
    snprintf(acTimestr, sizeof(acTimestr), "%4d-%02d-%02d %02d:%02d:%02d", time.date().year(), time.date().month(), time.date().day(), time.time().hour(), time.time().minute(), time.time().second());
    string = QString(QLatin1String(acTimestr)) ;
    ui->timeLabel->setText(string);		 //时间控件初始显示当前系统时间
	
    connect(ui->timeSetPushButton, SIGNAL(clicked(bool)), this, SLOT(openTimeSetWinSlot()));   //时间设置按钮按键信号响应
    connect(ui->confirmPushButton, SIGNAL(clicked(bool)), this, SLOT(confirmSlot()));  
    connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(cancleSlot()));   
    connect(timeSetWidget, SIGNAL(timeSetSendMsg(QString,QString,QString,QString,QString,QString)), this, SLOT(timeSetRecvMsg(QString,QString,QString,QString,QString,QString)));  //时间设置窗体控件设置信号响应
    connect(timeSetWidget, SIGNAL(cancleMsg()), this, SLOT(timeSetCancle()));   
	connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(closeButtonClickSlot()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabWidgetCurrentChangedSlot(int)));

	connect(m_ipLineEdit, SIGNAL(showKeyboardSig()), this, SLOT(showKeyboardSlot()));
	connect(m_ipLineEdit, SIGNAL(hideKeyboardSig()), this, SLOT(hideKeyboardSlot()));
	connect(m_netmaskLineEdit, SIGNAL(showKeyboardSig()), this, SLOT(showKeyboardSlot()));
	connect(m_netmaskLineEdit, SIGNAL(hideKeyboardSig()), this, SLOT(hideKeyboardSlot()));
	connect(m_gatewayLineEdit, SIGNAL(showKeyboardSig()), this, SLOT(showKeyboardSlot()));
	connect(m_gatewayLineEdit, SIGNAL(hideKeyboardSig()), this, SLOT(hideKeyboardSlot()));
	connect(m_pisServerIpLineEdit, SIGNAL(showKeyboardSig()), this, SLOT(showKeyboardSlot()));
	connect(m_pisServerIpLineEdit, SIGNAL(hideKeyboardSig()), this, SLOT(hideKeyboardSlot()));

	trainTypeAddPage = new addTrainTypeWidget(this);
	trainTypeAddPage->setGeometry(177, 114, trainTypeAddPage->width(), trainTypeAddPage->height());
    trainTypeAddPage->hide();
    connect(trainTypeAddPage, SIGNAL(sendCloseMsg()), this, SLOT(CloseTrainTypeAdd()));

	trainTypeEditPage = new editTraintypeWidget(this);
	trainTypeEditPage->setGeometry(177, 114, trainTypeEditPage->width(), trainTypeEditPage->height());
    trainTypeEditPage->hide();
    connect(trainTypeEditPage, SIGNAL(sendCloseMsg()), this, SLOT(CloseTrainTypeEdit()));
	connect(this, SIGNAL(loadEditTrainTypePage(char *)), trainTypeEditPage, SLOT(pageLoadSlot(char *)));

	//connect(ui->trainTypeAddPushButton, SIGNAL(clicked(bool)), this, SLOT(addTrainType()));
	//connect(ui->trainTypeDelPushButton, SIGNAL(clicked(bool)), this, SLOT(delTrainType()));
	connect(ui->trainTypeEditPushButton, SIGNAL(clicked(bool)), this, SLOT(editTrainType()));
	//connect(ui->trainTypeImportPushButton, SIGNAL(clicked(bool)), this, SLOT(importTrainType()));
	connect(ui->stationConfigExportPushButton, SIGNAL(clicked(bool)), this, SLOT(stationConfigFileExport()));
	ui->pisServerPortLineEdit->installEventFilter(this);
}

localSet::~localSet()
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "delete ~localSetWidget\n");
	
	if (timeSetWidget != NULL)
	{
		delete timeSetWidget;
		timeSetWidget = NULL;
	}
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}
	if (trainTypeAddPage != NULL)
	{
		delete trainTypeAddPage;
		trainTypeAddPage = NULL;
	}
	if (trainTypeEditPage != NULL)
	{
		delete trainTypeEditPage;
		trainTypeEditPage = NULL;
	}
	delete m_ipLineEdit;
	m_ipLineEdit = NULL;
	delete m_netmaskLineEdit;
	m_netmaskLineEdit = NULL;
	delete m_gatewayLineEdit;
	m_gatewayLineEdit = NULL;
	delete m_pisServerIpLineEdit;
	m_pisServerIpLineEdit = NULL;
    delete ui;
}

void localSet::openTimeSetWinSlot()
{
	QString timeStr = ui->timeLabel->text();
	char acTimeStr[256] = {0};
	int iYear = 0, iMonth = 0, iDay = 0, iHour = 0, iMin = 0, iSec = 0;
	
	strcpy(acTimeStr, timeStr.toLatin1().data());
	if (strlen(acTimeStr) != 0)
	{
		sscanf(acTimeStr, "%4d-%02d-%02d %02d:%02d:%02d", &iYear, &iMonth, &iDay, &iHour, &iMin, &iSec);
	}

	if (NULL == timeSetWidget)
	{
		timeSetWidget = new timeSet(this);
	}
	
	timeSetWidget->move(180, 185);
	timeSetWidget->setTimeLabelText(iYear, iMonth, iDay, iHour, iMin, iSec);
    timeSetWidget->show();
	ui->frame->resize(m_widgetWidth, 185+timeSetWidget->height()+10);
	this->resize(m_widgetWidth, 185+timeSetWidget->height()+10);
}

void localSet::timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec)     //响应时间设置控件信号，更新起始、结束时间显示label的显示文本
{
    char timestr[128] = {0};
    snprintf(timestr, sizeof(timestr), "%s-%s-%s %s:%s:%s", year.toStdString().data(), month.toStdString().data(), day.toStdString().data(),
            hour.toStdString().data(), min.toStdString().data(), sec.toStdString().data());
    QString string = QString(QLatin1String(timestr)) ;

    ui->timeLabel->setText(string);
	ui->frame->resize(m_widgetWidth,m_widgetHeight);
	this->resize(m_widgetWidth, m_widgetHeight);
}

void localSet::timeSetCancle()
{
	ui->frame->resize(m_widgetWidth,m_widgetHeight);  
	this->resize(m_widgetWidth, m_widgetHeight);
}

void localSet::closeButtonClickSlot()
{
	ui->frame->resize(m_widgetWidth,m_widgetHeight);
	this->resize(m_widgetWidth, m_widgetHeight);
	
    emit closeWidgetSignal();
    return;
}

void localSet::cancleSlot()
{		
	ui->frame->resize(m_widgetWidth,m_widgetHeight);
	this->resize(m_widgetWidth, m_widgetHeight);
	
    emit closeWidgetSignal();
    return;
}


void localSet::tabWidgetCurrentChangedSlot(int iDex)
{
	T_TRAIN_TYPE_LIST tTrainTypeList;
	T_PIS_INFO tPisInfo;
	char acAddrStr[128] = {0};
	int iTmp1 = 0, iTmp2 = 0, iTmp3 = 0, iTmp4 = 0;
	int iRet = 0, i = 0, row = 0;
	QString item = "";
	m_tabWidgetPageIdex = iDex;
	if (timeSetWidget != NULL)
	{
		timeSetWidget->hide();
	}
	ui->frame->resize(m_widgetWidth,m_widgetHeight);
	this->resize(m_widgetWidth, m_widgetHeight);
	if (0 == m_tabWidgetPageIdex)
	{
		m_ipLineEdit->hide();
		m_netmaskLineEdit->hide();
		m_gatewayLineEdit->hide();
		m_pisServerIpLineEdit->hide();
	}
	else if (1 == m_tabWidgetPageIdex)
	{
		m_pisServerIpLineEdit->hide();
		STATE_GetIpAddr(acAddrStr, sizeof(acAddrStr));
		if (0 != strlen(acAddrStr))
		{
			sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
		}
		m_ipLineEdit->m_ipPart1->setText(QString::number(iTmp1));
		m_ipLineEdit->m_ipPart2->setText(QString::number(iTmp2));
		m_ipLineEdit->m_ipPart3->setText(QString::number(iTmp3));
		m_ipLineEdit->m_ipPart4->setText(QString::number(iTmp4));

		memset(acAddrStr, 0, sizeof(acAddrStr));
		STATE_GetNetMask(acAddrStr, sizeof(acAddrStr));
		if (0 != strlen(acAddrStr))
		{
			sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
		}
		m_netmaskLineEdit->m_ipPart1->setText(QString::number(iTmp1));
		m_netmaskLineEdit->m_ipPart2->setText(QString::number(iTmp2));
		m_netmaskLineEdit->m_ipPart3->setText(QString::number(iTmp3));
		m_netmaskLineEdit->m_ipPart4->setText(QString::number(iTmp4));

		memset(acAddrStr, 0, sizeof(acAddrStr));
		STATE_GetGateWay(acAddrStr, sizeof(acAddrStr));
		if (0 != strlen(acAddrStr))
		{
			sscanf(acAddrStr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
		}
		m_gatewayLineEdit->m_ipPart1->setText(QString::number(iTmp1));
		m_gatewayLineEdit->m_ipPart2->setText(QString::number(iTmp2));
		m_gatewayLineEdit->m_ipPart3->setText(QString::number(iTmp3));
		m_gatewayLineEdit->m_ipPart4->setText(QString::number(iTmp4));
		m_ipLineEdit->show();
		m_netmaskLineEdit->show();
		m_gatewayLineEdit->show();
	}
	else if (2 == m_tabWidgetPageIdex)
	{
		m_ipLineEdit->hide();
		m_netmaskLineEdit->hide();
		m_gatewayLineEdit->hide();
		m_pisServerIpLineEdit->hide();

		row = ui->trainTypeTableWidget->rowCount();
	    for (i = 0; i < row; i++)
	    {
	        ui->trainTypeTableWidget->removeRow(i);
	    }
	    ui->trainTypeTableWidget->setRowCount(0);
		
		memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
	    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
		if (iRet < 0)
		{
			return;
		}
		for(i = 0; i < tTrainTypeList.iTypeNum; i++)
		{
			//ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
			row = ui->trainTypeTableWidget->rowCount();               
            ui->trainTypeTableWidget->insertRow(row);//添加新的一行 

			item = QString::number(row+1);
            ui->trainTypeTableWidget->setItem(row, 0, new QTableWidgetItem(item));
            ui->trainTypeTableWidget->item(row, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

			ui->trainTypeTableWidget->setItem(row, 1, new QTableWidgetItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i]))));
            ui->trainTypeTableWidget->item(row, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
		}
	}
	else if (3 == m_tabWidgetPageIdex)
	{
		m_ipLineEdit->hide();
		m_netmaskLineEdit->hide();
		m_gatewayLineEdit->hide();
		m_pisServerIpLineEdit->hide();

		iRet = STATE_GetBlackScreenFlag();
		if (iRet < 0)
		{
			return;
		}

		if (0 == iRet)
		{
			ui->blackScreenSetCheckBox->setChecked(false);
		}
		else
		{
			ui->blackScreenSetCheckBox->setChecked(true);
		}

		iRet = STATE_GetShadeAlarmEnableFlag();
		if (iRet < 0)
		{
			return;
		}

		if (0 == iRet)
		{
			ui->shadeAlarmCheckBox->setChecked(false);
		}
		else
		{
			ui->shadeAlarmCheckBox->setChecked(true);
		}
	}
	else
	{
		m_ipLineEdit->hide();
		m_netmaskLineEdit->hide();
		m_gatewayLineEdit->hide();
		
		memset(&tPisInfo, 0, sizeof(T_PIS_INFO));
		STATE_GetPisConfigInfo(&tPisInfo);
		if (0 != strlen(tPisInfo.acIpAddr))
		{
			sscanf(tPisInfo.acIpAddr, "%d.%d.%d.%d", &iTmp1, &iTmp2, &iTmp3, &iTmp4);
		}
		m_pisServerIpLineEdit->m_ipPart1->setText(QString::number(iTmp1));
		m_pisServerIpLineEdit->m_ipPart2->setText(QString::number(iTmp2));
		m_pisServerIpLineEdit->m_ipPart3->setText(QString::number(iTmp3));
		m_pisServerIpLineEdit->m_ipPart4->setText(QString::number(iTmp4));

		m_pisServerIpLineEdit->show();
		ui->pisServerPortLineEdit->setText(QString::number(tPisInfo.iPort));
	}
}

void localSet::confirmSlot()
{
	char acStr[256] = {0};
	int iYear = 0, iMonth = 0, iDay = 0, iHour = 0, iMin = 0, iSec = 0, iRet = 0;
	T_PIS_INFO tPisInfo;
	T_LOG_INFO tLogInfo;
	
	if (0 == m_tabWidgetPageIdex)
	{
		DebugPrint(DEBUG_UI_OPTION_PRINT, "localSetWidget set rtc time!");
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] timeStr:%s\n", __FUNCTION__, ui->timeLabel->text().toLatin1().data());
		sscanf(ui->timeLabel->text().toLatin1().data(), "%4d-%02d-%02d %02d:%02d:%02d", &iYear, &iMonth, &iDay, &iHour, &iMin, &iSec);
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "[%s] set time(%d-%d-%d %d:%d:%d)\n", __FUNCTION__, iYear, iMonth, iDay, iHour, iMin, iSec);
		snprintf(acStr, sizeof(acStr), "rtc.exe -s \"%4d-%02d-%02d %02d:%02d:%02d\"", iYear, iMonth, iDay, iHour, iMin, iSec);
		system(acStr);
		system("rtc.exe -i");

		/*系统校时记录日志*/
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "set local time %4d-%02d-%02d %02d:%02d:%02d", iYear, iMonth, iDay, iHour, iMin, iSec);
		LOG_WriteLog(&tLogInfo);
		
		emit timeManuelSetSignal();
	}
	else if (1 == m_tabWidgetPageIdex)
	{
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->hide();
		}

		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "IP set will reboot client, confirm?\n");
        QMessageBox msgBox(QMessageBox::Question,QString(tr("提示")),QString(tr("IP修改，客户端将重启，是否继续？")));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.button(QMessageBox::No)->setText("取 消");
        iRet=msgBox.exec();
        if(iRet != QMessageBox::Yes)
        {
            return;
        }

		memset(acStr, 0, sizeof(acStr));
		snprintf(acStr, sizeof(acStr), "ifconfig eth1 %s.%s.%s.%s netmask %s.%s.%s.%s",m_ipLineEdit->m_ipPart1->text().toLatin1().data(), m_ipLineEdit->m_ipPart2->text().toLatin1().data(),
			m_ipLineEdit->m_ipPart3->text().toLatin1().data(), m_ipLineEdit->m_ipPart4->text().toLatin1().data(),m_netmaskLineEdit->m_ipPart1->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart2->text().toLatin1().data(),
			m_netmaskLineEdit->m_ipPart3->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart4->text().toLatin1().data());
		system(acStr);

		memset(acStr, 0, sizeof(acStr));
		snprintf(acStr, sizeof(acStr), "%s.%s.%s.%s", m_ipLineEdit->m_ipPart1->text().toLatin1().data(), m_ipLineEdit->m_ipPart2->text().toLatin1().data(),
			m_ipLineEdit->m_ipPart3->text().toLatin1().data(), m_ipLineEdit->m_ipPart4->text().toLatin1().data());
		STATE_SetIpAddr(acStr);

		memset(acStr, 0, sizeof(acStr));
		snprintf(acStr, sizeof(acStr), "%s.%s.%s.%s", m_netmaskLineEdit->m_ipPart1->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart2->text().toLatin1().data(),
			m_netmaskLineEdit->m_ipPart3->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart4->text().toLatin1().data());
		STATE_SetNetMask(acStr);

		memset(acStr, 0, sizeof(acStr));
		snprintf(acStr, sizeof(acStr), "%s.%s.%s.%s", m_gatewayLineEdit->m_ipPart1->text().toLatin1().data(), m_gatewayLineEdit->m_ipPart2->text().toLatin1().data(),
			m_gatewayLineEdit->m_ipPart3->text().toLatin1().data(), m_gatewayLineEdit->m_ipPart4->text().toLatin1().data());
		STATE_SetGateWay(acStr);

		/*系统修改IP记录日志*/
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "set ip:%s.%s.%s.%s netmask:%s.%s.%s.%s, gateway:%s.%s.%s.%s!", 
			m_ipLineEdit->m_ipPart1->text().toLatin1().data(), m_ipLineEdit->m_ipPart2->text().toLatin1().data(),
			m_ipLineEdit->m_ipPart3->text().toLatin1().data(), m_ipLineEdit->m_ipPart4->text().toLatin1().data(),
			m_netmaskLineEdit->m_ipPart1->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart2->text().toLatin1().data(),
			m_netmaskLineEdit->m_ipPart3->text().toLatin1().data(), m_netmaskLineEdit->m_ipPart4->text().toLatin1().data(),
			m_gatewayLineEdit->m_ipPart1->text().toLatin1().data(), m_gatewayLineEdit->m_ipPart2->text().toLatin1().data(),
			m_gatewayLineEdit->m_ipPart3->text().toLatin1().data(), m_gatewayLineEdit->m_ipPart4->text().toLatin1().data());
		LOG_WriteLog(&tLogInfo);
		
		/*程序重启记录日志*/
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "monitor Client reboot!");
		LOG_WriteLog(&tLogInfo);
		
		QApplication *app;
        app->exit();
	}
	else if (3 == m_tabWidgetPageIdex)
	{
		if (true == ui->blackScreenSetCheckBox->isChecked())
		{
			iRet = STATE_SetBlackScreenFlag(1);
		}
		else
		{
			iRet = STATE_SetBlackScreenFlag(0);
		}

		if (true == ui->shadeAlarmCheckBox->isChecked())
		{
			iRet = STATE_SetShadeAlarmEnableFlag(1);
		}
		else
		{
			iRet = STATE_SetShadeAlarmEnableFlag(0);
		}
	}
	else if (4 == m_tabWidgetPageIdex)
	{
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->hide();
		}

		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "PIS Server Info set should reboot client to recv new pis server message, confirm?\n");
        QMessageBox msgBox(QMessageBox::Question,QString(tr("提示")),QString(tr("PIS信息修改，需重启客户端重新配置，是否继续？")));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.button(QMessageBox::No)->setText("取 消");
        iRet=msgBox.exec();
        if(iRet != QMessageBox::Yes)
        {
            return;
        }
		
		memset(&tPisInfo, 0, sizeof(T_PIS_INFO));
		STATE_GetPisConfigInfo(&tPisInfo);
		memset(acStr, 0, sizeof(acStr));
		snprintf(acStr, sizeof(acStr), "%s.%s.%s.%s", m_pisServerIpLineEdit->m_ipPart1->text().toLatin1().data(), m_pisServerIpLineEdit->m_ipPart2->text().toLatin1().data(),
			m_pisServerIpLineEdit->m_ipPart3->text().toLatin1().data(), m_pisServerIpLineEdit->m_ipPart4->text().toLatin1().data());
		strncpy(tPisInfo.acIpAddr, acStr, sizeof(tPisInfo.acIpAddr));
		tPisInfo.iPort = ui->pisServerPortLineEdit->text().toInt();
		STATE_SetPisConfigInfo(tPisInfo);
		
		/*修改PIS IP端口记录日志*/
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "set pis server ip:%s port:%d!", tPisInfo.acIpAddr, tPisInfo.iPort);
		LOG_WriteLog(&tLogInfo);

		/*程序重启记录日志*/
		memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
		tLogInfo.iLogType = 0;
		snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "monitor Client reboot!");
		LOG_WriteLog(&tLogInfo);
		
		QApplication *app;
        app->exit();
	}
	emit closeWidgetSignal();
}

void localSet::showKeyboardSlot()
{
	if (NULL == p_ipmethod)
	{
		p_ipmethod= new commonInputMethod();
		if (NULL == p_ipmethod)
		{
			return;
		}
		QWSServer::setCurrentInputMethod(p_ipmethod);
		if (NULL == p_ipmethod->p_inputwidget)
		{
			p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
			if (NULL == p_ipmethod->p_inputwidget)
			{
				return;
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
				return;
			}
			p_ipmethod->setConnect();
			p_ipmethod->setMapping();
		}
	}
	
	QObject *object = sender();
    if (object->objectName() == "ipAddrLineEdit")
    {
		p_ipmethod->p_inputwidget->move(231, 320);
    }
    else if (object->objectName() == "netMaskLineEdit")
    {
		p_ipmethod->p_inputwidget->move(231, 373);
    }
	else if (object->objectName() == "gateWayLineEdit")
    {
		p_ipmethod->p_inputwidget->move(231, 426);
    }
	else if (object->objectName() == "pisServerIpAddrLineEdit")
    {
		p_ipmethod->p_inputwidget->move(231, 354);
    }
	
	p_ipmethod->p_inputwidget->show();
}

void localSet::hideKeyboardSlot()
{
	if (p_ipmethod->p_inputwidget != NULL)
    {
    	p_ipmethod->p_inputwidget->hide();
	}
}

void localSet::addTrainType()
{  
	DebugPrint(DEBUG_UI_OPTION_PRINT, "localSetWidget add trainType button pressed!\n");
    if (trainTypeAddPage == NULL)
    {
        trainTypeAddPage = new addTrainTypeWidget(this);
        trainTypeAddPage->setGeometry(177, 114, trainTypeAddPage->width(), trainTypeAddPage->height());
        trainTypeAddPage->show();
        connect(trainTypeAddPage, SIGNAL(sendCloseMsg()), this, SLOT(CloseTrainTypeAdd()));
    }
	else
	{
    	trainTypeAddPage->show();
	}
}

void localSet::delTrainType()
{
	T_TRAIN_TYPE_LIST tTrainTypeList;
	int iRet = 0, i = 0, row = 0;
	int rowIndex = -1, iTrainTypeNum = 0;
	char acCurrentTrainType[128] = {0};
	QString item = "";
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "localSetWidget delete trainType button pressed!\n");

	iTrainTypeNum = STATE_GetTrainTypeNum();
	rowIndex = ui->trainTypeTableWidget->currentRow();
	if (rowIndex != -1)
    {
    	STATE_GetCurrentTrainType(acCurrentTrainType, sizeof(acCurrentTrainType));
		if (strlen(acCurrentTrainType) > 0)
		{
			if (!strcmp(ui->trainTypeTableWidget->item(rowIndex, 1)->text().toLatin1().data(), acCurrentTrainType))
			{
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget can't delete the traintype config file of using!\n");
				QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("当前正在使用的配置文件不能删除!")));
		        msgBox.setStandardButtons(QMessageBox::Yes);
		        msgBox.button(QMessageBox::Yes)->setText("确 定");
		        msgBox.exec();
			}
			else
			{
				STATE_delTrainType(rowIndex+1);
				STATE_SetTrainTypeNum(iTrainTypeNum-1);
			}
		}
		else
		{
			STATE_delTrainType(rowIndex+1);
			STATE_SetTrainTypeNum(iTrainTypeNum-1);
		}
    } 
	else
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget not select the config file to delete!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("请选择要删除的车型配置!")));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.exec();
	}
	

	row = ui->trainTypeTableWidget->rowCount();
    for (i = 0; i < row; i++)
    {
        ui->trainTypeTableWidget->removeRow(i);
    }
    ui->trainTypeTableWidget->setRowCount(0);
	
	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
	if (iRet < 0)
	{
		return;
	}
	for(i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		//ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
		row = ui->trainTypeTableWidget->rowCount();                
        ui->trainTypeTableWidget->insertRow(row);//添加新的一行 

		item = QString::number(row+1);
        ui->trainTypeTableWidget->setItem(row, 0, new QTableWidgetItem(item));
        ui->trainTypeTableWidget->item(row, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

		ui->trainTypeTableWidget->setItem(row, 1, new QTableWidgetItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i]))));
        ui->trainTypeTableWidget->item(row, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	}
}

void localSet::editTrainType()
{
	int rowIndex = -1;
	//char acCurrentTrainType[128] = {0};
	QString item = "";
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "localSetWidget edit trainType button pressed!\n");

	rowIndex = ui->trainTypeTableWidget->currentRow();
	if (rowIndex != -1)
    {
    	/*
    	STATE_GetCurrentTrainType(acCurrentTrainType, sizeof(acCurrentTrainType));
		if (strlen(acCurrentTrainType) > 0)
		{
			if (!strcmp(ui->trainTypeTableWidget->item(rowIndex, 1)->text().toLatin1().data(), acCurrentTrainType))
			{
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget can't delete the traintype config file of using!\n");
				QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("当前正在使用的配置文件不能修改!")));
		        msgBox.setStandardButtons(QMessageBox::Yes);
		        msgBox.button(QMessageBox::Yes)->setText("确 定");
		        msgBox.exec();
				return;
			}
		}
		*/
		
    	if (trainTypeEditPage == NULL)
		{
			trainTypeEditPage = new editTraintypeWidget(this);
			trainTypeEditPage->setGeometry(177, 114, trainTypeEditPage->width(), trainTypeEditPage->height());
			connect(trainTypeEditPage, SIGNAL(sendCloseMsg()), this, SLOT(CloseTrainTypeEdit()));
			connect(this, SIGNAL(loadEditTrainTypePage(char *)), trainTypeEditPage, SLOT(pageLoadSlot(char *)));
			
		}
		emit loadEditTrainTypePage(ui->trainTypeTableWidget->currentItem()->text().toLatin1().data());
    } 
	else
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget not select the config file to modify!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("请选择要修改的车型配置!")));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.button(QMessageBox::Yes)->setText("确 定");
        msgBox.exec();
	}
	
}

int localSet::checkImportFile(char *pcFileName)   //校验U盘cfg目录下的车厢配置文件
{
	char *pcTmp = NULL, *pcTmp2 = NULL;
	char acStr[128] = {0}, acTmp[32] = {0};
	int iRet = 0, i = 0, iLen = 0, iCount = 0, iFormationType = 0;
	int aiTemp[4] = {-1, -2, -3, -4}, aiTmp[4] = {-1, -2, -3, -4};

	if (NULL == pcFileName)
	{	
		return -1;
	}
	
	if (NULL == strstr(pcFileName, ".ini"))
	{
		return -1;
	}
	else 
	{
    	pcTmp = strrchr(pcFileName, '/');
		if (NULL == pcTmp)
		{
			return -1;
		}
		pcTmp = pcTmp+1;
		pcTmp2 = strstr(pcTmp, ".ini");
		memcpy(acStr, pcTmp, pcTmp2-pcTmp);
		if (0 == strlen(acStr)) 
		{
			return -1;
		}

		iLen = strlen(acStr);
		for (i = 0; i < iLen; i++)    //判断文件名是否只包含有字母和数字
		{
			if (0 == isalnum(acStr[i]))
			{
				return -1;
			}
		}

		iRet = ReadParam(pcFileName, "[PVSM_TRAIN]", "FormationType", acStr);
		if (iRet < 0)
		{
			return -1;
		}
		iFormationType = atoi(acStr);
		if (iFormationType != 1 && iFormationType != 2)
		{
			return -1;
		}

		memset(acStr, 0, sizeof(acStr));
		iRet = ReadParam(pcFileName, "[PVSM_TRAIN]", "NVRCount", acStr);
		if (iRet < 0)
		{
			return -1;
		}
		iCount = atoi(acStr);
		if (iCount != 1 && iCount != 2 && iCount != 4)
		{
			return -1;
		}

		for (i = 0; i < iCount; i++)
		{
			memset(acTmp,0, sizeof(acTmp));
			snprintf(acTmp, sizeof(acTmp), "[PVMS_NVR%d]", i+1);
			memset(acStr, 0, sizeof(acStr));
			iRet = ReadParam(pcFileName, acTmp, "NVRCarriageNO", acStr);
			if (iRet < 0)
			{
				return -1;
			}
			iRet = atoi(acStr);
			if (iRet <= 0)
			{
				return -1;
			}
			else
			{
				if (1 == iFormationType)
				{
					if (iRet > 8)
					{
						return -1;
					}
				}
				else
				{
					if (iRet > 16)
					{
						return -1;
					}
				}

				aiTemp[i] = iRet;
			}
			
			memset(acStr, 0, sizeof(acStr));
			iRet = ReadParam(pcFileName, acTmp, "PvmsCarriageNO", acStr);
			if (iRet < 0)
			{
				return -1;
			}
			iRet = atoi(acStr);
			if (iRet <= 0)
			{
				return -1;
			}
			else
			{
				if (1 == iFormationType)
				{
					if (iRet > 8)
					{
						return -1;
					}
				}
				else
				{
					if (iRet > 16)
					{
						return -1;
					}
				}
				aiTmp[i] = iRet;
			}

			memset(acStr, 0, sizeof(acStr));
			iRet = ReadParam(pcFileName, acTmp, "PvmsCameraNum", acStr);
			if (iRet < 0)
			{
				return -1;
			}
			iRet = atoi(acStr);		
			if (iRet <= 0)
			{
				return -1;
			}
			else
			{
				if (1 == iCount || 2 == iCount)
				{
					if (iRet > 2)
					{
						return -1;
					}
				}
				else
				{
					if (iRet > 1)
					{
						return -1;
					}
				}
			}
		}

		if (aiTemp[0] == aiTemp[1] || aiTemp[0] == aiTemp[2] || aiTemp[0] == aiTemp[3] ||
			aiTemp[1] == aiTemp[2] || aiTemp[1] == aiTemp[3] || aiTemp[2] == aiTemp[3])
		{
			return -1;
		}

		if (aiTmp[0] == aiTmp[1] || aiTmp[0] == aiTmp[2] || aiTmp[0] == aiTmp[3] ||
			aiTmp[1] == aiTmp[2] || aiTmp[1] == aiTmp[3] || aiTmp[2] == aiTmp[3])
		{
			return -1;
		}
	}
	
	return 0;
}

void localSet::importTrainType()
{
	int iRet = 0, i = 0, row = 0;
	int iTrainTypeNum = 0, iConfileNum = 0;
	char acTmp[128] = {0}, acTmp2[16] = {0};
	char acTrainType[32] = {0};
	char acTrainTypeName[256] = {0};
	QString item = "";
	T_TRAIN_TYPE_LIST tTrainTypeList;
	DIR *pDirHandle = NULL;
	struct dirent *pstDp; 

	DebugPrint(DEBUG_UI_OPTION_PRINT, "localSetWidget import trainType button pressed!\n");
	
	if (access("/mnt/usb/u/", F_OK) < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget not get USB device!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}
	else
	{
		if (0 == STATE_FindUsbDev())   //这里处理一个特殊情况:U盘拔掉是umount失败，/mnt/usb/u/路径还存在，但是实际U盘是没有再插上的
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget not get USB device!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
	        msgBox.setStandardButtons(QMessageBox::Yes);
	        msgBox.button(QMessageBox::Yes)->setText("确 定");
	        msgBox.exec();
	        return;
		}
	}

	if (STATE_ParseUsbLicense("/mnt/usb/u/") < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget importTrainType check License error!\n");
		QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("授权失败!"));     
	    box.setStandardButtons (QMessageBox::Ok);   
	    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
	    box.exec();
		return;
	}

	pDirHandle = opendir("/mnt/usb/u/cfg/");
	if (NULL == pDirHandle)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget not get cfg path in USB device!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("U盘中未检测cfg目录!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}
	
	for (pstDp = readdir(pDirHandle); pstDp != NULL; pstDp = readdir(pDirHandle))
	{ 
		memset(acTmp, 0, sizeof(acTmp));
		snprintf(acTmp, sizeof(acTmp), "/mnt/usb/u/cfg/%s", pstDp->d_name);
		if (0 == checkImportFile(acTmp))
		{
			iConfileNum++;
			memset(acTmp, 0, sizeof(acTmp));
			snprintf(acTmp, sizeof(acTmp), "/home/data/emuVideoMornitorClient/cfg/%s", pstDp->d_name);
			if (access(acTmp, F_OK) < 0)
			{
				memset(acTmp, 0, sizeof(acTmp));
				snprintf(acTmp, sizeof(acTmp), "cp /mnt/usb/u/cfg/%s /home/data/emuVideoMornitorClient/cfg/", pstDp->d_name);
				system(acTmp);
				system("sync");

				memset(acTmp, 0, sizeof(acTmp));
				sscanf(pstDp->d_name, "%[^.].%[^.]", acTmp,acTmp2);
				iTrainTypeNum = STATE_GetTrainTypeNum();
				STATE_GetLastTrainType(acTrainType, sizeof(acTrainType));
				memset(acTrainTypeName, 0, sizeof(acTrainTypeName));
				snprintf(acTrainTypeName, sizeof(acTrainTypeName), "%s\nTrainType%d=%s",acTrainType, iTrainTypeNum+1, acTmp);
				STATE_addTrainType(acTrainTypeName);	
				STATE_SetTrainTypeNum(iTrainTypeNum+1);
				
			}
			else 
			{
				memset(acTmp, 0, sizeof(acTmp));
				snprintf(acTmp, sizeof(acTmp), "cp /mnt/usb/u/cfg/%s /home/data/emuVideoMornitorClient/cfg/", pstDp->d_name);
				system(acTmp);
				system("sync");
			}
		}
	} 
	closedir(pDirHandle);

	if (iConfileNum > 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget traintype config file import success!\n");
		QMessageBox msgBox(QMessageBox::Information,QString(tr("注意")),QString(tr("导入成功!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();

		STATE_RefreshTrainTypeInfo();

		row = ui->trainTypeTableWidget->rowCount();
		for (i = 0; i < row; i++)
		{
			ui->trainTypeTableWidget->removeRow(i);
		}
		ui->trainTypeTableWidget->setRowCount(0);
		
		memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
		iRet = STATE_GetTrainTypeList(&tTrainTypeList);
		if (iRet < 0)
		{
			return;
		}
		for(i = 0; i < tTrainTypeList.iTypeNum; i++)
		{
			//ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
			row = ui->trainTypeTableWidget->rowCount(); 			   
			ui->trainTypeTableWidget->insertRow(row);//添加新的一行 

			item = QString::number(row+1);
			ui->trainTypeTableWidget->setItem(row, 0, new QTableWidgetItem(item));
			ui->trainTypeTableWidget->item(row, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

			ui->trainTypeTableWidget->setItem(row, 1, new QTableWidgetItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i]))));
			ui->trainTypeTableWidget->item(row, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
		}
	}
	else
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget traintype config file import fail,not find any normal ini file!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("导入失败!未检测到任何合格的ini文件!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
	}
}



void localSet::CloseTrainTypeAdd()
{
	T_TRAIN_TYPE_LIST tTrainTypeList;
	int iRet = 0, i = 0, row = 0;
	QString item = "";
    if(NULL==this->trainTypeAddPage)
    {
        return;
    }
    else
    {
        delete this->trainTypeAddPage;
    }
    this->trainTypeAddPage=NULL;

	row = ui->trainTypeTableWidget->rowCount();
    for (i = 0; i < row; i++)
    {
        ui->trainTypeTableWidget->removeRow(i);
    }
    ui->trainTypeTableWidget->setRowCount(0);
	
	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
	if (iRet < 0)
	{
		return;
	}
	for(i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		//ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
		row = ui->trainTypeTableWidget->rowCount();                
        ui->trainTypeTableWidget->insertRow(row);//添加新的一行 

		item = QString::number(row+1);
        ui->trainTypeTableWidget->setItem(row, 0, new QTableWidgetItem(item));
        ui->trainTypeTableWidget->item(row, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

		ui->trainTypeTableWidget->setItem(row, 1, new QTableWidgetItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i]))));
        ui->trainTypeTableWidget->item(row, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	}
}

void localSet::CloseTrainTypeEdit()
{
	T_TRAIN_TYPE_LIST tTrainTypeList;
	int iRet = 0, i = 0, row = 0;
	QString item = "";
    if(NULL==this->trainTypeEditPage)
    {
        return;
    }
    else
    {
        delete this->trainTypeEditPage;
    }
    this->trainTypeEditPage=NULL;

	row = ui->trainTypeTableWidget->rowCount();
    for (i = 0; i < row; i++)
    {
        ui->trainTypeTableWidget->removeRow(i);
    }
    ui->trainTypeTableWidget->setRowCount(0);
	
	memset(&tTrainTypeList, 0, sizeof(tTrainTypeList));
    iRet = STATE_GetTrainTypeList(&tTrainTypeList);
	if (iRet < 0)
	{
		return;
	}
	for(i = 0; i < tTrainTypeList.iTypeNum; i++)
	{
		//ui->trainTypeSetComboBox->addItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i])));
		row = ui->trainTypeTableWidget->rowCount();                
        ui->trainTypeTableWidget->insertRow(row);//添加新的一行 

		item = QString::number(row+1);
        ui->trainTypeTableWidget->setItem(row, 0, new QTableWidgetItem(item));
        ui->trainTypeTableWidget->item(row, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

		ui->trainTypeTableWidget->setItem(row, 1, new QTableWidgetItem(QString(QLatin1String(tTrainTypeList.acTrainTypeName[i]))));
        ui->trainTypeTableWidget->item(row, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	}
}

void localSet::stationConfigFileExport()
{	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "localSet station config file import!\n");
		
	if (access("/mnt/usb/u/", F_OK) < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not get USB device!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}
	else
	{
		if (0 == STATE_FindUsbDev())   //这里处理一个特殊情况:U盘拔掉是umount失败，/mnt/usb/u/路径还存在，但是实际U盘是没有再插上的
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not get USB device!\n");
			QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("未检测到U盘,请插入!")));
			msgBox.setStandardButtons(QMessageBox::Yes);
			msgBox.button(QMessageBox::Yes)->setText("确 定");
			msgBox.exec();
			return;
		}
	}

	if (STATE_ParseUsbLicense("/mnt/usb/u/") < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "localSetWidget stationConfigFileExport check License error!\n");
		QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("授权失败!"));     
	    box.setStandardButtons (QMessageBox::Ok);   
	    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
	    box.exec();
		return;
	}

	/*
	if (access("/mnt/usb/u/Station.ini", F_OK) < 0)
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "devUpdateWidget not find update file in USB device!\n");
		QMessageBox msgBox(QMessageBox::Warning,QString(tr("注意")),QString(tr("U盘中未检测车站代码配置文件!")));
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.button(QMessageBox::Yes)->setText("确 定");
		msgBox.exec();
		return;
	}
	*/

	system("cp /home/data/emuVideoMornitorClient/Station.ini /mnt/usb/u/Station.ini");
	system("sync");

	QMessageBox msgBox(QMessageBox::Information,QString(tr("注意")),QString(tr("Station.ini文件成功导出到U盘!")));
	msgBox.setStandardButtons(QMessageBox::Yes);
	msgBox.button(QMessageBox::Yes)->setText("确 定");
	msgBox.exec();
	return;
}


bool localSet::eventFilter(QObject *target, QEvent *event)
{
	if ((target == ui->pisServerPortLineEdit) && (event->type() == QEvent::MouseButtonPress))
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
			
			p_ipmethod->p_inputwidget->setGeometry(231, 425, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
			p_ipmethod->p_inputwidget->show();
		}
	}
	
	return QWidget::eventFilter(target, event);
}

