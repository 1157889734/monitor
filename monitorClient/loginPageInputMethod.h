#ifndef KEYBOARD_H
#define KEYBOARD_H
//#include <QWSInputMethod>
#include <QSignalMapper>
#include "loginPageKeyboardWidget.h"

class loginPageInputMethod:public QWSInputMethod
{
Q_OBJECT

public:
        loginPageInputMethod();
        ~loginPageInputMethod();
        loginPageKeyboardWidget *keyboardWidget;
        void setMapping();
        void setConnect();


private:
        QSignalMapper *m_mapper;     //可以理解为信号转发器，表示的是具有同一种信号的一类控件，作用是可批量处理这一类的信号

public slots:
        void sendContent(const QString&);
};

#endif // KEYBOARD_H

