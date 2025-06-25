#ifndef GY_CONVERTBINFILE_H
#define GY_CONVERTBINFILE_H

#include <QWidget>

namespace Ui {
class GY_ConvertBinFile;
}

class GY_ConvertBinFile : public QWidget
{
    Q_OBJECT

public:
    explicit GY_ConvertBinFile(QWidget *parent = nullptr);
    ~GY_ConvertBinFile();

private:
    Ui::GY_ConvertBinFile *ui;
};

#endif // GY_CONVERTBINFILE_H
