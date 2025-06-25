/********************************************************************************
** Form generated from reading UI file 'GY_GenerateBinFile.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_GENERATEBINFILE_H
#define UI_GY_GENERATEBINFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_GenerateBinFile
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *GY_GenerateBinFile)
    {
        if (GY_GenerateBinFile->objectName().isEmpty())
            GY_GenerateBinFile->setObjectName("GY_GenerateBinFile");
        GY_GenerateBinFile->resize(908, 553);
        gridLayout_2 = new QGridLayout(GY_GenerateBinFile);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GY_GenerateBinFile);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 906, 551));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(GY_GenerateBinFile);

        QMetaObject::connectSlotsByName(GY_GenerateBinFile);
    } // setupUi

    void retranslateUi(QWidget *GY_GenerateBinFile)
    {
        GY_GenerateBinFile->setWindowTitle(QCoreApplication::translate("GY_GenerateBinFile", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_GenerateBinFile: public Ui_GY_GenerateBinFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_GENERATEBINFILE_H
