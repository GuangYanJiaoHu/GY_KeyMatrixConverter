#include "GY_KeyboardDrawLayout.h"
#include "ui_GY_KeyboardDrawLayout.h"

GY_KeyboardDrawLayout::GY_KeyboardDrawLayout(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_KeyboardDrawLayout)
{
    ui->setupUi(this);

    //静态动画开始模拟
    AnimationStaticSimulate = new QTimer;
    connect(AnimationStaticSimulate, &QTimer::timeout, this, &GY_KeyboardDrawLayout::slotTimerAnimationStaticSimulate);
    //动态动画开始模拟
    AnimationDynamicSimulate = new QTimer;
    connect(AnimationDynamicSimulate, &QTimer::timeout, this, &GY_KeyboardDrawLayout::slotTimerAnimationDynamicSimulate);

    //添加按键检测
    Hook = new GY_KeyboardHook;
    connect(Hook, &GY_KeyboardHook::signalKeyPress,   this, &GY_KeyboardDrawLayout::slotKeyPress);
    connect(Hook, &GY_KeyboardHook::signalKeyRelease, this, &GY_KeyboardDrawLayout::slotKeyRelease);
    Hook->installHook(Hook);        //安装键盘检测模块
    Hook->setGlobalHotKey(false);    //默认开启钩子

    //默认内容
    this->keboardLayoutSize = 3; //默认缩放比例为1
    this->keyboardCheck = false; //默认不开启键盘检测功能
    this->setKeyboardType(GY_KeyboardTools::_Keyboard_60_CN_);//初始化键盘配列为60配列
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

//设置键盘类型
void GY_KeyboardDrawLayout::setKeyboardType(GY_KeyboardTools::KeyboardType keyboardType)
{
    switch(keyboardType){
    case GY_KeyboardTools::_Keyboard_60_CN_:
        mapKeyboardInfo = GY_KeyboardTools::getKeyboarLayout_60_CN();
        break;

    default:break;
    }
    this->dynamicSimulatePos = mapKeyboardInfo.first();
}

void GY_KeyboardDrawLayout::setKeyboardLayoutSize(double size)
{
    this->keboardLayoutSize = size;
    this->setDrawKeyborderLayout();
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
//清空键盘按键操作
void GY_KeyboardDrawLayout::slotKeyboardSettingClearKey()
{
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    pixmap.fill(QColor(0, 0, 0));  // 背景色修改
    foreach (auto item, mapKeyboardInfo) {
        setDrawKeyBoard(painter, item._Keyborders, Qt::gray, item._KeyCenterPoint, Qt::white, item._KeyName, Qt::yellow);
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}
//调整绘制键盘大小
void GY_KeyboardDrawLayout::slotKeyboardSettingDrawSize(double size)
{
    this->keboardLayoutSize = size;
    this->setDrawKeyborderLayout();
}
//键盘钩子是否开启
void GY_KeyboardDrawLayout::slotKeyboardSettingHook(bool isHook)
{
    Hook->setGlobalHotKey(isHook);
}
//按键检测功能-是否开启
void GY_KeyboardDrawLayout::slotKeyboardSettingKeyCheck(bool isCheck)
{
    this->keyboardCheck = isCheck;
}

//静态动画模拟
void GY_KeyboardDrawLayout::slotAnimationStaticSimulate(QString path, QStringList listStaticPicturePath, bool isStart)
{
    if(listStaticPicturePath.count() == 0){
        return;
    }
    if(isStart){
        this->listStaticPictureName.clear();
        for(int i = 0; i < listStaticPicturePath.count(); i++){
            this->listStaticPictureName.append(path + listStaticPicturePath.at(i));
        }
        AnimationStaticSimulate->start(this->staticAnimationSimulateSpeed);
    }else{
        AnimationStaticSimulate->stop();
    }
}
//定时器 - 槽函数 - 静态动画开始模拟
void GY_KeyboardDrawLayout::slotTimerAnimationStaticSimulate()
{
    static int staticAnimationIndex = 0;    //listStaticPictureName
    if(staticAnimationIndex >= this->listStaticPictureName.count()){
        staticAnimationIndex = 0;
    }
    this->setAnimationSimulate(this->listStaticPictureName.at(staticAnimationIndex), true);
    staticAnimationIndex++;
}
//静态动画逐帧模拟
void GY_KeyboardDrawLayout::slotAnimationStaticOnlySimulate(QString path, QString onlyPath)
{
    this->setAnimationSimulate(path + onlyPath, true);
}

//动态动画模拟
void GY_KeyboardDrawLayout::slotAnimationDynamicSimulate(QString path, QStringList listDynamicPicturePath, bool isStart)
{
    qDebug() << "动态动画模拟";
    if(listDynamicPicturePath.count() == 0){
        return;
    }
    if(isStart){
        this->listDynamicPictureName.clear();
        for(int i = 0; i < listDynamicPicturePath.count(); i++){
            this->listDynamicPictureName.append(path + listDynamicPicturePath.at(i));
        }
        AnimationDynamicSimulate->start(this->dynamicAnimationSimulateSpeed);
    }else{
        AnimationDynamicSimulate->stop();
    }
}
//定时器 - 槽函数 - 动态动画开始模拟
void GY_KeyboardDrawLayout::slotTimerAnimationDynamicSimulate()
{
    static int dynamicAnimationIndex = 0;
    if(dynamicAnimationIndex >= this->listDynamicPictureName.count()){
        dynamicAnimationIndex = 0;
    }
    this->setAnimationSimulate(this->listDynamicPictureName.at(dynamicAnimationIndex), false);
    dynamicAnimationIndex++;
}
//动态动画逐帧模拟
void GY_KeyboardDrawLayout::slotAnimationDynamicOnlySimulate(QString path, QString onlyPath)
{
    this->setAnimationSimulate(path + onlyPath, false);
}

//静态/动态动画模拟  默认静态动画
void GY_KeyboardDrawLayout::setAnimationSimulate(QString path, bool isAnimation)
{
    QImage image(path);
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    pixmap.fill(QColor(0, 0, 0));   // 背景色修改
    if(isAnimation){                //静态动画
        QImage newImage = image.scaled(mapKeyboardInfo.first()._KeyboardLayout._MaxWidth, mapKeyboardInfo.first()._KeyboardLayout._MaxHeight ,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);   //70配列
        foreach (auto item, mapKeyboardInfo) {
            QColor lightColor = newImage.pixelColor(item._KeyCenterPoint);
            this->setDrawKeyBoard(painter, item._Keyborders, Qt::gray, item._KeyCenterPoint, lightColor, item._KeyName, Qt::yellow);
        }
    }else{                          //动态动画
        QImage newImage = image.scaled(100, 100, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);   //70配列-100x100大小后续改成用户可调节的大小方式-对图片整体方法符合键盘尺寸
        QImage drawImage= image.scaled(100 * keboardLayoutSize, 100 * keboardLayoutSize, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);   //70配列-100x100大小后续改成用户可调节的大小方式-对图片整体方法符合键盘尺寸
        QPoint newImageCenterPoint(drawImage.size().width() / 2, drawImage.size().height() / 2);                                                                      //图片的中心点计算
        QPoint keyCenterPoint(this->dynamicSimulatePos._KeyCenterPoint.x() * keboardLayoutSize, this->dynamicSimulatePos._KeyCenterPoint.y() * keboardLayoutSize);  //按键的中心点计算
        //显示底图
        QPoint imageMoveKeyPoint(keyCenterPoint.x() - newImageCenterPoint.x() + keyboardMove, keyCenterPoint.y() - newImageCenterPoint.y() + keyboardMove);         //计算图片移动到按键中心点偏移位置
        //painter.drawImage(imageMoveKeyPoint.x(), imageMoveKeyPoint.y(), drawImage);  //显示绘制图片

        //计算图片中心点与键盘按键中心点比例关系
        QPoint imageOrKeyRatio(newImage.width() / 2.00 - this->dynamicSimulatePos._KeyCenterPoint.x(), newImage.height() / 2.00 - this->dynamicSimulatePos._KeyCenterPoint.y());
        foreach (auto item, mapKeyboardInfo) {
            QColor lightColor;
            if(!newImage.rect().contains(QPoint(item._KeyCenterPoint.x() + imageOrKeyRatio.x(), item._KeyCenterPoint.y() + imageOrKeyRatio.y()))){
                lightColor = newImage.pixelColor(0, 0);
            }else{
                lightColor = newImage.pixelColor(item._KeyCenterPoint.x() + imageOrKeyRatio.x(), item._KeyCenterPoint.y() + imageOrKeyRatio.y());
            }
            this->setDrawKeyBoard(painter, item._Keyborders, Qt::gray, item._KeyCenterPoint, lightColor, item._KeyName, Qt::yellow, false);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}

//静态ui模拟速度
void GY_KeyboardDrawLayout::slotAnimationStaticUiSimulateSpeed(int speed)
{
    qDebug() << "静态速度更改:" << speed;
    this->staticAnimationSimulateSpeed = speed;
    if(this->AnimationStaticSimulate->isActive()){
        this->AnimationStaticSimulate->start(speed);
    }
}
//动态ui模拟速度
void GY_KeyboardDrawLayout::slotAnimationDynamicUiSimulateSpeed(int speed)
{
    qDebug() << "静态速度更改:" << speed;
    this->dynamicAnimationSimulateSpeed = speed;
    if(this->AnimationDynamicSimulate->isActive()){
        this->AnimationDynamicSimulate->start(speed);
    }
}
//静态键盘下发模拟速度
void GY_KeyboardDrawLayout::slotAnimationStaticSendSimulateSpeed(int speed)
{

}
//动态键盘下发模拟速度
void GY_KeyboardDrawLayout::slotAnimationDynamicSendSimulateSpeed(int speed)
{

}
//更改动态动画模拟按键位置
void GY_KeyboardDrawLayout::slotAnimationDynamicUpdateSimulatePos()
{
    this->isDynamicSimulationPos = true;
}
//静态动画导出
void GY_KeyboardDrawLayout::slotAnimationStaticExport(QStringList path)
{
    qDebug() << "静态动画导出" << path;
    QList<QString> listStaticHexColor;
    QColor lightColor;
    foreach(auto itor, path){
        QImage image(itor);
        QImage newImage = image.scaled(mapKeyboardInfo.first()._KeyboardLayout._MaxWidth, mapKeyboardInfo.first()._KeyboardLayout._MaxHeight ,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);   //70配列
        for(int i = 0; i < dynamicSimulatePos._KeyboardLayout._ButtonCount; i++){
            if(mapKeyboardInfo.contains(i)){
                auto item = mapKeyboardInfo.find(i);
                lightColor = newImage.pixelColor(item.value()._KeyCenterPoint);
                listStaticHexColor.append(QString("%1%2%3").arg(lightColor.red(),  2, 16, QChar('0')).arg(lightColor.green(),2, 16, QChar('0')).arg(lightColor.blue(), 2, 16, QChar('0')));
            }else{  //没有这个按键，空白3个
                listStaticHexColor.append("000000");
            }
        }
    }
    QFile file(QFileDialog::getSaveFileName(this,"", "", "静态动画(*.sta);;所有文件 (*);")); //static Animation
    if(file.open(QFileDevice::WriteOnly)){
        for(int i = 0; i < listStaticHexColor.count(); i++){
            file.write(listStaticHexColor.at(i).toUtf8());
        }
        file.close();
    }else{
        qDebug() << "写入失败";
    }
}
//动态动画导出
void GY_KeyboardDrawLayout::slotAnimationDynamicExport(QStringList path)
{
    qDebug() << "动态动画导出" << path;
}
//鼠标点击事件
void GY_KeyboardDrawLayout::mousePressEvent(QMouseEvent *event)
{
    if(this->isDynamicSimulationPos){
        this->isDynamicSimulationPos = false;
        QPoint pos = (event->pos() - QPoint(keyboardMove, keyboardMove)) / this->keboardLayoutSize;
        for(QMap<int, GY_KeyboardTools::KeyboardButtonInfo>::iterator item = mapKeyboardInfo.begin(); item != mapKeyboardInfo.end(); ++item){
            if(item.value()._Keyborders.contains(pos)){
                qDebug() << "包含："<< pos;
                this->dynamicSimulatePos = item.value();
                emit signalKeyboardDrawLayoutUpdateSimulatePos();
                return;
            }
        }
    }
    this->dynamicSimulatePos = mapKeyboardInfo.first(); //保险
}

//把每一个按键进行一个绘制，将所有的绘制进行一次分离，这样检测以下，是不是每个按键都可以独立绘制
void GY_KeyboardDrawLayout::setDrawKeyBoard(QPainter &painter, QRect rectboard, QColor colorRect, QPoint centerPoint, QColor colorLight, QString text, QColor colorText, bool isAnimationType, bool isFill, QColor colorFill)
{
    float  sidePosX = 0, sidePosY = 0, sideWidth = 0, sideHeight = 0, lightCenterX = 0, lightCenterY = 0, lightRadiusX = 0, lightRadiusY = 0;
    float radius = (mapKeyboardInfo.first()._KeyCenterPoint.x() - mapKeyboardInfo.first()._Keyborders.x() + 0) * keboardLayoutSize;

    //---------------------------------------------------绘制按键四周边框--------------------------------------------------------------
    QPen pen(3);
    pen.setColor(colorRect);
    painter.setPen(pen);
    sidePosX   = rectboard.x() * keboardLayoutSize + keyboardMove;  //对x点整体放大
    sidePosY   = rectboard.y() * keboardLayoutSize + keyboardMove;  //对y点整体放大
    sideWidth  = rectboard.width() * keboardLayoutSize;             //对边长整体放大
    sideHeight = rectboard.height() * keboardLayoutSize;            //对边宽整体放大
    painter.drawRect(sidePosX, sidePosY, sideWidth, sideHeight);    //绘制边框

    //--------------------------------------------------绘制按键中心点灯光-------------------------------------------------------------
    QPoint pointCenter(centerPoint.x() * keboardLayoutSize + keyboardMove, centerPoint.y() * keboardLayoutSize + keyboardMove); //对键盘等比缩放
    QRadialGradient Radial(pointCenter, radius, pointCenter);                                       //设置圆的原点和焦点在中心,半径120
    //对动态动画与今天动画分别处理 true = 静态动画 || false = 动态动画
    if(isAnimationType == true){
        Radial.setColorAt(  0, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255/1.8));
        Radial.setColorAt(0.7, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255/7));  //设置50%处的半径为蓝色
        Radial.setColorAt(  1, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 13));
    }else{
        Radial.setColorAt(  0, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255));
        Radial.setColorAt(0.5, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 255/2)); //设置50%处的半径为蓝色
        Radial.setColorAt(  1, QColor(colorLight.red(), colorLight.green(), colorLight.blue(), 13));
    }
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
}

//键盘按下事件
void GY_KeyboardDrawLayout::slotKeyPress(GY_KeyboardHook::KeyInfo key)
{
    qDebug() << "按下：" << key.KeyValue;
    if(!this->keyboardCheck){
        qDebug() << "未勾选按键检测";
        return;
    }
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, ui->label->pixmap()); // 绘制原始图片
    foreach (auto item, mapKeyboardInfo) {
        if(item._KeyValue == key.KeyValue){
            setDrawKeyBoard(painter, item._Keyborders, Qt::green, item._KeyCenterPoint, Qt::green, item._KeyName, Qt::red, true, true, Qt::green);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}
//键盘抬起事件
void GY_KeyboardDrawLayout::slotKeyRelease(GY_KeyboardHook::KeyInfo key)
{
    qDebug() << key.KeyValue;
    if(!this->keyboardCheck){
        return;
    }
    QPixmap pixmap(ui->label->size());
    QPainter painter(&pixmap);
    painter.drawPixmap(0, 0, ui->label->pixmap()); // 绘制原始图片
    foreach (auto item, mapKeyboardInfo) {
        if(item._KeyValue == key.KeyValue){
            setDrawKeyBoard(painter, item._Keyborders, Qt::red, item._KeyCenterPoint, Qt::green, item._KeyName, Qt::white, true, true);
        }
    }
    ui->label->setPixmap(pixmap);   // 更新到窗口部件上
}
