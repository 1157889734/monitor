/****************************************************************************
** Meta object code from reading C++ file 'ippartlineedit.h'
**
** Created: Wed Mar 7 10:55:22 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ippartlineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ippartlineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyIpPartLineEdit[] = {

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
      18,   17,   17,   17, 0x05,
      32,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   47,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyIpPartLineEdit[] = {
    "MyIpPartLineEdit\0\0clickedLeft()\0"
    "clickedRight()\0text\0textEditSlot(QString)\0"
};

void MyIpPartLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyIpPartLineEdit *_t = static_cast<MyIpPartLineEdit *>(_o);
        switch (_id) {
        case 0: _t->clickedLeft(); break;
        case 1: _t->clickedRight(); break;
        case 2: _t->textEditSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyIpPartLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyIpPartLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_MyIpPartLineEdit,
      qt_meta_data_MyIpPartLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyIpPartLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyIpPartLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyIpPartLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyIpPartLineEdit))
        return static_cast<void*>(const_cast< MyIpPartLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int MyIpPartLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void MyIpPartLineEdit::clickedLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyIpPartLineEdit::clickedRight()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
