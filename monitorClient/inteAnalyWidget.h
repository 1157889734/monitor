#ifndef INTEANALYWIDGET_H
#define INTEANALYWIDGET_H

#include <QWidget>

namespace Ui {
class inteAnalyWidget;
}

class inteAnalyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit inteAnalyWidget(QWidget *parent = 0);
    ~inteAnalyWidget();
	void pageShowCtrl();

private:
    Ui::inteAnalyWidget *ui;
};

#endif // INTEANALYWIDGET_H