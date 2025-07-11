#ifndef GY_KEYBOARDTOOLS_H
#define GY_KEYBOARDTOOLS_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QMap>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QFileDevice>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>


/*

    switch(keboardTypeNumber){
    case KeyboardType::_Keyboard_70_CN_:
        staticAnimationWriteStart = (256 * 4096);   //100000的位置
        dynamicAnimationWriteStart = (496 * 4096);  //1F0000的位置
        turnOnAnimationWriteStart = (1756 * 4096);  //6DC000的位置
        break;
    case KeyboardType::_Keyboard_JIAN1_:
        staticAnimationWriteStart = (1501 * 4096); //5DD000的位置
        dynamicAnimationWriteStart = (4096);         //1000的位置
        break;
    default:    break;
    }

*/



class GY_KeyboardTools : public QObject
{
    Q_OBJECT
public:
    //键盘类型
    enum KeyboardType{
        _Keyboard_60_CN_, //60配列 - 磁轴 70个按键
        //_Keyboard_JIAN1_, //JIAN1配列键盘
    };

    //60配列 - 磁轴 70按键 - 键盘 写入地址信息
    enum Keyboard60_Bin_Addr {
        _FLASH_SAVE_ADDR            =  0 * 4096,            // 0x000000 最大值
        _FLASH_SAVE_ADDR_END        =  0 * 4096 + 280,      // * 70 * 4 = 280 HEX(118)
        _MIN_VALUES_ADDR            =  1 * 4096,            // 0X001000 最小值
        _MIN_VALUES_ADDR_END        =  1 * 4096 + 280,      // * 70 * 4 = 280 HEX(118)
        _DEAD_ZONE_ADDR             =  2 * 4096,            // 0X002000 白平衡
        _DEAD_ZONE_ADDR_END         =  2 * 4096 + 80,       // 白平衡 10 * 4 = 40  HEX(28)
        _AXISTYPE_SAVE_ADDR         =  3 * 4096,            // 0X003000 AxisType 存储地址    键轴表
        _AXISTYPE_SAVE_ADDR_END     =  3 * 4096 + 70,       // * AxisType 存储地址    键轴表
        _RANGEVALUE_SAVE_ADDR       =  4 * 4096,            // 0X004000 RangeValue存储地址 键轴信息
        _RANGEVALUE_SAVE_ADDR_END   =  4 * 4096 + 340,      // * 存储了5组轴信息 每组有17个float类型数据  共占340位 17（17个数据）x5（5组）   x4(float类型) 后边有从1~255顺序出现的数据是干扰项，不用管
        _CONFIGUR_GROUP_ADDR        =  5 * 4096,            // 0X005000 当前预设配置组编号
        _CONFIGUR_GROUP_ADDR_END    =  5 * 4096 + 1,        // * 多组预设 当前的组  01~07  目前只占一位 后续可能合并部分存储
        _RATE_OF_RETURN_ADDR        =  6 * 4096,            // 0X006000 usb回报率
        _RATE_OF_RETURN_ADDR_END    =  6 * 4096 + 1,       // * 原本存储了白平衡  后续未使用  回报率√
        //新增加内容
        _MACRO_OF_ADDR              =  7 * 4096,            //0x007000 宏相关存储
        _MACRO_OF_ADDR_END          =  7 * 4096 + 128,      // * 存储120个字节
        _INFOR_OF_ADDR              =  8 * 4096,            //0x008000 版本信息存储
        _INFOR_OF_ADDR_END          =  8 * 4096 + 896,      // * (128 * 7)
        _BAD_VALUE_ADDR             =  9 * 4096,            //0x009000 无轴保护
        _BAD_VALUE_ADDR_END         =  9 * 4096 + 280,      // * (5*14*4)
        //以下都是5组信息 每次偏移 32
        _THRESHOLD_VALUES_ADDR      = 32 * 4096,            // 0X020000 定高设定表
        _THRESHOLD_VALUES_ADDR_END  = 32 * 4096 + 280,      // * 定高存储信息  70个float类型  占70x4
        _RT_DOWN_ADDR               = 33 * 4096,            // 0X021000 rt触发 RT设定表
        _RT_DOWN_ADDR_END           = 33 * 4096 + 280,      // * RT触发值 70个float类型  占70x4
        _RT_UP_VALUES_ADDR          = 34 * 4096,            // 0X022000 rt抬起
        _RT_UP_VALUES_ADDR_END      = 34 * 4096 + 280,      // * RT抬起值 70个float类型  占70x4
        _RT_ENABLE_STATE_ADDR       = 35 * 4096,            // 0X023000 rt、定高状态选择 定高rt 混合显示             对应模式MODE
        _RT_ENABLE_STATE_ADDR_END   = 35 * 4096 + 70,       // * 定高/RT  标志位   有效信息01/02/03   70一组       对应模式MODE
        _SCAN_RATE_ADDR             = 36 * 4096,            // 0X024000 扫描率
        _SCAN_RATE_ADDR_END         = 36 * 4096 + 1,        // * 扫描率
        _LED_SAVE_ADDR              = 37 * 4096,            // 0X025000 灯存储
        _LED_SAVE_ADDR_END          = 37 * 4096 + 210,      // * 灯颜色信息 RGB 一个灯占三位 参考静态动画信息   占位70x3
        _ANIMATION_DATA_ADDR        = 38 * 4096,            // 0X026000 动画信息 动静态编号 速度
        _ANIMATION_DATA_ADDR_END    = 38 * 4096 + 13,       // * 合并存储了灯亮度信息 静态动画 动态动画信息 占位13位
        _FUNCT_SAVE_ADDR            = 39 * 4096,            // 0X027000 按键功能                                   只要第三位：格式 16进制后转0016进制 00FF类似于
        _FUNCT_SAVE_ADDR_END        = 39 * 4096 + 210,      // * 按键功能
        _FUNCT_FN_SAVE_ADDR         = 40 * 4096,            // 0X028000 fn 功能表存储地址 (70*3)                    只要第三位：格式 16进制后转0016进制 00FF类似于
        _FUNCT_FN_SAVE_ADDR_END     = 40 * 4096 + 210,      // * fn 功能表存储地址
        _MACRO_DEFINE_ADDR          = 41 * 4096,            // 0X029000 高级键
        _MACRO_DEFINE_ADDR_END      = 41 * 4096 + 420,      // * 高级键 70组信息每组信息包含6个参数
        _SECOND_STAGE_TIGGER        = 42 * 4096,            //多段触发 (5*14*4*6)1680
        _SECOND_STAGE_TIGGER_END    = 42 * 4096 + 1680,     //多段触发 (5*14*4*6)1680

        _FUNCT_INDICASTOR_LIGHR     = 43 * 4096,            //0X02b000 宏-功能指示灯
        _FUNCT_INDICASTOR_LIGHR_END = 43 * 4096 + 4020,     //宏 - 功能指示灯 20*(1+50*4) = 4020
        //动画存放地址
        _StaticAnimation_ADDR       = 256 * 4096,           //静态动画 - 100000的位置
        _TurnOnAnimation_ADDR       = 457 * 4096,           //开机动画 - 6DC000的位置
        _DynamicAnimation_ADDR      = 496 * 4096,           //动态动画 - 1F0000的位置
        _DeepAnimation_ADDR         = 2048 * 4096,          //深度动画 - 800000的位置
    };


    //键盘结构类型
    struct KeyboardLayout{
        int _Row;                               //键盘组成结构行数
        int _Col;                               //键盘组成列数
        int _ButtonCount;                       //按键总数量 行*列 = 总数量
        int _MaxWidth;                          //键盘最大宽度
        int _MaxHeight;                         //键盘最大高度
        KeyboardType _KeyboardType;             //键盘类型配列
    };
    //键盘每个按键的详细信息
    struct KeyboardButtonInfo{
        QPoint _KeyCenterPoint;                 //按键中心点
        QRect _Keyborders;                      //举行边框大小
        QString _KeyName;                       //按键字符
        int _KeyValue;                          //键值
        int _KeyPressCount;                     //按键计数
        int _KeyPressTime;                      //按键时间
        QColor _KeyCustomizeColor;              //自定义按键颜色
        QString _KeyValueJson;                  //json当中key的value值
        struct KeyboardLayout _KeyboardLayout;  //键盘按键结构
    };


    struct JsonPrivateOnlyKeyInfo{
        int _AKType;                  //RT类型
        QByteArray _RT_DOWN;                 //RT触发
        QByteArray _Rt_UP;                   //RT抬起
        QByteArray _RT_STATE;                //RT状态
        QByteArray _FIXED_HEIGHT;            //定高
        QByteArray _LightColor;              //灯颜色
        QByteArray _KeyValue;                //键值
        QByteArray _FnKeyValue;              //FN键值
        QByteArray _AdvancedKey;             //高级键
        QByteArray _SECONDARY_TIGGER;        //多段触发  与 定高 公用一个值
    };

    //json解析中的所有私有信息
    struct JsonPrivateInfo{
        int _KeyBoardCount;                  //按键个数
        QByteArray _MULTIPLE_SET;            //多组预设  读取后显示界面
        QByteArray _RETURN_SPEED;            //回报率   读取后显示界面
        QByteArray _SCAN_SPEED;              //扫描率   读取后显示界面
        QByteArray _ANIMATION_INFO;          //动画信息

        QList<GY_KeyboardTools::JsonPrivateOnlyKeyInfo> _JsonPrivateOnlyKeyInfo;    //每个按键都记录一遍
    };



public:
    explicit GY_KeyboardTools(QObject *parent = nullptr);
    static QMap<int, struct GY_KeyboardTools::KeyboardButtonInfo> getKeyboarLayout_60_CN();    //设置60配列键盘 70个按键

    static QByteArray getFlotaToByteArray(float data);                         //浮点转字节型
    static float getByteArrayToFloat(QByteArray data);                         //字节转浮点型
    static QByteArray getAnimationDynamic(QString path);                          //读取动态动画内容
    static QByteArray getAnimationStatic(QString path);                           //读取静态动画内容
    static QByteArray getDynamicFillZero(QByteArray data, int sector = 4);             //动态动画补零 sector 扇区数量
    static QByteArray getStaticFillZero(QByteArray data, int sector = 4);              //静态动画补零


private:


};

#endif // GY_KEYBOARDTOOLS_H
