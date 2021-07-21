#include "devupdateofcarriages.h"
#include "ui_devupdateofcarriages.h"
#include <stdio.h>

devupdateofcarriages::devupdateofcarriages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devupdateofcarriages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    setCaNoPage = new setcarriagesnumber();
    setCaNoPage->hide();

    usermanagePage = new userManage();
    usermanagePage->hide();

    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
    connect(this->setCaNoPage, SIGNAL(SendEscape()), this, SLOT(RecvSetCarNuMsg()));
    connect(this->usermanagePage, SIGNAL(SendEscape()), this, SLOT(RecvUserManageMsg()));
}

devupdateofcarriages::~devupdateofcarriages()
{
	delete setCaNoPage;
	delete usermanagePage;
    delete ui;
}

void devupdateofcarriages::buttonClick()
{
    QObject *Object = sender();
    if (Object == ui->pushButton_2)
    {
        if (setCaNoPage == NULL)
        {
            setCaNoPage = new setcarriagesnumber();
            setCaNoPage->hide();
            connect(setCaNoPage, SIGNAL(SendEscape()), this, SLOT(RecvSetCarNuMsg()));
        }
        setCaNoPage->move(310, 220);
        setCaNoPage->show();
    }

    if (Object == ui->pushButton_3)
    {
        if (usermanagePage == NULL)
        {
            usermanagePage = new userManage();
            usermanagePage->hide();
            connect(usermanagePage, SIGNAL(SendEscape()), this, SLOT(RecvUserManageMsg()));
        }
        usermanagePage->move(245, 189);
        usermanagePage->show();
    }
}

void devupdateofcarriages::RecvSetCarNuMsg()
{
    if(NULL==this->setCaNoPage)
    {
        return;
    }
}

void devupdateofcarriages::RecvUserManageMsg()
{
    if(NULL==this->usermanagePage)
    {
        return;
    }
}
