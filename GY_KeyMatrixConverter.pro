QT       += core gui  sql bluetooth  network concurrent


QMAKE_CXXFLAGS += -Wno-unknown-pragmas
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Communicate/GY_24GHz.cpp \                      #hid        公用文件
    Communicate/GY_BlueToothDevice.cpp \            #bluetooth  公用文件
    Communicate/GY_Communicate.cpp \                #hid        公用文件
    Communicate/GY_HIDKeyboard.cpp \                #hid        公用文件
    Communicate/GY_HIDMouse.cpp \                   #hid        公用文件
    Communicate/_BluetoothBLE/GY_BleConnect.cpp \   #bluetooth  公用文件
    Communicate/_BluetoothBLE/GY_BleSearch.cpp \    #bluetooth  公用文件
    Communicate/_HidUSB/HidDeviceInfo.cpp \         #hid        公用文件
    Communicate/_HidUSB/QHid.cpp \                  #hid        公用文件
    GY_FunctionUi/GY_AnimationCustomize.cpp \
    GY_FunctionUi/GY_AnimationSettingUi.cpp \
    GY_FunctionUi/GY_ConvertBinFile.cpp \
    GY_FunctionUi/GY_Generate/GY_ReadFile.cpp \
    GY_FunctionUi/GY_GenerateBinFile.cpp \
    GY_FunctionUi/GY_KeyboardSettingUi.cpp \
    GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.cpp \
    GY_Tools/GY_KeyboardTools.cpp \
    GY_Tools/WindowsHook/GY_KeyboardHook.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Communicate/GY_24GHz.h \                        #hid        公用文件
    Communicate/GY_BlueToothDevice.h \              #bluetooth  公用文件
    Communicate/GY_Communicate.h \                  #hid        公用文件
    Communicate/GY_HIDKeyboard.h \                  #hid        公用文件
    Communicate/GY_HIDMouse.h \                     #hid        公用文件
    Communicate/_BluetoothBLE/GY_BleConnect.h \     #bluetooth  公用文件
    Communicate/_BluetoothBLE/GY_BleSearch.h \      #bluetooth  公用文件
    Communicate/_HidUSB/HidDeviceInfo.h \           #hid        公用文件
    Communicate/_HidUSB/qhiddeviceinfo.h \          #hid        公用文件
    Communicate/_HidUSB/QHid.h \                    #hid        公用文件
    GY_FunctionUi/GY_AnimationCustomize.h \
    GY_FunctionUi/GY_AnimationSettingUi.h \
    GY_FunctionUi/GY_ConvertBinFile.h \
    GY_FunctionUi/GY_Generate/GY_ReadFile.h \
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


#windows中的头文件 切记 *以后如果有单独windows适配的内容要单独引用，不能公共防止，防止文件夹重复以及，文件冗余
win32{
SOURCES +=  \
    Communicate/_HidUSB/hidWindows.c \  #WINDOWS_hid

HEADERS += \
    Communicate/_HidUSB/hidapi.h \      #WINDOWS_hid
    LIBS += -lhid
    LIBS += -lsetupapi
    LIBS += -lDbgHelp
    LIBS += -luser32                    #windows函数库
}

# #MAC中的头文件 切记 *以后如果有单独MAC适配的内容要单独引用，不能公共防止，防止文件夹重复以及，文件冗余
# macx{
# SOURCES +=  \
#     Communicate/_HidUSB/hidMac.c \          #MAC_hid
#     Communicate/_HidUSB/qhidapi.cpp \       #MAC_hid
#     Communicate/_HidUSB/qhidapi_p.cpp \     #MAC_hid

# HEADERS += \
#     Communicate/_HidUSB/qhidapi.h \         #MAC_hid
#     Communicate/_HidUSB/qhidapi_global.h \  #MAC_hid
#     Communicate/_HidUSB/qhidapi_p.h \       #MAC_hid

# macos: QMAKE_INFO_PLIST = Info.qmake.macos.plist    #需要添加一些权限 才能使用蓝牙


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
