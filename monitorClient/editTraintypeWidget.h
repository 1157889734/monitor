#ifndef EDITTRAINTYPEWIDGET_H
#define EDITTRAINTYPEWIDGET_H

#include <QWidget>
#include "commonInputMethod.h"

namespace Ui {
class editTraintypeWidget;
}

class editTraintypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit editTraintypeWidget(QWidget *parent = 0);
    ~editTraintypeWidget();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
	void pageLoadSlot(char *pcTrainType);
    void closeWidgetSlot();
	void confirmSlot();
	void cancleSlot();
	void groupSetChange(int iComboBoxId);
    void serverNumChangeSlot();

signals:
    void sendCloseMsg();    

private:
    Ui::editTraintypeWidget *ui;
    commonInputMethod *p_ipmethod;
    char m_acTrainType[128];
};

#endif // EDITTRAINTYPEWIDGET_H
