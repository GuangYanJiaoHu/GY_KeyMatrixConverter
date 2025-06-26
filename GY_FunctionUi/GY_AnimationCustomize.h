#ifndef GY_ANIMATIONCUSTOMIZE_H
#define GY_ANIMATIONCUSTOMIZE_H

#include <QWidget>

namespace Ui {
class GY_AnimationCustomize;
}

class GY_AnimationCustomize : public QWidget
{
    Q_OBJECT

public:
    explicit GY_AnimationCustomize(QWidget *parent = nullptr);
    ~GY_AnimationCustomize();

signals:
    void signalCustomizeAnimationIsDraw(bool isStart);      //开始绘制图案
    void signalCustomizeClearKey();                         //清空绘制
private slots:
    void on_pushButton_Draw_clicked();  //开始绘制图案
    void on_pushButton_Clear_clicked(); //清空绘制

private:
    Ui::GY_AnimationCustomize *ui;
};

#endif // GY_ANIMATIONCUSTOMIZE_H
