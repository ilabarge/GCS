/****************************************************************************
** Meta object code from reading C++ file 'MapSymbol22.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/MapSymbol22.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MapSymbol22.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapSymbol22_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapSymbol22_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapSymbol22_t qt_meta_stringdata_MapSymbol22 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MapSymbol22"
QT_MOC_LITERAL(1, 12, 16), // "GCSRemoveGraphic"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "graphicID"
QT_MOC_LITERAL(4, 40, 16), // "GCSUpdateGraphic"
QT_MOC_LITERAL(5, 57, 3), // "gID"
QT_MOC_LITERAL(6, 61, 23), // "EsriRuntimeQt::Graphic*"
QT_MOC_LITERAL(7, 85, 7) // "graphic"

    },
    "MapSymbol22\0GCSRemoveGraphic\0\0graphicID\0"
    "GCSUpdateGraphic\0gID\0EsriRuntimeQt::Graphic*\0"
    "graphic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapSymbol22[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    2,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,

       0        // eod
};

void MapSymbol22::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapSymbol22 *_t = static_cast<MapSymbol22 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GCSRemoveGraphic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->GCSUpdateGraphic((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< EsriRuntimeQt::Graphic*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EsriRuntimeQt::Graphic* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MapSymbol22::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapSymbol22::GCSRemoveGraphic)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MapSymbol22::*_t)(int , EsriRuntimeQt::Graphic * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapSymbol22::GCSUpdateGraphic)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MapSymbol22::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MapSymbol22.data,
      qt_meta_data_MapSymbol22,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MapSymbol22::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapSymbol22::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MapSymbol22.stringdata0))
        return static_cast<void*>(const_cast< MapSymbol22*>(this));
    return QObject::qt_metacast(_clname);
}

int MapSymbol22::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MapSymbol22::GCSRemoveGraphic(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapSymbol22::GCSUpdateGraphic(int _t1, EsriRuntimeQt::Graphic * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
