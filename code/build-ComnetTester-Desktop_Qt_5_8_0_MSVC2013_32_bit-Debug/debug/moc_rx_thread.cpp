/****************************************************************************
** Meta object code from reading C++ file 'rx_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ComnetTester/rx_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rx_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rx_thread_t {
    QByteArrayData data[34];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rx_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rx_thread_t qt_meta_stringdata_rx_thread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "rx_thread"
QT_MOC_LITERAL(1, 10, 8), // "finished"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "error"
QT_MOC_LITERAL(4, 26, 3), // "err"
QT_MOC_LITERAL(5, 30, 12), // "update_queue"
QT_MOC_LITERAL(6, 43, 10), // "vechStatus"
QT_MOC_LITERAL(7, 54, 10), // "sendTarget"
QT_MOC_LITERAL(8, 65, 10), // "updateVech"
QT_MOC_LITERAL(9, 76, 7), // "message"
QT_MOC_LITERAL(10, 84, 12), // "messageAlert"
QT_MOC_LITERAL(11, 97, 14), // "messageConfirm"
QT_MOC_LITERAL(12, 112, 8), // "send_GPS"
QT_MOC_LITERAL(13, 121, 7), // "process"
QT_MOC_LITERAL(14, 129, 9), // "send_Ping"
QT_MOC_LITERAL(15, 139, 17), // "update_vech_queue"
QT_MOC_LITERAL(16, 157, 25), // "send_vehicle_auth_request"
QT_MOC_LITERAL(17, 183, 22), // "send_telemetry_command"
QT_MOC_LITERAL(18, 206, 14), // "send_targeting"
QT_MOC_LITERAL(19, 221, 17), // "send_manTargeting"
QT_MOC_LITERAL(20, 239, 6), // "target"
QT_MOC_LITERAL(21, 246, 8), // "vechStat"
QT_MOC_LITERAL(22, 255, 4), // "drop"
QT_MOC_LITERAL(23, 260, 7), // "arm_uav"
QT_MOC_LITERAL(24, 268, 10), // "disarm_uav"
QT_MOC_LITERAL(25, 279, 12), // "ManualToAuto"
QT_MOC_LITERAL(26, 292, 12), // "AutoToManual"
QT_MOC_LITERAL(27, 305, 5), // "Reset"
QT_MOC_LITERAL(28, 311, 12), // "DisableMotor"
QT_MOC_LITERAL(29, 324, 11), // "ToggleMotor"
QT_MOC_LITERAL(30, 336, 11), // "EnableMotor"
QT_MOC_LITERAL(31, 348, 16), // "setNetworkSerial"
QT_MOC_LITERAL(32, 365, 6), // "update"
QT_MOC_LITERAL(33, 372, 11) // "sendMessage"

    },
    "rx_thread\0finished\0\0error\0err\0"
    "update_queue\0vechStatus\0sendTarget\0"
    "updateVech\0message\0messageAlert\0"
    "messageConfirm\0send_GPS\0process\0"
    "send_Ping\0update_vech_queue\0"
    "send_vehicle_auth_request\0"
    "send_telemetry_command\0send_targeting\0"
    "send_manTargeting\0target\0vechStat\0"
    "drop\0arm_uav\0disarm_uav\0ManualToAuto\0"
    "AutoToManual\0Reset\0DisableMotor\0"
    "ToggleMotor\0EnableMotor\0setNetworkSerial\0"
    "update\0sendMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rx_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  169,    2, 0x06 /* Public */,
       3,    1,  170,    2, 0x06 /* Public */,
       5,    0,  173,    2, 0x06 /* Public */,
       6,    2,  174,    2, 0x06 /* Public */,
       7,    2,  179,    2, 0x06 /* Public */,
       8,    1,  184,    2, 0x06 /* Public */,
       9,    1,  187,    2, 0x06 /* Public */,
      10,    1,  190,    2, 0x06 /* Public */,
      11,    1,  193,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  196,    2, 0x0a /* Public */,
      13,    0,  197,    2, 0x0a /* Public */,
      14,    0,  198,    2, 0x0a /* Public */,
      15,    0,  199,    2, 0x0a /* Public */,
      16,    1,  200,    2, 0x0a /* Public */,
      17,    1,  203,    2, 0x0a /* Public */,
      18,    4,  206,    2, 0x0a /* Public */,
      19,    3,  215,    2, 0x0a /* Public */,
      20,    2,  222,    2, 0x0a /* Public */,
      21,    2,  227,    2, 0x0a /* Public */,
      22,    1,  232,    2, 0x0a /* Public */,
      23,    1,  235,    2, 0x0a /* Public */,
      24,    1,  238,    2, 0x0a /* Public */,
      25,    0,  241,    2, 0x0a /* Public */,
      26,    0,  242,    2, 0x0a /* Public */,
      27,    0,  243,    2, 0x0a /* Public */,
      28,    0,  244,    2, 0x0a /* Public */,
      29,    0,  245,    2, 0x0a /* Public */,
      30,    0,  246,    2, 0x0a /* Public */,
      31,    1,  247,    2, 0x0a /* Public */,
      32,    1,  250,    2, 0x0a /* Public */,
      33,    1,  253,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void rx_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rx_thread *_t = static_cast<rx_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->update_queue(); break;
        case 3: _t->vechStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sendTarget((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->updateVech((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->messageAlert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->messageConfirm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->send_GPS(); break;
        case 10: _t->process(); break;
        case 11: _t->send_Ping(); break;
        case 12: _t->update_vech_queue(); break;
        case 13: _t->send_vehicle_auth_request((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->send_telemetry_command((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->send_targeting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 16: _t->send_manTargeting((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 17: _t->target((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 18: _t->vechStat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->drop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->arm_uav((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->disarm_uav((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->ManualToAuto(); break;
        case 23: _t->AutoToManual(); break;
        case 24: _t->Reset(); break;
        case 25: _t->DisableMotor(); break;
        case 26: _t->ToggleMotor(); break;
        case 27: _t->EnableMotor(); break;
        case 28: _t->setNetworkSerial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->update((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->sendMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (rx_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::update_queue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::vechStatus)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::sendTarget)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::updateVech)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::message)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::messageAlert)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::messageConfirm)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject rx_thread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rx_thread.data,
      qt_meta_data_rx_thread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *rx_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rx_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_rx_thread.stringdata0))
        return static_cast<void*>(const_cast< rx_thread*>(this));
    return QObject::qt_metacast(_clname);
}

int rx_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void rx_thread::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void rx_thread::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rx_thread::update_queue()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void rx_thread::vechStatus(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rx_thread::sendTarget(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rx_thread::updateVech(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rx_thread::message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void rx_thread::messageAlert(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void rx_thread::messageConfirm(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
