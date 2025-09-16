#include "GY_GenerateBinFile.h"
#include "ui_GY_GenerateBinFile.h"

GY_GenerateBinFile::GY_GenerateBinFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_GenerateBinFile)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);

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
        return;
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
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(0.0) + GY_KeyboardTools::getFlotaToByteArray(0.0)); // 上死区 下死区
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_R->text().toInt() / double(255.0)));
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_G->text().toInt() / double(255.0)));
    jsonPublicInfo._WhiteBalance.append(GY_KeyboardTools::getFlotaToByteArray(ui->spinBox_whiteBalance_B->text().toInt() / double(255.0)));
    jsonPublicInfo._WhiteBalance.append(QByteArray::fromHex(ui->checkBox_shiShiJiaoZhun->isChecked() == 1? "01" : "02")); //实时校准 01 开 02关
    jsonPublicInfo._WhiteBalance.append(QByteArray::fromHex(QString("%1").arg(ui->spinBox_dengWei->text().toInt(), 2, 16, QLatin1Char('0')).toUtf8())); //上下灯位 01上 02下 03上下 04关闭
    jsonPublicInfo._WhiteBalance.append(QByteArray::fromHex(QString("%1").arg(ui->spinBox_LiangDu->text().toInt(), 2, 16, QLatin1Char('0')).toUtf8())); //亮度 01 开 02关

    jsonPublicInfo._RETURN_SPEED = QByteArray::fromHex(ui->checkBox_returnSpeed->isChecked() == 1? "01" : "02");    //回报率
    jsonPublicInfo._MULTIPLE_SET = QByteArray::fromHex("01");
    jsonPublicInfo._ShaftInfo = this->getAxisInfo();

    //======================================私有文件，拼接数据=======================================================================================================================
    GY_ReadFile readJson;   //创建读写
    QList<GY_KeyboardTools::JsonPrivateInfo> jsonPrivateInfo;
    for(int i = 0; i < ui->listWidget_ReadJson->count(); i++){
        jsonPrivateInfo.append(readJson.getJsonPrivateInfo(ui->listWidget_ReadJson->item(i)->text()));
    }

    QByteArray oldBinFileData; //读取一个空的bin文件
    QFile fileReadNullBin(QFileDialog::getOpenFileName(this,tr("读取空的bin文件"), "./", tr("bin file(*.bin)")));
    if(!fileReadNullBin.exists()){
        return ;
    }
    if(fileReadNullBin.open(QFileDevice::ReadOnly)){
        oldBinFileData += fileReadNullBin.readAll();
    }
    qDebug() << "读取bin字节数：" << oldBinFileData.size() << "前10个字节" << oldBinFileData.toHex().mid(9 * 4096, 16);
    fileReadNullBin.close();


    QByteArray binFile = readJson.getExprotBinFile(jsonPublicInfo, jsonPrivateInfo, oldBinFileData);
    QFile writeBinFileData(QFileDialog::getSaveFileName(this,tr("保存bin文件"),"./",tr("bin file(*.bin)")));
    if(writeBinFileData.open(QFileDevice::WriteOnly)){
        writeBinFileData.write(binFile);
    }else{
        QMessageBox::critical(this,"错误提示","写入失败");
        return;
    }
    writeBinFileData.close();

    QMessageBox::information(this,"写入提示","写入完成");
}
//获取每个键轴的信息
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

//键轴类型切换联动键轴信息
void GY_GenerateBinFile::on_comboBox_ShaftType_activated(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

//获取选中得json信息
void GY_GenerateBinFile::on_listWidget_ReadJson_currentTextChanged(const QString &currentText)
{
    GY_ReadFile readJson;   //创建读写
    GY_KeyboardTools::JsonPrivateInfo jsonPrivateInfo = readJson.getJsonPrivateInfo(currentText);
    //确认画布尺寸大小 _ (279，91)
    QMap<int, GY_KeyboardTools::KeyboardButtonInfo> mapKeyboardInfo = GY_KeyboardTools::getKeyboarLayout_60_CN();
    // 创建一个279x91像素的图像，使用ARGB32格式
    QImage image(279, 91, QImage::Format_ARGB32);
    // 填充白色背景
    image.fill(Qt::white);
    // 创建绘图工具
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);
    for(int i = 0; i < 70; i++){
        if(mapKeyboardInfo.contains(i)){
            //将当前颜色保存
            QColor color;
            QString colorLight =jsonPrivateInfo._JsonPrivateOnlyKeyInfo.at(i)._LightColor.toHex();
            color.setNamedColor("#" + colorLight);
            qDebug() << "转化颜色：" << color << " 未转化颜色：" << colorLight;
            // 设置画笔和画刷
            painter.setPen(Qt::NoPen);
            painter.setBrush(color);
            painter.drawRect(mapKeyboardInfo.find(i).value()._Keyborders);
        }
    }
    painter.end();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

//INI配置文件读取
void GY_GenerateBinFile::on_pushButton_ReadIni_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("选择需要导入的ini文件(键轴信息配置文件)"),"./",tr("ini file(*.ini)"));
    if(filePath.isEmpty()){
        return ;
    }

    QSettings settings(filePath, QSettings::IniFormat);
    settings.beginGroup("Key_Shaft_A");
    ui->doubleSpinBox_maxTop->setValue(       settings.value("A_MAX_Up").toDouble()        ); //最大上限值
    ui->doubleSpinBox_maxDefault->setValue(   settings.value("A_MAX_Defalut").toDouble()   ); //最大默认值
    ui->doubleSpinBox_maxBtm->setValue(       settings.value("A_MAX_Down").toDouble()      ); //最大下限值
    ui->doubleSpinBox_minTop->setValue(       settings.value("A_MIN_Up").toDouble()        ); //最小上限值
    ui->doubleSpinBox_minDefault->setValue(   settings.value("A_MAX_Default").toDouble()   ); //最小默认值
    ui->doubleSpinBox_minBtm->setValue(       settings.value("A_MIN_Down" ).toDouble()     ); //最小下限值
    ui->doubleSpinBox_deadZoneUp->setValue(   settings.value("A_DeadZoonUp").toDouble()    ); //上死区
    ui->doubleSpinBox_deadZoneDown->setValue( settings.value("A_DeadZoonDown").toDouble()  ); //下死区
    ui->doubleSpinBox_acoefficientA->setValue(settings.value("A_AcoefficientA").toDouble() ); //系数A
    ui->doubleSpinBox_acoefficientB->setValue(settings.value("A_AcoefficientB").toDouble() ); //系数B
    ui->doubleSpinBox_acoefficientC->setValue(settings.value("A_AcoefficientC").toDouble() ); //系数C
    ui->doubleSpinBox_acoefficientD->setValue(settings.value("A_AcoefficientD").toDouble() ); //系数D
    ui->doubleSpinBox_fhTop->setValue(        settings.value("A_RT_FH_Up").toDouble()      ); //RT定高上限
    ui->doubleSpinBox_fhDnDft->setValue(      settings.value("A_RT_FH_Default").toDouble() ); //RT定高默认
    ui->doubleSpinBox_fhBtm->setValue(        settings.value("A_RT_FH_Down").toDouble()    ); //RT定高下限
    ui->doubleSpinBox_rtTop->setValue(        settings.value("A_RT_Up").toDouble()         ); //RT上限值
    ui->doubleSpinBox_rtBtm->setValue(        settings.value("A_RT_Down").toDouble()       ); //RT下限值
    ui->doubleSpinBox_rtDnDft->setValue(      settings.value("A_RT_Click").toDouble()      ); //RT触发值
    ui->doubleSpinBox_rtUpDft->setValue(      settings.value("A_RT_Release").toDouble()    ); //RT抬起值
    settings.endGroup();

    settings.beginGroup("Key_Shaft_B");
    ui->doubleSpinBox_maxTop_2->setValue(       settings.value("B_MAX_Up").toDouble()        ); //最大上限值
    ui->doubleSpinBox_maxDefault_2->setValue(   settings.value("B_MAX_Defalut").toDouble()   ); //最大默认值
    ui->doubleSpinBox_maxBtm_2->setValue(       settings.value("B_MAX_Down").toDouble()      ); //最大下限值
    ui->doubleSpinBox_minTop_2->setValue(       settings.value("B_MIN_Up").toDouble()        ); //最小上限值
    ui->doubleSpinBox_minDefault_2->setValue(   settings.value("B_MAX_Default").toDouble()   ); //最小默认值
    ui->doubleSpinBox_minBtm_2->setValue(       settings.value("B_MIN_Down" ).toDouble()     ); //最小下限值
    ui->doubleSpinBox_deadZoneUp_2->setValue(   settings.value("B_DeadZoonUp").toDouble()    ); //上死区
    ui->doubleSpinBox_deadZoneDown_2->setValue( settings.value("B_DeadZoonDown").toDouble()  ); //下死区
    ui->doubleSpinBox_acoefficientA_2->setValue(settings.value("B_AcoefficientA").toDouble() ); //系数A
    ui->doubleSpinBox_acoefficientB_2->setValue(settings.value("B_AcoefficientB").toDouble() ); //系数B
    ui->doubleSpinBox_acoefficientC_2->setValue(settings.value("B_AcoefficientC").toDouble() ); //系数C
    ui->doubleSpinBox_acoefficientD_2->setValue(settings.value("B_AcoefficientD").toDouble() ); //系数D
    ui->doubleSpinBox_fhTop_2->setValue(        settings.value("B_RT_FH_Up").toDouble()      ); //RT定高上限
    ui->doubleSpinBox_fhDnDft_2->setValue(      settings.value("B_RT_FH_Default").toDouble() ); //RT定高默认
    ui->doubleSpinBox_fhBtm_2->setValue(        settings.value("B_RT_FH_Down").toDouble()    ); //RT定高下限
    ui->doubleSpinBox_rtTop_2->setValue(        settings.value("B_RT_Up").toDouble()         ); //RT上限值
    ui->doubleSpinBox_rtBtm_2->setValue(        settings.value("B_RT_Down").toDouble()       ); //RT下限值
    ui->doubleSpinBox_rtDnDft_2->setValue(      settings.value("B_RT_Click").toDouble()      ); //RT触发值
    ui->doubleSpinBox_rtUpDft_2->setValue(      settings.value("B_RT_Release").toDouble()    ); //RT抬起值
    settings.endGroup();

    settings.beginGroup("Key_Shaft_C");
    ui->doubleSpinBox_maxTop_3->setValue(       settings.value("C_MAX_Up").toDouble()        ); //最大上限值
    ui->doubleSpinBox_maxDefault_3->setValue(   settings.value("C_MAX_Defalut").toDouble()   ); //最大默认值
    ui->doubleSpinBox_maxBtm_3->setValue(       settings.value("C_MAX_Down").toDouble()      ); //最大下限值
    ui->doubleSpinBox_minTop_3->setValue(       settings.value("C_MIN_Up").toDouble()        ); //最小上限值
    ui->doubleSpinBox_minDefault_3->setValue(   settings.value("C_MAX_Default").toDouble()   ); //最小默认值
    ui->doubleSpinBox_minBtm_3->setValue(       settings.value("C_MIN_Down" ).toDouble()     ); //最小下限值
    ui->doubleSpinBox_deadZoneUp_3->setValue(   settings.value("C_DeadZoonUp").toDouble()    ); //上死区
    ui->doubleSpinBox_deadZoneDown_3->setValue( settings.value("C_DeadZoonDown").toDouble()  ); //下死区
    ui->doubleSpinBox_acoefficientA_3->setValue(settings.value("C_AcoefficientA").toDouble() ); //系数A
    ui->doubleSpinBox_acoefficientB_3->setValue(settings.value("C_AcoefficientB").toDouble() ); //系数B
    ui->doubleSpinBox_acoefficientC_3->setValue(settings.value("C_AcoefficientC").toDouble() ); //系数C
    ui->doubleSpinBox_acoefficientD_3->setValue(settings.value("C_AcoefficientD").toDouble() ); //系数D
    ui->doubleSpinBox_fhTop_3->setValue(        settings.value("C_RT_FH_Up").toDouble()      ); //RT定高上限
    ui->doubleSpinBox_fhDnDft_3->setValue(      settings.value("C_RT_FH_Default").toDouble() ); //RT定高默认
    ui->doubleSpinBox_fhBtm_3->setValue(        settings.value("C_RT_FH_Down").toDouble()    ); //RT定高下限
    ui->doubleSpinBox_rtTop_3->setValue(        settings.value("C_RT_Up").toDouble()         ); //RT上限值
    ui->doubleSpinBox_rtBtm_3->setValue(        settings.value("C_RT_Down").toDouble()       ); //RT下限值
    ui->doubleSpinBox_rtDnDft_3->setValue(      settings.value("C_RT_Click").toDouble()      ); //RT触发值
    ui->doubleSpinBox_rtUpDft_3->setValue(      settings.value("C_RT_Release").toDouble()    ); //RT抬起值
    settings.endGroup();

    settings.beginGroup("Key_Shaft_D");
    ui->doubleSpinBox_maxTop_4->setValue(       settings.value("D_MAX_Up").toDouble()        ); //最大上限值
    ui->doubleSpinBox_maxDefault_4->setValue(   settings.value("D_MAX_Defalut").toDouble()   ); //最大默认值
    ui->doubleSpinBox_maxBtm_4->setValue(       settings.value("D_MAX_Down").toDouble()      ); //最大下限值
    ui->doubleSpinBox_minTop_4->setValue(       settings.value("D_MIN_Up").toDouble()        ); //最小上限值
    ui->doubleSpinBox_minDefault_4->setValue(   settings.value("D_MAX_Default").toDouble()   ); //最小默认值
    ui->doubleSpinBox_minBtm_4->setValue(       settings.value("D_MIN_Down" ).toDouble()     ); //最小下限值
    ui->doubleSpinBox_deadZoneUp_4->setValue(   settings.value("D_DeadZoonUp").toDouble()    ); //上死区
    ui->doubleSpinBox_deadZoneDown_4->setValue( settings.value("D_DeadZoonDown").toDouble()  ); //下死区
    ui->doubleSpinBox_acoefficientA_4->setValue(settings.value("D_AcoefficientA").toDouble() ); //系数A
    ui->doubleSpinBox_acoefficientB_4->setValue(settings.value("D_AcoefficientB").toDouble() ); //系数B
    ui->doubleSpinBox_acoefficientC_4->setValue(settings.value("D_AcoefficientC").toDouble() ); //系数C
    ui->doubleSpinBox_acoefficientD_4->setValue(settings.value("D_AcoefficientD").toDouble() ); //系数D
    ui->doubleSpinBox_fhTop_4->setValue(        settings.value("D_RT_FH_Up").toDouble()      ); //RT定高上限
    ui->doubleSpinBox_fhDnDft_4->setValue(      settings.value("D_RT_FH_Default").toDouble() ); //RT定高默认
    ui->doubleSpinBox_fhBtm_4->setValue(        settings.value("D_RT_FH_Down").toDouble()    ); //RT定高下限
    ui->doubleSpinBox_rtTop_4->setValue(        settings.value("D_RT_Up").toDouble()         ); //RT上限值
    ui->doubleSpinBox_rtBtm_4->setValue(        settings.value("D_RT_Down").toDouble()       ); //RT下限值
    ui->doubleSpinBox_rtDnDft_4->setValue(      settings.value("D_RT_Click").toDouble()      ); //RT触发值
    ui->doubleSpinBox_rtUpDft_4->setValue(      settings.value("D_RT_Release").toDouble()    ); //RT抬起值
    settings.endGroup();

    settings.beginGroup("Key_Shaft_E");
    ui->doubleSpinBox_maxTop_5->setValue(       settings.value("E_MAX_Up").toDouble()        ); //最大上限值
    ui->doubleSpinBox_maxDefault_5->setValue(   settings.value("E_MAX_Defalut").toDouble()   ); //最大默认值
    ui->doubleSpinBox_maxBtm_5->setValue(       settings.value("E_MAX_Down").toDouble()      ); //最大下限值
    ui->doubleSpinBox_minTop_5->setValue(       settings.value("E_MIN_Up").toDouble()        ); //最小上限值
    ui->doubleSpinBox_minDefault_5->setValue(   settings.value("E_MAX_Default").toDouble()   ); //最小默认值
    ui->doubleSpinBox_minBtm_5->setValue(       settings.value("E_MIN_Down" ).toDouble()     ); //最小下限值
    ui->doubleSpinBox_deadZoneUp_5->setValue(   settings.value("E_DeadZoonUp").toDouble()    ); //上死区
    ui->doubleSpinBox_deadZoneDown_5->setValue( settings.value("E_DeadZoonDown").toDouble()  ); //下死区
    ui->doubleSpinBox_acoefficientA_5->setValue(settings.value("E_AcoefficientA").toDouble() ); //系数A
    ui->doubleSpinBox_acoefficientB_5->setValue(settings.value("E_AcoefficientB").toDouble() ); //系数B
    ui->doubleSpinBox_acoefficientC_5->setValue(settings.value("E_AcoefficientC").toDouble() ); //系数C
    ui->doubleSpinBox_acoefficientD_5->setValue(settings.value("E_AcoefficientD").toDouble() ); //系数D
    ui->doubleSpinBox_fhTop_5->setValue(        settings.value("E_RT_FH_Up").toDouble()      ); //RT定高上限
    ui->doubleSpinBox_fhDnDft_5->setValue(      settings.value("E_RT_FH_Default").toDouble() ); //RT定高默认
    ui->doubleSpinBox_fhBtm_5->setValue(        settings.value("E_RT_FH_Down").toDouble()    ); //RT定高下限
    ui->doubleSpinBox_rtTop_5->setValue(        settings.value("E_RT_Up").toDouble()         ); //RT上限值
    ui->doubleSpinBox_rtBtm_5->setValue(        settings.value("E_RT_Down").toDouble()       ); //RT下限值
    ui->doubleSpinBox_rtDnDft_5->setValue(      settings.value("E_RT_Click").toDouble()      ); //RT触发值
    ui->doubleSpinBox_rtUpDft_5->setValue(      settings.value("E_RT_Release").toDouble()    ); //RT抬起值
    settings.endGroup();
    qDebug() << "配置文件导入完成";
}

//导出INI配置文件
void GY_GenerateBinFile::on_pushButton_ExportIni_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this,tr("选择需要导出的ini文件地址(键轴信息配置文件)"),"./配置文件(键轴信息).ini",tr("ini file(*.ini)"));
    if(filePath.isEmpty()){
        return ;
    }


    // 指定ini文件路径
    QSettings settings(filePath, QSettings::IniFormat);

    // 设置A组的值
    settings.beginGroup("Key_Shaft_A");
    settings.setValue("A_MAX_Up"       , ui->doubleSpinBox_maxTop->value()        ); //最大上限值
    settings.setValue("A_MAX_Defalut"  , ui->doubleSpinBox_maxDefault->value()    ); //最大默认值
    settings.setValue("A_MAX_Down"     , ui->doubleSpinBox_maxBtm->value()        ); //最大下限值
    settings.setValue("A_MIN_Up"       , ui->doubleSpinBox_minTop->value()        ); //最小上限值
    settings.setValue("A_MAX_Default"  , ui->doubleSpinBox_minDefault->value()    ); //最小默认值
    settings.setValue("A_MIN_Down"     , ui->doubleSpinBox_minBtm->value()        ); //最小下限值
    settings.setValue("A_DeadZoonUp"   , ui->doubleSpinBox_deadZoneUp->value()    ); //上死区
    settings.setValue("A_DeadZoonDown" , ui->doubleSpinBox_deadZoneDown->value()  ); //下死区
    settings.setValue("A_AcoefficientA", ui->doubleSpinBox_acoefficientA->value() ); //系数A
    settings.setValue("A_AcoefficientB", ui->doubleSpinBox_acoefficientB->value() ); //系数B
    settings.setValue("A_AcoefficientC", ui->doubleSpinBox_acoefficientC->value() ); //系数C
    settings.setValue("A_AcoefficientD", ui->doubleSpinBox_acoefficientD->value() ); //系数D
    settings.setValue("A_RT_FH_Up"     , ui->doubleSpinBox_fhTop->value()         ); //RT定高上限
    settings.setValue("A_RT_FH_Default", ui->doubleSpinBox_fhDnDft->value()       ); //RT定高默认
    settings.setValue("A_RT_FH_Down"   , ui->doubleSpinBox_fhBtm->value()         ); //RT定高下限
    settings.setValue("A_RT_Up"        , ui->doubleSpinBox_rtTop->value()         ); //RT上限值
    settings.setValue("A_RT_Down"      , ui->doubleSpinBox_rtBtm->value()         ); //RT下限值
    settings.setValue("A_RT_Click"     , ui->doubleSpinBox_rtDnDft->value()       ); //RT触发值
    settings.setValue("A_RT_Release"   , ui->doubleSpinBox_rtUpDft->value()       ); //RT抬起值
    settings.endGroup();

    // 设置B组的值
    settings.beginGroup("Key_Shaft_B");
    settings.setValue("B_MAX_Up"       , ui->doubleSpinBox_maxTop_2->value()        ); //最大上限值
    settings.setValue("B_MAX_Defalut"  , ui->doubleSpinBox_maxDefault_2->value()    ); //最大默认值
    settings.setValue("B_MAX_Down"     , ui->doubleSpinBox_maxBtm_2->value()        ); //最大下限值
    settings.setValue("B_MIN_Up"       , ui->doubleSpinBox_minTop_2->value()        ); //最小上限值
    settings.setValue("B_MAX_Default"  , ui->doubleSpinBox_minDefault_2->value()    ); //最小默认值
    settings.setValue("B_MIN_Down"     , ui->doubleSpinBox_minBtm_2->value()        ); //最小下限值
    settings.setValue("B_DeadZoonUp"   , ui->doubleSpinBox_deadZoneUp_2->value()    ); //上死区
    settings.setValue("B_DeadZoonDown" , ui->doubleSpinBox_deadZoneDown_2->value()  ); //下死区
    settings.setValue("B_AcoefficientA", ui->doubleSpinBox_acoefficientA_2->value() ); //系数A
    settings.setValue("B_AcoefficientB", ui->doubleSpinBox_acoefficientB_2->value() ); //系数B
    settings.setValue("B_AcoefficientC", ui->doubleSpinBox_acoefficientC_2->value() ); //系数C
    settings.setValue("B_AcoefficientD", ui->doubleSpinBox_acoefficientD_2->value() ); //系数D
    settings.setValue("B_RT_FH_Up"     , ui->doubleSpinBox_fhTop_2->value()         ); //RT定高上限
    settings.setValue("B_RT_FH_Default", ui->doubleSpinBox_fhDnDft_2->value()       ); //RT定高默认
    settings.setValue("B_RT_FH_Down"   , ui->doubleSpinBox_fhBtm_2->value()         ); //RT定高下限
    settings.setValue("B_RT_Up"        , ui->doubleSpinBox_rtTop_2->value()         ); //RT上限值
    settings.setValue("B_RT_Down"      , ui->doubleSpinBox_rtBtm_2->value()         ); //RT下限值
    settings.setValue("B_RT_Click"     , ui->doubleSpinBox_rtDnDft_2->value()       ); //RT触发值
    settings.setValue("B_RT_Release"   , ui->doubleSpinBox_rtUpDft_2->value()       ); //RT抬起值
    settings.endGroup();

    // 设置C组的值
    settings.beginGroup("Key_Shaft_C");
    settings.setValue("C_MAX_Up"       , ui->doubleSpinBox_maxTop_3->value()        ); //最大上限值
    settings.setValue("C_MAX_Defalut"  , ui->doubleSpinBox_maxDefault_3->value()    ); //最大默认值
    settings.setValue("C_MAX_Down"     , ui->doubleSpinBox_maxBtm_3->value()        ); //最大下限值
    settings.setValue("C_MIN_Up"       , ui->doubleSpinBox_minTop_3->value()        ); //最小上限值
    settings.setValue("C_MAX_Default"  , ui->doubleSpinBox_minDefault_3->value()    ); //最小默认值
    settings.setValue("C_MIN_Down"     , ui->doubleSpinBox_minBtm_3->value()        ); //最小下限值
    settings.setValue("C_DeadZoonUp"   , ui->doubleSpinBox_deadZoneUp_3->value()    ); //上死区
    settings.setValue("C_DeadZoonDown" , ui->doubleSpinBox_deadZoneDown_3->value()  ); //下死区
    settings.setValue("C_AcoefficientA", ui->doubleSpinBox_acoefficientA_3->value() ); //系数A
    settings.setValue("C_AcoefficientB", ui->doubleSpinBox_acoefficientB_3->value() ); //系数B
    settings.setValue("C_AcoefficientC", ui->doubleSpinBox_acoefficientC_3->value() ); //系数C
    settings.setValue("C_AcoefficientD", ui->doubleSpinBox_acoefficientD_3->value() ); //系数D
    settings.setValue("C_RT_FH_Up"     , ui->doubleSpinBox_fhTop_3->value()         ); //RT定高上限
    settings.setValue("C_RT_FH_Default", ui->doubleSpinBox_fhDnDft_3->value()       ); //RT定高默认
    settings.setValue("C_RT_FH_Down"   , ui->doubleSpinBox_fhBtm_3->value()         ); //RT定高下限
    settings.setValue("C_RT_Up"        , ui->doubleSpinBox_rtTop_3->value()         ); //RT上限值
    settings.setValue("C_RT_Down"      , ui->doubleSpinBox_rtBtm_3->value()         ); //RT下限值
    settings.setValue("C_RT_Click"     , ui->doubleSpinBox_rtDnDft_3->value()       ); //RT触发值
    settings.setValue("C_RT_Release"   , ui->doubleSpinBox_rtUpDft_3->value()       ); //RT抬起值
    settings.endGroup();

    // 设置D组的值
    settings.beginGroup("Key_Shaft_D");
    settings.setValue("D_MAX_Up"       , ui->doubleSpinBox_maxTop_4->value()        ); //最大上限值
    settings.setValue("D_MAX_Defalut"  , ui->doubleSpinBox_maxDefault_4->value()    ); //最大默认值
    settings.setValue("D_MAX_Down"     , ui->doubleSpinBox_maxBtm_4->value()        ); //最大下限值
    settings.setValue("D_MIN_Up"       , ui->doubleSpinBox_minTop_4->value()        ); //最小上限值
    settings.setValue("D_MAX_Default"  , ui->doubleSpinBox_minDefault_4->value()    ); //最小默认值
    settings.setValue("D_MIN_Down"     , ui->doubleSpinBox_minBtm_4->value()        ); //最小下限值
    settings.setValue("D_DeadZoonUp"   , ui->doubleSpinBox_deadZoneUp_4->value()    ); //上死区
    settings.setValue("D_DeadZoonDown" , ui->doubleSpinBox_deadZoneDown_4->value()  ); //下死区
    settings.setValue("D_AcoefficientA", ui->doubleSpinBox_acoefficientA_4->value() ); //系数A
    settings.setValue("D_AcoefficientB", ui->doubleSpinBox_acoefficientB_4->value() ); //系数B
    settings.setValue("D_AcoefficientC", ui->doubleSpinBox_acoefficientC_4->value() ); //系数C
    settings.setValue("D_AcoefficientD", ui->doubleSpinBox_acoefficientD_4->value() ); //系数D
    settings.setValue("D_RT_FH_Up"     , ui->doubleSpinBox_fhTop_4->value()         ); //RT定高上限
    settings.setValue("D_RT_FH_Default", ui->doubleSpinBox_fhDnDft_4->value()       ); //RT定高默认
    settings.setValue("D_RT_FH_Down"   , ui->doubleSpinBox_fhBtm_4->value()         ); //RT定高下限
    settings.setValue("D_RT_Up"        , ui->doubleSpinBox_rtTop_4->value()         ); //RT上限值
    settings.setValue("D_RT_Down"      , ui->doubleSpinBox_rtBtm_4->value()         ); //RT下限值
    settings.setValue("D_RT_Click"     , ui->doubleSpinBox_rtDnDft_4->value()       ); //RT触发值
    settings.setValue("D_RT_Release"   , ui->doubleSpinBox_rtUpDft_4->value()       ); //RT抬起值
    settings.endGroup();

    // 设置E组的值
    settings.beginGroup("Key_Shaft_E");
    settings.setValue("E_MAX_Up"       , ui->doubleSpinBox_maxTop_5->value()        ); //最大上限值
    settings.setValue("E_MAX_Defalut"  , ui->doubleSpinBox_maxDefault_5->value()    ); //最大默认值
    settings.setValue("E_MAX_Down"     , ui->doubleSpinBox_maxBtm_5->value()        ); //最大下限值
    settings.setValue("E_MIN_Up"       , ui->doubleSpinBox_minTop_5->value()        ); //最小上限值
    settings.setValue("E_MAX_Default"  , ui->doubleSpinBox_minDefault_5->value()    ); //最小默认值
    settings.setValue("E_MIN_Down"     , ui->doubleSpinBox_minBtm_5->value()        ); //最小下限值
    settings.setValue("E_DeadZoonUp"   , ui->doubleSpinBox_deadZoneUp_5->value()    ); //上死区
    settings.setValue("E_DeadZoonDown" , ui->doubleSpinBox_deadZoneDown_5->value()  ); //下死区
    settings.setValue("E_AcoefficientA", ui->doubleSpinBox_acoefficientA_5->value() ); //系数A
    settings.setValue("E_AcoefficientB", ui->doubleSpinBox_acoefficientB_5->value() ); //系数B
    settings.setValue("E_AcoefficientC", ui->doubleSpinBox_acoefficientC_5->value() ); //系数C
    settings.setValue("E_AcoefficientD", ui->doubleSpinBox_acoefficientD_5->value() ); //系数D
    settings.setValue("E_RT_FH_Up"     , ui->doubleSpinBox_fhTop_5->value()         ); //RT定高上限
    settings.setValue("E_RT_FH_Default", ui->doubleSpinBox_fhDnDft_5->value()       ); //RT定高默认
    settings.setValue("E_RT_FH_Down"   , ui->doubleSpinBox_fhBtm_5->value()         ); //RT定高下限
    settings.setValue("E_RT_Up"        , ui->doubleSpinBox_rtTop_5->value()         ); //RT上限值
    settings.setValue("E_RT_Down"      , ui->doubleSpinBox_rtBtm_5->value()         ); //RT下限值
    settings.setValue("E_RT_Click"     , ui->doubleSpinBox_rtDnDft_5->value()       ); //RT触发值
    settings.setValue("E_RT_Release"   , ui->doubleSpinBox_rtUpDft_5->value()       ); //RT抬起值
    settings.endGroup();

    // 确保写入磁盘
    settings.sync();
    // 检查错误
    if (settings.status() == QSettings::NoError) {
        qDebug() << "配置文件生成成功：" << QDir::toNativeSeparators(filePath);
        QMessageBox::information(this,"配置文件","配置文件导出成功");
        qDebug() << "内容：\n" << settings.allKeys().join('\n');
    } else {
        qDebug() << "配置文件生成失败！";
        QMessageBox::critical(this,"配置文件","配置文件导出成功");
    }
}






















