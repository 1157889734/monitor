#ifndef IPLINEEDIT_H
#define IPLINEEDIT_H

#include <QLineEdit>
#include <QLabel>
#include "ippartlineedit.h"

class iplineedit : public QLineEdit
{
    Q_OBJECT
public:
    explicit iplineedit(QWidget *parent = 0);
    MyIpPartLineEdit *m_ipPart1;
    MyIpPartLineEdit *m_ipPart2;
    MyIpPartLineEdit *m_ipPart3;
    MyIpPartLineEdit *m_ipPart4;

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

