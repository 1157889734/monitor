#ifndef USERADD_H
#define USERADD_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class useradd;
}

class userAdd : public QWidget
{
    Q_OBJECT

public:
    explicit userAdd(QWidget *parent = 0);
    ~userAdd();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
    void closeWidgetSlot();
	void confirmSlot();
	void cancleSlot();

signals:
    void sendCloseMsg();

private:
    Ui::useradd *ui;
    commonInputMethod *p_ipmethod;
};


#endif // USERADD_H
