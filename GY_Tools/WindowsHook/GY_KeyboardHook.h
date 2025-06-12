#ifndef GY_KEYBOARDHOOK_H
#define GY_KEYBOARDHOOK_H

#include <QObject>
#include <QWidget>
#include <qt_windows.h>
#include <windowsx.h>
#include "Windows.h"



class GY_KeyboardHook: public QObject
{
    Q_OBJECT
public:
    enum KeyType{
        NumKey, //数字区，小键盘区
        EditKey //编辑区，大键盘区
    };

    struct KeyInfo{
        int KeyValue;   //按键数字
        QString Key;    //按键字符
        int KeyTime;    //按键时间
        bool KeyState;  //按键状态 true按下 | false 抬起
        GY_KeyboardHook::KeyType KeyType;//键盘类型
    };

public:
    explicit GY_KeyboardHook(QObject *parent = nullptr);
    void installHook(GY_KeyboardHook* hook);    //安装钩函数，指针参数为了发送信号
    void unInstallHook();       //删除钩子

    void setGlobalHotKey(const bool &isGlobalHotKey);//全局热键
    bool getGlobalHotKey();

    void KeyPress(KeyInfo keyInfo);     //按压按键
    void KeyRelease(KeyInfo keyInfo);   //释放按键

    bool KeyState(const int &flags, const int &KeyValue);        //按键状态
signals:
    void signalKeyPress(KeyInfo keyInfo);
    void signalKeyRelease(KeyInfo keyInfo);

private:
    bool isGlobalHotKey = false;    //全局热键
};

#endif // GY_KEYBOARDHOOK_H
