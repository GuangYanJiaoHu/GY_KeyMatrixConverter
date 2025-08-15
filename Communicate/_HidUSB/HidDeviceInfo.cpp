#include "HidDeviceInfo.h"

#ifdef Q_OS_MAC
int HidDeviceInfo::getDeviceHandle() const
{
    return DeviceHandle;
}

void HidDeviceInfo::setDeviceHandle(int newDeviceHandle)
{
    DeviceHandle = newDeviceHandle;
}
#elif defined(Q_OS_WIN)
hid_device *HidDeviceInfo::getDeviceHandle() const
{
    return DeviceHandle;
}

void HidDeviceInfo::setDeviceHandle(hid_device *newDeviceHandle)
{
    DeviceHandle = newDeviceHandle;
}
#endif

const QString &HidDeviceInfo::getDevicePortPath() const
{
    return DevicePortPath;
}

void HidDeviceInfo::setDevicePortPath(const QString &newDevicePortPath)
{
    DevicePortPath = newDevicePortPath;
}

const QString &HidDeviceInfo::getDeviceUniqueID() const
{
    return DeviceUniqueID;
}

void HidDeviceInfo::setDeviceUniqueID(const QString &newDeviceUniqueID)
{
    DeviceUniqueID = newDeviceUniqueID;
}

const QString &HidDeviceInfo::getDeviceID() const
{
    return DeviceID;
}

void HidDeviceInfo::setDeviceID(const QString &newDeviceID)
{
    DeviceID = newDeviceID;
}

const QString &HidDeviceInfo::getDeviceCheckStep() const
{
    return DeviceCheckStep;
}

void HidDeviceInfo::setDeviceCheckStep(const QString &newDeviceCheckStep)
{
    DeviceCheckStep = newDeviceCheckStep;
}

const QString &HidDeviceInfo::getDeviceDfuVersion() const
{
    return DeviceDfuVersion;
}

void HidDeviceInfo::setDeviceDfuVersion(const QString &newDeviceDfuVersion)
{
    DeviceDfuVersion = newDeviceDfuVersion;
}

const QString &HidDeviceInfo::getDeviceProductTime() const
{
    return DeviceProductTime;
}

void HidDeviceInfo::setDeviceProductTime(const QString &newDeviceProductTime)
{
    DeviceProductTime = newDeviceProductTime;
}

const QString &HidDeviceInfo::getDeviceBatchNumber() const
{
    return DeviceBatchNumber;
}

void HidDeviceInfo::setDeviceBatchNumber(const QString &newDeviceBatchNumber)
{
    DeviceBatchNumber = newDeviceBatchNumber;
}

const QString &HidDeviceInfo::getDeviceColor() const
{
    return DeviceColor;
}

void HidDeviceInfo::setDeviceColor(const QString &newDeviceColor)
{
    this->DeviceColor = newDeviceColor;
}

const QString &HidDeviceInfo::getDeviceManufacturer() const
{
    return DeviceManufacturer;
}

void HidDeviceInfo::setDeviceManufacturer(const QString &newDeviceManufacturer)
{
    DeviceManufacturer = newDeviceManufacturer;
}

const QString &HidDeviceInfo::getDeviceBatteryLevel() const
{
    return DeviceBatteryLevel;
}

void HidDeviceInfo::setDeviceBatteryLevel(const QString &newDeviceBatteryLevel)
{
    DeviceBatteryLevel = newDeviceBatteryLevel;
}

enum HidDeviceInfo::DeviceType HidDeviceInfo::getDeviceType() const
{
    return deviceType;
}

void HidDeviceInfo::setDeviceType(enum DeviceType newDeviceType)
{
    deviceType = newDeviceType;
}

const QString &HidDeviceInfo::getDeviceName() const
{
    return DeviceName;
}

void HidDeviceInfo::setDeviceName(const QString &newDeviceName)
{
    DeviceName = newDeviceName;
}

bool HidDeviceInfo::getDeviceChargingState() const
{
    return DeviceChargingState;
}

void HidDeviceInfo::setDeviceChargingState(const bool &newDeviceChargingState)
{
    DeviceChargingState = newDeviceChargingState;
}

bool HidDeviceInfo::getIsConnectStatus() const
{
    return IsConnectStatus;
}

void HidDeviceInfo::setIsConnectStatus(const bool &newIsConnectStatus)
{
    IsConnectStatus = newIsConnectStatus;
}

