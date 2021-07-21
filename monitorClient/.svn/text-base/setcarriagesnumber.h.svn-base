#ifndef SETCARRIAGESNUMBER_H
#define SETCARRIAGESNUMBER_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class setcarriagesnumber;
}

class setcarriagesnumber : public QWidget
{
    Q_OBJECT

public:
    explicit setcarriagesnumber(QWidget *parent = 0);
    ~setcarriagesnumber();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
    void cancleBtClick();
    void CloseButtonClick();

signals:
    void SendEscape();

private:
    Ui::setcarriagesnumber *ui;
    commonInputMethod *p_ipmethod;
};

#endif // SETCARRIAGESNUMBER_H
