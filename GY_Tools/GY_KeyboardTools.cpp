#include "GY_KeyboardTools.h"

GY_KeyboardTools::GY_KeyboardTools(QObject *parent)
    : QObject{parent}
{

}



QMap<int, GY_KeyboardTools::KeyboardButtonInfo> GY_KeyboardTools::getKeyboarLayout_60_CN()
{
    QMap<int, GY_KeyboardTools::KeyboardButtonInfo> MapKeyboard;
    //记录键盘详细布局信息
    struct KeyboardLayout  keyboardLayout;
    keyboardLayout._Row = 5;                // 5行
    keyboardLayout._Col = 14;               //14列
    keyboardLayout._KeyboardType = KeyboardType::_Keyboard_60_CN_; //60配列键盘
    keyboardLayout._ButtonCount = keyboardLayout._Row * keyboardLayout._Col;
    keyboardLayout._MaxWidth = 279; //根据键盘最大 X + 边框得来
    keyboardLayout._MaxHeight = 91; //根据键盘最大 Y + 边框得来
    QColor color = Qt::black;

    MapKeyboard.insert( 0, KeyboardButtonInfo{QPoint(  7.00, 7), QRect(  0.00, 0, 14, 14),                "~", 192, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 1, KeyboardButtonInfo{QPoint( 26.05, 7), QRect( 19.05, 0, 14, 14),                "1",  49, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 2, KeyboardButtonInfo{QPoint( 45.10, 7), QRect( 38.10, 0, 14, 14),                "2",  50, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 3, KeyboardButtonInfo{QPoint( 64.15, 7), QRect( 57.15, 0, 14, 14),                "3",  51, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 4, KeyboardButtonInfo{QPoint( 83.20, 7), QRect( 76.20, 0, 14, 14),                "4",  52, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 5, KeyboardButtonInfo{QPoint(102.25, 7), QRect( 95.25, 0, 14, 14),                "5",  53, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 6, KeyboardButtonInfo{QPoint(121.30, 7), QRect(114.30, 0, 14, 14),                "6",  54, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 7, KeyboardButtonInfo{QPoint(140.35, 7), QRect(133.35, 0, 14, 14),                "7",  55, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 8, KeyboardButtonInfo{QPoint(159.40, 7), QRect(152.40, 0, 14, 14),                "8",  56, 0, 0, color, keyboardLayout});
    MapKeyboard.insert( 9, KeyboardButtonInfo{QPoint(178.45, 7), QRect(171.45, 0, 14, 14),                "9",  57, 0, 0, color, keyboardLayout});
    MapKeyboard.insert(10, KeyboardButtonInfo{QPoint(197.50, 7), QRect(190.50, 0, 14, 14),                "0",  48, 0, 0, color, keyboardLayout});
    MapKeyboard.insert(11, KeyboardButtonInfo{QPoint(216.55, 7), QRect(209.55, 0, 14, 14),                "-", 189, 0, 0, color, keyboardLayout});
    MapKeyboard.insert(12, KeyboardButtonInfo{QPoint(235.60, 7), QRect(228.60, 0, 14, 14),                "+", 187, 0, 0, color, keyboardLayout});
    MapKeyboard.insert(13, KeyboardButtonInfo{QPoint(264.17, 7), QRect(257.17, 0, 14, 14),        "Backspace",   8, 0, 0, color, keyboardLayout});

    MapKeyboard.insert(14, KeyboardButtonInfo{QPoint( 11.76, 26.05), QRect(  4.76, 19.05, 14, 14),      "Tab",   9, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(15, KeyboardButtonInfo{QPoint( 35.57, 26.05), QRect( 28.57, 19.05, 14, 14),        "Q",  81, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(16, KeyboardButtonInfo{QPoint( 54.62, 26.05), QRect( 47.62, 19.05, 14, 14),        "W",  87, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(17, KeyboardButtonInfo{QPoint( 73.67, 26.05), QRect( 66.67, 19.05, 14, 14),        "E",  69, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(18, KeyboardButtonInfo{QPoint( 92.72, 26.05), QRect( 85.72, 19.05, 14, 14),        "R",  82, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(19, KeyboardButtonInfo{QPoint(111.77, 26.05), QRect(104.77, 19.05, 14, 14),        "T",  84, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(20, KeyboardButtonInfo{QPoint(130.82, 26.05), QRect(123.82, 19.05, 14, 14),        "Y",  89, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(21, KeyboardButtonInfo{QPoint(149.87, 26.05), QRect(142.87, 19.05, 14, 14),        "U",  85, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(22, KeyboardButtonInfo{QPoint(168.92, 26.05), QRect(161.92, 19.05, 14, 14),        "I",  73, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(23, KeyboardButtonInfo{QPoint(187.97, 26.05), QRect(180.97, 19.05, 14, 14),        "O",  79, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(24, KeyboardButtonInfo{QPoint(207.02, 26.05), QRect(200.02, 19.05, 14, 14),        "P",  80, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(25, KeyboardButtonInfo{QPoint(226.07, 26.05), QRect(219.07, 19.05, 14, 14),        "{", 219, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(26, KeyboardButtonInfo{QPoint(245.12, 26.05), QRect(238.12, 19.05, 14, 14),        "}", 221, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(27, KeyboardButtonInfo{QPoint(268.94, 26.05), QRect(261.94, 19.05, 14, 14),        "|", 220, 0, 0, color, keyboardLayout });

    MapKeyboard.insert(28, KeyboardButtonInfo{QPoint( 14.14, 45.10), QRect(  7.14, 38.10, 14, 14), "CapsLock",  20, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(29, KeyboardButtonInfo{QPoint( 40.34, 45.10), QRect( 33.34, 38.10, 14, 14),        "A",  65, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(30, KeyboardButtonInfo{QPoint( 59.39, 45.10), QRect( 52.39, 38.10, 14, 14),        "S",  83, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(31, KeyboardButtonInfo{QPoint( 78.44, 45.10), QRect( 71.44, 38.10, 14, 14),        "D",  68, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(32, KeyboardButtonInfo{QPoint( 97.49, 45.10), QRect( 90.49, 38.10, 14, 14),        "F",  70, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(33, KeyboardButtonInfo{QPoint(116.54, 45.10), QRect(109.54, 38.10, 14, 14),        "G",  71, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(34, KeyboardButtonInfo{QPoint(135.59, 45.10), QRect(128.59, 38.10, 14, 14),        "H",  72, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(35, KeyboardButtonInfo{QPoint(154.64, 45.10), QRect(147.64, 38.10, 14, 14),        "J",  74, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(36, KeyboardButtonInfo{QPoint(173.69, 45.10), QRect(166.69, 38.10, 14, 14),        "K",  75, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(37, KeyboardButtonInfo{QPoint(192.74, 45.10), QRect(185.74, 38.10, 14, 14),        "L",  76, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(38, KeyboardButtonInfo{QPoint(211.79, 45.10), QRect(204.79, 38.10, 14, 14),        ";", 186, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(39, KeyboardButtonInfo{QPoint(230.84, 45.10), QRect(223.84, 38.10, 14, 14),        "'", 222, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(40, KeyboardButtonInfo{QPoint(261.79, 45.10), QRect(254.79, 38.10, 14, 14),    "Enter",  13, 0, 0, color, keyboardLayout });

    MapKeyboard.insert(42, KeyboardButtonInfo{QPoint( 18.91, 64.15), QRect( 11.91, 57.15, 14, 14),    "Shift", 160, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(43, KeyboardButtonInfo{QPoint( 49.86, 64.15), QRect( 42.86, 57.15, 14, 14),        "Z",  90, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(44, KeyboardButtonInfo{QPoint( 68.91, 64.15), QRect( 61.91, 57.15, 14, 14),        "X",  88, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(45, KeyboardButtonInfo{QPoint( 87.96, 64.15), QRect( 80.96, 57.15, 14, 14),        "C",  67, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(46, KeyboardButtonInfo{QPoint(107.01, 64.15), QRect(100.01, 57.15, 14, 14),        "V",  86, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(47, KeyboardButtonInfo{QPoint(126.06, 64.15), QRect(119.06, 57.15, 14, 14),        "B",  66, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(48, KeyboardButtonInfo{QPoint(145.11, 64.15), QRect(138.11, 57.15, 14, 14),        "N",  78, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(49, KeyboardButtonInfo{QPoint(164.16, 64.15), QRect(157.16, 57.15, 14, 14),        "M",  77, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(50, KeyboardButtonInfo{QPoint(183.21, 64.15), QRect(176.21, 57.15, 14, 14),        "<", 188, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(51, KeyboardButtonInfo{QPoint(202.26, 64.15), QRect(195.26, 57.15, 14, 14),        ">", 190, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(52, KeyboardButtonInfo{QPoint(221.31, 64.15), QRect(214.31, 57.15, 14, 14),        "?", 191, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(53, KeyboardButtonInfo{QPoint(257.03, 64.15), QRect(250.03, 57.15, 14, 14),    "Shift", 161, 0, 0, color, keyboardLayout });

    MapKeyboard.insert(56, KeyboardButtonInfo{QPoint(  9.39, 83.20), QRect(  2.39, 76.20, 14, 14),     "Ctrl", 162, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(57, KeyboardButtonInfo{QPoint( 33.20, 83.20), QRect( 26.20, 76.20, 14, 14),      "Win",  91, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(58, KeyboardButtonInfo{QPoint( 57.01, 83.20), QRect( 50.01, 76.20, 14, 14),      "Alt", 164, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(61, KeyboardButtonInfo{QPoint(128.44, 83.20), QRect(121.44, 76.20, 14, 14),    "Space",  32, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(64, KeyboardButtonInfo{QPoint(199.89, 83.20), QRect(192.89, 76.20, 14, 14),      "Alt", 165, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(65, KeyboardButtonInfo{QPoint(223.70, 83.20), QRect(216.70, 76.20, 14, 14),       "Fn", 999, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(66, KeyboardButtonInfo{QPoint(247.51, 83.20), QRect(240.51, 76.20, 14, 14),     "Menu", 000, 0, 0, color, keyboardLayout });
    MapKeyboard.insert(67, KeyboardButtonInfo{QPoint(271.32, 83.20), QRect(264.32, 76.20, 14, 14),     "Ctrl", 163, 0, 0, color, keyboardLayout });
    return MapKeyboard;
}





