/****************************************************************************
** Meta object code from reading C++ file 'gcs_toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gcs_toolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gcs_toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GcsToolbar_t {
    QByteArrayData data[27];
    char stringdata[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GcsToolbar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GcsToolbar_t qt_meta_stringdata_GcsToolbar = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 14),
QT_MOC_LITERAL(4, 42, 19),
QT_MOC_LITERAL(5, 62, 7),
QT_MOC_LITERAL(6, 70, 14),
QT_MOC_LITERAL(7, 85, 14),
QT_MOC_LITERAL(8, 100, 15),
QT_MOC_LITERAL(9, 116, 16),
QT_MOC_LITERAL(10, 133, 13),
QT_MOC_LITERAL(11, 147, 11),
QT_MOC_LITERAL(12, 159, 14),
QT_MOC_LITERAL(13, 174, 14),
QT_MOC_LITERAL(14, 189, 15),
QT_MOC_LITERAL(15, 205, 14),
QT_MOC_LITERAL(16, 220, 14),
QT_MOC_LITERAL(17, 235, 11),
QT_MOC_LITERAL(18, 247, 12),
QT_MOC_LITERAL(19, 260, 13),
QT_MOC_LITERAL(20, 274, 10),
QT_MOC_LITERAL(21, 285, 7),
QT_MOC_LITERAL(22, 293, 7),
QT_MOC_LITERAL(23, 301, 8),
QT_MOC_LITERAL(24, 310, 7),
QT_MOC_LITERAL(25, 318, 7),
QT_MOC_LITERAL(26, 326, 7)
    },
    "GcsToolbar\0clickedMapView\0\0clickedUavView\0"
    "GcsToolbar::Vehicle\0vehicle\0clickedUgvView\0"
    "clickedPayload\0clickedSettings\0"
    "clickedWaypoints\0clickedZoning\0"
    "slotMapView\0slotUavViewCpp\0slotUavViewSlo\0"
    "slotUavViewCpp2\0slotUgvViewCpp\0"
    "slotUgvViewSlo\0slotPayload\0slotSettings\0"
    "slotWaypoints\0slotZoning\0Vehicle\0"
    "UAV_CPP\0UAV_CPP2\0UAV_SLO\0UGV_CPP\0"
    "UGV_SLO\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GcsToolbar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       1,  120, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06,
       3,    1,  100,    2, 0x06,
       6,    1,  103,    2, 0x06,
       7,    0,  106,    2, 0x06,
       8,    0,  107,    2, 0x06,
       9,    0,  108,    2, 0x06,
      10,    0,  109,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,  110,    2, 0x0a,
      12,    0,  111,    2, 0x0a,
      13,    0,  112,    2, 0x0a,
      14,    0,  113,    2, 0x0a,
      15,    0,  114,    2, 0x0a,
      16,    0,  115,    2, 0x0a,
      17,    0,  116,    2, 0x0a,
      18,    0,  117,    2, 0x0a,
      19,    0,  118,    2, 0x0a,
      20,    0,  119,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, flags, count, data
      21, 0x0,    5,  124,

 // enum data: key, value
      22, uint(GcsToolbar::UAV_CPP),
      23, uint(GcsToolbar::UAV_CPP2),
      24, uint(GcsToolbar::UAV_SLO),
      25, uint(GcsToolbar::UGV_CPP),
      26, uint(GcsToolbar::UGV_SLO),

       0        // eod
};

void GcsToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GcsToolbar *_t = static_cast<GcsToolbar *>(_o);
        switch (_id) {
        case 0: _t->clickedMapView(); break;
        case 1: _t->clickedUavView((*reinterpret_cast< GcsToolbar::Vehicle(*)>(_a[1]))); break;
        case 2: _t->clickedUgvView((*reinterpret_cast< GcsToolbar::Vehicle(*)>(_a[1]))); break;
        case 3: _t->clickedPayload(); break;
        case 4: _t->clickedSettings(); break;
        case 5: _t->clickedWaypoints(); break;
        case 6: _t->clickedZoning(); break;
        case 7: _t->slotMapView(); break;
        case 8: _t->slotUavViewCpp(); break;
        case 9: _t->slotUavViewSlo(); break;
        case 10: _t->slotUavViewCpp2(); break;
        case 11: _t->slotUgvViewCpp(); break;
        case 12: _t->slotUgvViewSlo(); break;
        case 13: _t->slotPayload(); break;
        case 14: _t->slotSettings(); break;
        case 15: _t->slotWaypoints(); break;
        case 16: _t->slotZoning(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GcsToolbar::Vehicle >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GcsToolbar::Vehicle >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GcsToolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedMapView)) {
                *result = 0;
            }
        }
        {
            typedef void (GcsToolbar::*_t)(GcsToolbar::Vehicle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedUavView)) {
                *result = 1;
            }
        }
        {
            typedef void (GcsToolbar::*_t)(GcsToolbar::Vehicle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedUgvView)) {
                *result = 2;
            }
        }
        {
            typedef void (GcsToolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedPayload)) {
                *result = 3;
            }
        }
        {
            typedef void (GcsToolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedSettings)) {
                *result = 4;
            }
        }
        {
            typedef void (GcsToolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedWaypoints)) {
                *result = 5;
            }
        }
        {
            typedef void (GcsToolbar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GcsToolbar::clickedZoning)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject GcsToolbar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GcsToolbar.data,
      qt_meta_data_GcsToolbar,  qt_static_metacall, 0, 0}
};


const QMetaObject *GcsToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GcsToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GcsToolbar.stringdata))
        return static_cast<void*>(const_cast< GcsToolbar*>(this));
    return QWidget::qt_metacast(_clname);
}

int GcsToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GcsToolbar::clickedMapView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GcsToolbar::clickedUavView(GcsToolbar::Vehicle _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GcsToolbar::clickedUgvView(GcsToolbar::Vehicle _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GcsToolbar::clickedPayload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GcsToolbar::clickedSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GcsToolbar::clickedWaypoints()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GcsToolbar::clickedZoning()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
