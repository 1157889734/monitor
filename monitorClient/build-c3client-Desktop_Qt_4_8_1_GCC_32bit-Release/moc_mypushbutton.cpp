/****************************************************************************
** Meta object code from reading C++ file 'mypushbutton.h'
**
** Created: Wed Mar 7 10:54:58 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mypushbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypushbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mypushbutton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      29,   13,   13,   13, 0x05,
      45,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_mypushbutton[] = {
    "mypushbutton\0\0clicked_left()\0"
    "clicked_right()\0clicked_release()\0"
};

void mypushbutton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mypushbutton *_t = static_cast<mypushbutton *>(_o);
        switch (_id) {
        case 0: _t->clicked_left(); break;
        case 1: _t->clicked_right(); break;
        case 2: _t->clicked_release(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData mypushbutton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mypushbutton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_mypushbutton,
      qt_meta_data_mypushbutton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mypushbutton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mypushbutton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mypushbutton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mypushbutton))
        return static_cast<void*>(const_cast< mypushbutton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int mypushbutton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void mypushbutton::clicked_left()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void mypushbutton::clicked_right()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void mypushbutton::clicked_release()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
