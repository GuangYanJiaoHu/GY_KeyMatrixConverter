#ifndef GY_READFILE_H
#define GY_READFILE_H

//该类仅用于读取json bin 与写入 json bin
#include <QObject>
#include <GY_Tools/GY_KeyboardTools.h>
class GY_ReadFile : public QObject
{
    Q_OBJECT
public:
    struct JsonPublicInfo{
        int _KeyBoardCount;                          //键盘个数  读取后显示界面
        QByteArray _Max;                             //最大值
        QByteArray _Min;                             //最小值
        QByteArray _WhiteBalance;                    //白平衡
        QByteArray _Shaft;                           //键轴表
        QByteArray _ShaftInfo;                       //键轴信息
        QByteArray _MULTIPLE_SET;                    //多组预设  读取后显示界面
        QByteArray _RETURN_SPEED;                    //回报率   读取后显示界面
        QByteArray _SCAN_SPEED;                      //扫描率   读取后显示界面
        QByteArray _AnimationStatic;                 //静态动画
        QByteArray _AnimationTurnOn;                 //开机动画
        QByteArray _AnimationDynamic;                //动态动画
        QByteArray _AnimationDeep;                   //深度动画
        GY_KeyboardTools::KeyboardType _KeyboardType;//键盘类型
    };


public:
    explicit GY_ReadFile(QObject *parent = nullptr);
    GY_KeyboardTools::JsonPrivateInfo getJsonPrivateInfo(QString path); //读取与解析json文件

    /**
     * @brief getExprotBinFile  获取生成bin文件
     * @param jsonPublicInfo    公有内容
     * @param jsonPrivateInfo   私有内容
     * @param binFile           空白bin文件
     * @return
     */
    QByteArray getExprotBinFile(GY_ReadFile::JsonPublicInfo jsonPublicInfo, QList<GY_KeyboardTools::JsonPrivateInfo> jsonPrivateInfo, QByteArray binFileInfo); //获取导出bin文件
    QByteArray getExportBinFile(QList<QMap<int, GY_ReadFile::JsonPublicInfo>> listMapJsonInfo, QByteArray binFileData, QByteArray dynamicAnimation, QByteArray staticAnimation, QByteArray turnOnAnimation, QByteArray deepAnimation, int keboardTypeNumber);


signals:

};

#endif // GY_READFILE_H
