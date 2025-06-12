#include "GY_KeyboardDrawLayout.h"
#include "ui_GY_KeyboardDrawLayout.h"

GY_KeyboardDrawLayout::GY_KeyboardDrawLayout(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_KeyboardDrawLayout)
{
    ui->setupUi(this);

    //添加按键检测
    Hook = new GY_KeyboardHook;
    connect(Hook, &GY_KeyboardHook::signalKeyPress,   this, &GY_KeyboardDrawLayout::slotKeyPress);
    connect(Hook, &GY_KeyboardHook::signalKeyRelease, this, &GY_KeyboardDrawLayout::slotKeyRelease);
    Hook->installHook(Hook);
    Hook->setGlobalHotKey(false);




    //默认内容
    keboardLayoutSize = 3; //默认缩放比例为1

    //初始化键盘配列为60配列
    mapKeyboardInfo = GY_KeyboardTools::getKeyboarLayout_60_CN();
    this->setDrawKeyborderLayout();
    QTimer::singleShot(20,this,[=](){   this->setDrawKeyborderLayout();   }); //这里在第一次绘制后必须要在重新绘制一次，不然大小会有问题。

    this->show();
}

GY_KeyboardDrawLayout::~GY_KeyboardDrawLayout()
{
    delete ui;
}

void GY_KeyboardDrawLayout::test(QString key)
{
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    pixmap.fill(QColor(0, 0, 0));  // 背景色修改
    foreach (auto item, mapKeyboardInfo) {
        if(item._KeyName == key){
            setDrawKeyBoard(painter, item._Keyborders, Qt::green, item._KeyCenterPoint, Qt::red, item._KeyName, Qt::yellow);
        }else{
            setDrawKeyBoard(painter, item._Keyborders, Qt::gray, item._KeyCenterPoint, Qt::white, item._KeyName, Qt::yellow);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}


/**
 * @brief GY_KeyboardDrawLayout::setDrawKeyborderLayout
 * 需要适当的给出位置偏移功能，整体缩放功能，对不同设备的选型绘制
 *
 */
void GY_KeyboardDrawLayout::setDrawKeyborderLayout()
{
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    pixmap.fill(QColor(0, 0, 0));  // 背景色修改
    foreach (auto item, mapKeyboardInfo) {
        setDrawKeyBoard(painter, item._Keyborders, Qt::gray, item._KeyCenterPoint, Qt::white, item._KeyName, Qt::yellow);
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}


//把每一个按键进行一个绘制，将所有的绘制进行一次分离，这样检测以下，是不是每个按键都可以独立绘制
void GY_KeyboardDrawLayout::setDrawKeyBoard(QPainter &painter, QRect rectboard, QColor colorRect, QPoint centerPoint, QColor colorLight, QString text, QColor colorText, bool isFill, QColor colorFill)
{
    float  sidePosX = 0, sidePosY = 0, sideWidth = 0, sideHeight = 0, lightCenterX = 0, lightCenterY = 0, lightRadiusX = 0, lightRadiusY = 0;
    float radius = (mapKeyboardInfo.first()._KeyCenterPoint.x() - mapKeyboardInfo.first()._Keyborders.x() + 0) * keboardLayoutSize;
    //---------------------------------------------------绘制按键四周边框--------------------------------------------------------------
    QPen pen(3);
    pen.setColor(colorRect);
    painter.setPen(pen);
    sidePosX   = rectboard.x() * keboardLayoutSize;         //对x点整体放大
    sidePosY   = rectboard.y() * keboardLayoutSize;         //对y点整体放大
    sideWidth  = rectboard.width() * keboardLayoutSize;     //对边长整体放大
    sideHeight = rectboard.height() * keboardLayoutSize;    //对边宽整体放大
    painter.drawRect(sidePosX, sidePosY, sideWidth, sideHeight);    //绘制边框
    qDebug() << "边框位置：" << sidePosX << "," << sidePosY << "," << sideWidth << "," << sideHeight;
    //--------------------------------------------------绘制按键中心点灯光-------------------------------------------------------------
    QPoint pointCenter(centerPoint.x() * keboardLayoutSize, centerPoint.y() * keboardLayoutSize); //对键盘等比缩放
    QRadialGradient Radial(pointCenter, radius, pointCenter);                                       //设置圆的原点和焦点在中心,半径120
    Radial.setColorAt(  0, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255/1.8));
    Radial.setColorAt(0.7, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255/7));  //设置50%处的半径为蓝色
    Radial.setColorAt(  1, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 0));
    painter.setPen(Qt::transparent);
    painter.setBrush(Radial);
    lightCenterX = pointCenter.x() - radius;
    lightCenterY = pointCenter.y() - radius;
    lightRadiusX = lightRadiusY = radius  * 2 ;
    if(isFill == false){
        painter.drawEllipse(lightCenterX, lightCenterY, lightRadiusX, lightRadiusY);
    }else{
        painter.fillRect(sidePosX, sidePosY, sideWidth, sideHeight, colorFill);

    }
    //-----------------------------------------------------绘制按键字符---------------------------------------------------------------
    pen.setColor(colorText);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setFont(QFont("微软雅黑", 9, QFont::Bold ));
    painter.drawText(pointCenter.x() - rectboard.width(), pointCenter.y(), text);
    qDebug() << "-----光圈位置：" << lightCenterX << "," << lightCenterY << "," << lightRadiusX << "," << lightRadiusY << ", 键名：" << text;
}


void GY_KeyboardDrawLayout::slotKeyPress(GY_KeyboardHook::KeyInfo key)
{
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, ui->label->pixmap()); // 绘制原始图片
    foreach (auto item, mapKeyboardInfo) {
        if(item._KeyValue == key.KeyValue){
            setDrawKeyBoard(painter, item._Keyborders, Qt::green, item._KeyCenterPoint, Qt::green, item._KeyName, Qt::red, true, Qt::green);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}

void GY_KeyboardDrawLayout::slotKeyRelease(GY_KeyboardHook::KeyInfo key)
{
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, ui->label->pixmap()); // 绘制原始图片
    foreach (auto item, mapKeyboardInfo) {
        if(item._KeyValue == key.KeyValue){
            setDrawKeyBoard(painter, item._Keyborders, Qt::red, item._KeyCenterPoint, Qt::green, item._KeyName, Qt::white, true);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}

