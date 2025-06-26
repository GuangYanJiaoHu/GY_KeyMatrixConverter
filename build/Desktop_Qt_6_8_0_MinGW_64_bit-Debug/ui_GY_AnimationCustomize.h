/********************************************************************************
** Form generated from reading UI file 'GY_AnimationCustomize.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_ANIMATIONCUSTOMIZE_H
#define UI_GY_ANIMATIONCUSTOMIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_AnimationCustomize
{
public:
    QPushButton *pushButton_Draw;
    QPushButton *pushButton_Clear;

    void setupUi(QWidget *GY_AnimationCustomize)
    {
        if (GY_AnimationCustomize->objectName().isEmpty())
            GY_AnimationCustomize->setObjectName("GY_AnimationCustomize");
        GY_AnimationCustomize->resize(692, 400);
        pushButton_Draw = new QPushButton(GY_AnimationCustomize);
        pushButton_Draw->setObjectName("pushButton_Draw");
        pushButton_Draw->setGeometry(QRect(50, 90, 121, 61));
        pushButton_Clear = new QPushButton(GY_AnimationCustomize);
        pushButton_Clear->setObjectName("pushButton_Clear");
        pushButton_Clear->setGeometry(QRect(200, 90, 111, 61));

        retranslateUi(GY_AnimationCustomize);

        QMetaObject::connectSlotsByName(GY_AnimationCustomize);
    } // setupUi

    void retranslateUi(QWidget *GY_AnimationCustomize)
    {
        GY_AnimationCustomize->setWindowTitle(QCoreApplication::translate("GY_AnimationCustomize", "Form", nullptr));
        pushButton_Draw->setText(QCoreApplication::translate("GY_AnimationCustomize", "\345\274\200\345\247\213\347\273\230\345\210\266", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("GY_AnimationCustomize", "\346\270\205\347\251\272\347\273\230\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_AnimationCustomize: public Ui_GY_AnimationCustomize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_ANIMATIONCUSTOMIZE_H
