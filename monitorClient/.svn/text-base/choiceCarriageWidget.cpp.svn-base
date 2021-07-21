#include "choiceCarriageWidget.h"
#include "ui_choiceCarriageWidget.h"

choiceCarriageWidget::choiceCarriageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choicecarriages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
}

choiceCarriageWidget::~choiceCarriageWidget()
{
    delete ui;
}

void choiceCarriageWidget::showPageSlot()
{
    this->show();
}

void choiceCarriageWidget::buttonClick()
{
    emit confirmCarriageSignal();
}
