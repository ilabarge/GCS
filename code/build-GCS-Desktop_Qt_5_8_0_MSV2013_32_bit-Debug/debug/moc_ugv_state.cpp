/****************************************************************************
** Meta object code from reading C++ file 'ugv_state.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/ugv_state.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ugv_state.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UGV_state_t {
    QByteArrayData data[14];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UGV_state_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UGV_state_t qt_meta_stringdata_UGV_state = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UGV_state"
QT_MOC_LITERAL(1, 10, 12), // "ManualToAuto"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "AutoToManual"
QT_MOC_LITERAL(4, 37, 5), // "Reset"
QT_MOC_LITERAL(5, 43, 12), // "DisableMotor"
QT_MOC_LITERAL(6, 56, 11), // "EnableMotor"
QT_MOC_LITERAL(7, 68, 11), // "ToggleMotor"
QT_MOC_LITERAL(8, 80, 1), // "r"
QT_MOC_LITERAL(9, 82, 3), // "ATM"
QT_MOC_LITERAL(10, 86, 3), // "MTA"
QT_MOC_LITERAL(11, 90, 8), // "DisableM"
QT_MOC_LITERAL(12, 99, 7), // "EnableM"
QT_MOC_LITERAL(13, 107, 7) // "ToggleM"

    },
    "UGV_state\0ManualToAuto\0\0AutoToManual\0"
    "Reset\0DisableMotor\0EnableMotor\0"
    "ToggleMotor\0r\0ATM\0MTA\0DisableM\0EnableM\0"
    "ToggleM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UGV_state[] = {

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
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UGV_state::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UGV_state *_t = static_cast<UGV_state *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ManualToAuto(); break;
        case 1: _t->AutoToManual(); break;
        case 2: _t->Reset(); break;
        case 3: _t->DisableMotor(); break;
        case 4: _t->EnableMotor(); break;
        case 5: _t->ToggleMotor(); break;
        case 6: _t->r(); break;
        case 7: _t->ATM(); break;
        case 8: _t->MTA(); break;
        case 9: _t->DisableM(); break;
        case 10: _t->EnableM(); break;
        case 11: _t->ToggleM(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::ManualToAuto)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::AutoToManual)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::Reset)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::DisableMotor)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::EnableMotor)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (UGV_state::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UGV_state::ToggleMotor)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UGV_state::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UGV_state.data,
      qt_meta_data_UGV_state,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UGV_state::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UGV_state::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UGV_state.stringdata0))
        return static_cast<void*>(const_cast< UGV_state*>(this));
    return QWidget::qt_metacast(_clname);
}

int UGV_state::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UGV_state::ManualToAuto()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UGV_state::AutoToManual()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void UGV_state::Reset()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void UGV_state::DisableMotor()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void UGV_state::EnableMotor()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void UGV_state::ToggleMotor()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
