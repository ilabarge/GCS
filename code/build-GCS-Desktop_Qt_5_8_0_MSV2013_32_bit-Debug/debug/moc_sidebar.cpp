/****************************************************************************
** Meta object code from reading C++ file 'sidebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/sidebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sidebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sideBar_t {
    QByteArrayData data[15];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sideBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sideBar_t qt_meta_stringdata_sideBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "sideBar"
QT_MOC_LITERAL(1, 8, 5), // "uavOn"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 4), // "isOn"
QT_MOC_LITERAL(4, 20, 5), // "ugvOn"
QT_MOC_LITERAL(5, 26, 10), // "waypointOn"
QT_MOC_LITERAL(6, 37, 11), // "satelliteOn"
QT_MOC_LITERAL(7, 49, 9), // "opspaceOn"
QT_MOC_LITERAL(8, 59, 8), // "targetOn"
QT_MOC_LITERAL(9, 68, 9), // "uavToggle"
QT_MOC_LITERAL(10, 78, 9), // "ugvToggle"
QT_MOC_LITERAL(11, 88, 14), // "waypointToggle"
QT_MOC_LITERAL(12, 103, 15), // "satelliteToggle"
QT_MOC_LITERAL(13, 119, 13), // "opspaceToggle"
QT_MOC_LITERAL(14, 133, 12) // "targetToggle"

    },
    "sideBar\0uavOn\0\0isOn\0ugvOn\0waypointOn\0"
    "satelliteOn\0opspaceOn\0targetOn\0uavToggle\0"
    "ugvToggle\0waypointToggle\0satelliteToggle\0"
    "opspaceToggle\0targetToggle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sideBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void sideBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sideBar *_t = static_cast<sideBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->uavOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ugvOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->waypointOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->satelliteOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->opspaceOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->targetOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->uavToggle(); break;
        case 7: _t->ugvToggle(); break;
        case 8: _t->waypointToggle(); break;
        case 9: _t->satelliteToggle(); break;
        case 10: _t->opspaceToggle(); break;
        case 11: _t->targetToggle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::uavOn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::ugvOn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::waypointOn)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::satelliteOn)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::opspaceOn)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (sideBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sideBar::targetOn)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject sideBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_sideBar.data,
      qt_meta_data_sideBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *sideBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sideBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_sideBar.stringdata0))
        return static_cast<void*>(const_cast< sideBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int sideBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void sideBar::uavOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sideBar::ugvOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void sideBar::waypointOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void sideBar::satelliteOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void sideBar::opspaceOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void sideBar::targetOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
