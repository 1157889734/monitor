#include "waitLoginWidget.h"
#include "ui_waitLoginWidget.h"
#include "state.h"
#include "debug.h"
#include <QTime>
#include <QTextCodec>
#include <stdio.h>

void *pageCountDownBrushThread(void *param)      //页面倒计时刷新线程
{	
	/*倒计时从60开始，每秒减一，直到为0退出*/
    int iCountDownValue = 60;
	
	pthread_detach(pthread_self());
	
    waitLoginWidget *waitLoginPage = (waitLoginWidget *)param;
	if (NULL == waitLoginPage)
	{
		return NULL;
	}

    while ((iCountDownValue > 0) && (1 == waitLoginPage->m_iThreadRunFlag))
    {
        QString str = QString::number(iCountDownValue);
		waitLoginPage->triggerSetCountDownValueSignal(str);  //更新倒计时显示控件的内容
        usleep(1*1000*1000);
        iCountDownValue--;
    }

	if (0 == iCountDownValue)
	{
		/*倒计时时间到了，进行页面跳转操作*/
		waitLoginPage->pageRedirect();
	}
    return NULL;
}

void waitLoginWidget::pageRedirect()
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "waitLogin Widget jump to choiceLoginDev Widget!\n");
	this->hide();   //隐藏当前页面
    emit pageRedirectSignal();    //触发页面跳转信号
}

waitLoginWidget::waitLoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waitLoginWidget)
{
	char acVersion[32] = {0};
	
    ui->setupUi(this);    //加载UI界面
    this->setWindowFlags(Qt::FramelessWindowHint);    //隐藏界面标题栏
    ui->okPushButton->setFocusPolicy(Qt::NoFocus); // 得到焦点时，不显示虚线框
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");    //设置字符编码类型
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
	
    connect(ui->okPushButton, SIGNAL(clicked()), this, SLOT(okButtonClickSlot()));   //确认按钮按键信号及相应槽函数的连接,一旦信号产生即进入okButtonClickSlot进行相应处理
    connect(this, SIGNAL(setCountDownValueSignal(QString)), this, SLOT(setCountDownValueSlot(QString)));

	m_iThreadRunFlag = 1;
	int iRet = pthread_create(&m_threadId, NULL, pageCountDownBrushThread, (void *)this);    //启动页面倒计时刷新线程，得到线程ID
	if (iRet != 0)
	{
		DebugPrint(DEBUG_UI_ERROR_PRINT, "create pageCountDownBrush thread error\n"); 
	}

	STATE_GetSysVersion(acVersion, sizeof(acVersion));
	if (strlen(acVersion) != 0)
	{
		DebugPrint(DEBUG_UI_NOMAL_PRINT, "ui app version:%s!\n",acVersion);
		ui->versionLabel->setText(QString(QLatin1String(acVersion)));
	}
}

waitLoginWidget::~waitLoginWidget()
{
    delete ui;
}

void waitLoginWidget::triggerSetCountDownValueSignal(QString timeStr)  
{
	emit setCountDownValueSignal(timeStr);
}

void waitLoginWidget::setCountDownValueSlot(QString timeStr)  
{
    ui->coutDownDisplayLabel->setText(timeStr);      //设置倒计时显示控件的内容为当前倒计时值
}

void waitLoginWidget::okButtonClickSlot()
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "waitingLogin Widget okButton pressed!\n");
	m_iThreadRunFlag = 0;
	pageRedirect();
}

