#ifndef LOCALSETPASSWDCONFIRM_H
#define LOCALSETPASSWDCONFIRM_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class LocalsetPasswdConfirm;
}

class LocalsetPasswdConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit LocalsetPasswdConfirm(QWidget *parent = 0);
    ~LocalsetPasswdConfirm();
    bool eventFilter(QObject *target, QEvent *event);
    commonInputMethod *p_ipmethod;


public slots:
    void pushButtonClickSlot();

signals:
    void sendCloseSignal();
    void sendOkSignal();

private:
    Ui::LocalsetPasswdConfirm *ui;
};

#endif // LOCALSETPASSWDCONFIRM_H