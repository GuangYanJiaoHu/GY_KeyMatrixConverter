#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <GY_KeyboardDrawLayout/GY_KeyboardDrawLayout.h>
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

private slots:
    void on_pushButton_KeyCheck_clicked();

private:
    Ui::MainWindow *ui;
    GY_KeyboardDrawLayout *keyboardDrawLayout;
};
#endif // MAINWINDOW_H
