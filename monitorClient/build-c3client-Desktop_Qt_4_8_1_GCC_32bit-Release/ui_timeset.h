/********************************************************************************
** Form generated from reading UI file 'timeset.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESET_H
#define UI_TIMESET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <mypushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_timeSet
{
public:
    QLabel *label;
    mypushbutton *pushButton_6;
    mypushbutton *pushButton_4;
    mypushbutton *pushButton_7;
    mypushbutton *pushButton_2;
    mypushbutton *pushButton_3;
    mypushbutton *pushButton_5;
    mypushbutton *pushButton_8;
    mypushbutton *pushButton_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *timeSet)
    {
        if (timeSet->objectName().isEmpty())
            timeSet->setObjectName(QString::fromUtf8("timeSet"));
        timeSet->resize(291, 291);
        label = new QLabel(timeSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 291, 291));
        label->setStyleSheet(QString::fromUtf8("#label {\n"
"   color: rgb(33, 131, 229);\n"
"	background-color: rgb(192, 193, 198);\n"
"}\n"
"#label  *{\n"
"	background-color: rgb();\n"
"}"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton_6 = new mypushbutton(timeSet);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(190, 157, 71, 81));
        pushButton_4 = new mypushbutton(timeSet);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 157, 71, 81));
        pushButton_7 = new mypushbutton(timeSet);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 257, 99, 27));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        pushButton_2 = new mypushbutton(timeSet);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 30, 71, 81));
        pushButton_3 = new mypushbutton(timeSet);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 30, 71, 81));
        pushButton_5 = new mypushbutton(timeSet);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(105, 157, 71, 81));
        pushButton_8 = new mypushbutton(timeSet);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(160, 257, 99, 27));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        pushButton_1 = new mypushbutton(timeSet);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(20, 30, 81, 81));
        label_2 = new QLabel(timeSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 57, 81, 27));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(timeSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 57, 71, 27));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(timeSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 57, 71, 27));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(timeSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 187, 71, 27));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(timeSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(105, 187, 71, 27));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(timeSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 187, 71, 27));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_7->setAlignment(Qt::AlignCenter);

        retranslateUi(timeSet);

        QMetaObject::connectSlotsByName(timeSet);
    } // setupUi

    void retranslateUi(QWidget *timeSet)
    {
        timeSet->setWindowTitle(QApplication::translate("timeSet", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("timeSet", "<html><head/><body><p>&nbsp;&nbsp;\346\227\245\346\234\237 ----------------------------------------</p><p><br/></p><p><br/></p><p> &nbsp;&nbsp;\346\227\266\351\227\264  ----------------------------------------<br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("timeSet", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("timeSet", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("timeSet", "+\n"
"\n"
"\n"
"-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("timeSet", "2016", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("timeSet", "11", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("timeSet", "19", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("timeSet", "14", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("timeSet", "30", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("timeSet", "00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class timeSet: public Ui_timeSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESET_H
