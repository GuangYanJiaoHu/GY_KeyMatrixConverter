/****************************************************************************
** Meta object code from reading C++ file 'GY_Communicate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Communicate/GY_Communicate.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_Communicate.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGY_CommunicateENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGY_CommunicateENDCLASS = QtMocHelpers::stringData(
    "GY_Communicate",
    "signalsDeviceConnect",
    "",
    "Device",
    "listDevice",
    "signalsDeviceDisconnect",
    "signalsDeviceBattery",
    "portPath",
    "battery",
    "batteryChange",
    "HidDeviceInfo::DeviceType",
    "deviceType",
    "signalsAdapterConnect1",
    "DeviceNumber",
    "signalsAdapterDisconnect1",
    "signals24GHzKeyboardOrMouseConnected",
    "isKeyboard",
    "isMouse",
    "slotAnimationStaticSimulate",
    "listColor",
    "slotAnimationDynamicSimulate",
    "soltKeyboardSettingBrightness",
    "lightHex",
    "soltKeyboardSettingSendData",
    "data",
    "slots24GHzConnect",
    "HidDeviceInfo",
    "deviceInfo",
    "slots24GHzDisconnect",
    "slotsKeyboardConnect",
    "DeviceInfo",
    "slotsKeyboardDisconnect",
    "slotsMouseConnect",
    "slotsMouseDisconnect",
    "slotsBatteryInfomation",
    "BlueToothDevice::DeviceType",
    "type",
    "slotsDeviceConnectInfo",
    "BlueToothInfo",
    "bluetoothInfo",
    "slotsDeviceDisconnectInfo"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGY_CommunicateENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       5,    1,  131,    2, 0x06,    3 /* Public */,
       6,    4,  134,    2, 0x06,    5 /* Public */,
      12,    2,  143,    2, 0x06,   10 /* Public */,
      14,    2,  148,    2, 0x06,   13 /* Public */,
      15,    2,  153,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  158,    2, 0x0a,   19 /* Public */,
      20,    1,  161,    2, 0x0a,   21 /* Public */,
      21,    1,  164,    2, 0x0a,   23 /* Public */,
      23,    1,  167,    2, 0x0a,   25 /* Public */,
      25,    2,  170,    2, 0x08,   27 /* Private */,
      28,    2,  175,    2, 0x08,   30 /* Private */,
      29,    1,  180,    2, 0x08,   33 /* Private */,
      31,    1,  183,    2, 0x08,   35 /* Private */,
      32,    1,  186,    2, 0x08,   37 /* Private */,
      33,    1,  189,    2, 0x08,   39 /* Private */,
      34,    2,  192,    2, 0x08,   41 /* Private */,
      37,    3,  197,    2, 0x08,   44 /* Private */,
      40,    3,  204,    2, 0x08,   48 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 10,    7,    8,    9,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   16,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   19,
    QMetaType::Void, QMetaType::QStringList,   19,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 10,   27,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    7,   11,
    QMetaType::Void, 0x80000000 | 26,   30,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 26,   30,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 35, 0x80000000 | 30,   36,   27,
    QMetaType::Void, 0x80000000 | 35, 0x80000000 | 38, 0x80000000 | 30,   36,   39,   27,
    QMetaType::Void, 0x80000000 | 35, 0x80000000 | 38, 0x80000000 | 30,   36,   39,   27,

       0        // eod
};

Q_CONSTINIT const QMetaObject GY_Communicate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGY_CommunicateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGY_CommunicateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGY_CommunicateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GY_Communicate, std::true_type>,
        // method 'signalsDeviceConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Device &, std::false_type>,
        // method 'signalsDeviceDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Device &, std::false_type>,
        // method 'signalsDeviceBattery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'signalsAdapterConnect1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'signalsAdapterDisconnect1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'signals24GHzKeyboardOrMouseConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotAnimationStaticSimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>,
        // method 'slotAnimationDynamicSimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>,
        // method 'soltKeyboardSettingBrightness'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'soltKeyboardSettingSendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slots24GHzConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const HidDeviceInfo &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'slots24GHzDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<HidDeviceInfo::DeviceType, std::false_type>,
        // method 'slotsKeyboardConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const HidDeviceInfo &, std::false_type>,
        // method 'slotsKeyboardDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotsMouseConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const HidDeviceInfo &, std::false_type>,
        // method 'slotsMouseDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slotsBatteryInfomation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeviceInfo, std::false_type>,
        // method 'slotsDeviceConnectInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothInfo, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeviceInfo, std::false_type>,
        // method 'slotsDeviceDisconnectInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothInfo, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeviceInfo, std::false_type>
    >,
    nullptr
} };

void GY_Communicate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GY_Communicate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalsDeviceConnect((*reinterpret_cast< std::add_pointer_t<Device>>(_a[1]))); break;
        case 1: _t->signalsDeviceDisconnect((*reinterpret_cast< std::add_pointer_t<Device>>(_a[1]))); break;
        case 2: _t->signalsDeviceBattery((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[4]))); break;
        case 3: _t->signalsAdapterConnect1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->signalsAdapterDisconnect1((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->signals24GHzKeyboardOrMouseConnected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->slotAnimationStaticSimulate((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 7: _t->slotAnimationDynamicSimulate((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 8: _t->soltKeyboardSettingBrightness((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->soltKeyboardSettingSendData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->slots24GHzConnect((*reinterpret_cast< std::add_pointer_t<HidDeviceInfo>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[2]))); break;
        case 11: _t->slots24GHzDisconnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<HidDeviceInfo::DeviceType>>(_a[2]))); break;
        case 12: _t->slotsKeyboardConnect((*reinterpret_cast< std::add_pointer_t<HidDeviceInfo>>(_a[1]))); break;
        case 13: _t->slotsKeyboardDisconnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->slotsMouseConnect((*reinterpret_cast< std::add_pointer_t<HidDeviceInfo>>(_a[1]))); break;
        case 15: _t->slotsMouseDisconnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->slotsBatteryInfomation((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[2]))); break;
        case 17: _t->slotsDeviceConnectInfo((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<BlueToothInfo>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[3]))); break;
        case 18: _t->slotsDeviceDisconnectInfo((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<BlueToothInfo>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GY_Communicate::*)(const Device & );
            if (_t _q_method = &GY_Communicate::signalsDeviceConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GY_Communicate::*)(const Device & );
            if (_t _q_method = &GY_Communicate::signalsDeviceDisconnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GY_Communicate::*)(const QString & , const QString & , const bool & , HidDeviceInfo::DeviceType );
            if (_t _q_method = &GY_Communicate::signalsDeviceBattery; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GY_Communicate::*)(const int & , const QString & );
            if (_t _q_method = &GY_Communicate::signalsAdapterConnect1; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GY_Communicate::*)(const int & , const QString & );
            if (_t _q_method = &GY_Communicate::signalsAdapterDisconnect1; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GY_Communicate::*)(bool , bool );
            if (_t _q_method = &GY_Communicate::signals24GHzKeyboardOrMouseConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *GY_Communicate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GY_Communicate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGY_CommunicateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GY_Communicate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void GY_Communicate::signalsDeviceConnect(const Device & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GY_Communicate::signalsDeviceDisconnect(const Device & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GY_Communicate::signalsDeviceBattery(const QString & _t1, const QString & _t2, const bool & _t3, HidDeviceInfo::DeviceType _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GY_Communicate::signalsAdapterConnect1(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GY_Communicate::signalsAdapterDisconnect1(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GY_Communicate::signals24GHzKeyboardOrMouseConnected(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
