#ifndef USEREDIT_H
#define USEREDIT_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class useredit;
}

class userEdit : public QWidget
{
    Q_OBJECT

public:
    explicit userEdit(QWidget *parent = 0);
    ~userEdit();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
    void recvOpenMsg(QString userName);
	void closeWidgetSlot();
	void confirmSlot();
	void cancleSlot();

signals:
    void sendCloseMsg();

private:
    Ui::useredit *ui;
    commonInputMethod *p_ipmethod;
};

#endif // USEREDIT_H
