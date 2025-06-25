#include "GY_KeyboardHook.h"
static HHOOK KeyHook = nullptr; //钩子对象
static GY_KeyboardHook* Hook;   //Qt界面中调用Hook类的对象

GY_KeyboardHook::GY_KeyboardHook(QObject *parent)
{
setGlobalHotKey(0);
}
//消息函数，系统消息队列信息会返回到该函数中
LRESULT CALLBACK keyProc(int nCode,WPARAM wParam, LPARAM lParam){
    KBDLLHOOKSTRUCT* hookStruct = (KBDLLHOOKSTRUCT*)lParam;            //lParam⽤于判断按键类型
    //qDebug() << "按键：" <<hookStruct->vkCode << " 时间：" << hookStruct->time << " 标志位：" << hookStruct->flags ;
    GY_KeyboardHook::KeyInfo keyInfo;
    keyInfo.KeyValue = hookStruct->vkCode;
    keyInfo.KeyTime = hookStruct->time;
    keyInfo.KeyType = GY_KeyboardHook::KeyType::EditKey;
    switch(hookStruct->vkCode){
    //------------------------------小键盘  小键盘+大键盘回车在一个位置 ----------------------------
    case 96:    //0
        keyInfo.Key = "Num 0";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 97:    //1
        keyInfo.Key = "Num 1";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 98:    //2
        keyInfo.Key = "Num 2";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 99:    //3
        keyInfo.Key = "Num 3";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 100:   //4
        keyInfo.Key = "Num 4";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 101:   //5
        keyInfo.Key = "Num 5";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 102:   //6
        keyInfo.Key = "Num 6";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 103:   //7
        keyInfo.Key = "Num 7";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 104:   //8
        keyInfo.Key = "Num 8";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 105:   //9
        keyInfo.Key = "Num 9";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 107:   //小键盘+
        keyInfo.Key = "Num +";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 109:   //小键盘-
        keyInfo.Key = "Num -";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 106:   //小键盘*
        keyInfo.Key = "Num *";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 111:   //小键盘/
        keyInfo.Key = "Num /";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 110:   //小键盘 .
        keyInfo.Key = "Num .";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 144:   //小键盘Num Lock
        keyInfo.Key = "Num Lock";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;
    case 12:    //小写键盘关闭后 5按键 clear
        keyInfo.Key = "Num 5";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        keyInfo.KeyType = GY_KeyboardHook::KeyType::NumKey;
        break;


        //---------------------中间按键-------------------------
    case 37:    //左
        keyInfo.Key = "Left";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 38:    //上
        keyInfo.Key = "Up";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 39:    //右
        keyInfo.Key = "Right";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 40:    //下
        keyInfo.Key = "Donw";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 173:   //声音关
        keyInfo.Key = "声音关闭";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;
    case 174:   //声音减小
        keyInfo.Key = "声音较小";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;
    case 175:   //声音加大
        keyInfo.Key = "声音加大";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;
    case 45:    //inster
        keyInfo.Key = "inster";
        if(hookStruct->flags == 1 || hookStruct->flags == 0){
            keyInfo.KeyState = true;
        }else{
            keyInfo.KeyState = false;
        }
        break;
    case 36:    //home
        keyInfo.Key = "home";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 33:    //pgup
        keyInfo.Key = "pgup";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 46:    //delete
        keyInfo.Key = "delete";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 35:    //end
        keyInfo.Key = "end";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 34:    //pgdn
        keyInfo.Key = "pgdn";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;

    case 44:    //print打印            FN
        keyInfo.Key = "Print";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        if(keyInfo.KeyState){   //按下
            Hook->KeyPress(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }else{                  //抬起
            Hook->KeyRelease(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }
        break;
    case 145:   //ScrollLock 滚动锁定  FN
        keyInfo.Key = "ScrollLock";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        if(keyInfo.KeyState){   //按下
            Hook->KeyPress(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }else{                  //抬起
            Hook->KeyRelease(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }
        break;
    case 19:    //PauseBreak 暂停中断   FN
        keyInfo.Key = "PauseBreak";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        if(keyInfo.KeyState){   //按下
            Hook->KeyPress(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }else{                  //抬起
            Hook->KeyRelease(GY_KeyboardHook::KeyInfo{ 999, "Fn", keyInfo.KeyTime, keyInfo.KeyState});
        }
        break;


    case 176:    //下一曲
        keyInfo.Key = "下一曲";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;
    case 179:    //播放暂停
        keyInfo.Key = "播放暂停";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;
    case 177:    //上一曲
        keyInfo.Key = "上一曲";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 17);
        break;




        //----------------------大键盘--------------------------
        //ESC - F1 - F12
    case 27:    //ESC
        keyInfo.Key = "ESC";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 112:   //F1
        keyInfo.Key = "F1";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 113:   //F2
        keyInfo.Key = "F2";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 114:   //F3
        keyInfo.Key = "F3";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 115:   //F4
        keyInfo.Key = "F4";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 116:   //F5
        keyInfo.Key = "F5";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 117:   //F6
        keyInfo.Key = "F6";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 118:   //F7
        keyInfo.Key = "F7";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 119:   //F8
        keyInfo.Key = "F8";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 120:   //F9
        keyInfo.Key = "F9";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 121:   //F10
        keyInfo.Key = "F10";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 122:   //F11
        keyInfo.Key = "F11";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 123:   //F12
        keyInfo.Key = "F12";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;

        //上方 ~ - 0 - 9 -Backspace
    case 192:   //~
        keyInfo.Key = "~";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 48:    //0
        keyInfo.Key = "0";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 49:    //1
        keyInfo.Key = "1";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 50:    //2
        keyInfo.Key = "2";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 51:    //3
        keyInfo.Key = "3";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 52:    //4
        keyInfo.Key = "4";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 53:    //5
        keyInfo.Key = "5";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 54:    //6
        keyInfo.Key = "6";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 55:    //7
        keyInfo.Key = "7";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 56:    //8
        keyInfo.Key = "8";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 57:    //9
        keyInfo.Key = "9";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 189:   //-
        keyInfo.Key = "-";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 187:   //=
        keyInfo.Key = "=";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 8:     // BackSpace
        keyInfo.Key = "BackSpace";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;

        //字符 a - z
    case 65:    //a
        keyInfo.Key = "a";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 66:    //b
        keyInfo.Key = "b";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 67:    //c
        keyInfo.Key = "c";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 68:    //d
        keyInfo.Key = "d";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 69:    //e
        keyInfo.Key = "e";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 70:    //f
        keyInfo.Key = "f";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 71:    //g
        keyInfo.Key = "g";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 72:    //h
        keyInfo.Key = "h";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 73:    //i
        keyInfo.Key = "i";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 74:    //j
        keyInfo.Key = "j";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 75:    //k
        keyInfo.Key = "k";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 76:    //l
        keyInfo.Key = "l";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 77:    //m
        keyInfo.Key = "m";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 78:    //n
        keyInfo.Key = "n";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 79:    //o
        keyInfo.Key = "o";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 80:    //p
        keyInfo.Key = "p";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 81:    //q
        keyInfo.Key = "q";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 82:    //r
        keyInfo.Key = "r";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 83:    //s
        keyInfo.Key = "s";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 84:    //t
        keyInfo.Key = "t";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 85:    //u
        keyInfo.Key = "u";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 86:    //v
        keyInfo.Key = "v";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 87:    //w
        keyInfo.Key = "w";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 88:    //x
        keyInfo.Key = "x";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 89:    //y
        keyInfo.Key = "y";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 90:    //z
        keyInfo.Key = "z";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;


        //Tab - { - } - |
    case 9:     //Tab
        keyInfo.Key = "Tab";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);

        break;
    case 219:   //{[
        keyInfo.Key = "{";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 221:   //}]
        keyInfo.Key = "}";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 220:   //|\、
        keyInfo.Key = "|";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;

        //capslock - ;: - "' - 回车
    case 20:    //CapsLock
        keyInfo.Key = "CapsLock";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 186:   //;:
        keyInfo.Key = ";";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 222:   //"'
        keyInfo.Key = "'";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;

        //小键盘回车 + 大键盘回车
    case 13:
        keyInfo.Key = "Enter";
        if(hookStruct->flags == 0){         //大键盘回车按下
            keyInfo.KeyState = true;
            keyInfo.KeyValue = 13;
        }else if(hookStruct->flags == 128){
            keyInfo.KeyState = false;
            keyInfo.KeyValue = 13;
        }

        if(hookStruct->flags == 1){         //数字键盘回车按下
            keyInfo.KeyState = true;
            keyInfo.Key = "Num Enter";
            keyInfo.KeyValue = 1313;

        }else if(hookStruct->flags == 129){ //数字键盘回车抬起
            keyInfo.KeyState = false;
            keyInfo.Key = "Num Enter";
            keyInfo.KeyValue = 1313;

        }
        break;

        // 左shift -  <《，,  -  》。> ?/、  - 右shift
    case 160:   //left Shift
        keyInfo.Key = "left Shift";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 161:   //right Shift
        keyInfo.Key = "right Shift";
        if(hookStruct->flags == 1){         //数字键盘回车按下
            keyInfo.KeyState = true;
        }else if(hookStruct->flags == 129){ //数字键盘回车抬起
            keyInfo.KeyState = false;
        }
        break;
    case 188:   //<,
        keyInfo.Key = "<";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 190:   //>.
        keyInfo.Key = ">";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 191:   //?/
        keyInfo.Key = "?";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;


        // 左Ctrl - windows - 左Alt - 右Alt - 右Ctrl
    case 162:   //left Ctrl
        keyInfo.Key = "Left Ctrl";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 163:   //right Ctrl
        keyInfo.Key = "Right Ctrl";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 164:   //left Alt
        keyInfo.Key = "Left Alt";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 32);
        break;
    case 165:   //Right Alt
        keyInfo.Key = "Right Alt";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 33);
        break;
    case 91:    //Left Windows

        keyInfo.Key = "Left Windows";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);

        break;
    case 92:    //right Windows

        keyInfo.Key = "Right Windows";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;
    case 32:   //空格
        keyInfo.Key = "Space";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 0);
        break;
    case 93:   //鼠标右键
        keyInfo.Key = "Right Mouse Button";
        keyInfo.KeyState = Hook->KeyState(hookStruct->flags, 1);
        break;

    default:
        qDebug() << "ERROR-错误: GY000001键盘按键未知";
        break;
    }

    if(keyInfo.KeyState){   //按下
        Hook->KeyPress(keyInfo);
    }else{                  //抬起
        Hook->KeyRelease(keyInfo);
    }

    if(Hook->getGlobalHotKey()) return 1;
    return CallNextHookEx(KeyHook, nCode, wParam, lParam);             //继续原有的事件队列
}



//安装键盘钩子
void GY_KeyboardHook::installHook(GY_KeyboardHook *hook)
{
    KeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyProc, nullptr, 0);
    Hook = hook;
    qDebug() << "键盘检测模块-安装成功";
}
//卸载键盘钩子
void GY_KeyboardHook::unInstallHook()
{
    UnhookWindowsHookEx(KeyHook);
    KeyHook = nullptr;
}

void GY_KeyboardHook::setGlobalHotKey(const bool &isGlobalHotKey)
{
    this->isGlobalHotKey = isGlobalHotKey;
}

bool GY_KeyboardHook::getGlobalHotKey()
{
    return this->isGlobalHotKey;
}

void GY_KeyboardHook::KeyPress(KeyInfo keyInfo)
{
    emit signalKeyPress(keyInfo);
}

void GY_KeyboardHook::KeyRelease(KeyInfo keyInfo)
{
    emit signalKeyRelease(keyInfo);
}
//按键状态
bool GY_KeyboardHook::KeyState(const int &flags, const int &KeyValue)
{
    if(flags == KeyValue){
        return true;
    }else{
        return false;
    }
}


