#include "inteAnalyWidget.h"
#include "ui_inteAnalyWidget.h"
#include <stdio.h>
#include <QDateTime>

inteAnalyWidget::inteAnalyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inteAnalyWidget)
{	
	char timestr[128] = {0};
	int iYear = 0, iMonth= 0, iDay = 0;
	QString string = "";
    ui->setupUi(this);

   	QDateTime time = QDateTime::currentDateTime();
    snprintf(timestr, sizeof(timestr), "%4d-%02d-%02d %02d:%02d:%02d", time.date().year(), time.date().month(), time.date().day(), time.time().hour(), time.time().minute(), time.time().second());
    string = QString(QLatin1String(timestr)) ;
    ui->endTimeLabel->setText(string);		 //结束时间控件初始显示当前系统时间
    
    memset(&timestr, 0, sizeof(timestr));	
	iYear = time.date().year();
	iMonth = time.date().month();
	iDay = time.date().day()-1;
	if (0 == iDay)
	{
		iMonth = time.date().month()-1;
		if (0 == iMonth)
		{
			iMonth = 12;
			iYear = time.date().year() - 1;
		}
		if (1 == iMonth || 3 == iMonth || 5 == iMonth || 7 == iMonth || 8 == iMonth || 10 == iMonth || 12 == iMonth)
		{
			iDay = 31;
		}
		else if (4 == iMonth || 6 == iMonth || 9 == iMonth || 11 == iMonth)
		{
			iDay = 30;
		}
		else
		{
			if((0 == iYear%4 && 0 == iYear%100)||(0 == iYear%400))
			{
				iDay = 29;
			}
			else
			{
				iDay = 28;
			}
		}
	}

	snprintf(timestr, sizeof(timestr), "%4d-%02d-%02d %02d:%02d:%02d", iYear, iMonth, iDay, time.time().hour(), time.time().minute(), time.time().second());
    string = QString(QLatin1String(timestr)) ;
	ui->startTimeLabel->setText(string);     //起始时间控件初始显示当前系统时间前一天
}

inteAnalyWidget::~inteAnalyWidget()
{
    delete ui;
}

void inteAnalyWidget::pageShowCtrl()
{
	char timestr[128] = {0};
	int iYear = 0, iMonth= 0, iDay = 0;
	QString string = "";
	QDateTime time = QDateTime::currentDateTime();
    snprintf(timestr, sizeof(timestr), "%4d-%02d-%02d %02d:%02d:%02d", time.date().year(), time.date().month(), time.date().day(), time.time().hour(), time.time().minute(), time.time().second());
    string = QString(QLatin1String(timestr)) ;
    ui->endTimeLabel->setText(string);		 //结束时间控件初始显示当前系统时间
    
    memset(&timestr, 0, sizeof(timestr));	
	iYear = time.date().year();
	iMonth = time.date().month();
	iDay = time.date().day()-1;
	if (0 == iDay)
	{
		iMonth = time.date().month()-1;
		if (0 == iMonth)
		{
			iMonth = 12;
			iYear = time.date().year() - 1;
		}
		if (1 == iMonth || 3 == iMonth || 5 == iMonth || 7 == iMonth || 8 == iMonth || 10 == iMonth || 12 == iMonth)
		{
			iDay = 31;
		}
		else if (4 == iMonth || 6 == iMonth || 9 == iMonth || 11 == iMonth)
		{
			iDay = 30;
		}
		else
		{
			if((0 == iYear%4 && 0 == iYear%100)||(0 == iYear%400))
			{
				iDay = 29;
			}
			else
			{
				iDay = 28;
			}
		}
	}
	snprintf(timestr, sizeof(timestr), "%4d-%02d-%02d %02d:%02d:%02d", iYear, iMonth, iDay, time.time().hour(), time.time().minute(), time.time().second());
    string = QString(QLatin1String(timestr)) ;
	ui->startTimeLabel->setText(string);     //起始时间控件初始显示当前系统时间前一天
}

