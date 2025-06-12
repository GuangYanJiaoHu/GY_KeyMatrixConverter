#ifndef GY_KEYBOARDDRAWLAYOUT_H
#define GY_KEYBOARDDRAWLAYOUT_H

#include <QWidget>
#include <GY_Tools/GY_KeyboardTools.h>
#include <GY_Tools/WindowsHook/GY_KeyboardHook.h>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QRadialGradient>
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

    void setKeyboardLayoutSize(double size);    //等比放大与缩小
    void setDrawKeyborderLayout();              //绘制键盘 - 边框布局

private slots:
    void slotKeyPress(GY_KeyboardHook::KeyInfo key);    //键盘按下
    void slotKeyRelease(GY_KeyboardHook::KeyInfo key);  //键盘抬起

private:
    void setDrawKeyBoard(QPainter &painter, QRect rectboard, QColor colorRect, QPoint centerPoint, QColor colorLight, QString text, QColor colorText, bool isFill = false, QColor colorFill = Qt::red);      //单独绘制一个按键


private:
    Ui::GY_KeyboardDrawLayout *ui;
    GY_KeyboardHook *Hook;//按键钩子检测
    double keboardLayoutSize;
    QMap<int, GY_KeyboardTools::KeyboardButtonInfo> mapKeyboardInfo;
};

#endif // GY_KEYBOARDDRAWLAYOUT_H
