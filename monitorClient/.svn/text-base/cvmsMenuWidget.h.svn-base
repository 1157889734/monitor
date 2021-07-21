#ifndef MENUOFCARRIAGES_H
#define MENUOFCARRIAGES_H

#include <QWidget>
#include "cvmsMonitorWidget.h"
#include "recplaybackofcarriages.h"
#include "devmanageofcarriages.h"
#include "devupdateofcarriages.h"

namespace Ui {
class menuofcarriages;
}

class cvmsMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cvmsMenuWidget(QWidget *parent = 0);
    ~cvmsMenuWidget();

public slots:
    void showPageSlot();     //显示当前页面的响应槽函数
    void regisoutBtClick();
    void menuBtClick();

signals:
    void registOutSignal(int iType);

private:
    Ui::menuofcarriages *ui;
    cvmsMonitorWidget *cvmsMonitorPage;
    recplaybackofcarriages *recpbPage;
    devmanageofcarriages *devmanagePage;
    devupdateofcarriages *devupdatePage;
};

#endif // MENUOFCARRIAGES_H
