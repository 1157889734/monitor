#include "netmaskpartlineedit.h"
#include <QIntValidator>
#include <QKeyEvent>
#include <QMouseEvent>

MyNetMaskPartLineEdit::MyNetMaskPartLineEdit(QWidget *parent/* = 0*/)
            : QLineEdit(parent)
{
    m_nextTab = NULL;

    this->setMaxLength(3);
    this->setFrame(false);
    this->setAlignment(Qt::AlignLeft);

    QValidator *validator = new QIntValidator(0, 255, this);
    this->setValidator(validator);

    connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(textEditSlot(const QString&)));
}

MyNetMaskPartLineEdit::~MyNetMaskPartLineEdit(void)
{
}

void MyNetMaskPartLineEdit::textEditSlot(const QString& text)
{
    QIntValidator v(0, 255, this);
    QString ipaddr = text;
    int pos = 0;
    QValidator::State state = v.validate(ipaddr, pos);
    if (state == QValidator::Acceptable)
    {
        if (3 == ipaddr.size())
        {
            m_nextTab->setFocus();
        }
    }

	if (ipaddr == "")
	{
        m_lastTab->setFocus();
	}
}

void MyNetMaskPartLineEdit::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
    {
        emit clickedLeft();
    }
    else if (event->button() == Qt::RightButton)
    {
        emit clickedRight();
    }
}
