/********************************************************************************
** Form generated from reading UI file 'inteAnalyWidget.ui'
**
** Created: Wed Mar 7 10:53:15 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTEANALYWIDGET_H
#define UI_INTEANALYWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inteAnalyWidget
{
public:
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit_2;
    QComboBox *comboBox;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_7;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_12;
    QPushButton *pushButton_8;
    QLabel *label_4;
    QLabel *label_10;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLabel *label_14;
    QComboBox *comboBox_5;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;
    QPushButton *startTimeSetPushButton;
    QPushButton *startTimeSetPushButton_2;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QTableWidget *recordFileTableWidget;

    void setupUi(QWidget *inteAnalyWidget)
    {
        if (inteAnalyWidget->objectName().isEmpty())
            inteAnalyWidget->setObjectName(QString::fromUtf8("inteAnalyWidget"));
        inteAnalyWidget->resize(1024, 665);
        label_2 = new QLabel(inteAnalyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 5, 305, 46));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(" #label_2 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_2 * { \n"
"     background-color:; \n"
" }"));
        dateTimeEdit_2 = new QDateTimeEdit(inteAnalyWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(90, 90, 194, 27));
        dateTimeEdit_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        dateTimeEdit_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dateTimeEdit_2->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        comboBox = new QComboBox(inteAnalyWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 170, 91, 27));
        label_11 = new QLabel(inteAnalyWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(6, 623, 305, 38));
        QFont font1;
        font1.setPointSize(15);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8(" #label_11 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_11 * { \n"
"     background-color:; \n"
" }"));
        label_3 = new QLabel(inteAnalyWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(6, 44, 305, 41));
        QFont font2;
        font2.setPointSize(12);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8(" #label_3 { \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_3 * { \n"
"     background-color:; \n"
" }"));
        label_7 = new QLabel(inteAnalyWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(158, 167, 153, 41));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8(" #label_7 { \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_7 * { \n"
"     background-color:; \n"
" }"));
        label_9 = new QLabel(inteAnalyWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(6, 249, 305, 31));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8(" #label_9 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_9 * { \n"
"     background-color:; \n"
" }"));
        label_13 = new QLabel(inteAnalyWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 621, 702, 40));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        pushButton_11 = new QPushButton(inteAnalyWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(610, 620, 41, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/prev_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(41, 41));
        pushButton_11->setFlat(true);
        pushButton_7 = new QPushButton(inteAnalyWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(110, 210, 91, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_6 = new QLabel(inteAnalyWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(6, 167, 156, 41));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8(" #label_6 { \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_6 * { \n"
"     background-color:; \n"
" }"));
        label_8 = new QLabel(inteAnalyWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(6, 208, 305, 41));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8(" #label_8 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_8 * { \n"
"     background-color:; \n"
" }"));
        label_5 = new QLabel(inteAnalyWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(6, 136, 305, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(" #label_5 { \n"
"	color: rgb(33, 131, 229);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_5 * { \n"
"     background-color:; \n"
" }"));
        label_12 = new QLabel(inteAnalyWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(320, 7, 700, 606));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/playerbk.png);"));
        pushButton_8 = new QPushButton(inteAnalyWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(30, 625, 101, 31));
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_4 = new QLabel(inteAnalyWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(6, 85, 305, 41));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8(" #label_4 { \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_4 * { \n"
"     background-color:; \n"
" }"));
        label_10 = new QLabel(inteAnalyWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(6, 294, 305, 331));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8(" #label_10 { \n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_10 * { \n"
"     background-color:; \n"
" }"));
        comboBox_3 = new QComboBox(inteAnalyWidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(60, 172, 91, 27));
        comboBox_3->setFont(font2);
        comboBox_4 = new QComboBox(inteAnalyWidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(230, 172, 71, 27));
        comboBox_4->setFont(font2);
        label_14 = new QLabel(inteAnalyWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(6, 200, 155, 41));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8(" #label_14 { \n"
"	color: rgb(0, 0, 0);\n"
"    background-color: rgb(255, 255, 255);\n"
"  } \n"
" #label_14 * { \n"
"     background-color:; \n"
" }"));
        comboBox_5 = new QComboBox(inteAnalyWidget);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(72, 207, 91, 27));
        comboBox_5->setFont(font2);
        pushButton_15 = new QPushButton(inteAnalyWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(110, 240, 91, 31));
        pushButton_15->setFont(font2);
        pushButton_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        pushButton_16 = new QPushButton(inteAnalyWidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(180, 625, 101, 31));
        pushButton_16->setFont(font2);
        pushButton_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        pushButton_17 = new QPushButton(inteAnalyWidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(680, 620, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/next_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon1);
        pushButton_17->setIconSize(QSize(41, 41));
        pushButton_17->setFlat(true);
        pushButton_32 = new QPushButton(inteAnalyWidget);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setGeometry(QRect(740, 626, 81, 31));
        pushButton_32->setFont(font2);
        pushButton_32->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        pushButton_33 = new QPushButton(inteAnalyWidget);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setGeometry(QRect(510, 626, 81, 31));
        pushButton_33->setFont(font2);
        pushButton_33->setStyleSheet(QString::fromUtf8("color: rgb(33, 131, 229);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        startTimeLabel = new QLabel(inteAnalyWidget);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));
        startTimeLabel->setGeometry(QRect(80, 50, 181, 27));
        startTimeLabel->setFont(font2);
        startTimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        endTimeLabel = new QLabel(inteAnalyWidget);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));
        endTimeLabel->setGeometry(QRect(80, 90, 181, 27));
        endTimeLabel->setFont(font2);
        endTimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        startTimeSetPushButton = new QPushButton(inteAnalyWidget);
        startTimeSetPushButton->setObjectName(QString::fromUtf8("startTimeSetPushButton"));
        startTimeSetPushButton->setGeometry(QRect(275, 52, 21, 21));
        startTimeSetPushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/time_set.png);"));
        startTimeSetPushButton_2 = new QPushButton(inteAnalyWidget);
        startTimeSetPushButton_2->setObjectName(QString::fromUtf8("startTimeSetPushButton_2"));
        startTimeSetPushButton_2->setGeometry(QRect(275, 92, 21, 21));
        startTimeSetPushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/res/time_set.png);"));
        line_4 = new QFrame(inteAnalyWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(350, 670, 311, 2));
        line_4->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(inteAnalyWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(6, 294, 305, 2));
        line_5->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(inteAnalyWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(6, 167, 305, 2));
        line_6->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(inteAnalyWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(6, 43, 305, 2));
        line_7->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(33, 131, 229); \n"
"background-color: rgb(33, 131, 229); "));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        recordFileTableWidget = new QTableWidget(inteAnalyWidget);
        if (recordFileTableWidget->columnCount() < 3)
            recordFileTableWidget->setColumnCount(3);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font3);
        __qtablewidgetitem->setBackground(QColor(220, 220, 220));
        recordFileTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font3);
        __qtablewidgetitem1->setBackground(QColor(220, 220, 220));
        recordFileTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font3);
        __qtablewidgetitem2->setBackground(QColor(220, 220, 220));
        recordFileTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        recordFileTableWidget->setObjectName(QString::fromUtf8("recordFileTableWidget"));
        recordFileTableWidget->setGeometry(QRect(6, 296, 305, 301));
        recordFileTableWidget->setFont(font2);
        recordFileTableWidget->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"background-color: rgb(255, 255, 255);"));
        recordFileTableWidget->setShowGrid(false);
        recordFileTableWidget->setColumnCount(3);
        recordFileTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        recordFileTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        recordFileTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        recordFileTableWidget->horizontalHeader()->setStretchLastSection(true);
        recordFileTableWidget->verticalHeader()->setVisible(false);

        retranslateUi(inteAnalyWidget);

        QMetaObject::connectSlotsByName(inteAnalyWidget);
    } // setupUi

    void retranslateUi(QWidget *inteAnalyWidget)
    {
        inteAnalyWidget->setWindowTitle(QApplication::translate("inteAnalyWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("inteAnalyWidget", " \346\243\200\347\264\242\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("inteAnalyWidget", "4\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inteAnalyWidget", "5\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QString());
        label_3->setText(QApplication::translate("inteAnalyWidget", " \350\265\267\345\247\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("inteAnalyWidget", " \346\225\205\351\232\234\347\255\211\347\272\247", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        label_13->setText(QString());
        pushButton_11->setText(QString());
        pushButton_7->setText(QApplication::translate("inteAnalyWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("inteAnalyWidget", " \350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_5->setText(QApplication::translate("inteAnalyWidget", " \344\275\215\347\275\256\345\217\212\346\225\205\351\232\234\347\261\273\345\236\213\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        pushButton_8->setText(QApplication::translate("inteAnalyWidget", "\346\225\205\351\232\234\345\233\276\347\211\207\344\270\213\350\275\275", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("inteAnalyWidget", " \347\273\223\346\235\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("inteAnalyWidget", "4\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inteAnalyWidget", "5\345\217\267\350\275\246\345\216\242", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("inteAnalyWidget", "\351\242\204\350\255\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inteAnalyWidget", "\345\221\212\350\255\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inteAnalyWidget", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("inteAnalyWidget", " \346\225\205\351\232\234\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("inteAnalyWidget", "\347\201\253\350\212\261\346\224\276\347\224\265", 0, QApplication::UnicodeUTF8)
        );
        pushButton_15->setText(QApplication::translate("inteAnalyWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        pushButton_16->setText(QApplication::translate("inteAnalyWidget", "\346\225\205\351\232\234\345\217\202\346\225\260\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_17->setText(QString());
        pushButton_32->setText(QApplication::translate("inteAnalyWidget", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        pushButton_33->setText(QApplication::translate("inteAnalyWidget", "\350\247\206\351\242\221\345\205\263\350\201\224", 0, QApplication::UnicodeUTF8));
        startTimeLabel->setText(QString());
        endTimeLabel->setText(QString());
        startTimeSetPushButton->setText(QString());
        startTimeSetPushButton_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = recordFileTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("inteAnalyWidget", "\351\200\211\344\270\255", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = recordFileTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("inteAnalyWidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = recordFileTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("inteAnalyWidget", "\346\226\207\344\273\266\345\220\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class inteAnalyWidget: public Ui_inteAnalyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTEANALYWIDGET_H
