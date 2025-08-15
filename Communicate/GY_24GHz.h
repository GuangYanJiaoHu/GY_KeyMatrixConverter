#ifndef GY_24GHZ_H
#define GY_24GHZ_H

#include <Communicate/_HidUSb/QHid.h>
#include <QObject>


#define _TIME_MOUSE     10000
#define _TIME_KEYBOARD  10000

class GY_24GHz : public QHid
{
    Q_OBJECT
public:
    GY_24GHz(const ushort &vendorId, const ushort &productId):QHid(vendorId, productId){
        connect(this, &QHid::signalConnectionSuccessful,this, &GY_24GHz::slotsAdapterConnect);
        connect(this, &QHid::signalDisconnection, this, &GY_24GHz::slotsAdapterDisconnect);
        connect(this, &QHid::signalReadyRead, this, &GY_24GHz::slotReadyRead);

        listMouseConnect = new QList<HidDeviceInfo>;
        listKeyboardConnect = new QList<HidDeviceInfo>;
        timerMouseBattery = new QTimer(this);
        connect(timerMouseBattery, &QTimer::timeout, this, &::GY_24GHz::slotGet_24GHzMouseBattery);
        timerKeyboardBattery = new QTimer(this);
        connect(timerKeyboardBattery, &QTimer::timeout, this, &GY_24GHz::slotGet_24GHzKeyboardBattery);
    }
    void GetDeviceReadMessage(const QString &portPath); //获取读到的信息
    QList<HidDeviceInfo> *getListConnectDevice();
    void Write(const QString &data);
    bool Write(const QString &portPath, const QString &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_24GHz_Adapter);
    bool Write(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_24GHz_Adapter);
    bool Write(const QString &portPath, const QStringList &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_24GHz_Adapter);
    bool WriteChar(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType = HidDeviceInfo::_24GHz_Adapter);

signals:
    void signal24GHzConnection(const HidDeviceInfo &deviceInfo, enum HidDeviceInfo::DeviceType deviceType);
    void signal24GHzDisconnection(const QString &portPath, enum HidDeviceInfo::DeviceType deviceType);
    void signal24GHzBattery(const QString &portPath, const QString &battery, const bool &batteryChange, enum HidDeviceInfo::DeviceType deviceType); //电量返回信号

    void signal24GHzKeyboardOrMouseConnected(bool isKeyboard, bool isMouse);                                    //2.4G键盘已连接，给前端界面专用，不参与其他逻辑功能
    void signal24_MouseBattery(const QString &portPath, const QString &battery, const bool &batteryChange);     //适配器电量返回
    void signal24_KeyboardBattery(const QString &portPath, const QString &battery, const bool &batteryChange);  //适配器电量返回

private:
    void setDeviceMessage(const QString &portPath, const QString &Data, const QString &order, enum HidDeviceInfo::DeviceType deviceType);

private slots:
    void slotReadyRead(const QString &portPath, QString &recvData);                  //读取数据 hid_device *Handle,
    void GetDeviceMouseOrKeyboard(const QString &portPath, const QString &readData); //获取设备类型
    void _24GHzMouseConnect(const QString &portPath );                               //2.4G鼠标连接成功
    void _24GHzKeyboardConnect(const QString &portPath);                             //2.4G键盘连接成功
    void slotsAdapterConnect(const QString &portPath);                               //适配器连接成功
    void slotsAdapterDisconnect(const QString &portPath);                            //适配器断开连接
    void slotGet_24GHzMouseBattery();
    void slotGet_24GHzKeyboardBattery();


private:
    QTimer *timerMouseBattery, *timerKeyboardBattery;
    QTimer *timerMouseconnect, *timerKeyboardconnect;
    QString _24GHz_port_path;
    bool mouse_connect_static=false,keyboard_connect_static=false;
    bool isMouseConnect = false, isKeyboardConnect = false;
    QList<HidDeviceInfo> *listMouseConnect;     //当前鼠标连接的设备列表
    QList<HidDeviceInfo> *listKeyboardConnect;  //当前鼠标连接的设备列表

};


#endif // GY_24GHZ_H
