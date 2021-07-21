/********************************************************************************
** Form generated from reading UI file 'localSet.ui'
**
** Created: Wed Mar 7 10:53:16 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALSET_H
#define UI_LOCALSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_localSet
{
public:
    QFrame *frame;
    QPushButton *confirmPushButton;
    QLabel *label;
    QPushButton *closePushButton;
    QTabWidget *tabWidget;
    QWidget *timeSetTab;
    QLabel *timeSetLabel;
    QPushButton *timeSetPushButton;
    QLabel *timeLabel;
    QWidget *netSetTab;
    QLabel *ipAddrLabel;
    QLabel *netMaskLabel;
    QLabel *gateWayLabel;
    QWidget *trainTypeSetTab;
    QTableWidget *trainTypeTableWidget;
    QPushButton *trainTypeEditPushButton;
    QWidget *blackScreenSetTab;
    QLabel *blackScreenSetLabel;
    QCheckBox *blackScreenSetCheckBox;
    QLabel *label_2;
    QCheckBox *shadeAlarmCheckBox;
    QWidget *pisServerSetTab;
    QPushButton *stationConfigExportPushButton;
    QLabel *pisIpAddrLabel;
    QLabel *pisPortLabel;
    QLineEdit *pisServerPortLineEdit;
    QPushButton *canclePushButton;

    void setupUi(QWidget *localSet)
    {
        if (localSet->objectName().isEmpty())
            localSet->setObjectName(QString::fromUtf8("localSet"));
        localSet->resize(525, 371);
        frame = new QFrame(localSet);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 525, 371));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(184, 180, 176);\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        confirmPushButton = new QPushButton(frame);
        confirmPushButton->setObjectName(QString::fromUtf8("confirmPushButton"));
        confirmPushButton->setGeometry(QRect(150, 330, 99, 27));
        confirmPushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1, 1, 523, 25));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 124, 224);\n"
"color: rgb(255, 255, 255);"));
        closePushButton = new QPushButton(frame);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(498, 2, 23, 20));
        closePushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/close.png);"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(48, 50, 431, 271));
        tabWidget->setFont(font);
        timeSetTab = new QWidget();
        timeSetTab->setObjectName(QString::fromUtf8("timeSetTab"));
        timeSetLabel = new QLabel(timeSetTab);
        timeSetLabel->setObjectName(QString::fromUtf8("timeSetLabel"));
        timeSetLabel->setGeometry(QRect(48, 87, 76, 17));
        timeSetLabel->setFont(font);
        timeSetPushButton = new QPushButton(timeSetTab);
        timeSetPushButton->setObjectName(QString::fromUtf8("timeSetPushButton"));
        timeSetPushButton->setGeometry(QRect(360, 80, 27, 27));
        timeSetPushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/time_set.png);\n"
"background-color: rgb(240, 240, 240);"));
        timeLabel = new QLabel(timeSetTab);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(130, 80, 211, 27));
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(184, 180, 176);\n"
"	border-width: 1px;\n"
"	border-style: solid;"));
        tabWidget->addTab(timeSetTab, QString());
        netSetTab = new QWidget();
        netSetTab->setObjectName(QString::fromUtf8("netSetTab"));
        ipAddrLabel = new QLabel(netSetTab);
        ipAddrLabel->setObjectName(QString::fromUtf8("ipAddrLabel"));
        ipAddrLabel->setGeometry(QRect(122, 34, 56, 17));
        ipAddrLabel->setFont(font);
        netMaskLabel = new QLabel(netSetTab);
        netMaskLabel->setObjectName(QString::fromUtf8("netMaskLabel"));
        netMaskLabel->setGeometry(QRect(104, 87, 76, 17));
        netMaskLabel->setFont(font);
        gateWayLabel = new QLabel(netSetTab);
        gateWayLabel->setObjectName(QString::fromUtf8("gateWayLabel"));
        gateWayLabel->setGeometry(QRect(104, 140, 76, 17));
        gateWayLabel->setFont(font);
        tabWidget->addTab(netSetTab, QString());
        trainTypeSetTab = new QWidget();
        trainTypeSetTab->setObjectName(QString::fromUtf8("trainTypeSetTab"));
        trainTypeTableWidget = new QTableWidget(trainTypeSetTab);
        if (trainTypeTableWidget->columnCount() < 2)
            trainTypeTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        trainTypeTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        trainTypeTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        trainTypeTableWidget->setObjectName(QString::fromUtf8("trainTypeTableWidget"));
        trainTypeTableWidget->setGeometry(QRect(55, 10, 321, 178));
        trainTypeTableWidget->verticalHeader()->setVisible(false);
        trainTypeEditPushButton = new QPushButton(trainTypeSetTab);
        trainTypeEditPushButton->setObjectName(QString::fromUtf8("trainTypeEditPushButton"));
        trainTypeEditPushButton->setGeometry(QRect(180, 200, 71, 27));
        trainTypeEditPushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border:none;border-radius:5px;background-color: rgb(94, 135, 205);"));
        tabWidget->addTab(trainTypeSetTab, QString());
        blackScreenSetTab = new QWidget();
        blackScreenSetTab->setObjectName(QString::fromUtf8("blackScreenSetTab"));
        blackScreenSetLabel = new QLabel(blackScreenSetTab);
        blackScreenSetLabel->setObjectName(QString::fromUtf8("blackScreenSetLabel"));
        blackScreenSetLabel->setGeometry(QRect(130, 80, 81, 17));
        blackScreenSetLabel->setFont(font);
        blackScreenSetCheckBox = new QCheckBox(blackScreenSetTab);
        blackScreenSetCheckBox->setObjectName(QString::fromUtf8("blackScreenSetCheckBox"));
        blackScreenSetCheckBox->setGeometry(QRect(230, 78, 97, 22));
        blackScreenSetCheckBox->setFont(font);
        label_2 = new QLabel(blackScreenSetTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 111, 17));
        label_2->setFont(font);
        shadeAlarmCheckBox = new QCheckBox(blackScreenSetTab);
        shadeAlarmCheckBox->setObjectName(QString::fromUtf8("shadeAlarmCheckBox"));
        shadeAlarmCheckBox->setGeometry(QRect(230, 118, 97, 22));
        shadeAlarmCheckBox->setFont(font);
        tabWidget->addTab(blackScreenSetTab, QString());
        pisServerSetTab = new QWidget();
        pisServerSetTab->setObjectName(QString::fromUtf8("pisServerSetTab"));
        stationConfigExportPushButton = new QPushButton(pisServerSetTab);
        stationConfigExportPushButton->setObjectName(QString::fromUtf8("stationConfigExportPushButton"));
        stationConfigExportPushButton->setGeometry(QRect(140, 200, 151, 27));
        stationConfigExportPushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);border:none;border-radius:5px;\n"
"background-color: rgb(94, 135, 205);"));
        pisIpAddrLabel = new QLabel(pisServerSetTab);
        pisIpAddrLabel->setObjectName(QString::fromUtf8("pisIpAddrLabel"));
        pisIpAddrLabel->setGeometry(QRect(122, 68, 56, 17));
        pisIpAddrLabel->setFont(font);
        pisPortLabel = new QLabel(pisServerSetTab);
        pisPortLabel->setObjectName(QString::fromUtf8("pisPortLabel"));
        pisPortLabel->setGeometry(QRect(120, 134, 56, 17));
        pisPortLabel->setFont(font);
        pisServerPortLineEdit = new QLineEdit(pisServerSetTab);
        pisServerPortLineEdit->setObjectName(QString::fromUtf8("pisServerPortLineEdit"));
        pisServerPortLineEdit->setGeometry(QRect(190, 130, 132, 29));
        tabWidget->addTab(pisServerSetTab, QString());
        canclePushButton = new QPushButton(frame);
        canclePushButton->setObjectName(QString::fromUtf8("canclePushButton"));
        canclePushButton->setGeometry(QRect(290, 330, 99, 27));
        canclePushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));

        retranslateUi(localSet);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(localSet);
    } // setupUi

    void retranslateUi(QWidget *localSet)
    {
        localSet->setWindowTitle(QApplication::translate("localSet", "Form", 0, QApplication::UnicodeUTF8));
        confirmPushButton->setText(QApplication::translate("localSet", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("localSet", " \346\234\254\345\234\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QString());
        timeSetLabel->setText(QApplication::translate("localSet", "\346\227\266\351\227\264\350\256\276\347\275\256 :", 0, QApplication::UnicodeUTF8));
        timeSetPushButton->setText(QString());
        timeLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(timeSetTab), QApplication::translate("localSet", "\346\227\266\351\227\264\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        ipAddrLabel->setText(QApplication::translate("localSet", "IP\345\234\260\345\235\200 :", 0, QApplication::UnicodeUTF8));
        netMaskLabel->setText(QApplication::translate("localSet", "\345\255\220\347\275\221\346\216\251\347\240\201 :", 0, QApplication::UnicodeUTF8));
        gateWayLabel->setText(QApplication::translate("localSet", "\351\273\230\350\256\244\347\275\221\345\205\263 :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(netSetTab), QApplication::translate("localSet", "\347\275\221\347\273\234\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = trainTypeTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("localSet", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = trainTypeTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("localSet", "\350\275\246\345\236\213\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        trainTypeEditPushButton->setText(QApplication::translate("localSet", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(trainTypeSetTab), QApplication::translate("localSet", "\350\275\246\345\236\213\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        blackScreenSetLabel->setText(QApplication::translate("localSet", "\351\273\221\345\261\217\344\275\277\350\203\275 :", 0, QApplication::UnicodeUTF8));
        blackScreenSetCheckBox->setText(QApplication::translate("localSet", "\345\274\200\345\220\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("localSet", "\351\201\256\346\214\241\346\212\245\350\255\246\344\275\277\350\203\275 :", 0, QApplication::UnicodeUTF8));
        shadeAlarmCheckBox->setText(QApplication::translate("localSet", "\345\274\200\345\220\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(blackScreenSetTab), QApplication::translate("localSet", "\344\275\277\350\203\275\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        stationConfigExportPushButton->setText(QApplication::translate("localSet", "\347\253\231\344\273\243\347\240\201\351\205\215\347\275\256\346\226\207\344\273\266\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        pisIpAddrLabel->setText(QApplication::translate("localSet", "IP\345\234\260\345\235\200 :", 0, QApplication::UnicodeUTF8));
        pisPortLabel->setText(QApplication::translate("localSet", "\347\253\257\345\217\243\345\217\267 :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pisServerSetTab), QApplication::translate("localSet", "PIS\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        canclePushButton->setText(QApplication::translate("localSet", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class localSet: public Ui_localSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALSET_H
