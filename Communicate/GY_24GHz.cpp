#include "GY_24GHz.h"

//读取设备信息，当设备连接成功后必须要做的一步
void GY_24GHz::GetDeviceReadMessage(const QString &portPath)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath() == portPath){
            this->WriteHandle(item->getDeviceHandle(), QByteArray("FC 10"));       //读取一次当前连接的设备5
            break;                                                                      //已经拿到信息后就可以即使的关闭循环状态节省资源
        }
    }
}

QList<HidDeviceInfo> *GY_24GHz::getListConnectDevice()
{
    return listConnectDevice;
}

//测试使用
void GY_24GHz::Write(const QString &data)
{
    for(auto item = 0; item < listConnectDevice->count(); item++){
        this->WriteHandle(listConnectDevice->at(item).getDeviceHandle(), data.toUtf8());
    }
}

#pragma region=================================== 工 具 方 式 类 ============================================{

bool GY_24GHz::Write(const QString &portPath, const QString &data, enum HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
        for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
            if(item->getDeviceUniqueID() == portPath){
                this->WriteHandle(item->getDeviceHandle(), data.toUtf8());
                return true;
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:
        if(listKeyboardConnect->isEmpty()) return false;
        for(auto item = 0; item < listKeyboardConnect->count(); item++){
            if(listKeyboardConnect->at(item).getDevicePortPath() == portPath){
                this->WriteHandle(listKeyboardConnect->at(item).getDeviceHandle(), data.toUtf8());
                return true;
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:
        if(listMouseConnect->isEmpty()){ qDebug() << "空" ;return false;}
        for(auto item = 0; item < listMouseConnect->count(); item++){
            qDebug() << "ID:" << listMouseConnect->at(item).getDeviceUniqueID() << portPath;
            if(listMouseConnect->at(item).getDevicePortPath() == portPath){
                this->WriteHandle(listMouseConnect->at(item).getDeviceHandle(), data.toUtf8());
                return true;
            }
        }
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool GY_24GHz::Write(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
        for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
            if(item->getDeviceUniqueID() == portPath){
                this->WriteHandle(item->getDeviceHandle(), data);
                return true;
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:

        if(listKeyboardConnect->isEmpty()) return false;
        for(auto item = 0; item < listKeyboardConnect->count(); item++){
            if(listKeyboardConnect->at(item).getDevicePortPath() == portPath){
                this->WriteHandle(listKeyboardConnect->at(item).getDeviceHandle(), data);
                return true;
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:

        if(listMouseConnect->isEmpty()) return false;
        for(auto item = 0; item != listMouseConnect->count(); item++){
            if(listMouseConnect->at(item).getDevicePortPath() == portPath){
                this->WriteHandle(listMouseConnect->at(item).getDeviceHandle(), data);
                return true;
            }
        }
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool GY_24GHz::Write(const QString &portPath, const QStringList &data, enum HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
    {
        for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
            if(item->getDevicePortPath() == portPath){
                for(int i = 0; i < data.count(); i++){
                    for(auto j = 0; j != listKeyboardConnect->count(); j++){
                        this->WriteHandle(listKeyboardConnect->at(j).getDeviceHandle(), data.at(i).toUtf8());
                        QThread::msleep(50);
                    }
                }
                return true;
            }
        }
        break;
    }
    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:
    {
        if(listMouseConnect->isEmpty()) return false;
        for(auto item = 0; item < listMouseConnect->count(); item++){
            if(listMouseConnect->at(item).getDevicePortPath() == portPath){
            }
        }
        for(int i = 0; i < data.count(); i++){
            for(auto item = 0; item < listMouseConnect->count(); item++){
                this->WriteHandle(listMouseConnect->at(item).getDeviceHandle(), data.at(i).toUtf8());
                QThread::msleep(50);
            }
        }
        return true;

        break;
    }
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:
    {
        if(listKeyboardConnect->isEmpty()) return false;
        for(auto item = 0; item != listKeyboardConnect->count(); item++){
            if(listKeyboardConnect->at(item).getDevicePortPath() == portPath){
                for(int i = 0; i < data.count(); i++){
                    this->WriteHandle(listKeyboardConnect->at(item).getDeviceHandle(), data.at(i).toUtf8());
                    QThread::msleep(50);
                }
            }
            return true;
        }
        break;
    }
    default:return false;
    }
    return false;
}

bool GY_24GHz::WriteChar(const QString &portPath, const QByteArray &data, enum HidDeviceInfo::DeviceType deviceType)
{
    switch(deviceType){
    case HidDeviceInfo::DeviceType::_24GHz_Adapter:
        for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
            if(item->getDevicePortPath() == portPath){
                return this->WriteHandleChar(item->getDeviceHandle(), data);
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_KEYBOARD:
        if(listKeyboardConnect->isEmpty()) return false;
        for(auto item = 0; item != listKeyboardConnect->count(); item++){
            if(listKeyboardConnect->at(item).getDevicePortPath() == portPath){
                return this->WriteHandleChar(listKeyboardConnect->at(item).getDeviceHandle(), data);
            }
        }
        break;
    case HidDeviceInfo::DeviceType::_24GHz_MOUSE:
        if(listMouseConnect->isEmpty()) return false;
        for(auto item = 0; item != listMouseConnect->count(); item++){
            if(listMouseConnect->at(item).getDevicePortPath() == portPath){
                return this->WriteHandleChar(listMouseConnect->at(item).getDeviceHandle(), data);
            }
        }
        break;
    default: return false;
    }
    return false;
}

void GY_24GHz::setDeviceMessage(const QString &portPath, const QString &Data, const QString &order, enum HidDeviceInfo::DeviceType deviceType)
{
    QString recvData = Data;    //赋值避免破坏传入信息
    switch(deviceType){
    case HidDeviceInfo::_24GHz_Adapter:
        for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
            if(item->getDevicePortPath() == portPath){
                if(order == "FC FF"){
                    QStringList deviceNameOrDFU = QString(HexToMessage(recvData)).simplified().remove(QChar('\u0000')).split(' ');
                    if(deviceNameOrDFU.count() >= 2){
                        item->setDeviceName(deviceNameOrDFU.at(0));
                        item->setDeviceDfuVersion(deviceNameOrDFU.at(1));
                    }
                    qDebug() << "适配器返回信息-DFU版本：" << item->getDeviceName() << " - " << item->getDeviceDfuVersion();
                }
            }
        }
        break;
    case HidDeviceInfo::_24GHz_MOUSE:
        for(auto item = listMouseConnect->begin(); item != listMouseConnect->end(); item++){
            if(item->getDevicePortPath() == portPath){
                if(order == "FD F5 02"){
                    item->setDeviceColor(QString(HexToMessage(recvData.remove("FD F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-设备颜色：" << QString(HexToMessage(recvData.remove("FD F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD F5 03"){
                    item->setDeviceProductTime(QString(HexToMessage(recvData.remove("FD F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-出厂时间：" << QString(HexToMessage(recvData.remove("FD F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD F5 04"){
                    item->setDeviceManufacturer(QString(HexToMessage(recvData.remove("FD F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-生产厂家：" << QString(HexToMessage(recvData.remove("FD F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD F5 05"){
                    item->setDeviceBatchNumber(QString(HexToMessage(recvData.remove("FD F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-设备批号：" << QString(HexToMessage(recvData.remove("FD F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD F5 06"){
                    item->setDeviceUniqueID(QString(HexToMessage(recvData.remove("FD F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-唯一编码：" << QString(HexToMessage(recvData.remove("FD F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD F5 07"){
                    item->setDeviceCheckStep(QString(HexToMessage(recvData.remove("FD F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G鼠标返回信息-检测步骤：" << QString(HexToMessage(recvData.remove("FD F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FD FF"){
                    QStringList deviceNameOrDFU = QString(HexToMessage(recvData.remove("FD FF", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')).split(' ');
                    if(deviceNameOrDFU.count() >= 2){
                        item->setDeviceName(deviceNameOrDFU.at(0));
                        item->setDeviceDfuVersion(deviceNameOrDFU.at(1));
                    }
                    qDebug() << "2.4G鼠标返回信息-DFU版本：" << item->getDeviceName() << " - " << item->getDeviceDfuVersion();
                }else if(order == "FD F6"){
                    int batter_value=recvData.mid(6,2).toInt(nullptr, 16);//读取的信息转为int值
                    if(batter_value>100)//信息错误时会出现大于100的电量
                        batter_value=batter_value%100;//尝试是否有其他方式模拟
                    QString batterLevel = QString("%1").arg(batter_value);
                    QString batterType = QString("%1").arg(recvData.mid(9,2).toInt(nullptr, 16));
                    bool isBatterType = true;
                    if(batterType == "1"){
                        isBatterType = true;
                        if(batterLevel != item->getDeviceBatteryLevel() || isBatterType != item->getDeviceChargingState()){
                            item->setDeviceBatteryLevel(batterLevel);
                            emit signal24GHzBattery(item->getDevicePortPath(), item->getDeviceBatteryLevel(), true, HidDeviceInfo::DeviceType::_24GHz_MOUSE);
                        }
                        item->setDeviceChargingState(true);
                    }else{
                        isBatterType = false;
                        if(batterLevel != item->getDeviceBatteryLevel() || isBatterType != item->getDeviceChargingState()){
                            item->setDeviceBatteryLevel(batterLevel);
                            emit signal24GHzBattery(item->getDevicePortPath(), item->getDeviceBatteryLevel(), true, HidDeviceInfo::DeviceType::_24GHz_MOUSE);
                        }
                        item->setDeviceChargingState(false);
                    }
                    qDebug() << "2.4G鼠标返回信息-电量信息：" << batterLevel << " -充电状态- " << isBatterType;
                }
                break;
            }
        }
        break;
    case HidDeviceInfo::_24GHz_KEYBOARD:
        for(auto item = listKeyboardConnect->begin(); item != listKeyboardConnect->end(); item++){
            if(item->getDevicePortPath() == portPath){
                if(order == "FE F5 02"){
                    item->setDeviceColor(QString(HexToMessage(recvData.remove("FE F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-设备颜色：" << QString(HexToMessage(recvData.remove("FE F5 02", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE F5 03"){
                    item->setDeviceProductTime(QString(HexToMessage(recvData.remove("FE F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-出厂时间：" << QString(HexToMessage(recvData.remove("FE F5 03", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE F5 04"){
                    item->setDeviceManufacturer(QString(HexToMessage(recvData.remove("FE F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-生产厂家：" << QString(HexToMessage(recvData.remove("FE F5 04", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE F5 05"){
                    item->setDeviceBatchNumber(QString(HexToMessage(recvData.remove("FE F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-设备批号：" << QString(HexToMessage(recvData.remove("FE F5 05", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE F5 06"){
                    item->setDeviceUniqueID(QString(HexToMessage(recvData.remove("FE F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-唯一编码：" << QString(HexToMessage(recvData.remove("FE F5 06", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE F5 07"){
                    item->setDeviceCheckStep(QString(HexToMessage(recvData.remove("FE F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')));
                    qDebug() << "2.4G键盘返回信息-检测步骤：" << QString(HexToMessage(recvData.remove("FE F5 07", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000'));
                }else if(order == "FE FF"){
                    QStringList deviceNameOrDFU = QString(HexToMessage(recvData.remove("FE", Qt::CaseInsensitive))).simplified().remove(QChar('\u0000')).split(' ');
                    if(deviceNameOrDFU.count() >= 2){
                        item->setDeviceName(deviceNameOrDFU.at(0));
                        item->setDeviceDfuVersion(deviceNameOrDFU.at(1));
                    }
                    qDebug() << "2.4G键盘返回信息-DFU版本：" << item->getDeviceName() << " - " << item->getDeviceDfuVersion();
                }else if(order == "FE F6"){
                    int batter_value=recvData.mid(6,2).toInt(nullptr, 16);//读取的信息转为int值
                    if(batter_value>100)//信息错误时会出现大于100的电量
                        batter_value=batter_value%100;//尝试是否有其他方式模拟
                    QString batterLevel = QString("%1").arg(batter_value);
                    QString batterType = QString("%1").arg(recvData.mid(9,2).toInt(nullptr, 16));
                    bool isBatterType = true;
                    if(batterType == "1"){
                        isBatterType = true;
                        if(batterLevel != item->getDeviceBatteryLevel() || isBatterType != item->getDeviceChargingState()){
                            item->setDeviceBatteryLevel(batterLevel);
                            emit signal24GHzBattery(item->getDevicePortPath(), item->getDeviceBatteryLevel(), true, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
                        }
                        item->setDeviceChargingState(true);

                    }else{
                        isBatterType = false;
                        if(batterLevel != item->getDeviceBatteryLevel() || isBatterType != item->getDeviceChargingState()){
                            item->setDeviceBatteryLevel(batterLevel);
                            emit signal24GHzBattery(item->getDevicePortPath(), item->getDeviceBatteryLevel(), true, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
                        }
                        item->setDeviceChargingState(false);
                    }
                    qDebug() << "2.4G键盘返回信息-电量信息：" << batterLevel << " -充电状态- " << isBatterType << " = " << item->getDeviceChargingState();
                }
                break;
            }
        }
        break;
    default: break;
    }
}

//读取数据
void GY_24GHz::slotReadyRead(const QString &portPath, QString &recvData)  //hid_device *Handle,
{
    qDebug() << "--2.4G读取数据--：" << recvData;
    //------------------------------------------------------适配器读取-------------------------------------------------------------
    if(recvData.left(5) == "FC 10" || recvData.left(5) == "fc 10"){            //FC 10 判断2.4适配器是否连接了键盘或者鼠标
        this->GetDeviceMouseOrKeyboard(portPath, recvData);
    }else if(recvData.left(8) == "FC F5 03" || recvData.left(8) == "fc f5 03"){

    }else if(recvData.left(14) == "4C 69 67 68 74" || recvData.left(14) == "4c 69 67 68 74"){
        this->setDeviceMessage(portPath, recvData, "FC FF", HidDeviceInfo::_24GHz_Adapter);
    }
    //------------------------------------------------------鼠标读取-------------------------------------------------------------
    if(recvData.left(8) == "FD F5 02" || recvData.left(8) == "fd f5 02"){
        this->setDeviceMessage(portPath, recvData, "FD F5 02", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(8) == "FD F5 03" || recvData.left(8) == "fd f5 03"){
        this->setDeviceMessage(portPath, recvData, "FD F5 03", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(8) == "FD F5 04" || recvData.left(8) == "fd f5 04"){
        this->setDeviceMessage(portPath, recvData, "FD F5 04", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(8) == "FD F5 05" || recvData.left(8) == "fd f5 05"){
        this->setDeviceMessage(portPath, recvData, "FD F5 05", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(8) == "FD F5 06" || recvData.left(8) == "fd f5 06"){
        this->setDeviceMessage(portPath, recvData, "FD F5 06", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(8) == "FD F5 07" || recvData.left(8) == "fd f5 07"){
        this->setDeviceMessage(portPath, recvData, "FD F5 07", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(5) == "FD 4C" || recvData.left(5) == "fd ff"){       //这里由于硬件传输问题需要将FE FF 改为获取FE 4c
        this->setDeviceMessage(portPath, recvData, "FD FF", HidDeviceInfo::_24GHz_MOUSE);
    }else if(recvData.left(5) == "FD F6" || recvData.left(5) == "fd f6"){
        this->setDeviceMessage(portPath, recvData, "FD F6", HidDeviceInfo::_24GHz_MOUSE);
    }
    //------------------------------------------------------键盘读取-------------------------------------------------------------
    if(recvData.left(8) == "FE F5 02" || recvData.left(8) == "fe f5 02"){
        this->setDeviceMessage(portPath, recvData, "FE F5 02", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 03" || recvData.left(8) == "fe f5 03"){
        this->setDeviceMessage(portPath, recvData, "FE F5 03", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 04" || recvData.left(8) == "fe f5 04"){
        this->setDeviceMessage(portPath, recvData, "FE F5 04", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 05" || recvData.left(8) == "fe f5 05"){
        this->setDeviceMessage(portPath, recvData, "FE F5 05", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 06" || recvData.left(8) == "fe f5 06"){
        this->setDeviceMessage(portPath, recvData, "FE F5 06", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(8) == "FE F5 07" || recvData.left(8) == "fe f5 07"){
        this->setDeviceMessage(portPath, recvData, "FE F5 07", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(5) == "FE 4C" || recvData.left(5) == "fe 4c"){       //这里由于硬件传输问题需要将FE FF 改为获取FE 4c
        this->setDeviceMessage(portPath, recvData, "FE FF", HidDeviceInfo::_24GHz_KEYBOARD);
    }else if(recvData.left(5) == "FE F6" || recvData.left(5) == "fe f6"){
        this->setDeviceMessage(portPath, recvData, "FE F6", HidDeviceInfo::_24GHz_KEYBOARD);
    }
}

//获取设备类型 FC 10 01 01 前01为鼠标  后01为键盘
void GY_24GHz::GetDeviceMouseOrKeyboard(const QString &portPath, const QString &readData)
{
    QString recvData = readData;

    //根据path为核心 判断是否出现了频繁的连接断开
    bool mouse_connect,keyboard_connect;

    if(!QString(HexToMessage(recvData.mid(6, 2))).remove(" ").remove(QChar('\u0000')).isEmpty())
        mouse_connect=1;
    else
        mouse_connect=0;
    if( !QString(HexToMessage(recvData.mid(9, 2))).remove(" ").remove(QChar('\u0000')).isEmpty())
        keyboard_connect=1;
    else
        keyboard_connect=0;
    qDebug()<<"测试连接"<<mouse_connect<<keyboard_connect;

    _24GHz_port_path=portPath;  //这组信息是单设备的 可能多个适配器会有问题
    //------------------------------------------------------以下判断鼠标是否连接成功-------------------------------------------------------------
    if(mouse_connect){           //鼠标连接
        //直接给一个延时
        QTimer::singleShot(200, this, [=](){
            this->_24GHzMouseConnect(portPath);//这个根据portpath来区别设备
            qDebug() << "-----2.4鼠标连接成功-----" << listConnectDevice->count();
            if(!isMouseConnect){    //这时候并没有键盘，直接连接即可
                if(!timerMouseBattery->isActive()){
                    timerMouseBattery->start(_TIME_MOUSE);
                }
                isMouseConnect = true;
            }
        });
    }else{                                                                                                  //鼠标断开
        if(isMouseConnect){
            //关于断开这里 多设备要考虑情况 单独删除设备 都删空了再调整参数
            for(int i = 0; i < listMouseConnect->count(); i++)
                if(listMouseConnect->at(i).getDevicePortPath() == portPath)
                {
                    listMouseConnect->removeAt(i);//删除设备
                    qDebug() << "-----2.4鼠标断开连接-----" << listConnectDevice->count() << portPath;
                    emit signal24GHzDisconnection(portPath, HidDeviceInfo::DeviceType::_24GHz_MOUSE);
                    break;
                }
            if(listMouseConnect->isEmpty()){
                timerMouseBattery->stop();
                isMouseConnect = false;
            }
        }
    }
    //------------------------------------------------------以下判断键盘是否连接成功-------------------------------------------------------------
    if(keyboard_connect){           //键盘连接
        this->_24GHzKeyboardConnect(portPath);//多个键盘连接
        if(!isKeyboardConnect){
            qDebug() << "-----2.4键盘连接成功-----" << listConnectDevice->count();
            if(!timerKeyboardBattery->isActive()){
                timerKeyboardBattery->start(_TIME_KEYBOARD);
            }
        }
        isKeyboardConnect = true;
    }else{                                                                                                  //键盘断开
        if(isKeyboardConnect){
            for(int i = 0; i < listKeyboardConnect->count(); i++)
                if(listKeyboardConnect->at(i).getDevicePortPath() == portPath)
                {
                    listKeyboardConnect->removeAt(i);//删除设备
                    qDebug() << "-----2.4键盘断开连接-----" << listConnectDevice->count()<<portPath;
                    emit signal24GHzDisconnection(portPath, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
                    break;
                }
            if(listKeyboardConnect->isEmpty()){
                timerKeyboardBattery->stop();
                isKeyboardConnect=false;
            }
        }
    }
    emit signal24GHzKeyboardOrMouseConnected(isKeyboardConnect,isMouseConnect);
}
//多设备发现这里有重复调用的情况 改为单次添加设备
void GY_24GHz::_24GHzMouseConnect(const QString &portPath)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath()!=portPath)
            continue;//过滤不相关设备
        //过滤相同设备重复发送了连接的信息
        for(int j=0;j<listMouseConnect->count();j++)
            if(listMouseConnect->at(j).getDevicePortPath()==portPath)
                return;//重复直接退出

        HidDeviceInfo deviceInfo;
        deviceInfo.setDeviceHandle(item->getDeviceHandle());                //设备handle信息
        deviceInfo.setDevicePortPath(item->getDevicePortPath());            //设备路径信息
        deviceInfo.setDeviceType(HidDeviceInfo::DeviceType::_24GHz_MOUSE);  //设备类型信息
        deviceInfo.setIsConnectStatus(true);                                //设备连接状态信息
        listMouseConnect->append(deviceInfo);
        this->WriteHandle(item->getDeviceHandle(), QByteArray("FD F5 02")); //设备颜色
        QTimer::singleShot(200, this, [=](){
            for(int i = 0; i < listMouseConnect->count(); i++){
                if(listMouseConnect->at(i).getDevicePortPath() == deviceInfo.getDevicePortPath()){
                    emit signal24GHzConnection(listMouseConnect->at(i), HidDeviceInfo::DeviceType::_24GHz_MOUSE);
                }
            }
        });
    }
}

void GY_24GHz::_24GHzKeyboardConnect(const QString &portPath)
{
    for(auto item = listConnectDevice->begin(); item != listConnectDevice->end(); item++){
        if(item->getDevicePortPath()!=portPath)
            continue;//过滤不相关设备
        //过滤相同设备重复发送了连接的信息
        for(int j=0;j<listKeyboardConnect->count();j++)
            if(listKeyboardConnect->at(j).getDevicePortPath()==portPath)
                return;//重复直接退出

        this->WriteHandle(item->getDeviceHandle(), QByteArray("FE F5 02"));     //设备颜色
        HidDeviceInfo deviceInfo;
        deviceInfo.setDeviceHandle(item->getDeviceHandle());                    //设备handle信息
        deviceInfo.setDevicePortPath(item->getDevicePortPath());                //设备路径信息
        deviceInfo.setDeviceType(HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);   //设备类型信息
        deviceInfo.setIsConnectStatus(true);                                    //设备连接状态信息
        listKeyboardConnect->append(deviceInfo);

        QTimer::singleShot(200, this, [=](){
            for(int i = 0; i < listKeyboardConnect->count(); i++){
                if(listKeyboardConnect->at(i).getDevicePortPath() == deviceInfo.getDevicePortPath()){
                    emit signal24GHzConnection(listKeyboardConnect->at(i), HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
                }
            }
        });
    }
}

void GY_24GHz::slotsAdapterConnect(const QString &portPath)
{
    this->GetDeviceReadMessage(portPath);
    qDebug()<<"---------------------------------------适配器连接成功--------------------------------------------------" ;
    for(int i = 0; i < this->getListConnectDevice()->count(); i++){
        if(this->getListConnectDevice()->at(i).getDevicePortPath() == portPath){
            emit signal24GHzConnection(this->getListConnectDevice()->at(i), HidDeviceInfo::DeviceType::_24GHz_Adapter);
            break;
        }
    }
}

void GY_24GHz::slotsAdapterDisconnect(const QString &portPath)
{
    //关于断开这里 多设备要考虑情况 单独删除设备 都删空了再调整参数
    if(isKeyboardConnect){
        for(int i = 0; i < listKeyboardConnect->count(); i++)
            if(listKeyboardConnect->at(i).getDevicePortPath() == portPath){
                listKeyboardConnect->removeAt(i);//删除设备
                qDebug() << "-----2.4键盘断开连接-----" << listConnectDevice->count()<<portPath;
                emit signal24GHzDisconnection(portPath, HidDeviceInfo::DeviceType::_24GHz_KEYBOARD);
                break;
            }
        if(listKeyboardConnect->isEmpty()){
            timerKeyboardBattery->stop();
            isKeyboardConnect=false;
        }
    }
    if(isMouseConnect){
        //关于断开这里 多设备要考虑情况 单独删除设备 都删空了再调整参数
        for(int i = 0; i < listMouseConnect->count(); i++)
            if(listMouseConnect->at(i).getDevicePortPath() == portPath) {
                listMouseConnect->removeAt(i);//删除设备
                qDebug() << "-----2.4鼠标断开连接-----" << listConnectDevice->count() << portPath;
                emit signal24GHzDisconnection(portPath, HidDeviceInfo::DeviceType::_24GHz_MOUSE);
                break;
            }
        if(listMouseConnect->isEmpty()){
            timerMouseBattery->stop();
            isMouseConnect = false;
        }
    }
    emit signal24GHzDisconnection(portPath, HidDeviceInfo::DeviceType::_24GHz_Adapter);
    qDebug()<<"发送信号 适配器断开了";
}

void GY_24GHz::slotGet_24GHzMouseBattery()
{
    qDebug()<<"定时器轮询读取鼠标电量";
    for(int i = 0; i < listMouseConnect->count(); i++){
        this->WriteHandle(listMouseConnect->at(i).getDeviceHandle(), QByteArray("FD F6"));        //电量读取
    }
}

void GY_24GHz::slotGet_24GHzKeyboardBattery()
{
    qDebug()<<"定时器轮询读取键盘电量";
    for(int i = 0; i < listKeyboardConnect->count(); i++){
        this->WriteHandle(listKeyboardConnect->at(i).getDeviceHandle(), QByteArray("FE F6"));        //电量读取
    }
}

#pragma endregion}
