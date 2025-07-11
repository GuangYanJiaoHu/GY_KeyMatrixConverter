/********************************************************************************
** Form generated from reading UI file 'GY_AnimationSettingUi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GY_ANIMATIONSETTINGUI_H
#define UI_GY_ANIMATIONSETTINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GY_AnimationSettingUi
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_Static;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_12;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_StaticReadPath;
    QLineEdit *lineEdit_StaticReadPath;
    QPushButton *pushButton_StaticReadPath;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_StaticOnlySimulate;
    QComboBox *comboBox_StaticOnlySimulate;
    QCheckBox *checkBox_StaticSend;
    QWidget *widget_4;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_StaticStart;
    QPushButton *pushButton_StaticExport;
    QWidget *widget_8;
    QGridLayout *gridLayout_8;
    QLabel *label_StaticSend;
    QLabel *label_StaticUi;
    QLabel *label_StaticSendMs;
    QLabel *label_StaticUiMs;
    QSlider *horizontalSlider_StaticUi;
    QSlider *horizontalSlider_StaticSend;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_14;
    QWidget *widget_10;
    QGridLayout *gridLayout_15;
    QLabel *label_DynamicSend_2;
    QLabel *label_PixmapWidth;
    QSlider *horizontalSlider_PixmapHeight;
    QSlider *horizontalSlider_PixmapWidth;
    QLabel *label_PixmapHeight;
    QLabel *label_DynamicUi_2;
    QSpinBox *spinBox_PixmapWidth;
    QSpinBox *spinBox_PixmapHeight;
    QWidget *widget_9;
    QGridLayout *gridLayout_13;
    QLabel *label_DynamicUiMs;
    QLabel *label_DynamicSend;
    QLabel *label_DynamicUi;
    QLabel *label_DynamicSendMs;
    QSlider *horizontalSlider_DynamicUi;
    QSlider *horizontalSlider_DynamicSend;
    QWidget *widget_5;
    QGridLayout *gridLayout_9;
    QLabel *label_DynamicReadPath;
    QLineEdit *lineEdit_DynamicReadPath;
    QPushButton *pushButton_DynamicReadPath;
    QWidget *widget_7;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_DynamicStart;
    QPushButton *pushButton_DynamicExport;
    QWidget *widget_6;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_DynamicOnlySimulate;
    QLabel *label_DynamicOnlySimulate;
    QCheckBox *checkBox_DynamicSend;
    QPushButton *pushButton_DynamicUpdateSimulatePos;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *GY_AnimationSettingUi)
    {
        if (GY_AnimationSettingUi->objectName().isEmpty())
            GY_AnimationSettingUi->setObjectName("GY_AnimationSettingUi");
        GY_AnimationSettingUi->resize(912, 542);
        gridLayout = new QGridLayout(GY_AnimationSettingUi);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GY_AnimationSettingUi);
        widget->setObjectName("widget");
        QFont font;
        font.setPointSize(9);
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:10px;  /*\345\234\206\350\247\222*/\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	color: rgb(200, 200, 174);\n"
"	background-color: rgb(27, 213, 116);\n"
"	border-radius:10px;  /*\345\234\206\350\247\222*/\n"
"} \n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:10px;  /*\345\234\206\350\247\222*/\n"
"} "));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName("gridLayout_5");
        scrollArea_Static = new QScrollArea(groupBox);
        scrollArea_Static->setObjectName("scrollArea_Static");
        scrollArea_Static->setFont(font);
        scrollArea_Static->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        scrollArea_Static->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 406, 490));
        gridLayout_12 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_12->setObjectName("gridLayout_12");
        gridLayout_12->setVerticalSpacing(7);
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(16777215, 50));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_StaticReadPath = new QLabel(widget_2);
        label_StaticReadPath->setObjectName("label_StaticReadPath");
        label_StaticReadPath->setMaximumSize(QSize(70, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        font1.setBold(true);
        label_StaticReadPath->setFont(font1);

        gridLayout_3->addWidget(label_StaticReadPath, 0, 0, 1, 1);

        lineEdit_StaticReadPath = new QLineEdit(widget_2);
        lineEdit_StaticReadPath->setObjectName("lineEdit_StaticReadPath");
        lineEdit_StaticReadPath->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_StaticReadPath, 0, 1, 1, 1);

        pushButton_StaticReadPath = new QPushButton(widget_2);
        pushButton_StaticReadPath->setObjectName("pushButton_StaticReadPath");
        pushButton_StaticReadPath->setMinimumSize(QSize(60, 0));
        pushButton_StaticReadPath->setFont(font1);

        gridLayout_3->addWidget(pushButton_StaticReadPath, 0, 2, 1, 1);


        gridLayout_12->addWidget(widget_2, 0, 0, 1, 1);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(16777215, 50));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(-1, 0, -1, 0);
        label_StaticOnlySimulate = new QLabel(widget_3);
        label_StaticOnlySimulate->setObjectName("label_StaticOnlySimulate");
        label_StaticOnlySimulate->setMaximumSize(QSize(70, 16777215));
        label_StaticOnlySimulate->setFont(font1);

        gridLayout_4->addWidget(label_StaticOnlySimulate, 0, 0, 1, 1);

        comboBox_StaticOnlySimulate = new QComboBox(widget_3);
        comboBox_StaticOnlySimulate->setObjectName("comboBox_StaticOnlySimulate");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(11);
        font2.setBold(true);
        comboBox_StaticOnlySimulate->setFont(font2);

        gridLayout_4->addWidget(comboBox_StaticOnlySimulate, 0, 1, 1, 1);

        checkBox_StaticSend = new QCheckBox(widget_3);
        checkBox_StaticSend->setObjectName("checkBox_StaticSend");
        checkBox_StaticSend->setFont(font1);

        gridLayout_4->addWidget(checkBox_StaticSend, 0, 2, 1, 1);


        gridLayout_12->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName("widget_4");
        widget_4->setMaximumSize(QSize(16777215, 80));
        gridLayout_7 = new QGridLayout(widget_4);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setHorizontalSpacing(7);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        pushButton_StaticStart = new QPushButton(widget_4);
        pushButton_StaticStart->setObjectName("pushButton_StaticStart");
        pushButton_StaticStart->setMinimumSize(QSize(0, 50));
        pushButton_StaticStart->setFont(font1);

        gridLayout_7->addWidget(pushButton_StaticStart, 0, 0, 1, 1);

        pushButton_StaticExport = new QPushButton(widget_4);
        pushButton_StaticExport->setObjectName("pushButton_StaticExport");
        pushButton_StaticExport->setMinimumSize(QSize(0, 50));
        pushButton_StaticExport->setFont(font1);

        gridLayout_7->addWidget(pushButton_StaticExport, 0, 2, 1, 1);


        gridLayout_12->addWidget(widget_4, 2, 0, 1, 1);

        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName("widget_8");
        widget_8->setMaximumSize(QSize(16777215, 80));
        gridLayout_8 = new QGridLayout(widget_8);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(11, 0, 11, 0);
        label_StaticSend = new QLabel(widget_8);
        label_StaticSend->setObjectName("label_StaticSend");
        label_StaticSend->setFont(font1);

        gridLayout_8->addWidget(label_StaticSend, 1, 0, 1, 1);

        label_StaticUi = new QLabel(widget_8);
        label_StaticUi->setObjectName("label_StaticUi");
        label_StaticUi->setFont(font1);

        gridLayout_8->addWidget(label_StaticUi, 0, 0, 1, 1);

        label_StaticSendMs = new QLabel(widget_8);
        label_StaticSendMs->setObjectName("label_StaticSendMs");
        label_StaticSendMs->setMinimumSize(QSize(50, 0));
        label_StaticSendMs->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(label_StaticSendMs, 1, 2, 1, 1);

        label_StaticUiMs = new QLabel(widget_8);
        label_StaticUiMs->setObjectName("label_StaticUiMs");
        label_StaticUiMs->setMinimumSize(QSize(50, 0));
        label_StaticUiMs->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(label_StaticUiMs, 0, 2, 1, 1);

        horizontalSlider_StaticUi = new QSlider(widget_8);
        horizontalSlider_StaticUi->setObjectName("horizontalSlider_StaticUi");
        horizontalSlider_StaticUi->setMinimum(10);
        horizontalSlider_StaticUi->setMaximum(300);
        horizontalSlider_StaticUi->setPageStep(1);
        horizontalSlider_StaticUi->setValue(50);
        horizontalSlider_StaticUi->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_8->addWidget(horizontalSlider_StaticUi, 0, 1, 1, 1);

        horizontalSlider_StaticSend = new QSlider(widget_8);
        horizontalSlider_StaticSend->setObjectName("horizontalSlider_StaticSend");
        horizontalSlider_StaticSend->setMinimum(10);
        horizontalSlider_StaticSend->setMaximum(300);
        horizontalSlider_StaticSend->setPageStep(1);
        horizontalSlider_StaticSend->setValue(50);
        horizontalSlider_StaticSend->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_8->addWidget(horizontalSlider_StaticSend, 1, 1, 1, 1);


        gridLayout_12->addWidget(widget_8, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_12->addItem(verticalSpacer, 4, 0, 1, 1);

        scrollArea_Static->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea_Static, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName("gridLayout_6");
        scrollArea_2 = new QScrollArea(groupBox_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 405, 490));
        gridLayout_14 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_14->setSpacing(7);
        gridLayout_14->setObjectName("gridLayout_14");
        widget_10 = new QWidget(scrollAreaWidgetContents_2);
        widget_10->setObjectName("widget_10");
        widget_10->setMinimumSize(QSize(0, 0));
        widget_10->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_15 = new QGridLayout(widget_10);
        gridLayout_15->setObjectName("gridLayout_15");
        gridLayout_15->setHorizontalSpacing(0);
        gridLayout_15->setContentsMargins(11, 0, 11, 0);
        label_DynamicSend_2 = new QLabel(widget_10);
        label_DynamicSend_2->setObjectName("label_DynamicSend_2");
        label_DynamicSend_2->setMinimumSize(QSize(40, 0));
        label_DynamicSend_2->setMaximumSize(QSize(40, 16777215));
        label_DynamicSend_2->setFont(font1);

        gridLayout_15->addWidget(label_DynamicSend_2, 1, 0, 1, 1);

        label_PixmapWidth = new QLabel(widget_10);
        label_PixmapWidth->setObjectName("label_PixmapWidth");
        label_PixmapWidth->setMinimumSize(QSize(20, 0));
        label_PixmapWidth->setMaximumSize(QSize(20, 16777215));

        gridLayout_15->addWidget(label_PixmapWidth, 0, 3, 1, 1);

        horizontalSlider_PixmapHeight = new QSlider(widget_10);
        horizontalSlider_PixmapHeight->setObjectName("horizontalSlider_PixmapHeight");
        horizontalSlider_PixmapHeight->setMinimum(100);
        horizontalSlider_PixmapHeight->setMaximum(400);
        horizontalSlider_PixmapHeight->setValue(100);
        horizontalSlider_PixmapHeight->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_15->addWidget(horizontalSlider_PixmapHeight, 1, 1, 1, 1);

        horizontalSlider_PixmapWidth = new QSlider(widget_10);
        horizontalSlider_PixmapWidth->setObjectName("horizontalSlider_PixmapWidth");
        horizontalSlider_PixmapWidth->setMinimum(100);
        horizontalSlider_PixmapWidth->setMaximum(400);
        horizontalSlider_PixmapWidth->setValue(100);
        horizontalSlider_PixmapWidth->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_15->addWidget(horizontalSlider_PixmapWidth, 0, 1, 1, 1);

        label_PixmapHeight = new QLabel(widget_10);
        label_PixmapHeight->setObjectName("label_PixmapHeight");
        label_PixmapHeight->setMinimumSize(QSize(20, 0));
        label_PixmapHeight->setMaximumSize(QSize(20, 16777215));

        gridLayout_15->addWidget(label_PixmapHeight, 1, 3, 1, 1);

        label_DynamicUi_2 = new QLabel(widget_10);
        label_DynamicUi_2->setObjectName("label_DynamicUi_2");
        label_DynamicUi_2->setMinimumSize(QSize(40, 0));
        label_DynamicUi_2->setMaximumSize(QSize(40, 16777215));
        label_DynamicUi_2->setFont(font1);

        gridLayout_15->addWidget(label_DynamicUi_2, 0, 0, 1, 1);

        spinBox_PixmapWidth = new QSpinBox(widget_10);
        spinBox_PixmapWidth->setObjectName("spinBox_PixmapWidth");
        spinBox_PixmapWidth->setMinimumSize(QSize(75, 30));
        spinBox_PixmapWidth->setMinimum(100);
        spinBox_PixmapWidth->setMaximum(400);

        gridLayout_15->addWidget(spinBox_PixmapWidth, 0, 2, 1, 1);

        spinBox_PixmapHeight = new QSpinBox(widget_10);
        spinBox_PixmapHeight->setObjectName("spinBox_PixmapHeight");
        spinBox_PixmapHeight->setMinimumSize(QSize(75, 30));
        spinBox_PixmapHeight->setMinimum(100);
        spinBox_PixmapHeight->setMaximum(400);

        gridLayout_15->addWidget(spinBox_PixmapHeight, 1, 2, 1, 1);


        gridLayout_14->addWidget(widget_10, 7, 0, 1, 1);

        widget_9 = new QWidget(scrollAreaWidgetContents_2);
        widget_9->setObjectName("widget_9");
        widget_9->setMaximumSize(QSize(16777215, 80));
        gridLayout_13 = new QGridLayout(widget_9);
        gridLayout_13->setObjectName("gridLayout_13");
        gridLayout_13->setContentsMargins(11, 0, 11, 0);
        label_DynamicUiMs = new QLabel(widget_9);
        label_DynamicUiMs->setObjectName("label_DynamicUiMs");
        label_DynamicUiMs->setMinimumSize(QSize(50, 0));
        label_DynamicUiMs->setMaximumSize(QSize(50, 16777215));

        gridLayout_13->addWidget(label_DynamicUiMs, 0, 2, 1, 1);

        label_DynamicSend = new QLabel(widget_9);
        label_DynamicSend->setObjectName("label_DynamicSend");
        label_DynamicSend->setFont(font1);

        gridLayout_13->addWidget(label_DynamicSend, 1, 0, 1, 1);

        label_DynamicUi = new QLabel(widget_9);
        label_DynamicUi->setObjectName("label_DynamicUi");
        label_DynamicUi->setFont(font1);

        gridLayout_13->addWidget(label_DynamicUi, 0, 0, 1, 1);

        label_DynamicSendMs = new QLabel(widget_9);
        label_DynamicSendMs->setObjectName("label_DynamicSendMs");
        label_DynamicSendMs->setMinimumSize(QSize(50, 0));
        label_DynamicSendMs->setMaximumSize(QSize(50, 16777215));

        gridLayout_13->addWidget(label_DynamicSendMs, 1, 2, 1, 1);

        horizontalSlider_DynamicUi = new QSlider(widget_9);
        horizontalSlider_DynamicUi->setObjectName("horizontalSlider_DynamicUi");
        horizontalSlider_DynamicUi->setMinimum(10);
        horizontalSlider_DynamicUi->setMaximum(300);
        horizontalSlider_DynamicUi->setValue(50);
        horizontalSlider_DynamicUi->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_13->addWidget(horizontalSlider_DynamicUi, 0, 1, 1, 1);

        horizontalSlider_DynamicSend = new QSlider(widget_9);
        horizontalSlider_DynamicSend->setObjectName("horizontalSlider_DynamicSend");
        horizontalSlider_DynamicSend->setMinimum(10);
        horizontalSlider_DynamicSend->setMaximum(300);
        horizontalSlider_DynamicSend->setValue(50);
        horizontalSlider_DynamicSend->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_13->addWidget(horizontalSlider_DynamicSend, 1, 1, 1, 1);


        gridLayout_14->addWidget(widget_9, 3, 0, 1, 1);

        widget_5 = new QWidget(scrollAreaWidgetContents_2);
        widget_5->setObjectName("widget_5");
        widget_5->setMaximumSize(QSize(16777215, 50));
        gridLayout_9 = new QGridLayout(widget_5);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(-1, 0, -1, 0);
        label_DynamicReadPath = new QLabel(widget_5);
        label_DynamicReadPath->setObjectName("label_DynamicReadPath");
        label_DynamicReadPath->setMaximumSize(QSize(70, 16777215));
        label_DynamicReadPath->setFont(font1);

        gridLayout_9->addWidget(label_DynamicReadPath, 0, 0, 1, 1);

        lineEdit_DynamicReadPath = new QLineEdit(widget_5);
        lineEdit_DynamicReadPath->setObjectName("lineEdit_DynamicReadPath");
        lineEdit_DynamicReadPath->setReadOnly(true);

        gridLayout_9->addWidget(lineEdit_DynamicReadPath, 0, 1, 1, 1);

        pushButton_DynamicReadPath = new QPushButton(widget_5);
        pushButton_DynamicReadPath->setObjectName("pushButton_DynamicReadPath");
        pushButton_DynamicReadPath->setMinimumSize(QSize(60, 0));
        pushButton_DynamicReadPath->setFont(font1);

        gridLayout_9->addWidget(pushButton_DynamicReadPath, 0, 2, 1, 1);


        gridLayout_14->addWidget(widget_5, 0, 0, 1, 1);

        widget_7 = new QWidget(scrollAreaWidgetContents_2);
        widget_7->setObjectName("widget_7");
        widget_7->setMaximumSize(QSize(16777215, 80));
        gridLayout_11 = new QGridLayout(widget_7);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setHorizontalSpacing(7);
        gridLayout_11->setContentsMargins(-1, 0, -1, 0);
        pushButton_DynamicStart = new QPushButton(widget_7);
        pushButton_DynamicStart->setObjectName("pushButton_DynamicStart");
        pushButton_DynamicStart->setMinimumSize(QSize(0, 50));
        pushButton_DynamicStart->setFont(font1);

        gridLayout_11->addWidget(pushButton_DynamicStart, 0, 0, 1, 1);

        pushButton_DynamicExport = new QPushButton(widget_7);
        pushButton_DynamicExport->setObjectName("pushButton_DynamicExport");
        pushButton_DynamicExport->setMinimumSize(QSize(0, 50));
        pushButton_DynamicExport->setFont(font1);

        gridLayout_11->addWidget(pushButton_DynamicExport, 0, 2, 1, 1);


        gridLayout_14->addWidget(widget_7, 2, 0, 1, 1);

        widget_6 = new QWidget(scrollAreaWidgetContents_2);
        widget_6->setObjectName("widget_6");
        widget_6->setMaximumSize(QSize(16777215, 50));
        gridLayout_10 = new QGridLayout(widget_6);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(-1, 0, -1, 0);
        comboBox_DynamicOnlySimulate = new QComboBox(widget_6);
        comboBox_DynamicOnlySimulate->setObjectName("comboBox_DynamicOnlySimulate");
        comboBox_DynamicOnlySimulate->setFont(font2);

        gridLayout_10->addWidget(comboBox_DynamicOnlySimulate, 0, 1, 1, 1);

        label_DynamicOnlySimulate = new QLabel(widget_6);
        label_DynamicOnlySimulate->setObjectName("label_DynamicOnlySimulate");
        label_DynamicOnlySimulate->setMaximumSize(QSize(70, 16777215));
        label_DynamicOnlySimulate->setFont(font1);

        gridLayout_10->addWidget(label_DynamicOnlySimulate, 0, 0, 1, 1);

        checkBox_DynamicSend = new QCheckBox(widget_6);
        checkBox_DynamicSend->setObjectName("checkBox_DynamicSend");
        checkBox_DynamicSend->setFont(font1);

        gridLayout_10->addWidget(checkBox_DynamicSend, 0, 2, 1, 1);


        gridLayout_14->addWidget(widget_6, 1, 0, 1, 1);

        pushButton_DynamicUpdateSimulatePos = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_DynamicUpdateSimulatePos->setObjectName("pushButton_DynamicUpdateSimulatePos");
        pushButton_DynamicUpdateSimulatePos->setMinimumSize(QSize(0, 50));
        pushButton_DynamicUpdateSimulatePos->setFont(font1);

        gridLayout_14->addWidget(pushButton_DynamicUpdateSimulatePos, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(17, 116, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_14->addItem(verticalSpacer_2, 8, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_6->addWidget(scrollArea_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(GY_AnimationSettingUi);

        QMetaObject::connectSlotsByName(GY_AnimationSettingUi);
    } // setupUi

    void retranslateUi(QWidget *GY_AnimationSettingUi)
    {
        GY_AnimationSettingUi->setWindowTitle(QCoreApplication::translate("GY_AnimationSettingUi", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GY_AnimationSettingUi", "\351\235\231\346\200\201\345\212\250\347\224\273", nullptr));
        label_StaticReadPath->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\212\250\347\224\273\345\234\260\345\235\200\357\274\232", nullptr));
        pushButton_StaticReadPath->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\350\257\273\345\217\226", nullptr));
        label_StaticOnlySimulate->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\351\200\220\345\270\247\346\250\241\346\213\237\357\274\232", nullptr));
        checkBox_StaticSend->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\346\250\241\346\213\237\344\270\213\345\217\221\351\224\256\347\233\230", nullptr));
        pushButton_StaticStart->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        pushButton_StaticExport->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\257\274\345\207\272\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        label_StaticSend->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\351\224\256\347\233\230\344\270\213\345\217\221\351\200\237\345\272\246\357\274\232", nullptr));
        label_StaticUi->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\347\225\214\351\235\242\346\250\241\346\213\237\351\200\237\345\272\246\357\274\232", nullptr));
        label_StaticSendMs->setText(QCoreApplication::translate("GY_AnimationSettingUi", "50ms", nullptr));
        label_StaticUiMs->setText(QCoreApplication::translate("GY_AnimationSettingUi", "50ms", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GY_AnimationSettingUi", "\345\212\250\346\200\201\345\212\250\347\224\273", nullptr));
        label_DynamicSend_2->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\233\276\351\253\230\357\274\232", nullptr));
        label_PixmapWidth->setText(QCoreApplication::translate("GY_AnimationSettingUi", "PX", nullptr));
        label_PixmapHeight->setText(QCoreApplication::translate("GY_AnimationSettingUi", "PX", nullptr));
        label_DynamicUi_2->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\233\276\345\256\275\357\274\232", nullptr));
        label_DynamicUiMs->setText(QCoreApplication::translate("GY_AnimationSettingUi", "50ms", nullptr));
        label_DynamicSend->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\351\224\256\347\233\230\344\270\213\345\217\221\351\200\237\345\272\246\357\274\232", nullptr));
        label_DynamicUi->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\347\225\214\351\235\242\346\250\241\346\213\237\351\200\237\345\272\246\357\274\232", nullptr));
        label_DynamicSendMs->setText(QCoreApplication::translate("GY_AnimationSettingUi", "50ms", nullptr));
        label_DynamicReadPath->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\212\250\347\224\273\345\234\260\345\235\200\357\274\232", nullptr));
        pushButton_DynamicReadPath->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\350\257\273\345\217\226", nullptr));
        pushButton_DynamicStart->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        pushButton_DynamicExport->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\345\257\274\345\207\272\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        label_DynamicOnlySimulate->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\351\200\220\345\270\247\346\250\241\346\213\237\357\274\232", nullptr));
        checkBox_DynamicSend->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\346\250\241\346\213\237\344\270\213\345\217\221\351\224\256\347\233\230", nullptr));
        pushButton_DynamicUpdateSimulatePos->setText(QCoreApplication::translate("GY_AnimationSettingUi", "\346\233\264\346\226\260\346\250\241\346\213\237\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_AnimationSettingUi: public Ui_GY_AnimationSettingUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_ANIMATIONSETTINGUI_H
