#include "recplaybackofcarriages.h"
#include "ui_recplaybackofcarriages.h"
#include <QDateTime>
#include <stdio.h>

int iDateEdit1 = 0;

QTableWidgetItem *g_checkBox = NULL;


recplaybackofcarriages::recplaybackofcarriages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recplaybackofcarriages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

	ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget->horizontalHeader()->resizeSection(0,46); //设置表头第一列的宽度为46
    ui->tableWidget->horizontalHeader()->resizeSection(1,46);
    ui->tableWidget->horizontalHeader()->resizeSection(2,219);

    g_checkBox = new QTableWidgetItem();
    g_checkBox->setCheckState(Qt::Unchecked);
    //checkBox_1->setText("勾选启用");
    //ui->tableWidget->setItem(0, 0, g_checkBox);
    //ui->tableWidget->setItem(1, 0, g_checkBox);

    timesetwid = new timeSet(this);
    timesetwid->hide();

    char timestr[128] = {0};
    QDateTime time = QDateTime::currentDateTime();
    snprintf(timestr, sizeof(timestr), "%d-%02d-%02d %02d:%02d:%02d", time.date().year(), time.date().month(), time.date().day(), time.time().hour(), time.time().minute(), time.time().second());
    QString string = QString(QLatin1String(timestr)) ;
    ui->label->setText(string);
    ui->label_14->setText(string);
    connect(ui->pushButton, SIGNAL(clicked_left()), this, SLOT(timeSetClick()));
    connect(ui->pushButton_2, SIGNAL(clicked_left()), this, SLOT(timeSetClick()));
    connect(timesetwid, SIGNAL(timeSetSendMsg(QString,QString,QString,QString,QString,QString)), this, SLOT(timeSetRecvMsg(QString,QString,QString,QString,QString,QString)));
}

recplaybackofcarriages::~recplaybackofcarriages()
{
	delete timesetwid;
	delete g_checkBox;
    delete ui;
}

void recplaybackofcarriages::timeSetClick()
{
    QObject* Object=sender();

    if (Object == ui->pushButton)
    {
        timesetwid->setGeometry(280, 50, timesetwid->width(), timesetwid->height());
        iDateEdit1 = 1;
    }
    else if (Object == ui->pushButton_2)
    {
        timesetwid->setGeometry(280, 90, timesetwid->width(), timesetwid->height());
        iDateEdit1 = 2;
    }
    timesetwid->show();
}

void recplaybackofcarriages::timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec)
{
    char timestr[128] = {0};
    snprintf(timestr, sizeof(timestr), "%s-%s-%s %s:%s:%s", year.toStdString().data(), month.toStdString().data(), day.toStdString().data(),
            hour.toStdString().data(), min.toStdString().data(), sec.toStdString().data());
    QString string = QString(QLatin1String(timestr)) ;
    if (1 == iDateEdit1)
    {
        ui->label->setText(string);
    }
    else if (2 == iDateEdit1)
    {
        ui->label_14->setText(string);
    }
}
