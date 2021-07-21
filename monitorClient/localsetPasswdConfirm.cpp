#include "localsetPasswdConfirm.h"
#include "ui_localsetPasswdConfirm.h"
#include "debug.h"
#include <QMessageBox>

LocalsetPasswdConfirm::LocalsetPasswdConfirm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalsetPasswdConfirm)
{
    ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);  

	p_ipmethod= new commonInputMethod();     //新建一个输入法类
	if (p_ipmethod != NULL)
	{
	    QWSServer::setCurrentInputMethod(p_ipmethod);
		p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);     //新建输入法内部的键盘输入窗体
		if (p_ipmethod->p_inputwidget != NULL)
		{
		    p_ipmethod->p_inputwidget->setGeometry(300, 450, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
		    p_ipmethod->p_inputwidget->hide();      //键盘默认隐藏
		    p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
		}
	}
	
    ui->passwordLineEdit->installEventFilter(this);
	ui->closePushButton->setFocusPolicy(Qt::NoFocus);
	ui->confirmPushButton->setFocusPolicy(Qt::NoFocus);
	ui->canclePushButton->setFocusPolicy(Qt::NoFocus);
    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(pushButtonClickSlot()));
    connect(ui->confirmPushButton, SIGNAL(clicked(bool)), this, SLOT(pushButtonClickSlot()));
    connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(pushButtonClickSlot()));
}

LocalsetPasswdConfirm::~LocalsetPasswdConfirm()
{	
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}	
    delete ui;
}

void LocalsetPasswdConfirm::pushButtonClickSlot()
{
    QObject *object = sender();
	if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    if ((object == ui->closePushButton) || (object == ui->canclePushButton))
    {
        emit sendCloseSignal();
    }
    if (object == ui->confirmPushButton)
    {		
        if (0 == QString::compare(ui->passwordLineEdit->text(), "12345"))
        {
            emit sendOkSignal();
        }
        else
        {
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "LocalsetPasswdConfirmWidget LocalsetPasswd input error!\n");
            QMessageBox box(QMessageBox::Warning,QString::fromUtf8("错误"),QString::fromUtf8("密码错误!"));     //新建消息提示框，提示错误信息
            box.setStandardButtons (QMessageBox::Ok);   //设置提示框只有一个标准按钮
            box.setButtonText (QMessageBox::Ok,QString::fromUtf8("确 定"));     //将按钮显示改成"确 定"
            box.exec();
        }
    }
}

bool LocalsetPasswdConfirm::eventFilter(QObject *target, QEvent *event)
{
    if ((target == ui->passwordLineEdit)  && (event->type() == QEvent::MouseButtonPress))
    {
        QMouseEvent *mouseEvent = (QMouseEvent *)event;
        if (mouseEvent->button() == Qt::LeftButton)
        {
        	if (NULL == p_ipmethod)
			{
				p_ipmethod= new commonInputMethod();
				if (NULL == p_ipmethod)
				{
					return QWidget::eventFilter(target, event);
				}
				QWSServer::setCurrentInputMethod(p_ipmethod);
				if (NULL == p_ipmethod->p_inputwidget)
				{
					p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
					if (NULL == p_ipmethod->p_inputwidget)
					{
						return QWidget::eventFilter(target, event);
					}
					p_ipmethod->setConnect();
    				p_ipmethod->setMapping();
				}
			}
			else
			{
				if (NULL == p_ipmethod->p_inputwidget)
				{
					p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
					if (NULL == p_ipmethod->p_inputwidget)
					{
						return QWidget::eventFilter(target, event);
					}
					p_ipmethod->setConnect();
	    			p_ipmethod->setMapping();
				}
			}
			p_ipmethod->p_inputwidget->setGeometry(300, 450, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
            p_ipmethod->p_inputwidget->show();
        }
    }
    return QWidget::eventFilter(target, event);
}
