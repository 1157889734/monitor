#ifndef PVMSMONITOR_H
#define PVMSMONITOR_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <time.h>
#include "CMPlayer.h"
#include "pmsgcli.h"
#include "presetPasswdConfirm.h"
#include "state.h"

namespace Ui {
class pvmsMonitorWidget;
}

typedef enum _E_CAMERA_STATE    //摄像机状态
{
	CAMERA_ON = 1,    //开启状态
	CAMERA_OFF = 2    //关闭状态
} E_CAMERA_STATUE;

typedef enum _E_FILLLIGHT_STATE     //补光灯状态
{
	FILLLIGHT_ON = 1,    //开启状态
	FILLLIGHT_OFF = 2   //关闭状态
} E_FILLLIGHT_STATUE;

typedef enum _E_PVMSUPDOWN_STATE    //升降弓状态
{
	PVMS_DOWN = 0,   //降弓
	PVMS_UP = 1    //升弓
} E_PVMSUPDOWN_STATE;

typedef enum _E_CMP_CMD
{
    CMP_CMD_CREATE_CH,
    CMP_CMD_DESTORY_CH,
    CMP_CMD_ENABLE_CH,
    CMP_CMD_DISABLE_CH,
	CMP_CMD_CHG_ALL_VIDEOWIN,
	CMP_CMD_GET_STREAM_STATE
} E_CMP_CMD;

typedef struct _T_CMP_PACKET
{
    int iMsgCmd;  //E_CMP_CMD
    int iCh;
} T_CMP_PACKET, *PT_CMP_PACKET;

typedef struct _T_CMP_PACKET_LIST
{
    T_CMP_PACKET tPkt;
    struct _T_CMP_PACKET_LIST *next;
} T_CMP_PACKET_LIST;

typedef struct _T_CMP_QUEUE
{
    T_CMP_PACKET_LIST *ptFirst, *ptLast;
    INT32 iQueueType;  // 0:先进先出(FIFO)，1:后进先出(LIFO)
    INT32 iPktCount;
    pthread_mutex_t *pMutex;				
} T_CMP_QUEUE, *PT_CMP_QUEUE;

typedef struct _T_CAMERA_INFO
{
	char acCameraRtspUrl[128];    //保存rtsp地址
	int iPosNO;    //位置号
	int iCameraSwitchState;    //摄像头开关状态，E_CAMERA_STATUE
	int iFillLightSwitchState;   //补光灯开关状态，E_FILLLIGHT_STATUE
	int iPvmsUpdownState;   //升降弓状态，E_PVMSUPDOWN_STATE
    QTimer *pvmsDownMonitorTimer;    //降弓监控定时器，收到降弓信号10分钟无升弓则要关闭补光灯
	int iPresetNo;  //预置点编号
	int iCmpOpenFlag;    //摄像头打开标志
	int iManualFillLightCtrlFlag;   //手动操作补光灯标志
	int iStreamState;
	time_t tPtzOprateTime;    //云台操作时间
	PMSG_HANDLE phandle;   //所属服务器的通信句柄
	CMPHandle cmpHandle;    //客户端媒体播放句柄
} __attribute__((packed)) T_CAMERA_INFO, *PT_CAMERA_INFO;

class pvmsMonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pvmsMonitorWidget(QWidget *parent = 0);
    ~pvmsMonitorWidget();
    bool eventFilter(QObject *target, QEvent *event);  //事件过滤器
    time_t m_lastActionTime;    //界面最后一次操作时间
    QLabel *m_channelStateLabel;  
    QLabel *m_channelNoLabel;
    QWidget *m_playWin;    //播放窗体
    QPushButton *m_presetNoPushbutton[8]; 
    int m_iFullScreenFlag;   //全屏标识
    int m_iThreadRunFlag;   //线程运行标识
    int m_iPollingFlag;   //轮询标识
    time_t tPollingOparateTime;  //轮询操作时间
    int m_iCameraNum;  //摄像机总数 
    int m_iCameraPlayNo;   //正在播放的摄像机编号，与m_tCameraRtspUrl的下标对应
    int m_iCameraSwitchState;
    int m_iPresetReturnFlag;    //预置点返回标识
    int m_iSelectPresetNo;   //保存选中的预置点编号
    int m_iPtzCtrType;   //正在进行的云台控制类型
    int m_iPtzMoveType;   //正在进行的云台操作类型类型，开始或停止
    int m_iDisplayEnable;  //显示全局使能标识
    int m_iSystimeChangeFlag;   //系统时间改变标志
    int m_iAlarmNotCtrlFlag;   //有报警信息未处理标志
    int m_iPisGetFlag;   //从PIS接收过消息的标志
    int m_iRecordPlayFlag;   //是否在回放标志，1-在回放，0-未回放
    int m_iOldRecordPlayFlag;
    int m_iBlackScreenFlag;   //黑屏标志
    int m_iPresetPasswdOkFlag;
    int m_iMousePosX;
    int m_iMousePosY;
    int pmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen);   //与服务器通信消息处理
    CMPHandle m_cmpHandle;    //客户端媒体播放句柄
    pthread_t m_threadId;    //线程ID
    PMSG_HANDLE m_NvrServerPhandle[MAX_SERVER_NUM];    //nvr服务器PMSG通信句柄
    PMSG_HANDLE m_PisServerPhandle;    //pis服务器PMSG通信句柄
    T_CAMERA_INFO m_tCameraInfo[MAX_SERVER_NUM*MAX_CAMERA_OFSERVER];    //保存的所有摄像机信息
    PT_CMP_QUEUE m_ptQueue;
    pthread_mutex_t tMutex;
    void startVideoPolling();
   	void enableVideoPlay(int iFlag);  //设置显示全局使能标识
   	void triggerVideoPollingSignal();
   	void triggerFullScreenSignal();
   	void triggerPresetReturnSignal(int iCameraNO);
	void triggerGetDevStateSignal();
	void triggerSetTimeSignal();
	void triggerRecordPlayCtrlSignal();
	void triggerCmpOptionCtrlSinal(int iType, int iCh);
    void pvmsUpdownCtrl(char *pcMsgData);
	void closePlayWin();
    void videoChannelCtrl();
    void noPollingChOption();
    void getChStreamState(int iCh);

public slots:
    void startPollingSlot();  //开始按钮按键信号响应槽函数，设置轮询使能
	void pausePollingSlot();  //暂停按钮按键信号响应槽函数，设置轮询使能
    void presetNoGroupButtonClickSlot(int iButtonNo);     //预置点编号按钮组按键信号响应槽函数，iButtonNo为按钮编号
	void presetSetCtrlSlot();
	void presetGetCtrlSlot();
	void cameraSwitchSlot();
	void fillLightSwitchSlot();
	void manualSwitchLastCameraSlot();
	void manualSwitchNextCameraSlot();
   	void closePresetPasswdPageSlot();   //关闭预置点密码确认界面槽函数
   	void setPresetSlot();
	void videoPollingSignalCtrl();
	void setFullScreenSignalCtrl();
	void presetReturnSignalCtrl(int iCameraNO);
	void setRecordPlayFlag(int iFlag);
	void temporarySaveBeginSlot();
	void temporarySaveEndSlot();
	void systimeSetSlot();
	void alarmPushButoonClickSlot();
	void alarmHappenCtrlSlot();	
	void alarmHappenSlot();	
	void alarmClearSlot();
	void cameraSwitchEndSlot();
	void fillLightSwitchEndSlot();
	void manualSwitchEndSlot();
	void blackScreenCtrlSlot();
	void blackScreenExitCtrlSlot();
    void recordPlayCtrlSlot();
	void pvmsDownEndSlot1();
	void pvmsDownEndSlot2();
	void pvmsDownEndSlot3();
	void pvmsDownEndSlot4();	
    void cmpOptionCtrlSlot(int iType, int iCh);
	void chLabelDisplayCtrlSlot();   //通道状态和通道号标签是否显示的处理函数
	void chStateLabelTextCtrlSlot(int iFlag);   //通道状态标签文本显示的处理函数，0-显示关闭，1-显示开启
	void camSwitchButtonTextCtrlSlot(int iFlag);   //摄像机开关状态按钮文本显示的处理函数，0-显示关闭，1-显示开启
	void fillLightSwitchButtonTextCtrlSlot(int iFlag);   //补光灯开关状态按钮文本显示的处理函数，0-显示关闭，1-显示开启
	
signals:
	void videoPollingSignal();
	void setFullScreenSignal();
	void presetReturnSignal(int iCameraNO);
	void getDevStateSignal();
	void setTimeSignal();
	void alarmPushButoonClickSignal();
	void hideAlarmWidgetSignal();
	void showAlarmWidgetSignal();
	void recordPlayCtrlSignal();	
    void cmpOptionCtrlSignal(int iType, int iCh);
	void chLabelDisplayCtrlSignal();   //通道状态和通道号标签是否显示的处理信号
	void chStateLabelTextCtrlSignal(int iFlag);   //通道状态标签文本显示的处理信号，0-显示关闭，1-显示开启
	void camSwitchButtonTextCtrlSignal(int iFlag);   //摄像机开关状态按钮文本显示的处理信号，0-显示关闭，1-显示开启
	void fillLightSwitchButtonTextCtrlSignal(int iFlag);   //补光灯开关状态按钮文本显示的处理信号，0-显示关闭，1-显示开启
	
private:
    Ui::pvmsMonitorWidget *ui;
    QTimer *m_temporarySaveTimer;
    QTimer *m_alarmHappenTimer;
    QTimer *m_cameraSwitchTimer;
    QTimer *m_fillLightSwitchTimer;
    QTimer *m_manualSwitchTimer;
    PresetPasswdConfirm *m_presetPasswdConfirmPage;    //预置点密码确认界面
};

#endif // PVMSMONITOR_H
