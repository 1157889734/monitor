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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtoverlay
{
public:

    void setupUi(QWidget *qtoverlay)
    {
        if (qtoverlay->objectName().isEmpty())
            qtoverlay->setObjectName(QString::fromUtf8("qtoverlay"));
        qtoverlay->resize(400, 300);

        retranslateUi(qtoverlay);

        QMetaObject::connectSlotsByName(qtoverlay);
    } // setupUi

    void retranslateUi(QWidget *qtoverlay)
    {
        qtoverlay->setWindowTitle(QCoreApplication::translate("qtoverlay", "qtoverlay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtoverlay: public Ui_qtoverlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTOVERLAY_H
