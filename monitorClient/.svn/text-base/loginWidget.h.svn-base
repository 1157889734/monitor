#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "loginPageInputMethod.h"
#include <QInputDialog>

typedef enum _E_DEVTYPE
{
	E_CVMSTYPE = 1,     //车厢监控设备
	E_PVMSTYPE = 2      //受电弓监控设备
} E_DEVTYPE;


namespace Ui {
class loginWidget;
}

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginWidget(QWidget *parent = 0);
    ~loginWidget();
    loginPageInputMethod *m_inputMethod;

signals:
    void gotoPvmsMenuPageSignal();     //受电弓监控主页面跳转信号
    void gotoCvmsMenuPageSignal();     //车厢监控主页面跳转信号
  
public slots:
    void showPageSlot(int iType);  //显示当前页面的响应槽函数，这里iType代表接收到的参数，表示页面类型，1-车厢监控页面，2-受电弓监控页面
    void okButtonSlot();
    void cancleButtonSlot();
    void delTextMsgSlot();

private:
    Ui::loginWidget *ui;
    int m_iLoginType;
};

#endif // LOGINWIDGET_H
