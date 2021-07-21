#ifndef ADDTRAINTYPEWIDGET_H
#define ADDTRAINTYPEWIDGET_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class addTrainTypeWidget;
}

class addTrainTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit addTrainTypeWidget(QWidget *parent = 0);
    ~addTrainTypeWidget();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
    void closeWidgetSlot();
	void confirmSlot();
	void cancleSlot();
	void groupSetChange(int iComboBoxId);
    void serverNumChangeSlot();

signals:
    void sendCloseMsg();

private:
    Ui::addTrainTypeWidget *ui;
    commonInputMethod *p_ipmethod;
};

#endif // ADDTRAINTYPEWIDGET_H
