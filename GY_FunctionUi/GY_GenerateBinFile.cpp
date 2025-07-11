#include "GY_GenerateBinFile.h"
#include "ui_GY_GenerateBinFile.h"

GY_GenerateBinFile::GY_GenerateBinFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_GenerateBinFile)
{
    ui->setupUi(this);

    //设置动态动画排序 - listwiget可拖动
    ui->listWidget_Deep->setDragEnabled(true);
    ui->listWidget_Deep->setAcceptDrops(true);
    ui->listWidget_Deep->setDropIndicatorShown(true);
    ui->listWidget_Deep->setDefaultDropAction(Qt::MoveAction);

    ui->listWidget_Static->setDragEnabled(true);
    ui->listWidget_Static->setAcceptDrops(true);
    ui->listWidget_Static->setDropIndicatorShown(true);
    ui->listWidget_Static->setDefaultDropAction(Qt::MoveAction);

    ui->listWidget_Dynamic->setDragEnabled(true);
    ui->listWidget_Dynamic->setAcceptDrops(true);
    ui->listWidget_Dynamic->setDropIndicatorShown(true);
    ui->listWidget_Dynamic->setDefaultDropAction(Qt::MoveAction);

    ui->listWidget_ReadJson->setDragEnabled(true);
    ui->listWidget_ReadJson->setAcceptDrops(true);
    ui->listWidget_ReadJson->setDropIndicatorShown(true);
    ui->listWidget_ReadJson->setDefaultDropAction(Qt::MoveAction);
}

GY_GenerateBinFile::~GY_GenerateBinFile()
{
    delete ui;
}


//确认按键默认值
void GY_GenerateBinFile::on_pushButton_keyMaxorMinValue_clicked()
{

}
//开机动画读取
void GY_GenerateBinFile::on_pushButton_clicked()
{
    ui->lineEdit_TurnOn->clear();
    QString filePath = QFileDialog::getOpenFileName(this,tr("选择开机动画文件"),"./",tr("sta file(*.sta)"));
    if(filePath.isEmpty()){
        return ;
    }
    ui->lineEdit_TurnOn->setText(filePath);
}
//静态动画读取
void GY_GenerateBinFile::on_pushButton_Static_clicked()
{
    ui->listWidget_Static->clear();
    QStringList filePathList = QFileDialog::getOpenFileNames(this,tr("选择静态动画文件"),"./",tr("sta file(*.sta)"));
    if(filePathList.isEmpty()){
        return ;
    }
    foreach (auto filePath, filePathList){   //遍历只加载.txt到文件列表
        ui->listWidget_Static->addItem(new QListWidgetItem(filePath));
    }
}
//动态动画读取
void GY_GenerateBinFile::on_pushButton_Dynamic_clicked()
{
    ui->listWidget_Dynamic->clear();
    QStringList filePathList = QFileDialog::getOpenFileNames(this,tr("选择动态动画文件"),"./",tr("dya file(*.dya)"));
    if(filePathList.isEmpty()){
        return ;
    }
    foreach (auto filePath, filePathList){   //遍历只加载.txt到文件列表
        ui->listWidget_Dynamic->addItem(new QListWidgetItem(filePath));
    }
}
//深度动画读取
void GY_GenerateBinFile::on_pushButton_Deep_clicked()
{
    ui->listWidget_Deep->clear();
    QStringList filePathList = QFileDialog::getOpenFileNames(this,tr("选择深度动画文件"),"./",tr("sta file(*.dya)"));
    if(filePathList.isEmpty()){
        return ;
    }
    foreach (auto filePath, filePathList){   //遍历只加载.txt到文件列表
        ui->listWidget_Deep->addItem(new QListWidgetItem(filePath));
    }
}
//数据导出-bin文件导出-配置导出
void GY_GenerateBinFile::on_pushButton_Export_clicked()
{
    GY_ReadFile::JsonPublicInfo jsonPublicInfo;
    //判断导出键盘类型
    switch(ui->comboBox_keyboardType->currentIndex()){
    case 0:
        QMessageBox::critical(this,"错误提示","请选择键盘类型");
        break;
    case 1:
        jsonPublicInfo._KeyBoardCount = 70;
        jsonPublicInfo._KeyboardType = GY_KeyboardTools::KeyboardType::_Keyboard_60_CN_;
        break;
    default: break;
    }



    //=================================================== 对动画文件进行导出生成 静态，动画，深度，开机 ==================================================================
    for(int i = 0; i < ui->listWidget_Static->count() ; i++){    jsonPublicInfo._AnimationStatic  += GY_KeyboardTools::getAnimationStatic ( ui->listWidget_Static->item(i)->text());  }
    for(int i = 0; i < ui->listWidget_Dynamic->count(); i++){    jsonPublicInfo._AnimationDynamic += GY_KeyboardTools::getAnimationDynamic( ui->listWidget_Dynamic->item(i)->text()); }
    for(int i = 0; i < ui->listWidget_Deep->count()   ; i++){    jsonPublicInfo._AnimationDeep    += GY_KeyboardTools::getAnimationDynamic( ui->listWidget_Deep->item(i)->text());    }
    jsonPublicInfo._AnimationTurnOn = GY_KeyboardTools::getAnimationStatic(ui->lineEdit_TurnOn->text());


    //=====================================公有文件，最大值，最小值，白平衡，键轴表，键轴信息，多组预设，回报率 全信息，组好的内容===============================================
    for(int i = 0; i < jsonPublicInfo._KeyBoardCount; i++){
        jsonPublicInfo._Max  += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_keyMax->text().toDouble());    //最大值
        jsonPublicInfo._Min  += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_keyMin->text().toDouble());    //最小值
        jsonPublicInfo._Shaft+= QByteArray::fromHex(QString("%1").arg(ui->comboBox_keyboardType->currentIndex(), 2, 16, QLatin1Char('0')).toUtf8());
    }
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0));
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(1.0)); //空位补0
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_R->text().toInt() / double(255.0)));
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_G->text().toInt() / double(255.0)));
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_B->text().toInt() / double(255.0)));
    jsonPublicInfo._RETURN_SPEED = QByteArray::fromHex(QString("%1").arg(ui->spinBox_returnSpeed->text().toInt(), 2, 16, QLatin1Char('0')).toUtf8());//回报率
    jsonPublicInfo._MULTIPLE_SET = QByteArray::fromHex("01");
    jsonPublicInfo._ShaftInfo = this->getAxisInfo();

    //======================================私有文件，拼接数据=======================================================================================================================
    GY_ReadFile readJson;   //创建读写
    QList<GY_KeyboardTools::JsonPrivateInfo> jsonPrivateInfo;
    for(int i = 0; i < ui->listWidget_ReadJson->count(); i++){
        jsonPrivateInfo.append(readJson.getJsonPrivateInfo(ui->listWidget_ReadJson->item(i)->text()));
    }

}

QByteArray GY_GenerateBinFile::getAxisInfo()
{
    QByteArray axisInfo;
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxDefault->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxTop->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxBtm->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minDefault->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minTop->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minBtm->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtUpDft->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtDnDft->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtTop->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtBtm->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhDnDft->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhTop->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhBtm->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientA->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientB->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientC->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientD->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneUp->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneDown->text().toDouble());

    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxDefault_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxTop_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxBtm_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minDefault_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minTop_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minBtm_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtUpDft_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtDnDft_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtTop_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtBtm_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhDnDft_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhTop_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhBtm_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientA_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientB_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientC_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientD_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneUp_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneDown_2->text().toDouble());

    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxDefault_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxTop_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxBtm_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minDefault_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minTop_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minBtm_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtUpDft_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtDnDft_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtTop_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtBtm_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhDnDft_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhTop_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhBtm_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientA_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientB_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientC_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientD_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneUp_2->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneDown_2->text().toDouble());

    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxDefault_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxTop_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxBtm_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minDefault_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minTop_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minBtm_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtUpDft_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtDnDft_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtTop_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtBtm_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhDnDft_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhTop_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhBtm_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientA_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientB_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientC_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientD_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneUp_3->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneDown_3->text().toDouble());

    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxDefault_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxTop_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_maxBtm_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minDefault_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minTop_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_minBtm_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtUpDft_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtDnDft_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtTop_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_rtBtm_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhDnDft_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhTop_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_fhBtm_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientA_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientB_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientC_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_acoefficientD_5->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneUp_4->text().toDouble());
    axisInfo += GY_KeyboardTools::getFlotaToByteArray(ui->doubleSpinBox_deadZoneDown_4->text().toDouble());
    return axisInfo;
}


//json文件读取并判断不能大于5条数据
void GY_GenerateBinFile::on_pushButton_ReadJson_clicked()
{
    ui->listWidget_ReadJson->clear();
    QStringList filePathList = QFileDialog::getOpenFileNames(this,tr("选择需要导入的Json文件"),"./",tr("json file(*.json)"));
    if(filePathList.isEmpty()){
        return ;
    }
    if(filePathList.count() > 5){
        QMessageBox::critical(this, "错误信息提示", "json文件不能超过5个文件");
        return ;
    }
    foreach (auto filePath, filePathList){                  			//遍历只加载.txt到文件列表
        ui->listWidget_ReadJson->addItem(new QListWidgetItem(filePath));
    }
}

