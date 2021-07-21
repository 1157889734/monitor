#ifndef CHOICECARRIAGES_H
#define CHOICECARRIAGES_H

#include <QWidget>

namespace Ui {
class choicecarriages;
}

class choiceCarriageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit choiceCarriageWidget(QWidget *parent = 0);
    ~choiceCarriageWidget();

public slots:
    void showPageSlot();  //显示当前页面的响应槽函数
    void buttonClick();

signals:
    void confirmCarriageSignal();

private:
    Ui::choicecarriages *ui;
};

#endif // CHOICECARRIAGES_H
