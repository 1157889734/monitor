#ifndef DEVUPDATEWIDGET_H
#define DEVUPDATEWIDGET_H

#include <QWidget>
#include <QTimer>
#include "commonInputMethod.h"
#include "userManage.h"
#include "state.h"
#include "pmsgcli.h"
#include "localsetPasswdConfirm.h"
#include "localSet.h"
#include "timeset.h"

namespace Ui {
class devUpdateWidget;
}

class devUpdateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit devUpdateWidget(QWidget *parent = 0);
    ~devUpdateWidget();
    commonInputMethod *p_ipmethod;
    bool eventFilter(QObject *target, QEvent *event);

public slots:
    void userManageSlot();
	void configFileSelectionSlot();
	void configFileImportSlot();
    void closeUserManageWidget();
    void closeLocalSetPasswdConfirmWidget(); 
    void closeLocalSetWidget();
    void timeManuelSetSlot();
	void localSetPasswdOkCtrl();
    void setBrightnessLineEditValue(int value);
	void setSaturationLineEditValue(int value);
	void setContrastLineEditValue(int value);
    void setTrainType();
    void pollingTimeChange(int iComboBoxId);
	void presetReturnTimeChange(int iComboBoxId);
	void setSystemTime();
	void setCameraImageParamSlot();
	void devUpdateSlot();
	void devRebootSlot();
	//void serverRebootSlot();
	
	void devLocalSetSlot();
	void inputWidgetExitSlot();
	void inputWidgetEnterSlot();
	void setTimeSignalCtrl();
	void alarmPushButoonClickSlot();
	void alarmHappenCtrlSlot();
	void alarmHappenSlot();
	void alarmClearSlot();
	void openTimeSetWidgetSlot();
    void timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec);

signals:	
	void alarmPushButoonClickSignal();
	void systimeSetSignal();

private:
    Ui::devUpdateWidget *ui;
    QTimer *m_alarmHappenTimer;
    LocalsetPasswdConfirm *localSetPasswdConfirmWidget;
    localSet *localSetWidget;
    userManage *usermanagePage;
    timeSet *timeSetWidget;    //时间设置控制窗体
    QString m_TrainType;
    QString m_pollingtTimeText;
    QString m_presetReturnTimeText;
    QString m_brightNessText;
    QString m_saturationText;
    QString m_contrastText;
    PMSG_HANDLE m_Phandle[MAX_SERVER_NUM];    //服务器PMSG通信句柄
    void getTrainConfig();     //获取车型配置信息
    void setTrainTypeCombox();
	void setPollingTimeRadioButton();	  //设置轮询时间单选按钮组的样式
	void setPresetReturnTimeRadioButton();	   //设置预置点返回时间单选按钮组的样式
};

#endif // DEVUPDATEWIDGET_H
