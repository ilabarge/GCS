/****************************************************************************
** Meta object code from reading C++ file 'Vehicle22.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/Vehicle22.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Vehicle22.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Vehicle22_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vehicle22_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vehicle22_t qt_meta_stringdata_Vehicle22 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Vehicle22"
QT_MOC_LITERAL(1, 10, 16), // "GCSUpdateGraphic"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "gID"
QT_MOC_LITERAL(4, 32, 23), // "EsriRuntimeQt::Graphic*"
QT_MOC_LITERAL(5, 56, 7), // "graphic"
QT_MOC_LITERAL(6, 64, 18), // "addWaypointGraphic"
QT_MOC_LITERAL(7, 83, 11), // "Waypoint22*"
QT_MOC_LITERAL(8, 95, 22), // "updateWaypointGraphics"
QT_MOC_LITERAL(9, 118, 2), // "wp"
QT_MOC_LITERAL(10, 121, 21), // "removeWaypointGraphic"
QT_MOC_LITERAL(11, 143, 10), // "waypointID"
QT_MOC_LITERAL(12, 154, 6) // "lineID"

    },
    "Vehicle22\0GCSUpdateGraphic\0\0gID\0"
    "EsriRuntimeQt::Graphic*\0graphic\0"
    "addWaypointGraphic\0Waypoint22*\0"
    "updateWaypointGraphics\0wp\0"
    "removeWaypointGraphic\0waypointID\0"
    "lineID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vehicle22[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    2,   39,    2, 0x06 /* Public */,
       8,    1,   44,    2, 0x06 /* Public */,
      10,    2,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QColor,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

       0        // eod
};

void Vehicle22::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Vehicle22 *_t = static_cast<Vehicle22 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GCSUpdateGraphic((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< EsriRuntimeQt::Graphic*(*)>(_a[2]))); break;
        case 1: _t->addWaypointGraphic((*reinterpret_cast< Waypoint22*(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->updateWaypointGraphics((*reinterpret_cast< Waypoint22*(*)>(_a[1]))); break;
        case 3: _t->removeWaypointGraphic((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EsriRuntimeQt::Graphic* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Waypoint22* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Waypoint22* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Vehicle22::*_t)(int , EsriRuntimeQt::Graphic * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vehicle22::GCSUpdateGraphic)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Vehicle22::*_t)(Waypoint22 * , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vehicle22::addWaypointGraphic)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Vehicle22::*_t)(Waypoint22 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vehicle22::updateWaypointGraphics)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Vehicle22::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vehicle22::removeWaypointGraphic)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Vehicle22::staticMetaObject = {
    { &MapSymbol22::staticMetaObject, qt_meta_stringdata_Vehicle22.data,
      qt_meta_data_Vehicle22,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Vehicle22::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vehicle22::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Vehicle22.stringdata0))
        return static_cast<void*>(const_cast< Vehicle22*>(this));
    return MapSymbol22::qt_metacast(_clname);
}

int Vehicle22::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MapSymbol22::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Vehicle22::GCSUpdateGraphic(int _t1, EsriRuntimeQt::Graphic * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Vehicle22::addWaypointGraphic(Waypoint22 * _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Vehicle22::updateWaypointGraphics(Waypoint22 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Vehicle22::removeWaypointGraphic(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
