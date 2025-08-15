#ifndef GY_BLECONNECT_H
#define GY_BLECONNECT_H

#include <QLowEnergyCharacteristic>
#include <QLowEnergyController>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyService>
#include <QBluetoothAddress>
#include <QBluetoothUuid>
#include <QStringList>
#include <QThread>
#include <QObject>
#include <QTimer>

#define _UuidKeyboardBattry_ "{0000180f-0000-1000-8000-00805f9b34fb}"    //键盘电量uuid
#define _UuidKeyboardWrite_  "{6e400001-b5a3-f393-e0a9-e50e24dcca9e}"    //键盘可写uuid
#define _UuidMouseBattry_    "{0000180f-0000-1000-8000-00805f9b34fb}"    //鼠标电量uuid
#define _UuidMouseWrite_     "{6e400001-b5a3-f393-e0a9-e50e24dcca9e}"    //鼠标可写uuid
#define _SuccessConnection_  "|==++*^@~C#O$N#N$E#C$T#I$O#N~@^*++==|"     //成功连接报文判断

//蓝牙信息
struct BlueToothInfo{
    bool isValid;                 //传入的info信息的内容是否有效
    bool isCached;                //QBluetoothDeviceInfo对象是否是基于缓存数据创建的
    bool isConnectState;          //蓝牙的连接状态
    QString getName;              //获取蓝牙名称
    QString getMacAddress;        //获取苹果MAC蓝牙地址
    QString getWindowsAddress;    //获取windows蓝牙地址
    QList<QBluetoothUuid> getUuid;//获取蓝牙的uuid面前提是要连接上以后才可以查出来
};
//设备信息
struct DeviceInfo{
    QString getDfuVersion;        //DFU版本号
    QString getDeviceColor;       //设备颜色
    QString getProductTime;       //出场时间
    QString getManufacturer;      //生产厂家
    QString getBatchNumber;       //批次号
    QString getUniqueID;          //唯一编码
    QString getCheckStep;         //检测步骤
    QString getDeviceID;          //设备ID
    QString getBatteryLevel;      //电池电量
    QString getNameAndVersion;    //名字+DFU版本号
    bool getChargingState;        //充电状态

    int warm = 50;              //白平衡
    int red = 50;
};

class GY_BleConnect : public QObject
{
    Q_OBJECT
public:
    explicit GY_BleConnect(QObject *parent = nullptr);
    ~GY_BleConnect();
    struct DeviceInfo    getDeviceAllInfo();    //获取设备全部信息
    struct BlueToothInfo getBluetoothInfo();    //获取全部蓝牙的信息
    void GY_Reconnection();                     //重新连接蓝牙
    void setDisconnectController();             //设置断开控制器

public slots:
    void setBluetoothDeviceInfo(const QBluetoothDeviceInfo &info);//设置bluetooth的连接信息
    bool slotWrite(const QByteArray &data);     //QByteArray类型写入
    bool slotWriteToHex(const QByteArray &data);//QByteArray类型写入

signals:
    void sendConnectionStatus(const bool &isConnect, const struct BlueToothInfo &bluetoothInfo);//蓝牙连接成功
    void sendBatteryInfomation(const struct DeviceInfo &deviceInfo);
    void sendWrite(const QByteArray &data);     //QByteArray类型写入
    void sendWriteToHex(const QByteArray &data);//QByteArray类型写入

private slots:
    void slotControllerConnectSuccess();                                    //控制器连接成功
    void slotControllerError(QLowEnergyController::Error error);            //连接控制器失败报错
    void slotControllerDiscover(const QBluetoothUuid &newService);          //连接获取所有UUID,获取uuid
    void slotServiceError(QLowEnergyService::ServiceError error);           //服务端发生错误连接
    void slotServiceStateChanged(QLowEnergyService::ServiceState newState); //判断服务状态
    void slotServiceCharacteristicWritten(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);//蓝牙服务特性读取写入信息
    void slotServiceCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);//蓝牙服务特性读取写入信息

private:
    QBluetoothDeviceInfo bluetoothInfomation;
    struct DeviceInfo    DeviceAllInfo;              //设备信息
    struct BlueToothInfo BluetoothInfo;              //保存全部蓝牙信息
    QLowEnergyController *lowEnergyController;       //创建控制器
    QLowEnergyService    *lowEnergyService;          //低耗蓝牙服务
    QLowEnergyCharacteristic lowEnergyCharacteristic;//可以写的Characteristic 通信写入数据
    QLowEnergyCharacteristic lowCharacteristicWrite; //可以写的Characteristic 通信写入数据
};

#endif // GY_BLECONNECT_H
