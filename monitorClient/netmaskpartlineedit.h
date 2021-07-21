#ifndef NETMASKPARTLINEEDIT_H
#define NETMASKPARTLINEEDIT_H

#include <QLineEdit>

class QWidget;
class QFocusEvent;
class QKeyEvent;

class MyNetMaskPartLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyNetMaskPartLineEdit(QWidget *parent = 0);
    ~MyNetMaskPartLineEdit(void);

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

