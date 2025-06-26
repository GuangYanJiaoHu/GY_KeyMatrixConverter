/********************************************************************************
** Form generated from reading UI file 'GY_KeyboardSettingUi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_KEYBOARDSETTINGUI_H
#define UI_GY_KEYBOARDSETTINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_KeyboardSettingUi
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget_5;
    QGridLayout *gridLayout_8;
    QLabel *label_KeyboardType_4;
    QSlider *horizontalSlider_Light;
    QSpinBox *spinBox_Light;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_ClearKeyboard;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_KeyCheck;
    QCheckBox *checkBox_Hook;
    QCheckBox *checkBox_KeyPressTime;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_KeyboardType;
    QComboBox *comboBox_KeyboardType;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_KeyboardType_2;
    QSlider *horizontalSlider_Size;
    QDoubleSpinBox *doubleSpinBox_Size;

    void setupUi(QWidget *GY_KeyboardSettingUi)
    {
        if (GY_KeyboardSettingUi->objectName().isEmpty())
            GY_KeyboardSettingUi->setObjectName("GY_KeyboardSettingUi");
        GY_KeyboardSettingUi->resize(986, 434);
        gridLayout = new QGridLayout(GY_KeyboardSettingUi);
        gridLayout->setObjectName("gridLayout");
        groupBox_3 = new QGroupBox(GY_KeyboardSettingUi);
        groupBox_3->setObjectName("groupBox_3");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        groupBox_3->setFont(font);
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(groupBox_3);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 470, 380));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_9->setObjectName("gridLayout_9");
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName("gridLayout_7");
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_7->addWidget(textBrowser, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_7->addWidget(pushButton_2, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox, 2, 0, 1, 1);

        widget_4 = new QWidget(scrollAreaWidgetContents_2);
        widget_4->setObjectName("widget_4");
        gridLayout_6 = new QGridLayout(widget_4);
        gridLayout_6->setObjectName("gridLayout_6");
        label = new QLabel(widget_4);
        label->setObjectName("label");

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget_4);
        lineEdit->setObjectName("lineEdit");

        gridLayout_6->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName("pushButton");

        gridLayout_6->addWidget(pushButton, 0, 2, 1, 1);


        gridLayout_9->addWidget(widget_4, 1, 0, 1, 1);

        widget_5 = new QWidget(scrollAreaWidgetContents_2);
        widget_5->setObjectName("widget_5");
        widget_5->setMaximumSize(QSize(16777215, 120));
        gridLayout_8 = new QGridLayout(widget_5);
        gridLayout_8->setObjectName("gridLayout_8");
        label_KeyboardType_4 = new QLabel(widget_5);
        label_KeyboardType_4->setObjectName("label_KeyboardType_4");
        label_KeyboardType_4->setMaximumSize(QSize(110, 16777215));

        gridLayout_8->addWidget(label_KeyboardType_4, 0, 0, 1, 1);

        horizontalSlider_Light = new QSlider(widget_5);
        horizontalSlider_Light->setObjectName("horizontalSlider_Light");
        horizontalSlider_Light->setMaximum(255);
        horizontalSlider_Light->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_8->addWidget(horizontalSlider_Light, 0, 1, 1, 1);

        spinBox_Light = new QSpinBox(widget_5);
        spinBox_Light->setObjectName("spinBox_Light");
        spinBox_Light->setMinimumSize(QSize(80, 0));
        spinBox_Light->setMaximum(255);

        gridLayout_8->addWidget(spinBox_Light, 0, 2, 1, 1);


        gridLayout_9->addWidget(widget_5, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_11->addWidget(scrollArea_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(GY_KeyboardSettingUi);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 454, 380));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_ClearKeyboard = new QPushButton(scrollAreaWidgetContents);
        pushButton_ClearKeyboard->setObjectName("pushButton_ClearKeyboard");
        pushButton_ClearKeyboard->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_ClearKeyboard, 3, 0, 1, 1);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName("gridLayout_4");
        checkBox_KeyCheck = new QCheckBox(widget_2);
        checkBox_KeyCheck->setObjectName("checkBox_KeyCheck");

        gridLayout_4->addWidget(checkBox_KeyCheck, 0, 1, 1, 1);

        checkBox_Hook = new QCheckBox(widget_2);
        checkBox_Hook->setObjectName("checkBox_Hook");
        checkBox_Hook->setChecked(false);

        gridLayout_4->addWidget(checkBox_Hook, 0, 0, 1, 1);

        checkBox_KeyPressTime = new QCheckBox(widget_2);
        checkBox_KeyPressTime->setObjectName("checkBox_KeyPressTime");

        gridLayout_4->addWidget(checkBox_KeyPressTime, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 120));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_KeyboardType = new QLabel(widget);
        label_KeyboardType->setObjectName("label_KeyboardType");
        label_KeyboardType->setMaximumSize(QSize(110, 16777215));

        horizontalLayout->addWidget(label_KeyboardType);

        comboBox_KeyboardType = new QComboBox(widget);
        comboBox_KeyboardType->addItem(QString());
        comboBox_KeyboardType->addItem(QString());
        comboBox_KeyboardType->setObjectName("comboBox_KeyboardType");

        horizontalLayout->addWidget(comboBox_KeyboardType);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_KeyboardType_2 = new QLabel(widget);
        label_KeyboardType_2->setObjectName("label_KeyboardType_2");
        label_KeyboardType_2->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_2->addWidget(label_KeyboardType_2);

        horizontalSlider_Size = new QSlider(widget);
        horizontalSlider_Size->setObjectName("horizontalSlider_Size");
        horizontalSlider_Size->setMinimum(1);
        horizontalSlider_Size->setMaximum(100);
        horizontalSlider_Size->setSingleStep(1);
        horizontalSlider_Size->setValue(1);
        horizontalSlider_Size->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_Size->setTickInterval(1);

        horizontalLayout_2->addWidget(horizontalSlider_Size);

        doubleSpinBox_Size = new QDoubleSpinBox(widget);
        doubleSpinBox_Size->setObjectName("doubleSpinBox_Size");
        doubleSpinBox_Size->setMinimumSize(QSize(80, 0));
        doubleSpinBox_Size->setMinimum(1.000000000000000);
        doubleSpinBox_Size->setMaximum(10.000000000000000);
        doubleSpinBox_Size->setSingleStep(1.000000000000000);
        doubleSpinBox_Size->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_Size);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_10->addWidget(scrollArea, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);


        retranslateUi(GY_KeyboardSettingUi);

        QMetaObject::connectSlotsByName(GY_KeyboardSettingUi);
    } // setupUi

    void retranslateUi(QWidget *GY_KeyboardSettingUi)
    {
        GY_KeyboardSettingUi->setWindowTitle(QCoreApplication::translate("GY_KeyboardSettingUi", "Form", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\344\277\241\346\201\257\345\233\236\344\274\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\346\270\205\347\251\272", nullptr));
        label->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\344\277\241\346\201\257\345\217\221\351\200\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\345\217\221\351\200\201", nullptr));
        label_KeyboardType_4->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\344\272\256\345\272\246\350\260\203\346\225\264\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GY_KeyboardSettingUi", "\347\225\214\351\235\242\351\205\215\347\275\256", nullptr));
        pushButton_ClearKeyboard->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\345\210\235\345\247\213\345\214\226(\346\270\205\347\251\272)\346\214\211\351\224\256\346\243\200\346\265\213", nullptr));
        checkBox_KeyCheck->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\346\214\211\351\224\256\346\243\200\346\265\213\345\212\237\350\203\275", nullptr));
        checkBox_Hook->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\345\205\250\345\261\200\351\222\251\345\255\220", nullptr));
        checkBox_KeyPressTime->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\346\214\211\351\224\256\346\227\266\351\227\264\346\230\276\347\244\272", nullptr));
        label_KeyboardType->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\347\261\273\345\236\213\351\200\211\346\213\251\357\274\232", nullptr));
        comboBox_KeyboardType->setItemText(0, QCoreApplication::translate("GY_KeyboardSettingUi", "60\351\205\215\345\210\227-70\346\214\211\351\224\256", nullptr));
        comboBox_KeyboardType->setItemText(1, QCoreApplication::translate("GY_KeyboardSettingUi", "\346\226\260\345\242\236\346\265\213\350\257\225", nullptr));

        label_KeyboardType_2->setText(QCoreApplication::translate("GY_KeyboardSettingUi", "\351\224\256\347\233\230\345\244\247\345\260\217\350\260\203\346\225\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_KeyboardSettingUi: public Ui_GY_KeyboardSettingUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_KEYBOARDSETTINGUI_H
