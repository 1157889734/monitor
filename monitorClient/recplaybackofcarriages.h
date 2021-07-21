#ifndef RECPLAYBACKOFCARRIAGES_H
#define RECPLAYBACKOFCARRIAGES_H

#include <QWidget>
#include "timeset.h"

namespace Ui {
class recplaybackofcarriages;
}

class recplaybackofcarriages : public QWidget
{
    Q_OBJECT

public:
    explicit recplaybackofcarriages(QWidget *parent = 0);
    ~recplaybackofcarriages();
    timeSet *timesetwid;

public slots:
    void timeSetClick();
    void timeSetRecvMsg(QString year, QString month, QString day, QString hour, QString min, QString sec);

private:
    Ui::recplaybackofcarriages *ui;
};

#endif // RECPLAYBACKOFCARRIAGES_H
