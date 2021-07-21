/****************************************************************************
** Meta object code from reading C++ file 'loginWidget.h'
**
** Created: Wed Mar 7 10:55:03 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loginWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_loginWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      38,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   63,   12,   12, 0x0a,
      87,   12,   12,   12, 0x0a,
     102,   12,   12,   12, 0x0a,
     121,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_loginWidget[] = {
    "loginWidget\0\0gotoPvmsMenuPageSignal()\0"
    "gotoCvmsMenuPageSignal()\0iType\0"
    "showPageSlot(int)\0okButtonSlot()\0"
    "cancleButtonSlot()\0delTextMsgSlot()\0"
};

void loginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        loginWidget *_t = static_cast<loginWidget *>(_o);
        switch (_id) {
        case 0: _t->gotoPvmsMenuPageSignal(); break;
        case 1: _t->gotoCvmsMenuPageSignal(); break;
        case 2: _t->showPageSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->okButtonSlot(); break;
        case 4: _t->cancleButtonSlot(); break;
        case 5: _t->delTextMsgSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData loginWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject loginWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_loginWidget,
      qt_meta_data_loginWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &loginWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *loginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *loginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_loginWidget))
        return static_cast<void*>(const_cast< loginWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int loginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void loginWidget::gotoPvmsMenuPageSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void loginWidget::gotoCvmsMenuPageSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
