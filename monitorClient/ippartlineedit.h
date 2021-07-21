#ifndef IPPARTLINEEDIT_H
#define IPPARTLINEEDIT_H

#include <QLineEdit>

class QWidget;
class QFocusEvent;
class QKeyEvent;

class MyIpPartLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyIpPartLineEdit(QWidget *parent = 0);
    ~MyIpPartLineEdit(void);

    void setNextTabEdit(QLineEdit *nexttab) { m_nextTab = nexttab; }
    void setLastTabEdit(QLineEdit *lasttab) { m_lastTab = lasttab; }

protected:
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void clickedLeft();
    void clickedRight();

private slots:
    void textEditSlot(const QString& text);

private:
    QLineEdit *m_nextTab;
    QLineEdit *m_lastTab;
};

#endif // IPPARTLINEEDIT_H

