/****************************************************************************
** Meta object code from reading C++ file 'GY_24GHz.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Communicate/GY_24GHz.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_24GHz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGY_24GHzENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGY_24GHzENDCLASS = QtMocHelpers::stringData(
    "GY_24GHz",
    "signal24GHzConnection",
    "",
    "HidDeviceInfo",
    "deviceInfo",
    "HidDeviceInfo::DeviceType",
    "deviceType",
    "signal24GHzDisconnection",
    "portPath",
    "signal24GHzBattery",
    "battery",
    "batteryChange",
    "signal24GHzKeyboardOrMouseConnected",
    "isKeyboard",
    "isMouse",
    "signal24_MouseBattery",
    "signal24_KeyboardBattery",
    "slotReadyRead",
    "QString&",
    "recvData",
    "GetDeviceMouseOrKeyboard",
    "readData",
    "_24GHzMouseConnect",
    "_24GHzKeyboardConnect",
    "slotsAdapterConnect",
    "slotsAdapterDisconnect",
    "slotGet_24GHzMouseBattery",
    "slotGet_24GHzKeyboardBattery"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGY_24GHzENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   98,    2, 0x06,    1 /* Public */,
       7,    2,  103,    2, 0x06,    4 /* Public */,
       9,    4,  108,    2, 0x06,    7 /* Public */,
      12,    2,  117,    2, 0x06,   12 /* Public */,
      15,    3,  122,    2, 0x06,   15 /* Public */,
      16,    3,  129,    2, 0x06,   19 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    2,  136,    2, 0x08,   23 /* Private */,
      20,    2,  141,    2, 0x08,   26 /* Private */,
      22,    1,  146,    2, 0x08,   29 /* Private */,
      23,    1,  149,    2, 0x08,   31 /* Private */,
      24,    1,  152,    2, 0x08,   33 /* Private */,
      25,    1,  155,    2, 0x08,   35 /* Private */,
      26,    0,  158,    2, 0x08,   37 /* Private */,
      27,    0,  159,    2, 0x08,   38 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    8,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 5,    8,   10,   11,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    8,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    8,   10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,    8,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,   21,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GY_24GHz::staticMetaObject = { {
    QMetaObject::SuperData::link<QHid::staticMetaObject>(),
    qt_meta_stringdata_CLASSGY_24GHzENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGY_24GHzENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGY_24GHzENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GY_24GHz, std::true_type>,
        // method 'signal24GHzConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const HidDeviceInfo &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'signal24GHzDisconnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'signal24GHzBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'signal24GHzKeyboardOrMouseConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signal24_MouseBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'signal24_KeyboardBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'GetDeviceMouseOrKeyboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method '_24GHzMouseConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method '_24GHzKeyboardConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotsAdapterConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotsAdapterDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotGet_24GHzMouseBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotGet_24GHzKeyboardBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GY_24GHz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GY_24GHz *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal24GHzConnection((*reinterpret_cast< std::add_pointer_t<HidDeviceInfo>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[2]))); break;
        case 1: _t->signal24GHzDisconnection((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[2]))); break;
        case 2: _t->signal24GHzBattery((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[4]))); break;
        case 3: _t->signal24GHzKeyboardOrMouseConnected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->signal24_MouseBattery((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 5: _t->signal24_KeyboardBattery((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 6: _t->slotReadyRead((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2]))); break;
        case 7: _t->GetDeviceMouseOrKeyboard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->_24GHzMouseConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->_24GHzKeyboardConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->slotsAdapterConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->slotsAdapterDisconnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->slotGet_24GHzMouseBattery(); break;
        case 13: _t->slotGet_24GHzKeyboardBattery(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GY_24GHz::*)(const HidDeviceInfo & , HidDeviceInfo::DeviceType );
            if (_t _q_method = &GY_24GHz::signal24GHzConnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GY_24GHz::*)(const QString & , HidDeviceInfo::DeviceType );
            if (_t _q_method = &GY_24GHz::signal24GHzDisconnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GY_24GHz::*)(const QString & , const QString & , const bool & , HidDeviceInfo::DeviceType );
            if (_t _q_method = &GY_24GHz::signal24GHzBattery; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GY_24GHz::*)(bool , bool );
            if (_t _q_method = &GY_24GHz::signal24GHzKeyboardOrMouseConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GY_24GHz::*)(const QString & , const QString & , const bool & );
            if (_t _q_method = &GY_24GHz::signal24_MouseBattery; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GY_24GHz::*)(const QString & , const QString & , const bool & );
            if (_t _q_method = &GY_24GHz::signal24_KeyboardBattery; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *GY_24GHz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GY_24GHz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGY_24GHzENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QHid::qt_metacast(_clname);
}

int GY_24GHz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHid::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GY_24GHz::signal24GHzConnection(const HidDeviceInfo & _t1, HidDeviceInfo::DeviceType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GY_24GHz::signal24GHzDisconnection(const QString & _t1, HidDeviceInfo::DeviceType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GY_24GHz::signal24GHzBattery(const QString & _t1, const QString & _t2, const bool & _t3, HidDeviceInfo::DeviceType _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GY_24GHz::signal24GHzKeyboardOrMouseConnected(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GY_24GHz::signal24_MouseBattery(const QString & _t1, const QString & _t2, const bool & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GY_24GHz::signal24_KeyboardBattery(const QString & _t1, const QString & _t2, const bool & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
