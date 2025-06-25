/********************************************************************************
** Form generated from reading UI file 'GY_ConvertBinFile.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_CONVERTBINFILE_H
#define UI_GY_CONVERTBINFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_ConvertBinFile
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_ConverBinFile;
    QComboBox *comboBox_ConverBinFile;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_ReadBinFile;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *GY_ConvertBinFile)
    {
        if (GY_ConvertBinFile->objectName().isEmpty())
            GY_ConvertBinFile->setObjectName("GY_ConvertBinFile");
        GY_ConvertBinFile->resize(886, 373);
        gridLayout_2 = new QGridLayout(GY_ConvertBinFile);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GY_ConvertBinFile);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 884, 371));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setObjectName("gridLayout_4");
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(16777215, 60));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_ConverBinFile = new QPushButton(widget_3);
        pushButton_ConverBinFile->setObjectName("pushButton_ConverBinFile");
        pushButton_ConverBinFile->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setBold(true);
        pushButton_ConverBinFile->setFont(font);

        gridLayout_3->addWidget(pushButton_ConverBinFile, 0, 3, 1, 1);

        comboBox_ConverBinFile = new QComboBox(widget_3);
        comboBox_ConverBinFile->addItem(QString());
        comboBox_ConverBinFile->addItem(QString());
        comboBox_ConverBinFile->setObjectName("comboBox_ConverBinFile");

        gridLayout_3->addWidget(comboBox_ConverBinFile, 0, 2, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(110, 16777215));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_3, 1, 0, 1, 1);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setMaximumSize(QSize(110, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton_ReadBinFile = new QPushButton(widget_2);
        pushButton_ReadBinFile->setObjectName("pushButton_ReadBinFile");
        pushButton_ReadBinFile->setFont(font);

        horizontalLayout->addWidget(pushButton_ReadBinFile);


        gridLayout_4->addWidget(widget_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(GY_ConvertBinFile);

        QMetaObject::connectSlotsByName(GY_ConvertBinFile);
    } // setupUi

    void retranslateUi(QWidget *GY_ConvertBinFile)
    {
        GY_ConvertBinFile->setWindowTitle(QCoreApplication::translate("GY_ConvertBinFile", "Form", nullptr));
        pushButton_ConverBinFile->setText(QCoreApplication::translate("GY_ConvertBinFile", "\345\257\274\345\207\272\346\226\260Bin\351\205\215\345\210\227", nullptr));
        comboBox_ConverBinFile->setItemText(0, QCoreApplication::translate("GY_ConvertBinFile", "60\351\205\215\345\210\227-70\346\214\211\351\224\256", nullptr));
        comboBox_ConverBinFile->setItemText(1, QCoreApplication::translate("GY_ConvertBinFile", "98\351\205\215\345\210\227-", nullptr));

        label_2->setText(QCoreApplication::translate("GY_ConvertBinFile", "\350\275\254\346\215\242\351\224\256\347\233\230\351\205\215\345\210\227\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("GY_ConvertBinFile", "\350\257\273\345\217\226Bin\346\226\207\344\273\266\357\274\232", nullptr));
        pushButton_ReadBinFile->setText(QCoreApplication::translate("GY_ConvertBinFile", "\350\257\273\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_ConvertBinFile: public Ui_GY_ConvertBinFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_CONVERTBINFILE_H
