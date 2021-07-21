#include "loginWidget.h"
#include "ui_loginWidget.h"
#include "state.h"
#include "debug.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QSqlQuery"
#include <QMessageBox>
#include <QTextCodec>
#include <qdebug.h>

loginWidget::loginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);     //隐藏窗口标题栏

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");    //设置字符编码类型
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);   
	
    ui->userNameLineEdit->setTextMargins(ui->userLabel->x()+ui->userLabel->width()-ui->userNameLineEdit->x(),0, 0, 0);   //设置输入框里嵌套图标在输入框的位置
    ui->userNameLineEdit->setPlaceholderText(tr("请输入用户名"));   //设置输入框里的占位显示字样，当焦点进入输入框时这些字自动隐藏，焦点离开时自动根据有没有添加文字来决定要不要显示占位字样
    ui->passwdLineEdit->setTextMargins(ui->passwdLabel->x()+ui->passwdLabel->width()-ui->passwdLineEdit->x(), 0, 0, 0);
    ui->passwdLineEdit->setPlaceholderText(tr("请输入密码"));\
    ui->userNameLineEdit->setFocus();
	ui->okPushButton->setFocusPolicy(Qt::NoFocus);
	ui->canclePushButton->setFocusPolicy(Qt::NoFocus);
	/*加载软键盘*/
    m_inputMethod = new loginPageInputMethod();
    loginPageKeyboardWidget *keyboardWidget = new loginPageKeyboardWidget(ui->frame);
    m_inputMethod->keyboardWidget = keyboardWidget;
    m_inputMethod->setConnect();
    m_inputMethod->setMapping();
    m_inputMethod->keyboardWidget->move(140, 320);
    m_inputMethod->keyboardWidget->show();
    QWSServer::setCurrentInputMethod(m_inputMethod);     //设置当前的输入方式为自定义的软键盘

    connect(ui->okPushButton, SIGNAL(clicked(bool)), this, SLOT(okButtonSlot()));	   //确定按钮的按键信号连接相应槽函数
    //connect(ui->canclePushButton, SIGNAL(clicked(bool)), this, SLOT(cancleButtonSlot()));     //取消按钮的按键信号连接相应槽函数
    connect(m_inputMethod->keyboardWidget, SIGNAL(sendDelAllMsg()), this, SLOT(delTextMsgSlot()));      //软键盘删除信号连接相应槽函数
    connect(m_inputMethod->keyboardWidget, SIGNAL(sendEnterMsg()), this, SLOT(okButtonSlot()));     //软键盘回车信号连接相应槽函数
}

loginWidget::~loginWidget()
{
	delete m_inputMethod;
	m_inputMethod = NULL;
    delete ui;
}

void loginWidget::showPageSlot(int iType)
{
	DebugPrint(DEBUG_UI_NOMAL_PRINT, "login Widget page show\n");
    this->show();
    m_iLoginType = iType;     //保留前面的设备选择页面传下来的设备类型值，以便能跳转到相应的后续页面
}

void loginWidget::delTextMsgSlot()      //点击软键盘上的删除按钮，在这里进行相应处理:即一键删除用户名或密码输入框中的所有已输入字符
{
    if (ui->userNameLineEdit->hasFocus())      //判断是否正在输入用户名
    {
        ui->userNameLineEdit->setText("");
    }
    else if (ui->passwdLineEdit->hasFocus())     //判断是否正在输入密码
    {
        ui->passwdLineEdit->setText("");
    }
}


void loginWidget::okButtonSlot()
{
	int iCheckFlag = 0;
    QString urname,pwd,type;
    QSqlDatabase database;

	DebugPrint(DEBUG_UI_OPTION_PRINT, "login Widget okButton pressed!\n");
	
	/*是否已经存在一个默认的数据库连接，如果存在则通过database方法获取，不存在则通过addDatabase创建一个新的数据库连接*/
	if(QSqlDatabase::contains("qt_sql_default_connection"))   
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else  
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
	}
    database.setDatabaseName("database.db");   //设置连接的数据库名称
	
	#if 0
	//打开数据库   
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }
    else
    {    
    	//QSqlQuery类提供执行和操作的SQL语句的方法。        
    	//可以用来执行DML（数据操作语言）语句，如SELECT、INSERT、UPDATE、DELETE
        QSqlQuery sql_query;      

        QString select_sql = "create table usermanage(id INTEGER PRIMARY KEY autoincrement,	name nvarchar(128), passwd nvarchar(128), type nvarchar(128), info nvarchar(128))";    //查询数据库中所有的用户名、密码和用户类型记录
        if(!sql_query.exec(select_sql))    //执行SQL语句
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
        }
    }
	#else
	//打开数据库   
    if(!database.open())
    {
		DebugPrint(DEBUG_UI_ERROR_PRINT, "loginWidget database open error!\n");
    }

	//QSqlQuery类提供执行和操作的SQL语句的方法。        
    //可以用来执行DML（数据操作语言）语句，如SELECT、INSERT、UPDATE、DELETE
	QSqlQuery sql_query;    
	QString select_sql = "";
	
	if (ui->userNameLineEdit->text() == "admin")    //admin登录用户,通过检查数据库中是否存在该用户，如果存在则和数据中的密码匹配，如果不存在则默认密码12345              
    {
    	select_sql = "select passwd from usermanage where name='admin'";   //检测数据库中是否存在admin用户
		if(!sql_query.exec(select_sql))    //执行SQL语句
	    {
			DebugPrint(DEBUG_UI_ERROR_PRINT, "loginWidget database select error!\n");
	    }
		else
	    {
	        if(sql_query.first())
	        {
	        	iCheckFlag = 1;
	            pwd = sql_query.value(0).toString();
	        }
	    }
		
    	if (0 == iCheckFlag)
    	{
			if (ui->passwdLineEdit->text() == "12345")
			{
				this->hide();
				STATE_SetCurrentUserType("supperManager");
				if (E_CVMSTYPE == m_iLoginType)
				{
					emit gotoCvmsMenuPageSignal();
				}
				else if (E_PVMSTYPE == m_iLoginType)
				{
					emit gotoPvmsMenuPageSignal();
				}
			}  
			else
			{
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "loginWidget username or passwd input not match!\n");
				QMessageBox box(QMessageBox::Warning,tr("信息有误"),tr("用户名或密码错误!"));     //新建消息提示框，提示错误信息
			    box.setStandardButtons (QMessageBox::Ok);   //设置提示框只有一个标准按钮
			    box.setButtonText (QMessageBox::Ok,tr("确 定"));     //将按钮显示改成"确 定"
			    box.exec();
			}
    	}
		else
		{
			if (ui->passwdLineEdit->text() != pwd)
			{				
				DebugPrint(DEBUG_UI_MESSAGE_PRINT, "loginWidget username or passwd input not match!\n");
				QMessageBox box(QMessageBox::Warning,tr("信息有误"),tr("用户名或密码错误!"));     //新建消息提示框，提示错误信息
			    box.setStandardButtons (QMessageBox::Ok);   //设置提示框只有一个标准按钮
			    box.setButtonText (QMessageBox::Ok,tr("确 定"));     //将按钮显示改成"确 定"
			    box.exec();
			}
			else
			{
				this->hide();
				STATE_SetCurrentUserType("supperManager");
				if (E_CVMSTYPE == m_iLoginType)
				{
					emit gotoCvmsMenuPageSignal();
				}
				else if (E_PVMSTYPE == m_iLoginType)
				{
					emit gotoPvmsMenuPageSignal();
				}
			}
		}
    }
	else
	{
        QString select_sql = "select name, passwd, type from usermanage";    //查询数据库中所有的用户名、密码和用户类型记录
        if(!sql_query.exec(select_sql))    //执行SQL语句
        {
			DebugPrint(DEBUG_UI_ERROR_PRINT, "loginWidget database select error!\n");
        }
        else
        {
            while(sql_query.next())   //循环进行用户名、密码的匹配，直到匹配成功退出，否则弹出错误提示框
            {
                urname = sql_query.value(0).toString();
                pwd = sql_query.value(1).toString();
				type = sql_query.value(2).toString();
                if ((ui->userNameLineEdit->text() == urname) && (ui->passwdLineEdit->text() == pwd))    //用户名、密码匹配成功                
                {
                    this->hide();
					STATE_SetCurrentUserType(type.toLatin1().data());   //保存当前登录用户的用户类型
					
					if (E_CVMSTYPE == m_iLoginType)
					{
						emit gotoCvmsMenuPageSignal();
					}
					else if (E_PVMSTYPE == m_iLoginType)
					{
						emit gotoPvmsMenuPageSignal();
					}
					database.close();
                    return;
                }
            }
        }
				
		DebugPrint(DEBUG_UI_MESSAGE_PRINT, "loginWidget username or passwd input not match!\n");
		QMessageBox box(QMessageBox::Warning,tr("信息有误"),tr("用户名或密码错误!"));     //新建消息提示框，提示错误信息
	    box.setStandardButtons (QMessageBox::Ok);   //设置提示框只有一个标准按钮
	    box.setButtonText (QMessageBox::Ok,QString("确 定"));     //将按钮显示改成"确 定"
	    box.exec();
	}
	database.close();
	#endif
}

void loginWidget::cancleButtonSlot()
{
	DebugPrint(DEBUG_UI_OPTION_PRINT, "login Widget cancleButton pressed!\n");
    QApplication *app;
    app->exit();     //退出QT主程序
}
