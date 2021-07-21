#ifndef PVMSMENUWIDGET_H
#define PVMSMENUWIDGET_H

#include "pvmsMonitorWidget.h"
#include "recordPlayWidget.h"
#include "inteAnalyWidget.h"
#include "devManageWidget.h"
#include "devUpdateWidget.h"
#include "alarmWidget.h"
#include "state.h"
#include "rs485serv.h"
#include <QWidget>
#include <QTimer>

namespace Ui {
class pvmsMenuWidget;
}

class pvmsMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pvmsMenuWidget(QWidget *parent = 0);
    ~pvmsMenuWidget();
    void recvPmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen);
    void recvRs485Ctrl(char *pcData, int iDataLen);
    PRS485_HANDLE m_pRs485Handle;

public slots:
    void showPageSlot();     //显示当前页面的响应槽函数
    void registOutButtonClick();
    void menuButtonClick();	
    void blackScreenCtrlSlot();
    void blackScreenExitCtrlSlot();
    void alarmHappenSlot();
    void alarmClearSlot();
    void alarmPageShowSlot();
    void hideAlarmWidgetSlot();
    void showAlarmWidgetSlot();
	void closeAlarmWidget();
	void serverOffLineSlot(int iDex);
    void pmsgTimerFunc();
    void rs485TimerFunc();

signals:
    void registOutSignal(int iType);     //注销信号，iType:表示执行注销的页面类型，这里应该为2，表示受电弓监控页面,
    void reflushAlarmPageSignal(int iAlarmType, int iCarriageNO, int iDevPos);
    void alarmHappenSignal();
    void alarmClearSignal();
    void blackScreenSignal();
    void blackScreenExitSignal();
	
private:
    Ui::pvmsMenuWidget *ui;
    pvmsMonitorWidget *m_pvmsMonitorPage;
    recordPlayWidget *m_recordPlayPage;
    inteAnalyWidget *m_inteAnalyPage;
    devManageWidget *m_devManagePage;
    devUpdateWidget *m_devUpdatePage;
    alarmWidget *m_alarmPage;
    QTimer *m_PmsgTimer;
    QTimer *m_Rs485Timer;
    int m_iAlarmPageOpenFlag;
    int m_iCheckDiskErrFlag[MAX_SERVER_NUM];  //是否检查服务器硬盘错误标志
	int m_iNoCheckDiskErrNum[MAX_SERVER_NUM];   //不检测服务器硬盘错误计数，每10秒加1
};

#endif // PVMSMENUWIDGET_H
