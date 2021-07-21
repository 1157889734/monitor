#include "loginPageKeyboardWidget.h"
#include "ui_loginPageKeyboardWidget.h"
#include <QMouseEvent>
#include <stdio.h>

int g_iShiftClickNum = 0;   //记录键盘shift键的按键次数，以便奇数次和偶数次按键做出不同的相应

loginPageKeyboardWidget::loginPageKeyboardWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyboardDialog)
{
    int i = 0;
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

	/*ui->pushButton属于类的私有成员，这里将所有的按钮保存为该类的公有成员，以便其他类(输入法)能使用*/
    pushbutton[0] = ui->pushButton_1;
    pushbutton[1] = ui->pushButton_2;
    pushbutton[2] = ui->pushButton_3;
    pushbutton[3] = ui->pushButton_4;
    pushbutton[4] = ui->pushButton_5;
    pushbutton[5] = ui->pushButton_6;
    pushbutton[6] = ui->pushButton_7;
    pushbutton[7] = ui->pushButton_8;
    pushbutton[8] = ui->pushButton_9;
    pushbutton[9] = ui->pushButton_10;
    pushbutton[10] = ui->pushButton_11;
    pushbutton[11] = ui->pushButton_12;
    pushbutton[12] = ui->pushButton_13;
    pushbutton[13] = ui->pushButton_14;
    pushbutton[14] = ui->pushButton_15;
    pushbutton[15] = ui->pushButton_16;
    pushbutton[16] = ui->pushButton_17;
    pushbutton[17] = ui->pushButton_18;
    pushbutton[18] = ui->pushButton_19;
    pushbutton[19] = ui->pushButton_20;
    pushbutton[20] = ui->pushButton_21;
    pushbutton[21] = ui->pushButton_22;
    pushbutton[22] = ui->pushButton_23;
    pushbutton[23] = ui->pushButton_24;
    pushbutton[24] = ui->pushButton_25;
    pushbutton[25] = ui->pushButton_26;
    pushbutton[26] = ui->pushButton_27;
    pushbutton[27] = ui->pushButton_28;
    pushbutton[28] = ui->pushButton_29;
    pushbutton[29] = ui->pushButton_30;
    pushbutton[30] = ui->pushButton_31;
    pushbutton[31] = ui->pushButton_32;
    pushbutton[32] = ui->pushButton_33;
    pushbutton[33] = ui->pushButton_34;
    pushbutton[34] = ui->pushButton_35;
    pushbutton[35] = ui->pushButton_36;
    pushbutton[36] = ui->pushButton_37;
    pushbutton[37] = ui->pushButton_38;
    pushbutton[38] = ui->pushButton_39;
    pushbutton[39] = ui->pushButton_40;
    pushbutton[40] = ui->pushButton_41;
    pushbutton[41] = ui->pushButton_42;
    pushbutton[42] = ui->pushButton_43;
    pushbutton[43] = ui->pushButton_44;
    pushbutton[44] = ui->pushButton_45;
    pushbutton[45] = ui->pushButton_46;

    for (i = 0; i < 46; i++)
    {
        pushbutton[i]->setFocusPolicy(Qt::NoFocus);       //设置键盘按钮任何时候不获取焦点，以免当点击键盘按钮时，焦点从输入框转移到键盘上而导致输入框不能显示输入内容
    }

    for (i = 40; i < 46; i++)
    {
        connect(pushbutton[i], SIGNAL(clicked_left()), this, SLOT(buttonClick()));     //按钮的按键信号连接按键相应槽函数
    }
	
    m_capsFlag = 0;   //大写标记
    connect(ui->pushButton_44, SIGNAL(clicked_left()), this, SLOT(setShiftFlag()));   //shift按钮的按键相应
}

loginPageKeyboardWidget::~loginPageKeyboardWidget()
{
    delete ui;
}

void loginPageKeyboardWidget::buttonClick()
{
    QObject* object = sender();

    if (object == ui->pushButton_41)   //区分触发该槽函数的不同信号来源
    {
         emit sendDelAllMsg();
    }
    if (object == ui->pushButton_43)
    {
         emit sendEnterMsg();
    }

}

void loginPageKeyboardWidget::setShiftFlag()
{
        g_iShiftClickNum++;
        if (0 == g_iShiftClickNum%2)
        {
            m_capsFlag = 0;
        }
        else
        {
            m_capsFlag = 1;
        }
}

