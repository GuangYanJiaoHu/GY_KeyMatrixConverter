/********************************************************************************
** Form generated from reading UI file 'GY_KeyboardDrawLayout.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_KEYBOARDDRAWLAYOUT_H
#define UI_GY_KEYBOARDDRAWLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_KeyboardDrawLayout
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *GY_KeyboardDrawLayout)
    {
        if (GY_KeyboardDrawLayout->objectName().isEmpty())
            GY_KeyboardDrawLayout->setObjectName("GY_KeyboardDrawLayout");
        GY_KeyboardDrawLayout->resize(1219, 496);
        gridLayout = new QGridLayout(GY_KeyboardDrawLayout);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(GY_KeyboardDrawLayout);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(GY_KeyboardDrawLayout);

        QMetaObject::connectSlotsByName(GY_KeyboardDrawLayout);
    } // setupUi

    void retranslateUi(QWidget *GY_KeyboardDrawLayout)
    {
        GY_KeyboardDrawLayout->setWindowTitle(QCoreApplication::translate("GY_KeyboardDrawLayout", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GY_KeyboardDrawLayout: public Ui_GY_KeyboardDrawLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_KEYBOARDDRAWLAYOUT_H
