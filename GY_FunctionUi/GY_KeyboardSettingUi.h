#ifndef GY_KEYBOARDSETTINGUI_H
#define GY_KEYBOARDSETTINGUI_H

#include <QWidget>

namespace Ui {
class GY_KeyboardSettingUi;
}

class GY_KeyboardSettingUi : public QWidget
{
    Q_OBJECT

public:
    explicit GY_KeyboardSettingUi(QWidget *parent = nullptr);
    ~GY_KeyboardSettingUi();
signals:
    void signalKeyboardSettingClearKey();               //清空键盘按键操作
    void signalKeyboardSettingDrawSize(double size);    //调整绘制键盘大小
    void signalKeyboardSettingHook(bool isHook);        //键盘钩子功能-是否开启
    void signalKeyboardSettingKeyCheck(bool isCheck);   //按键检测功能-是否开启

private slots:
    void on_comboBox_KeyboardType_currentIndexChanged(int index);   //键盘类型调整
    void on_pushButton_ClearKeyboard_clicked();                     //清空键盘按键操作
    void on_horizontalSlider_Size_sliderMoved(int position);        //调整绘制键盘大小 - 滑块
    void on_doubleSpinBox_Size_valueChanged(double arg1);           //调整绘制键盘大小
    void on_checkBox_Hook_stateChanged(int arg1);                   //键盘钩子功能-是否开启
    void on_checkBox_KeyCheck_stateChanged(int arg1);               //按键检测功能-是否开启
    void on_horizontalSlider_Light_sliderMoved(int position);       //键盘灯光调整
    void on_spinBox_Light_valueChanged(int arg1);                   //键盘灯光调整

private:
    Ui::GY_KeyboardSettingUi *ui;
};

#endif // GY_KEYBOARDSETTINGUI_H
