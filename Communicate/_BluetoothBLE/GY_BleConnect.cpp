#include "GY_BleConnect.h"

GY_BleConnect::GY_BleConnect(QObject *parent): QObject{parent}{}
GY_BleConnect::~GY_BleConnect(){}

//设置bluetooth的连接信息,并将所需内容全部获取
void GY_BleConnect::setBluetoothDeviceInfo(const QBluetoothDeviceInfo &info)
{
    qDebug() << "Bluetooth连接线程-Connect:" << QThread::currentThreadId();
    BluetoothInfo.getName = info.name();
    BluetoothInfo.getUuid = info.serviceUuids();
    BluetoothInfo.isValid = info.isValid();
    BluetoothInfo.isCached = info.isCached();
    BluetoothInfo.getMacAddress = info.deviceUuid().toString();
    BluetoothInfo.getWindowsAddress = info.address().toString();
    BluetoothInfo.isConnectState = false;
    bluetoothInfomation = info;
    lowEnergyController = QLowEnergyController::createCentral(bluetoothInfomation); //创建蓝牙控制器
    connect(lowEnergyController, &QLowEnergyController::connected, this, &GY_BleConnect::slotControllerConnectSuccess);             //连接控制器成功后进入
    connect(lowEnergyController, &QLowEnergyController::errorOccurred,this, &GY_BleConnect::slotControllerError);                   //连接控制器失败报错
    connect(lowEnergyController, &QLowEnergyController::serviceDiscovered, this, &GY_BleConnect::slotControllerDiscover);           //连接获取所有UUID,获取uuid
    lowEnergyController->connectToDevice();//连接
}

//重新连接蓝牙
void GY_BleConnect::GY_Reconnection()
{
    if( BluetoothInfo.isConnectState){
        lowEnergyController->disconnectFromDevice();
        lowEnergyController->connectToDevice();
    }else{
        lowEnergyController->connectToDevice();
    }
}
//设置断开控制器
void GY_BleConnect::setDisconnectController()
{
    qDebug() << "当前连接状态-这里有问题：" << BluetoothInfo.isConnectState;
    if( BluetoothInfo.isConnectState){
        lowEnergyController->disconnectFromDevice();
    }
}
//QByteArray类型写入      //qDebug() << "蓝牙写入函数 -QByteArray- 线程: " << QThread::currentThreadId();
bool GY_BleConnect::slotWrite(const QByteArray &data)
{
    if(! BluetoothInfo.isConnectState) return false;
    lowEnergyService->writeCharacteristic(lowCharacteristicWrite, data, QLowEnergyService::WriteWithResponse);
    QThread::msleep(10);
    return true;
}
//QByteArray类型写入     //qDebug() << "蓝牙写入函数 -QByteArray - HEX 线程: " << QThread::currentThreadId();
bool GY_BleConnect::slotWriteToHex(const QByteArray &data)
{
    if(! BluetoothInfo.isConnectState) return false;
    lowEnergyService->writeCharacteristic(lowCharacteristicWrite, QByteArray::fromHex(data), QLowEnergyService::WriteWithResponse);
    QThread::msleep(10);
    return true;
}

struct BlueToothInfo GY_BleConnect::getBluetoothInfo()
{
    return BluetoothInfo;
}

struct DeviceInfo GY_BleConnect::getDeviceAllInfo()
{
    return DeviceAllInfo;
}

#pragma region 控制器槽函数 | 服务器槽函数 {
//连接控制器成功后进入
void GY_BleConnect::slotControllerConnectSuccess()
{
    lowEnergyController->discoverServices();    //控制器连接成功，进入下一阶段;
}
//连接控制器失败报错
void GY_BleConnect::slotControllerError(QLowEnergyController::Error error)
{
    switch(error){
    case QLowEnergyController::NoError:                     break;
    case QLowEnergyController::UnknownError:                break;
    case QLowEnergyController::UnknownRemoteDeviceError:    break;
    case QLowEnergyController::NetworkError:                break;
    case QLowEnergyController::InvalidBluetoothAdapterError:break;
    case QLowEnergyController::ConnectionError:             break;
    case QLowEnergyController::AdvertisingError:            break;
    case QLowEnergyController::RemoteHostClosedError:       break;
    case QLowEnergyController::AuthorizationError:          break;
    default: break;
    }
    qDebug()<<"---控制器状态-----"<<lowEnergyController->state();
}
//连接获取所有UUID,获取uuid
void GY_BleConnect::slotControllerDiscover(const QBluetoothUuid &newService)
{
    if(newService == QBluetoothUuid(_UuidKeyboardWrite_)){
        lowEnergyService = lowEnergyController->createServiceObject(newService,this);                                               //赋值转换
        connect(lowEnergyService, &QLowEnergyService::errorOccurred, this, &GY_BleConnect::slotServiceError);
        connect(lowEnergyService, &QLowEnergyService::stateChanged,  this, &GY_BleConnect::slotServiceStateChanged);                //判断服务状态
        connect(lowEnergyService, &QLowEnergyService::characteristicWritten, this, &GY_BleConnect::slotServiceCharacteristicWritten); //蓝牙服务特性读取写入信息
        connect(lowEnergyService, &QLowEnergyService::characteristicChanged, this, &GY_BleConnect::slotServiceCharacteristicChanged);
        if(lowEnergyService){
            QTimer::singleShot(600,this,[=]{lowEnergyService->discoverDetails();}); //连接速度太快会导致连接不上的情况发生目前现在550毫秒为最低连接状态
        }
    }
}

void GY_BleConnect::slotServiceError(QLowEnergyService::ServiceError error)
{
    switch(error){
    case QLowEnergyService::NoError:                 return;  //报错但是不做错误处理
    case QLowEnergyService::OperationError:
    case QLowEnergyService::CharacteristicReadError: break;
    case QLowEnergyService::CharacteristicWriteError:break;
    case QLowEnergyService::DescriptorReadError:     break;
    case QLowEnergyService::DescriptorWriteError:    break;
    case QLowEnergyService::UnknownError:            break;
    default: break;
    }
    BluetoothInfo.isConnectState = false;
    lowEnergyController->disconnectFromDevice();
}

void GY_BleConnect::slotServiceStateChanged(QLowEnergyService::ServiceState newState)
{
    if(newState == QLowEnergyService::RemoteServiceDiscovered){
        QList<QLowEnergyCharacteristic> list = lowEnergyService->characteristics();
        for(int i = 0; i < list.count(); i++){
            lowEnergyCharacteristic = list.at(i);
            if(!lowEnergyCharacteristic.isValid()) return;
            switch(lowEnergyCharacteristic.properties()){
            case (QLowEnergyCharacteristic::WriteNoResponse|QLowEnergyCharacteristic::Write): //允许写入没响应的特征值 //允许写入特征
                lowCharacteristicWrite = list.at(i);
                lowEnergyService->writeCharacteristic(lowCharacteristicWrite,QByteArray(_SuccessConnection_),QLowEnergyService::WriteWithResponse);//用于判断是否连接成功
                break;
            case QLowEnergyCharacteristic::Notify: //对特征值通知
                lowEnergyService->writeDescriptor(list.at(i).descriptor(QBluetoothUuid::DescriptorType::ClientCharacteristicConfiguration), QByteArray::fromHex("0100")); //0100不能改
                break;
            default:break;
            }
        }
    }else if(newState == QLowEnergyService::RemoteServiceDiscovering){
    }else if(newState == QLowEnergyService::RemoteService){
        QTimer::singleShot(600,this,[=]{lowEnergyService->discoverDetails();});//尝试再次连接
    }else{
        BluetoothInfo.isConnectState = false;
        lowEnergyController->disconnectFromDevice();
        qDebug() <<"\033[1;33m==========蓝牙已经断开连接 + 服务状态不是所需要的结果："<< newState << "=======\033[0m" << "\n";
        emit sendConnectionStatus( BluetoothInfo.isConnectState,  BluetoothInfo);   //发送连接状态的信号
    }
}

void GY_BleConnect::slotServiceCharacteristicWritten(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue)
{
    if(newValue.toStdString() == _SuccessConnection_ &&  BluetoothInfo.isConnectState == false){
        BluetoothInfo.isConnectState = true;
        this->slotWriteToHex(QByteArray("FE F5 01"));
        this->slotWriteToHex(QByteArray("FE F5 02"));
        this->slotWriteToHex(QByteArray("FE F5 03"));
        this->slotWriteToHex(QByteArray("FE F5 04"));
        this->slotWriteToHex(QByteArray("FE F5 05"));
        this->slotWriteToHex(QByteArray("FE F5 06"));
        this->slotWriteToHex(QByteArray("FE F5 07"));
        this->slotWriteToHex(QByteArray("FE F5 08"));
        this->slotWriteToHex(QByteArray("FE F6 00"));
        this->slotWriteToHex(QByteArray("FE FF"));
        qDebug() <<"\033[1;31m> > > > > > > 连 接 成 功 < < < < < < <" <<  BluetoothInfo.getWindowsAddress << " " <<BluetoothInfo.getName << " 线程号:" << QThread::currentThreadId() << "\033[0m" << "\n";
        QTimer::singleShot(2000,this,[=](){ emit sendConnectionStatus( BluetoothInfo.isConnectState,  BluetoothInfo); }); //发送连接状态的信号
    }
}

void GY_BleConnect::slotServiceCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue)
{
    qDebug() <<"\033[1;36m======= 接 收 消 息：" << newValue << "\033[0m";
    char str_0X00 = 0x00;
    QByteArray data = newValue.toHex().remove(0,6);
    QString text = QString::fromUtf8(newValue.mid(3,-1));
    if(newValue.left(3).toHex() == "fef501" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getDfuVersion = text.remove("\xFE\xF5\x01").replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef502" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getDeviceColor = text.replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef503" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getProductTime = text.remove("\xFE\xF5\x03").replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef504" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getManufacturer = text.remove("\xFE\xF5\x04").replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef505" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getBatchNumber = text.remove("\xFE\xF5\x05").replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef506" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getUniqueID = text.replace(str_0X00, "");
    }else if(newValue.left(3).toHex() == "fef507" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getCheckStep = text.remove("\xFE\xF5\x07").replace(str_0X00,"");
    }else if(newValue.left(3).toHex() == "fef508" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){
        DeviceAllInfo.getDeviceID = text.remove("\xFE\xF5\x08").replace(str_0X00,"");
    }else if(newValue.left(2).toHex() == "fef6" && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){//电量信息
        DeviceAllInfo.getBatteryLevel = QString::number(newValue.left(4).toHex().remove(0,4).left(2).toInt(NULL,16));
        DeviceAllInfo.getChargingState = newValue.left(4).toHex().remove(0,4).right(2).toInt(NULL,16);
        emit sendBatteryInfomation(DeviceAllInfo);
        qDebug() << "解析电量信息:" << newValue.left(4).toHex().remove(0,4) << "\t电量值:" << DeviceAllInfo.getBatteryLevel << "\t充电状态:" << DeviceAllInfo.getChargingState << "\tID:" << DeviceAllInfo.getUniqueID;
    }else if(newValue.contains("Light&Salt_keyboard1") && data.left(6) != "ffffff" && data.left(6) != " " && data != ""){//名称+版本号
        DeviceAllInfo.getNameAndVersion = QString(newValue).replace(str_0X00, "");
    }
}
#pragma endregion}
