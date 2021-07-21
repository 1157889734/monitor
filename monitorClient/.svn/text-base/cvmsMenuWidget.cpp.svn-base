#include "cvmsMenuWidget.h"
#include "ui_cvmsMenuWidget.h"

#define CVMSPAGETYPE  1   

cvmsMenuWidget::cvmsMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuofcarriages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    cvmsMonitorPage = new cvmsMonitorWidget(this);
    cvmsMonitorPage->hide();
    recpbPage = new recplaybackofcarriages(this);
    recpbPage->hide();
    devmanagePage = new devmanageofcarriages(this);
    devmanagePage->hide();
    devupdatePage = new devupdateofcarriages(this);
    devupdatePage->hide();

    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(regisoutBtClick()));
    connect(ui->pushButton_2, SIGNAL(clicked_left()), this, SLOT(menuBtClick()));
    connect(ui->pushButton_3, SIGNAL(clicked_left()), this, SLOT(menuBtClick()));
    connect(ui->pushButton_4, SIGNAL(clicked_left()), this, SLOT(menuBtClick()));
    connect(ui->pushButton_5, SIGNAL(clicked_left()), this, SLOT(menuBtClick()));
}

cvmsMenuWidget::~cvmsMenuWidget()
{
	delete cvmsMonitorPage;
	delete recpbPage;
	delete devmanagePage;
	delete devupdatePage;
    delete ui;
}

void cvmsMenuWidget::showPageSlot()
{
    this->show();
    recpbPage->hide();
    devmanagePage->hide();
    devupdatePage->hide();
    cvmsMonitorPage->move(0, 103);
    cvmsMonitorPage->show();
}

void cvmsMenuWidget::regisoutBtClick()
{
    this->hide();
    emit registOutSignal(CVMSPAGETYPE);
}

void cvmsMenuWidget::menuBtClick()
{
    QObject* Object=sender();
    if(Object==0)
    {
        return ;
    }
    //printf("send objectname:%s\n",Object->objectName().toStdString().data());

    if (Object->objectName() == "pushButton_2")
    {
        recpbPage->hide();
        devmanagePage->hide();
        devupdatePage->hide();
        cvmsMonitorPage->move(0, 103);
        cvmsMonitorPage->show();
    }
    else if (Object->objectName() == "pushButton_3")
    {
        cvmsMonitorPage->hide();
        devmanagePage->hide();
        devupdatePage->hide();
        recpbPage->move(0, 103);
        recpbPage->show();
    }
    else if (Object->objectName() == "pushButton_4")
    {
        cvmsMonitorPage->hide();
        recpbPage->hide();
        devupdatePage->hide();
        devmanagePage->move(0, 103);
        devmanagePage->show();
    }
    else if (Object->objectName() == "pushButton_5")
    {
        cvmsMonitorPage->hide();
        recpbPage->hide();
        devmanagePage->hide();
        devupdatePage->move(0, 103);
        devupdatePage->show();
    }
}
