/****************************************************************************
** Meta object code from reading C++ file 'userAdd.h'
**
** Created: Wed Mar 7 10:55:15 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userAdd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userAdd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_userAdd[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,    8,    8,    8, 0x0a,
      42,    8,    8,    8, 0x0a,
      56,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_userAdd[] = {
    "userAdd\0\0sendCloseMsg()\0closeWidgetSlot()\0"
    "confirmSlot()\0cancleSlot()\0"
};

void userAdd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        userAdd *_t = static_cast<userAdd *>(_o);
        switch (_id) {
        case 0: _t->sendCloseMsg(); break;
        case 1: _t->closeWidgetSlot(); break;
        case 2: _t->confirmSlot(); break;
        case 3: _t->cancleSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData userAdd::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject userAdd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_userAdd,
      qt_meta_data_userAdd, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &userAdd::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *userAdd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *userAdd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_userAdd))
        return static_cast<void*>(const_cast< userAdd*>(this));
    return QWidget::qt_metacast(_clname);
}

int userAdd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void userAdd::sendCloseMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
