#ifndef PRESETPASSWDCONFIRM_H
#define PRESETPASSWDCONFIRM_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class PresetPasswdConfirm;
}

class PresetPasswdConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit PresetPasswdConfirm(QWidget *parent = 0);
    ~PresetPasswdConfirm();
    bool eventFilter(QObject *target, QEvent *event);
    commonInputMethod *p_ipmethod;


public slots:
    void pushButtonClickSlot();

signals:
    void sendCloseSignal();
    void sendOkSignal();

private:
    Ui::PresetPasswdConfirm *ui;
};

#endif // PRESETPASSWDCONFIRM_H
