#ifndef GY_GENERATEBINFILE_H
#define GY_GENERATEBINFILE_H

#include <QWidget>
#include <GY_Tools/GY_KeyboardTools.h>
#include <QMessageBox>
#include <GY_FunctionUi/GY_Generate/GY_ReadFile.h>
#include <QSettings>
namespace Ui {
class GY_GenerateBinFile;
}

class GY_GenerateBinFile : public QWidget
{
    Q_OBJECT

public:
    explicit GY_GenerateBinFile(QWidget *parent = nullptr);
    ~GY_GenerateBinFile();

private:
    QByteArray getAxisInfo();                       //获取每个键轴的信息

private slots:
    void on_pushButton_keyMaxorMinValue_clicked();
    void on_pushButton_clicked();                    //开机动画读取
    void on_pushButton_Static_clicked();             //静态动画读取
    void on_pushButton_Dynamic_clicked();            //动态动画读取
    void on_pushButton_Deep_clicked();               //深度动画读取
    void on_pushButton_Export_clicked();             //数据导出-bin文件导出-配置导出
    void on_pushButton_ReadJson_clicked();           //json文件读取并判断不能大于5条数据
    void on_comboBox_ShaftType_activated(int index); //键轴类型切换联动键轴信息
    void on_listWidget_ReadJson_currentTextChanged(const QString &currentText); //获取选中得json信息
    void on_pushButton_ReadIni_clicked();            //导入INI配置文件
    void on_pushButton_ExportIni_clicked();          //导出INI配置文件

private:
    Ui::GY_GenerateBinFile *ui;

};

#endif // GY_GENERATEBINFILE_H
