/********************************************************************************
** Form generated from reading UI file 'pvmsMenuWidget.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVMSMENUWIDGET_H
#define UI_PVMSMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pvmsMenuWidget
{
public:
    QLabel *label;
    QPushButton *loginOutPushButton;
    QPushButton *recordPlayMenuPushButton;
    QPushButton *pvmsMonitorMenuPushButton;
    QPushButton *devUpdateMenuPushButton;
    QPushButton *inteAnalyMenuPushButton;
    QPushButton *devManageMenuPushButton;

    void setupUi(QWidget *pvmsMenuWidget)
    {
        if (pvmsMenuWidget->objectName().isEmpty())
            pvmsMenuWidget->setObjectName(QString::fromUtf8("pvmsMenuWidget"));
        pvmsMenuWidget->resize(1024, 768);
        pvmsMenuWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 246, 246);"));
        label = new QLabel(pvmsMenuWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1024, 32));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(" #label { \n"
"    background-image: url(:/res/MainDlgHead.png); \n"
"    color: rgb(255, 255, 255);\n"
"  } \n"
" #label * { \n"
"    background-image:url(); \n"
" }"));
        loginOutPushButton = new QPushButton(pvmsMenuWidget);
        loginOutPushButton->setObjectName(QString::fromUtf8("loginOutPushButton"));
        loginOutPushButton->setGeometry(QRect(950, 0, 71, 31));
        loginOutPushButton->setFont(font);
        loginOutPushButton->setAutoFillBackground(false);
        loginOutPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/zxanniubk.png);\n"
""));
        loginOutPushButton->setAutoDefault(false);
        loginOutPushButton->setDefault(false);
        loginOutPushButton->setFlat(true);
        recordPlayMenuPushButton = new QPushButton(pvmsMenuWidget);
        recordPlayMenuPushButton->setObjectName(QString::fromUtf8("recordPlayMenuPushButton"));
        recordPlayMenuPushButton->setGeometry(QRect(205, 32, 204, 71));
        recordPlayMenuPushButton->setFont(font);
        recordPlayMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(49, 150, 220);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(38, 131, 245);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}"));
        recordPlayMenuPushButton->setCheckable(true);
        recordPlayMenuPushButton->setFlat(false);
        pvmsMonitorMenuPushButton = new QPushButton(pvmsMenuWidget);
        pvmsMonitorMenuPushButton->setObjectName(QString::fromUtf8("pvmsMonitorMenuPushButton"));
        pvmsMonitorMenuPushButton->setGeometry(QRect(0, 32, 204, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(18);
        pvmsMonitorMenuPushButton->setFont(font1);
        pvmsMonitorMenuPushButton->setAutoFillBackground(false);
        pvmsMonitorMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(49, 150, 220);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(38, 131, 245);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}"));
        pvmsMonitorMenuPushButton->setCheckable(true);
        pvmsMonitorMenuPushButton->setChecked(false);
        pvmsMonitorMenuPushButton->setFlat(false);
        devUpdateMenuPushButton = new QPushButton(pvmsMenuWidget);
        devUpdateMenuPushButton->setObjectName(QString::fromUtf8("devUpdateMenuPushButton"));
        devUpdateMenuPushButton->setGeometry(QRect(820, 32, 204, 71));
        devUpdateMenuPushButton->setFont(font);
        devUpdateMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(49, 150, 220);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(38, 131, 245);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}"));
        devUpdateMenuPushButton->setCheckable(true);
        devUpdateMenuPushButton->setFlat(false);
        inteAnalyMenuPushButton = new QPushButton(pvmsMenuWidget);
        inteAnalyMenuPushButton->setObjectName(QString::fromUtf8("inteAnalyMenuPushButton"));
        inteAnalyMenuPushButton->setGeometry(QRect(410, 32, 204, 71));
        inteAnalyMenuPushButton->setFont(font);
        inteAnalyMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(49, 150, 220);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(38, 131, 245);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}"));
        inteAnalyMenuPushButton->setCheckable(true);
        inteAnalyMenuPushButton->setFlat(false);
        devManageMenuPushButton = new QPushButton(pvmsMenuWidget);
        devManageMenuPushButton->setObjectName(QString::fromUtf8("devManageMenuPushButton"));
        devManageMenuPushButton->setGeometry(QRect(615, 32, 204, 71));
        devManageMenuPushButton->setFont(font);
        devManageMenuPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(49, 150, 220);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(38, 131, 245);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(35, 86, 138);color: rgb(255, 255, 255);}"));
        devManageMenuPushButton->setCheckable(true);
        devManageMenuPushButton->setFlat(false);

        retranslateUi(pvmsMenuWidget);

        QMetaObject::connectSlotsByName(pvmsMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *pvmsMenuWidget)
    {
        pvmsMenuWidget->setWindowTitle(QApplication::translate("pvmsMenuWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pvmsMenuWidget", " \345\217\227\347\224\265\345\274\223\350\247\206\351\242\221\347\233\221\346\216\247\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        loginOutPushButton->setText(QApplication::translate("pvmsMenuWidget", "\346\263\250 \351\224\200", 0, QApplication::UnicodeUTF8));
        recordPlayMenuPushButton->setText(QApplication::translate("pvmsMenuWidget", "\345\275\225\345\203\217\345\233\236\346\224\276", 0, QApplication::UnicodeUTF8));
        pvmsMonitorMenuPushButton->setText(QApplication::translate("pvmsMenuWidget", "\345\217\227\347\224\265\345\274\223\347\233\221\346\216\247", 0, QApplication::UnicodeUTF8));
        devUpdateMenuPushButton->setText(QApplication::translate("pvmsMenuWidget", "\347\273\264\346\212\244\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        inteAnalyMenuPushButton->setText(QApplication::translate("pvmsMenuWidget", "\346\231\272\350\203\275\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        devManageMenuPushButton->setText(QApplication::translate("pvmsMenuWidget", "\350\256\276\345\244\207\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pvmsMenuWidget: public Ui_pvmsMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVMSMENUWIDGET_H
