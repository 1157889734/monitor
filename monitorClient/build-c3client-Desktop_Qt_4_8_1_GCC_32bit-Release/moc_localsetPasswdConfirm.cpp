/****************************************************************************
** Meta object code from reading C++ file 'localsetPasswdConfirm.h'
**
** Created: Wed Mar 7 10:55:24 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../localsetPasswdConfirm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localsetPasswdConfirm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LocalsetPasswdConfirm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      41,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LocalsetPasswdConfirm[] = {
    "LocalsetPasswdConfirm\0\0sendCloseSignal()\0"
    "sendOkSignal()\0pushButtonClickSlot()\0"
};

void LocalsetPasswdConfirm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LocalsetPasswdConfirm *_t = static_cast<LocalsetPasswdConfirm *>(_o);
        switch (_id) {
        case 0: _t->sendCloseSignal(); break;
        case 1: _t->sendOkSignal(); break;
        case 2: _t->pushButtonClickSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LocalsetPasswdConfirm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LocalsetPasswdConfirm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LocalsetPasswdConfirm,
      qt_meta_data_LocalsetPasswdConfirm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LocalsetPasswdConfirm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LocalsetPasswdConfirm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LocalsetPasswdConfirm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocalsetPasswdConfirm))
        return static_cast<void*>(const_cast< LocalsetPasswdConfirm*>(this));
    return QWidget::qt_metacast(_clname);
}

int LocalsetPasswdConfirm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LocalsetPasswdConfirm::sendCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LocalsetPasswdConfirm::sendOkSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
