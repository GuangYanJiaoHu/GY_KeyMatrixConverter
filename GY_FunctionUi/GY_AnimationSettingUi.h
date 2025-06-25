#ifndef GY_ANIMATIONSETTINGUI_H
#define GY_ANIMATIONSETTINGUI_H

#include <QWidget>
#include <GY_Tools/GY_KeyboardTools.h>
#include <QFileDialog>
#include <QFile>
#include <QDir>

namespace Ui {
class GY_AnimationSettingUi;
}

class GY_AnimationSettingUi : public QWidget
{
    Q_OBJECT

public:
    explicit GY_AnimationSettingUi(QWidget *parent = nullptr);
    ~GY_AnimationSettingUi();

public slots:
    void slotKeyboardDrawLayoutUpdateSimulatePos();    //修改模拟位置完成

private slots:
    void on_pushButton_StaticReadPath_clicked();                        //读取静态动画地址
    void on_pushButton_DynamicReadPath_clicked();                       //动态动画读取地址
    void on_pushButton_StaticStart_clicked();                           //静态动画开始模拟
    void on_pushButton_DynamicStart_clicked();                          //动态动画开始模拟
    void on_comboBox_StaticOnlySimulate_currentIndexChanged(int index); //静态动画逐帧模拟
    void on_comboBox_DynamicOnlySimulate_currentIndexChanged(int index);//动态动画逐帧模拟
    void on_horizontalSlider_StaticUi_sliderReleased();                 //静态动画界面速度模拟 - 抬手发送
    void on_horizontalSlider_StaticSend_sliderReleased();               //静态动画键盘下发速度模拟 - 抬手发送
    void on_horizontalSlider_StaticUi_valueChanged(int value);          //静态动画界面速度模拟 - 给控件显示专用
    void on_horizontalSlider_StaticSend_valueChanged(int value);        //静态动画键盘下发速度模拟 - 给控件显示专用
    void on_horizontalSlider_DynamicUi_sliderReleased();                //动态动画界面速度模拟 - 抬手发送
    void on_horizontalSlider_DynamicSend_sliderReleased();              //动态动画键盘下发速度模拟 - 抬手发送
    void on_horizontalSlider_DynamicUi_valueChanged(int value);         //动态动画界面速度模拟 - 给控件显示专用
    void on_horizontalSlider_DynamicSend_valueChanged(int value);       //动态动画键盘下发速度模拟 - 给控件显示专用
    void on_pushButton_DynamicUpdateSimulatePos_clicked();              //更改动态动画模拟按键位置

    void on_pushButton_StaticExport_clicked();

    void on_pushButton_DynamicExport_clicked();

signals:
    void signalAnimationStaticSimulate(QString path, QStringList listStaticPictureName, bool isStart);      //静态动画模拟
    void signalAnimationDynamicSimulate(QString path, QStringList listDynamicPicturePath, bool isStart);    //动态动画模拟
    void signalAnimationStaticOnlySimulate(QString path, QString onlyName);                                 //静态动画逐帧模拟
    void signalAnimationDynamicOnlySimulate(QString path, QString onlyName);                                //动态动画逐帧模拟
    void signalAnimationStaticUiSimulateSpeed(int speed);               //静态ui模拟速度
    void signalAnimationDynamicUiSimulateSpeed(int speed);              //动态ui模拟速度
    void signalAnimationStaticSendSimulateSpeed(int speed);             //静态键盘下发模拟速度
    void signalAnimationDynamicSendSimulateSpeed(int speed);            //动态键盘下发模拟速度
    void signalAnimationDynamicUpdateSimulatePos();                     //动态动画更改模拟位置
    void signalAnimationStaticExport(QStringList path);                 //静态动画导出
    void signalAnimationDynamicExport(QStringList path);                //动态动画导出

private:
    Ui::GY_AnimationSettingUi *ui;
    QStringList listStaticPicturePath, listDynamicPicturePath;  //存储静态/动态动画地址
};

#endif // GY_ANIMATIONSETTINGUI_H
