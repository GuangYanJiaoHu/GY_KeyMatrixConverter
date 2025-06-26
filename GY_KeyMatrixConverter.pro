QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GY_FunctionUi/GY_AnimationCustomize.cpp \
    GY_FunctionUi/GY_AnimationSettingUi.cpp \
    GY_FunctionUi/GY_ConvertBinFile.cpp \
    GY_FunctionUi/GY_GenerateBinFile.cpp \
    GY_FunctionUi/GY_KeyboardSettingUi.cpp \
    GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.cpp \
    GY_Tools/GY_KeyboardTools.cpp \
    GY_Tools/WindowsHook/GY_KeyboardHook.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GY_FunctionUi/GY_AnimationCustomize.h \
    GY_FunctionUi/GY_AnimationSettingUi.h \
    GY_FunctionUi/GY_ConvertBinFile.h \
    GY_FunctionUi/GY_GenerateBinFile.h \
    GY_FunctionUi/GY_KeyboardSettingUi.h \
    GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.h \
    GY_Tools/GY_KeyboardTools.h \
    GY_Tools/WindowsHook/GY_KeyboardHook.h \
    mainwindow.h

FORMS += \
    GY_FunctionUi/GY_AnimationCustomize.ui \
    GY_FunctionUi/GY_AnimationSettingUi.ui \
    GY_FunctionUi/GY_ConvertBinFile.ui \
    GY_FunctionUi/GY_GenerateBinFile.ui \
    GY_FunctionUi/GY_KeyboardSettingUi.ui \
    GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
