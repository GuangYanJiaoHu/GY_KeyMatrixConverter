#ifndef GY_GENERATEBINFILE_H
#define GY_GENERATEBINFILE_H

#include <QWidget>

namespace Ui {
class GY_GenerateBinFile;
}

class GY_GenerateBinFile : public QWidget
{
    Q_OBJECT

public:
    explicit GY_GenerateBinFile(QWidget *parent = nullptr);
    ~GY_GenerateBinFile();

private slots:
    void on_pushButton_keyMaxorMinValue_clicked();

private:
    Ui::GY_GenerateBinFile *ui;
};

#endif // GY_GENERATEBINFILE_H
