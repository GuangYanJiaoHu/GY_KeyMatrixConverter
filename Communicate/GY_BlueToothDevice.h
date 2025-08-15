#ifndef GY_BLUETOOTHDEVICE_H
#define GY_BLUETOOTHDEVICE_H

#include <Communicate/_BluetoothBLE/GY_BleConnect.h>
#include <Communicate/_BluetoothBLE/GY_BleSearch.h>
#include <QObject>
class BlueToothDevice : public QObject
{
    Q_OBJECT
public:
    enum DeviceType{
        KEYBOARD,
        MOUSE
    };

public:
    explicit BlueToothDevice(QObject *parent = nullptr);
    void GY_WriteAllMouseDevice(const QByteArray &data);                                 //鼠标全部设备发送
    void GY_WriteAllKeyboardDevice(const QByteArray &data);                              //键盘全部设备发送
    void GY_WriteToHexAllMouseDevice(const QByteArray &data);                            //鼠标全部设备发送以十六进制写入
    void GY_WriteToHexAllKeyboardDevice(const QByteArray &data);                         //键盘全部设备发送以十六进制写入
    bool GY_WriteMouseUniqueID(const QString &uniqueID, const QByteArray &data);         //鼠标唯一编码判别写入
    bool GY_WriteKeyboardUniqueID(const QString &uniqueID, const QByteArray &data);      //键盘唯一编码判别写入
    bool GY_WriteToHexMouseUniqueID(const QString &uniqueID, const QByteArray &data);    //鼠标唯一编码判别以十六进制写入
    bool GY_WriteToHexKeyboardUniqueID(const QString &uniqueID, const QByteArray &data); //键盘唯一编码判别以十六进制写入
    void start(const int &searchTime = 15000);

signals:
    void sendDeviceConnectInfo(BlueToothDevice::DeviceType type, struct BlueToothInfo bluetoothInfo, struct DeviceInfo deviceInfo);      //发送设备连接后的信息
    void sendDeviceDisconnectInfo(BlueToothDevice::DeviceType type, struct BlueToothInfo bluetoothInfo, struct DeviceInfo deviceInfo);   //发送设备连接后的信息
    void sendBatteryInfomation(BlueToothDevice::DeviceType type, const struct DeviceInfo &deviceInfo);

private slots:
    void slotKeyboardSearchInfo(const QBluetoothDeviceInfo &info);                      //键盘搜索到的信息
    void slotKeyboardSearchFinished(const QList<QBluetoothDeviceInfo> &info_list);      //键盘搜索完成
    void slotMouseSearchInfo(const QBluetoothDeviceInfo &info);                         //鼠标搜索到的信息
    void slotMouseSearchFinished(const QList<QBluetoothDeviceInfo> &info_list);         //鼠标搜索完成
    void slotMouseBatteryInfomation(const struct DeviceInfo &deviceInfo);
    void slotKeyboardBatteryInfomation(const struct DeviceInfo &deviceInfo);

private:
    QList<GY_BleConnect *> listBleMouse;
    QList<GY_BleConnect *> listBleKeyboard;
    GY_BleSearch *bleSearch;
    GY_BleConnect *bleConnect;
    QThread *thradMouseConnect, *thradDeKeyboardConnect;
    QTimer *getBatteryLevel;
};
#endif // GY_BLUETOOTHDEVICE_H
