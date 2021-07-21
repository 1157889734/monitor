#ifndef LACALSET_H
#define LACALSET_H

#include <QWidget>
#include "timeset.h"
#include "commonInputMethod.h"
#include "iplineedit.h"
#include "netmasklineedit.h"
#include "addTraintypeWidget.h"
#include "editTraintypeWidget.h"

namespace Ui {
class localSet;
}

class localSet : public QWidget
{
    Q_OBJECT

public:
    explicit localSet(QWidget *parent = 0);
    ~localSet();
    bool eventFilter(QObject *target, QEvent *event);

public slots:
	void closeButtonClickSlot();
	void openTimeSetWinSlot();
	void timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec);
	void timeSetCancle();
	void tabWidgetCurrentChangedSlot(int iDex);
	void confirmSlot();
	void cancleSlot();
	void showKeyboardSlot();
	void hideKeyboardSlot();
	void delTrainType();
	void addTrainType();
	void editTrainType();
	void importTrainType();
    void CloseTrainTypeEdit();
    void CloseTrainTypeAdd();
    void stationConfigFileExport();
	
signals:
    void closeWidgetSignal();
    void loadEditTrainTypePage(char *pcTrainType);
    void timeManuelSetSignal();
	
private:
    Ui::localSet *ui;
    int m_widgetWidth;
    int m_widgetHeight;
    int m_tabWidgetPageIdex;
    timeSet *timeSetWidget;    //时间设置控制窗体
    commonInputMethod *p_ipmethod;
    iplineedit *m_ipLineEdit;
    iplineedit *m_gatewayLineEdit;
    netmasklineedit *m_netmaskLineEdit;
    iplineedit *m_pisServerIpLineEdit;
    addTrainTypeWidget *trainTypeAddPage;
    editTraintypeWidget *trainTypeEditPage;  
	int checkImportFile(char *pcFileName);//校验U盘cfg目录下的车厢配置文件
};

#endif // LACALSET_H
