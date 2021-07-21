/****************************************************************************
** Meta object code from reading C++ file 'devUpdateWidget.h'
**
** Created: Wed Mar 7 10:55:11 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../devUpdateWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devUpdateWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_devUpdateWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      46,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   16,   16,   16, 0x0a,
      82,   16,   16,   16, 0x0a,
     108,   16,   16,   16, 0x0a,
     131,   16,   16,   16, 0x0a,
     155,   16,   16,   16, 0x0a,
     190,   16,   16,   16, 0x0a,
     212,   16,   16,   16, 0x0a,
     232,   16,   16,   16, 0x0a,
     261,  255,   16,   16, 0x0a,
     293,  255,   16,   16, 0x0a,
     325,  255,   16,   16, 0x0a,
     355,   16,   16,   16, 0x0a,
     382,  370,   16,   16, 0x0a,
     405,  370,   16,   16, 0x0a,
     433,   16,   16,   16, 0x0a,
     449,   16,   16,   16, 0x0a,
     475,   16,   16,   16, 0x0a,
     491,   16,   16,   16, 0x0a,
     507,   16,   16,   16, 0x0a,
     525,   16,   16,   16, 0x0a,
     547,   16,   16,   16, 0x0a,
     570,   16,   16,   16, 0x0a,
     590,   16,   16,   16, 0x0a,
     617,   16,   16,   16, 0x0a,
     639,   16,   16,   16, 0x0a,
     657,   16,   16,   16, 0x0a,
     674,   16,   16,   16, 0x0a,
     726,  698,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_devUpdateWidget[] = {
    "devUpdateWidget\0\0alarmPushButoonClickSignal()\0"
    "systimeSetSignal()\0userManageSlot()\0"
    "configFileSelectionSlot()\0"
    "configFileImportSlot()\0closeUserManageWidget()\0"
    "closeLocalSetPasswdConfirmWidget()\0"
    "closeLocalSetWidget()\0timeManuelSetSlot()\0"
    "localSetPasswdOkCtrl()\0value\0"
    "setBrightnessLineEditValue(int)\0"
    "setSaturationLineEditValue(int)\0"
    "setContrastLineEditValue(int)\0"
    "setTrainType()\0iComboBoxId\0"
    "pollingTimeChange(int)\0"
    "presetReturnTimeChange(int)\0setSystemTime()\0"
    "setCameraImageParamSlot()\0devUpdateSlot()\0"
    "devRebootSlot()\0devLocalSetSlot()\0"
    "inputWidgetExitSlot()\0inputWidgetEnterSlot()\0"
    "setTimeSignalCtrl()\0alarmPushButoonClickSlot()\0"
    "alarmHappenCtrlSlot()\0alarmHappenSlot()\0"
    "alarmClearSlot()\0openTimeSetWidgetSlot()\0"
    "year,month,day,hour,min,sec\0"
    "timeSetRecvMsg(QString,QString,QString,QString,QString,QString)\0"
};

void devUpdateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        devUpdateWidget *_t = static_cast<devUpdateWidget *>(_o);
        switch (_id) {
        case 0: _t->alarmPushButoonClickSignal(); break;
        case 1: _t->systimeSetSignal(); break;
        case 2: _t->userManageSlot(); break;
        case 3: _t->configFileSelectionSlot(); break;
        case 4: _t->configFileImportSlot(); break;
        case 5: _t->closeUserManageWidget(); break;
        case 6: _t->closeLocalSetPasswdConfirmWidget(); break;
        case 7: _t->closeLocalSetWidget(); break;
        case 8: _t->timeManuelSetSlot(); break;
        case 9: _t->localSetPasswdOkCtrl(); break;
        case 10: _t->setBrightnessLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setSaturationLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setContrastLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setTrainType(); break;
        case 14: _t->pollingTimeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->presetReturnTimeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setSystemTime(); break;
        case 17: _t->setCameraImageParamSlot(); break;
        case 18: _t->devUpdateSlot(); break;
        case 19: _t->devRebootSlot(); break;
        case 20: _t->devLocalSetSlot(); break;
        case 21: _t->inputWidgetExitSlot(); break;
        case 22: _t->inputWidgetEnterSlot(); break;
        case 23: _t->setTimeSignalCtrl(); break;
        case 24: _t->alarmPushButoonClickSlot(); break;
        case 25: _t->alarmHappenCtrlSlot(); break;
        case 26: _t->alarmHappenSlot(); break;
        case 27: _t->alarmClearSlot(); break;
        case 28: _t->openTimeSetWidgetSlot(); break;
        case 29: _t->timeSetRecvMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData devUpdateWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject devUpdateWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_devUpdateWidget,
      qt_meta_data_devUpdateWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &devUpdateWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *devUpdateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *devUpdateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_devUpdateWidget))
        return static_cast<void*>(const_cast< devUpdateWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int devUpdateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void devUpdateWidget::alarmPushButoonClickSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void devUpdateWidget::systimeSetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
