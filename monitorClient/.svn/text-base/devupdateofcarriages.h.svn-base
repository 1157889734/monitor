#ifndef DEVUPDATEOFCARRIAGES_H
#define DEVUPDATEOFCARRIAGES_H

#include <QWidget>
#include "setcarriagesnumber.h"
#include "userManage.h"

namespace Ui {
class devupdateofcarriages;
}

class devupdateofcarriages : public QWidget
{
    Q_OBJECT

public:
    explicit devupdateofcarriages(QWidget *parent = 0);
    ~devupdateofcarriages();

public slots:
    void buttonClick();
    void RecvSetCarNuMsg();
    void RecvUserManageMsg();

private:
    Ui::devupdateofcarriages *ui;
    setcarriagesnumber *setCaNoPage;
    userManage * usermanagePage;
};

#endif // DEVUPDATEOFCARRIAGES_H
