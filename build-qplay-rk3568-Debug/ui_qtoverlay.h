/********************************************************************************
** Form generated from reading UI file 'qtoverlay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTOVERLAY_H
#define UI_QTOVERLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtoverlay
{
public:
    QWidget *videoWindow;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *slider;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;

    void setupUi(QWidget *qtoverlay)
    {
        if (qtoverlay->objectName().isEmpty())
            qtoverlay->setObjectName(QString::fromUtf8("qtoverlay"));
        qtoverlay->resize(896, 534);
        videoWindow = new QWidget(qtoverlay);
        videoWindow->setObjectName(QString::fromUtf8("videoWindow"));
        videoWindow->setGeometry(QRect(50, 40, 771, 441));
        layoutWidget = new QWidget(qtoverlay);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 497, 771, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        slider = new QSlider(layoutWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider);

        pushButton_pause = new QPushButton(layoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        horizontalLayout->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(layoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));

        horizontalLayout->addWidget(pushButton_play);


        retranslateUi(qtoverlay);

        QMetaObject::connectSlotsByName(qtoverlay);
    } // setupUi

    void retranslateUi(QWidget *qtoverlay)
    {
        qtoverlay->setWindowTitle(QCoreApplication::translate("qtoverlay", "qtoverlay", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("qtoverlay", "pause", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("qtoverlay", "stop", nullptr));
        pushButton_play->setText(QCoreApplication::translate("qtoverlay", "play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtoverlay: public Ui_qtoverlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTOVERLAY_H
