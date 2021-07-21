#include "devmanageofcarriages.h"
#include "ui_devmanageofcarriages.h"

devmanageofcarriages::devmanageofcarriages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devmanageofcarriages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

	ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget->horizontalHeader()->resizeSection(0,46); //设置表头第一列的宽度为46
    ui->tableWidget->horizontalHeader()->resizeSection(1,136);
    ui->tableWidget->horizontalHeader()->resizeSection(2,136);
    ui->tableWidget->horizontalHeader()->resizeSection(3,116);
    ui->tableWidget->horizontalHeader()->resizeSection(4,116);
    ui->tableWidget->horizontalHeader()->resizeSection(5,111);
	
	ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget_2->horizontalHeader()->resizeSection(0,46); //设置表头第一列的宽度为46
    ui->tableWidget_2->horizontalHeader()->resizeSection(1,136);
    ui->tableWidget_2->horizontalHeader()->resizeSection(2,136);
    ui->tableWidget_2->horizontalHeader()->resizeSection(3,116);
    ui->tableWidget_2->horizontalHeader()->resizeSection(4,116);
    ui->tableWidget_2->horizontalHeader()->resizeSection(5,116);
    //ui->tableWidget_2->horizontalHeader()->resizeSection(6,61);
}

devmanageofcarriages::~devmanageofcarriages()
{
    delete ui;
}
