#ifndef QHID_H
#define QHID_H

#include <Communicate/_HidUSB/HidDeviceInfo.h>
#define VERSION_HID "V1.0.0.1"  //hid版本信息：目前已整合mac与windows，使用过程中尽可能的不要更改QHid种的所有内容，如果需要更改则标注修改内容。

class QHid : public QObject{
    Q_OBJECT
public:
    QHid(const ushort &vendorId, const ushort &productId); //传入productId = 产品ID
    ~QHid();
#ifdef Q_OS_MAC
    bool WriteHandle(int writeHandle, const QByteArray &data);         ////port端口判别写入
    bool WriteHandleChar(int writeHandle, const QByteArray &data);
#elif defined(Q_OS_WIN)
    bool WriteHandle(hid_device *writeHandle, const QByteArray &data);         ////port端口判别写入
    bool WriteHandleChar(hid_device *writeHandle, const QByteArray &data);
#endif
    void CloseDevice();
    enum HidDeviceInfo::DeviceType GetDeviceType();

signals:
    void signalConnectionSuccessful(const QString &portPath);   //设备连接成功
    void signalDisconnection(const QString &portPath);          //设备断开连接
    void signalReadyRead(const QString &portPath, QString &recvData);    //发送读取到的信息

protected:
    QByteArray HexToMessage(const QString &HexData);    //十进制转信息
    QString MessageToHex(const QByteArray &Data);       //信息转十进制
#ifdef Q_OS_MAC
    int handle;
    QHidApi *HidApi;
#elif defined(Q_OS_WIN)
    hid_device *handle;
#endif
    QList<HidDeviceInfo> *listConnectDevice;            //当前连接的设备列表

private:
    void FindDevicePath();          //寻找设备路径
    void OpenDevice();              //打开设备

private slots:
    void SlotCommunicateJudgment(); //是否有设备连接主机
    void SlotReadRecvMessage();     //读取返回信息；

private:
    int isConnectNumber = 5;
    uint vendorId, productId;
    QTimer *timerRecvMessage;
    int  deviceNowNumber, deviceConnectNumber;  //1、设备当前数量 -  2设备连接数量
    QStringList listPath, listNewPath;
};

#endif // QHID_H
