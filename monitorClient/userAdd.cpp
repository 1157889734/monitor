#include "userAdd.h"
#include "ui_userAdd.h"
#include "state.h"
#include "debug.h"
#include <QTextCodec>
#include <QMessageBox>
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QSqlQuery"
#include <QMessageBox>
#include <qdebug.h>
#include <stdio.h>

userAdd::userAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::useradd)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setWindowModality(Qt::WindowModal);  

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);

    p_ipmethod= new commonInputMethod();
	if (p_ipmethod != NULL)
	{
		QWSServer::setCurrentInputMethod(p_ipmethod);
	    p_ipmethod->p_inputwidget = new commonKeyboardWidget(p_ipmethod);
		if (p_ipmethod->p_inputwidget != NULL)
		{
			p_ipmethod->p_inputwidget->setGeometry(231, 440, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
		    p_ipmethod->p_inputwidget->hide();
			p_ipmethod->setConnect();
		    p_ipmethod->setMapping();
		}
	}

    ui->userNameLineEdit->installEventFilter(this);
    ui->passwdLineEdit->installEventFilter(this);
    ui->userNoteLineEdit->installEventFilter(this);

    connect(ui->closePushButton, SIGNAL(clicked(bool)), this, SLOT(closeWidgetSlot()));
    connect(ui->confirmPushButton, SIGNAL(clicked(bool)), this, SLOT(confirmSlot()));
    connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(cancleSlot()));
}

userAdd::~userAdd()
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "delete ~userAddWidget\n");
	if (p_ipmethod != NULL)
	{
		delete p_ipmethod;
		p_ipmethod = NULL;
	}
    delete ui;
}

void userAdd::closeWidgetSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}

void userAdd::confirmSlot()
{
	char acUserType[16] = {0};
	int nRow = 0, i = 0;
	
	STATE_GetCurrentUserType(acUserType, sizeof(acUserType));

    if (0 == QString::compare(ui->userTypeComboBox->currentText(), tr("???????????????")))
    {
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "userAddWidget this user type has no right to add supperManager!\n");
        QMessageBox box(QMessageBox::Warning,QString::fromUtf8("??????"),QString::fromUtf8("?????????????????????????????????!"));     //??????????????????????????????????????????
        box.setStandardButtons (QMessageBox::Ok);   //???????????????????????????????????????
        box.setButtonText (QMessageBox::Ok,QString::fromUtf8("??? ???"));     //?????????????????????"??? ???"
        box.exec();
        return;
    }

	if (!strcmp(acUserType, "manager"))   //??????????????????????????????
	{
        if (0 == QString::compare(ui->userTypeComboBox->currentText(), tr("?????????")))
		{
			DebugPrint(DEBUG_UI_MESSAGE_PRINT, "userAddWidget this user type has no right to add manager!\n");
			QMessageBox box(QMessageBox::Warning,QString::fromUtf8("??????"),QString::fromUtf8("?????????????????????????????????!"));     //??????????????????????????????????????????
		    box.setStandardButtons (QMessageBox::Ok);   //???????????????????????????????????????
		    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("??? ???"));     //?????????????????????"??? ???"
		    box.exec();
			return;
		}
	}
	else if (!strcmp(acUserType, "operator"))   //?????????????????????????????????
	{
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "userAddWidget this user type has no right to add user!\n");
		QMessageBox box(QMessageBox::Warning,QString::fromUtf8("??????"),QString::fromUtf8("????????????????????????!"));     
	    box.setStandardButtons (QMessageBox::Ok);   
	    box.setButtonText (QMessageBox::Ok,QString::fromUtf8("??? ???"));     
	    box.exec();
		return;
	}

	ui->userNameWarnLabel->setText("");
	ui->passWdWarnLabel->setText("");

    if (ui->userNameLineEdit->text() == "")
    {
        if (p_ipmethod->p_inputwidget != NULL)
        {
            p_ipmethod->p_inputwidget->hide();
        }
        ui->userNameWarnLabel->setText(QObject::tr("*?????????????????????"));
        ui->userNameWarnLabel->setFocus();
        return;
    }
    if (ui->passwdLineEdit->text() == "")
    {
        if (p_ipmethod->p_inputwidget != NULL)
        {
            p_ipmethod->p_inputwidget->hide();
        }
        ui->passWdWarnLabel->setText(QObject::tr("*??????????????????"));
        ui->passWdWarnLabel->setFocus();
        return;
    }
	
	QString type = "";
	if (0 == ui->userTypeComboBox->currentIndex())
	{
		type = "supperManager";
	}
	else if (1 == ui->userTypeComboBox->currentIndex())
	{
		type = tr("manager");
	}
	else if (2 == ui->userTypeComboBox->currentIndex())
	{
		type = tr("operator");
	}
	
    QSqlDatabase database;
	if(QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else  
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
	}
    database.setDatabaseName("database.db");

    //???????????????
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
        return;
    }
    QSqlQuery sql_query;
    sql_query.prepare("select name, type, info from usermanage");
    sql_query.exec();
    sql_query.last();
	nRow = sql_query.at() + 1;
	
    sql_query.first();
    for (i = 0; i<nRow; i++)
    {
    	if (0 == QString::compare(sql_query.value(0).toString(), ui->userNameLineEdit->text()))
    	{	
    		if (p_ipmethod->p_inputwidget != NULL)
	        {
	            p_ipmethod->p_inputwidget->hide();
	        }
	        ui->userNameWarnLabel->setText(QObject::tr("*?????????????????????"));
	        ui->userNameWarnLabel->setFocus();
			database.close();
    		return;
    	}
		sql_query.next();
    }

    sql_query.last();
    QString insertStr = "insert into usermanage (type, info, name, passwd) values ('"+type+"',"+"'"+ui->userNoteLineEdit->text()+"',"+"'"+ui->userNameLineEdit->text()+"',"+"'"+ui->passwdLineEdit->text()+"')";
    if(!sql_query.exec(insertStr))
    {
        qDebug()<<sql_query.lastError();
    }

    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
	database.close();
    emit sendCloseMsg();
}

void userAdd::cancleSlot()
{
    if (p_ipmethod->p_inputwidget != NULL)
    {
        p_ipmethod->p_inputwidget->hide();
    }
    emit sendCloseMsg();
}

bool userAdd::eventFilter(QObject *target, QEvent *event)
{
	if (((target == ui->userNameLineEdit) || (target == ui->passwdLineEdit) || (target == ui->userNoteLineEdit)) && (event->type() == QEvent::MouseButtonPress))
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
			p_ipmethod->p_inputwidget->setGeometry(231, 440, p_ipmethod->p_inputwidget->width(), p_ipmethod->p_inputwidget->height());
            p_ipmethod->p_inputwidget->show();
        }

		if (target == ui->userNameLineEdit)
		{
			ui->userNameLineEdit->setText("");
        	ui->userNameLineEdit->setStyleSheet("QLineEdit{color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);}");
		}
		else if (target == ui->passwdLineEdit)
		{
			ui->passwdLineEdit->setEchoMode(QLineEdit::Password);
        	ui->passwdLineEdit->setText("");
        	ui->passwdLineEdit->setStyleSheet("QLineEdit{color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);}");
		}
		else if (target == ui->userNoteLineEdit)
		{
			ui->userNoteLineEdit->setText("");
        	ui->userNoteLineEdit->setStyleSheet("QLineEdit{color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);}");
		}
	}
	
    return QWidget::eventFilter(target, event);
}
