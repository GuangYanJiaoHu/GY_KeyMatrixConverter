#include "GY_AnimationSettingUi.h"
#include "ui_GY_AnimationSettingUi.h"

GY_AnimationSettingUi::GY_AnimationSettingUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_AnimationSettingUi)
{
    ui->setupUi(this);
    ui->pushButton_StaticStart->setCheckable(true);             //开启静态动画模拟 - 按钮T/F状态
    ui->pushButton_DynamicStart->setCheckable(true);            //开启动态动画模拟 - 按钮T/F状态
    ui->pushButton_DynamicUpdateSimulatePos->setCheckable(true);//开启动态动画模拟位置更改 - 按钮T/F状态
}

GY_AnimationSettingUi::~GY_AnimationSettingUi()
{
    delete ui;
}


//---------------------------------------------静态动画-------------------------------------------------------------------
//静态动画读取地址
void GY_AnimationSettingUi::on_pushButton_StaticReadPath_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(NULL, "Open Folder", "../");
    if(filePath.isEmpty()){
        return ;
    }
    listStaticPicturePath.clear();
    ui->lineEdit_StaticReadPath->setText(filePath);
    QDir Dir(filePath);                              			//查看工作路径是否存在
    Dir.setFilter(QDir::Files);                     			//设置过滤器只查看文件
    listStaticPicturePath = Dir.entryList(QDir::Files);  			//获取所有文件
    foreach (auto file, listStaticPicturePath){                  			//遍历只加载.txt到文件列表
        ui->comboBox_StaticOnlySimulate->addItem(file);
    }
}

//静态动画开始模拟
void GY_AnimationSettingUi::on_pushButton_StaticStart_clicked()
{
    if(!ui->pushButton_StaticStart->isChecked()){      //默认状态
        ui->pushButton_StaticStart->setText("开始模拟");
        emit signalAnimationStaticSimulate(ui->lineEdit_StaticReadPath->text() + "/", listStaticPicturePath, false); //界面停止模拟装状态
    }else{                                              //点击后状态，显示停止模拟
        ui->pushButton_StaticStart->setText("停止模拟");
        emit signalAnimationStaticSimulate(ui->lineEdit_StaticReadPath->text() + "/", listStaticPicturePath, true);  //界面开始模拟状态
    }
}

//静态动画逐帧模拟
void GY_AnimationSettingUi::on_comboBox_StaticOnlySimulate_currentIndexChanged(int index)
{
    if(listStaticPicturePath.isEmpty()){
        return ;
    }
    emit signalAnimationStaticOnlySimulate(ui->lineEdit_StaticReadPath->text() + "/", listStaticPicturePath.at(index));
}


//---------------------------------------------动态动画-------------------------------------------------------------------
//动态动画读取地址
void GY_AnimationSettingUi::on_pushButton_DynamicReadPath_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(NULL, "Open Folder", "../");
    if(filePath.isEmpty()){
        return ;
    }
    listDynamicPicturePath.clear();
    ui->lineEdit_DynamicReadPath->setText(filePath);
    QDir Dir(filePath);                              			//查看工作路径是否存在
    Dir.setFilter(QDir::Files);                     			//设置过滤器只查看文件
    listDynamicPicturePath = Dir.entryList(QDir::Files);  		//获取所有文件
    foreach (auto file, listDynamicPicturePath){                //遍历只加载.txt到文件列表
        ui->comboBox_DynamicOnlySimulate->addItem(file);
    }
}

//动态动画开始模拟
void GY_AnimationSettingUi::on_pushButton_DynamicStart_clicked()
{
    if(!ui->pushButton_DynamicStart->isChecked()){      //默认状态
        ui->pushButton_DynamicStart->setText("开始模拟");
        emit signalAnimationDynamicSimulate(ui->lineEdit_DynamicReadPath->text() + "/", listDynamicPicturePath, false); //界面停止模拟装状态
    }else{                                              //点击后状态，显示停止模拟
        ui->pushButton_DynamicStart->setText("停止模拟");
        emit signalAnimationDynamicSimulate(ui->lineEdit_DynamicReadPath->text() + "/", listDynamicPicturePath, true);  //界面开始模拟状态
    }
}



//动态动画逐帧模拟
void GY_AnimationSettingUi::on_comboBox_DynamicOnlySimulate_currentIndexChanged(int index)
{
    if(listDynamicPicturePath.isEmpty()){
        return ;
    }
    emit signalAnimationDynamicOnlySimulate(ui->lineEdit_DynamicReadPath->text() + "/", listDynamicPicturePath.at(index));
}

//静态动画界面速度模拟 - 抬手发送
void GY_AnimationSettingUi::on_horizontalSlider_StaticUi_sliderReleased()
{
    //信号对接

    emit signalAnimationStaticUiSimulateSpeed(ui->horizontalSlider_StaticUi->value());
}

//静态动画键盘下发速度模拟 - 抬手发送
void GY_AnimationSettingUi::on_horizontalSlider_StaticSend_sliderReleased()
{
    //信号对接
    emit signalAnimationStaticSendSimulateSpeed(ui->horizontalSlider_StaticSend->value());
}

//静态动画界面速度模拟 - 给控件显示专用
void GY_AnimationSettingUi::on_horizontalSlider_StaticUi_valueChanged(int value)
{
    ui->label_StaticUiMs->setText(QString("%1ms").arg(value));
}

//静态动画键盘下发速度模拟 - 给控件显示专用
void GY_AnimationSettingUi::on_horizontalSlider_StaticSend_valueChanged(int value)
{
    ui->label_StaticSendMs->setText(QString("%1ms").arg(value));
}

//动态动画界面速度模拟 - 抬手发送
void GY_AnimationSettingUi::on_horizontalSlider_DynamicUi_sliderReleased()
{
    emit signalAnimationDynamicUiSimulateSpeed(ui->horizontalSlider_DynamicUi->value());
}

//动态动画键盘下发速度模拟 - 抬手发送
void GY_AnimationSettingUi::on_horizontalSlider_DynamicSend_sliderReleased()
{

    emit signalAnimationDynamicSendSimulateSpeed(ui->horizontalSlider_DynamicSend->value());
}

//动态动画界面速度模拟 - 给控件显示专用
void GY_AnimationSettingUi::on_horizontalSlider_DynamicUi_valueChanged(int value)
{
    ui->label_DynamicUiMs->setText(QString("%1ms").arg(value));
}

//动态动画键盘下发速度模拟 - 给控件显示专用
void GY_AnimationSettingUi::on_horizontalSlider_DynamicSend_valueChanged(int value)
{
    ui->label_DynamicSendMs->setText(QString("%1ms").arg(value));
}

//更改动态动画模拟按键位置
void GY_AnimationSettingUi::on_pushButton_DynamicUpdateSimulatePos_clicked()
{
    if(!ui->pushButton_DynamicUpdateSimulatePos->isChecked()){      //默认状态
        ui->pushButton_DynamicUpdateSimulatePos->setText("更新模拟位置");
        //emit signalAnimationDynamicUpdateSimulatePos(); //界面停止模拟装状态
    }else{                                              //点击后状态，显示停止模拟
        ui->pushButton_DynamicUpdateSimulatePos->setText("选择模拟按键位置");
        emit signalAnimationDynamicUpdateSimulatePos();  //界面开始模拟状态
    }
}
//修改模拟位置完成 - 更新按钮状态
void GY_AnimationSettingUi::slotKeyboardDrawLayoutUpdateSimulatePos()
{
    ui->pushButton_DynamicUpdateSimulatePos->setChecked(false);
    ui->pushButton_DynamicUpdateSimulatePos->setText("更新模拟位置");
    qDebug() << "按键状态：" << ui->pushButton_DynamicUpdateSimulatePos->isChecked();
}
//静态动画导出
void GY_AnimationSettingUi::on_pushButton_StaticExport_clicked()
{
    if(ui->lineEdit_StaticReadPath->text().isEmpty()){
        //无导出内容
        return;
    }
    QStringList path;
    foreach(auto item, listStaticPicturePath){
        path.append(ui->lineEdit_StaticReadPath->text() + "/" + item);
    }
    emit signalAnimationStaticExport(path);
}

//静态动画导出
void GY_AnimationSettingUi::on_pushButton_DynamicExport_clicked()
{
    if(ui->lineEdit_DynamicReadPath->text().isEmpty()){
        return;
    }
    QStringList path;
    foreach(auto item, listDynamicPicturePath){
        path.append(ui->lineEdit_DynamicReadPath->text() + "/" + item);
    }
    emit signalAnimationDynamicExport(path);
}

