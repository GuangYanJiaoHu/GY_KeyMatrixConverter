/****************************************************************************
** Meta object code from reading C++ file 'GY_KeyboardSettingUi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GY_FunctionUi/GY_KeyboardSettingUi.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_KeyboardSettingUi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGY_KeyboardSettingUiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGY_KeyboardSettingUiENDCLASS = QtMocHelpers::stringData(
    "GY_KeyboardSettingUi",
    "signalKeyboardSettingClearKey",
    "",
    "signalKeyboardSettingDrawSize",
    "size",
    "signalKeyboardSettingHook",
    "isHook",
    "signalKeyboardSettingKeyCheck",
    "isCheck",
    "on_comboBox_KeyboardType_currentIndexChanged",
    "index",
    "on_pushButton_ClearKeyboard_clicked",
    "on_horizontalSlider_Size_sliderMoved",
    "position",
    "on_doubleSpinBox_Size_valueChanged",
    "arg1",
    "on_checkBox_Hook_stateChanged",
    "on_checkBox_KeyCheck_stateChanged",
    "on_horizontalSlider_Light_sliderMoved",
    "on_spinBox_Light_valueChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGY_KeyboardSettingUiENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    1,   87,    2, 0x06,    2 /* Public */,
       5,    1,   90,    2, 0x06,    4 /* Public */,
       7,    1,   93,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   96,    2, 0x08,    8 /* Private */,
      11,    0,   99,    2, 0x08,   10 /* Private */,
      12,    1,  100,    2, 0x08,   11 /* Private */,
      14,    1,  103,    2, 0x08,   13 /* Private */,
      16,    1,  106,    2, 0x08,   15 /* Private */,
      17,    1,  109,    2, 0x08,   17 /* Private */,
      18,    1,  112,    2, 0x08,   19 /* Private */,
      19,    1,  115,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject GY_KeyboardSettingUi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGY_KeyboardSettingUiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGY_KeyboardSettingUiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGY_KeyboardSettingUiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GY_KeyboardSettingUi, std::true_type>,
        // method 'signalKeyboardSettingClearKey'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalKeyboardSettingDrawSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'signalKeyboardSettingHook'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalKeyboardSettingKeyCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_comboBox_KeyboardType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_ClearKeyboard_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_Size_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_doubleSpinBox_Size_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_checkBox_Hook_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_KeyCheck_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_Light_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBox_Light_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void GY_KeyboardSettingUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GY_KeyboardSettingUi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalKeyboardSettingClearKey(); break;
        case 1: _t->signalKeyboardSettingDrawSize((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->signalKeyboardSettingHook((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->signalKeyboardSettingKeyCheck((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_comboBox_KeyboardType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_pushButton_ClearKeyboard_clicked(); break;
        case 6: _t->on_horizontalSlider_Size_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_Size_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->on_checkBox_Hook_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_checkBox_KeyCheck_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_horizontalSlider_Light_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_spinBox_Light_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GY_KeyboardSettingUi::*)();
            if (_t _q_method = &GY_KeyboardSettingUi::signalKeyboardSettingClearKey; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GY_KeyboardSettingUi::*)(double );
            if (_t _q_method = &GY_KeyboardSettingUi::signalKeyboardSettingDrawSize; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GY_KeyboardSettingUi::*)(bool );
            if (_t _q_method = &GY_KeyboardSettingUi::signalKeyboardSettingHook; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GY_KeyboardSettingUi::*)(bool );
            if (_t _q_method = &GY_KeyboardSettingUi::signalKeyboardSettingKeyCheck; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *GY_KeyboardSettingUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GY_KeyboardSettingUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGY_KeyboardSettingUiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GY_KeyboardSettingUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GY_KeyboardSettingUi::signalKeyboardSettingClearKey()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GY_KeyboardSettingUi::signalKeyboardSettingDrawSize(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GY_KeyboardSettingUi::signalKeyboardSettingHook(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GY_KeyboardSettingUi::signalKeyboardSettingKeyCheck(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
