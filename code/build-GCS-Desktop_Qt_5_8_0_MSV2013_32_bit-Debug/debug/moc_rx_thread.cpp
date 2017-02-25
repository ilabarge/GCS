/****************************************************************************
** Meta object code from reading C++ file 'rx_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs/src/rx_thread.h"
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
    QByteArrayData data[47];
    char stringdata0[574];
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
QT_MOC_LITERAL(6, 43, 14), // "endUGVJoystick"
QT_MOC_LITERAL(7, 58, 16), // "startUGVJoystick"
QT_MOC_LITERAL(8, 75, 9), // "newTarget"
QT_MOC_LITERAL(9, 85, 7), // "Target*"
QT_MOC_LITERAL(10, 93, 10), // "vechStatus"
QT_MOC_LITERAL(11, 104, 10), // "sendTarget"
QT_MOC_LITERAL(12, 115, 10), // "updateVech"
QT_MOC_LITERAL(13, 126, 10), // "updateTarg"
QT_MOC_LITERAL(14, 137, 17), // "updateTargDisplay"
QT_MOC_LITERAL(15, 155, 7), // "message"
QT_MOC_LITERAL(16, 163, 12), // "messageAlert"
QT_MOC_LITERAL(17, 176, 14), // "messageConfirm"
QT_MOC_LITERAL(18, 191, 7), // "process"
QT_MOC_LITERAL(19, 199, 9), // "send_ping"
QT_MOC_LITERAL(20, 209, 2), // "id"
QT_MOC_LITERAL(21, 212, 17), // "update_vech_queue"
QT_MOC_LITERAL(22, 230, 25), // "send_vehicle_auth_request"
QT_MOC_LITERAL(23, 256, 21), // "send_vehicle_waypoint"
QT_MOC_LITERAL(24, 278, 11), // "Waypoint22*"
QT_MOC_LITERAL(25, 290, 22), // "send_telemetry_command"
QT_MOC_LITERAL(26, 313, 14), // "send_targeting"
QT_MOC_LITERAL(27, 328, 17), // "send_manTargeting"
QT_MOC_LITERAL(28, 346, 12), // "target_added"
QT_MOC_LITERAL(29, 359, 6), // "target"
QT_MOC_LITERAL(30, 366, 8), // "vechStat"
QT_MOC_LITERAL(31, 375, 4), // "drop"
QT_MOC_LITERAL(32, 380, 7), // "arm_uav"
QT_MOC_LITERAL(33, 388, 10), // "disarm_uav"
QT_MOC_LITERAL(34, 399, 18), // "start_UGV_Joystick"
QT_MOC_LITERAL(35, 418, 17), // "stop_UGV_Joystick"
QT_MOC_LITERAL(36, 436, 12), // "ManualToAuto"
QT_MOC_LITERAL(37, 449, 12), // "AutoToManual"
QT_MOC_LITERAL(38, 462, 5), // "Reset"
QT_MOC_LITERAL(39, 468, 12), // "DisableMotor"
QT_MOC_LITERAL(40, 481, 11), // "ToggleMotor"
QT_MOC_LITERAL(41, 493, 11), // "EnableMotor"
QT_MOC_LITERAL(42, 505, 16), // "setNetworkSerial"
QT_MOC_LITERAL(43, 522, 6), // "update"
QT_MOC_LITERAL(44, 529, 12), // "updateTarget"
QT_MOC_LITERAL(45, 542, 19), // "updateTargetDisplay"
QT_MOC_LITERAL(46, 562, 11) // "sendMessage"

    },
    "rx_thread\0finished\0\0error\0err\0"
    "update_queue\0endUGVJoystick\0"
    "startUGVJoystick\0newTarget\0Target*\0"
    "vechStatus\0sendTarget\0updateVech\0"
    "updateTarg\0updateTargDisplay\0message\0"
    "messageAlert\0messageConfirm\0process\0"
    "send_ping\0id\0update_vech_queue\0"
    "send_vehicle_auth_request\0"
    "send_vehicle_waypoint\0Waypoint22*\0"
    "send_telemetry_command\0send_targeting\0"
    "send_manTargeting\0target_added\0target\0"
    "vechStat\0drop\0arm_uav\0disarm_uav\0"
    "start_UGV_Joystick\0stop_UGV_Joystick\0"
    "ManualToAuto\0AutoToManual\0Reset\0"
    "DisableMotor\0ToggleMotor\0EnableMotor\0"
    "setNetworkSerial\0update\0updateTarget\0"
    "updateTargetDisplay\0sendMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rx_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  219,    2, 0x06 /* Public */,
       3,    1,  220,    2, 0x06 /* Public */,
       5,    0,  223,    2, 0x06 /* Public */,
       6,    0,  224,    2, 0x06 /* Public */,
       7,    0,  225,    2, 0x06 /* Public */,
       8,    1,  226,    2, 0x06 /* Public */,
      10,    2,  229,    2, 0x06 /* Public */,
      11,    2,  234,    2, 0x06 /* Public */,
      12,    1,  239,    2, 0x06 /* Public */,
      13,    1,  242,    2, 0x06 /* Public */,
      14,    1,  245,    2, 0x06 /* Public */,
      15,    1,  248,    2, 0x06 /* Public */,
      16,    1,  251,    2, 0x06 /* Public */,
      17,    1,  254,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  257,    2, 0x0a /* Public */,
      19,    1,  258,    2, 0x0a /* Public */,
      21,    0,  261,    2, 0x0a /* Public */,
      22,    1,  262,    2, 0x0a /* Public */,
      23,    2,  265,    2, 0x0a /* Public */,
      25,    1,  270,    2, 0x0a /* Public */,
      26,    4,  273,    2, 0x0a /* Public */,
      27,    3,  282,    2, 0x0a /* Public */,
      28,    1,  289,    2, 0x0a /* Public */,
      29,    2,  292,    2, 0x0a /* Public */,
      30,    2,  297,    2, 0x0a /* Public */,
      31,    1,  302,    2, 0x0a /* Public */,
      32,    1,  305,    2, 0x0a /* Public */,
      33,    1,  308,    2, 0x0a /* Public */,
      34,    0,  311,    2, 0x0a /* Public */,
      35,    0,  312,    2, 0x0a /* Public */,
      36,    0,  313,    2, 0x0a /* Public */,
      37,    0,  314,    2, 0x0a /* Public */,
      38,    0,  315,    2, 0x0a /* Public */,
      39,    0,  316,    2, 0x0a /* Public */,
      40,    0,  317,    2, 0x0a /* Public */,
      41,    0,  318,    2, 0x0a /* Public */,
      42,    1,  319,    2, 0x0a /* Public */,
      43,    1,  322,    2, 0x0a /* Public */,
      44,    1,  325,    2, 0x0a /* Public */,
      45,    1,  328,    2, 0x0a /* Public */,
      46,    1,  331,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
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
        case 3: _t->endUGVJoystick(); break;
        case 4: _t->startUGVJoystick(); break;
        case 5: _t->newTarget((*reinterpret_cast< Target*(*)>(_a[1]))); break;
        case 6: _t->vechStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->sendTarget((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->updateVech((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateTarg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateTargDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->messageAlert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->messageConfirm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->process(); break;
        case 15: _t->send_ping((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->update_vech_queue(); break;
        case 17: _t->send_vehicle_auth_request((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->send_vehicle_waypoint((*reinterpret_cast< Waypoint22*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->send_telemetry_command((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->send_targeting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 21: _t->send_manTargeting((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 22: _t->target_added((*reinterpret_cast< Target*(*)>(_a[1]))); break;
        case 23: _t->target((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 24: _t->vechStat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->drop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->arm_uav((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->disarm_uav((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->start_UGV_Joystick(); break;
        case 29: _t->stop_UGV_Joystick(); break;
        case 30: _t->ManualToAuto(); break;
        case 31: _t->AutoToManual(); break;
        case 32: _t->Reset(); break;
        case 33: _t->DisableMotor(); break;
        case 34: _t->ToggleMotor(); break;
        case 35: _t->EnableMotor(); break;
        case 36: _t->setNetworkSerial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->update((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->updateTarget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->updateTargetDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->sendMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 18:
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
            typedef void (rx_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::endUGVJoystick)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::startUGVJoystick)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(Target * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::newTarget)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::vechStatus)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::sendTarget)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::updateVech)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::updateTarg)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::updateTargDisplay)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::message)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::messageAlert)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (rx_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rx_thread::messageConfirm)) {
                *result = 13;
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
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
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
void rx_thread::endUGVJoystick()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void rx_thread::startUGVJoystick()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void rx_thread::newTarget(Target * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rx_thread::vechStatus(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void rx_thread::sendTarget(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void rx_thread::updateVech(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void rx_thread::updateTarg(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void rx_thread::updateTargDisplay(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void rx_thread::message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void rx_thread::messageAlert(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void rx_thread::messageConfirm(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
