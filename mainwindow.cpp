#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建键盘绘制区域
    keyboardDrawLayout = new GY_KeyboardDrawLayout(ui->widget_keyboardLayout);
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_keyboardLayout);
    layout->addWidget(keyboardDrawLayout);
    layout->setContentsMargins(0, 0, 0, 0);

    //创建键盘设置界面
    keyboardSettingUi = new GY_KeyboardSettingUi(ui->widget_KeyboardSetting);
    connect(keyboardSettingUi, &GY_KeyboardSettingUi::signalKeyboardSettingClearKey, keyboardDrawLayout, &GY_KeyboardDrawLayout::slotKeyboardSettingClearKey);  //清空按键检测
    connect(keyboardSettingUi, &GY_KeyboardSettingUi::signalKeyboardSettingDrawSize, keyboardDrawLayout, &GY_KeyboardDrawLayout::slotKeyboardSettingDrawSize);  //键盘绘制尺寸
    connect(keyboardSettingUi, &GY_KeyboardSettingUi::signalKeyboardSettingHook,     keyboardDrawLayout, &GY_KeyboardDrawLayout::slotKeyboardSettingHook);      //键盘钩子
    connect(keyboardSettingUi, &GY_KeyboardSettingUi::signalKeyboardSettingKeyCheck, keyboardDrawLayout, &GY_KeyboardDrawLayout::slotKeyboardSettingKeyCheck);  //按键检测功能
    QVBoxLayout *layout2 = new QVBoxLayout(ui->widget_KeyboardSetting);
    layout2->addWidget(keyboardSettingUi);
    layout2->setContentsMargins(0, 0, 0, 0);

    //创建键盘动画模拟界面
    animationSettingUi = new GY_AnimationSettingUi(ui->widget_Animation);
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationStaticSimulate,          keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationStaticSimulate);               //静态动画模拟
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicSimulate,         keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicSimulate);              //动态动画模拟
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationStaticOnlySimulate,      keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationStaticOnlySimulate);           //静态动画逐帧模拟
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicOnlySimulate,     keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicOnlySimulate);          //动态动画逐帧模拟
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationStaticUiSimulateSpeed,   keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationStaticUiSimulateSpeed);        //静态ui模拟速度
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicUiSimulateSpeed,  keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicUiSimulateSpeed);       //动态ui模拟速度
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationStaticSendSimulateSpeed, keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationStaticSendSimulateSpeed);      //静态键盘下发模拟速度
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicSendSimulateSpeed,keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicSendSimulateSpeed);     //动态键盘下发模拟速度
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicUpdateSimulatePos,keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicUpdateSimulatePos);     //更改动态动画模拟按键位置
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationStaticExport,            keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationStaticExport);                 //静态动画导出
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicExport,           keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicExport);                //动态动画导出
    connect(animationSettingUi, &GY_AnimationSettingUi::signalAnimationDynamicPixmapSize,       keyboardDrawLayout, &GY_KeyboardDrawLayout::slotAnimationDynamicPixmapSize);            //动态动画导出
    connect(keyboardDrawLayout, &GY_KeyboardDrawLayout::signalKeyboardDrawLayoutUpdateSimulatePos,animationSettingUi, &GY_AnimationSettingUi::slotKeyboardDrawLayoutUpdateSimulatePos); //更改模拟位置完成
    QVBoxLayout *layout3 = new QVBoxLayout(ui->widget_Animation);
    layout3->addWidget(animationSettingUi);
    layout3->setContentsMargins(0, 0, 0, 0);

    //bin文件生成
    generateBinFile = new GY_GenerateBinFile();
    QVBoxLayout *layout4 = new QVBoxLayout(ui->widget_GenerateBinFile);
    layout4->addWidget(generateBinFile);
    layout4->setContentsMargins(0, 0, 0, 0);

    //bin文件转换
    convertBinFile = new GY_ConvertBinFile();
    QVBoxLayout *layout5 = new QVBoxLayout(ui->widget_ConvertBinFile);
    layout5->addWidget(convertBinFile);
    layout5->setContentsMargins(0, 0, 0, 0);

    //自定义动画
    animationCustomize = new GY_AnimationCustomize();
    connect(animationCustomize, &GY_AnimationCustomize::signalCustomizeAnimationIsDraw, keyboardDrawLayout, GY_KeyboardDrawLayout::slotCustomizeAnimationIsDraw);   //自定义图案绘制
    connect(animationCustomize, &GY_AnimationCustomize::signalCustomizeClearKey,        keyboardDrawLayout, GY_KeyboardDrawLayout::slotKeyboardSettingClearKey);    //清空绘制

    QVBoxLayout *layout6 = new QVBoxLayout(ui->widget_Customize);
    layout6->addWidget(animationCustomize);
    layout6->setContentsMargins(0, 0, 0, 0);

}

MainWindow::~MainWindow()
{
    delete ui;
}



