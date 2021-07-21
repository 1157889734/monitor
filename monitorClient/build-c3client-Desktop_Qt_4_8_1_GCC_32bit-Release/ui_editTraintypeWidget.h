/********************************************************************************
** Form generated from reading UI file 'editTraintypeWidget.ui'
**
** Created: Wed Mar 7 10:53:16 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTRAINTYPEWIDGET_H
#define UI_EDITTRAINTYPEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editTraintypeWidget
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *closePushButton;
    QLabel *trainTypeNameLabel;
    QLineEdit *trainTypeNameLineEdit;
    QRadioButton *groupSetRadioButton;
    QRadioButton *groupSetRadioButton_2;
    QLabel *groupSetLabel;
    QLabel *serverNumLabel;
    QComboBox *serverNumComboBox;
    QGroupBox *firstServerInfoGroupBox;
    QLabel *firstServerPvmsNumLabel;
    QLabel *firstServerPvmsCarNoLabel;
    QLabel *firstServerCarNoLabel;
    QComboBox *firstServerPvmsNumComboBox;
    QComboBox *firstServerPvmsCarNoComboBox;
    QComboBox *firstServerCarNoComboBox;
    QGroupBox *secondServerInfoGroupBox;
    QLabel *secondServerPvmsNumLabel;
    QLabel *secondServerPvmsCarNoLabel;
    QLabel *secondServerCarNoLabel;
    QComboBox *secondServerPvmsNumComboBox;
    QComboBox *secondServerPvmsCarNoComboBox;
    QComboBox *secondServerCarNoComboBox;
    QPushButton *confirmPushButton;
    QPushButton *canclePushButton;
    QGroupBox *thirdServerInfoGroupBox;
    QLabel *thirdServerPvmsNumLabel;
    QLabel *thirdServerPvmsCarNoLabel;
    QLabel *thirdServerCarNoLabel;
    QComboBox *thirdServerPvmsNumComboBox;
    QComboBox *thirdServerPvmsCarNoComboBox;
    QComboBox *thirdServerCarNoComboBox;
    QGroupBox *fourthServerInfoGroupBox;
    QLabel *fourthServerPvmsNumLabel;
    QLabel *fourthServerPvmsCarNoLabel;
    QLabel *fourthServerCarNoLabel;
    QComboBox *fourthServerPvmsNumComboBox;
    QComboBox *fourthServerPvmsCarNoComboBox;
    QComboBox *fourthServerCarNoComboBox;
    QLabel *trainTypeNameWarnLabel;

    void setupUi(QWidget *editTraintypeWidget)
    {
        if (editTraintypeWidget->objectName().isEmpty())
            editTraintypeWidget->setObjectName(QString::fromUtf8("editTraintypeWidget"));
        editTraintypeWidget->resize(661, 561);
        frame = new QFrame(editTraintypeWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 661, 561));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color: rgb(240, 240, 240);\n"
"border-color: rgb(184, 180, 176);\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 661, 25));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 124, 224);\n"
"color: rgb(255, 255, 255);"));
        closePushButton = new QPushButton(frame);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(630, 3, 23, 20));
        closePushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/close.png);"));
        trainTypeNameLabel = new QLabel(frame);
        trainTypeNameLabel->setObjectName(QString::fromUtf8("trainTypeNameLabel"));
        trainTypeNameLabel->setGeometry(QRect(110, 32, 71, 21));
        trainTypeNameLabel->setFont(font);
        trainTypeNameLineEdit = new QLineEdit(frame);
        trainTypeNameLineEdit->setObjectName(QString::fromUtf8("trainTypeNameLineEdit"));
        trainTypeNameLineEdit->setEnabled(true);
        trainTypeNameLineEdit->setGeometry(QRect(210, 30, 211, 27));
        trainTypeNameLineEdit->setFont(font);
        trainTypeNameLineEdit->setStyleSheet(QString::fromUtf8(""));
        trainTypeNameLineEdit->setReadOnly(false);
        groupSetRadioButton = new QRadioButton(frame);
        groupSetRadioButton->setObjectName(QString::fromUtf8("groupSetRadioButton"));
        groupSetRadioButton->setEnabled(true);
        groupSetRadioButton->setGeometry(QRect(220, 70, 71, 22));
        groupSetRadioButton->setFont(font);
        groupSetRadioButton->setStyleSheet(QString::fromUtf8(""));
        groupSetRadioButton->setText(QString::fromUtf8("8\347\274\226\347\273\204"));
        groupSetRadioButton->setCheckable(true);
        groupSetRadioButton->setChecked(true);
        groupSetRadioButton_2 = new QRadioButton(frame);
        groupSetRadioButton_2->setObjectName(QString::fromUtf8("groupSetRadioButton_2"));
        groupSetRadioButton_2->setEnabled(true);
        groupSetRadioButton_2->setGeometry(QRect(310, 70, 81, 22));
        groupSetRadioButton_2->setFont(font);
        groupSetRadioButton_2->setCheckable(true);
        groupSetRadioButton_2->setChecked(false);
        groupSetRadioButton_2->setAutoExclusive(true);
        groupSetLabel = new QLabel(frame);
        groupSetLabel->setObjectName(QString::fromUtf8("groupSetLabel"));
        groupSetLabel->setGeometry(QRect(110, 70, 81, 21));
        groupSetLabel->setFont(font);
        serverNumLabel = new QLabel(frame);
        serverNumLabel->setObjectName(QString::fromUtf8("serverNumLabel"));
        serverNumLabel->setGeometry(QRect(110, 110, 121, 21));
        serverNumLabel->setFont(font);
        serverNumComboBox = new QComboBox(frame);
        serverNumComboBox->setObjectName(QString::fromUtf8("serverNumComboBox"));
        serverNumComboBox->setGeometry(QRect(260, 108, 131, 27));
        serverNumComboBox->setFont(font);
        firstServerInfoGroupBox = new QGroupBox(frame);
        firstServerInfoGroupBox->setObjectName(QString::fromUtf8("firstServerInfoGroupBox"));
        firstServerInfoGroupBox->setGeometry(QRect(10, 150, 311, 171));
        firstServerInfoGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(184, 180, 176);\n"
"margin-top:0.5ex;\n"
"}\n"
"QGroupBox::title{\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top left;\n"
"left:10px;\n"
"margin-left:0px;\n"
"padding:0.1px\n"
"}"));
        firstServerPvmsNumLabel = new QLabel(firstServerInfoGroupBox);
        firstServerPvmsNumLabel->setObjectName(QString::fromUtf8("firstServerPvmsNumLabel"));
        firstServerPvmsNumLabel->setGeometry(QRect(28, 82, 101, 21));
        firstServerPvmsNumLabel->setFont(font);
        firstServerPvmsCarNoLabel = new QLabel(firstServerInfoGroupBox);
        firstServerPvmsCarNoLabel->setObjectName(QString::fromUtf8("firstServerPvmsCarNoLabel"));
        firstServerPvmsCarNoLabel->setGeometry(QRect(28, 122, 161, 21));
        firstServerPvmsCarNoLabel->setFont(font);
        firstServerCarNoLabel = new QLabel(firstServerInfoGroupBox);
        firstServerCarNoLabel->setObjectName(QString::fromUtf8("firstServerCarNoLabel"));
        firstServerCarNoLabel->setGeometry(QRect(28, 42, 101, 21));
        firstServerCarNoLabel->setFont(font);
        firstServerPvmsNumComboBox = new QComboBox(firstServerInfoGroupBox);
        firstServerPvmsNumComboBox->setObjectName(QString::fromUtf8("firstServerPvmsNumComboBox"));
        firstServerPvmsNumComboBox->setGeometry(QRect(150, 80, 131, 27));
        firstServerPvmsNumComboBox->setFont(font);
        firstServerPvmsCarNoComboBox = new QComboBox(firstServerInfoGroupBox);
        firstServerPvmsCarNoComboBox->setObjectName(QString::fromUtf8("firstServerPvmsCarNoComboBox"));
        firstServerPvmsCarNoComboBox->setGeometry(QRect(190, 120, 91, 27));
        firstServerPvmsCarNoComboBox->setFont(font);
        firstServerCarNoComboBox = new QComboBox(firstServerInfoGroupBox);
        firstServerCarNoComboBox->setObjectName(QString::fromUtf8("firstServerCarNoComboBox"));
        firstServerCarNoComboBox->setGeometry(QRect(150, 40, 131, 27));
        firstServerCarNoComboBox->setFont(font);
        secondServerInfoGroupBox = new QGroupBox(frame);
        secondServerInfoGroupBox->setObjectName(QString::fromUtf8("secondServerInfoGroupBox"));
        secondServerInfoGroupBox->setEnabled(false);
        secondServerInfoGroupBox->setGeometry(QRect(340, 150, 311, 171));
        secondServerInfoGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(184, 180, 176);\n"
"margin-top:0.5ex;\n"
"}\n"
"QGroupBox::title{\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top left;\n"
"left:10px;\n"
"margin-left:0px;\n"
"padding:0.1px\n"
"}"));
        secondServerPvmsNumLabel = new QLabel(secondServerInfoGroupBox);
        secondServerPvmsNumLabel->setObjectName(QString::fromUtf8("secondServerPvmsNumLabel"));
        secondServerPvmsNumLabel->setGeometry(QRect(28, 82, 101, 21));
        secondServerPvmsNumLabel->setFont(font);
        secondServerPvmsCarNoLabel = new QLabel(secondServerInfoGroupBox);
        secondServerPvmsCarNoLabel->setObjectName(QString::fromUtf8("secondServerPvmsCarNoLabel"));
        secondServerPvmsCarNoLabel->setGeometry(QRect(28, 122, 161, 21));
        secondServerPvmsCarNoLabel->setFont(font);
        secondServerCarNoLabel = new QLabel(secondServerInfoGroupBox);
        secondServerCarNoLabel->setObjectName(QString::fromUtf8("secondServerCarNoLabel"));
        secondServerCarNoLabel->setGeometry(QRect(28, 42, 101, 21));
        secondServerCarNoLabel->setFont(font);
        secondServerPvmsNumComboBox = new QComboBox(secondServerInfoGroupBox);
        secondServerPvmsNumComboBox->setObjectName(QString::fromUtf8("secondServerPvmsNumComboBox"));
        secondServerPvmsNumComboBox->setGeometry(QRect(150, 80, 131, 27));
        secondServerPvmsNumComboBox->setFont(font);
        secondServerPvmsCarNoComboBox = new QComboBox(secondServerInfoGroupBox);
        secondServerPvmsCarNoComboBox->setObjectName(QString::fromUtf8("secondServerPvmsCarNoComboBox"));
        secondServerPvmsCarNoComboBox->setGeometry(QRect(190, 120, 91, 27));
        secondServerPvmsCarNoComboBox->setFont(font);
        secondServerCarNoComboBox = new QComboBox(secondServerInfoGroupBox);
        secondServerCarNoComboBox->setObjectName(QString::fromUtf8("secondServerCarNoComboBox"));
        secondServerCarNoComboBox->setGeometry(QRect(150, 40, 131, 27));
        secondServerCarNoComboBox->setFont(font);
        confirmPushButton = new QPushButton(frame);
        confirmPushButton->setObjectName(QString::fromUtf8("confirmPushButton"));
        confirmPushButton->setGeometry(QRect(200, 520, 99, 27));
        confirmPushButton->setFont(font);
        confirmPushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        canclePushButton = new QPushButton(frame);
        canclePushButton->setObjectName(QString::fromUtf8("canclePushButton"));
        canclePushButton->setGeometry(QRect(360, 520, 99, 27));
        canclePushButton->setFont(font);
        canclePushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image: url(:/res/anniubk.png);\n"
"border-color: rgb(33, 131, 229);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        thirdServerInfoGroupBox = new QGroupBox(frame);
        thirdServerInfoGroupBox->setObjectName(QString::fromUtf8("thirdServerInfoGroupBox"));
        thirdServerInfoGroupBox->setEnabled(false);
        thirdServerInfoGroupBox->setGeometry(QRect(10, 330, 311, 171));
        thirdServerInfoGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(184, 180, 176);\n"
"margin-top:0.5ex;\n"
"}\n"
"QGroupBox::title{\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top left;\n"
"left:10px;\n"
"margin-left:0px;\n"
"padding:0.1px\n"
"}"));
        thirdServerPvmsNumLabel = new QLabel(thirdServerInfoGroupBox);
        thirdServerPvmsNumLabel->setObjectName(QString::fromUtf8("thirdServerPvmsNumLabel"));
        thirdServerPvmsNumLabel->setGeometry(QRect(28, 82, 101, 21));
        thirdServerPvmsNumLabel->setFont(font);
        thirdServerPvmsCarNoLabel = new QLabel(thirdServerInfoGroupBox);
        thirdServerPvmsCarNoLabel->setObjectName(QString::fromUtf8("thirdServerPvmsCarNoLabel"));
        thirdServerPvmsCarNoLabel->setGeometry(QRect(28, 122, 161, 21));
        thirdServerPvmsCarNoLabel->setFont(font);
        thirdServerCarNoLabel = new QLabel(thirdServerInfoGroupBox);
        thirdServerCarNoLabel->setObjectName(QString::fromUtf8("thirdServerCarNoLabel"));
        thirdServerCarNoLabel->setGeometry(QRect(28, 42, 101, 21));
        thirdServerCarNoLabel->setFont(font);
        thirdServerPvmsNumComboBox = new QComboBox(thirdServerInfoGroupBox);
        thirdServerPvmsNumComboBox->setObjectName(QString::fromUtf8("thirdServerPvmsNumComboBox"));
        thirdServerPvmsNumComboBox->setGeometry(QRect(150, 80, 131, 27));
        thirdServerPvmsNumComboBox->setFont(font);
        thirdServerPvmsCarNoComboBox = new QComboBox(thirdServerInfoGroupBox);
        thirdServerPvmsCarNoComboBox->setObjectName(QString::fromUtf8("thirdServerPvmsCarNoComboBox"));
        thirdServerPvmsCarNoComboBox->setGeometry(QRect(190, 120, 91, 27));
        thirdServerPvmsCarNoComboBox->setFont(font);
        thirdServerCarNoComboBox = new QComboBox(thirdServerInfoGroupBox);
        thirdServerCarNoComboBox->setObjectName(QString::fromUtf8("thirdServerCarNoComboBox"));
        thirdServerCarNoComboBox->setGeometry(QRect(150, 40, 131, 27));
        thirdServerCarNoComboBox->setFont(font);
        fourthServerInfoGroupBox = new QGroupBox(frame);
        fourthServerInfoGroupBox->setObjectName(QString::fromUtf8("fourthServerInfoGroupBox"));
        fourthServerInfoGroupBox->setEnabled(false);
        fourthServerInfoGroupBox->setGeometry(QRect(340, 330, 311, 171));
        fourthServerInfoGroupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(184, 180, 176);\n"
"margin-top:0.5ex;\n"
"}\n"
"QGroupBox::title{\n"
"subcontrol-origin:margin;\n"
"subcontrol-position:top left;\n"
"left:10px;\n"
"margin-left:0px;\n"
"padding:0.1px\n"
"}"));
        fourthServerPvmsNumLabel = new QLabel(fourthServerInfoGroupBox);
        fourthServerPvmsNumLabel->setObjectName(QString::fromUtf8("fourthServerPvmsNumLabel"));
        fourthServerPvmsNumLabel->setGeometry(QRect(28, 82, 101, 21));
        fourthServerPvmsNumLabel->setFont(font);
        fourthServerPvmsCarNoLabel = new QLabel(fourthServerInfoGroupBox);
        fourthServerPvmsCarNoLabel->setObjectName(QString::fromUtf8("fourthServerPvmsCarNoLabel"));
        fourthServerPvmsCarNoLabel->setGeometry(QRect(28, 122, 161, 21));
        fourthServerPvmsCarNoLabel->setFont(font);
        fourthServerCarNoLabel = new QLabel(fourthServerInfoGroupBox);
        fourthServerCarNoLabel->setObjectName(QString::fromUtf8("fourthServerCarNoLabel"));
        fourthServerCarNoLabel->setGeometry(QRect(28, 42, 101, 21));
        fourthServerCarNoLabel->setFont(font);
        fourthServerPvmsNumComboBox = new QComboBox(fourthServerInfoGroupBox);
        fourthServerPvmsNumComboBox->setObjectName(QString::fromUtf8("fourthServerPvmsNumComboBox"));
        fourthServerPvmsNumComboBox->setGeometry(QRect(150, 80, 131, 27));
        fourthServerPvmsNumComboBox->setFont(font);
        fourthServerPvmsCarNoComboBox = new QComboBox(fourthServerInfoGroupBox);
        fourthServerPvmsCarNoComboBox->setObjectName(QString::fromUtf8("fourthServerPvmsCarNoComboBox"));
        fourthServerPvmsCarNoComboBox->setGeometry(QRect(190, 120, 91, 27));
        fourthServerPvmsCarNoComboBox->setFont(font);
        fourthServerCarNoComboBox = new QComboBox(fourthServerInfoGroupBox);
        fourthServerCarNoComboBox->setObjectName(QString::fromUtf8("fourthServerCarNoComboBox"));
        fourthServerCarNoComboBox->setGeometry(QRect(150, 40, 131, 27));
        fourthServerCarNoComboBox->setFont(font);
        trainTypeNameWarnLabel = new QLabel(frame);
        trainTypeNameWarnLabel->setObjectName(QString::fromUtf8("trainTypeNameWarnLabel"));
        trainTypeNameWarnLabel->setGeometry(QRect(440, 32, 131, 17));
        trainTypeNameWarnLabel->setStyleSheet(QString::fromUtf8("color: rgb(240, 10, 10);"));

        retranslateUi(editTraintypeWidget);

        QMetaObject::connectSlotsByName(editTraintypeWidget);
    } // setupUi

    void retranslateUi(QWidget *editTraintypeWidget)
    {
        editTraintypeWidget->setWindowTitle(QApplication::translate("editTraintypeWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("editTraintypeWidget", " \344\277\256\346\224\271\350\275\246\345\236\213", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QString());
        trainTypeNameLabel->setText(QApplication::translate("editTraintypeWidget", "\350\275\246\345\236\213\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        trainTypeNameLineEdit->setText(QString());
        groupSetRadioButton_2->setText(QApplication::translate("editTraintypeWidget", "16\347\274\226\347\273\204", 0, QApplication::UnicodeUTF8));
        groupSetLabel->setText(QApplication::translate("editTraintypeWidget", "\347\274\226\347\273\204\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        serverNumLabel->setText(QApplication::translate("editTraintypeWidget", "NVR\346\234\215\345\212\241\345\231\250\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        serverNumComboBox->clear();
        serverNumComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
        );
        firstServerInfoGroupBox->setTitle(QApplication::translate("editTraintypeWidget", "1\345\217\267\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        firstServerPvmsNumLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        firstServerPvmsCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\350\275\246\345\216\242\344\275\215\347\275\256\345\217\267", 0, QApplication::UnicodeUTF8));
        firstServerCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\346\234\215\345\212\241\345\231\250\350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        firstServerPvmsNumComboBox->clear();
        firstServerPvmsNumComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
        );
        firstServerPvmsCarNoComboBox->clear();
        firstServerPvmsCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        firstServerCarNoComboBox->clear();
        firstServerCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        secondServerInfoGroupBox->setTitle(QApplication::translate("editTraintypeWidget", "2\345\217\267\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        secondServerPvmsNumLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        secondServerPvmsCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\350\275\246\345\216\242\344\275\215\347\275\256\345\217\267", 0, QApplication::UnicodeUTF8));
        secondServerCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\346\234\215\345\212\241\345\231\250\350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        secondServerPvmsNumComboBox->clear();
        secondServerPvmsNumComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
        );
        secondServerPvmsCarNoComboBox->clear();
        secondServerPvmsCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        secondServerCarNoComboBox->clear();
        secondServerCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        confirmPushButton->setText(QApplication::translate("editTraintypeWidget", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        canclePushButton->setText(QApplication::translate("editTraintypeWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        thirdServerInfoGroupBox->setTitle(QApplication::translate("editTraintypeWidget", "3\345\217\267\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        thirdServerPvmsNumLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        thirdServerPvmsCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\350\275\246\345\216\242\344\275\215\347\275\256\345\217\267", 0, QApplication::UnicodeUTF8));
        thirdServerCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\346\234\215\345\212\241\345\231\250\350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        thirdServerPvmsNumComboBox->clear();
        thirdServerPvmsNumComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
        );
        thirdServerPvmsCarNoComboBox->clear();
        thirdServerPvmsCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        thirdServerCarNoComboBox->clear();
        thirdServerCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        fourthServerInfoGroupBox->setTitle(QApplication::translate("editTraintypeWidget", "4\345\217\267\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        fourthServerPvmsNumLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        fourthServerPvmsCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\345\217\227\347\224\265\345\274\223\350\275\246\345\216\242\344\275\215\347\275\256\345\217\267", 0, QApplication::UnicodeUTF8));
        fourthServerCarNoLabel->setText(QApplication::translate("editTraintypeWidget", "\346\234\215\345\212\241\345\231\250\350\275\246\345\216\242\345\217\267", 0, QApplication::UnicodeUTF8));
        fourthServerPvmsNumComboBox->clear();
        fourthServerPvmsNumComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
        );
        fourthServerPvmsCarNoComboBox->clear();
        fourthServerPvmsCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        fourthServerCarNoComboBox->clear();
        fourthServerCarNoComboBox->insertItems(0, QStringList()
         << QApplication::translate("editTraintypeWidget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("editTraintypeWidget", "8", 0, QApplication::UnicodeUTF8)
        );
        trainTypeNameWarnLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class editTraintypeWidget: public Ui_editTraintypeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTRAINTYPEWIDGET_H
