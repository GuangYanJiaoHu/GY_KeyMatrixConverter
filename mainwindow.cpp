#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    keyboardDrawLayout = new GY_KeyboardDrawLayout(ui->widget_keyboardLayout);
    //keyboardDrawLayout = new GY_KeyboardDrawLayout();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//打开按键检测
void MainWindow::on_pushButton_KeyCheck_clicked()
{
    keyboardDrawLayout->test("Alt");
    QTimer::singleShot(1000,this,[=](){
        keyboardDrawLayout->test("A");
    });
    QTimer::singleShot(2000,this,[=](){
        keyboardDrawLayout->test("O");
    });

}

