/********************************************************************************
** Form generated from reading UI file 'alarmWidget.ui'
**
** Created: Wed Mar 7 10:53:16 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMWIDGET_H
#define UI_ALARMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alarmWidget
{
public:
    QFrame *frame;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *clearPushButton;
    QPushButton *closeRPushButton;
    QPushButton *closePushButton;

    void setupUi(QWidget *alarmWidget)
    {
        if (alarmWidget->objectName().isEmpty())
            alarmWidget->setObjectName(QString::fromUtf8("alarmWidget"));
        alarmWidget->resize(635, 390);
        frame = new QFrame(alarmWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 635, 390));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color: rgb(217, 221, 223);\n"
"border-color: rgb(184, 180, 176);\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 635, 25));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 124, 224);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 40, 575, 291));
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget->verticalHeader()->setVisible(false);
        clearPushButton = new QPushButton(frame);
        clearPushButton->setObjectName(QString::fromUtf8("clearPushButton"));
        clearPushButton->setGeometry(QRect(195, 350, 90, 30));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        clearPushButton->setFont(font1);
        clearPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        closeRPushButton = new QPushButton(frame);
        closeRPushButton->setObjectName(QString::fromUtf8("closeRPushButton"));
        closeRPushButton->setGeometry(QRect(350, 350, 90, 30));
        closeRPushButton->setFont(font1);
        closeRPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        closePushButton = new QPushButton(alarmWidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(608, 3, 23, 20));
        closePushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/close.png);"));

        retranslateUi(alarmWidget);

        QMetaObject::connectSlotsByName(alarmWidget);
    } // setupUi

    void retranslateUi(QWidget *alarmWidget)
    {
        alarmWidget->setWindowTitle(QApplication::translate("alarmWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("alarmWidget", "\346\212\245\350\255\246\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("alarmWidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("alarmWidget", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("alarmWidget", "\346\212\245\350\255\246\350\257\246\346\203\205", 0, QApplication::UnicodeUTF8));
        clearPushButton->setText(QApplication::translate("alarmWidget", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        closeRPushButton->setText(QApplication::translate("alarmWidget", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class alarmWidget: public Ui_alarmWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMWIDGET_H
