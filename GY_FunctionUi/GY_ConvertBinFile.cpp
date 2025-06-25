#include "GY_ConvertBinFile.h"
#include "ui_GY_ConvertBinFile.h"

GY_ConvertBinFile::GY_ConvertBinFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GY_ConvertBinFile)
{
    ui->setupUi(this);
}

GY_ConvertBinFile::~GY_ConvertBinFile()
{
    delete ui;
}
