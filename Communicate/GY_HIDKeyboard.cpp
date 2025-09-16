#include "GY_HIDKeyboard.h"
//读取设备信息，当设备连接成功后必须要做的一步
void GY_HIDKeyboard::GetDeviceReadMessage(const QString &portPath)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            qDebug()<<"开始读取hid设备信息"<<QTime::currentTime();
            qDebug() << "写入状态:" << this->WriteHandle(item->getDeviceHandle(), QByteArray("FE F5 02"));  //设备颜色
            break;      //已经拿到信息后就可以即使的关闭循环状态节省资源
        }
    }
    if(!timerBattery->isActive()){
        timerBattery->start(5000);
    }
}

QList<HidDeviceInfo> *GY_HIDKeyboard::getListConnectDevice()
{
    return listConnectDevice;
}

#pragma region=================================== 工 具 方 式 类 ============================================{
bool GY_HIDKeyboard::Write(const QString &portPath, const QString &data, enum HidDeviceInfo::DeviceType deviceType)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            return this->WriteHandle(item->getDeviceHandle(), data.toUtf8());
        }
    }
    return false;
}

bool GY_HIDKeyboard::Write(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            qDebug()<<"写入"<<data;
            return this->WriteHandle(item->getDeviceHandle(), data);
        }
    }
    return false;
}

bool GY_HIDKeyboard::Write(const QString &portPath, const QStringList &data, enum HidDeviceInfo::DeviceType deviceType)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            for(int i = 0; i < data.count(); i++){
                this->WriteHandle(item->getDeviceHandle(), data.at(i).toUtf8());
                QThread::msleep(50);
            }
            return true;
        }
    }
    return false;
}

bool GY_HIDKeyboard::WriteChar(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            qDebug() << "writechar:" << portPath << " : " << data;
            return this->WriteHandleChar(item->getDeviceHandle(), data);
        }
    }
    return false;
}

void GY_HIDKeyboard::slotsKeyboardConnect(const QString &portPath)
{
    this->GetDeviceReadMessage(portPath);
    QTimer::singleShot(200,this,[=](){
        for(int i = 0; i < this->getListConnectDevice()->count(); i++){
            if(this->getListConnectDevice()->at(i).getDevicePortPath() == portPath){
                emit signalKeyboardConnection(this->getListConnectDevice()->at(i));
            }
        }
    });
}

void GY_HIDKeyboard::setDeviceMessage(const QString &portPath, const QString &Data, const QString &order, enum HidDeviceInfo::DeviceType deviceType)
{
    QString recvData = Data;
    for(auto i = 0; i < listConnectDevice->count(); i++){
        if(listConnectDevice->at(i).getDevicePortPath() == portPath){
            if(order == "FE F5 02"){
                listConnectDevice->operator [](i).setDeviceColor(QString(HexToMessage(recvData.remove("FE F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                qDebug() << "HID键盘返回信息-设备颜色：" << QString(HexToMessage(recvData.remove("FE F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE F5 03"){
                listConnectDevice->operator [](i).setDeviceProductTime(QString(HexToMessage(recvData.remove("FE F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                qDebug() << "HID键盘返回信息-出厂时间：" << QString(HexToMessage(recvData.remove("FE F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE F5 04"){
                listConnectDevice->operator [](i).setDeviceManufacturer(QString(HexToMessage(recvData.remove("FE F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                qDebug() << "HID键盘返回信息-生产厂家：" << QString(HexToMessage(recvData.remove("FE F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE F5 05"){
                listConnectDevice->operator [](i).setDeviceBatchNumber(QString(HexToMessage(recvData.remove("FE F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                qDebug() << "HID键盘返回信息-设备批号：" << QString(HexToMessage(recvData.remove("FE F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE F5 06"){
                QString uniqueID = QString(HexToMessage(recvData.remove("FE F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                if(uniqueID.contains("GY02B-")){                                                                    //旧键盘
                    listConnectDevice->operator [](i).setDeviceType(HidDeviceInfo::DeviceType::_HID_KEYBOARD_JIAN0);//设备类型
                }else if(uniqueID.contains("GY03B-")){
                    listConnectDevice->operator [](i).setDeviceType(HidDeviceInfo::DeviceType::_HID_KEYBOARD);      //设备类型
                }
                listConnectDevice->operator [](i).setDeviceUniqueID(uniqueID);
                qDebug() << "HID键盘返回信息-唯一编码：" << QString(HexToMessage(recvData.remove("FE F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE F5 07"){
                listConnectDevice->operator [](i).setDeviceCheckStep(QString(HexToMessage(recvData.remove("FE F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                qDebug() << "HID键盘返回信息-检测步骤：" << QString(HexToMessage(recvData.remove("FE F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
            }else if(order == "FE FF"){
                QStringList deviceNameOrDFU = QString(HexToMessage(recvData)).simplified().remove(QChar('\u0000')).split(' ');
                if(deviceNameOrDFU.count() >= 2){
                    listConnectDevice->operator [](i).setDeviceName(deviceNameOrDFU.at(0));
                    listConnectDevice->operator [](i).setDeviceDfuVersion(deviceNameOrDFU.at(1));
                    if(deviceNameOrDFU.at(0).contains("KEY_PAD")){                                                  //这是小键盘
                        listConnectDevice->operator [](i).setDeviceType(HidDeviceInfo::DeviceType::_HID_KEYPAD);    //设备类型
                    }
                }
                qDebug() << "HID键盘返回信息-DFU版本：" << listConnectDevice->at(i).getDeviceName() << " - " << listConnectDevice->at(i).getDeviceDfuVersion();
            }else if(order == "FE F6"){
                int batter_value=recvData.mid(6,2).toInt(nullptr, 16);                                              //读取的信息转为int值
                if(batter_value>100) {                                                                              //信息错误时会出现大于100的电量
                    batter_value=batter_value%100;                                                                  //尝试是否有其他方式模拟
                }
                QString batterLevel = QString("%1").arg(batter_value);
                QString batterType = QString("%1").arg(recvData.mid(9,2).toInt(nullptr, 16));
                bool isBatterType = true;
                if(batterType == "1"){
                    isBatterType = true;
                    if(batterLevel != listConnectDevice->at(i).getDeviceBatteryLevel() || isBatterType != listConnectDevice->at(i).getDeviceChargingState()){
                        listConnectDevice->operator [](i).setDeviceBatteryLevel(batterLevel);
                        emit signalBatteryChange(listConnectDevice->at(i).getDevicePortPath(), listConnectDevice->at(i).getDeviceBatteryLevel(), true, HidDeviceInfo::DeviceType::_HID_KEYBOARD);
                    }
                    listConnectDevice->operator [](i).setDeviceChargingState(true);
                }else{
                    isBatterType = false;
                    if(batterLevel != listConnectDevice->at(i).getDeviceBatteryLevel() || isBatterType != listConnectDevice->at(i).getDeviceChargingState()){
                        listConnectDevice->operator [](i).setDeviceBatteryLevel(batterLevel);
                        emit signalBatteryChange(listConnectDevice->at(i).getDevicePortPath(), listConnectDevice->at(i).getDeviceBatteryLevel(), false, HidDeviceInfo::DeviceType::_HID_KEYBOARD);
                    }
                    listConnectDevice->operator [](i).setDeviceChargingState(false);
                }
                qDebug() << "HID键盘返回信息-电量信息：" << batterLevel << " -充电状态- " << isBatterType;
            }
            break;
        }
    }
}

//读取数据
void GY_HIDKeyboard::slotReadyRead(const QString &portPath, QString &recvData)  //hid_device *Handle,
{
    qDebug() << "--HID键盘读取数据--：" << recvData;
    //-------------------------------------------------------HID鼠标读取--------------------------------------------------------------------
    if(recvData.left(8) == "FE F5 02" || recvData.left(8) == "fe f5 02"){
        this->setDeviceMessage(portPath, recvData, "FE F5 02", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 03" || recvData.left(8) == "fe f5 03"){
        this->setDeviceMessage(portPath, recvData, "FE F5 03", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 04" || recvData.left(8) == "fe f5 04"){
        this->setDeviceMessage(portPath, recvData, "FE F5 04", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 05" || recvData.left(8) == "fe f5 05"){
        this->setDeviceMessage(portPath, recvData, "FE F5 05", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 06" || recvData.left(8) == "fe f5 06"){
        this->setDeviceMessage(portPath, recvData, "FE F5 06", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 07" || recvData.left(8) == "fe f5 07"){
        this->setDeviceMessage(portPath, recvData, "FE F5 07", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(14) == "4C 69 67 68 74" || recvData.left(14) == "4c 69 67 68 74"){       //这里由于硬件传输问题需要将FE FF 改为获取FE 4c
        this->setDeviceMessage(portPath, recvData, "FE FF", HidDeviceInfo::_HID_KEYBOARD);
    }else if(recvData.left(5) == "FE F6" || recvData.left(5) == "fe f6"){
        this->setDeviceMessage(portPath, recvData, "FE F6", HidDeviceInfo::_HID_KEYBOARD);
    }
}
#pragma endregion}
