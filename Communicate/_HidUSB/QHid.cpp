#include "QHid.h"

QHid::QHid(const ushort &vendorId, const ushort &productId):vendorId(vendorId), productId(productId), deviceNowNumber(0), deviceConnectNumber(0)
{
#ifdef Q_OS_MAC
    HidApi = new QHidApi;
#endif
    qDebug() << "当前QHid线程" << QThread::currentThreadId();
    listConnectDevice = new QList<HidDeviceInfo>;
    timerRecvMessage = new QTimer(this);
    connect(timerRecvMessage, &QTimer::timeout, this, &QHid::SlotReadRecvMessage);
    timerRecvMessage->start(10);                //控制持续的读取速度
    if(hid_init()){ qDebug() << "初始化失败"; }
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QHid::SlotCommunicateJudgment);
    timer->start(100);
}

QHid::~QHid(){}


//判断是否有插拔 - 连接/断开
void QHid::SlotCommunicateJudgment()
{
    FindDevicePath();
    if(deviceConnectNumber > deviceNowNumber){
        qDebug() << "------插入设备------"<<QTime::currentTime() << listNewPath.count() << listPath.count();
        isConnectNumber = 5;
        this->OpenDevice();
    }else if(deviceConnectNumber < deviceNowNumber){
        qDebug() << "------拔出设备------"<<QTime::currentTime() << listNewPath.count() << listPath.count();

        this->CloseDevice();
    }
    deviceNowNumber = deviceConnectNumber;
}

//读取返回信息；
void QHid::SlotReadRecvMessage()//所有hid通信
{
    if(listConnectDevice->isEmpty()) return ;    //"error设备返回为空 | 后归档问题库(error:1000)"
    for(int i = 0; i < listConnectDevice->count(); i++){
#ifdef Q_OS_MAC
        QByteArray recvData = HidApi->read(listConnectDevice->at(i).getDeviceHandle(), 50);
        QString data = this->MessageToHex(recvData.replace('\x00',' '));
        if(!recvData.isEmpty()){
            emit signalReadyRead(listConnectDevice->at(i).getDevicePortPath(), data);
        }
#elif defined(Q_OS_WIN)
        unsigned char buf[32 + 5];
        int ret = hid_read(listConnectDevice->at(i).getDeviceHandle(), buf, 32);  //读取到的信息
        if(ret>0){
            QString recvData = this->MessageToHex((QByteArray::fromRawData((char *)buf, 32)).replace('\x00',' '));
            emit signalReadyRead(listConnectDevice->at(i).getDevicePortPath(), recvData);
        }
#endif
    }
}

//寻找设备的端口路径port
void QHid::FindDevicePath()
{
    deviceConnectNumber = 0;
    QStringList listFirstPath;
    struct hid_device_info *device = hid_enumerate(this->vendorId, this->productId);
    listFirstPath = listPath;
    listPath.clear();
    while(device){
        listPath.append(QString(QLatin1String(device->path)));
        device = device->next;
        deviceConnectNumber++;  //有设备连接上了
    }
    if(listFirstPath.size() < listPath.size()){
        listNewPath.clear();
        for(int i = 0; i < listPath.size(); i++){
            if(listFirstPath.indexOf(listPath.at(i)) == -1){
                listNewPath.append(listPath.at(i));
            }
        }
    }
    hid_free_enumeration(hid_enumerate(this->vendorId, this->productId));
}
//打开对应端口设备
void QHid::OpenDevice()
{
    for(int i = 0; i < listNewPath.count(); i++){
#ifdef Q_OS_MAC
        handle = HidApi->open(0, vendorId, productId, " ");
        if(handle){
            HidDeviceInfo deviceInfoAppend;                         //设备信息添加
            deviceInfoAppend.setDeviceHandle(handle);               //设备handle信息
            deviceInfoAppend.setDevicePortPath(listNewPath.at(i));  //设备路径信息
            deviceInfoAppend.setDeviceType(this->GetDeviceType());  //设备类型信息
            deviceInfoAppend.setIsConnectStatus(true);              //设备连接状态信息
            listConnectDevice->append(deviceInfoAppend);            //将设备信息压入链表中
            qDebug() << "ableToOpen_Successful" << listNewPath.at(i) << " handle:" << handle << " - " ;
            QTimer::singleShot(i * 10, [=](){ emit signalConnectionSuccessful(listNewPath.at(i)); });
            continue;
        }else{                                                      //端口打开失败
            qDebug() << "port error;"<<i <<":"<< listNewPath.at(i) << " : " << isConnectNumber;
            if(isConnectNumber < 0){
                return;
            }else{
                isConnectNumber--;
                qDebug() << "---------没连接上-------重新连接------调用次数：" << isConnectNumber;
                this->OpenDevice();

            }
        }
#elif defined(Q_OS_WIN)
        qDebug() << "ableToOpen_Successful" << listNewPath.at(i);
        if(!listNewPath.at(i).contains("mi_01")) continue;
        handle = hid_open_path(listNewPath.at(i).toStdString().c_str());
        if (handle){
            hid_set_nonblocking(handle, 1);                         //非阻塞
            qDebug() << "打开"<< listNewPath.at(i) << " - " << this->productId << " handle：" << handle;
            HidDeviceInfo deviceInfoAppend;                         //设备信息添加
            deviceInfoAppend.setDeviceHandle(handle);               //设备handle信息
            deviceInfoAppend.setDevicePortPath(listNewPath.at(i));  //设备路径信息
            deviceInfoAppend.setDeviceType(this->GetDeviceType());  //设备类型信息
            deviceInfoAppend.setIsConnectStatus(true);              //设备连接状态信息
            listConnectDevice->append(deviceInfoAppend);            //将设备信息压入链表中
            QTimer::singleShot(i * 10, [=](){ emit signalConnectionSuccessful(listNewPath.at(i)); });
        }else{                                                      //端口打开失败
            QThread::msleep(1000);
            qDebug() << "unable to open device|后面该为错误编号" << listNewPath.at(i) << " - " << this->productId;
        }
#endif
    }

}

//关闭拔掉设备
void QHid::CloseDevice()
{
    for(int i = listConnectDevice->size() - 1; i >= 0; i--){
        bool isConnect = 0;
        for(int j = 0; j < listPath.count(); j++){           //现有连接端口列表
            if(listPath.at(j) == listConnectDevice->at(i).getDevicePortPath()){
                isConnect = 1;
                break;
            }
        }
        if(isConnect == 0){
            qDebug() << "关闭端口" << listConnectDevice->at(i).getDevicePortPath();
            emit signalDisconnection(listConnectDevice->at(i).getDevicePortPath()); //返回断开信息，注意先后顺序
#ifdef Q_OS_MAC
            HidApi->close(listConnectDevice->at(i).getDeviceHandle());
#elif defined(Q_OS_WIN)
            hid_close(listConnectDevice->at(i).getDeviceHandle());
#endif
            listConnectDevice->removeAt(i);     //列表中移除此设备
        }
    }
}

#pragma region=========================== 工 具 方 式 类 ================================={
#ifdef Q_OS_MAC //port端口判别写入
bool QHid::WriteHandle(int writeHandle, const QByteArray &data)
{
    if(listConnectDevice->isEmpty()) return false;  //当前无连接设备
    return  HidApi->write(writeHandle, HexToMessage(data));
}
bool QHid::WriteHandleChar(int writeHandle, const QByteArray &data)
{
    if(listConnectDevice->isEmpty()) return false;  //当前无连接设备
    return  HidApi->write(writeHandle, data);
}

#elif defined(Q_OS_WIN)
//port端口判别写入
bool QHid::WriteHandle(hid_device *writeHandle, const QByteArray &data)
{
    if(listConnectDevice->isEmpty()) return false;  //当前无连接设备
    qDebug()<<"WriteHandle"<<writeHandle<<data<<QTime::currentTime();
    QByteArray request = HexToMessage(data);
    unsigned char *buf  = (unsigned char *)request.data();
    return  hid_write(writeHandle, buf, 33);
}

bool QHid::WriteHandleChar(hid_device *writeHandle, const QByteArray &data)
{
    if(listConnectDevice->isEmpty()) return false;  //当前无连接设备
    unsigned char *buf  = (unsigned char *)data.data();
    return  hid_write(writeHandle, buf, 33);
}
#endif

//十进制转信息
QByteArray QHid::HexToMessage(const QString &HexData)
{
    QString message = "00 " + HexData;
    QByteArray data;
    for(int i = 0; i <= message.count(" "); i++){
        data.append(message.section(" ", i, i).toInt(NULL, 16));
    }
    return  data;
}
//信息转十进制
QString QHid::MessageToHex(const QByteArray &Data)
{
    QString hexData = Data.toHex();
    for(int i = 0; i < hexData.length(); i++){
        if(i % 3 == 0){
            hexData.insert(i, " ");
        }
    }
    return  hexData.mid(1);
}
//返回设备类型 *注：当以后再有新设备添加后，则在这里添加新的设备值
enum HidDeviceInfo::DeviceType QHid::GetDeviceType()
{
    switch(this->productId){
    case 0x5750:  return HidDeviceInfo::DeviceType::_HID_KEYBOARD;      break;
    case 0x5850:  return HidDeviceInfo::DeviceType::_HID_MOUSE;         break;
    case 0x5855:  return HidDeviceInfo::DeviceType::_24GHz_Adapter;     break;
    case 0x04D2:  return HidDeviceInfo::DeviceType::_HID_KEYBOARD_60;   break; // _HID_KEYBOARD_60,       //4 0x04D2
    default:
        qDebug() << "------------ 未 知 设 备 类 型 | 后归档问题库(error:1000)-----------";
        break;
    }
    return HidDeviceInfo::DeviceType::_24GHz_KEYBOARD;
}

#pragma endregion}
