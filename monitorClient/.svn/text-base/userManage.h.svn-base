#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>
#include "userEdit.h"
#include "userAdd.h"

namespace Ui {
class usermanage;
}

class userManage : public QWidget
{
    Q_OBJECT

public:
    explicit userManage(QWidget *parent = 0);
    ~userManage();

public slots:
	void closeButtonClick();
	void delUser();
	void addUser();
	void editUser();
    void CloseUsrEdit();
    void CloseUsrAdd();
signals:
    void SendUsrEditMsg(QString usrName);
    void SendEscape();

private:
    Ui::usermanage *ui;
    userEdit *usrEditPage;
    userAdd *usrAddPage;
};

#endif // USERMANAGE_H
