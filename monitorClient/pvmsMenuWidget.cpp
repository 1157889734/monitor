#include "pvmsMenuWidget.h"
#include "ui_pvmsMenuWidget.h"
#include "pmsgcli.h"
#include "state.h"
#include "debug.h"
#include "log.h"
#include <stdio.h>
#include <netinet/in.h>
#include <QTextCodec>
#include <QMessageBox>

#define PVMSPAGETYPE  2    //此页面类型，2表示受电弓监控页面

void pvmsMenuWidget::pmsgTimerFunc()
{
    int i = 0, iRet = 0;
    T_TRAIN_CONFIG tTrainConfigInfo;
    T_PMSG_PACKET tPkt;
	PMSG_HANDLE pmsgHandle = 0;

    memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
    STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
    for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
    {
        memset(&tPkt, 0, sizeof(T_PMSG_PACKET));
		pmsgHandle = STATE_GetNvrServerPmsgHandle(i);
        iRet = PMSG_GetDataFromPmsgQueue(pmsgHandle, &tPkt);
        if (iRet < 0)
        {
            DebugPrint(DEBUG_PMSG_ERROR_PRINT, "get server 192.168.%d.81 pmsg data error\n", 100+tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO);
            continue;
        }
        DebugPrint(DEBUG_PMSG_NORMAL_PRINT, "pmsgTimerFunc get pmsg message 0x%x, msgDataLen=%d\n",(int)tPkt.ucMsgCmd, tPkt.iMsgDataLen);
        recvPmsgCtrl(tPkt.PHandle, tPkt.ucMsgCmd, tPkt.pcMsgData, tPkt.iMsgDataLen);
        if (tPkt.pcMsgData)
        {
            free(tPkt.pcMsgData);
            tPkt.pcMsgData = NULL;
        }
    }
}

void pvmsMenuWidget::rs485TimerFunc()
{
    int iRet = 0;
    T_RS485_PACKET tPkt;

    iRet = RS485_GetDataFromRs485Queue(m_pRs485Handle, &tPkt);
    if (iRet < 0)
    {
        DebugPrint(DEBUG_RS485_DATA_PRINT, "get rs485 data error\n");
        return;
    }

    if (NULL == tPkt.pcData || 0 == tPkt.iDataLen)
    {
        return;
    }

    recvRs485Ctrl(tPkt.pcData, tPkt.iDataLen);
    if (tPkt.pcData)
    {
        free(tPkt.pcData);
        tPkt.pcData = NULL;
    }
}

pvmsMenuWidget::pvmsMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pvmsMenuWidget)
{
	int i = 0;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");    //设置字符编码类型
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec); 

    m_pvmsMonitorPage = new pvmsMonitorWidget(this);   //受电弓监控页面
    m_pvmsMonitorPage->setGeometry(0, 103, m_pvmsMonitorPage->width(), m_pvmsMonitorPage->height());   //设置位置
    m_recordPlayPage = new recordPlayWidget(this);     //录像回放页面
    m_recordPlayPage->setGeometry(0, 103, m_recordPlayPage->width(), m_recordPlayPage->height());
    m_inteAnalyPage = new inteAnalyWidget(this);		 //智能分析页面
    m_inteAnalyPage->setGeometry(0, 103, m_inteAnalyPage->width(), m_inteAnalyPage->height());
    m_devManagePage = new devManageWidget(this);       //设备管理页面
    m_devManagePage->setGeometry(0, 103, m_devManagePage->width(), m_devManagePage->height());
    m_devUpdatePage = new devUpdateWidget(this);       //设备更新页面
    m_devUpdatePage->setGeometry(0, 103, m_devUpdatePage->width(), m_devUpdatePage->height());	
    m_pvmsMonitorPage->hide();
    m_recordPlayPage->hide();
    m_inteAnalyPage->hide();
    m_devManagePage->hide();
    m_devUpdatePage->hide();
	m_alarmPage = NULL;
	m_iAlarmPageOpenFlag = 0;

	for (i = 0; i < MAX_SERVER_NUM; i++)
	{
		m_iNoCheckDiskErrNum[i] = 0;
		m_iCheckDiskErrFlag[i] = 0;
	}

	/*信号与槽的连接初始化，使得信号触发时能做出相应正确的响应*/
	connect(m_pvmsMonitorPage, SIGNAL(getDevStateSignal()), m_devManagePage, SLOT(getDevStateSignalCtrl()));
	connect(m_pvmsMonitorPage, SIGNAL(setTimeSignal()), m_devUpdatePage, SLOT(setTimeSignalCtrl()));
	connect(m_recordPlayPage, SIGNAL(setRecordPlayFlagSignal(int)), m_pvmsMonitorPage, SLOT(setRecordPlayFlag(int)));
	connect(m_devUpdatePage, SIGNAL(systimeSetSignal()), m_pvmsMonitorPage, SLOT(systimeSetSlot()));
	connect(m_devManagePage, SIGNAL(systimeSetSignal()), m_pvmsMonitorPage, SLOT(systimeSetSlot()));
	connect(m_pvmsMonitorPage, SIGNAL(hideAlarmWidgetSignal()), this, SLOT(hideAlarmWidgetSlot()));
	connect(m_pvmsMonitorPage, SIGNAL(showAlarmWidgetSignal()), this, SLOT(showAlarmWidgetSlot()));
	connect(this, SIGNAL(blackScreenSignal()), m_pvmsMonitorPage, SLOT(blackScreenCtrlSlot()));
	connect(this, SIGNAL(blackScreenExitSignal()), m_pvmsMonitorPage, SLOT(blackScreenExitCtrlSlot()));

	connect(m_pvmsMonitorPage, SIGNAL(alarmPushButoonClickSignal()), this, SLOT(alarmPageShowSlot()));
	connect(m_recordPlayPage, SIGNAL(alarmPushButoonClickSignal()), this, SLOT(alarmPageShowSlot()));
	connect(m_devManagePage, SIGNAL(alarmPushButoonClickSignal()), this, SLOT(alarmPageShowSlot()));
	connect(m_devUpdatePage, SIGNAL(alarmPushButoonClickSignal()), this, SLOT(alarmPageShowSlot()));
    connect(m_devManagePage, SIGNAL(serverOffLine(int)), this, SLOT(serverOffLineSlot(int)));
	
    ui->pvmsMonitorMenuPushButton->setFocusPolicy(Qt::NoFocus); // 得到焦点时，不显示虚线框
    ui->recordPlayMenuPushButton->setFocusPolicy(Qt::NoFocus);
    ui->inteAnalyMenuPushButton->setFocusPolicy(Qt::NoFocus);
    ui->devManageMenuPushButton->setFocusPolicy(Qt::NoFocus);
    ui->devUpdateMenuPushButton->setFocusPolicy(Qt::NoFocus);
    ui->loginOutPushButton->setFocusPolicy(Qt::NoFocus);
	
    connect(ui->loginOutPushButton, SIGNAL(clicked()), this, SLOT(registOutButtonClick()));    
    connect(ui->pvmsMonitorMenuPushButton, SIGNAL(clicked()), this, SLOT(menuButtonClick()));     //连接受电弓监控菜单按钮的按键信号和响应函数
    connect(ui->recordPlayMenuPushButton, SIGNAL(clicked()), this, SLOT(menuButtonClick()));	  //连接录像回放菜单按钮的按键信号和响应函数
    connect(ui->inteAnalyMenuPushButton, SIGNAL(clicked()), this, SLOT(menuButtonClick()));		  //连接智能分析菜单按钮的按键信号和响应函数
    connect(ui->devManageMenuPushButton, SIGNAL(clicked()), this, SLOT(menuButtonClick()));		  //连接设备管理菜单按钮的按键信号和响应函数
    connect(ui->devUpdateMenuPushButton, SIGNAL(clicked()), this, SLOT(menuButtonClick()));		  //连接设备更新菜单按钮的按键信号和响应函数

	ui->pvmsMonitorMenuPushButton->setChecked(true);
	ui->recordPlayMenuPushButton->setChecked(false);
	ui->inteAnalyMenuPushButton->setChecked(false);
	ui->devManageMenuPushButton->setChecked(false);
	ui->devUpdateMenuPushButton->setChecked(false);

    m_PmsgTimer = new QTimer(this);
    m_PmsgTimer->start(50);
    connect(m_PmsgTimer, SIGNAL(timeout()), this, SLOT(pmsgTimerFunc()));

    m_Rs485Timer = new QTimer(this);
    m_Rs485Timer->start(100);
    connect(m_Rs485Timer, SIGNAL(timeout()), this, SLOT(rs485TimerFunc()));
}

pvmsMenuWidget::~pvmsMenuWidget()
{
    if (m_PmsgTimer != NULL)
    {
        if (m_PmsgTimer ->isActive())
        {
            m_PmsgTimer ->stop();
        }
        delete m_PmsgTimer;
        m_PmsgTimer  = NULL;
    }

    if (m_Rs485Timer != NULL)
    {
        if (m_Rs485Timer ->isActive())
        {
            m_Rs485Timer ->stop();
        }
        delete m_Rs485Timer;
        m_Rs485Timer  = NULL;
    }

	delete m_pvmsMonitorPage;
	m_pvmsMonitorPage = NULL;
	delete m_recordPlayPage;
	m_recordPlayPage = NULL;
	delete m_inteAnalyPage;
	m_inteAnalyPage = NULL;
	delete m_devManagePage;
	m_devManagePage = NULL;
	delete m_devUpdatePage;	
	m_devUpdatePage = NULL;
	if (m_alarmPage!= NULL)
	{
		delete m_alarmPage;
	}
    delete ui;
}

void pvmsMenuWidget::blackScreenCtrlSlot()   //黑屏触发，触发黑屏信号通知m_pvmsMonitorPage子界面
{
	emit blackScreenSignal();
}

void pvmsMenuWidget::blackScreenExitCtrlSlot()  //黑屏退出，触发黑屏退出信号通知m_pvmsMonitorPage子界面
{
	this->update();
	emit blackScreenExitSignal();
}

void pvmsMenuWidget::alarmHappenSlot()     //报警触发，触发报警信号通知上一层的MyApplication界面
{
	emit alarmHappenSignal();
}

void pvmsMenuWidget::alarmClearSlot()  //报警清除，触发报警清除信号通知上一层的MyApplication界面
{
	emit alarmClearSignal();
}

void pvmsMenuWidget::alarmPageShowSlot()
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "alarm  button pressed!\n");

	if (m_alarmPage== NULL)
    {
        m_alarmPage = new alarmWidget(this);      //新建报警信息显示窗体
		m_alarmPage->setGeometry(195, 189, m_alarmPage->width(), m_alarmPage->height());
        m_alarmPage->show();
        connect(m_alarmPage, SIGNAL(SendEscape()), this, SLOT(closeAlarmWidget()));
		connect(this, SIGNAL(reflushAlarmPageSignal(int, int, int)), m_alarmPage, SLOT(reflushAlarmPageSlot(int, int, int)));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), this, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), this, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_pvmsMonitorPage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_pvmsMonitorPage, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_recordPlayPage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_recordPlayPage, SLOT(alarmClearSlot()));  
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_devManagePage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_devManagePage, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_devUpdatePage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_devUpdatePage, SLOT(alarmClearSlot()));
    }
	else
	{
		m_alarmPage->show();
	}
	
	m_iAlarmPageOpenFlag = 1;
	m_alarmPage->triggerAlarmCleanSignal();
}
  
void pvmsMenuWidget::hideAlarmWidgetSlot()
{
	if (m_alarmPage != NULL)
    {
    	m_alarmPage->hide();
	}
}

void pvmsMenuWidget::showAlarmWidgetSlot()
{
	if ((m_alarmPage != NULL) && (1 == m_iAlarmPageOpenFlag))
    {
    	m_alarmPage->show();
	}
}

void pvmsMenuWidget::closeAlarmWidget()
{ 
	m_iAlarmPageOpenFlag = 0;
    m_alarmPage->hide();
}

void pvmsMenuWidget::serverOffLineSlot(int iDex)   //服务器离线后将服务器检测硬盘错误标志及不检测计数清0，使得再次连上服务器后头3分钟依然不处理硬盘报警
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenuWidget server %d OffLine\n", iDex);
	
	T_TRAIN_CONFIG tTrainConfigInfo;
	
	m_iCheckDiskErrFlag[iDex] = 0;
	m_iNoCheckDiskErrNum[iDex] = 0;

	memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
	STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);

	emit reflushAlarmPageSignal(ALARM_SERVER_OFFLINE, tTrainConfigInfo.tNvrServerInfo[iDex].iCarriageNO, 0);   //触发服务器离线报警信息，清除所有与服务器相关的报警及其附属相机相关的报警
}

void pvmsMenuWidget::recvPmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen)  //与服务器通信消息的分发处理
{
	int iAlarmType = 0, iDevPos = 0, iShadeAlarmEnableFlag = 0, i = 0;
	T_TRAIN_CONFIG tTrainConfigInfo;
	
	switch(ucMsgCmd)    //不同的应答消息类型分发给不同的页面处理
	{
		case SERV_CLI_MSG_TYPE_SET_PTZ_RESP:
		case SERV_CLI_MSG_TYPE_SET_PRESETS_RESP:
		case SERV_CLI_MSG_TYPE_PVMS_IPC_CTRL_RESP:
		case SERV_CLI_MSG_TYPE_PVMS_LIGHT_CTRL_RESP:
		case SERV_CLI_MSG_TYPE_PVMS_UPDOWN_REPORT:
		case SERV_CLI_MSG_TYPE_PVMS_UP_DOWN_CTRL:
		{
			DebugPrint(DEBUG_PMSG_NORMAL_PRINT, "pvmsMenu Widget get pmsg message 0x%x, msgDataLen=%d\n",(int)ucMsgCmd, iMsgDataLen);
            if (m_pvmsMonitorPage != NULL)
			{
                m_pvmsMonitorPage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
			}
			break;
		}
		case SERV_CLI_MSG_TYPE_GET_RECORD_TIME_LEN_RESP:
		case SERV_CLI_MSG_TYPE_GET_RECORD_FILE_RESP:	
		{
			DebugPrint(DEBUG_PMSG_NORMAL_PRINT, "pvmsMenu Widget get pmsg message 0x%x, msgDataLen=%d\n",(int)ucMsgCmd, iMsgDataLen);
            if (m_recordPlayPage != NULL)
			{
                m_recordPlayPage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
			}
			break;
	    }
	    case SERV_CLI_MSG_TYPE_GET_NVR_STATUS_RESP:
		{
			if (pcMsgData == NULL || iMsgDataLen != 18)
			{
				break;
			}
			else
			{
                if (m_devManagePage != NULL)
				{
                    m_devManagePage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
				}
				
				memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
				STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
				for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
    			{  
    				if (pHandle == STATE_GetNvrServerPmsgHandle(i))
    				{						
						/*第一次连上服务器的3分钟之内不检测硬盘是否异常*/
                        if (0 == m_iCheckDiskErrFlag[i])
						{
                            m_iNoCheckDiskErrNum[i]++;
                            if (18 == m_iNoCheckDiskErrNum[i])
							{
                                m_iCheckDiskErrFlag[i] = 1;
                                m_iNoCheckDiskErrNum[i] = 0;
							}
						}

						T_NVR_STATUS *ptNvrstaus = (T_NVR_STATUS *)pcMsgData;
						if (htons(ptNvrstaus->i16HdiskTotalSize) <= 0)
						{
                            if (1 == m_iCheckDiskErrFlag[i])
							{
								iAlarmType = ALARM_HDISK_ERR;
							}
						}
						else
						{
							iAlarmType = ALARM_HDISK_CLEAR;
						}	

                        if (tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO <= 0)
                        {
                            break;
                        }
                        emit reflushAlarmPageSignal(iAlarmType, tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO, 0);
						break;
    				}
				}				
			}
			break;
		}
		case SERV_CLI_MSG_TYPE_GET_IPC_STATUS_RESP:
		case SERV_CLI_MSG_TYPE_PISMSG_REPORT:
		{
			DebugPrint(DEBUG_PMSG_NORMAL_PRINT, "pvmsMenu Widget get pmsg message 0x%x, msgDataLen=%d\n",(int)ucMsgCmd, iMsgDataLen);
            if (m_devManagePage != NULL)
			{
                m_devManagePage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
			}
			break;
	    }
		case SERV_CLI_MSG_TYPE_VIDEO_ALARM_REPORT:
		{
			DebugPrint(DEBUG_PMSG_NORMAL_PRINT, "pvmsMenu Widget get pmsg message 0x%x, msgDataLen=%d\n",(int)ucMsgCmd, iMsgDataLen);
			if (pcMsgData == NULL || iMsgDataLen != 4)
			{
				break;
			}
			else
			{
                if (m_devManagePage != NULL)
				{
                    m_devManagePage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
				}
				
				T_VIDEO_ALARM_STATUS *ptVideoAlarmStatus = (T_VIDEO_ALARM_STATUS *)pcMsgData;
				if (8 == ptVideoAlarmStatus->i8DevPos) 
				{
					iDevPos = 1;
				}
				else if (9 == ptVideoAlarmStatus->i8DevPos)
				{
					iDevPos = 2;
				}
				
				if (1 == ptVideoAlarmStatus->i8VideoShade)
				{
					iAlarmType = ALARM_VIDEO_SHADE;  //iAlarmType=1,表示遮挡报警
					iShadeAlarmEnableFlag = STATE_GetShadeAlarmEnableFlag();
					if (iShadeAlarmEnableFlag != 1)   //根据配置文件中的遮挡报警使能决定是否处理遮挡报警
					{
						break;
					}
				}
				else 
				{
					if (1 == ptVideoAlarmStatus->i8VideoLost)
					{
						iAlarmType = ALARM_VIDEO_LOST;   //iAlarmType=2,表示丢失报警
					}
					else 
					{
						iAlarmType = ALARM_VIDEO_CLEAR;  //iAlarmType=0,表示报警恢复
					}
				}

				memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
				STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
				for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
    			{
    				if (pHandle == STATE_GetNvrServerPmsgHandle(i))
    				{
                        if (tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO <= 0 || (iDevPos != 1 && iDevPos != 2))
                        {
                            break;
                        }
                        emit reflushAlarmPageSignal(iAlarmType, tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO, iDevPos);
						break;
    				}
				}			
	            break;
			}
        }
		#if 0
		case SERV_CLI_MSG_TYPE_HDISK_ALARM_REPORT:	
		{			
			DebugPrint(DEBUG_PMSG_DATA_PRINT, "pvmsMenu Widget get pmsg message data:\n%s\n",pcMsgData);
			if (pcMsgData == NULL || iMsgDataLen != 2)
			{
				break;
			}
			else
			{
                if (m_devManagePage != NULL)
				{
                    m_devManagePage->pmsgCtrl(pHandle, ucMsgCmd, pcMsgData, iMsgDataLen);
				}
				
				T_HDISK_ALARM_STATUS *ptHdiskAlarmStatus = (T_HDISK_ALARM_STATUS *)pcMsgData;
				
				if (1 == ptHdiskAlarmStatus->i8HdiskLost)
				{
					iAlarmType = ALARM_HDISK_LOST;
				}
				else if (1 == ptHdiskAlarmStatus->i8HdiskBad)
				{
					iAlarmType = ALARM_HDISK_ERR;
				}
				else
				{
					iAlarmType = ALARM_HDISK_CLEAR;
				}

				memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
				STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
				for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
    			{
    				if (pHandle == STATE_GetNvrServerPmsgHandle(i))
    				{
    					iCarriageNO = tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO;
						break;
    				}
				}
                if (iCarriageNO <= 0)
                {
                    break;
                }
                emit reflushAlarmPageSignal(iAlarmType, iCarriageNO, 0);
			}
			break;
	    }
		#endif
		default:
			break;
	}
}

void pvmsMenuWidget::recvRs485Ctrl(char *pcData, int iDataLen)
{
    if (m_devManagePage != NULL)
	{
        m_devManagePage->rs485Ctrl(pcData, iDataLen);
	}
}

void pvmsMenuWidget::showPageSlot()      
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget show\n");
    this->show();
    m_recordPlayPage->hide();
    m_inteAnalyPage->hide();
    m_devManagePage->hide();
    m_devUpdatePage->hide();
    m_pvmsMonitorPage->show(); 
	m_pvmsMonitorPage->startVideoPolling();   //启动视频轮询
	m_pvmsMonitorPage->enableVideoPlay(1);   //运行受电弓监控页面解码的显示  

	if (NULL == m_alarmPage)
	{
		m_alarmPage = new alarmWidget(this);
		m_alarmPage->setGeometry(195, 189, m_alarmPage->width(), m_alarmPage->height());
		m_alarmPage->hide();

		connect(m_alarmPage, SIGNAL(SendEscape()), this, SLOT(closeAlarmWidget()));
		connect(this, SIGNAL(reflushAlarmPageSignal(int, int, int)), m_alarmPage, SLOT(reflushAlarmPageSlot(int, int, int)));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), this, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), this, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_pvmsMonitorPage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_pvmsMonitorPage, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_recordPlayPage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_recordPlayPage, SLOT(alarmClearSlot()));  
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_devManagePage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_devManagePage, SLOT(alarmClearSlot()));
		connect(m_alarmPage, SIGNAL(alarmHappenSignal()), m_devUpdatePage, SLOT(alarmHappenSlot()));
		connect(m_alarmPage, SIGNAL(alarmClearSignal()), m_devUpdatePage, SLOT(alarmClearSlot()));
	}
}

void pvmsMenuWidget::registOutButtonClick()      //注销按钮按键信号相应槽函数
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget registOutButton pressed!\n");
	m_pvmsMonitorPage->closePlayWin();   //关闭受电弓监控界面的播放窗口
	m_recordPlayPage->closePlayWin();   //关闭录像回放界面的播放窗口
	m_pvmsMonitorPage->m_iPresetPasswdOkFlag = 0;
    this->hide();
    emit registOutSignal(PVMSPAGETYPE);    //触发注销信号，带上当前设备类型
}

void pvmsMenuWidget::menuButtonClick()        //主菜单各按钮按键信号响应，切换不同的界面
{
	char acUserType[16] = {0};
	
	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));

    QObject* Sender = sender();     //Sender->objectName(),可区分不同的信号来源，也就是不同的按钮按键
    if(Sender==0)
    {
        return ;       
    }

    if (Sender->objectName() == "pvmsMonitorMenuPushButton")     //受电弓监控按钮被按，则切换到受电弓监控页面
    {
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget pvmsMonitorMenuPushButton  pressed!\n");
        m_recordPlayPage->hide();
		m_recordPlayPage->closePlayWin();   //关闭录像回放界面的播放窗口
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget close recordplay window!\n");
        m_inteAnalyPage->hide();
        m_devManagePage->hide();
		if (m_devManagePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devManagePage->p_ipmethod->p_inputwidget->hide();
		}
        m_devUpdatePage->hide();
		if (m_devUpdatePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devUpdatePage->p_ipmethod->p_inputwidget->hide();
		}
        m_pvmsMonitorPage->show();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget set pvmsMonitorPage show!\n");
		m_pvmsMonitorPage->m_playWin->show();
		m_pvmsMonitorPage->enableVideoPlay(1);   //运行受电弓监控页面解码的显示

		ui->pvmsMonitorMenuPushButton->setChecked(true);
		ui->recordPlayMenuPushButton->setChecked(false);
		ui->inteAnalyMenuPushButton->setChecked(false);
		ui->devManageMenuPushButton->setChecked(false);
		ui->devUpdateMenuPushButton->setChecked(false);
    }
    else if (Sender->objectName() == "recordPlayMenuPushButton")     //录像回放按钮被按，则切换到录像回放页面 
    {
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget recordPlayMenuPushButton  pressed!\n");
        m_pvmsMonitorPage->hide();
		m_pvmsMonitorPage->m_playWin->hide();
        m_inteAnalyPage->hide();
		m_devManagePage->hide();
		if (m_devManagePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devManagePage->p_ipmethod->p_inputwidget->hide();
		}
        m_devUpdatePage->hide();
		if (m_devUpdatePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devUpdatePage->p_ipmethod->p_inputwidget->hide();
		}
        m_recordPlayPage->show();
		m_recordPlayPage->pageShowCtrl();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget set recordPlayPage show!\n");
		m_pvmsMonitorPage->enableVideoPlay(0);   //禁止受电弓监控页面解码显示
		ui->pvmsMonitorMenuPushButton->setChecked(false);
		ui->recordPlayMenuPushButton->setChecked(true);
		ui->inteAnalyMenuPushButton->setChecked(false);
		ui->devManageMenuPushButton->setChecked(false);
		ui->devUpdateMenuPushButton->setChecked(false);
    }
    else if (Sender->objectName() == "inteAnalyMenuPushButton")      //智能分析按钮被按，则切换到智能分析页面
    {
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget inteAnalyMenuPushButton  pressed!\n");
        m_pvmsMonitorPage->hide();
		m_pvmsMonitorPage->m_playWin->hide(); 
        m_recordPlayPage->hide();
		m_recordPlayPage->closePlayWin();   //关闭录像回放界面的播放窗口
		m_devManagePage->hide();
		if (m_devManagePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devManagePage->p_ipmethod->p_inputwidget->hide();
		}
        m_devUpdatePage->hide();
		if (m_devUpdatePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devUpdatePage->p_ipmethod->p_inputwidget->hide();
		}
        m_inteAnalyPage->show();
		m_inteAnalyPage->pageShowCtrl();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget set inteAnalyPage show!\n");
		m_pvmsMonitorPage->enableVideoPlay(0);  //禁止受电弓监控页面解码显示
		ui->pvmsMonitorMenuPushButton->setChecked(false);
		ui->recordPlayMenuPushButton->setChecked(false);
		ui->inteAnalyMenuPushButton->setChecked(true);
		ui->devManageMenuPushButton->setChecked(false);
		ui->devUpdateMenuPushButton->setChecked(false);
    }
    else if (Sender->objectName() == "devManageMenuPushButton")      //设备管理按钮被按，则切换到设备管理页面
    {
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget devManageMenuPushButton  pressed!\n");
    	if (!strcmp(acUserType, "operator"))   //操作员不能查看此界面
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "pvmsMenu Widget this user type has not this right!\n");
			QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("该用户没有查看权限!"));     
		    box.setStandardButtons (QMessageBox::Ok);   
		    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
		    box.exec();
			return;
		}
        m_pvmsMonitorPage->hide();
		m_pvmsMonitorPage->m_playWin->hide();
        m_recordPlayPage->hide();
		m_recordPlayPage->closePlayWin();   //关闭录像回放界面的播放窗口
        m_inteAnalyPage->hide();
        m_devUpdatePage->hide();
		if (m_devUpdatePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devUpdatePage->p_ipmethod->p_inputwidget->hide();
		}
        m_devManagePage->show();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget set devManagePage show!\n");
		if (m_devManagePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devManagePage->p_ipmethod->p_inputwidget->hide();
		}
		m_pvmsMonitorPage->enableVideoPlay(0);  //禁止受电弓监控页面解码显示
		ui->pvmsMonitorMenuPushButton->setChecked(false);
		ui->recordPlayMenuPushButton->setChecked(false);
		ui->inteAnalyMenuPushButton->setChecked(false);
		ui->devManageMenuPushButton->setChecked(true);
		ui->devUpdateMenuPushButton->setChecked(false);
    }
    else if (Sender->objectName() == "devUpdateMenuPushButton")     //设备更新按钮被按，则切换到设备更新页面
    {
		DebugPrint(DEBUG_UI_OPTION_PRINT, "pvmsMenu Widget devUpdateMenuPushButton  pressed!\n");
    	if (!strcmp(acUserType, "operator"))   //操作员不能查看此界面
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "pvmsMenu Widget this user type has not this right!\n");
			QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("该用户没有查看权限!"));     
		    box.setStandardButtons (QMessageBox::Ok);   
		    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     
		    box.exec();
			return;
		}
        m_pvmsMonitorPage->hide();
		m_pvmsMonitorPage->m_playWin->hide();
        m_recordPlayPage->hide();
		m_recordPlayPage->closePlayWin();   //关闭录像回放界面的播放窗口
        m_inteAnalyPage->hide();
        m_devManagePage->hide();
		if (m_devManagePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devManagePage->p_ipmethod->p_inputwidget->hide();
		}
        m_devUpdatePage->show();
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "pvmsMenu Widget set devUpdatePage show!\n");
		if (m_devUpdatePage->p_ipmethod->p_inputwidget != NULL)
		{
			m_devUpdatePage->p_ipmethod->p_inputwidget->hide();
		}
		m_pvmsMonitorPage->enableVideoPlay(0);  //禁止受电弓监控页面解码显示
		ui->pvmsMonitorMenuPushButton->setChecked(false);
		ui->recordPlayMenuPushButton->setChecked(false);
		ui->inteAnalyMenuPushButton->setChecked(false);
		ui->devManageMenuPushButton->setChecked(false);
		ui->devUpdateMenuPushButton->setChecked(true);
    }
}

