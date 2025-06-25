#ifndef GY_KEYBOARDDRAWLAYOUT_H
#define GY_KEYBOARDDRAWLAYOUT_H

#include <QWidget>
#include <GY_Tools/GY_KeyboardTools.h>
#include <GY_Tools/WindowsHook/GY_KeyboardHook.h>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QRadialGradient>
#include <QTimer>
#include <QRgb>
#include <QMouseEvent>
#include <QFileDevice>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class GY_KeyboardDrawLayout;
}

class GY_KeyboardDrawLayout : public QWidget
{
    Q_OBJECT

public:
    explicit GY_KeyboardDrawLayout(QWidget *parent = nullptr);
    ~GY_KeyboardDrawLayout();

    void test(QString key);//测试专用

    void setKeyboardType(GY_KeyboardTools::KeyboardType keyboardType);   //设置键盘类型
    void setKeyboardLayoutSize(double size);    //等比放大与缩小
    void setDrawKeyborderLayout();              //绘制键盘 - 边框布局


signals:
    void signalKeyboardDrawLayoutUpdateSimulatePos();    //修改模拟位置完成

public slots:
    void slotKeyboardSettingClearKey();                  //清空键盘按键操作
    void slotKeyboardSettingDrawSize(double size);       //调整绘制键盘大小
    void slotKeyboardSettingHook(bool isHook);           //键盘钩子功能-是否开启
    void slotKeyboardSettingKeyCheck(bool isCheck);      //按键检测功能-是否开启
    void slotAnimationStaticSimulate(QString path, QStringList listStaticPictureName, bool isStart);      //静态动画模拟
    void slotAnimationDynamicSimulate(QString path, QStringList listDynamicPictureName, bool isStart);    //动态动画模拟
    void slotAnimationStaticOnlySimulate(QString path, QString onlyName);                   //静态动画逐帧模拟
    void slotAnimationDynamicOnlySimulate(QString path, QString onlyName);                  //动态动画逐帧模拟
    void slotAnimationStaticUiSimulateSpeed(int speed);         //静态ui模拟速度
    void slotAnimationDynamicUiSimulateSpeed(int speed);        //动态ui模拟速度
    void slotAnimationStaticSendSimulateSpeed(int speed);       //静态键盘下发模拟速度
    void slotAnimationDynamicSendSimulateSpeed(int speed);      //动态键盘下发模拟速度
    void slotAnimationDynamicUpdateSimulatePos();               //更改动态动画模拟按键位置
    void slotAnimationStaticExport(QStringList path);           //静态动画导出
    void slotAnimationDynamicExport(QStringList path);          //动态动画导出


private slots:
    void slotKeyPress(GY_KeyboardHook::KeyInfo key);    //键盘按下
    void slotKeyRelease(GY_KeyboardHook::KeyInfo key);  //键盘抬起
    void slotTimerAnimationStaticSimulate();            //定时器 - 槽函数 - 静态动画开始模拟
    void slotTimerAnimationDynamicSimulate();           //定时器 - 槽函数 - 动态动画开始模拟
    virtual void mousePressEvent(QMouseEvent *event) override;  //鼠标点击事件

private:/**
     * @brief setDrawKeyBoard
     * @param painter
     * @param rectboard
     * @param colorRect
     * @param centerPoint
     * @param colorLight
     * @param text
     * @param colorText
     * @param isFill
     * @param colorFill
     * @param isAnimationType true = 静态动画 || false = 动态动画
     */
    void setDrawKeyBoard(QPainter &painter, QRect rectboard, QColor colorRect, QPoint centerPoint, QColor colorLight, QString text, QColor colorText, bool isAnimationType = true, bool isFill = false, QColor colorFill = Qt::red);      //单独绘制一个按键
    void setAnimationSimulate(QString path, bool isAnimation = true);        //静态/动态动画模拟  默认静态动画
private:
    Ui::GY_KeyboardDrawLayout *ui;
    GY_KeyboardHook *Hook;      //按键钩子检测
    int keyboardMove = 30, staticAnimationSimulateSpeed = 50, dynamicAnimationSimulateSpeed = 50;      //界面绘制键盘偏移, 静态动画模拟速度，动态动画模拟速度
    double keboardLayoutSize;   //键盘大小
    bool keyboardCheck, isDynamicSimulationPos;         //键盘检测功能,，动态动画模拟修改位置
    QTimer *AnimationStaticSimulate, *AnimationDynamicSimulate;
    QMap<int, GY_KeyboardTools::KeyboardButtonInfo> mapKeyboardInfo;
    QStringList listStaticPictureName, listDynamicPictureName;//存放地址每个图片的地址
    GY_KeyboardTools::KeyboardButtonInfo dynamicSimulatePos;   //更改动态动画模拟点位专用记录
};

#endif // GY_KEYBOARDDRAWLAYOUT_H
