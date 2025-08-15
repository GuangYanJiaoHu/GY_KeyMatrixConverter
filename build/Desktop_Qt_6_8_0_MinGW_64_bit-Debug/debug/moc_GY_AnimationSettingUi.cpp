/****************************************************************************
** Meta object code from reading C++ file 'GY_AnimationSettingUi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GY_FunctionUi/GY_AnimationSettingUi.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GY_AnimationSettingUi.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGY_AnimationSettingUiENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGY_AnimationSettingUiENDCLASS = QtMocHelpers::stringData(
    "GY_AnimationSettingUi",
    "signalAnimationStaticSimulate",
    "",
    "path",
    "listStaticPictureName",
    "isStart",
    "isDownLoadKeyboard",
    "signalAnimationDynamicSimulate",
    "listDynamicPicturePath",
    "signalAnimationStaticOnlySimulate",
    "onlyName",
    "signalAnimationDynamicOnlySimulate",
    "signalAnimationStaticUiSimulateSpeed",
    "speed",
    "signalAnimationDynamicUiSimulateSpeed",
    "signalAnimationDynamicUpdateSimulatePos",
    "signalAnimationStaticExport",
    "signalAnimationDynamicExport",
    "signalAnimationDynamicPixmapSize",
    "size",
    "slotKeyboardDrawLayoutUpdateSimulatePos",
    "on_pushButton_StaticReadPath_clicked",
    "on_pushButton_DynamicReadPath_clicked",
    "on_pushButton_StaticStart_clicked",
    "on_pushButton_DynamicStart_clicked",
    "on_comboBox_StaticOnlySimulate_currentIndexChanged",
    "index",
    "on_comboBox_DynamicOnlySimulate_currentIndexChanged",
    "on_horizontalSlider_StaticUi_sliderReleased",
    "on_horizontalSlider_StaticUi_valueChanged",
    "value",
    "on_horizontalSlider_DynamicUi_sliderReleased",
    "on_horizontalSlider_DynamicUi_valueChanged",
    "on_pushButton_DynamicUpdateSimulatePos_clicked",
    "on_pushButton_StaticExport_clicked",
    "on_pushButton_DynamicExport_clicked",
    "on_horizontalSlider_PixmapWidth_valueChanged",
    "on_spinBox_PixmapWidth_valueChanged",
    "arg1",
    "on_horizontalSlider_PixmapHeight_valueChanged",
    "on_spinBox_PixmapHeight_valueChanged",
    "on_checkBox_StaticSend_stateChanged",
    "on_checkBox_DynamicSend_stateChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGY_AnimationSettingUiENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,  194,    2, 0x06,    1 /* Public */,
       7,    4,  203,    2, 0x06,    6 /* Public */,
       9,    3,  212,    2, 0x06,   11 /* Public */,
      11,    3,  219,    2, 0x06,   15 /* Public */,
      12,    1,  226,    2, 0x06,   19 /* Public */,
      14,    1,  229,    2, 0x06,   21 /* Public */,
      15,    0,  232,    2, 0x06,   23 /* Public */,
      16,    1,  233,    2, 0x06,   24 /* Public */,
      17,    1,  236,    2, 0x06,   26 /* Public */,
      18,    1,  239,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    0,  242,    2, 0x0a,   30 /* Public */,
      21,    0,  243,    2, 0x08,   31 /* Private */,
      22,    0,  244,    2, 0x08,   32 /* Private */,
      23,    0,  245,    2, 0x08,   33 /* Private */,
      24,    0,  246,    2, 0x08,   34 /* Private */,
      25,    1,  247,    2, 0x08,   35 /* Private */,
      27,    1,  250,    2, 0x08,   37 /* Private */,
      28,    0,  253,    2, 0x08,   39 /* Private */,
      29,    1,  254,    2, 0x08,   40 /* Private */,
      31,    0,  257,    2, 0x08,   42 /* Private */,
      32,    1,  258,    2, 0x08,   43 /* Private */,
      33,    0,  261,    2, 0x08,   45 /* Private */,
      34,    0,  262,    2, 0x08,   46 /* Private */,
      35,    0,  263,    2, 0x08,   47 /* Private */,
      36,    1,  264,    2, 0x08,   48 /* Private */,
      37,    1,  267,    2, 0x08,   50 /* Private */,
      39,    1,  270,    2, 0x08,   52 /* Private */,
      40,    1,  273,    2, 0x08,   54 /* Private */,
      41,    1,  276,    2, 0x08,   56 /* Private */,
      42,    1,  279,    2, 0x08,   58 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Bool, QMetaType::Bool,    3,    8,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,   10,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,   10,    6,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QPoint,   19,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   38,

       0        // eod
};

Q_CONSTINIT const QMetaObject GY_AnimationSettingUi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGY_AnimationSettingUiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGY_AnimationSettingUiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGY_AnimationSettingUiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GY_AnimationSettingUi, std::true_type>,
        // method 'signalAnimationStaticSimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalAnimationDynamicSimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalAnimationStaticOnlySimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalAnimationDynamicOnlySimulate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalAnimationStaticUiSimulateSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalAnimationDynamicUiSimulateSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalAnimationDynamicUpdateSimulatePos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalAnimationStaticExport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'signalAnimationDynamicExport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'signalAnimationDynamicPixmapSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'slotKeyboardDrawLayoutUpdateSimulatePos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_StaticReadPath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_DynamicReadPath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_StaticStart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_DynamicStart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_StaticOnlySimulate_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_comboBox_DynamicOnlySimulate_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_StaticUi_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_StaticUi_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_DynamicUi_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_DynamicUi_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_DynamicUpdateSimulatePos_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_StaticExport_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_DynamicExport_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_PixmapWidth_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBox_PixmapWidth_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_PixmapHeight_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBox_PixmapHeight_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_StaticSend_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_DynamicSend_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void GY_AnimationSettingUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GY_AnimationSettingUi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAnimationStaticSimulate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 1: _t->signalAnimationDynamicSimulate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 2: _t->signalAnimationStaticOnlySimulate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 3: _t->signalAnimationDynamicOnlySimulate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 4: _t->signalAnimationStaticUiSimulateSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->signalAnimationDynamicUiSimulateSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->signalAnimationDynamicUpdateSimulatePos(); break;
        case 7: _t->signalAnimationStaticExport((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->signalAnimationDynamicExport((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->signalAnimationDynamicPixmapSize((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 10: _t->slotKeyboardDrawLayoutUpdateSimulatePos(); break;
        case 11: _t->on_pushButton_StaticReadPath_clicked(); break;
        case 12: _t->on_pushButton_DynamicReadPath_clicked(); break;
        case 13: _t->on_pushButton_StaticStart_clicked(); break;
        case 14: _t->on_pushButton_DynamicStart_clicked(); break;
        case 15: _t->on_comboBox_StaticOnlySimulate_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_comboBox_DynamicOnlySimulate_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_horizontalSlider_StaticUi_sliderReleased(); break;
        case 18: _t->on_horizontalSlider_StaticUi_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_horizontalSlider_DynamicUi_sliderReleased(); break;
        case 20: _t->on_horizontalSlider_DynamicUi_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_pushButton_DynamicUpdateSimulatePos_clicked(); break;
        case 22: _t->on_pushButton_StaticExport_clicked(); break;
        case 23: _t->on_pushButton_DynamicExport_clicked(); break;
        case 24: _t->on_horizontalSlider_PixmapWidth_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_spinBox_PixmapWidth_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_horizontalSlider_PixmapHeight_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_spinBox_PixmapHeight_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_checkBox_StaticSend_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_checkBox_DynamicSend_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GY_AnimationSettingUi::*)(QString , QStringList , bool , bool );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationStaticSimulate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QString , QStringList , bool , bool );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicSimulate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QString , QString , bool );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationStaticOnlySimulate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QString , QString , bool );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicOnlySimulate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(int );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationStaticUiSimulateSpeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(int );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicUiSimulateSpeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)();
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicUpdateSimulatePos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QStringList );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationStaticExport; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QStringList );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicExport; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GY_AnimationSettingUi::*)(QPoint );
            if (_t _q_method = &GY_AnimationSettingUi::signalAnimationDynamicPixmapSize; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *GY_AnimationSettingUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GY_AnimationSettingUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGY_AnimationSettingUiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GY_AnimationSettingUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void GY_AnimationSettingUi::signalAnimationStaticSimulate(QString _t1, QStringList _t2, bool _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GY_AnimationSettingUi::signalAnimationDynamicSimulate(QString _t1, QStringList _t2, bool _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GY_AnimationSettingUi::signalAnimationStaticOnlySimulate(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GY_AnimationSettingUi::signalAnimationDynamicOnlySimulate(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GY_AnimationSettingUi::signalAnimationStaticUiSimulateSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GY_AnimationSettingUi::signalAnimationDynamicUiSimulateSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GY_AnimationSettingUi::signalAnimationDynamicUpdateSimulatePos()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GY_AnimationSettingUi::signalAnimationStaticExport(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GY_AnimationSettingUi::signalAnimationDynamicExport(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GY_AnimationSettingUi::signalAnimationDynamicPixmapSize(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
