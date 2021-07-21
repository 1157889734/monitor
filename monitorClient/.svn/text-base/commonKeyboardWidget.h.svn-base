#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QPushButton>

class commonInputMethod;

namespace Ui {
    class InputWidget;
}

class commonKeyboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit commonKeyboardWidget(commonInputMethod *ipm, QWidget *parent = 0);
    ~commonKeyboardWidget();
	QPushButton *pushbutton[46];	//保存类的按钮控件数组为该类的公有成员，以便其他类能够使用
	int m_capsFlag; 	 //大写标记
	
public slots:  //定义槽
	void setShiftFlag();
	void buttonClick();

signals:	 //定义信号
	void sendCloseMsg();
	void sendEnterMsg();

private:
    Ui::InputWidget *ui;
    QButtonGroup *button_group;
    QPoint  mouse_pos;
    QPoint  widget_pos;
    bool should_move;
    bool CapLockFlag,ShiftFlag;

};

#endif // INPUTWIDGET_H
