#include "iplineedit.h"
#include <QValidator>
#include <QIntValidator>

static int flag_show = 1;
static QString send_name = "";

iplineedit::iplineedit(QWidget *parent) :
    QLineEdit(parent)
{
    m_ipPart1 = new MyIpPartLineEdit(this);
    m_ipPart2 = new MyIpPartLineEdit(this);
    m_ipPart3 = new MyIpPartLineEdit(this);
    m_ipPart4 = new MyIpPartLineEdit(this);
	
    m_labeldDot1 = new QLabel(this);
    m_labeldDot2 = new QLabel(this);
    m_labeldDot3 = new QLabel(this);

    m_ipPart1->setGeometry(QRect(0, 0, 33, 29));
    m_ipPart2->setGeometry(QRect(33, 0, 33, 29));
    m_ipPart3->setGeometry(QRect(66, 0, 33, 29));
    m_ipPart4->setGeometry(QRect(99, 0, 30, 29));

    m_labeldDot1->setText(".");
    m_labeldDot1->setGeometry(QRect(30, 1, 3, 27));
    m_labeldDot1->setAlignment(Qt::AlignCenter);
    m_labeldDot1->setStyleSheet("QLabel{color:rgb(0, 0, 0);font-size:13px;background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-left:none;border-right:none;}");

    m_labeldDot2->setText(".");
    m_labeldDot2->setGeometry(QRect(63, 1, 3, 27));
    m_labeldDot2->setAlignment(Qt::AlignCenter);
    m_labeldDot2->setStyleSheet("QLabel{color:rgb(0, 0, 0);font-size:13px;background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-left:none;border-right:none;}");

    m_labeldDot3->setText(".");
    m_labeldDot3->setGeometry(QRect(96, 1, 3, 27));
    m_labeldDot3->setAlignment(Qt::AlignCenter);
    m_labeldDot3->setStyleSheet("QLabel{color:rgb(0, 0, 0);font-size:13px; background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-left:none;border-right:none;}");

    /*
    m_ipPart1->setMaxLength(3);
    m_ipPart1->setFrame(false);
    m_ipPart1->setAlignment(Qt::AlignLeft);
    QValidator *validator1 = new QIntValidator(0, 255, m_ipPart1);
    m_ipPart1->setValidator(validator1);*/
    m_ipPart1->setStyleSheet("QLineEdit{color:rgb(0, 0, 0);background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-style: solid;border-right:none;}");
    m_ipPart2->setStyleSheet("QLineEdit{color:rgb(0, 0, 0);background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-style: solid;border-left:none;border-right:none;}");
    m_ipPart3->setStyleSheet("QLineEdit{color:rgb(0, 0, 0);background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-style: solid;border-left:none;border-right:none;}");
    m_ipPart4->setStyleSheet("QLineEdit{color:rgb(0, 0, 0);background-color:rgb(240, 240, 240);border-color: rgb(184, 180, 176);border-width: 1px;border-style: solid;border-left:none;}");

    QWidget::setTabOrder(m_ipPart1, m_ipPart2);
    QWidget::setTabOrder(m_ipPart2, m_ipPart3);
    QWidget::setTabOrder(m_ipPart3, m_ipPart4);
    m_ipPart1->setNextTabEdit(m_ipPart2);
    m_ipPart2->setNextTabEdit(m_ipPart3);
    m_ipPart3->setNextTabEdit(m_ipPart4);
    m_ipPart4->setNextTabEdit(m_ipPart4);

	m_ipPart4->setLastTabEdit(m_ipPart3);
	m_ipPart3->setLastTabEdit(m_ipPart2);
	m_ipPart2->setLastTabEdit(m_ipPart1);
	m_ipPart1->setLastTabEdit(m_ipPart1);

    m_ipPart1->setObjectName(tr("ip_part1"));
    m_ipPart2->setObjectName(tr("ip_part2"));
    m_ipPart3->setObjectName(tr("ip_part3"));
    m_ipPart4->setObjectName(tr("ip_part4"));

    connect(m_ipPart1, SIGNAL(clickedLeft()), this, SLOT(showKeyboardSlot()));
    connect(m_ipPart1, SIGNAL(clickedRight()), this, SLOT(hideKeyboardSlot()));
    connect(m_ipPart2, SIGNAL(clickedLeft()), this, SLOT(showKeyboardSlot()));
    connect(m_ipPart2, SIGNAL(clickedRight()), this, SLOT(hideKeyboardSlot()));
    connect(m_ipPart3, SIGNAL(clickedLeft()), this, SLOT(showKeyboardSlot()));
    connect(m_ipPart3, SIGNAL(clickedRight()), this, SLOT(hideKeyboardSlot()));
    connect(m_ipPart4, SIGNAL(clickedLeft()), this, SLOT(showKeyboardSlot()));
    connect(m_ipPart4, SIGNAL(clickedRight()), this, SLOT(hideKeyboardSlot()));
}

void iplineedit::showKeyboardSlot()
{
    QObject* Object=sender();
    if(Object==0)
    {
        return ;
    }
    if(Object->objectName() != send_name)
    {
        flag_show = 1;
        send_name = Object->objectName();
    }

    flag_show++;

    if(flag_show%2==0)
    {
        emit showKeyboardSig();
    }
    else
    {
        emit hideKeyboardSig();
    }
}

void iplineedit::hideKeyboardSlot()
{
    flag_show = 1;
    emit hideKeyboardSig();
}
