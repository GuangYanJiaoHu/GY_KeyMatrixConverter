/****************************************************************************
** Meta object code from reading C++ file 'GY_HIDKeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Communicate/GY_HIDKeyboard.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_HIDKeyboard.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGY_HIDKeyboardENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGY_HIDKeyboardENDCLASS = QtMocHelpers::stringData(
    "GY_HIDKeyboard",
    "signalBatteryChange",
    "",
    "portPath",
    "battery",
    "batteryChange",
    "HidDeviceInfo::DeviceType",
    "deviceType",
    "signalKeyboardConnection",
    "HidDeviceInfo",
    "deviceInfo",
    "signalKeyboardDisconnection",
    "slotReadyRead",
    "QString&",
    "recvData",
    "slotsKeyboardConnect"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGY_HIDKeyboardENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   44,    2, 0x06,    1 /* Public */,
       8,    1,   53,    2, 0x06,    6 /* Public */,
      11,    1,   56,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    2,   59,    2, 0x08,   10 /* Private */,
      15,    1,   64,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 6,    3,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   14,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject GY_HIDKeyboard::staticMetaObject = { {
    QMetaObject::SuperData::link<QHid::staticMetaObject>(),
    qt_meta_stringdata_CLASSGY_HIDKeyboardENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGY_HIDKeyboardENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGY_HIDKeyboardENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GY_HIDKeyboard, std::true_type>,
        // method 'signalBatteryChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'signalKeyboardConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const HidDeviceInfo &, std::false_type>,
        // method 'signalKeyboardDisconnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'slotsKeyboardConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void GY_HIDKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GY_HIDKeyboard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalBatteryChange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[4]))); break;
        case 1: _t->signalKeyboardConnection((*reinterpret_cast< std::add_pointer_t<HidDeviceInfo>>(_a[1]))); break;
        case 2: _t->signalKeyboardDisconnection((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->slotReadyRead((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2]))); break;
        case 4: _t->slotsKeyboardConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GY_HIDKeyboard::*)(const QString & , const QString & , const bool & , HidDeviceInfo::DeviceType );
            if (_t _q_method = &GY_HIDKeyboard::signalBatteryChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GY_HIDKeyboard::*)(const HidDeviceInfo & );
            if (_t _q_method = &GY_HIDKeyboard::signalKeyboardConnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GY_HIDKeyboard::*)(const QString & );
            if (_t _q_method = &GY_HIDKeyboard::signalKeyboardDisconnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *GY_HIDKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GY_HIDKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGY_HIDKeyboardENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QHid::qt_metacast(_clname);
}

int GY_HIDKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHid::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GY_HIDKeyboard::signalBatteryChange(const QString & _t1, const QString & _t2, const bool & _t3, HidDeviceInfo::DeviceType _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GY_HIDKeyboard::signalKeyboardConnection(const HidDeviceInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GY_HIDKeyboard::signalKeyboardDisconnection(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
