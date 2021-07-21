/********************************************************************************
** Form generated from reading UI file 'pvmsMonitorWidget.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVMSMONITORWIDGET_H
#define UI_PVMSMONITORWIDGET_H

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

class Ui_pvmsMonitorWidget
{
public:
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QPushButton *ptzLeftPushButton;
    QPushButton *ptzUpPushButton;
    QPushButton *ptzRightPushButton;
    QPushButton *ptzDownPushButton;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *zoomInPushButton;
    QPushButton *zoomOutPushButton;
    QPushButton *focusFarPushButton;
    QPushButton *focusNearPushButton;
    QLabel *label_7;
    QFrame *line_2;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *presetNoPushButton;
    QPushButton *presetNoPushButton_5;
    QPushButton *presetSetPushButton;
    QPushButton *cameraSwitchPushButton;
    QFrame *line_3;
    QPushButton *presetGetPushButton;
    QPushButton *fillLightSwitchPushButton;
    QPushButton *presetNoPushButton_2;
    QPushButton *presetNoPushButton_3;
    QPushButton *presetNoPushButton_4;
    QPushButton *presetNoPushButton_6;
    QPushButton *presetNoPushButton_7;
    QPushButton *presetNoPushButton_8;
    QPushButton *startPollingPushButton;
    QPushButton *pausePollingPushButton;
    QPushButton *pollingLastOnePushButton;
    QPushButton *pollingNextOnePushButton;
    QPushButton *alarmPushButton;
    QPushButton *temporarySavePushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_10;

    void setupUi(QWidget *pvmsMonitorWidget)
    {
        if (pvmsMonitorWidget->objectName().isEmpty())
            pvmsMonitorWidget->setObjectName(QString::fromUtf8("pvmsMonitorWidget"));
        pvmsMonitorWidget->resize(1024, 665);
        pvmsMonitorWidget->setAutoFillBackground(false);
        label_3 = new QLabel(pvmsMonitorWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(794, 5, 226, 55));
        QFont font;
        font.setPointSize(18);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setStyleSheet(QString::fromUtf8(" #label_3 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_3 * { \n"
"     background-color:; \n"
" }"));
        label_3->setTextFormat(Qt::AutoText);
        line = new QFrame(pvmsMonitorWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(794, 50, 226, 2));
        line->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(pvmsMonitorWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(794, 60, 226, 131));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8(" #label_4 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_4 * { \n"
"     background-color:; \n"
" }"));
        ptzLeftPushButton = new QPushButton(pvmsMonitorWidget);
        ptzLeftPushButton->setObjectName(QString::fromUtf8("ptzLeftPushButton"));
        ptzLeftPushButton->setGeometry(QRect(828, 100, 40, 40));
        ptzLeftPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 255, 255);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(53, 159, 229);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 96, 138);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/ptz_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzLeftPushButton->setIcon(icon);
        ptzLeftPushButton->setIconSize(QSize(50, 50));
        ptzUpPushButton = new QPushButton(pvmsMonitorWidget);
        ptzUpPushButton->setObjectName(QString::fromUtf8("ptzUpPushButton"));
        ptzUpPushButton->setGeometry(QRect(890, 60, 40, 40));
        ptzUpPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 255, 255);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(53, 159, 229);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 96, 138);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/ptz_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzUpPushButton->setIcon(icon1);
        ptzUpPushButton->setIconSize(QSize(50, 50));
        ptzUpPushButton->setFlat(false);
        ptzRightPushButton = new QPushButton(pvmsMonitorWidget);
        ptzRightPushButton->setObjectName(QString::fromUtf8("ptzRightPushButton"));
        ptzRightPushButton->setGeometry(QRect(950, 100, 40, 40));
        ptzRightPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 255, 255);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(53, 159, 229);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 96, 138);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/ptz_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzRightPushButton->setIcon(icon2);
        ptzRightPushButton->setIconSize(QSize(50, 50));
        ptzDownPushButton = new QPushButton(pvmsMonitorWidget);
        ptzDownPushButton->setObjectName(QString::fromUtf8("ptzDownPushButton"));
        ptzDownPushButton->setGeometry(QRect(890, 140, 40, 40));
        ptzDownPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 255, 255);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(53, 159, 229);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(35, 96, 138);border-color: rgb(183, 183, 183);border-width: 1px;border-style: solid;}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/ptz_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzDownPushButton->setIcon(icon3);
        ptzDownPushButton->setIconSize(QSize(50, 50));
        label_5 = new QLabel(pvmsMonitorWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(794, 185, 226, 51));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8(" #label_5 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_5 * { \n"
"     background-color:; \n"
" }"));
        label_6 = new QLabel(pvmsMonitorWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(794, 230, 226, 41));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("#label_6 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_6 * { \n"
"     background-color:; \n"
" }"));
        zoomInPushButton = new QPushButton(pvmsMonitorWidget);
        zoomInPushButton->setObjectName(QString::fromUtf8("zoomInPushButton"));
        zoomInPushButton->setGeometry(QRect(934, 190, 71, 35));
        zoomInPushButton->setFont(font1);
        zoomInPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        zoomOutPushButton = new QPushButton(pvmsMonitorWidget);
        zoomOutPushButton->setObjectName(QString::fromUtf8("zoomOutPushButton"));
        zoomOutPushButton->setGeometry(QRect(812, 190, 71, 35));
        zoomOutPushButton->setFont(font1);
        zoomOutPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        focusFarPushButton = new QPushButton(pvmsMonitorWidget);
        focusFarPushButton->setObjectName(QString::fromUtf8("focusFarPushButton"));
        focusFarPushButton->setGeometry(QRect(812, 230, 71, 35));
        focusFarPushButton->setFont(font1);
        focusFarPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        focusNearPushButton = new QPushButton(pvmsMonitorWidget);
        focusNearPushButton->setObjectName(QString::fromUtf8("focusNearPushButton"));
        focusNearPushButton->setGeometry(QRect(934, 230, 71, 35));
        focusNearPushButton->setFont(font1);
        focusNearPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        label_7 = new QLabel(pvmsMonitorWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(794, 280, 226, 41));
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QString::fromUtf8(" #label_7 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_7 * { \n"
"     background-color:; \n"
" }"));
        label_7->setTextFormat(Qt::AutoText);
        line_2 = new QFrame(pvmsMonitorWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(794, 320, 226, 2));
        line_2->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(pvmsMonitorWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(794, 323, 226, 245));
        label_8->setStyleSheet(QString::fromUtf8(" #label_8 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_8 * { \n"
"     background-color:; \n"
" }"));
        label_9 = new QLabel(pvmsMonitorWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(794, 579, 226, 81));
        label_9->setStyleSheet(QString::fromUtf8(" #label_9 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_9 * { \n"
"	 color: rgb(33, 131, 229);\n"
"     background-color:; \n"
" }"));
        presetNoPushButton = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton->setObjectName(QString::fromUtf8("presetNoPushButton"));
        presetNoPushButton->setGeometry(QRect(810, 330, 42, 60));
        presetNoPushButton->setFont(font1);
        presetNoPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton->setCheckable(true);
        presetNoPushButton->setChecked(false);
        presetNoPushButton->setFlat(false);
        presetNoPushButton_5 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_5->setObjectName(QString::fromUtf8("presetNoPushButton_5"));
        presetNoPushButton_5->setGeometry(QRect(810, 410, 42, 60));
        presetNoPushButton_5->setFont(font1);
        presetNoPushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_5->setCheckable(true);
        presetSetPushButton = new QPushButton(pvmsMonitorWidget);
        presetSetPushButton->setObjectName(QString::fromUtf8("presetSetPushButton"));
        presetSetPushButton->setGeometry(QRect(810, 490, 81, 32));
        presetSetPushButton->setFont(font1);
        presetSetPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetSetPushButton->setCheckable(false);
        presetSetPushButton->setChecked(false);
        cameraSwitchPushButton = new QPushButton(pvmsMonitorWidget);
        cameraSwitchPushButton->setObjectName(QString::fromUtf8("cameraSwitchPushButton"));
        cameraSwitchPushButton->setGeometry(QRect(810, 530, 81, 32));
        cameraSwitchPushButton->setFont(font1);
        cameraSwitchPushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        cameraSwitchPushButton->setCheckable(true);
        line_3 = new QFrame(pvmsMonitorWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(794, 578, 226, 2));
        line_3->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        presetGetPushButton = new QPushButton(pvmsMonitorWidget);
        presetGetPushButton->setObjectName(QString::fromUtf8("presetGetPushButton"));
        presetGetPushButton->setGeometry(QRect(924, 490, 81, 32));
        presetGetPushButton->setFont(font1);
        presetGetPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        fillLightSwitchPushButton = new QPushButton(pvmsMonitorWidget);
        fillLightSwitchPushButton->setObjectName(QString::fromUtf8("fillLightSwitchPushButton"));
        fillLightSwitchPushButton->setGeometry(QRect(924, 530, 81, 32));
        fillLightSwitchPushButton->setFont(font1);
        fillLightSwitchPushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        fillLightSwitchPushButton->setCheckable(true);
        presetNoPushButton_2 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_2->setObjectName(QString::fromUtf8("presetNoPushButton_2"));
        presetNoPushButton_2->setGeometry(QRect(860, 330, 42, 60));
        presetNoPushButton_2->setFont(font1);
        presetNoPushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
""));
        presetNoPushButton_2->setCheckable(true);
        presetNoPushButton_3 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_3->setObjectName(QString::fromUtf8("presetNoPushButton_3"));
        presetNoPushButton_3->setGeometry(QRect(910, 330, 42, 60));
        presetNoPushButton_3->setFont(font1);
        presetNoPushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_3->setCheckable(true);
        presetNoPushButton_4 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_4->setObjectName(QString::fromUtf8("presetNoPushButton_4"));
        presetNoPushButton_4->setGeometry(QRect(960, 330, 42, 60));
        presetNoPushButton_4->setFont(font1);
        presetNoPushButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_4->setCheckable(true);
        presetNoPushButton_6 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_6->setObjectName(QString::fromUtf8("presetNoPushButton_6"));
        presetNoPushButton_6->setGeometry(QRect(860, 410, 42, 60));
        presetNoPushButton_6->setFont(font1);
        presetNoPushButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_6->setCheckable(true);
        presetNoPushButton_7 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_7->setObjectName(QString::fromUtf8("presetNoPushButton_7"));
        presetNoPushButton_7->setGeometry(QRect(910, 410, 42, 60));
        presetNoPushButton_7->setFont(font1);
        presetNoPushButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_7->setCheckable(true);
        presetNoPushButton_8 = new QPushButton(pvmsMonitorWidget);
        presetNoPushButton_8->setObjectName(QString::fromUtf8("presetNoPushButton_8"));
        presetNoPushButton_8->setGeometry(QRect(960, 410, 42, 60));
        presetNoPushButton_8->setFont(font1);
        presetNoPushButton_8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover\n"
"{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        presetNoPushButton_8->setCheckable(true);
        startPollingPushButton = new QPushButton(pvmsMonitorWidget);
        startPollingPushButton->setObjectName(QString::fromUtf8("startPollingPushButton"));
        startPollingPushButton->setGeometry(QRect(820, 625, 30, 31));
        startPollingPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border-image: url(:/res/play_nor.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{border-image: url(:/res/play_hover.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{border-image: url(:/res/play_down.png);}\n"
"\n"
"QPushButton:checked\n"
"{border-image: url(:/res/play_down.png);}"));
        startPollingPushButton->setIconSize(QSize(30, 31));
        startPollingPushButton->setCheckable(true);
        startPollingPushButton->setChecked(false);
        startPollingPushButton->setFlat(true);
        pausePollingPushButton = new QPushButton(pvmsMonitorWidget);
        pausePollingPushButton->setObjectName(QString::fromUtf8("pausePollingPushButton"));
        pausePollingPushButton->setGeometry(QRect(880, 625, 30, 31));
        pausePollingPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border-image: url(:/res/pause_nor.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{border-image: url(:/res/pause_hover.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{border-image: url(:/res/pause_down.png);}\n"
"\n"
"QPushButton:checked\n"
"{border-image: url(:/res/pause_down.png);}"));
        pausePollingPushButton->setIconSize(QSize(30, 31));
        pausePollingPushButton->setCheckable(true);
        pausePollingPushButton->setFlat(true);
        pollingLastOnePushButton = new QPushButton(pvmsMonitorWidget);
        pollingLastOnePushButton->setObjectName(QString::fromUtf8("pollingLastOnePushButton"));
        pollingLastOnePushButton->setGeometry(QRect(820, 585, 30, 31));
        pollingLastOnePushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border-image: url(:/res/prev_nor.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{border-image: url(:/res/prev_hover.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{border-image: url(:/res/prev_down.png);background-color: rgb(255, 255, 255);}\n"
""));
        pollingLastOnePushButton->setIconSize(QSize(30, 31));
        pollingLastOnePushButton->setFlat(true);
        pollingNextOnePushButton = new QPushButton(pvmsMonitorWidget);
        pollingNextOnePushButton->setObjectName(QString::fromUtf8("pollingNextOnePushButton"));
        pollingNextOnePushButton->setGeometry(QRect(880, 585, 30, 31));
        pollingNextOnePushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border-image: url(:/res/next_nor.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:hover\n"
"{border-image: url(:/res/next_hover.png);background-color: rgb(255, 255, 255);}\n"
"\n"
"QPushButton:pressed\n"
"{border-image: url(:/res/next_down.png);background-color: rgb(255, 255, 255);}"));
        pollingNextOnePushButton->setIconSize(QSize(30, 31));
        pollingNextOnePushButton->setFlat(true);
        alarmPushButton = new QPushButton(pvmsMonitorWidget);
        alarmPushButton->setObjectName(QString::fromUtf8("alarmPushButton"));
        alarmPushButton->setGeometry(QRect(930, 587, 71, 31));
        alarmPushButton->setFont(font1);
        alarmPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(255, 0, 0);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
""));
        alarmPushButton->setCheckable(true);
        temporarySavePushButton = new QPushButton(pvmsMonitorWidget);
        temporarySavePushButton->setObjectName(QString::fromUtf8("temporarySavePushButton"));
        temporarySavePushButton->setGeometry(QRect(930, 624, 71, 31));
        temporarySavePushButton->setFont(font1);
        temporarySavePushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        label = new QLabel(pvmsMonitorWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(894, 200, 31, 17));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 131, 229);"));
        label_2 = new QLabel(pvmsMonitorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(894, 240, 31, 17));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 131, 229);"));
        label_10 = new QLabel(pvmsMonitorWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(894, 110, 31, 17));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 131, 229);"));

        retranslateUi(pvmsMonitorWidget);

        QMetaObject::connectSlotsByName(pvmsMonitorWidget);
    } // setupUi

    void retranslateUi(QWidget *pvmsMonitorWidget)
    {
        pvmsMonitorWidget->setWindowTitle(QApplication::translate("pvmsMonitorWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("pvmsMonitorWidget", "  \344\272\221\345\217\260\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        ptzLeftPushButton->setText(QString());
        ptzUpPushButton->setText(QString());
        ptzRightPushButton->setText(QString());
        ptzDownPushButton->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        zoomInPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\347\274\251", 0, QApplication::UnicodeUTF8));
        zoomOutPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\344\274\270", 0, QApplication::UnicodeUTF8));
        focusFarPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\350\277\234", 0, QApplication::UnicodeUTF8));
        focusNearPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\350\277\221", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("pvmsMonitorWidget", "  \351\242\204\347\275\256\347\202\271", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QString());
        presetNoPushButton->setText(QApplication::translate("pvmsMonitorWidget", "1", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_5->setText(QApplication::translate("pvmsMonitorWidget", "5", 0, QApplication::UnicodeUTF8));
        presetSetPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        cameraSwitchPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\346\221\204\345\203\217\345\244\264\345\205\263", 0, QApplication::UnicodeUTF8));
        presetGetPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\350\260\203\347\224\250", 0, QApplication::UnicodeUTF8));
        fillLightSwitchPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\350\241\245\345\205\211\347\201\257\345\274\200", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_2->setText(QApplication::translate("pvmsMonitorWidget", "2", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_3->setText(QApplication::translate("pvmsMonitorWidget", "3", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_4->setText(QApplication::translate("pvmsMonitorWidget", "4", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_6->setText(QApplication::translate("pvmsMonitorWidget", "6", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_7->setText(QApplication::translate("pvmsMonitorWidget", "7", 0, QApplication::UnicodeUTF8));
        presetNoPushButton_8->setText(QApplication::translate("pvmsMonitorWidget", "8", 0, QApplication::UnicodeUTF8));
        startPollingPushButton->setText(QString());
        pausePollingPushButton->setText(QString());
        pollingLastOnePushButton->setText(QString());
        pollingNextOnePushButton->setText(QString());
        alarmPushButton->setText(QApplication::translate("pvmsMonitorWidget", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        temporarySavePushButton->setText(QApplication::translate("pvmsMonitorWidget", "\347\253\213\345\215\263\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pvmsMonitorWidget", "\350\260\203\347\204\246", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("pvmsMonitorWidget", "\350\201\232\347\204\246", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("pvmsMonitorWidget", "\346\226\271\345\220\221", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pvmsMonitorWidget: public Ui_pvmsMonitorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVMSMONITORWIDGET_H
