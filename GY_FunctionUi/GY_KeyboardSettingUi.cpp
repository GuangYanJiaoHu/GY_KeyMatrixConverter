#include "GY_KeyboardSettingUi.h"
#include "ui_GY_KeyboardSettingUi.h"

GY_KeyboardSettingUi::GY_KeyboardSettingUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_KeyboardSettingUi)
{
    ui->setupUi(this);
    //默认第一个键盘
    ui->comboBox_KeyboardType->setCurrentIndex(0);
    //默认开启键盘钩子
    ui->checkBox_Hook->setChecked(false);
}

GY_KeyboardSettingUi::~GY_KeyboardSettingUi()
{
    delete ui;
}

//键盘类型调整 - 切记这里的类型要和tools中的枚举类型要一一对应起来
void GY_KeyboardSettingUi::on_comboBox_KeyboardType_currentIndexChanged(int index)
{
    qDebug() << "键盘类型调整";
}

//清空按键检测，让主界面重新绘制
void GY_KeyboardSettingUi::on_pushButton_ClearKeyboard_clicked()
{
    emit signalKeyboardSettingClearKey();
}

//调整绘制键盘大小 - 滑块
void GY_KeyboardSettingUi::on_horizontalSlider_Size_sliderMoved(int position)
{
    ui->doubleSpinBox_Size->setValue(position / 10.00);
    emit signalKeyboardSettingDrawSize(ui->doubleSpinBox_Size->value());
}

//调整绘制键盘大小
void GY_KeyboardSettingUi::on_doubleSpinBox_Size_valueChanged(double arg1)
{
    ui->horizontalSlider_Size->setValue(arg1 * 10.00);
    emit signalKeyboardSettingDrawSize(arg1);
}

//键盘钩子功能 - 是否开启
void GY_KeyboardSettingUi::on_checkBox_Hook_stateChanged(int arg1)
{
    emit signalKeyboardSettingHook(arg1);
}

//按键检测功能 - 是否开启
void GY_KeyboardSettingUi::on_checkBox_KeyCheck_stateChanged(int arg1)
{
    emit signalKeyboardSettingKeyCheck(arg1);
}

//键盘灯光调整
void GY_KeyboardSettingUi::on_horizontalSlider_Light_sliderMoved(int position)
{
    ui->spinBox_Light->setValue(position);
}

//键盘灯光调整
void GY_KeyboardSettingUi::on_spinBox_Light_valueChanged(int arg1)
{
    ui->horizontalSlider_Light->setValue(arg1);
}

