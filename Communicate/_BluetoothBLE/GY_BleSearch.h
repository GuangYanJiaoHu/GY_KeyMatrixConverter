#ifndef GY_BLESEARCH_H
#define GY_BLESEARCH_H
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QThread>
#include <QObject>

class GY_BleSearch : public QObject
{
    Q_OBJECT
public:
    explicit GY_BleSearch(QObject *parent = nullptr);
    ~GY_BleSearch();
    void GY_StopSearch();
    void GY_StartSearchDevice(const int &searchTimer = 15000, const bool &isWhile = true);

signals:
    void sendKeyboardSearchInfo(const QBluetoothDeviceInfo &info);               //键盘蓝牙搜索信息
    void sendKeyboardSearchFinished(const QList<QBluetoothDeviceInfo> &infoList);//键盘蓝牙搜索完成

    void sendMouseSearchInfo(const QBluetoothDeviceInfo &info);                  //鼠标蓝牙搜索信息
    void sendMouseSearchFinished(const QList<QBluetoothDeviceInfo> &infoList);   //鼠标蓝牙搜索完成

private slots:
    void slotBluetoothSearchFinished();                                 //蓝牙搜索完成
    void slotDeviceDiscovered(const QBluetoothDeviceInfo &info);        //蓝牙搜索到对应蓝牙名称

private:
    QBluetoothDeviceDiscoveryAgent *deviceDiscover;
    QList<QString> ListMouseName;
    QList<QString> ListKeyboardName;
    QThread *thradSearch;
    bool isWhile;
};

#endif // GY_BLESEARCH_H
