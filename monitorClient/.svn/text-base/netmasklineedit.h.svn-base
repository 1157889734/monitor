#ifndef NETMASKLINEEDIT_H
#define NETMASKLINEEDIT_H

#include <QLineEdit>
#include <QLabel>
#include "netmaskpartlineedit.h"

class netmasklineedit : public QLineEdit
{
    Q_OBJECT
public:
    explicit netmasklineedit(QWidget *parent = 0);
    MyNetMaskPartLineEdit *m_ipPart1;
    MyNetMaskPartLineEdit *m_ipPart2;
    MyNetMaskPartLineEdit *m_ipPart3;
    MyNetMaskPartLineEdit *m_ipPart4;

    QLabel *m_labeldDot1;
    QLabel *m_labeldDot2;
    QLabel *m_labeldDot3;

private slots:
    void showKeyboardSlot();
    void hideKeyboardSlot();

signals:
    void showKeyboardSig();
    void hideKeyboardSig();
};

#endif // IPLINEEDIT_H

