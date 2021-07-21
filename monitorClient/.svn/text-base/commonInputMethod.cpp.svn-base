#include "commonInputMethod.h"
#include <QMessageBox>

commonInputMethod::commonInputMethod()
{
	m_mapper = new QSignalMapper(this);  //创建QSignalMapper对象
	connect(m_mapper, SIGNAL(mapped(QString)), this, SLOT(sendContent(QString)));	//QSignalMapper对象做了转发后的相应处理
}

commonInputMethod::~commonInputMethod()
{
	delete m_mapper;
	m_mapper = NULL;
	if (p_inputwidget != NULL)
	{
		delete p_inputwidget;
		p_inputwidget = NULL;
	}
}

void commonInputMethod::sendContent(const QString &content)	 //QSignalMapper对象转发信号处理槽函数，主要完成的是产生标准的键盘输入事件，并产生相应的标准键盘值
{
	QString upContent = "";
	if (content != "del" && content != "backspace" && content != "enter" && content != "space")
	{
		if (1 == p_inputwidget->m_capsFlag)
		{
			upContent = content.toUpper();
			sendCommitString(upContent);
		}
		else
		{
			sendCommitString(content);
		}
	}
	else if (content == "del")
	{
		QWSServer::sendKeyEvent(0x01000003, Qt::Key_Delete, Qt::NoModifier, true, false);
	}
	else if (content == "backspace")
	{
		QWSServer::sendKeyEvent(0x01000003, Qt::Key_Backspace, Qt::NoModifier, true, false);
	}
	else if (content == "enter")
	{
		if(NULL==p_inputwidget)
		{
	       return;
		}
	    else
	    {
	        delete p_inputwidget;	    	
	    	p_inputwidget=NULL;
	    }
		emit enter();
	}
	else if (content == "space")
	{
		QWSServer::sendKeyEvent(0x20, Qt::Key_Space, Qt::NoModifier, true, false);
	}
}

void commonInputMethod::setMapping() 	 //设置QSignalMapper的转发规则
{
	const static QString key_text[46] = {"1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m",
										 "*","-","@","#","del","backspace","enter","","","space"};
	int i;
	for (i = 0; i < 43; i++)
	{
		//printf("setMapping pushbutton %d to %s\n",i+1,key_text[i].toAscii().data());
		m_mapper->setMapping((QObject *)p_inputwidget->pushbutton[i], key_text[i]);//设置signalmapper的转发规则, 转发处理的对象为软键盘的每个按钮，转发参数为QString类型的信号， 并把key_text[i]的内容作为实参传递。
	}
	m_mapper->setMapping((QObject *)p_inputwidget->pushbutton[45], key_text[45]);
}

void commonInputMethod::setConnect()   //设置QSignalMapper的转发信号如何触发
{
	/*p_inputwidget->pushbutton[43]-shift, p_inputwidget->pushbutton[44]-无效键，这里无需处理*/
	int i;
	for (i = 0; i < 43; i++)
	{
		connect((QObject *)p_inputwidget->pushbutton[i], SIGNAL(clicked_left()), m_mapper, SLOT(map()));	  //键盘的按钮触发了按键信号，就触发QSignalMapper的转发信号
	}
	connect((QObject *)p_inputwidget->pushbutton[45], SIGNAL(clicked_left()), m_mapper, SLOT(map()));
}

void commonInputMethod::closeWidget()
{
    if(NULL==p_inputwidget)
	{
       return;
	}
    else
    {
        delete p_inputwidget;	    	
    	p_inputwidget=NULL;
    }

	emit exit();
}

void commonInputMethod::enterConfirm()
{
    if(NULL==p_inputwidget)
       return;
    else
        delete p_inputwidget;
    p_inputwidget=NULL;
}


