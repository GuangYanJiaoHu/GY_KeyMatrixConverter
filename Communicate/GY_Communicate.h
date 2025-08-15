#ifndef GY_COMMUNICATE_H
#define GY_COMMUNICATE_H

#include <Communicate/GY_BlueToothDevice.h>
#include <Communicate/GY_HIDKeyboard.h>
#include <Communicate/GY_HIDMouse.h>
#include <Communicate/GY_24GHz.h>
#include <QObject>
#include <QPair>
enum DeviceType{            //设备类型              *注：当这里设备适当添加后 如若涉及2.4与hid都应到hiddeviceinfo类中进行枚举值的添加
    _HID_KEYBOARD,          //0 0x5750 (新键盘)
    _HID_KEYBOARD_JIAN0,    //1 0x5750 (旧键盘)
    _HID_MOUSE,             //2 0x5850
    _HID_KEYPAD,            //3
    _HID_KEYBOARD_60,       //4 0x04D2

    _24GHz_Adapter,         //4 适配器 0x5855
    _24GHz_KEYBOARD,        //5 FE 指令
    _24GHz_MOUSE,           //6 FD 指令

    _BLUE_KEYBOARD,         //7 蓝牙键盘
    _BLUE_MOUSE             //8 蓝牙鼠标
};

enum ConnectType{   //设备连接方式
    _BLUETOOTH,     //0 蓝牙无限连接
    _24GHz,         //1 2.4G无限连接
    _HID,           //2 HID有线连接
    _Adapter        //3 适配器
};

struct Device{
#ifdef Q_OS_MAC
    int DeviceHandle;           //Mac端口句柄
#elif defined(Q_OS_WIN)
    hid_device *DeviceHandle;   //端口句柄
#endif
    QString DeviceID;           //设备ID
    QString DeviceName;         //名字+DFU版本号
    QString BleAddress;         //蓝牙地址 [仅蓝牙]
    QString DeviceColor;        //设备颜色
    QString DevicePortPath;     //端口路径 - 端口号
    QString DeviceUniqueID;     //唯一编码
    QString DeviceCheckStep;    //检测步骤
    QString DeviceDfuVersion;   //DFU版本号
    QString DeviceProductTime;  //出场时间
    QString DeviceBatchNumber;  //批次号
    QString DeviceManufacturer; //生产厂家
    QString DeviceBatteryLevel; //电池电量
    DeviceType DeviceType;      //设备类型
    ConnectType ConnectType;    //设备连接方式
    bool DeviceChargingState;   //充电状态
    bool IsConnectStatus = 0;   //连接状态 初始状态为false
    int warm = 50;              //白平衡
    int red = 50;
};

class GY_Communicate : public QObject
{
    Q_OBJECT
public:
    explicit GY_Communicate(QObject *parent = nullptr);
    bool Write(const QString &portPath, const QString &data);    //根据唯一编码写入数据
    bool WriteAllKeyboard(const QString &data);                 //给全部的键盘写
    bool WriteAllKeyboardColorSend(const QString &data);              //刷表专用
    bool WriteAdatper(const QString &data);                     //给全部的适配器写
    bool WriteAllMouse(const QString &data);                    //给全部的鼠标写
    bool WriteCharFiltration(char arry[][33], const int groupCount ,const bool filtration = false);//给全部的键盘写
    bool GY_write_array(char arry[][33], const int groupCount ,const int device_type); //主要为了处理小键盘的信息发送
    int getAdapterNumber();
    void receiverOpenClose(bool isOpen);
    void receiverClear();

public slots:
    void slotAnimationStaticSimulate(QList<QString> listColor);     //下发颜色数据 - 静态 给键盘模拟
    void slotAnimationDynamicSimulate(QList<QString> listColor);    //下发颜色数据 - 动态 给键盘模拟
    void soltKeyboardSettingBrightness(QString lightHex);           //键盘灯光亮度调节
    void soltKeyboardSettingSendData(QString data);                 //键盘指令发送


private:
    Device getListDeviceInfo(const HidDeviceInfo &DeviceInfo, const DeviceType &DeviceType, const ConnectType &ConnectType);                         //获取list的设备信息，将其返回
    Device getListBlueDeviceInfo(BlueToothInfo bluetoothInfo, DeviceInfo deviceInfo, const DeviceType &DeviceType, const ConnectType &ConnectType);  //获取list的设备信息，将其返回
    QList<Device> getDeviceList();
    QPair<int, int> readWhiteBalance(int listDevice);
    QString zero_fill(QString data);

signals:
    void signalsDeviceConnect(const Device &listDevice);     //有设备连接了
    void signalsDeviceDisconnect(const Device &listDevice);  //有设备断开了
    void signalsDeviceBattery(const QString &portPath, const QString &battery, const bool &batteryChange, enum HidDeviceInfo::DeviceType deviceType);

    //测试
    void signalsAdapterConnect1(const int &DeviceNumber, const QString &portPath);
    void signalsAdapterDisconnect1(const int &DeviceNumber, const QString &portPath);
    //结束
    void signals24GHzKeyboardOrMouseConnected(bool isKeyboard, bool isMouse); //2.4G键盘已连接，给前端界面专用，不参与其他逻辑功能

private slots:
    void slots24GHzConnect(const HidDeviceInfo &deviceInfo, enum HidDeviceInfo::DeviceType deviceType);
    void slots24GHzDisconnect(const QString &portPath, enum HidDeviceInfo::DeviceType deviceType);

    void slotsKeyboardConnect(const HidDeviceInfo &DeviceInfo);     //键盘链接成功
    void slotsKeyboardDisconnect(const QString &portPath);          //键盘断开连接
    void slotsMouseConnect(const HidDeviceInfo &DeviceInfo);        //鼠标连接成功
    void slotsMouseDisconnect(const QString &portPath);             //鼠标断开连接

    void slotsBatteryInfomation(BlueToothDevice::DeviceType type, struct DeviceInfo deviceInfo);                                        //蓝牙电量信息获取
    void slotsDeviceConnectInfo(BlueToothDevice::DeviceType type, struct BlueToothInfo bluetoothInfo, struct DeviceInfo deviceInfo);    //蓝牙设备连接成功
    void slotsDeviceDisconnectInfo(BlueToothDevice::DeviceType type, struct BlueToothInfo bluetoothInfo, struct DeviceInfo deviceInfo); //蓝牙设备断开连接

private:
    BlueToothDevice *blueToothDevice;   //蓝牙设备
    GY_HIDKeyboard *keyboard;           //键盘设备
    GY_HIDMouse *Mouse;                 //鼠标设备
    GY_24GHz *Adapter;                  //适配器设备
    QList<Device> listDevice;
    HidDeviceInfo deviceAdapter;   //适配器连接
    QList<HidDeviceInfo> listDeviceAdapter;
    HidDeviceInfo device24GHzKeyboard;   //适配器连接
    HidDeviceInfo device24GHzMouse;   //适配器连接
    int adapterNumber = 0;
    QString TAG = "GY_Communicate";
};



#endif // GY_COMMUNICATE_H
