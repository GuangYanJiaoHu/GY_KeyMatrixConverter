#include "GY_Communicate.h"

GY_Communicate::GY_Communicate(QObject *parent)
    : QObject{parent}
{
    // 0x044D,0x04D2 //60配列键盘

    keyboard = new GY_HIDKeyboard(0x044D, 0x04D2);   //pid vid
    connect(keyboard, &GY_HIDKeyboard::signalKeyboardConnection,    this, &GY_Communicate::slotsKeyboardConnect);
    connect(keyboard, &GY_HIDKeyboard::signalKeyboardDisconnection, this, &GY_Communicate::slotsKeyboardDisconnect);

    // keyboard = new GY_HIDKeyboard(0x0483,0x5750);   //pid vid
    // connect(keyboard, &GY_HIDKeyboard::signalKeyboardConnection,    this, &GY_Communicate::slotsKeyboardConnect);
    // connect(keyboard, &GY_HIDKeyboard::signalKeyboardDisconnection, this, &GY_Communicate::slotsKeyboardDisconnect);
    // connect(keyboard, &GY_HIDKeyboard::signalBatteryChange,         this, &GY_Communicate::signalsDeviceBattery);

    Mouse = new GY_HIDMouse(0x0483,0x5850);         //pid vid
    connect(Mouse, &GY_HIDMouse::signalMouseConnection,     this, &GY_Communicate::slotsMouseConnect);
    connect(Mouse, &GY_HIDMouse::signalMouseDisconnection,  this, &GY_Communicate::slotsMouseDisconnect);
    connect(Mouse, &GY_HIDMouse::signalBatteryChange,       this, &GY_Communicate::signalsDeviceBattery);

    Adapter = new GY_24GHz(0x0483,0x5855);          //pid vid
    connect(Adapter, &GY_24GHz::signal24GHzConnection,      this, &GY_Communicate::slots24GHzConnect);
    connect(Adapter, &GY_24GHz::signal24GHzDisconnection,   this, &GY_Communicate::slots24GHzDisconnect);
    connect(Adapter, &GY_24GHz::signal24GHzBattery,         this, &GY_Communicate::signalsDeviceBattery);
    connect(Adapter, &GY_24GHz::signal24GHzKeyboardOrMouseConnected,this, &GY_Communicate::signals24GHzKeyboardOrMouseConnected);

    blueToothDevice = new BlueToothDevice(this);    //bluetooth device
    connect(blueToothDevice, &BlueToothDevice::sendDeviceConnectInfo,   this, &GY_Communicate::slotsDeviceConnectInfo);
    connect(blueToothDevice, &BlueToothDevice::sendDeviceDisconnectInfo,this, &GY_Communicate::slotsDeviceDisconnectInfo);
    connect(blueToothDevice, &BlueToothDevice::sendBatteryInfomation,   this, &GY_Communicate::slotsBatteryInfomation);

    blueToothDevice->start();
}


#pragma region========================================================= 槽 函 数 ========================================================================================={

//键盘链接成功
void GY_Communicate::slotsKeyboardConnect(const HidDeviceInfo &DeviceInfo)
{
    Device device;
    switch(DeviceInfo.getDeviceType()){
    case HidDeviceInfo::DeviceType::_HID_KEYBOARD:
        device = this->getListDeviceInfo(DeviceInfo, DeviceType::_HID_KEYBOARD, ConnectType::_HID);
        listDevice.append(device);
        break;
    case HidDeviceInfo::DeviceType::_HID_KEYBOARD_JIAN0:
        device = this->getListDeviceInfo(DeviceInfo, DeviceType::_HID_KEYBOARD_JIAN0, ConnectType::_HID);
        listDevice.append(device);
        break;
    case HidDeviceInfo::DeviceType::_HID_KEYPAD:
        device = this->getListDeviceInfo(DeviceInfo, DeviceType::_HID_KEYPAD, ConnectType::_HID);
        listDevice.append(device);
        break;
    case HidDeviceInfo::DeviceType::_HID_KEYBOARD_60:
        device = this->getListDeviceInfo(DeviceInfo, DeviceType::_HID_KEYBOARD_60, ConnectType::_HID);
        listDevice.append(device);
        break;
    default:break;
    }
    QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
    device.warm = result.first;
    device.red = result.second;
    qDebug() << TAG << __LINE__ << "-----------------------HID键盘=连接成功--------------------- 设备类型：" << DeviceInfo.getDeviceType() << " 设备数量" << listDevice.count();
    emit signalsDeviceConnect(device);
}

//键盘断开连接
void GY_Communicate::slotsKeyboardDisconnect(const QString &portPath)
{
    qDebug()<<"---------------------------------------HID键盘=断开连接--------------------------------------------------";
    for(int i = 0; i < listDevice.count(); i++){
        if(listDevice.at(i).DevicePortPath == portPath){
            emit signalsDeviceDisconnect(listDevice.at(i));
            listDevice.removeAt(i);
            qDebug() << TAG << __LINE__ << "HID键盘数量" << this->getDeviceList().count();
            return;
        }
    }
}

//鼠标连接成功
void GY_Communicate::slotsMouseConnect(const HidDeviceInfo &DeviceInfo)
{
    qDebug()<<"---------------------------------------HID鼠标=连接成功--------------------------------------------------" << DeviceInfo.getDeviceType();
    Device device = this->getListDeviceInfo(DeviceInfo, DeviceType::_HID_MOUSE, ConnectType::_HID);
    listDevice.append(device);
    QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
    device.warm = result.first;
    device.red = result.second;
    qDebug() << TAG << __LINE__ <<"87这个设备连接过 - " <<  device.warm << " - " << device.red;
    emit signalsDeviceConnect(device);
}
//鼠标断开连接
void GY_Communicate::slotsMouseDisconnect(const QString &portPath)
{
    qDebug() << TAG << __LINE__ << "---------------------------------------HID鼠标=断开连接--------------------------------------------------" << "当前设备数量;";
    for(int i = 0; i < listDevice.count(); i++){
        if(listDevice.at(i).DevicePortPath == portPath){
            emit signalsDeviceDisconnect(listDevice.at(i));
            listDevice.removeAt(i);
            return;
        }
    }
}
//蓝牙设备获取电量
void GY_Communicate::slotsBatteryInfomation(BlueToothDevice::DeviceType type, DeviceInfo deviceInfo)
{
    if(deviceInfo.getUniqueID.isEmpty()) return;
}
//蓝牙设备连接成功
void GY_Communicate::slotsDeviceConnectInfo(BlueToothDevice::DeviceType type, BlueToothInfo bluetoothInfo, DeviceInfo deviceInfo)
{
    switch(type){
    case BlueToothDevice::DeviceType::KEYBOARD:
    {
        qDebug() << TAG << __LINE__ <<"---------------------------------------蓝牙键盘=连接成功--------------------------------------------------";
        Device device = this->getListBlueDeviceInfo(bluetoothInfo, deviceInfo, DeviceType::_BLUE_KEYBOARD, ConnectType::_BLUETOOTH);
        listDevice.append(device);
        QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
        device.warm = result.first;
        device.red = result.second;
        qDebug() << TAG << __LINE__ <<"188这个设备连接过 - " <<  device.warm << " - " << device.red;
        emit signalsDeviceConnect(device);
        break;
    }
    case BlueToothDevice::DeviceType::MOUSE:
    {
        qDebug() << TAG << __LINE__ <<"---------------------------------------蓝牙鼠标=连接成功--------------------------------------------------";
        Device device =this->getListBlueDeviceInfo(bluetoothInfo, deviceInfo, DeviceType::_BLUE_MOUSE, ConnectType::_BLUETOOTH);
        listDevice.append(device);
        QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
        device.warm = result.first;
        device.red = result.second;
        qDebug() << TAG << __LINE__ <<"200这个设备连接过 - " <<  device.warm << " - " << device.red;
        emit signalsDeviceConnect(device);
        break;
    }
    default:    break;
    }
}
//蓝牙设备断开连接
void GY_Communicate::slotsDeviceDisconnectInfo(BlueToothDevice::DeviceType type, BlueToothInfo bluetoothInfo, DeviceInfo deviceInfo)
{
    switch(type){
    case BlueToothDevice::DeviceType::KEYBOARD:
        qDebug() << TAG << __LINE__ <<"---------------------------------------蓝牙键盘=断开连接--------------------------------------------------";
        for(int i = 0; i < listDevice.count(); i++){
            if(listDevice.at(i).BleAddress == bluetoothInfo.getWindowsAddress){
                emit signalsDeviceDisconnect(listDevice.at(i));
                listDevice.removeAt(i);
                return;
            }
        }
        break;
    case BlueToothDevice::DeviceType::MOUSE:
        qDebug() << TAG << __LINE__ <<"---------------------------------------蓝牙鼠标=断开连接--------------------------------------------------";
        for(int i = 0; i < listDevice.count(); i++){
            if(listDevice.at(i).BleAddress == bluetoothInfo.getWindowsAddress){
                emit signalsDeviceDisconnect(listDevice.at(i));
                listDevice.removeAt(i);
                return;
            }
        }
        break;
    default: break;
    }
}
#pragma endregion }

#pragma region====================================================== 工 具 类 函 数 ======================================================================================{
bool GY_Communicate::Write(const QString &portPath, const QString &data)
{
    for(int i = 0; i < listDevice.count(); i++){
        if(listDevice.at(i).DevicePortPath == portPath){
            switch(listDevice.at(i).DeviceType){
            case DeviceType::_HID_KEYBOARD:
                keyboard->Write(portPath, data);
                break;
            case DeviceType::_HID_KEYPAD:
                break;
            case DeviceType::_HID_MOUSE:
                Mouse->Write(portPath, data);
                break;
            case DeviceType::_HID_KEYBOARD_60:
                keyboard->Write(portPath, data);
                break;
            case DeviceType::_24GHz_Adapter: //适配器
                Adapter->Write(portPath, data);
                break;
            case DeviceType::_BLUE_MOUSE:
                blueToothDevice->GY_WriteToHexMouseUniqueID(portPath, data.toUtf8());
                break;
            case DeviceType::_BLUE_KEYBOARD:
                blueToothDevice->GY_WriteToHexKeyboardUniqueID(portPath, data.toUtf8());
                break;
            case DeviceType::_24GHz_KEYBOARD:
                qDebug() << TAG << __LINE__ <<"24键盘通信"<<portPath<<data.toUtf8();
                Adapter->Write(portPath, data.toUtf8(), HidDeviceInfo::_24GHz_KEYBOARD);
                break;
            case DeviceType::_24GHz_MOUSE:
                qDebug() << TAG << __LINE__ <<"24鼠标通信"<<portPath<<data.toUtf8();
                Adapter->Write(portPath, data.toUtf8(), HidDeviceInfo::_24GHz_MOUSE);
                break;
            default:
                break;
            }
            return true;
        }
    }
    return false;
}

bool GY_Communicate::WriteAllKeyboard(const QString &data)
{
    if(listDevice.isEmpty()) return false;
    for(int i = 0; i < listDevice.count(); i++){
        qDebug() << listDevice.at(i).DeviceType;
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD || listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD_JIAN0){
            qDebug() << TAG << __LINE__ << "HID键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_24GHz_KEYBOARD){
            qDebug() << TAG << __LINE__ << TAG << "2.4G键盘写入" << Adapter->Write(listDevice.at(i).DevicePortPath, data, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_BLUE_KEYBOARD){
            qDebug() << TAG << __LINE__ << TAG <<"蓝牙写入"<<data.toUtf8();
            blueToothDevice->GY_WriteToHexAllKeyboardDevice(data.toUtf8());
        }
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYPAD){
            qDebug() << TAG << __LINE__ <<"小键盘写入"<<data.toUtf8();
            qDebug() << TAG << __LINE__ << "HID键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD_60){
            qDebug() << TAG << __LINE__ <<"——60配列键盘写入"<<data.toUtf8();
            qDebug() << TAG << __LINE__<< "——60配列键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
    }
    return true;
}

bool GY_Communicate::WriteAllKeyboardColorSend(const QString &data)
{
    if(listDevice.isEmpty()) return false;
    for(int i = 0; i < listDevice.count(); i++){
        qDebug() << listDevice.at(i).DeviceType;
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD || listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD_JIAN0){
            qDebug() << "HID键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_24GHz_KEYBOARD){
            qDebug() << "2.4G键盘写入" << Adapter->Write(listDevice.at(i).DevicePortPath, data, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_BLUE_KEYBOARD){
            qDebug()<<"蓝牙写入"<<data.toUtf8();
            blueToothDevice->GY_WriteToHexAllKeyboardDevice(data.toUtf8());
        }
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYPAD){
            qDebug() << "小键盘写入"<<data.toUtf8();
            qDebug() << "HID键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_HID_KEYBOARD_60){
            qDebug() << "_60配列键盘写入" << keyboard->Write(listDevice.at(i).DevicePortPath, data);
        }
    }
    return true;
}

//这个函数没调用
bool GY_Communicate::WriteAdatper(const QString &data)
{
    if(!deviceAdapter.getIsConnectStatus()) return false;
    Adapter->Write(deviceAdapter.getDevicePortPath(), data);
    for(int i=0;i<listDeviceAdapter.count();i++)
    {

    }
    return true;
}

bool GY_Communicate::WriteAllMouse(const QString &data)
{
    if(listDevice.isEmpty()) return false;
    for(int i = 0; i < listDevice.count(); i++){
        if(listDevice.at(i).DeviceType == DeviceType::_HID_MOUSE){
            Mouse->Write(listDevice.at(i).DevicePortPath, data);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_24GHz_MOUSE){
            qDebug() << Adapter->Write(listDevice.at(i).DevicePortPath, data, HidDeviceInfo::DeviceType::_24GHz_MOUSE);
        }
        if(listDevice.at(i).DeviceType == DeviceType::_BLUE_MOUSE){
            blueToothDevice->GY_WriteToHexAllMouseDevice(data.toUtf8());
        }
    }
    return true;
}

bool GY_Communicate::WriteCharFiltration(char arry[][33], const int groupCount, const bool filtration)
{
    if(listDevice.isEmpty()) return false;

    if(filtration){
        for(int j = 0; j < listDevice.count(); j++){
            if(listDevice.at(j).DeviceType == DeviceType::_HID_KEYBOARD || listDevice.at(j).DeviceType == DeviceType::_HID_KEYBOARD_JIAN0){
                for(int i = 0; i < groupCount; i++){
                    QByteArray request;
                    for(int j = 0; j < 33; j++){
                        request.append(arry[i][j]);
                    }
                    keyboard->WriteChar(listDevice.at(j).DevicePortPath, request);
                    QThread::msleep(5);
                }
            }
        }
        return true;
    }
    for(int k = 0; k < listDevice.count(); k++){
        for(int i = 0; i < groupCount; i++){
            QByteArray request;
            for(int j = 0; j < 33; j++){
                request.append(arry[i][j]);
            }
            if(listDevice.at(k).DeviceType == DeviceType::_HID_KEYBOARD || listDevice.at(k).DeviceType == DeviceType::_HID_KEYBOARD_JIAN0){
                keyboard->WriteChar(listDevice.at(k).DevicePortPath, request);
            }else if(listDevice.at(k).DeviceType == DeviceType::_24GHz_KEYBOARD){
                Adapter->WriteChar(listDevice.at(k).DevicePortPath, request, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
            }else if(listDevice.at(k).DeviceType == DeviceType::_BLUE_KEYBOARD){
                blueToothDevice->GY_WriteAllKeyboardDevice(request.right(32));
            }
            QThread::msleep(5);
        }
    }
    return true;
}

bool GY_Communicate::GY_write_array(char arry[][33], const int groupCount, const int device_type)
{
    if(listDevice.isEmpty()) return false;
    for(int j = 0; j < listDevice.count(); j++){
        if( listDevice.at(j).DeviceType == device_type){
            for(int i = 0; i < groupCount; i++){
                QByteArray request;
                for(int j = 0; j < 33; j++){
                    request.append(arry[i][j]);
                }
                keyboard->WriteChar(listDevice.at(j).DevicePortPath, request);
                QThread::msleep(5);
            }
        }
    }
    //  QThread::msleep(15);//保证一些稳定性
    return true;
}

int GY_Communicate::getAdapterNumber()
{
    //返回适配器的数量即可
    qDebug()<<"适配器数量"<<listDeviceAdapter.count();
    return  listDeviceAdapter.count();
}

void GY_Communicate::receiverOpenClose(bool isOpen)
{
    //这里必须加以限制，多设备会出现混乱的问题
    if(listDeviceAdapter.count()>0){
        if(isOpen){
            qDebug()<<"发送指令，适配器进入配对模式";
            Adapter->Write("FC E2 01");//解锁 允许配对
        }else{
            Adapter->Write("FC E2 00");//锁 退出配对模式
        }
    }
}

void GY_Communicate::receiverClear()
{
    //清空这里有一个问题 需要设备逐条清空 多个适配器连接需要弹窗报错
    for(int i = 0; i < listDeviceAdapter.count(); i++){
        Adapter->Write("FC E4");
    }
}
//下发颜色数据 - 静态 给键盘模拟
void GY_Communicate::slotAnimationStaticSimulate(QList<QString> listColor)
{
    //qDebug() << TAG << __LINE__ << "静态动画模拟 - 下发键盘数据" << " 按键颜色个数：" << listColor.count();
    QString colorData;
    for(int i = 0, j = 1, k = 1;  i < listColor.count(); i++){
        if(j % 30 == 0 && j != 0){
            colorData += " ";
            colorData +=  listColor.at(i);
            QString head = QString("03 %1").arg(k, 2, 16, QChar('0'));
            this->WriteAllKeyboardColorSend(head + colorData);
            colorData.clear();
            k += 10;
            QThread::msleep(5);
        }else{
            colorData += " ";
            colorData +=  listColor.at(i);
        }
        j++;
    }
    this->WriteAllKeyboardColorSend("fe 01 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
}

//下发颜色数据 - 动态 给键盘模拟
void GY_Communicate::slotAnimationDynamicSimulate(QList<QString> listColor)
{
    QString colorData;
    for(int i = 0, j = 1, k = 1;  i < listColor.count(); i++){
        if(j % 30 == 0 && j != 0){
            colorData += " ";
            colorData +=  listColor.at(i);
            QString head = QString("03 %1").arg(k, 2, 16, QChar('0'));
            this->WriteAllKeyboardColorSend(head + colorData);
            colorData.clear();
            k += 10;
            QThread::msleep(5);
        }else{
            colorData += " ";
            colorData +=  listColor.at(i);
        }
        j++;
    }
    this->WriteAllKeyboardColorSend("fe 01 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
}
//键盘灯光亮度调节
void GY_Communicate::soltKeyboardSettingBrightness(QString lightHex)
{
    this->WriteAllKeyboard("FE 05 " + lightHex);
}

void GY_Communicate::soltKeyboardSettingSendData(QString data)
{
    this->WriteAllKeyboard(data);
}


Device GY_Communicate::getListDeviceInfo(const HidDeviceInfo &DeviceInfo, const DeviceType &DeviceType, const ConnectType &ConnectType)
{
    Device device;
    device.DeviceHandle       =  DeviceInfo.getDeviceHandle();       //端口句柄
    device.DeviceID           =  DeviceInfo.getDeviceID();           //设备ID
    device.DeviceName         =  DeviceInfo.getDeviceName();         //名字
    device.BleAddress         =  nullptr;                            //蓝牙地址 [仅蓝牙]
    device.DeviceColor        =  DeviceInfo.getDeviceColor();        //设备颜色
    device.DevicePortPath     =  DeviceInfo.getDevicePortPath();     //端口路径 - 端口号
    device.DeviceUniqueID     =  DeviceInfo.getDeviceUniqueID();     //唯一编码
    device.DeviceCheckStep    =  DeviceInfo.getDeviceCheckStep();    //检测步骤
    device.DeviceDfuVersion   =  DeviceInfo.getDeviceDfuVersion();   //DFU版本号
    device.DeviceProductTime  =  DeviceInfo.getDeviceProductTime();  //出场时间
    device.DeviceBatchNumber  =  DeviceInfo.getDeviceBatchNumber();  //批次号
    device.DeviceManufacturer =  DeviceInfo.getDeviceManufacturer(); //生产厂家
    device.DeviceBatteryLevel =  DeviceInfo.getDeviceBatteryLevel(); //电池电量
    device.DeviceType         =  DeviceType;                         //设备类型
    device.ConnectType        =  ConnectType;                        //设备连接方式
    device.DeviceChargingState=  DeviceInfo.getDeviceChargingState();//充电状态
    device.IsConnectStatus    =  true;                               //连接状态 初始状态为false
    qDebug() << "设备唯一编码:" << DeviceInfo.getDeviceUniqueID();
    qDebug() << "设备颜色:" << DeviceInfo.getDeviceColor();
    // qDebug() << "设备检测步骤:" << DeviceInfo.getDeviceCheckStep();
    qDebug() << "设备固件版本:" << DeviceInfo.getDeviceDfuVersion();
    qDebug() << "设备电池电量:" << DeviceInfo.getDeviceBatteryLevel();
    qDebug() << "设备写入名称:" << DeviceInfo.getDeviceName();
    // qDebug() << "设备出厂时间:" << DeviceInfo.getDeviceProductTime();
    qDebug() << "设备当前类型:" << DeviceInfo.getDeviceType();
    qDebug() << "-------------------------------------------------------------------------------------------\n";
    return device;
}

Device GY_Communicate::getListBlueDeviceInfo(BlueToothInfo bluetoothInfo, DeviceInfo deviceInfo, const DeviceType &DeviceType, const ConnectType &ConnectType)
{
    Device device;
#ifdef Q_OS_MAC
    device.DeviceHandle       =  -1;                           //端口句柄
#elif defined(Q_OS_WIN)
    device.DeviceHandle       =  nullptr;                           //端口句柄
#endif
    device.DeviceID           =  deviceInfo.getDeviceID;            //设备ID
    device.DeviceName         =  bluetoothInfo.getName;             //名字
    device.BleAddress         =  bluetoothInfo.getWindowsAddress;   //蓝牙地址 [仅蓝牙]
    device.DeviceColor        =  deviceInfo.getDeviceColor;         //设备颜色
    device.DevicePortPath     =  nullptr;                           //端口路径 - 端口号
    device.DeviceUniqueID     =  deviceInfo.getUniqueID;            //唯一编码
    device.DeviceCheckStep    =  deviceInfo.getCheckStep;           //检测步骤
    device.DeviceDfuVersion   =  deviceInfo.getDfuVersion;          //DFU版本号
    device.DeviceProductTime  =  deviceInfo.getProductTime;         //出场时间
    device.DeviceBatchNumber  =  deviceInfo.getBatchNumber;         //批次号
    device.DeviceManufacturer =  deviceInfo.getManufacturer;        //生产厂家
    device.DeviceBatteryLevel =  deviceInfo.getBatteryLevel;        //电池电量
    device.DeviceType         =  DeviceType;                        //设备类型
    device.ConnectType        =  ConnectType;                       //设备连接方式
    device.DeviceChargingState=  deviceInfo.getChargingState;       //充电状态
    device.IsConnectStatus    =  true;                              //连接状态 初始状态为false
    qDebug() << "设备唯一编码:" << device.DeviceUniqueID;
    qDebug() << "设备唯一颜色:" << device.DeviceColor;
    qDebug() << "设备检测步骤:" << device.DeviceCheckStep;
    qDebug() << "设备固件版本:" << device.DeviceDfuVersion;
    qDebug() << "设备电池电量:" << device.DeviceBatteryLevel;
    qDebug() << "设备写入名称:" << device.DeviceName;
    qDebug() << "设备出厂时间:" << device.DeviceProductTime;
    qDebug() << "设备当前类型:" << device.DeviceType;
    qDebug() << "设备蓝牙地址:" << device.BleAddress;
    qDebug() << "-------------------------------------------------------------------------------------------\n";
    return device;
}

QList<Device> GY_Communicate::getDeviceList()
{
    QList<Device> listDeviceFiltration; //过滤适配器的item
    for(int i = 0; i < listDevice.count(); i++){
        if(listDevice.at(i).DeviceType == DeviceType::_24GHz_Adapter){
            continue;
        }
        listDeviceFiltration.append(listDevice.at(i));
    }
    return listDeviceFiltration;
}

QPair<int, int> GY_Communicate::readWhiteBalance(int listDeviceNumber)
{
    QString portPath = listDevice.at(listDeviceNumber).DevicePortPath;
    QFile file(QApplication::applicationDirPath()+ "/Data/cfg.ini");
    file.open(QIODevice::ReadWrite);
    file.close();
    QSettings *configIniWrite = new QSettings(QApplication::applicationDirPath()+ "/Data/cfg.ini", QSettings::IniFormat);
    if(configIniWrite->childGroups().contains(portPath)){          //再次连接的设备
        listDevice.operator [](listDeviceNumber).warm = configIniWrite->value(portPath+"/warm").toInt();
        listDevice.operator [](listDeviceNumber).red = configIniWrite->value(portPath+"/red").toInt();
        qDebug()<<"453这个设备连接过" << portPath << " - " << listDevice.at(listDeviceNumber).warm << " - " << listDevice.at(listDeviceNumber).red;
    }
    QPair<int, int> result(listDevice.at(listDeviceNumber).warm, listDevice.at(listDeviceNumber).red);
    return result;
}
#pragma endregion }


//补零函数 保证数据输入时没有多余干扰信息   后续使用
QString GY_Communicate::zero_fill(QString data)
{
    for(int i=data.length()/3;i<32;i++){
        data.append(" 00");
    }
    return data;
}

void GY_Communicate::slots24GHzConnect(const HidDeviceInfo &deviceInfo, HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
    {
        qDebug()<<"---------------------------------------适配器=连接成功--------------------------------------------------" <<  deviceInfo.getDeviceType() ;
        deviceAdapter = deviceInfo;
        deviceAdapter.setIsConnectStatus(true);
        //多设备需要考虑删除设备的个数
        listDeviceAdapter.append(deviceInfo);
        emit signalsAdapterConnect1(listDeviceAdapter.count(), deviceInfo.getDevicePortPath());
        break;
    }
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:
    {
        qDebug()<<"---------------------------------------2.4GHz键盘=连接成功--------------------------------------------------" <<  deviceInfo.getDeviceType();
        Device device = this->getListDeviceInfo(deviceInfo, DeviceType::_24GHz_KEYBOARD, ConnectType::_24GHz);
        listDevice.append(device);
        QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
        device.warm = result.first;
        device.red = result.second;
        qDebug()<<"132这个设备连接过 - " <<  device.warm << " - " << device.red << device.DeviceColor;
        emit signalsDeviceConnect(device);
        //emit signals24GHzKeyboardConnect(deviceInfo);
        break;
    }
    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:
    {
        qDebug()<<"---------------------------------------2.4GHz鼠标=连接成功--------------------------------------------------" <<  deviceInfo.getDeviceType();
        Device device = this->getListDeviceInfo(deviceInfo, DeviceType::_24GHz_MOUSE, ConnectType::_24GHz);
        listDevice.append(device);
        QPair<int, int> result = this->readWhiteBalance(listDevice.count() - 1);
        device.warm = result.first;
        device.red = result.second;
        qDebug()<<"153这个设备连接过 - " <<  device.warm << " - " << device.red;
        emit signalsDeviceConnect(device);
        //emit signals24GHzMouseConnect(deviceInfo);
        break;
    }
    default:
        qDebug() << "ERROR-00002:24GHz设备类型未识别到";
        break;
    }
}

void GY_Communicate::slots24GHzDisconnect(const QString &portPath, HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
    {
        qDebug()<<"---------------------------------------适配器=断开连接--------------------------------------------------";
        //多设备需要考虑删除设备的个数
        for(int i = 0; i < listDeviceAdapter.count(); i++){
            if(listDeviceAdapter.at(i).getDevicePortPath()==portPath)
            {
                listDeviceAdapter.removeAt(i);
                break;//退出循环
            }
        }
        emit signalsAdapterDisconnect1(listDeviceAdapter.count(), portPath);
        break;
    }
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:
    {
        qDebug()<<"---------------------------------------2.4GHz键盘=断开连接--------------------------------------------------";
        for(int i = 0; i < listDevice.count(); i++){
            if(listDevice.at(i).DevicePortPath == portPath && listDevice.at(i).DeviceType == DeviceType::_24GHz_KEYBOARD){
                emit signalsDeviceDisconnect(listDevice.at(i));
                listDevice.removeAt(i);
                return;
            }
        }
        break;
    }

    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:
    {
        qDebug()<<"---------------------------------------2.4GH鼠标=断开连接--------------------------------------------------";
        for(int i = 0; i < listDevice.count(); i++){
            if(listDevice.at(i).DevicePortPath == portPath && listDevice.at(i).DeviceType == DeviceType::_24GHz_MOUSE){
                emit signalsDeviceDisconnect(listDevice.at(i));
                listDevice.removeAt(i);
                return;
            }
        }
        break;
    }

    default:
        qDebug() << "ERROR-00002:24GHz设备类型未识别到";
        break;
    }
}

