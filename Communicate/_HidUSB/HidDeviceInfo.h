#ifndef HIDDEVICEINFO_H
#define HIDDEVICEINFO_H

#include <QObject>
#include "hidapi.h"
#include <QLatin1String>
#include <QApplication>
#include <QByteArray>
#include <QSettings>
#include <QIODevice>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QFile>
#define MAX_STR 255
#include <QCoreApplication>
#include <QWidget>
#include "qhidapi.h"
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QTimer>
#include <QLatin1String>
#include <QTime>
#include <QMessageBox>
#include <QThread>
#include <QSettings>
#include <QFile>
#include <QIODevice>

#if defined(Q_OS_WIN32)
#include <windows.h>
#include <Tlhelp32.h>
#include <dbt.h>
#include <devguid.h>
#include <SetupAPI.h>
#include <InitGuid.h>
#endif

#define VERSION "1.0.0.18"

class HidDeviceInfo{
public:
    enum DeviceType{
        _HID_KEYBOARD,          //0 0x5750
        _HID_KEYBOARD_JIAN0,    //1 0x5750
        _HID_MOUSE,             //2 0x5850
        _HID_KEYPAD,            //3 0x5750
        _HID_KEYBOARD_60,       //4 0x04D2

        _24GHz_Adapter,         //5 适配器 0x5855
        _24GHz_KEYBOARD,        //6 FE 指令
        _24GHz_MOUSE            //7 FD 指令
    };

#ifdef Q_OS_MAC
    int getDeviceHandle() const;
    void setDeviceHandle(int newDeviceHandle);
#elif defined(Q_OS_WIN)
    hid_device *getDeviceHandle() const;
    void setDeviceHandle(hid_device *newDeviceHandle);
#endif
    const QString &getDevicePortPath() const;
    void setDevicePortPath(const QString &newDevicePortPath);

    const QString &getDeviceUniqueID() const;
    void setDeviceUniqueID(const QString &newDeviceUniqueID);

    const QString &getDeviceID() const;
    void setDeviceID(const QString &newDeviceID);

    const QString &getDeviceCheckStep() const;
    void setDeviceCheckStep(const QString &newDeviceCheckStep);

    const QString &getDeviceDfuVersion() const;
    void setDeviceDfuVersion(const QString &newDeviceDfuVersion);

    const QString &getDeviceProductTime() const;
    void setDeviceProductTime(const QString &newDeviceProductTime);

    const QString &getDeviceBatchNumber() const;
    void setDeviceBatchNumber(const QString &newDeviceBatchNumber);

    const QString &getDeviceColor() const;
    void setDeviceColor(const QString &newDeviceColor);

    const QString &getDeviceManufacturer() const;
    void setDeviceManufacturer(const QString &newDeviceManufacturer);

    const QString &getDeviceBatteryLevel() const;
    void setDeviceBatteryLevel(const QString &newDeviceBatteryLevel);

    enum DeviceType getDeviceType() const;
    void setDeviceType(enum DeviceType newDeviceType);

    const QString &getDeviceName() const;
    void setDeviceName(const QString &newDeviceName);

    bool getDeviceChargingState() const;
    void setDeviceChargingState(const bool &newDeviceChargingState);

    bool getIsConnectStatus() const;
    void setIsConnectStatus(const bool &newIsConnectStatus);

private:

#ifdef Q_OS_MAC
    int DeviceHandle;           //Mac端口句柄
#elif defined(Q_OS_WIN)
    hid_device *DeviceHandle;   //端口句柄
#endif
    QString DeviceID;           //设备ID
    QString DeviceName;         //名字+DFU版本号
    QString DeviceColor;        //设备颜色
    QString DevicePortPath;     //端口路径 - 端口号
    QString DeviceUniqueID;     //唯一编码
    QString DeviceCheckStep;    //检测步骤
    QString DeviceDfuVersion;   //DFU版本号
    QString DeviceProductTime;  //出场时间
    QString DeviceBatchNumber;  //批次号
    QString DeviceManufacturer; //生产厂家
    QString DeviceBatteryLevel; //电池电量
    enum DeviceType deviceType; //设备类型
    bool DeviceChargingState=0; //充电状态
    bool IsConnectStatus = 0;   //连接状态 初始状态为false
};
#endif // HIDDEVICEINFO_H
