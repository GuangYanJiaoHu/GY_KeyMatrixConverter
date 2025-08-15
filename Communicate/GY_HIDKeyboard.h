#ifndef GY_HIDKEYBOARD_H
#define GY_HIDKEYBOARD_H

#include <Communicate/_HidUSB/QHid.h>
#include <QObject>

class GY_HIDKeyboard : public QHid
{
    Q_OBJECT
public:
    GY_HIDKeyboard(const ushort &vendorId, const ushort &productId):QHid(vendorId, productId){
        connect(this, &QHid::signalConnectionSuccessful,this, &GY_HIDKeyboard::slotsKeyboardConnect);
        connect(this, &QHid::signalDisconnection, this, &GY_HIDKeyboard::signalKeyboardDisconnection);
        connect(this, &QHid::signalReadyRead, this, &GY_HIDKeyboard::slotReadyRead);

        timerBattery = new QTimer(this);
        connect(timerBattery, &QTimer::timeout,this,[=](){
            for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
                this->WriteHandle(item->getDeviceHandle(), QByteArray("FE F6"));
            }
        });
    }
    void GetDeviceReadMessage(const QString &portPath); //获取读到的信息
    QList<HidDeviceInfo> *getListConnectDevice();
    bool Write(const QString &portPath, const QString &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_HID_KEYBOARD);
    bool Write(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_HID_KEYBOARD);
    bool Write(const QString &portPath, const QStringList &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_HID_KEYBOARD);
    bool WriteChar(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_HID_KEYBOARD);

signals:
    void signalBatteryChange(const QString &portPath, const QString &battery, const bool &batteryChange, enum HidDeviceInfo::DeviceType deviceType);
    void signalKeyboardConnection(const HidDeviceInfo &deviceInfo);
    void signalKeyboardDisconnection(const QString &portPath);

private slots:
    void slotReadyRead(const QString &portPath, QString &recvData);  //读取数据 hid_device *Handle,
    void slotsKeyboardConnect(const QString &portPath);     //键盘链接成功

private:
    void setDeviceMessage(const QString &portPath, const QString &Data, const QString &order, enum HidDeviceInfo::DeviceType deviceType);

private:
    QTimer *timerBattery;

};

#endif // GY_HIDKEYBOARD_H
