/****************************************************************************
** Meta object code from reading C++ file 'addTraintypeWidget.h'
**
** Created: Wed Mar 7 10:55:20 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addTraintypeWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addTraintypeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addTrainTypeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   19,   19,   19, 0x0a,
      53,   19,   19,   19, 0x0a,
      67,   19,   19,   19, 0x0a,
      92,   80,   19,   19, 0x0a,
     112,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_addTrainTypeWidget[] = {
    "addTrainTypeWidget\0\0sendCloseMsg()\0"
    "closeWidgetSlot()\0confirmSlot()\0"
    "cancleSlot()\0iComboBoxId\0groupSetChange(int)\0"
    "serverNumChangeSlot()\0"
};

void addTrainTypeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        addTrainTypeWidget *_t = static_cast<addTrainTypeWidget *>(_o);
        switch (_id) {
        case 0: _t->sendCloseMsg(); break;
        case 1: _t->closeWidgetSlot(); break;
        case 2: _t->confirmSlot(); break;
        case 3: _t->cancleSlot(); break;
        case 4: _t->groupSetChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->serverNumChangeSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData addTrainTypeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject addTrainTypeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addTrainTypeWidget,
      qt_meta_data_addTrainTypeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addTrainTypeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addTrainTypeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addTrainTypeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addTrainTypeWidget))
        return static_cast<void*>(const_cast< addTrainTypeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int addTrainTypeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void addTrainTypeWidget::sendCloseMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
