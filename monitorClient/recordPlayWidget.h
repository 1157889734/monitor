#ifndef RECORDPLAY_H
#define RECORDPLAY_H

#include <QWidget>
#include <QTableWidget>
#include <QTimer>
#include "timeset.h"
#include "CMPlayer.h"
#include "pmsgcli.h"
#include "state.h"
#include "ftpApi.h"
#include "mySlider.h"

#define MAX_RECORD_SEACH_NUM 10000
#define MAX_RECFILE_PATH_LEN 256

namespace Ui {
class recordPlayWidget;
}

class recordPlayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit recordPlayWidget(QWidget *parent = 0);
    ~recordPlayWidget();
    timeSet *timeSetWidget;    //时间设置控制窗体
    int pmsgCtrl(PMSG_HANDLE pHandle, unsigned char ucMsgCmd, char *pcMsgData, int iMsgDataLen);     //与服务器通信消息处理
    int m_iPlayRange;    //录像文件总播放时长
    int m_iSliderValue;     //进度条当前值
    int m_iPlayFlag;   //播放标志，0-暂停状态，未播放，1-在播放
    double m_dPlaySpeed;   //播放速度
    void setPlaySldValue(int iValue);       //刷新进度条
    CMPHandle m_cmpHandle;   //客户端媒体播放句柄
    pthread_t m_threadId;      //刷新进度条线程ID
    int m_iThreadRunFlag;    //刷新进度条线程运行标识
    int m_iFtpServerIdex;    //当前ftp服务器索引编号
    mySlider *m_playSlider;    //播放进度条
    PFTP_HANDLE m_tFtpHandle[MAX_SERVER_NUM];  //FTP句柄
    void closePlayWin();
	void triggerSetSliderValueSignal(int iValue);   //触发设置播放进度条值的信号
	void triggerDownloadProcessBarDisplaySignal(int iEnableFlag);   //触发是否显示文件下载进度条的信号，iEnableFlag为1，显示，为0不显示
	void triggerSetDownloadProcessBarValueSignal(int iValue);   //触发设置文件下载进度条的值的信号
	void triggerCloseRecordPlaySignal();
    void triggerSetRangeLabelSignal();
	void pageShowCtrl();
	void recordPlayCtrl(int iRow, int iDex);
    void recordQueryCtrl(char *pcMsgData, int iMsgDataLen);
	
public slots:    //信号相应的槽函数
    void openStartTimeSetWidgetSlot();
	void openStopTimeSetWidgetSlot();
    void timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec);
	void recordQuerySlot();
	void recordDownloadSlot();
	void recordPlayStartSlot();
	void recordPlayStopSlot();
	void recordPlayFastForwardSlot();
	void recordPlaySlowForwardSlot();
	void recordPlayLastOneSlot();
	void recordPlayNextOneSlot();
	void playSliderMoveSlot(int iPosTime);
	void playSliderPressSlot(int iPosTime);
	void playPlusStepSlot();
	void playMinusStepSlot();
	void recordSelectionSlot(QTableWidgetItem *item);
    void recordPlaySlot(QTableWidgetItem *item);
    void carNoChangeSlot();
	void setPlaySliderValueSlot(int iValue);       //刷新进度条
	void downloadProcessBarDisplaySlot(int iEnableFlag);	//是否显示文件下载进度条，iEnableFlag为1，显示，为0不显示
	void setDownloadProcessBarValueSlot(int iValue);   //设置文件下载进度条的值
	void closeRecordPlaySlot();
	void alarmPushButoonClickSlot();
	void alarmHappenCtrlSlot();
	void alarmHappenSlot();
	void alarmClearSlot();
	void recordQueryEndSlot();
	void recordTableWidgetFillSlot();
	void recordTableWidgetFillFunc();
	void setRangeLabelSlot();

signals:
	void setSliderValueSignal(int iValue);
	void downloadProcessBarDisplaySignal(int iEnableFlag);
	void setDownloadProcessBarValueSignal(int iValue);
	void setRecordPlayFlagSignal(int iFlag);
	void closeRecordPlaySignal();
	void alarmPushButoonClickSignal();
	void recordTableWidgetFillSignal();
	void setRangeLabelSignal();
	void recordSeletPlay(QTableWidgetItem *item);
	
private:
    Ui::recordPlayWidget *ui;
    QStyle *m_tableWidgetStyle;
    QWidget *m_playWin;     //播放窗体
    QTimer *m_alarmHappenTimer;
    QTimer *m_recorQueryTimer;
    QTimer *m_recordTabelWidgetFillTimer;
    char *m_pcRecordFileBuf;
    int m_iTotalLen;
    int m_iRecordIdex;
    char m_acFilePath[MAX_RECORD_SEACH_NUM][MAX_RECFILE_PATH_LEN];   //记录查询到的录像文件路径全名
    PMSG_HANDLE m_Phandle[MAX_SERVER_NUM];    //服务器PMSG通信句柄
    void getTrainConfig();     //获取车型配置信息
    void setPlayButtonStyleSheet();
};

#endif // RECORDPLAY_H
