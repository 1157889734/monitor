/****************************************************************************
** Meta object code from reading C++ file 'devManageWidget.h'
**
** Created: Wed Mar 7 10:55:10 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../devManageWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devManageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_devManageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      39,   16,   16,   16, 0x05,
      73,   68,   16,   16, 0x05,
      92,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     126,  111,   16,   16, 0x0a,
     153,   16,   16,   16, 0x0a,
     174,   16,   16,   16, 0x0a,
     203,   16,   16,   16, 0x0a,
     227,   16,   16,   16, 0x0a,
     253,   16,   16,   16, 0x0a,
     280,   16,   16,   16, 0x0a,
     302,   16,   16,   16, 0x0a,
     320,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_devManageWidget[] = {
    "devManageWidget\0\0enterKeyPressSignal()\0"
    "alarmPushButoonClickSignal()\0iDex\0"
    "serverOffLine(int)\0systimeSetSignal()\0"
    "TrainNumberStr\0trainNumberChange(QString)\0"
    "trainNumberSetSlot()\0trainNumberButtonClickSlot()\0"
    "getDevStateSignalCtrl()\0"
    "closeKeyboardWidgetSlot()\0"
    "alarmPushButoonClickSlot()\0"
    "alarmHappenCtrlSlot()\0alarmHappenSlot()\0"
    "alarmClearSlot()\0"
};

void devManageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        devManageWidget *_t = static_cast<devManageWidget *>(_o);
        switch (_id) {
        case 0: _t->enterKeyPressSignal(); break;
        case 1: _t->alarmPushButoonClickSignal(); break;
        case 2: _t->serverOffLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->systimeSetSignal(); break;
        case 4: _t->trainNumberChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->trainNumberSetSlot(); break;
        case 6: _t->trainNumberButtonClickSlot(); break;
        case 7: _t->getDevStateSignalCtrl(); break;
        case 8: _t->closeKeyboardWidgetSlot(); break;
        case 9: _t->alarmPushButoonClickSlot(); break;
        case 10: _t->alarmHappenCtrlSlot(); break;
        case 11: _t->alarmHappenSlot(); break;
        case 12: _t->alarmClearSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData devManageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject devManageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_devManageWidget,
      qt_meta_data_devManageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &devManageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *devManageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *devManageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_devManageWidget))
        return static_cast<void*>(const_cast< devManageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int devManageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void devManageWidget::enterKeyPressSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void devManageWidget::alarmPushButoonClickSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void devManageWidget::serverOffLine(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void devManageWidget::systimeSetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
