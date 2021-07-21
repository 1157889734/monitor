#ifndef LOGINPAGEKEYBOARDWIDGET_H
#define LOGINPAGEKEYBOARDWIDGET_H

#include <QDialog>

namespace Ui {
class KeyboardDialog;
}

class loginPageKeyboardWidget : public QDialog
{
    Q_OBJECT

public:
    explicit loginPageKeyboardWidget(QWidget *parent = 0);
    ~loginPageKeyboardWidget();
    QPushButton *pushbutton[46];    //保存类的按钮控件数组为该类的公有成员，以便其他类能够使用
    int m_capsFlag;      //大写标记

public slots:  //定义槽
    void setShiftFlag();
    void buttonClick();

signals:     //定义信号
    void sendDelAllMsg();
    void sendEnterMsg();

private:
    Ui::KeyboardDialog *ui;
};

#endif // KEYBOARDDIALOG_H
