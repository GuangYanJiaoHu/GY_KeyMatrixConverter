#include "GY_GenerateBinFile.h"
#include "ui_GY_GenerateBinFile.h"

GY_GenerateBinFile::GY_GenerateBinFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_GenerateBinFile)
{
    ui->setupUi(this);
}

GY_GenerateBinFile::~GY_GenerateBinFile()
{
    delete ui;
}
//确认按键默认值
void GY_GenerateBinFile::on_pushButton_keyMaxorMinValue_clicked()
{

}

