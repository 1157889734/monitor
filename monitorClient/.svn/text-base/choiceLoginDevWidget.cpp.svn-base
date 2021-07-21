#include "choiceLoginDevWidget.h"
#include "loginWidget.h"
#include "ui_choiceLoginDevWidget.h"
#include "debug.h"
#include <stdio.h>
#include <QTextCodec>

choiceLoginDevWidget::choiceLoginDevWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choiceLoginDevWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->cvmsPushButton->setFocusPolicy(Qt::NoFocus); // 得到焦点时，不显示虚线框
    ui->pvmsPushButton->setFocusPolicy(Qt::NoFocus);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");    
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
	
    connect(ui->cvmsPushButton, SIGNAL(clicked()), this, SLOT(choiceCvmsSlot()));
    connect(ui->pvmsPushButton, SIGNAL(clicked()), this, SLOT(choicePvmsSlot()));
}

choiceLoginDevWidget::~choiceLoginDevWidget()
{
    delete ui;
}

void choiceLoginDevWidget::showPageSlot()
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "choiceLoginDe Widget show!\n");
    this->show(); 
}

void choiceLoginDevWidget::choiceCvmsSlot()
{
	
	DebugPrint(DEBUG_UI_OPTION_PRINT, "choiceLoginDe Widget cvmsButton pressed!\n");
    this->hide();
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "choiceLoginDe Widget jump to login Widget!\n");
    emit confirmDevTypeSignal(E_CVMSTYPE);
}

void choiceLoginDevWidget::choicePvmsSlot()
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "choiceLoginDe Widget pvmsButton pressed!\n");
    this->hide();
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "choiceLoginDe Widget jump to login Widget!\n");
    emit confirmDevTypeSignal(E_PVMSTYPE);
}

