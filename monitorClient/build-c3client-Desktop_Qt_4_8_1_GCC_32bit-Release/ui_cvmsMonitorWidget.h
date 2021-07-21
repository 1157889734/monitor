/********************************************************************************
** Form generated from reading UI file 'cvmsMonitorWidget.ui'
**
** Created: Wed Mar 7 10:53:16 2018
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVMSMONITORWIDGET_H
#define UI_CVMSMONITORWIDGET_H

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

class Ui_cvmsMonitorWidget
{
public:
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *cvmsMonitorWidget)
    {
        if (cvmsMonitorWidget->objectName().isEmpty())
            cvmsMonitorWidget->setObjectName(QString::fromUtf8("cvmsMonitorWidget"));
        cvmsMonitorWidget->resize(1024, 665);
        line = new QFrame(cvmsMonitorWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 2, 2, 603));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(cvmsMonitorWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1022, 2, 2, 603));
        line_2->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(255, 255, 255); \n"
"background-color: rgb(255, 255, 255); "));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(cvmsMonitorWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 0, 1024, 2));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); "));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label = new QLabel(cvmsMonitorWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 605, 1024, 55));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 253);"));
        line_4 = new QFrame(cvmsMonitorWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 615, 1024, 2));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(cvmsMonitorWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(2, 303, 1022, 2));
        line_5->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(255, 255, 255); \n"
"background-color: rgb(255, 255, 255); "));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(cvmsMonitorWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(511, 2, 2, 603));
        line_6->setStyleSheet(QString::fromUtf8("border-top: 1px solid  rgb(255, 255, 255); \n"
"background-color: rgb(255, 255, 255); "));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(cvmsMonitorWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 624, 35, 35));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/play_down.png);"));
        pushButton_2 = new QPushButton(cvmsMonitorWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 624, 35, 35));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/res/pause_nor.png);"));
        pushButton_2->setFlat(false);
        pushButton_3 = new QPushButton(cvmsMonitorWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 624, 35, 35));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/res/next_nor.png);"));
        pushButton_4 = new QPushButton(cvmsMonitorWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 624, 35, 35));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-image: url(:/res/prev_nor.png);"));
        label_2 = new QLabel(cvmsMonitorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(3, 3, 508, 300));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_3 = new QLabel(cvmsMonitorWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(513, 3, 508, 300));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_4 = new QLabel(cvmsMonitorWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(3, 305, 508, 300));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_5 = new QLabel(cvmsMonitorWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(513, 305, 508, 300));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(cvmsMonitorWidget);

        QMetaObject::connectSlotsByName(cvmsMonitorWidget);
    } // setupUi

    void retranslateUi(QWidget *cvmsMonitorWidget)
    {
        cvmsMonitorWidget->setWindowTitle(QApplication::translate("cvmsMonitorWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cvmsMonitorWidget: public Ui_cvmsMonitorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVMSMONITORWIDGET_H
