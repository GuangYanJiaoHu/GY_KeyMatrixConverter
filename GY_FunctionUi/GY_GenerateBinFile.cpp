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
