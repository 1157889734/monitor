/****************************************************************************
** Meta object code from reading C++ file 'iplineedit.h'
**
** Created: Wed Mar 7 10:55:21 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iplineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iplineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_iplineedit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      30,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_iplineedit[] = {
    "iplineedit\0\0showKeyboardSig()\0"
    "hideKeyboardSig()\0showKeyboardSlot()\0"
    "hideKeyboardSlot()\0"
};

void iplineedit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        iplineedit *_t = static_cast<iplineedit *>(_o);
        switch (_id) {
        case 0: _t->showKeyboardSig(); break;
        case 1: _t->hideKeyboardSig(); break;
        case 2: _t->showKeyboardSlot(); break;
        case 3: _t->hideKeyboardSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData iplineedit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject iplineedit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_iplineedit,
      qt_meta_data_iplineedit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &iplineedit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *iplineedit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *iplineedit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_iplineedit))
        return static_cast<void*>(const_cast< iplineedit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int iplineedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void iplineedit::showKeyboardSig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void iplineedit::hideKeyboardSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
