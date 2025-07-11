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

    MapKeyboard.insert( 0, KeyboardButtonInfo{QPoint(  7.00, 7), QRect(  0.00, 0, 14, 14),              "ESC",  27, 0, 0, color, "0029", keyboardLayout});
    MapKeyboard.insert( 1, KeyboardButtonInfo{QPoint( 26.05, 7), QRect( 19.05, 0, 14, 14),                "1",  49, 0, 0, color, "001E", keyboardLayout});
    MapKeyboard.insert( 2, KeyboardButtonInfo{QPoint( 45.10, 7), QRect( 38.10, 0, 14, 14),                "2",  50, 0, 0, color, "001F", keyboardLayout});
    MapKeyboard.insert( 3, KeyboardButtonInfo{QPoint( 64.15, 7), QRect( 57.15, 0, 14, 14),                "3",  51, 0, 0, color, "0020", keyboardLayout});
    MapKeyboard.insert( 4, KeyboardButtonInfo{QPoint( 83.20, 7), QRect( 76.20, 0, 14, 14),                "4",  52, 0, 0, color, "0021", keyboardLayout});
    MapKeyboard.insert( 5, KeyboardButtonInfo{QPoint(102.25, 7), QRect( 95.25, 0, 14, 14),                "5",  53, 0, 0, color, "0022", keyboardLayout});
    MapKeyboard.insert( 6, KeyboardButtonInfo{QPoint(121.30, 7), QRect(114.30, 0, 14, 14),                "6",  54, 0, 0, color, "0023", keyboardLayout});
    MapKeyboard.insert( 7, KeyboardButtonInfo{QPoint(140.35, 7), QRect(133.35, 0, 14, 14),                "7",  55, 0, 0, color, "0024", keyboardLayout});
    MapKeyboard.insert( 8, KeyboardButtonInfo{QPoint(159.40, 7), QRect(152.40, 0, 14, 14),                "8",  56, 0, 0, color, "0025", keyboardLayout});
    MapKeyboard.insert( 9, KeyboardButtonInfo{QPoint(178.45, 7), QRect(171.45, 0, 14, 14),                "9",  57, 0, 0, color, "0026", keyboardLayout});
    MapKeyboard.insert(10, KeyboardButtonInfo{QPoint(197.50, 7), QRect(190.50, 0, 14, 14),                "0",  48, 0, 0, color, "0027", keyboardLayout});
    MapKeyboard.insert(11, KeyboardButtonInfo{QPoint(216.55, 7), QRect(209.55, 0, 14, 14),                "-", 189, 0, 0, color, "002D", keyboardLayout});
    MapKeyboard.insert(12, KeyboardButtonInfo{QPoint(235.60, 7), QRect(228.60, 0, 14, 14),                "+", 187, 0, 0, color, "002E", keyboardLayout});
    MapKeyboard.insert(13, KeyboardButtonInfo{QPoint(264.17, 7), QRect(257.17, 0, 14, 14),        "Backspace",   8, 0, 0, color, "002A", keyboardLayout});

    MapKeyboard.insert(14, KeyboardButtonInfo{QPoint( 11.76, 26.05), QRect(  4.76, 19.05, 14, 14),      "Tab",   9, 0, 0, color, "002B", keyboardLayout });
    MapKeyboard.insert(15, KeyboardButtonInfo{QPoint( 35.57, 26.05), QRect( 28.57, 19.05, 14, 14),        "Q",  81, 0, 0, color, "0014", keyboardLayout });
    MapKeyboard.insert(16, KeyboardButtonInfo{QPoint( 54.62, 26.05), QRect( 47.62, 19.05, 14, 14),        "W",  87, 0, 0, color, "001A", keyboardLayout });
    MapKeyboard.insert(17, KeyboardButtonInfo{QPoint( 73.67, 26.05), QRect( 66.67, 19.05, 14, 14),        "E",  69, 0, 0, color, "0008", keyboardLayout });
    MapKeyboard.insert(18, KeyboardButtonInfo{QPoint( 92.72, 26.05), QRect( 85.72, 19.05, 14, 14),        "R",  82, 0, 0, color, "0015", keyboardLayout });
    MapKeyboard.insert(19, KeyboardButtonInfo{QPoint(111.77, 26.05), QRect(104.77, 19.05, 14, 14),        "T",  84, 0, 0, color, "0017", keyboardLayout });
    MapKeyboard.insert(20, KeyboardButtonInfo{QPoint(130.82, 26.05), QRect(123.82, 19.05, 14, 14),        "Y",  89, 0, 0, color, "001C", keyboardLayout });
    MapKeyboard.insert(21, KeyboardButtonInfo{QPoint(149.87, 26.05), QRect(142.87, 19.05, 14, 14),        "U",  85, 0, 0, color, "0018", keyboardLayout });
    MapKeyboard.insert(22, KeyboardButtonInfo{QPoint(168.92, 26.05), QRect(161.92, 19.05, 14, 14),        "I",  73, 0, 0, color, "000C", keyboardLayout });
    MapKeyboard.insert(23, KeyboardButtonInfo{QPoint(187.97, 26.05), QRect(180.97, 19.05, 14, 14),        "O",  79, 0, 0, color, "0012", keyboardLayout });
    MapKeyboard.insert(24, KeyboardButtonInfo{QPoint(207.02, 26.05), QRect(200.02, 19.05, 14, 14),        "P",  80, 0, 0, color, "0013", keyboardLayout });
    MapKeyboard.insert(25, KeyboardButtonInfo{QPoint(226.07, 26.05), QRect(219.07, 19.05, 14, 14),        "{", 219, 0, 0, color, "002F", keyboardLayout });
    MapKeyboard.insert(26, KeyboardButtonInfo{QPoint(245.12, 26.05), QRect(238.12, 19.05, 14, 14),        "}", 221, 0, 0, color, "0030", keyboardLayout });
    MapKeyboard.insert(27, KeyboardButtonInfo{QPoint(268.94, 26.05), QRect(261.94, 19.05, 14, 14),        "|", 220, 0, 0, color, "0031", keyboardLayout });

    MapKeyboard.insert(28, KeyboardButtonInfo{QPoint( 14.14, 45.10), QRect(  7.14, 38.10, 14, 14), "CapsLock",  20, 0, 0, color, "0039", keyboardLayout });
    MapKeyboard.insert(29, KeyboardButtonInfo{QPoint( 40.34, 45.10), QRect( 33.34, 38.10, 14, 14),        "A",  65, 0, 0, color, "0004", keyboardLayout });
    MapKeyboard.insert(30, KeyboardButtonInfo{QPoint( 59.39, 45.10), QRect( 52.39, 38.10, 14, 14),        "S",  83, 0, 0, color, "0016", keyboardLayout });
    MapKeyboard.insert(31, KeyboardButtonInfo{QPoint( 78.44, 45.10), QRect( 71.44, 38.10, 14, 14),        "D",  68, 0, 0, color, "0007", keyboardLayout });
    MapKeyboard.insert(32, KeyboardButtonInfo{QPoint( 97.49, 45.10), QRect( 90.49, 38.10, 14, 14),        "F",  70, 0, 0, color, "0009", keyboardLayout });
    MapKeyboard.insert(33, KeyboardButtonInfo{QPoint(116.54, 45.10), QRect(109.54, 38.10, 14, 14),        "G",  71, 0, 0, color, "000A", keyboardLayout });
    MapKeyboard.insert(34, KeyboardButtonInfo{QPoint(135.59, 45.10), QRect(128.59, 38.10, 14, 14),        "H",  72, 0, 0, color, "000B", keyboardLayout });
    MapKeyboard.insert(35, KeyboardButtonInfo{QPoint(154.64, 45.10), QRect(147.64, 38.10, 14, 14),        "J",  74, 0, 0, color, "000D", keyboardLayout });
    MapKeyboard.insert(36, KeyboardButtonInfo{QPoint(173.69, 45.10), QRect(166.69, 38.10, 14, 14),        "K",  75, 0, 0, color, "000E", keyboardLayout });
    MapKeyboard.insert(37, KeyboardButtonInfo{QPoint(192.74, 45.10), QRect(185.74, 38.10, 14, 14),        "L",  76, 0, 0, color, "000F", keyboardLayout });
    MapKeyboard.insert(38, KeyboardButtonInfo{QPoint(211.79, 45.10), QRect(204.79, 38.10, 14, 14),        ";", 186, 0, 0, color, "0033", keyboardLayout });
    MapKeyboard.insert(39, KeyboardButtonInfo{QPoint(230.84, 45.10), QRect(223.84, 38.10, 14, 14),        "'", 222, 0, 0, color, "0034", keyboardLayout });
    MapKeyboard.insert(40, KeyboardButtonInfo{QPoint(261.79, 45.10), QRect(254.79, 38.10, 14, 14),    "Enter",  13, 0, 0, color, "0028", keyboardLayout });

    MapKeyboard.insert(42, KeyboardButtonInfo{QPoint( 18.91, 64.15), QRect( 11.91, 57.15, 14, 14),  "Shift L", 160, 0, 0, color, "00E1", keyboardLayout });
    MapKeyboard.insert(43, KeyboardButtonInfo{QPoint( 49.86, 64.15), QRect( 42.86, 57.15, 14, 14),        "Z",  90, 0, 0, color, "001D", keyboardLayout });
    MapKeyboard.insert(44, KeyboardButtonInfo{QPoint( 68.91, 64.15), QRect( 61.91, 57.15, 14, 14),        "X",  88, 0, 0, color, "001B", keyboardLayout });
    MapKeyboard.insert(45, KeyboardButtonInfo{QPoint( 87.96, 64.15), QRect( 80.96, 57.15, 14, 14),        "C",  67, 0, 0, color, "0006", keyboardLayout });
    MapKeyboard.insert(46, KeyboardButtonInfo{QPoint(107.01, 64.15), QRect(100.01, 57.15, 14, 14),        "V",  86, 0, 0, color, "0019", keyboardLayout });
    MapKeyboard.insert(47, KeyboardButtonInfo{QPoint(126.06, 64.15), QRect(119.06, 57.15, 14, 14),        "B",  66, 0, 0, color, "0005", keyboardLayout });
    MapKeyboard.insert(48, KeyboardButtonInfo{QPoint(145.11, 64.15), QRect(138.11, 57.15, 14, 14),        "N",  78, 0, 0, color, "0011", keyboardLayout });
    MapKeyboard.insert(49, KeyboardButtonInfo{QPoint(164.16, 64.15), QRect(157.16, 57.15, 14, 14),        "M",  77, 0, 0, color, "0010", keyboardLayout });
    MapKeyboard.insert(50, KeyboardButtonInfo{QPoint(183.21, 64.15), QRect(176.21, 57.15, 14, 14),        "<", 188, 0, 0, color, "0036", keyboardLayout });
    MapKeyboard.insert(51, KeyboardButtonInfo{QPoint(202.26, 64.15), QRect(195.26, 57.15, 14, 14),        ">", 190, 0, 0, color, "0037", keyboardLayout });
    MapKeyboard.insert(52, KeyboardButtonInfo{QPoint(221.31, 64.15), QRect(214.31, 57.15, 14, 14),        "?", 191, 0, 0, color, "0038", keyboardLayout });
    MapKeyboard.insert(53, KeyboardButtonInfo{QPoint(257.03, 64.15), QRect(250.03, 57.15, 14, 14),  "Shift R", 161, 0, 0, color, "00E5", keyboardLayout });

    MapKeyboard.insert(56, KeyboardButtonInfo{QPoint(  9.39, 83.20), QRect(  2.39, 76.20, 14, 14),   "Ctrl L", 162, 0, 0, color, "00E0", keyboardLayout });
    MapKeyboard.insert(57, KeyboardButtonInfo{QPoint( 33.20, 83.20), QRect( 26.20, 76.20, 14, 14),    "Win L",  91, 0, 0, color, "00E3", keyboardLayout });
    MapKeyboard.insert(58, KeyboardButtonInfo{QPoint( 57.01, 83.20), QRect( 50.01, 76.20, 14, 14),    "Alt L", 164, 0, 0, color, "00E2", keyboardLayout });
    MapKeyboard.insert(61, KeyboardButtonInfo{QPoint(128.44, 83.20), QRect(121.44, 76.20, 14, 14),    "Space",  32, 0, 0, color, "002C", keyboardLayout });
    MapKeyboard.insert(64, KeyboardButtonInfo{QPoint(199.89, 83.20), QRect(192.89, 76.20, 14, 14),    "Alt R", 165, 0, 0, color, "00E6", keyboardLayout });
    MapKeyboard.insert(65, KeyboardButtonInfo{QPoint(223.70, 83.20), QRect(216.70, 76.20, 14, 14),       "Fn", 999, 0, 0, color, "00FE", keyboardLayout });
    MapKeyboard.insert(66, KeyboardButtonInfo{QPoint(247.51, 83.20), QRect(240.51, 76.20, 14, 14),     "Menu", 000, 0, 0, color, "0076", keyboardLayout });
    MapKeyboard.insert(67, KeyboardButtonInfo{QPoint(271.32, 83.20), QRect(264.32, 76.20, 14, 14),   "Ctrl R", 163, 0, 0, color, "00E4", keyboardLayout });
    return MapKeyboard;
}
//读取动态动画内容
QByteArray GY_KeyboardTools::getAnimationDynamic(QString path)
{
    QByteArray dynamicBinFile;

    QFile fileRead(path);    //读取动画文件
    if(fileRead.open(QFileDevice::ReadOnly | QFileDevice::Text)){
        QByteArray readLineData; //一行一行读取
        while ( !(readLineData = fileRead.readLine()).isNull() ){
            dynamicBinFile += GY_KeyboardTools::getDynamicFillZero(readLineData.left(readLineData.size() - 2), 1); //去掉末尾的\n字节 占1个扇区
        }
    }else{
        qDebug() << "读取失败 " << path;
    }
    fileRead.close();
    return dynamicBinFile;
}
//读取静态动画内容
QByteArray GY_KeyboardTools::getAnimationStatic(QString path)
{
    QByteArray animationStaticData;
    QFile fileRead(path);
    if(fileRead.open(QFileDevice::ReadOnly)){
        animationStaticData += GY_KeyboardTools::getStaticFillZero(fileRead.readAll(), 4);
    }else{
        qDebug() << "读取失败 " << path;
    }
    fileRead.close();
    return animationStaticData;
}
//动态动画补零
QByteArray GY_KeyboardTools::getDynamicFillZero(QByteArray data, int sector)
{
    int sectorBite = 4096 * sector * 2; //扇区总字节数 - 考虑传入的字节数为16进制每次占两个字节，所以要*2
    QByteArray writeDate = data;
    for(int i = data.size(); i < sectorBite; i++){
        writeDate.append("0");
    }
    return QByteArray::fromHex(writeDate);
}
//静态动画补零
QByteArray GY_KeyboardTools::getStaticFillZero(QByteArray data, int sector)
{
    int sectorBite = 4096 * sector * 2; //扇区总字节数 - 考虑传入的字节数为16进制每次占两个字节，所以要*2
    QByteArray writeDate = data;
    //qDebug() << "读取后数据长度：" << data.size();
    for(int i = data.size(); i < sectorBite - 2 ;i++){
        writeDate.append("0");
    }
    writeDate.append("3C");
    return QByteArray::fromHex(writeDate);
}

//Float-4字节转QByteArray
QByteArray GY_KeyboardTools::getFlotaToByteArray(float data)
{
    unsigned char byteFloat[4];
    std::memcpy(byteFloat, &data, sizeof(float));
    QByteArray qByteArray((char*)byteFloat, sizeof(float));
    return qByteArray;
}

//QByteArray转Float-4字
float GY_KeyboardTools::getByteArrayToFloat(QByteArray data)
{
    float dataBate_4;
    memcpy(&dataBate_4, (char *)data.left(4).data(), sizeof(float));
    return dataBate_4;
}








/*
 * const keyValue =[
        { value: '0081', key: 'System Power', key2: '' },
        { value: '0082', key: 'System Sleep', key2: '' },
        { value: '0083', key: 'System Wake', key2: '' },
        { value: '0000', key: ' ', key2: 'NO Event' },
        { value: '0001', key: 'Overrun Error', key2: '' },
        { value: '0002', key: 'FOST Fail', key2: '' },
        { value: '0003', key: 'ErrorUndefined', key2: '' },
        { value: '0004', key: 'A', key2: 'a' },
        { value: '0005', key: 'B', key2: 'b' },
        { value: '0006', key: 'C', key2: 'c' },
        { value: '0007', key: 'D', key2: 'd' },
        { value: '0008', key: 'E', key2: 'e' },
        { value: '0009', key: 'F', key2: 'f' },
        { value: '000A', key: 'G', key2: 'g' },
        { value: '000B', key: 'H', key2: 'h' },
        { value: '000C', key: 'I', key2: 'i' },
        { value: '000D', key: 'J', key2: 'j' },
        { value: '000E', key: 'K', key2: 'k' },
        { value: '000F', key: 'L', key2: 'l' },
        { value: '0010', key: 'M', key2: 'm' },
        { value: '0011', key: 'N', key2: 'n' },
        { value: '0012', key: 'O', key2: 'o' },
        { value: '0013', key: 'P', key2: 'p' },
        { value: '0014', key: 'Q', key2: 'q' },
        { value: '0015', key: 'R', key2: 'r' },
        { value: '0016', key: 'S', key2: 's' },
        { value: '0017', key: 'T', key2: 't' },
        { value: '0018', key: 'U', key2: 'u' },
        { value: '0019', key: 'V', key2: 'v' },
        { value: '001A', key: 'W', key2: 'w' },
        { value: '001B', key: 'X', key2: 'x' },
        { value: '001C', key: 'Y', key2: 'y' },
        { value: '001D', key: 'Z', key2: 'z' },
        { value: '001E', key: '1', key2: '!' },
        { value: '001F', key: '2', key2: '@' },
        { value: '0020', key: '3', key2: '#' },
        { value: '0021', key: '4', key2: '$' },
        { value: '0022', key: '5', key2: '%' },
        { value: '0023', key: '6', key2: '^' },
        { value: '0024', key: '7', key2: '&' },
        { value: '0025', key: '8', key2: '*' },
        { value: '0026', key: '9', key2: '(' },
        { value: '0027', key: '0', key2: ')' },
        { value: '0028', key: 'ENTER', key2: 'Return' },
        { value: '0029', key: 'ESC', key2: '' },
        { value: '002A', key: 'BACKSPACE', key2: '' },
        { value: '002B', key: 'TAB', key2: '' },
        { value: '002C', key: 'SPACE', key2: '' },
        { value: '002D', key: '-', key2: '_' },
        { value: '002E', key: '=', key2: '+' },
        { value: '002F', key: '[', key2: '{' },
        { value: '0030', key: ']', key2: '}' },
        { value: '0031', key: '\\', key2: '|' },
        { value: '0032', key: 'Europe 1', key2: '' },
        { value: '0033', key: ';', key2: ':' },
        { value: '0034', key: "'", key2: '' },
        { value: '0035', key: '`', key2: '~' },
        { value: '0036', key: ',', key2: '<' },
        { value: '0037', key: '.', key2: '>' },
        { value: '0038', key: '/', key2: '?' },
        { value: '0039', key: 'CAPSLOCK', key2: '' },
        { value: '003A', key: 'F1', key2: '' },
        { value: '003B', key: 'F2', key2: '' },
        { value: '003C', key: 'F3', key2: '' },
        { value: '003D', key: 'F4', key2: '' },
        { value: '003E', key: 'F5', key2: '' },
        { value: '003F', key: 'F6', key2: '' },
        { value: '0040', key: 'F7', key2: '' },
        { value: '0041', key: 'F8', key2: '' },
        { value: '0042', key: 'F9', key2: '' },
        { value: '0043', key: 'F10', key2: '' },
        { value: '0044', key: 'F11', key2: '' },
        { value: '0045', key: 'F12', key2: '' },
        { value: '0046', key: 'Prt', key2: '' },
        { value: '0047', key: 'ScrollLock', key2: '' },
        { value: '0048', key: 'Pause', key2: 'Break' },
        { value: '0049', key: 'Insert', key2: '' },
        { value: '004A', key: 'Home', key2: '' },
        { value: '004B', key: 'Page Up', key2: '' },
        { value: '004C', key: 'Delete', key2: '' },
        { value: '004D', key: 'End', key2: '' },
        { value: '004E', key: 'Page Down', key2: '' },
        { value: '004F', key: '→', key2: '' },
        { value: '0050', key: '←', key2: '' },
        { value: '0051', key: '↓', key2: '' },
        { value: '0052', key: '↑', key2: '' },
        { value: '0053', key: 'Num Lock', key2: '' },
        { value: '0054', key: '//', key2: 'Keypad//' },
        { value: '0055', key: '*', key2: 'Keypad*' },
        { value: '0056', key: '-', key2: 'Keypad-' },
        { value: '0057', key: '+', key2: 'Keypad+' },
        { value: '0058', key: 'ENTER', key2: 'Keypad Enter' },
        { value: '0059', key: '1', key2: 'Keypad 1' },
        { value: '005A', key: '2', key2: 'Keypad 2' },
        { value: '005B', key: '3', key2: 'Keypad 3' },
        { value: '005C', key: '4', key2: 'Keypad 4' },
        { value: '005D', key: '5', key2: 'Keypad 5' },
        { value: '005E', key: '6', key2: 'Keypad 6' },
        { value: '005F', key: '7', key2: 'Keypad 7' },
        { value: '0060', key: '8', key2: 'Keypad 8' },
        { value: '0061', key: '9', key2: 'Keypad 9' },
        { value: '0062', key: '0', key2: 'Keypad 0' },
        { value: '0063', key: '.', key2: 'Keypad .' },
        { value: '0064', key: 'Europe 2', key2: '' },
        { value: '0065', key: 'App', key2: ''},
        {value: '0066', key: 'Keyboard Power', key2: ''},
        {value: '0067', key: 'Keypad =', key2: ''},
        {value: '0068', key: 'F13', key2: ''},
        {value: '0069', key: 'F14', key2: ''},
        {value: '006A', key: 'F15', key2: ''},
        {value: '006B', key: 'F16', key2: ''},
        {value: '006C', key: 'F17', key2: ''},
        {value: '006D', key: 'F18', key2: ''},
        {value: '006E', key: 'F19', key2: ''},
        {value: '006F', key: 'F20', key2: ''},
        {value: '0070', key: 'F21', key2: ''},
        {value: '0071', key: 'F22', key2: ''},
        {value: '0072', key: 'F23', key2: ''},
        {value: '0073', key: 'F24', key2: ''},
        {value: '0074', key: 'Keyboard Execute', key2: ''},
        {value: '0075', key: 'Keyboard Help', key2: ''},
        {value: '0076', key: 'MENU', key2: ''},
        {value: '0077', key: 'Keyboard Select', key2: ''},
        {value: '0078', key: 'Keyboard Stop', key2: ''},
        {value: '0079', key: 'Keyboard Again', key2: ''},
        {value: '007A', key: 'Keyboard Undo', key2: ''},
        {value: '007B', key: 'Keyboard Cut', key2: ''},
        {value: '007C', key: 'Keyboard Copy', key2: ''},
        {value: '007D', key: 'Keyboard Paste', key2: ''},
        {value: '007E', key: 'Keyboard Find', key2: ''},
        {value: '007F', key: 'Keyboard Mute', key2: ''},
        {value: '0080', key: 'Keyboard Volume Up', key2: ''},
        {value: '0081', key: 'Keyboard Volume Dn', key2: ''},
        {value: '0082', key: 'Keyboard Locking', key2: 'Caps Lock'},
        {value: '0083', key: 'Keyboard Locking', key2: 'Num Lock'},
        {value: '0084', key: 'Keyboard Locking', key2: 'Scroll Lock'},
        {value: '0085', key: 'Keyboard ,', key2: '(Brazilian Keypad.)'},
        {value: '0086', key: 'Keyboard Equal Sign', key2: ''},
        {value: '0087', key: "Keyboard Int'l 1", key2: '(Ro)'},
        {value: '0088', key: "Keyboard Intl'2", key2: '(Katakana/Hiragana)'},
        {value: '0089', key: "Keyboard Int'l 2", key2: '(Yen)'},
        {value: '008A', key: "Keyboard Int'l 4", key2: '(Henkan)'},
        {value: '008B', key: "Keyboard Int'l 5", key2: 'Muhenkan'},
        {value: '008C', key: "Keyboard Int'l 6", key2: '(PC9800 Keypad,)'},
        {value: '008D', key: "Keyboard Int'l 7", key2: ''},
        {value: '008E', key: "Keyboard Int'l 8", key2: ''},
        {value: '008F', key: "Keyboard Int'l 9", key2: ''},
        {value: '0090', key: 'Keyboard Lang 1', key2: '(Hanguel/English)'},
        {value: '0091', key: 'Keyboard Lang 2', key2: '(Hanja)'},
        {value: '0092', key: 'Keyboard Lang 3', key2: '(Katakana)'},
        {value: '0093', key: 'Keyboard Lang 4', key2: '(Hiragana)'},
        {value: '0094', key: 'Keyboard Lang 5', key2: '(Zenkaku/Hankaku)'},
        {value: '0095', key: 'Keyboard Lang 6', key2: ''},
        {value: '0096', key: 'Keyboard Lang 7', key2: ''},
        {value: '0097', key: 'Keyboard Lang 8', key2: ''},
        {value: '0098', key: 'Keyboard Lang 9', key2: ''},
        {value: '0099', key: 'Keyboard Alternate', key2: 'Erase'},
        {value: '009A', key: 'Keyboard', key2: 'SysReq/Attention'},
        {value: '009B', key: 'Keyboard Cancel', key2: ''},
        {value: '009C', key: 'Keyboard Clear', key2: ''},
        {value: '009D', key: 'Keyboard Prior', key2: ''},
        {value: '009E', key: 'ENTER', key2: ''},
        {value: '009F', key: 'Keyboard Separator', key2: ''},
        {value: '00A0', key: 'Keyboard Out', key2: ''},
        {value: '00E0', key: 'Ctrl(L)', key2: 'Ctrl(L)'},
        {value: '00E1', key: 'Shift(L)', key2: 'Shift(L)'},
        {value: '00E2', key: 'Alt(L)', key2: 'Alt(L)'},
        {value: '00E3', key: 'Win(L)', key2: 'Windows(L)'},
        {value: '00E4', key: 'Ctrl(R)', key2: 'Ctrl(R)'},
        {value: '00E5', key: 'Shift(R)', key2: 'Shift(R)'},
        {value: '00E6', key: 'Alt(R)', key2: 'Alt(R)'},
        {value: '0XE4', key: 'RLT(R)', key2: 'RLT(R)'},
        {value: '00E7', key: 'Win(R)', key2: 'Windows(R)'},
        {value: '00B5', key: 'Scan Next Track', key2: ''},
        {value: '00B6', key: 'Scan Previous Track', key2: ''},
        {value: '00B7', key: 'Stop', key2: ''},
        {value: '00CD', key: 'Play/Pause', key2: ''},
        {value: '00E8', key: 'Mute', key2: ''},
        {value: '00E5', key: 'Bass Boost', key2: ''},
        {value: '00E7', key: 'Loudness', key2: ''},
        {value: '00E9', key: 'Volume Up', key2: ''},
        {value: '00EA', key: 'Volume Down', key2: ''},
        {value: '00FE', key: 'FN', key2: 'fn'},
        {value: '0152', key: 'Bass Up', key2: ''},
        {value: '0153', key: 'Bass Down', key2: ''},
        {value: '0154', key: 'Treble Up', key2: ''},
        {value: '0155', key: 'Treble Down', key2: ''},
        {value: '0183', key: 'Media Select', key2: ''},
        {value: '018A', key: 'Mail', key2: ''},
        {value: '0192', key: 'Calculator', key2: ''},
        {value: '0194', key: 'My Computer', key2: ''},
        {value: '0221', key: 'WWW Search', key2: ''},
        {value: '0223', key: 'WWW Home', key2: ''},
        {value: '0224', key: 'WWW Back', key2: ''},
        {value: '0225', key: 'WWW Forward', key2: ''},
        {value: '0226', key: 'WWW Stop', key2: ''},
        {value: '0227', key: 'WWW Refresh', key2: ''},
        {value: '022A', key: 'WWW Favorites', key2: ''},
        {value: '00EC', key: 'Previous', key2: ''},
        {value: '00EF', key: 'Play', key2: ''},
        {value: '00EB', key: 'Next', key2: ''},
        {value: '00FB', key: 'Light  -', key2: ''},
        {value: '00FA', key: 'Light  +', key2: ''},
        // {value: '00FA', key: 'Mode', key2: ''},
        {value: '00E8', key: 'Mute', key2: ''},
        {value: '00E0', key: '^ Ctrl(L)', key2: '^ Ctrl(L)'},
        {value: '00E3', key: '⌘ Cmd(L)', key2: '⌘ Cmd(L)'},
        {value: '00E2', key: '⌥ Opt(L)', key2: '⌥ Opt(L)'},
        {value: '00E4', key: '^ Ctrl(R)', key2: '^ Ctrl(R)'},
        {value: '00E7', key: '⌘ Cmd(R)', key2: '⌘ Cmd(R)'},
        {value: '00E6', key: '⌥ Opt(R)', key2: '⌥ Opt(R)'},
        {value: '0000', key: ' ', key2: ''}, //特殊空值
        {value: '00A1', key: '配置1', key2: '配置1'},
        {value: '00A2', key: '配置2', key2: '配置2'},
        {value: '00A3', key: '配置3', key2: '配置3'},
        {value: '00A4', key: '配置4', key2: '配置4'},
        {value: '00A5', key: '配置5', key2: '配置5'},
]
 *
 *
*/


