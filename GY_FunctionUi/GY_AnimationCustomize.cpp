#include "GY_AnimationCustomize.h"
#include "ui_GY_AnimationCustomize.h"

GY_AnimationCustomize::GY_AnimationCustomize(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_AnimationCustomize)
{
    ui->setupUi(this);
    ui->pushButton_Draw->setCheckable(true);
}

GY_AnimationCustomize::~GY_AnimationCustomize()
{
    delete ui;
}



//开始绘图案
void GY_AnimationCustomize::on_pushButton_Draw_clicked()
{
    if(!ui->pushButton_Draw->isChecked()){
        ui->pushButton_Draw->setText("开始绘制");
        emit signalCustomizeAnimationIsDraw(false);
    }else{
        ui->pushButton_Draw->setText("结束绘制");
        emit signalCustomizeAnimationIsDraw(true);
    }
}


void GY_AnimationCustomize::on_pushButton_Clear_clicked()
{
    emit signalCustomizeClearKey();
}

