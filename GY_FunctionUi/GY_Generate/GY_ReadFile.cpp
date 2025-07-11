#include "GY_ReadFile.h"

GY_ReadFile::GY_ReadFile(QObject *parent)
    : QObject{parent}
{

}

//读取与解析json文件
GY_KeyboardTools::JsonPrivateInfo GY_ReadFile::getJsonPrivateInfo(QString path)
{
    GY_KeyboardTools::JsonPrivateInfo jsonPrivateInfo;
    //读取文件内容
    QByteArray jsonData;    //读取的json数据
    QFile file(path);
    if(file.open(QFileDevice::ReadOnly)){
        jsonData = file.readAll();
    }else{
        return jsonPrivateInfo;
    }

    int keyBoardCount;
    // 解析JSON数据
    QJsonDocument jsonDocument(QJsonDocument::fromJson(jsonData));
    if (jsonDocument.isNull()) {
        qDebug() << "json解析有问题";
        keyBoardCount = -1;
        return jsonPrivateInfo;
    }
    //==============================================================解析动画信息、多组预设、回报率、扫描率==========================================================================
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("0000"));     //动画信息
    QJsonObject jsonObject = jsonDocument.object();
    QJsonObject keyboardType70 = jsonObject.value("KeyboardType-70").toObject();
    keyBoardCount = keyboardType70.value("KeyBoardCount").toInt();                      //键盘个数
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("LightingBrightness").toInt(), 2, 16, QLatin1Char('0')).toUtf8() ));
    if(keyboardType70.value("AnimationNumber").toInt() == 0){
        jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("00"));
    }else{
        jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("01"));
    }
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationNumber").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationDirection").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationSpeed").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    if(keyboardType70.value("AnimationDynamicNumber").toInt() == 0){
        jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("00"));
    }else{
        jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("01"));
    }
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationDynamicNumber").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationDynamicSpeed").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex("01"));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationBaseBrightness").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._ANIMATION_INFO.append(QByteArray::fromHex(QString("%1").arg(keyboardType70.value("AnimationBrightness").toInt(), 2, 16, QLatin1Char('0')).toUtf8()));
    jsonPrivateInfo._MULTIPLE_SET = QByteArray::fromHex(QString("%1").arg(keyboardType70.value("MultipleSetsOfPresets").toInt(), 2, 16, QLatin1Char('0')).toUtf8());
    jsonPrivateInfo._RETURN_SPEED = QByteArray::fromHex(keyboardType70.value("ReturnSpeed").toString().toUtf8());
    jsonPrivateInfo._SCAN_SPEED   = QByteArray::fromHex(keyboardType70.value("ScanRate").toString().toUtf8());
    jsonPrivateInfo._KeyBoardCount= keyboardType70.value("KeyBoardCount").toInt();

    //--------------------------------------------------------------------------解析定高、触发、抬起、高级键、模式、灯、轴---------------------------------------------------------------------------------------------
    // 解析键盘键位列表
    QJsonArray keyBoardBinList = keyboardType70.value("KeyBoardBinList").toArray();
    GY_KeyboardTools::JsonPrivateOnlyKeyInfo jsonOnly;
    for(int i = 0; i < keyBoardBinList.count(); i++){
        QJsonObject keyBoardBinListObject = keyBoardBinList.at(i).toObject();
        jsonOnly._FIXED_HEIGHT    = GY_KeyboardTools::getFlotaToByteArray(keyBoardBinListObject.value("FixHeightVal").toDouble());
        jsonOnly._RT_DOWN         = GY_KeyboardTools::getFlotaToByteArray(keyBoardBinListObject.value("RTLVal").toDouble());
        jsonOnly._Rt_UP           = GY_KeyboardTools::getFlotaToByteArray(keyBoardBinListObject.value("RTRVal").toDouble());
        jsonOnly._SECONDARY_TIGGER= GY_KeyboardTools::getFlotaToByteArray(keyBoardBinListObject.value("AKTwoVal").toDouble()) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0);  //补两位空
        jsonOnly._RT_STATE        = QByteArray::fromHex(keyBoardBinListObject.value("Mode").toString().toUtf8());
        jsonOnly._LightColor      = QByteArray::fromHex(keyBoardBinListObject.value("LightColor").toString().right(6).toUtf8());
        jsonOnly._FnKeyValue      = QByteArray::fromHex("01") + QByteArray::fromHex("00")  + QByteArray::fromHex(keyBoardBinListObject.value("FnKeyValue").toString().right(2).toUtf8());
        jsonOnly._KeyValue        = QByteArray::fromHex("01") + QByteArray::fromHex("00")  + QByteArray::fromHex(keyBoardBinListObject.value("KeyValue").toString().right(2).toUtf8());
        jsonPrivateInfo._JsonPrivateOnlyKeyInfo.append(jsonOnly);
    }
    // 解析高级键列表
    QJsonArray AdvancedKeyList = keyboardType70.value("AdvancedKeyList").toArray();
    for(int i = 0; i < AdvancedKeyList.count(); i++){
        QJsonObject AdvancedKeyObject = AdvancedKeyList.at(i).toObject();
        int AdvancedKeyType = AdvancedKeyObject.value("AKType").toInt();
        QByteArray data;
        switch(AdvancedKeyType){
        case 1:
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("AKCoverMode").toString().toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("preKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("nextKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("AKDelaySwitch").toString().toUtf8()));
            data += ( QByteArray::fromHex("00"));
            break;
        case 2:
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("AKDelaySwitch").toString().toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("preKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("nextKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyObject.value("AKStopDelayTime").toInt(), 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            break;
        case 3:
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("preKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("nextKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            break;
        case 4:
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyObject.value("MTSlider").toInt(), 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("preKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("nextKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("MTSliderSwitch").toString().toUtf8()));
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyObject.value("MTDoubleSlider").toInt(), 2, 10, QLatin1Char('0')).toUtf8()));
            break;
        case 5:
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex(AdvancedKeyObject.value("preKeyValue").toString().right(2).toUtf8()));
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyObject.value("nextKeyValue").toInt(), 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            break;
        default: AdvancedKeyType = 0;
            data += ( QByteArray::fromHex(QString("%1").arg(AdvancedKeyType, 2, 10, QLatin1Char('0')).toUtf8()));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            data += ( QByteArray::fromHex("00"));
            break;
        }
        jsonPrivateInfo._JsonPrivateOnlyKeyInfo[i]._AKType = AdvancedKeyType;
        jsonPrivateInfo._JsonPrivateOnlyKeyInfo[i]._AdvancedKey = data;
    }
    return jsonPrivateInfo;
}
//处理生成bin文件专用
QByteArray GY_ReadFile::getExprotBinFile(JsonPublicInfo jsonPublicInfo, QList<GY_KeyboardTools::JsonPrivateInfo> jsonPrivateInfo, QByteArray binFileInfo)
{
    //对公有文件内容写入
    //首先要确认键盘类型，将动画文件先行写入   无论是否需要动画写入，豆花都是必须写入的内容
    QByteArray binFile = binFileInfo;
    switch(jsonPublicInfo._KeyboardType){
    case GY_KeyboardTools::KeyboardType::_Keyboard_60_CN_:
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_StaticAnimation_ADDR , jsonPublicInfo._AnimationStatic.size(), jsonPublicInfo._AnimationStatic);   //静态动画写入
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_TurnOnAnimation_ADDR,  jsonPublicInfo._AnimationTurnOn.size(), jsonPublicInfo._AnimationTurnOn);   //开机动画写入
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_DynamicAnimation_ADDR, jsonPublicInfo._AnimationDynamic.size(),jsonPublicInfo._AnimationDynamic);  //动态动画写入
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_DeepAnimation_ADDR,    jsonPublicInfo._AnimationDeep.size(),   jsonPublicInfo._AnimationDeep);     //深度动画写入
        break;
    default:    break;
    }

    //---------------------------------------判断是否要对私有内容中数据进行改动，如果没有私有数据，则公有信息只写入动画文件，不写入其他文件--------------------------------------------------------------------
    for(int i = 0; i < jsonPrivateInfo.count(); i++){
        //---------------------------------------------------------------写入公有内容------------------------------------------------------------------------------------------------------------
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_FLASH_SAVE_ADDR, jsonPublicInfo._Max.size(), jsonPublicInfo._Max);                                      //最大值
        qDebug() << "写入最大值大小:" << jsonPublicInfo._Max.size() << " 起始位置：" <<GY_KeyboardTools::Keyboard60_Bin_Addr::_FLASH_SAVE_ADDR ;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_MIN_VALUES_ADDR, jsonPublicInfo._Min.size(), jsonPublicInfo._Min);                                      //最小值
        qDebug() << "写入最小值大小:" << jsonPublicInfo._Min.size() << " 起始位置：" <<GY_KeyboardTools::Keyboard60_Bin_Addr::_MIN_VALUES_ADDR ;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_DEAD_ZONE_ADDR , jsonPublicInfo._WhiteBalance.size(), jsonPublicInfo._WhiteBalance);  //死区+白平衡
        qDebug() << "写入白平衡大小:" << jsonPublicInfo._WhiteBalance.size() << " 起始位置：" <<GY_KeyboardTools::Keyboard60_Bin_Addr::_DEAD_ZONE_ADDR;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_AXISTYPE_SAVE_ADDR  , jsonPublicInfo._Shaft.size(), jsonPublicInfo._Shaft);                             //键轴表
        qDebug() << "写入键轴表大小:" << jsonPublicInfo._Shaft.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_AXISTYPE_SAVE_ADDR;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_RANGEVALUE_SAVE_ADDR, jsonPublicInfo._ShaftInfo.size(), jsonPublicInfo._ShaftInfo);                     //键轴信息
        qDebug() << "写入键轴信息大小:" << jsonPublicInfo._ShaftInfo.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_RANGEVALUE_SAVE_ADDR;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_CONFIGUR_GROUP_ADDR , jsonPublicInfo._MULTIPLE_SET.size(), jsonPublicInfo._MULTIPLE_SET);               //预多组预设
        qDebug() << "写入多组预设大小:" << jsonPublicInfo._MULTIPLE_SET.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_CONFIGUR_GROUP_ADDR;
        binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_RATE_OF_RETURN_ADDR , jsonPublicInfo._RETURN_SPEED.size(), jsonPublicInfo._RETURN_SPEED);               //回报率
        qDebug() << "写入回报率大小:" << jsonPublicInfo._RETURN_SPEED.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_RATE_OF_RETURN_ADDR;

        //----------------------------------------------------比对当前json私有内容中的按键个数(记录的list数量)是否跟要写入的按键数量吻合------------------------------------------------------------------
        if(jsonPrivateInfo.first()._JsonPrivateOnlyKeyInfo.count() == jsonPublicInfo._KeyBoardCount){
            //-------------------------------------------------------------------------私有数据原样写回-----------------------------------------------------------------------------------------------
            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_SCAN_RATE_ADDR      + (4096 * 32 * i), jsonPrivateInfo.at(i)._SCAN_SPEED.size()    , jsonPrivateInfo.at(i)._SCAN_SPEED);        //扫描率
            qDebug() << "写入扫描率大小:" << jsonPrivateInfo.at(i)._SCAN_SPEED.size()   << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_SCAN_RATE_ADDR + (4096 * 32 * i) ;

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_ANIMATION_DATA_ADDR + (4096 * 32 * i), jsonPrivateInfo.at(i)._ANIMATION_INFO.size(), jsonPrivateInfo.at(i)._ANIMATION_INFO);    //动画信息
            qDebug() << "写入动画信息大小:" << jsonPrivateInfo.at(i)._ANIMATION_INFO.size()<< " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_ANIMATION_DATA_ADDR + (4096 * 32 * i);
            //---------------------------------------------------------写入每个按键的信息(私有信息需要对N个按键数据内容整合)--------------------------------------------------------------------------------
            QByteArray _RT_DOWN;                 //RT触发
            QByteArray _Rt_UP;                   //RT抬起
            QByteArray _RT_STATE;                //RT状态
            QByteArray _FIXED_HEIGHT;            //定高
            QByteArray _LightColor;              //灯颜色
            QByteArray _KeyValue;                //键值
            QByteArray _FnKeyValue;              //FN键值
            QByteArray _AdvancedKey;             //高级键
            QByteArray _SECONDARY_TIGGER;        //多段触发  与 定高 公用一个值

            for(int j = 0; j < jsonPublicInfo._KeyBoardCount; j++){
                _FIXED_HEIGHT       += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._FIXED_HEIGHT;
                _RT_DOWN            += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._RT_DOWN;
                _Rt_UP              += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._Rt_UP;
                _RT_STATE           += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._RT_STATE;
                _LightColor         += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._LightColor;
                _KeyValue           += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._KeyValue;
                _FnKeyValue         += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._FnKeyValue;
                _AdvancedKey        += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._AdvancedKey;
                _SECONDARY_TIGGER   += jsonPrivateInfo.at(i)._JsonPrivateOnlyKeyInfo.at(j)._SECONDARY_TIGGER;
            }
            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_THRESHOLD_VALUES_ADDR + (4096 * 32 * i), _FIXED_HEIGHT.size()    , _FIXED_HEIGHT);      //定高表
            qDebug() << "写入定高表大小:" << _FIXED_HEIGHT.size()<< " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_THRESHOLD_VALUES_ADDR + (4096 * 32 * i);

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_DOWN_ADDR          + (4096 * 32 * i), _RT_DOWN.size()         , _RT_DOWN);           //RT触发
            qDebug() << "写入RT触发大小:" << _RT_DOWN.size()     << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_DOWN_ADDR + (4096 * 32 * i) << "写入内容：" << _RT_DOWN;

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_UP_VALUES_ADDR     + (4096 * 32 * i), _Rt_UP.size()           , _Rt_UP);             //RT抬起
            qDebug() << "写入RT抬起大小:" << _Rt_UP.size()       << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_UP_VALUES_ADDR + (4096 * 32 * i) << "写入内容：" << _Rt_UP;

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_ENABLE_STATE_ADDR  + (4096 * 32 * i), _RT_STATE.size()        , _RT_STATE);          //RT状态
            qDebug() << "写入RT状态大小:" << _RT_STATE.size()       << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_RT_UP_VALUES_ADDR + (4096 * 32 * i) << "写入内容：" << _RT_STATE;

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_LED_SAVE_ADDR         + (4096 * 32 * i), _LightColor.size()      , _LightColor);        //灯存储信息
            qDebug() << "写入灯存储信息大小:" << _LightColor.size()<< " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_LED_SAVE_ADDR + (4096 * 32 * i);

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_FUNCT_SAVE_ADDR       + (4096 * 32 * i), _KeyValue.size()        , _KeyValue);          //键值表
            qDebug() << "写入键值表大小:" << _KeyValue.size()     << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_FUNCT_SAVE_ADDR + (4096 * 32 * i);

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_FUNCT_FN_SAVE_ADDR    + (4096 * 32 * i), _FnKeyValue.size()      , _FnKeyValue);        //FN键值表
            qDebug() << "写入FN键值表大小:" << _FnKeyValue.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_FUNCT_FN_SAVE_ADDR + (4096 * 32 * i);

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_MACRO_DEFINE_ADDR     + (4096 * 32 * i), _AdvancedKey.size()     , _AdvancedKey);       //高级键
            qDebug() << "写入高级键大小:" << _AdvancedKey.size()  << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_MACRO_DEFINE_ADDR + (4096 * 32 * i);

            binFile.replace(GY_KeyboardTools::Keyboard60_Bin_Addr::_SECOND_STAGE_TIGGER   + (4096 * 32 * i), _SECONDARY_TIGGER.size(), _SECONDARY_TIGGER);  //多段触发 二次触发
            qDebug() << "写入多段触发大小:" << _SECONDARY_TIGGER.size() << " 起始位置：" << GY_KeyboardTools::Keyboard60_Bin_Addr::_SECOND_STAGE_TIGGER + (4096 * 32 * i);
            qDebug() << "--------------------------------------------循环写入次数:" << i << "-----------------------------------------------------------\n";

        }

        qDebug() << "当前写入键盘按键个数与要写入类型键盘个数不吻合，检查写入数据";

    }
    return binFile;
}

