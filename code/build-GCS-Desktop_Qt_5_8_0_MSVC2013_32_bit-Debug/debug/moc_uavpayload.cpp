/****************************************************************************
** Meta object code from reading C++ file 'uavpayload.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/uavpayload.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uavpayload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UAVPayload_t {
    QByteArrayData data[6];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UAVPayload_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UAVPayload_t qt_meta_stringdata_UAVPayload = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UAVPayload"
QT_MOC_LITERAL(1, 11, 3), // "arm"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "disarm"
QT_MOC_LITERAL(4, 23, 7), // "armvech"
QT_MOC_LITERAL(5, 31, 10) // "disarmvech"

    },
    "UAVPayload\0arm\0\0disarm\0armvech\0"
    "disarmvech"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UAVPayload[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UAVPayload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UAVPayload *_t = static_cast<UAVPayload *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->arm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->disarm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->armvech(); break;
        case 3: _t->disarmvech(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UAVPayload::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UAVPayload::arm)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UAVPayload::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UAVPayload::disarm)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UAVPayload::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UAVPayload.data,
      qt_meta_data_UAVPayload,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UAVPayload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UAVPayload::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UAVPayload.stringdata0))
        return static_cast<void*>(const_cast< UAVPayload*>(this));
    return QWidget::qt_metacast(_clname);
}

int UAVPayload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void UAVPayload::arm(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UAVPayload::disarm(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
