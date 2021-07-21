#include "setcarriagesnumber.h"
#include "ui_setcarriagesnumber.h"
#include <QTextCodec>
#include <stdio.h>

setcarriagesnumber::setcarriagesnumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setcarriagesnumber)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    p_ipmethod= new commonInputMethod();
	if (p_ipmethod != NULL)
	{
		QWSServer::setCurrentInputMethod(p_ipmethod);
	    p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->setGeometry(231, 270, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
		    p_ipmethod->p_inputwidget->hide();
			p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
		}
	}

    ui->lineEdit->installEventFilter(this);
    //connect(ui->lineEdit, SIGNAL());
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(cancleBtClick()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(CloseButtonClick()));
}

setcarriagesnumber::~setcarriagesnumber()
{
	delete p_ipmethod;
    delete ui;
}

void setcarriagesnumber::cancleBtClick()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit SendEscape();
}

void setcarriagesnumber::CloseButtonClick()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit SendEscape();
}

bool setcarriagesnumber::eventFilter(QObject *target, QEvent *event)
{
    if ((target == ui->lineEdit) && (event->type() == QEvent::MouseButtonPress))
    {
        QMouseEvent *me = (QMouseEvent *)event;
        if (me->button() == Qt::LeftButton)
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
			p_ipmethod->p_inputwidget->setGeometry(231, 270, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
            p_ipmethod->p_inputwidget->show();
        }
    }
    return QWidget::eventFilter(target, event);
}
