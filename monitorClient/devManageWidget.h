#ifndef DEVMANAGEWIDGET_H
#define DEVMANAGEWIDGET_H

#include <QWidget>
#include <QTimer>
#include "commonInputMethod.h"
#include "pmsgcli.h"
#include "state.h"

namespace Ui {
class devManageWidget;
}

class devManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit devManageWidget(QWidget *parent = 0);
    ~devManageWidget();
    commonInputMethod *p_ipmethod;
    int pmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen);
    int rs485Ctrl(char *pcData, int iDataLen);
    void pisMsgCtrl(char *pcMsgData);
    void videoAlarmCtrl(PMSG_HANDLE pHandle, char *pcMsgData);
    void getNvrStatusCtrl(PMSG_HANDLE pHandle, char *pcMsgData);
    void getIpcStatusCtrl(PMSG_HANDLE pHandle, char *pcMsgData);

public slots:
	void trainNumberChange(QString TrainNumberStr);
    void trainNumberSetSlot();
	void trainNumberButtonClickSlot();
	void getDevStateSignalCtrl();
	void closeKeyboardWidgetSlot(); 
	void alarmPushButoonClickSlot();
	void alarmHappenCtrlSlot();
	void alarmHappenSlot();
	void alarmClearSlot();

signals:
	void enterKeyPressSignal();
	void alarmPushButoonClickSignal();
	void serverOffLine(int iDex);	
	void systimeSetSignal();

private:
    Ui::devManageWidget *ui;
    QTimer *m_alarmHappenTimer;
    PMSG_HANDLE m_NvrServerPhandle[MAX_SERVER_NUM];    //nvr服务器PMSG通信句柄
    int m_aiServerIdex[MAX_SERVER_NUM];   //服务器在表中的行号索引，方便获取到服务器状态信息后刷新表对应的行，下标与m_Phandle是一一对应的
    int m_aiCameraIdex[MAX_SERVER_NUM][MAX_CAMERA_OFSERVER];   //每组服务器包含的摄像机在表中的行号索引，方便获取到摄像机状态信息后刷新表对应的行，一维下标与m_Phandle是一一对应的
	int m_aiNvrOnlineFlag[MAX_SERVER_NUM];   //服务器在线状态
	int m_aiCameraOnlineFlag[MAX_SERVER_NUM][MAX_CAMERA_OFSERVER];   //每组服务器包含的摄像机的在线状态 
	int m_iCheckDiskErrFlag[MAX_SERVER_NUM];  //是否检查服务器硬盘错误标志
	int m_iNoCheckDiskErrNum[MAX_SERVER_NUM];   //不检测服务器硬盘错误计数，每10秒加1
	QString m_TrainNumEditSave;
    void getTrainConfig();     //获取车型配置信息
};

#endif // DEVMANAGEWIDGET_H
