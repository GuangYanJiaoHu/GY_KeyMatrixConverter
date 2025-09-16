/****************************************************************************
** Meta object code from reading C++ file 'GY_BlueToothDevice.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Communicate/GY_BlueToothDevice.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_BlueToothDevice.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBlueToothDeviceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBlueToothDeviceENDCLASS = QtMocHelpers::stringData(
    "BlueToothDevice",
    "sendDeviceConnectInfo",
    "",
    "BlueToothDevice::DeviceType",
    "type",
    "BlueToothInfo",
    "bluetoothInfo",
    "DeviceInfo",
    "deviceInfo",
    "sendDeviceDisconnectInfo",
    "sendBatteryInfomation",
    "slotKeyboardSearchInfo",
    "QBluetoothDeviceInfo",
    "info",
    "slotKeyboardSearchFinished",
    "QList<QBluetoothDeviceInfo>",
    "info_list",
    "slotMouseSearchInfo",
    "slotMouseSearchFinished",
    "slotMouseBatteryInfomation",
    "slotKeyboardBatteryInfomation"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBlueToothDeviceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x06,    1 /* Public */,
       9,    3,   75,    2, 0x06,    5 /* Public */,
      10,    2,   82,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   87,    2, 0x08,   12 /* Private */,
      14,    1,   90,    2, 0x08,   14 /* Private */,
      17,    1,   93,    2, 0x08,   16 /* Private */,
      18,    1,   96,    2, 0x08,   18 /* Private */,
      19,    1,   99,    2, 0x08,   20 /* Private */,
      20,    1,  102,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7,    4,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject BlueToothDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBlueToothDeviceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBlueToothDeviceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBlueToothDeviceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BlueToothDevice, std::true_type>,
        // method 'sendDeviceConnectInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothInfo, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeviceInfo, std::false_type>,
        // method 'sendDeviceDisconnectInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothInfo, std::false_type>,
        QtPrivate::TypeAndForceComplete<DeviceInfo, std::false_type>,
        // method 'sendBatteryInfomation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BlueToothDevice::DeviceType, std::false_type>,
        QtPrivate::TypeAndForceComplete<const DeviceInfo &, std::false_type>,
        // method 'slotKeyboardSearchInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'slotKeyboardSearchFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QBluetoothDeviceInfo> &, std::false_type>,
        // method 'slotMouseSearchInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'slotMouseSearchFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QBluetoothDeviceInfo> &, std::false_type>,
        // method 'slotMouseBatteryInfomation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const DeviceInfo &, std::false_type>,
        // method 'slotKeyboardBatteryInfomation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const DeviceInfo &, std::false_type>
    >,
    nullptr
} };

void BlueToothDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlueToothDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendDeviceConnectInfo((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<BlueToothInfo>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[3]))); break;
        case 1: _t->sendDeviceDisconnectInfo((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<BlueToothInfo>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[3]))); break;
        case 2: _t->sendBatteryInfomation((*reinterpret_cast< std::add_pointer_t<BlueToothDevice::DeviceType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[2]))); break;
        case 3: _t->slotKeyboardSearchInfo((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 4: _t->slotKeyboardSearchFinished((*reinterpret_cast< std::add_pointer_t<QList<QBluetoothDeviceInfo>>>(_a[1]))); break;
        case 5: _t->slotMouseSearchInfo((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 6: _t->slotMouseSearchFinished((*reinterpret_cast< std::add_pointer_t<QList<QBluetoothDeviceInfo>>>(_a[1]))); break;
        case 7: _t->slotMouseBatteryInfomation((*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[1]))); break;
        case 8: _t->slotKeyboardBatteryInfomation((*reinterpret_cast< std::add_pointer_t<DeviceInfo>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QBluetoothDeviceInfo> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QBluetoothDeviceInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BlueToothDevice::*)(BlueToothDevice::DeviceType , BlueToothInfo , DeviceInfo );
            if (_t _q_method = &BlueToothDevice::sendDeviceConnectInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BlueToothDevice::*)(BlueToothDevice::DeviceType , BlueToothInfo , DeviceInfo );
            if (_t _q_method = &BlueToothDevice::sendDeviceDisconnectInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BlueToothDevice::*)(BlueToothDevice::DeviceType , const DeviceInfo & );
            if (_t _q_method = &BlueToothDevice::sendBatteryInfomation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *BlueToothDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueToothDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBlueToothDeviceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BlueToothDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BlueToothDevice::sendDeviceConnectInfo(BlueToothDevice::DeviceType _t1, BlueToothInfo _t2, DeviceInfo _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BlueToothDevice::sendDeviceDisconnectInfo(BlueToothDevice::DeviceType _t1, BlueToothInfo _t2, DeviceInfo _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BlueToothDevice::sendBatteryInfomation(BlueToothDevice::DeviceType _t1, const DeviceInfo & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
