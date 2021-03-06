#include "waitLoginWidget.h"
#include "choiceLoginDevWidget.h"
#include "loginWidget.h"
#include "pvmsMenuWidget.h"
#include "choiceCarriageWidget.h"
#include "cvmsMenuWidget.h"
#include "CMPlayer.h"
#include "debug.h"
#include "log.h"
#include "state.h"
#include "pmsgcli.h"
#include "rs485serv.h"
#include "MyApplication.h"
#include <QApplication>
#include <QWSServer>
#include <QTextCodec>
#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>

#define DEBUG_PORT 9880

waitLoginWidget *g_waitLoginPage = NULL;  //等待登录页面
choiceLoginDevWidget *g_choiceLoginDevPage = NULL;    //选择登录设备页面
loginWidget *g_loginPage = NULL;   //登录页面
pvmsMenuWidget *g_pvmsMenuPage = NULL;   //受电弓监控主菜单页面
choiceCarriageWidget *g_choiceCarriagePage = NULL;    //车厢选择页面
cvmsMenuWidget *g_cvmsMenuPage = NULL;     //车厢监控主菜单页面

int main(int argc, char *argv[])
{
	char acNvrServerIp[128] = {0}, acClientVersion[64] = {0};
    int iWidth = 1024, iHeight = 768, iRet = 0, i = 0;
	short sYear = 0;	
	T_TRAIN_CONFIG tTrainConfigInfo;
	T_PIS_INFO tPisConfigInfo;
	T_PVMS_INFO tPvmsInfo;
	T_TIME_INFO tTimeInfo;
	T_LOG_INFO tLogInfo;
    T_CMPDEC_INFO tCmpDecInfo;                                
	PRS485_HANDLE pRs485Handle = 0;
	PMSG_HANDLE pmsgHandle = 0;
	
	signal(SIGPIPE,SIG_IGN);    
	
    memset(&tCmpDecInfo, 0, sizeof(T_CMPDEC_INFO));
    tCmpDecInfo.tVdecInfo.eVoType = CMP_VO_TYPE_HDMI;
    tCmpDecInfo.tVdecInfo.iScreenWidth = iWidth;
    tCmpDecInfo.tVdecInfo.iScreenHeight = iHeight;
	
	DebugInit(DEBUG_PORT);    //调试信息模块初始化 
	LOG_Init();    //本地日志模块初始化

	/*程序启动记录日志*/
	memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
	tLogInfo.iLogType = 0;
	STATE_GetSysVersion(acClientVersion, sizeof(acClientVersion));
	snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "Startup %s!", acClientVersion);  
	LOG_WriteLog(&tLogInfo);
	
    iRet = CMP_Init(&tCmpDecInfo);   //cmplayer客户端媒体播放模块初始化        
    if (iRet < 0)
    {
        DebugPrint(DEBUG_UI_ERROR_PRINT, "CMP_Init error, iRet=%d\n",iRet);
    }
	PMSG_Init();    //协议通信模块初始化

	STATE_ReadTrainConfigFile();	//程序运行起来读取一次车型配置文件
	/*获取车型配置信息，并创建与NVR服务器的通信连接,保存PMSG_HANDLE句柄*/    
	memset(&tTrainConfigInfo, 0, sizeof(T_TRAIN_CONFIG));
	STATE_GetCurrentTrainConfigInfo(&tTrainConfigInfo);
	for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
	{
		memset(acNvrServerIp, 0, sizeof(acNvrServerIp));
		snprintf(acNvrServerIp, sizeof(acNvrServerIp), "192.168.%d.81", 100+tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO);
        iRet = PMSG_CreateConnect(acNvrServerIp, 10100);
		if (0 == iRet)
		{
			DebugPrint(DEBUG_UI_ERROR_PRINT, "create connection to server:%s error!\n",acNvrServerIp);
			continue;
		}
		if (STATE_SetNvrServerPmsgHandle(i, (PMSG_HANDLE)iRet) < 0)
		{
			DebugPrint(DEBUG_UI_ERROR_PRINT, "save server:%s pmsg handle error!\n",acNvrServerIp);
		}
	}

	STATE_ReadPisConfig();
	memset(&tPisConfigInfo, 0, sizeof(T_PIS_INFO));
	STATE_GetPisConfigInfo(&tPisConfigInfo);
    iRet = PMSG_CreateConnect(tPisConfigInfo.acIpAddr, tPisConfigInfo.iPort);
	if (0 == iRet)
	{
		DebugPrint(DEBUG_UI_ERROR_PRINT, "create connection to server:%s error!\n",acNvrServerIp);
	}
	if (STATE_SetPisPmsgHandle((PMSG_HANDLE)iRet) < 0)
	{
		DebugPrint(DEBUG_UI_ERROR_PRINT, "save pis server pmsg handle error!\n");
	}

    pRs485Handle = RS485_CreateConnect();
	if (0 == pRs485Handle)
	{
		DebugPrint(DEBUG_UI_ERROR_PRINT, "rs485 connection error!\n");
	}

	usleep(1*1000*1000);

	QDateTime time = QDateTime::currentDateTime();
	sYear = time.date().year();
 	tTimeInfo.year = htons(sYear);
	tTimeInfo.mon = time.date().month();
	tTimeInfo.day = time.date().day();
	tTimeInfo.hour = time.time().hour();
	tTimeInfo.min = time.time().minute();
	tTimeInfo.sec = time.time().second();
	/*发送设置服务器连接的受电弓信息的报文给服务器，告知服务器受电弓信息, 并且对服务器进行校时*/
	for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
	{
		memset(&tPvmsInfo, 0, sizeof(T_PVMS_INFO));
		tPvmsInfo.i8PvmsVideoNum = tTrainConfigInfo.tNvrServerInfo[i].iPvmsCameraNum;
		tPvmsInfo.i8PvmsCarriageNo = tTrainConfigInfo.tNvrServerInfo[i].iPvmsCarriageNO;
		pmsgHandle = STATE_GetNvrServerPmsgHandle(i);
		iRet = PMSG_SendPmsgData(pmsgHandle, CLI_SERV_MSG_TYPE_SET_PVMS_INFO, (char *)&tPvmsInfo, sizeof(T_PVMS_INFO));
        if (iRet < 0)
        {
            DebugPrint(DEBUG_UI_ERROR_PRINT, "PMSG_SendPmsgData CLI_SERV_MSG_TYPE_SET_PVMS_INFO to server %d error!iRet=%d\n", i+1,iRet);
        }

		iRet = PMSG_SendPmsgData(pmsgHandle, CLI_SERV_MSG_TYPE_CHECK_TIME, (char *)&tTimeInfo, sizeof(T_TIME_INFO));    //发送校时命令
        if (iRet < 0)
        {
            DebugPrint(DEBUG_UI_ERROR_PRINT, "PMSG_SendPmsgData CLI_SERV_MSG_TYPE_CHECK_TIME to server %d error!iRet=%d\n", i+1,iRet);
        }
		else
		{
			memset(&tLogInfo, 0, sizeof(T_LOG_INFO));
			tLogInfo.iLogType = 0;
			snprintf(tLogInfo.acLogDesc, sizeof(tLogInfo.acLogDesc), "notify server %d Time Check OK %4d-%02d-%02d %02d:%02d:%02d!", 100+tTrainConfigInfo.tNvrServerInfo[i].iCarriageNO, 
				time.date().year(), time.date().month(), time.date().day(), time.time().hour(), time.time().minute(), time.time().second());
			LOG_WriteLog(&tLogInfo);
		}
	}

    MyApplication app(argc, argv);  //创建QT运行主应用程序
	
	//获取并设置Checkbox为自定义样式  
    QFile checkBoxQss(":/res/myCheckBox.qss");  
    checkBoxQss.open(QFile::ReadOnly);  
    app.setStyleSheet(checkBoxQss.readAll());  
	checkBoxQss.close();

	app.setWindowIcon(QIcon(":/res/info.png"));   //设置窗口图标，这里主要是messagebox窗体会显示，而避免出现QT图标
	
	g_waitLoginPage = new waitLoginWidget(); 
	g_choiceLoginDevPage = new choiceLoginDevWidget();
	g_loginPage = new loginWidget();
	g_pvmsMenuPage = new pvmsMenuWidget();
	g_choiceCarriagePage = new choiceCarriageWidget();
	g_cvmsMenuPage = new cvmsMenuWidget();

    g_waitLoginPage->show();
    g_choiceLoginDevPage->hide();
    g_loginPage->hide();
    g_pvmsMenuPage->hide();
    g_choiceCarriagePage->hide();   
    g_cvmsMenuPage->hide();

    g_pvmsMenuPage->m_pRs485Handle = pRs485Handle;

	QObject::connect(g_pvmsMenuPage, SIGNAL(alarmHappenSignal()), &app, SLOT(alarmHappenSignalCtrl()));
	QObject::connect(g_pvmsMenuPage, SIGNAL(alarmClearSignal()), &app, SLOT(alarmClearSignalCtrl()));
	QObject::connect(&app, SIGNAL(blackScreenSignal()), g_pvmsMenuPage, SLOT(blackScreenCtrlSlot()));
	QObject::connect(&app, SIGNAL(blackScreenExitSignal()), g_pvmsMenuPage, SLOT(blackScreenExitCtrlSlot()));
	
    /*等待登录页面的页面跳转信号连接选择登录设备页面的页面显示相应槽函数，这样一旦触发等待登录页面
	的页面跳转信号，即可相应选择登录设备页面的页面显示函数，以下的connect是同样的作用，信号和槽可以多对多*/
    QObject::connect(g_waitLoginPage, SIGNAL(pageRedirectSignal()), g_choiceLoginDevPage, SLOT(showPageSlot())); 
	
    QObject::connect(g_choiceLoginDevPage, SIGNAL(confirmDevTypeSignal(int)), g_loginPage, SLOT(showPageSlot(int)));    //选择登录设备页面的确认设备类型信号连接登录页面的页面显示槽
    QObject::connect(g_loginPage, SIGNAL(gotoPvmsMenuPageSignal()), g_pvmsMenuPage, SLOT(showPageSlot()));      //登录页面的受电弓监控页面跳转信号连接受电弓监控主菜单页面的页面显示槽
    QObject::connect(g_loginPage, SIGNAL(gotoCvmsMenuPageSignal()), g_choiceCarriagePage, SLOT(showPageSlot()));  //登录页面的车厢监控页面跳转信号连接车厢选择页面的页面显示槽
    QObject::connect(g_choiceCarriagePage, SIGNAL(confirmCarriageSignal()), g_cvmsMenuPage, SLOT(showPageSlot()));      //车厢选择页面的确认车厢信号连接车厢监控主菜单页面的页面显示槽
    QObject::connect(g_pvmsMenuPage, SIGNAL(registOutSignal(int)), g_loginPage, SLOT(showPageSlot(int)));       //受电弓监控主菜单页面的注销信号连接登录页面的页面显示槽
	QObject::connect(g_cvmsMenuPage, SIGNAL(registOutSignal(int)), g_loginPage, SLOT(showPageSlot(int))); 	  //车厢监控主菜单页面的注销信号连接登录页面的页面显示槽

	/*设置QT编码格式为UTF-8*/
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);

	QWSServer::setBackground(QColor(0,0,0,0));  //设置背景颜色    

    app.exec();  
	
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "will exit Qapplication!must do some thing here\n");  

	RS485_DestroyConnect(pRs485Handle);
	
	for (i = 0; i < tTrainConfigInfo.iNvrServerCount; i++)
	{
		pmsgHandle = STATE_GetNvrServerPmsgHandle(i);
		PMSG_DestroyConnect(pmsgHandle);
	}
	PMSG_DestroyConnect(STATE_GetPisPmsgHandle());
	
	usleep(1*1000*1000);
		
	/*删除所有Qt页面*/
	delete g_waitLoginPage;
	g_waitLoginPage = NULL;
	delete g_choiceLoginDevPage;
	g_choiceLoginDevPage = NULL;
	delete g_loginPage;
	g_loginPage = NULL;
	delete g_pvmsMenuPage;
	g_pvmsMenuPage = NULL;
	delete g_choiceCarriagePage;
	g_choiceCarriagePage = NULL;
	delete g_cvmsMenuPage;
	g_cvmsMenuPage = NULL;
	
	PMSG_Uninit();
	CMP_UnInit();
	LOG_UnInit();
	DebugUninit();
	
    return 0;
}
