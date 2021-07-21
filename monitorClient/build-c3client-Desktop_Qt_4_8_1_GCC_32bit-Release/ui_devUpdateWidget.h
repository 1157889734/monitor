/********************************************************************************
** Form generated from reading UI file 'devUpdateWidget.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVUPDATEWIDGET_H
#define UI_DEVUPDATEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_devUpdateWidget
{
public:
    QLabel *label;
    QComboBox *trainTypeSetComboBox;
    QPushButton *alarmPushButton;
    QPushButton *permissonManagePushButton;
    QPushButton *trainTypeSetPushButton;
    QLabel *label_2;
    QLabel *pollingTimeSetLabel;
    QRadioButton *pollingTimeSetRadioButton;
    QRadioButton *pollingTimeSetRadioButton_2;
    QRadioButton *pollingTimeSetRadioButton_3;
    QRadioButton *pollingTimeSetRadioButton_4;
    QLineEdit *pollingTimeSetLineEdit;
    QLabel *label_3;
    QLineEdit *presetReturnTimeSetLineEdit;
    QRadioButton *presetReturnTimeSetRadioButton_3;
    QRadioButton *presetReturnTimeSetRadioButton;
    QLabel *presetReturnTimeSetLabel;
    QLabel *label_4;
    QRadioButton *presetReturnTimeSetRadioButton_2;
    QRadioButton *presetReturnTimeSetRadioButton_4;
    QLabel *label_7;
    QLabel *devTimeAdjustLabel;
    QLabel *devConfigLabel;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *timeAdjustPushButton;
    QLabel *configFileSelectionLabel;
    QLineEdit *configFileDisplayLineEdit;
    QPushButton *configFileSelectionPushButton;
    QPushButton *configFileImportPushButton;
    QLabel *label_14;
    QLabel *updateLabel;
    QPushButton *updateBeginPushButton;
    QPushButton *clientRebootPushButton;
    QLabel *updateStatusLabel;
    QLabel *label_17;
    QLabel *imageParamSetLabel;
    QLabel *cameraLabel;
    QLabel *carriageLabel;
    QComboBox *carriageSelectionComboBox;
    QComboBox *cameraSelectionComboBox;
    QLabel *brightnessLabel;
    QSlider *brightnessSlider;
    QLineEdit *brightnessLineEdit;
    QLineEdit *saturationLineEdit;
    QLabel *saturationLabel;
    QSlider *saturationSlider;
    QLineEdit *contrastLineEdit;
    QLabel *contrastLabel;
    QSlider *contrastSlider;
    QPushButton *imageParamSetPushButton;
    QLabel *sysTimeAdjustLabel;
    QTextEdit *updateStatueTextEdit;
    QPushButton *localSetPushButton;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *timeSetPushButton;
    QLineEdit *timeSetLineEdit;
    QRadioButton *setManalTimeRadioButton;
    QRadioButton *setSysTimeRadioButton;

    void setupUi(QWidget *devUpdateWidget)
    {
        if (devUpdateWidget->objectName().isEmpty())
            devUpdateWidget->setObjectName(QString::fromUtf8("devUpdateWidget"));
        devUpdateWidget->resize(1024, 665);
        label = new QLabel(devUpdateWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 771, 55));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(" #label { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label * { \n"
"     background-color:; \n"
" }"));
        trainTypeSetComboBox = new QComboBox(devUpdateWidget);
        trainTypeSetComboBox->setObjectName(QString::fromUtf8("trainTypeSetComboBox"));
        trainTypeSetComboBox->setGeometry(QRect(210, 23, 131, 27));
        trainTypeSetComboBox->setFont(font);
        alarmPushButton = new QPushButton(devUpdateWidget);
        alarmPushButton->setObjectName(QString::fromUtf8("alarmPushButton"));
        alarmPushButton->setGeometry(QRect(770, 20, 111, 35));
        alarmPushButton->setFont(font);
        alarmPushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{background-color: rgb(255, 255, 255);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:hover{background-color: rgb(246, 246, 246);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:pressed{background-color: rgb(86, 164, 246);color: rgb(255, 255, 255);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}\n"
"\n"
"QPushButton:checked\n"
"{background-color: rgb(255, 0, 0);color: rgb(86, 164, 246);border-color: rgb(86, 164, 246);border-width: 1px;border-style: solid;}"));
        alarmPushButton->setCheckable(true);
        permissonManagePushButton = new QPushButton(devUpdateWidget);
        permissonManagePushButton->setObjectName(QString::fromUtf8("permissonManagePushButton"));
        permissonManagePushButton->setGeometry(QRect(650, 20, 111, 35));
        permissonManagePushButton->setFont(font);
        permissonManagePushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"\n"
""));
        trainTypeSetPushButton = new QPushButton(devUpdateWidget);
        trainTypeSetPushButton->setObjectName(QString::fromUtf8("trainTypeSetPushButton"));
        trainTypeSetPushButton->setGeometry(QRect(350, 20, 101, 35));
        trainTypeSetPushButton->setFont(font);
        trainTypeSetPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_2 = new QLabel(devUpdateWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 71, 771, 55));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(" #label_2 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_2 * { \n"
"     background-color:; \n"
" }"));
        pollingTimeSetLabel = new QLabel(devUpdateWidget);
        pollingTimeSetLabel->setObjectName(QString::fromUtf8("pollingTimeSetLabel"));
        pollingTimeSetLabel->setGeometry(QRect(130, 90, 211, 21));
        pollingTimeSetLabel->setFont(font);
        pollingTimeSetLabel->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton"));
        pollingTimeSetRadioButton->setGeometry(QRect(370, 90, 61, 22));
        pollingTimeSetRadioButton->setFont(font);
        pollingTimeSetRadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_2 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_2->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_2"));
        pollingTimeSetRadioButton_2->setGeometry(QRect(450, 90, 61, 22));
        pollingTimeSetRadioButton_2->setFont(font);
        pollingTimeSetRadioButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_3 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_3->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_3"));
        pollingTimeSetRadioButton_3->setGeometry(QRect(540, 90, 61, 22));
        pollingTimeSetRadioButton_3->setFont(font);
        pollingTimeSetRadioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_3->setChecked(false);
        pollingTimeSetRadioButton_4 = new QRadioButton(devUpdateWidget);
        pollingTimeSetRadioButton_4->setObjectName(QString::fromUtf8("pollingTimeSetRadioButton_4"));
        pollingTimeSetRadioButton_4->setGeometry(QRect(620, 90, 81, 22));
        pollingTimeSetRadioButton_4->setFont(font);
        pollingTimeSetRadioButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pollingTimeSetRadioButton_4->setChecked(false);
        pollingTimeSetLineEdit = new QLineEdit(devUpdateWidget);
        pollingTimeSetLineEdit->setObjectName(QString::fromUtf8("pollingTimeSetLineEdit"));
        pollingTimeSetLineEdit->setGeometry(QRect(700, 87, 101, 27));
        pollingTimeSetLineEdit->setFont(font);
        pollingTimeSetLineEdit->setReadOnly(false);
        label_3 = new QLabel(devUpdateWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 133, 771, 55));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8(" #label_3 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_3 * { \n"
"     background-color:; \n"
" }"));
        presetReturnTimeSetLineEdit = new QLineEdit(devUpdateWidget);
        presetReturnTimeSetLineEdit->setObjectName(QString::fromUtf8("presetReturnTimeSetLineEdit"));
        presetReturnTimeSetLineEdit->setGeometry(QRect(700, 147, 101, 27));
        presetReturnTimeSetLineEdit->setFont(font);
        presetReturnTimeSetLineEdit->setReadOnly(false);
        presetReturnTimeSetRadioButton_3 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_3->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_3"));
        presetReturnTimeSetRadioButton_3->setGeometry(QRect(540, 150, 81, 22));
        presetReturnTimeSetRadioButton_3->setFont(font);
        presetReturnTimeSetRadioButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton_3->setChecked(false);
        presetReturnTimeSetRadioButton = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton"));
        presetReturnTimeSetRadioButton->setGeometry(QRect(370, 150, 71, 22));
        presetReturnTimeSetRadioButton->setFont(font);
        presetReturnTimeSetRadioButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetLabel = new QLabel(devUpdateWidget);
        presetReturnTimeSetLabel->setObjectName(QString::fromUtf8("presetReturnTimeSetLabel"));
        presetReturnTimeSetLabel->setGeometry(QRect(130, 150, 211, 21));
        presetReturnTimeSetLabel->setFont(font);
        presetReturnTimeSetLabel->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(devUpdateWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 90, 31, 17));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton_2 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_2->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_2"));
        presetReturnTimeSetRadioButton_2->setGeometry(QRect(450, 150, 81, 22));
        presetReturnTimeSetRadioButton_2->setFont(font);
        presetReturnTimeSetRadioButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        presetReturnTimeSetRadioButton_4 = new QRadioButton(devUpdateWidget);
        presetReturnTimeSetRadioButton_4->setObjectName(QString::fromUtf8("presetReturnTimeSetRadioButton_4"));
        presetReturnTimeSetRadioButton_4->setGeometry(QRect(620, 150, 81, 22));
        presetReturnTimeSetRadioButton_4->setFont(font);
        presetReturnTimeSetRadioButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(devUpdateWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(810, 150, 31, 17));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        devTimeAdjustLabel = new QLabel(devUpdateWidget);
        devTimeAdjustLabel->setObjectName(QString::fromUtf8("devTimeAdjustLabel"));
        devTimeAdjustLabel->setGeometry(QRect(120, 199, 361, 31));
        devTimeAdjustLabel->setFont(font);
        devTimeAdjustLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(33, 131, 229);"));
        devConfigLabel = new QLabel(devUpdateWidget);
        devConfigLabel->setObjectName(QString::fromUtf8("devConfigLabel"));
        devConfigLabel->setGeometry(QRect(530, 199, 361, 31));
        devConfigLabel->setFont(font);
        devConfigLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(33, 131, 229);"));
        label_10 = new QLabel(devUpdateWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 227, 361, 181));
        label_10->setStyleSheet(QString::fromUtf8(" #label_10 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_10 * { \n"
"     background-color:; \n"
" }"));
        label_11 = new QLabel(devUpdateWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(530, 227, 361, 181));
        label_11->setStyleSheet(QString::fromUtf8(" #label_11 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_11 * { \n"
"     background-color:; \n"
" }"));
        timeAdjustPushButton = new QPushButton(devUpdateWidget);
        timeAdjustPushButton->setObjectName(QString::fromUtf8("timeAdjustPushButton"));
        timeAdjustPushButton->setGeometry(QRect(260, 360, 81, 27));
        timeAdjustPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        configFileSelectionLabel = new QLabel(devUpdateWidget);
        configFileSelectionLabel->setObjectName(QString::fromUtf8("configFileSelectionLabel"));
        configFileSelectionLabel->setGeometry(QRect(540, 280, 101, 17));
        configFileSelectionLabel->setFont(font);
        configFileSelectionLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        configFileDisplayLineEdit = new QLineEdit(devUpdateWidget);
        configFileDisplayLineEdit->setObjectName(QString::fromUtf8("configFileDisplayLineEdit"));
        configFileDisplayLineEdit->setGeometry(QRect(540, 300, 251, 27));
        configFileDisplayLineEdit->setFont(font);
        configFileSelectionPushButton = new QPushButton(devUpdateWidget);
        configFileSelectionPushButton->setObjectName(QString::fromUtf8("configFileSelectionPushButton"));
        configFileSelectionPushButton->setGeometry(QRect(800, 300, 81, 27));
        configFileSelectionPushButton->setFont(font);
        configFileSelectionPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        configFileImportPushButton = new QPushButton(devUpdateWidget);
        configFileImportPushButton->setObjectName(QString::fromUtf8("configFileImportPushButton"));
        configFileImportPushButton->setGeometry(QRect(800, 340, 81, 27));
        configFileImportPushButton->setFont(font);
        configFileImportPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_14 = new QLabel(devUpdateWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(120, 447, 361, 211));
        label_14->setStyleSheet(QString::fromUtf8(" #label_14 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_14 * { \n"
"     background-color:; \n"
" }"));
        updateLabel = new QLabel(devUpdateWidget);
        updateLabel->setObjectName(QString::fromUtf8("updateLabel"));
        updateLabel->setGeometry(QRect(120, 417, 361, 31));
        updateLabel->setFont(font);
        updateLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(33, 131, 229);"));
        updateBeginPushButton = new QPushButton(devUpdateWidget);
        updateBeginPushButton->setObjectName(QString::fromUtf8("updateBeginPushButton"));
        updateBeginPushButton->setGeometry(QRect(260, 620, 81, 27));
        updateBeginPushButton->setFont(font);
        updateBeginPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        clientRebootPushButton = new QPushButton(devUpdateWidget);
        clientRebootPushButton->setObjectName(QString::fromUtf8("clientRebootPushButton"));
        clientRebootPushButton->setGeometry(QRect(370, 620, 81, 27));
        clientRebootPushButton->setFont(font);
        clientRebootPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        updateStatusLabel = new QLabel(devUpdateWidget);
        updateStatusLabel->setObjectName(QString::fromUtf8("updateStatusLabel"));
        updateStatusLabel->setGeometry(QRect(270, 459, 71, 17));
        updateStatusLabel->setFont(font);
        updateStatusLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_17 = new QLabel(devUpdateWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(530, 447, 361, 211));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        imageParamSetLabel = new QLabel(devUpdateWidget);
        imageParamSetLabel->setObjectName(QString::fromUtf8("imageParamSetLabel"));
        imageParamSetLabel->setGeometry(QRect(530, 417, 361, 31));
        imageParamSetLabel->setFont(font);
        imageParamSetLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(33, 131, 229);"));
        cameraLabel = new QLabel(devUpdateWidget);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));
        cameraLabel->setGeometry(QRect(706, 480, 61, 17));
        cameraLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        carriageLabel = new QLabel(devUpdateWidget);
        carriageLabel->setObjectName(QString::fromUtf8("carriageLabel"));
        carriageLabel->setGeometry(QRect(550, 480, 51, 17));
        carriageLabel->setFont(font);
        carriageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        carriageSelectionComboBox = new QComboBox(devUpdateWidget);
        carriageSelectionComboBox->setObjectName(QString::fromUtf8("carriageSelectionComboBox"));
        carriageSelectionComboBox->setEnabled(true);
        carriageSelectionComboBox->setGeometry(QRect(600, 476, 85, 24));
        carriageSelectionComboBox->setFont(font);
        carriageSelectionComboBox->setMinimumContentsLength(0);
        cameraSelectionComboBox = new QComboBox(devUpdateWidget);
        cameraSelectionComboBox->setObjectName(QString::fromUtf8("cameraSelectionComboBox"));
        cameraSelectionComboBox->setEnabled(true);
        cameraSelectionComboBox->setGeometry(QRect(770, 476, 101, 24));
        cameraSelectionComboBox->setFont(font);
        brightnessLabel = new QLabel(devUpdateWidget);
        brightnessLabel->setObjectName(QString::fromUtf8("brightnessLabel"));
        brightnessLabel->setGeometry(QRect(590, 515, 51, 17));
        brightnessLabel->setFont(font);
        brightnessLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        brightnessSlider = new QSlider(devUpdateWidget);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(640, 510, 131, 29));
        brightnessSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal{border: 1px solid #4A708B;background: #C0C0C0;height: 5px;border-radius: 1px;padding-left:-1px;padding-right:-1px;}\n"
"\n"
"QSlider::sub-page:horizontal{background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #B1B1B1,stop:1 #c4c4c4);background:qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #5DCCFF,stop: 1 #1874CD);border: 1px solid #4A708B;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::add-page:horizontal{background: #575757;border: 0px solid #777;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::handle:horizontal{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}\n"
"\n"
"QSlider::handle:horizontal:hover{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;"
                        "}\n"
"\n"
"QSlider::sub-page:horizontal:disabled{background: #00009C;border-color: #999;}\n"
"\n"
"QSlider::add-page:horizontal:disabled{background: #eee;border-color: #999;}\n"
"\n"
"QSlider::handle:horizontal:disabled{background: #eee;border: 1px solid #aaa;border-radius: 4px;}"));
        brightnessSlider->setMinimum(0);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setValue(50);
        brightnessSlider->setOrientation(Qt::Horizontal);
        brightnessLineEdit = new QLineEdit(devUpdateWidget);
        brightnessLineEdit->setObjectName(QString::fromUtf8("brightnessLineEdit"));
        brightnessLineEdit->setGeometry(QRect(780, 510, 41, 27));
        brightnessLineEdit->setFont(font);
        saturationLineEdit = new QLineEdit(devUpdateWidget);
        saturationLineEdit->setObjectName(QString::fromUtf8("saturationLineEdit"));
        saturationLineEdit->setGeometry(QRect(780, 540, 41, 27));
        saturationLineEdit->setFont(font);
        saturationLabel = new QLabel(devUpdateWidget);
        saturationLabel->setObjectName(QString::fromUtf8("saturationLabel"));
        saturationLabel->setGeometry(QRect(590, 545, 51, 17));
        saturationLabel->setFont(font);
        saturationLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        saturationSlider = new QSlider(devUpdateWidget);
        saturationSlider->setObjectName(QString::fromUtf8("saturationSlider"));
        saturationSlider->setGeometry(QRect(640, 540, 131, 29));
        saturationSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal{border: 1px solid #4A708B;background: #C0C0C0;height: 5px;border-radius: 1px;padding-left:-1px;padding-right:-1px;}\n"
"\n"
"QSlider::sub-page:horizontal{background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #B1B1B1,stop:1 #c4c4c4);background:qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #5DCCFF,stop: 1 #1874CD);border: 1px solid #4A708B;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::add-page:horizontal{background: #575757;border: 0px solid #777;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::handle:horizontal{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}\n"
"\n"
"QSlider::handle:horizontal:hover{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;"
                        "}\n"
"\n"
"QSlider::sub-page:horizontal:disabled{background: #00009C;border-color: #999;}\n"
"\n"
"QSlider::add-page:horizontal:disabled{background: #eee;border-color: #999;}\n"
"\n"
"QSlider::handle:horizontal:disabled{background: #eee;border: 1px solid #aaa;border-radius: 4px;}"));
        saturationSlider->setMaximum(100);
        saturationSlider->setValue(50);
        saturationSlider->setOrientation(Qt::Horizontal);
        contrastLineEdit = new QLineEdit(devUpdateWidget);
        contrastLineEdit->setObjectName(QString::fromUtf8("contrastLineEdit"));
        contrastLineEdit->setGeometry(QRect(780, 570, 41, 27));
        contrastLineEdit->setFont(font);
        contrastLabel = new QLabel(devUpdateWidget);
        contrastLabel->setObjectName(QString::fromUtf8("contrastLabel"));
        contrastLabel->setGeometry(QRect(590, 575, 51, 17));
        contrastLabel->setFont(font);
        contrastLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        contrastSlider = new QSlider(devUpdateWidget);
        contrastSlider->setObjectName(QString::fromUtf8("contrastSlider"));
        contrastSlider->setGeometry(QRect(640, 570, 131, 29));
        contrastSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal{border: 1px solid #4A708B;background: #C0C0C0;height: 5px;border-radius: 1px;padding-left:-1px;padding-right:-1px;}\n"
"\n"
"QSlider::sub-page:horizontal{background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #B1B1B1,stop:1 #c4c4c4);background:qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #5DCCFF,stop: 1 #1874CD);border: 1px solid #4A708B;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::add-page:horizontal{background: #575757;border: 0px solid #777;height: 10px;border-radius: 2px;}\n"
"\n"
"QSlider::handle:horizontal{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}\n"
"\n"
"QSlider::handle:horizontal:hover{background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA,stop:0.778409 rgba(255, 255, 255, 255));width: 11px;margin-top: -3px;margin-bottom: -3px;border-radius: 5px;"
                        "}\n"
"\n"
"QSlider::sub-page:horizontal:disabled{background: #00009C;border-color: #999;}\n"
"\n"
"QSlider::add-page:horizontal:disabled{background: #eee;border-color: #999;}\n"
"\n"
"QSlider::handle:horizontal:disabled{background: #eee;border: 1px solid #aaa;border-radius: 4px;}"));
        contrastSlider->setMaximum(100);
        contrastSlider->setValue(50);
        contrastSlider->setOrientation(Qt::Horizontal);
        imageParamSetPushButton = new QPushButton(devUpdateWidget);
        imageParamSetPushButton->setObjectName(QString::fromUtf8("imageParamSetPushButton"));
        imageParamSetPushButton->setGeometry(QRect(670, 610, 81, 27));
        imageParamSetPushButton->setFont(font);
        imageParamSetPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        sysTimeAdjustLabel = new QLabel(devUpdateWidget);
        sysTimeAdjustLabel->setObjectName(QString::fromUtf8("sysTimeAdjustLabel"));
        sysTimeAdjustLabel->setGeometry(QRect(240, 310, 201, 27));
        sysTimeAdjustLabel->setFont(font);
        sysTimeAdjustLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 218, 226);\n"
"color: rgb(0, 0, 0);"));
        updateStatueTextEdit = new QTextEdit(devUpdateWidget);
        updateStatueTextEdit->setObjectName(QString::fromUtf8("updateStatueTextEdit"));
        updateStatueTextEdit->setGeometry(QRect(150, 479, 302, 131));
        localSetPushButton = new QPushButton(devUpdateWidget);
        localSetPushButton->setObjectName(QString::fromUtf8("localSetPushButton"));
        localSetPushButton->setGeometry(QRect(150, 620, 81, 27));
        localSetPushButton->setFont(font);
        localSetPushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_5 = new QLabel(devUpdateWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 315, 67, 17));
        label_5->setFont(font);
        label_6 = new QLabel(devUpdateWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 260, 67, 17));
        label_6->setFont(font);
        timeSetPushButton = new QPushButton(devUpdateWidget);
        timeSetPushButton->setObjectName(QString::fromUtf8("timeSetPushButton"));
        timeSetPushButton->setGeometry(QRect(450, 259, 21, 21));
        timeSetPushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/time_set.png);"));
        timeSetLineEdit = new QLineEdit(devUpdateWidget);
        timeSetLineEdit->setObjectName(QString::fromUtf8("timeSetLineEdit"));
        timeSetLineEdit->setGeometry(QRect(240, 257, 201, 27));
        timeSetLineEdit->setFont(font);
        setManalTimeRadioButton = new QRadioButton(devUpdateWidget);
        setManalTimeRadioButton->setObjectName(QString::fromUtf8("setManalTimeRadioButton"));
        setManalTimeRadioButton->setGeometry(QRect(135, 258, 21, 22));
        setManalTimeRadioButton->setChecked(false);
        setSysTimeRadioButton = new QRadioButton(devUpdateWidget);
        setSysTimeRadioButton->setObjectName(QString::fromUtf8("setSysTimeRadioButton"));
        setSysTimeRadioButton->setGeometry(QRect(135, 312, 21, 22));
        setSysTimeRadioButton->setChecked(true);

        retranslateUi(devUpdateWidget);

        carriageSelectionComboBox->setCurrentIndex(0);
        cameraSelectionComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(devUpdateWidget);
    } // setupUi

    void retranslateUi(QWidget *devUpdateWidget)
    {
        devUpdateWidget->setWindowTitle(QApplication::translate("devUpdateWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("devUpdateWidget", "   \350\275\246\345\236\213\350\256\276\347\275\256   ", 0, QApplication::UnicodeUTF8));
        alarmPushButton->setText(QApplication::translate("devUpdateWidget", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        permissonManagePushButton->setText(QApplication::translate("devUpdateWidget", "\346\235\203\351\231\220\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        trainTypeSetPushButton->setText(QApplication::translate("devUpdateWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        pollingTimeSetLabel->setText(QApplication::translate("devUpdateWidget", "\345\217\227\347\224\265\345\274\223\347\233\221\346\216\247\350\275\256\350\257\242\345\210\207\346\215\242\346\227\266\351\227\264\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pollingTimeSetRadioButton->setText(QApplication::translate("devUpdateWidget", "10\347\247\222", 0, QApplication::UnicodeUTF8));
        pollingTimeSetRadioButton_2->setText(QApplication::translate("devUpdateWidget", "20\347\247\222", 0, QApplication::UnicodeUTF8));
        pollingTimeSetRadioButton_3->setText(QApplication::translate("devUpdateWidget", "30\347\247\222", 0, QApplication::UnicodeUTF8));
        pollingTimeSetRadioButton_4->setText(QApplication::translate("devUpdateWidget", "\350\207\252\345\256\232\344\271\211", 0, QApplication::UnicodeUTF8));
        pollingTimeSetLineEdit->setText(QApplication::translate("devUpdateWidget", "30", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        presetReturnTimeSetLineEdit->setText(QApplication::translate("devUpdateWidget", "15", 0, QApplication::UnicodeUTF8));
        presetReturnTimeSetRadioButton_3->setText(QApplication::translate("devUpdateWidget", "15\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        presetReturnTimeSetRadioButton->setText(QApplication::translate("devUpdateWidget", "5\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        presetReturnTimeSetLabel->setText(QApplication::translate("devUpdateWidget", "\350\247\206\351\242\221\347\224\273\351\235\242\350\277\224\345\233\236\351\242\204\347\275\256\347\202\271\346\227\266\351\227\264\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("devUpdateWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        presetReturnTimeSetRadioButton_2->setText(QApplication::translate("devUpdateWidget", "10\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        presetReturnTimeSetRadioButton_4->setText(QApplication::translate("devUpdateWidget", "\350\207\252\345\256\232\344\271\211", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("devUpdateWidget", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        devTimeAdjustLabel->setText(QApplication::translate("devUpdateWidget", "   \350\256\276\345\244\207\346\240\241\346\227\266", 0, QApplication::UnicodeUTF8));
        devConfigLabel->setText(QApplication::translate("devUpdateWidget", "    \350\256\276\345\244\207\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_11->setText(QString());
        timeAdjustPushButton->setText(QApplication::translate("devUpdateWidget", "\346\240\241  \346\227\266", 0, QApplication::UnicodeUTF8));
        configFileSelectionLabel->setText(QApplication::translate("devUpdateWidget", "\351\200\211\346\213\251\351\205\215\347\275\256\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        configFileSelectionPushButton->setText(QApplication::translate("devUpdateWidget", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        configFileImportPushButton->setText(QApplication::translate("devUpdateWidget", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        updateLabel->setText(QApplication::translate("devUpdateWidget", "   \347\250\213\345\272\217\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        updateBeginPushButton->setText(QApplication::translate("devUpdateWidget", "\345\274\200\345\247\213\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        clientRebootPushButton->setText(QApplication::translate("devUpdateWidget", "\351\207\215\345\220\257\345\256\242\346\210\267\347\253\257", 0, QApplication::UnicodeUTF8));
        updateStatusLabel->setText(QApplication::translate("devUpdateWidget", "\346\233\264\346\226\260\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_17->setText(QString());
        imageParamSetLabel->setText(QApplication::translate("devUpdateWidget", "   \345\233\276\345\203\217\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        cameraLabel->setText(QApplication::translate("devUpdateWidget", "   \346\221\204\345\203\217\346\234\272", 0, QApplication::UnicodeUTF8));
        carriageLabel->setText(QApplication::translate("devUpdateWidget", "\350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        carriageSelectionComboBox->clear();
        carriageSelectionComboBox->insertItems(0, QStringList()
         << QApplication::translate("devUpdateWidget", "1\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("devUpdateWidget", "8\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
        );
        cameraSelectionComboBox->clear();
        cameraSelectionComboBox->insertItems(0, QStringList()
         << QApplication::translate("devUpdateWidget", "8\345\217\267\346\221\204\345\203\217\346\234\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("devUpdateWidget", "9\345\217\267\346\221\204\345\203\217\346\234\272", 0, QApplication::UnicodeUTF8)
        );
        brightnessLabel->setText(QApplication::translate("devUpdateWidget", "\344\272\256 \345\272\246", 0, QApplication::UnicodeUTF8));
        brightnessLineEdit->setText(QApplication::translate("devUpdateWidget", "128", 0, QApplication::UnicodeUTF8));
        saturationLineEdit->setText(QApplication::translate("devUpdateWidget", "128", 0, QApplication::UnicodeUTF8));
        saturationLabel->setText(QApplication::translate("devUpdateWidget", "\351\245\261\345\222\214\345\272\246", 0, QApplication::UnicodeUTF8));
        contrastLineEdit->setText(QApplication::translate("devUpdateWidget", "128", 0, QApplication::UnicodeUTF8));
        contrastLabel->setText(QApplication::translate("devUpdateWidget", "\345\257\271\346\257\224\345\272\246", 0, QApplication::UnicodeUTF8));
        imageParamSetPushButton->setText(QApplication::translate("devUpdateWidget", "\350\256\276\347\275\256\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        sysTimeAdjustLabel->setText(QString());
        localSetPushButton->setText(QApplication::translate("devUpdateWidget", "\346\234\254\345\234\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("devUpdateWidget", "\347\263\273\347\273\237\346\240\241\346\227\266", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("devUpdateWidget", "\346\211\213\345\212\250\346\240\241\346\227\266", 0, QApplication::UnicodeUTF8));
        timeSetPushButton->setText(QString());
        setManalTimeRadioButton->setText(QString());
        setSysTimeRadioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class devUpdateWidget: public Ui_devUpdateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVUPDATEWIDGET_H
