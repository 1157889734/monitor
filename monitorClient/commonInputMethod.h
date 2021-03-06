#ifndef IPMETHOD_H
#define IPMETHOD_H
#include <QSignalMapper>
//#include <QWSInputMethod>
#include <QMouseEvent>
#include "commonKeyboardWidget.h"

class commonInputMethod : public QWSInputMethod
{
    Q_OBJECT

public:
	commonInputMethod();
	~commonInputMethod();
	commonKeyboardWidget *p_inputwidget;
	void setMapping();
	void setConnect();


private:
	QSignalMapper *m_mapper;	 //可以理解为信号转发器，表示的是具有同一种信号的一类控件，作用是可批量处理这一类的信号

signals:
	void exit();
	void enter();

public slots:
	void sendContent(const QString&);
	void closeWidget();
	void enterConfirm();
};

#endif // IPMETHOD_H
