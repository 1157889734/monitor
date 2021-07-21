/********************************************************************************
** Form generated from reading UI file 'waitLoginWidget.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITLOGINWIDGET_H
#define UI_WAITLOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waitLoginWidget
{
public:
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *coutDownDisplayLabel;
    QPushButton *okPushButton;
    QLabel *versionLabel;

    void setupUi(QWidget *waitLoginWidget)
    {
        if (waitLoginWidget->objectName().isEmpty())
            waitLoginWidget->setObjectName(QString::fromUtf8("waitLoginWidget"));
        waitLoginWidget->resize(1024, 768);
        frame = new QFrame(waitLoginWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1024, 768));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"color: rgb(255, 255, 255);\n"
"	background-image: url(:/res/background1.png);\n"
"}\n"
"#frame *{\n"
"background-image: url();\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 310, 321, 31));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(615, 310, 31, 31));
        label_3->setFont(font);
        coutDownDisplayLabel = new QLabel(frame);
        coutDownDisplayLabel->setObjectName(QString::fromUtf8("coutDownDisplayLabel"));
        coutDownDisplayLabel->setGeometry(QRect(595, 310, 31, 31));
        coutDownDisplayLabel->setFont(font);
        okPushButton = new QPushButton(frame);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));
        okPushButton->setGeometry(QRect(430, 400, 111, 71));
        okPushButton->setFont(font);
        versionLabel = new QLabel(frame);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));
        versionLabel->setGeometry(QRect(890, 650, 81, 21));
        QFont font1;
        font1.setPointSize(16);
        versionLabel->setFont(font1);

        retranslateUi(waitLoginWidget);

        QMetaObject::connectSlotsByName(waitLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *waitLoginWidget)
    {
        waitLoginWidget->setWindowTitle(QApplication::translate("waitLoginWidget", "waitLoginWidget", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("waitLoginWidget", "\347\233\221\346\216\247\347\250\213\345\272\217\346\255\243\345\234\250\345\220\257\345\212\250\357\274\214\350\257\267\347\250\215\345\220\216......   ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("waitLoginWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        coutDownDisplayLabel->setText(QApplication::translate("waitLoginWidget", "12", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("waitLoginWidget", "\347\241\256  \350\256\244", 0, QApplication::UnicodeUTF8));
        versionLabel->setText(QApplication::translate("waitLoginWidget", "V1.0.0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class waitLoginWidget: public Ui_waitLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITLOGINWIDGET_H
