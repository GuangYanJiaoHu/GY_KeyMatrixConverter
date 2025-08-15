#include "GY_BlueToothDevice.h"

BlueToothDevice::BlueToothDevice(QObject *parent): QObject{parent}
{
    bleSearch = new GY_BleSearch;
    connect(bleSearch, &GY_BleSearch::sendMouseSearchInfo, this, &BlueToothDevice::slotMouseSearchInfo);
    connect(bleSearch, &GY_BleSearch::sendKeyboardSearchInfo, this, &BlueToothDevice::slotKeyboardSearchInfo);

    connect(bleSearch, &GY_BleSearch::sendMouseSearchFinished, this, &BlueToothDevice::slotMouseSearchFinished);
    connect(bleSearch, &GY_BleSearch::sendKeyboardSearchFinished, this, &BlueToothDevice::slotKeyboardSearchFinished);


    getBatteryLevel = new QTimer(this); //获取电量专用
    connect(getBatteryLevel, &QTimer::timeout,this, [=](){
        if(listBleKeyboard.count() == 0 && listBleMouse.count() == 0) return;
        qDebug() << "==========================================更新电量====================================================";
        for(int i = 0; i < listBleKeyboard.count(); i++){
            emit listBleKeyboard.at(i)->sendWriteToHex("FE F6");
        }
        for(int i = 0; i < listBleMouse.count(); i++){
            emit listBleMouse.at(i)->sendWriteToHex("FE F6");
        }
    });
    getBatteryLevel->start(30000); //30s读取更新一次电量
}

void BlueToothDevice::start(const int &searchTime)
{
    bleSearch->GY_StartSearchDevice(searchTime, true);
}

//键盘搜索到的信息 准备连接
void BlueToothDevice::slotKeyboardSearchInfo(const QBluetoothDeviceInfo &info)
{
#ifdef Q_OS_MAC
        for(int i = 0; i < listBleKeyboard.count(); i++){
            if(listBleKeyboard.at(i)->getBluetoothInfo().getMacAddress == info.address().toString()){
                return;
            }
        }
#elif defined(Q_OS_WIN)
        for(int i = 0; i < listBleKeyboard.count(); i++){
            if(listBleKeyboard.at(i)->getBluetoothInfo().getWindowsAddress == info.address().toString()){
                return;
            }
        }
#endif

    GY_BleConnect *bleKeyboardConnect = new GY_BleConnect;
    connect(bleKeyboardConnect, &GY_BleConnect::sendWrite, bleKeyboardConnect, &GY_BleConnect::slotWrite);
    connect(bleKeyboardConnect, &GY_BleConnect::sendWriteToHex, bleKeyboardConnect, &GY_BleConnect::slotWriteToHex);
    connect(bleKeyboardConnect, &GY_BleConnect::sendBatteryInfomation, this, &BlueToothDevice::slotKeyboardBatteryInfomation);
    QThread *thradDeKeyboardConnect = new QThread;
    connect(thradDeKeyboardConnect, &QThread::started, bleKeyboardConnect, [=](){
        bleKeyboardConnect->setBluetoothDeviceInfo(info);
    });
    connect(thradDeKeyboardConnect, &QThread::finished, bleKeyboardConnect, &GY_BleConnect::deleteLater);
    connect(thradDeKeyboardConnect, &QThread::finished, thradDeKeyboardConnect, &QThread::deleteLater);
    connect(bleKeyboardConnect, &GY_BleConnect::sendConnectionStatus,this,[=](const bool &isConnect, const struct BlueToothInfo &bluetoothInfo){
#ifdef Q_OS_MAC
        if(isConnect){
            qDebug() << "键盘：" << bluetoothInfo.getMacAddress << "--连接成功--";
            listBleKeyboard.append(bleKeyboardConnect);
            emit sendDeviceConnectInfo(BlueToothDevice::DeviceType::KEYBOARD, bleKeyboardConnect->getBluetoothInfo(), bleKeyboardConnect->getDeviceAllInfo());
        }else{
            qDebug() << "键盘：" << bluetoothInfo.getMacAddress  << "--断开连接--";
            emit sendDeviceDisconnectInfo(BlueToothDevice::DeviceType::KEYBOARD, bleKeyboardConnect->getBluetoothInfo(), bleKeyboardConnect->getDeviceAllInfo());
            for(int i = 0; i < listBleKeyboard.count(); i++){
                if(listBleKeyboard.at(i)->getBluetoothInfo().getMacAddress == bluetoothInfo.getMacAddress){
                    listBleKeyboard.at(i)->setDisconnectController();
                    listBleKeyboard.removeOne(listBleKeyboard.at(i));
                    bleKeyboardConnect->deleteLater();
                    if (thradDeKeyboardConnect->isRunning()) {
                        thradDeKeyboardConnect->quit();
                        thradDeKeyboardConnect->wait();
                    }
                }
            }
        }
#elif defined(Q_OS_WIN)
        if(isConnect){
            qDebug() << "键盘：" << bluetoothInfo.getWindowsAddress << "--连接成功--";
            listBleKeyboard.append(bleKeyboardConnect);
            emit sendDeviceConnectInfo(BlueToothDevice::DeviceType::KEYBOARD, bleKeyboardConnect->getBluetoothInfo(), bleKeyboardConnect->getDeviceAllInfo());
        }else{
            qDebug() << "键盘：" << bluetoothInfo.getWindowsAddress  << "--断开连接--";
            emit sendDeviceDisconnectInfo(BlueToothDevice::DeviceType::KEYBOARD, bleKeyboardConnect->getBluetoothInfo(), bleKeyboardConnect->getDeviceAllInfo());
            for(int i = 0; i < listBleKeyboard.count(); i++){
                if(listBleKeyboard.at(i)->getBluetoothInfo().getWindowsAddress == bluetoothInfo.getWindowsAddress){
                    listBleKeyboard.at(i)->setDisconnectController();
                    listBleKeyboard.removeOne(listBleKeyboard.at(i));
                    bleKeyboardConnect->deleteLater();
                    if (thradDeKeyboardConnect->isRunning()) {
                        thradDeKeyboardConnect->quit();
                        thradDeKeyboardConnect->wait();
                    }
                }
            }
        }
#endif
    });
    bleKeyboardConnect->moveToThread(thradDeKeyboardConnect);
    thradDeKeyboardConnect->start();
}

//鼠标搜索到的信息 准备连接
void BlueToothDevice::slotMouseSearchInfo(const QBluetoothDeviceInfo &info)
{
#ifdef Q_OS_MAC
        for(int i = 0; i < listBleMouse.count(); i++){
            if(listBleMouse.at(i)->getBluetoothInfo().getMacAddress == info.address().toString()){
                return;
            }
        }
#elif defined(Q_OS_WIN)
        for(int i = 0; i < listBleMouse.count(); i++){
            if(listBleMouse.at(i)->getBluetoothInfo().getWindowsAddress == info.address().toString()){
                return;
            }
        }
#endif
    GY_BleConnect *bleMouseConnect = new GY_BleConnect;
    connect(bleMouseConnect, &GY_BleConnect::sendWrite, bleMouseConnect, &GY_BleConnect::slotWrite);
    connect(bleMouseConnect, &GY_BleConnect::sendWriteToHex, bleMouseConnect, &GY_BleConnect::slotWriteToHex);
    connect(bleMouseConnect, &GY_BleConnect::sendBatteryInfomation, this, &BlueToothDevice::slotMouseBatteryInfomation);
    QThread *thradMouseConnect = new QThread;
    connect(thradMouseConnect, &QThread::started, bleMouseConnect, [=](){
        bleMouseConnect->setBluetoothDeviceInfo(info);
    });
    connect(thradMouseConnect, &QThread::finished, bleMouseConnect, &GY_BleConnect::deleteLater);
    connect(thradMouseConnect, &QThread::finished, thradMouseConnect, &QThread::deleteLater);
    connect(bleMouseConnect, &GY_BleConnect::sendConnectionStatus,this,[=](const bool &isConnect, const struct BlueToothInfo &bluetoothInfo){
#ifdef Q_OS_MAC
        if(isConnect){
            qDebug() << "鼠标：" << bluetoothInfo.getMacAddress << "--连接成功--";
            listBleMouse.append(bleMouseConnect);
            emit sendDeviceConnectInfo(BlueToothDevice::DeviceType::MOUSE, bleMouseConnect->getBluetoothInfo(), bleMouseConnect->getDeviceAllInfo());
        }else{
            qDebug() << "鼠标：" << bluetoothInfo.getMacAddress << "--断开连接--";
            emit sendDeviceDisconnectInfo(BlueToothDevice::DeviceType::MOUSE, bleMouseConnect->getBluetoothInfo(), bleMouseConnect->getDeviceAllInfo());
            for(int i = 0; i < listBleMouse.count(); i++){
                if(listBleMouse.at(i)->getBluetoothInfo().getMacAddress == bluetoothInfo.getMacAddress){
                    listBleMouse.at(i)->setDisconnectController();
                    listBleMouse.removeOne(listBleMouse.at(i));
                    bleMouseConnect->deleteLater();
                    if (thradMouseConnect->isRunning()) {
                        thradMouseConnect->quit();
                        thradMouseConnect->wait();
                    }
                }
            }
        }
#elif defined(Q_OS_WIN)
        if(isConnect){
            qDebug() << "鼠标：" << bluetoothInfo.getWindowsAddress << "--连接成功--";
            listBleMouse.append(bleMouseConnect);
            emit sendDeviceConnectInfo(BlueToothDevice::DeviceType::MOUSE, bleMouseConnect->getBluetoothInfo(), bleMouseConnect->getDeviceAllInfo());
        }else{
            qDebug() << "鼠标：" << bluetoothInfo.getWindowsAddress << "--断开连接--";
            emit sendDeviceDisconnectInfo(BlueToothDevice::DeviceType::MOUSE, bleMouseConnect->getBluetoothInfo(), bleMouseConnect->getDeviceAllInfo());
            for(int i = 0; i < listBleMouse.count(); i++){
                if(listBleMouse.at(i)->getBluetoothInfo().getWindowsAddress == bluetoothInfo.getWindowsAddress){
                    qDebug() << "鼠标测试循环问题-内层循环145搜索到地址相同：" << listBleMouse.count();
                    listBleMouse.at(i)->setDisconnectController();
                    qDebug() << "鼠标测试循环问题-内层循环147断开设备：" << listBleMouse.count();
                    listBleMouse.removeOne(listBleMouse.at(i));
                    bleMouseConnect->deleteLater();
                    if (thradMouseConnect->isRunning()) {
                        thradMouseConnect->quit();
                        thradMouseConnect->wait();
                    }
                    break;
                }
            }
        }
#endif
    });
    bleMouseConnect->moveToThread(thradMouseConnect);
    thradMouseConnect->start();
}

void BlueToothDevice::slotKeyboardSearchFinished(const QList<QBluetoothDeviceInfo> &info_list){ Q_UNUSED(info_list) }
void BlueToothDevice::slotMouseSearchFinished(const QList<QBluetoothDeviceInfo> &info_list){ Q_UNUSED(info_list) }

void BlueToothDevice::slotMouseBatteryInfomation(const DeviceInfo &deviceInfo)
{
    emit sendBatteryInfomation(BlueToothDevice::DeviceType::MOUSE, deviceInfo);
}

void BlueToothDevice::slotKeyboardBatteryInfomation(const DeviceInfo &deviceInfo)
{
    emit sendBatteryInfomation(BlueToothDevice::DeviceType::KEYBOARD, deviceInfo);
}



#pragma region 写入操作{

//--------------------------------- " 以 下 为：全部设备写入 需要自行转换进制" --------------------------------------
void BlueToothDevice::GY_WriteAllMouseDevice(const QByteArray &data)
{
    for(int i = 0; i < listBleMouse.count(); i++){
        emit listBleMouse.at(i)->sendWrite(data);
    }
}

void BlueToothDevice::GY_WriteAllKeyboardDevice(const QByteArray &data)
{
    for(int i = 0; i < listBleKeyboard.count(); i++){
        emit listBleKeyboard.at(i)->sendWrite(data);
    }
}

//--------------------------------- " 以 下 为：全部设备写入 转换成HEX进制" --------------------------------------
void BlueToothDevice::GY_WriteToHexAllMouseDevice(const QByteArray &data)
{
    for(int i = 0; i < listBleMouse.count(); i++){
        emit listBleMouse.at(i)->sendWriteToHex(data);
    }
}

void BlueToothDevice::GY_WriteToHexAllKeyboardDevice(const QByteArray &data)
{
    for(int i = 0; i < listBleKeyboard.count(); i++){
        emit listBleKeyboard.at(i)->sendWriteToHex(data);
    }
}

//--------------------------------- " 以 下 为：写入数据需要根据写入类型转换 " --------------------------------------
bool BlueToothDevice::GY_WriteMouseUniqueID(const QString &uniqueID, const QByteArray &data)
{
    for(int i = 0; i < listBleMouse.count(); i++){
        if(uniqueID == listBleMouse.at(i)->getDeviceAllInfo().getUniqueID){
            emit listBleMouse.at(i)->sendWrite(data);
            return true;
        }
    }
    return false;
}

bool BlueToothDevice::GY_WriteKeyboardUniqueID(const QString &uniqueID, const QByteArray &data)
{
    for(int i = 0; i < listBleKeyboard.count(); i++){
        if(uniqueID == listBleKeyboard.at(i)->getDeviceAllInfo().getUniqueID){
            emit listBleKeyboard.at(i)->sendWrite(data);
            return true;
        }
    }
    return false;
}

bool BlueToothDevice::GY_WriteToHexKeyboardUniqueID(const QString &uniqueID, const QByteArray &data)
{
    for(int i = 0; i < listBleKeyboard.count(); i++){
        if(uniqueID == listBleKeyboard.at(i)->getDeviceAllInfo().getUniqueID){
            emit listBleKeyboard.at(i)->sendWriteToHex(data);
            return true;
        }
    }
    return false;
}

bool BlueToothDevice::GY_WriteToHexMouseUniqueID(const QString &uniqueID, const QByteArray &data)
{
    for(int i = 0; i < listBleMouse.count(); i++){
        if(uniqueID == listBleMouse.at(i)->getDeviceAllInfo().getUniqueID){
            emit listBleMouse.at(i)->sendWriteToHex(data);
            return true;
        }
    }
    return false;
}

#pragma endregion }

