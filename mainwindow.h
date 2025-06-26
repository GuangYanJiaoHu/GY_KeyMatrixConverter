#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include <GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.h>
#include <GY_FunctionUi/GY_KeyboardSettingUi.h>
#include <GY_FunctionUi/GY_AnimationSettingUi.h>
#include <GY_FunctionUi/GY_GenerateBinFile.h>
#include <GY_FunctionUi/GY_ConvertBinFile.h>
#include <GY_FunctionUi/GY_AnimationCustomize.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    GY_KeyboardDrawLayout *keyboardDrawLayout; //键盘绘制
    GY_KeyboardSettingUi  *keyboardSettingUi;  //键盘设置
    GY_AnimationSettingUi *animationSettingUi; //动画设置
    GY_GenerateBinFile    *generateBinFile;    //bin文件生成
    GY_ConvertBinFile     *convertBinFile;     //bin文件转换
    GY_AnimationCustomize *animationCustomize; //自定义动画
};
#endif // MAINWINDOW_H
