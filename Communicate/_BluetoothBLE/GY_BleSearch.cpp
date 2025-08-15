#include "GY_BleSearch.h"

GY_BleSearch::GY_BleSearch(QObject *parent): QObject{parent}
{
    ListKeyboardName << "L&S_Key" << "JIAN·壹" << "Keyboard";
    ListMouseName << "Mouse" << "SHU";
}

GY_BleSearch::~GY_BleSearch()
{
    deviceDiscover->deleteLater();
}

//搜索开启
void GY_BleSearch::GY_StartSearchDevice(const int &searchTimer, const bool &isWhile)
{
    this->isWhile = isWhile;
    qDebug() << "Bluetooth====搜索线程-Search:" <<QThread::currentThreadId();
    deviceDiscover = new QBluetoothDeviceDiscoveryAgent(this);
    connect(deviceDiscover, &QBluetoothDeviceDiscoveryAgent::finished, this, &GY_BleSearch::slotBluetoothSearchFinished);
    connect(deviceDiscover, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &GY_BleSearch::slotDeviceDiscovered);//成功搜索到
    deviceDiscover->setLowEnergyDiscoveryTimeout(searchTimer);                  //0一直跑/单位毫秒 | 25s
    deviceDiscover->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);     //开始搜索
}
//蓝牙搜索完成
void GY_BleSearch::slotBluetoothSearchFinished()
{
    QList<QBluetoothDeviceInfo> listConnectKeyboardInfo;
    QList<QBluetoothDeviceInfo> listConnectMouseInfo;
    for(int k = 0; k < deviceDiscover->discoveredDevices().count(); k++){
        for(int i = 0; i < ListKeyboardName.count(); i++){
            if(deviceDiscover->discoveredDevices().at(i).name().contains(ListKeyboardName.at(i)) ) listConnectKeyboardInfo.append(deviceDiscover->discoveredDevices().at(i));
        }
        for(int i = 0; i < ListMouseName.count(); i++ ){
            if(deviceDiscover->discoveredDevices().at(i).name().contains(ListMouseName.at(i)) ) listConnectMouseInfo.append(deviceDiscover->discoveredDevices().at(i));
        }
    }
    emit sendKeyboardSearchFinished(listConnectKeyboardInfo);
    emit sendMouseSearchFinished(listConnectMouseInfo);
    delete deviceDiscover;          //这里清缓存
    if(this->isWhile){
        this->GY_StartSearchDevice();
    }
}
//蓝牙搜索到对应蓝牙名称
void GY_BleSearch::slotDeviceDiscovered(const QBluetoothDeviceInfo &info)
{
    for(int i = 0; i < ListKeyboardName.count(); i++){
        if(info.name().contains(ListKeyboardName.at(i)) ){
            emit sendKeyboardSearchInfo(info);
        }
    }
    for(int i = 0; i < ListMouseName.count(); i++ ){
        if(info.name().contains(ListMouseName.at(i)) ) {
            emit sendMouseSearchInfo(info);
        }
    }
}
void GY_BleSearch::GY_StopSearch()
{
    deviceDiscover->stop();
}

