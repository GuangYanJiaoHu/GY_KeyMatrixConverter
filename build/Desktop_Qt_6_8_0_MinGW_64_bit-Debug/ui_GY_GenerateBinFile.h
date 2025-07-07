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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
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
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QWidget *widget_2;
    QGridLayout *gridLayout_14;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_10;
    QListWidget *listWidget_Dynamic;
    QFrame *frame_4;
    QGridLayout *gridLayout_9;
    QLineEdit *lineEdit_DynamicPath;
    QPushButton *pushButton_Dynamic;
    QFrame *line_4;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QGridLayout *gridLayout_12;
    QFrame *frame_5;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_Static;
    QLineEdit *lineEdit_StaticPath;
    QFrame *line_3;
    QListWidget *listWidget_Static;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_6;
    QGridLayout *gridLayout_13;
    QFrame *frame_6;
    QGridLayout *gridLayout_22;
    QPushButton *pushButton_Deep;
    QLineEdit *lineEdit_DeepPath;
    QFrame *line_5;
    QListWidget *listWidget_Deep;
    QFrame *line_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_shaftInfo_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_keyMin;
    QDoubleSpinBox *doubleSpinBox_keyMin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_whiteBalance_R;
    QSpinBox *spinBox_whiteBalance_R;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_whiteBalance_G;
    QSpinBox *spinBox_whiteBalance_G;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_returnSpeed;
    QSpinBox *spinBox_returnSpeed;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_keyMax;
    QDoubleSpinBox *doubleSpinBox_keyMax;
    QPushButton *pushButton_keyMaxorMinValue;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_whiteBalance_B;
    QSpinBox *spinBox_whiteBalance_B;
    QFrame *line;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *GY_GenerateBinFile)
    {
        if (GY_GenerateBinFile->objectName().isEmpty())
            GY_GenerateBinFile->setObjectName("GY_GenerateBinFile");
        GY_GenerateBinFile->resize(1104, 511);
        gridLayout_2 = new QGridLayout(GY_GenerateBinFile);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setVerticalSpacing(7);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GY_GenerateBinFile);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(7);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1102, 509));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(11);
        font.setBold(true);
        scrollAreaWidgetContents->setFont(font);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 10, 0, 0);
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(10);
        font1.setBold(false);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"            border: 1px solid #C0C0C0;\n"
"           background: white;\n"
"        }\n"
"        /* \346\234\252\351\200\211\344\270\255\347\232\204\346\240\207\347\255\276\351\241\265\346\240\267\345\274\217*/\n"
"        QTabBar::tab {\n"
"            background: #E0E0E0;\n"
"            color: black;\n"
"            border: 1px solid #C0C0C0;\n"
"            border-bottom-color: #C0C0C0;\n"
"            border-top-left-radius: 4px;\n"
"            border-top-right-radius: 4px;\n"
"            min-width: 6ex;\n"
"            padding: 2px;\n"
"        }\n"
"        /*\351\200\211\344\270\255\347\232\204\346\240\207\347\255\276\351\241\265\346\240\267\345\274\217*/\n"
"        QTabBar::tab:selected {\n"
"            background: #4A86E8;\n"
"            color: white;\n"
"            border-color: #4A86E8;\n"
"            border-bottom-color: #4A86E8;\n"
"        }\n"
"        /*\351\274\240\346\240\207\346\202\254\345\201\234\347\232\204\346\240\207\347\255\276\351\241\265\346\240\267\345"
                        "\274\217*/\n"
"        QTabBar::tab:!selected:hover {\n"
"            background: #6AA1F8;\n"
"            color: white;\n"
"        }"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	color: rgb(200, 200, 174);\n"
"	background-color: rgb(27, 213, 116);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"} \n"
"\n"
"QPushButton:pressed{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"} "));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setHorizontalSpacing(7);
        gridLayout_6->setVerticalSpacing(1);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        gridLayout_14 = new QGridLayout(widget_2);
        gridLayout_14->setObjectName("gridLayout_14");
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName("lineEdit");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setBold(true);
        lineEdit->setFont(font2);
        lineEdit->setReadOnly(true);

        gridLayout_14->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(150, 25));
        pushButton->setMaximumSize(QSize(150, 25));
        pushButton->setFont(font);

        gridLayout_14->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_6->addWidget(widget_2, 0, 0, 1, 1);

        scrollArea_3 = new QScrollArea(tab);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setStyleSheet(QString::fromUtf8(""));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 1098, 435));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        scrollArea_4 = new QScrollArea(scrollAreaWidgetContents_3);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 360, 433));
        gridLayout_10 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        listWidget_Dynamic = new QListWidget(scrollAreaWidgetContents_4);
        listWidget_Dynamic->setObjectName("listWidget_Dynamic");
        listWidget_Dynamic->setFrameShape(QFrame::Shape::Box);

        gridLayout_10->addWidget(listWidget_Dynamic, 1, 0, 1, 1);

        frame_4 = new QFrame(scrollAreaWidgetContents_4);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_9 = new QGridLayout(frame_4);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        lineEdit_DynamicPath = new QLineEdit(frame_4);
        lineEdit_DynamicPath->setObjectName("lineEdit_DynamicPath");
        lineEdit_DynamicPath->setFont(font2);
        lineEdit_DynamicPath->setEchoMode(QLineEdit::EchoMode::Normal);
        lineEdit_DynamicPath->setReadOnly(true);
        lineEdit_DynamicPath->setClearButtonEnabled(false);

        gridLayout_9->addWidget(lineEdit_DynamicPath, 2, 1, 1, 1);

        pushButton_Dynamic = new QPushButton(frame_4);
        pushButton_Dynamic->setObjectName("pushButton_Dynamic");
        pushButton_Dynamic->setMinimumSize(QSize(0, 25));
        pushButton_Dynamic->setMaximumSize(QSize(16777215, 25));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(12);
        font3.setBold(true);
        pushButton_Dynamic->setFont(font3);
        pushButton_Dynamic->setFlat(false);

        gridLayout_9->addWidget(pushButton_Dynamic, 0, 1, 1, 1);

        line_4 = new QFrame(frame_4);
        line_4->setObjectName("line_4");
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 133, 255);"));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_9->addWidget(line_4, 1, 1, 1, 1);


        gridLayout_10->addWidget(frame_4, 0, 0, 1, 1);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        gridLayout_8->addWidget(scrollArea_4, 0, 1, 1, 1);

        scrollArea_5 = new QScrollArea(scrollAreaWidgetContents_3);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName("scrollAreaWidgetContents_5");
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 359, 433));
        gridLayout_12 = new QGridLayout(scrollAreaWidgetContents_5);
        gridLayout_12->setObjectName("gridLayout_12");
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(scrollAreaWidgetContents_5);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_11 = new QGridLayout(frame_5);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton_Static = new QPushButton(frame_5);
        pushButton_Static->setObjectName("pushButton_Static");
        pushButton_Static->setMinimumSize(QSize(0, 25));
        pushButton_Static->setMaximumSize(QSize(16777215, 25));
        pushButton_Static->setFont(font3);
        pushButton_Static->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Static{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"}\n"
"\n"
"QPushButton#pushButton_Static:hover{\n"
"	color: rgb(200, 200, 174);\n"
"	background-color: rgb(27, 213, 116);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"} \n"
"QPushButton#pushButton_Static:pressed{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(7, 193, 96);\n"
"	border-radius:5px;  /*\345\234\206\350\247\222*/\n"
"} "));

        gridLayout_11->addWidget(pushButton_Static, 0, 0, 1, 1);

        lineEdit_StaticPath = new QLineEdit(frame_5);
        lineEdit_StaticPath->setObjectName("lineEdit_StaticPath");
        lineEdit_StaticPath->setFont(font2);
        lineEdit_StaticPath->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_StaticPath, 2, 0, 1, 1);

        line_3 = new QFrame(frame_5);
        line_3->setObjectName("line_3");
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 133, 255);"));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_11->addWidget(line_3, 1, 0, 1, 1);


        gridLayout_12->addWidget(frame_5, 0, 0, 1, 1);

        listWidget_Static = new QListWidget(scrollAreaWidgetContents_5);
        listWidget_Static->setObjectName("listWidget_Static");
        listWidget_Static->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget_Static->setFrameShape(QFrame::Shape::Box);

        gridLayout_12->addWidget(listWidget_Static, 1, 0, 1, 1);

        scrollArea_5->setWidget(scrollAreaWidgetContents_5);

        gridLayout_8->addWidget(scrollArea_5, 0, 0, 1, 1);

        scrollArea_6 = new QScrollArea(scrollAreaWidgetContents_3);
        scrollArea_6->setObjectName("scrollArea_6");
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName("scrollAreaWidgetContents_6");
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 359, 433));
        gridLayout_13 = new QGridLayout(scrollAreaWidgetContents_6);
        gridLayout_13->setObjectName("gridLayout_13");
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(scrollAreaWidgetContents_6);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_22 = new QGridLayout(frame_6);
        gridLayout_22->setObjectName("gridLayout_22");
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        pushButton_Deep = new QPushButton(frame_6);
        pushButton_Deep->setObjectName("pushButton_Deep");
        pushButton_Deep->setMinimumSize(QSize(0, 25));
        pushButton_Deep->setMaximumSize(QSize(16777215, 25));
        pushButton_Deep->setFont(font3);

        gridLayout_22->addWidget(pushButton_Deep, 0, 1, 1, 1);

        lineEdit_DeepPath = new QLineEdit(frame_6);
        lineEdit_DeepPath->setObjectName("lineEdit_DeepPath");
        lineEdit_DeepPath->setFont(font2);
        lineEdit_DeepPath->setFrame(true);
        lineEdit_DeepPath->setDragEnabled(false);
        lineEdit_DeepPath->setReadOnly(true);

        gridLayout_22->addWidget(lineEdit_DeepPath, 2, 1, 1, 1);

        line_5 = new QFrame(frame_6);
        line_5->setObjectName("line_5");
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 133, 255);"));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_22->addWidget(line_5, 1, 1, 1, 1);


        gridLayout_13->addWidget(frame_6, 0, 0, 1, 1);

        listWidget_Deep = new QListWidget(scrollAreaWidgetContents_6);
        listWidget_Deep->setObjectName("listWidget_Deep");
        listWidget_Deep->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listWidget_Deep->setFrameShape(QFrame::Shape::Box);

        gridLayout_13->addWidget(listWidget_Deep, 1, 0, 1, 1);

        scrollArea_6->setWidget(scrollAreaWidgetContents_6);

        gridLayout_8->addWidget(scrollArea_6, 0, 2, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_6->addWidget(scrollArea_3, 2, 0, 1, 1);

        line_2 = new QFrame(tab);
        line_2->setObjectName("line_2");
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 133, 255);"));
        line_2->setLineWidth(1);
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_6->addWidget(line_2, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1098, 468));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setObjectName("gridLayout_7");
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(220, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(9);
        font4.setBold(true);
        groupBox->setFont(font4);
        groupBox->setMouseTracking(false);
        groupBox->setTabletTracking(false);
        groupBox->setAcceptDrops(false);
        groupBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_shaftInfo_2 = new QLabel(groupBox);
        label_shaftInfo_2->setObjectName("label_shaftInfo_2");
        label_shaftInfo_2->setMaximumSize(QSize(250, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font5.setPointSize(10);
        font5.setBold(true);
        label_shaftInfo_2->setFont(font5);
        label_shaftInfo_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_shaftInfo_2);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font5);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(comboBox);


        gridLayout_4->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_keyMin = new QLabel(groupBox);
        label_keyMin->setObjectName("label_keyMin");
        label_keyMin->setFont(font5);
        label_keyMin->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_keyMin);

        doubleSpinBox_keyMin = new QDoubleSpinBox(groupBox);
        doubleSpinBox_keyMin->setObjectName("doubleSpinBox_keyMin");
        doubleSpinBox_keyMin->setFont(font5);
        doubleSpinBox_keyMin->setValue(0.200000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_keyMin);


        gridLayout_4->addLayout(horizontalLayout_3, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_whiteBalance_R = new QLabel(groupBox);
        label_whiteBalance_R->setObjectName("label_whiteBalance_R");
        label_whiteBalance_R->setMaximumSize(QSize(250, 16777215));
        label_whiteBalance_R->setFont(font5);

        horizontalLayout_6->addWidget(label_whiteBalance_R);

        spinBox_whiteBalance_R = new QSpinBox(groupBox);
        spinBox_whiteBalance_R->setObjectName("spinBox_whiteBalance_R");
        spinBox_whiteBalance_R->setFont(font5);
        spinBox_whiteBalance_R->setMaximum(255);
        spinBox_whiteBalance_R->setValue(255);
        spinBox_whiteBalance_R->setDisplayIntegerBase(10);

        horizontalLayout_6->addWidget(spinBox_whiteBalance_R);


        gridLayout_4->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_whiteBalance_G = new QLabel(groupBox);
        label_whiteBalance_G->setObjectName("label_whiteBalance_G");
        label_whiteBalance_G->setMaximumSize(QSize(250, 16777215));
        label_whiteBalance_G->setFont(font5);

        horizontalLayout_5->addWidget(label_whiteBalance_G);

        spinBox_whiteBalance_G = new QSpinBox(groupBox);
        spinBox_whiteBalance_G->setObjectName("spinBox_whiteBalance_G");
        spinBox_whiteBalance_G->setFont(font5);
        spinBox_whiteBalance_G->setMaximum(255);
        spinBox_whiteBalance_G->setValue(117);

        horizontalLayout_5->addWidget(spinBox_whiteBalance_G);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_returnSpeed = new QLabel(groupBox);
        label_returnSpeed->setObjectName("label_returnSpeed");
        label_returnSpeed->setMaximumSize(QSize(250, 16777215));
        label_returnSpeed->setFont(font5);

        horizontalLayout_7->addWidget(label_returnSpeed);

        spinBox_returnSpeed = new QSpinBox(groupBox);
        spinBox_returnSpeed->setObjectName("spinBox_returnSpeed");
        spinBox_returnSpeed->setFont(font5);
        spinBox_returnSpeed->setMinimum(1);
        spinBox_returnSpeed->setMaximum(2);

        horizontalLayout_7->addWidget(spinBox_returnSpeed);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_keyMax = new QLabel(groupBox);
        label_keyMax->setObjectName("label_keyMax");
        label_keyMax->setFont(font5);
        label_keyMax->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_keyMax);

        doubleSpinBox_keyMax = new QDoubleSpinBox(groupBox);
        doubleSpinBox_keyMax->setObjectName("doubleSpinBox_keyMax");
        doubleSpinBox_keyMax->setFont(font5);
        doubleSpinBox_keyMax->setValue(1.200000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_keyMax);


        gridLayout_4->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        pushButton_keyMaxorMinValue = new QPushButton(groupBox);
        pushButton_keyMaxorMinValue->setObjectName("pushButton_keyMaxorMinValue");
        pushButton_keyMaxorMinValue->setFont(font3);

        gridLayout_4->addWidget(pushButton_keyMaxorMinValue, 8, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_whiteBalance_B = new QLabel(groupBox);
        label_whiteBalance_B->setObjectName("label_whiteBalance_B");
        label_whiteBalance_B->setMaximumSize(QSize(250, 16777215));
        label_whiteBalance_B->setFont(font5);

        horizontalLayout_4->addWidget(label_whiteBalance_B);

        spinBox_whiteBalance_B = new QSpinBox(groupBox);
        spinBox_whiteBalance_B->setObjectName("spinBox_whiteBalance_B");
        spinBox_whiteBalance_B->setFont(font5);
        spinBox_whiteBalance_B->setMaximum(255);
        spinBox_whiteBalance_B->setValue(87);

        horizontalLayout_4->addWidget(spinBox_whiteBalance_B);


        gridLayout_4->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_4->addWidget(line, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(groupBox_2, 0, 1, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_5->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(GY_GenerateBinFile);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GY_GenerateBinFile);
    } // setupUi

    void retranslateUi(QWidget *GY_GenerateBinFile)
    {
        GY_GenerateBinFile->setWindowTitle(QCoreApplication::translate("GY_GenerateBinFile", "Form", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QCoreApplication::translate("GY_GenerateBinFile", "\345\274\200\346\234\272\345\212\250\347\224\273\345\234\260\345\235\200", nullptr));
        pushButton->setText(QCoreApplication::translate("GY_GenerateBinFile", "\345\274\200\346\234\272\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        lineEdit_DynamicPath->setText(QCoreApplication::translate("GY_GenerateBinFile", "\345\212\250\346\200\201\345\212\250\347\224\273\345\234\260\345\235\200", nullptr));
        lineEdit_DynamicPath->setPlaceholderText(QString());
        pushButton_Dynamic->setText(QCoreApplication::translate("GY_GenerateBinFile", "\350\257\273\345\217\226\345\212\250\346\200\201\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        pushButton_Static->setText(QCoreApplication::translate("GY_GenerateBinFile", "\350\257\273\345\217\226\351\235\231\346\200\201\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        lineEdit_StaticPath->setText(QCoreApplication::translate("GY_GenerateBinFile", "\351\235\231\346\200\201\345\212\250\347\224\273\345\234\260\345\235\200", nullptr));
        pushButton_Deep->setText(QCoreApplication::translate("GY_GenerateBinFile", "\350\257\273\345\217\226\346\267\261\345\272\246\345\212\250\347\224\273\346\226\207\344\273\266", nullptr));
        lineEdit_DeepPath->setText(QCoreApplication::translate("GY_GenerateBinFile", "\346\267\261\345\272\246\345\212\250\347\224\273\345\234\260\345\235\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GY_GenerateBinFile", "\345\212\250\347\224\273\346\216\222\345\272\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GY_GenerateBinFile", "\345\205\254\346\234\211\344\277\241\346\201\257", nullptr));
        label_shaftInfo_2->setText(QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223A(\351\273\230\350\256\244)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223B", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223C", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223D", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("GY_GenerateBinFile", "\350\275\264\344\275\223E", nullptr));

        label_keyMin->setText(QCoreApplication::translate("GY_GenerateBinFile", "\346\214\211\351\224\256\346\234\200\345\260\217\345\200\274", nullptr));
        label_whiteBalance_R->setText(QCoreApplication::translate("GY_GenerateBinFile", "\347\231\275\345\271\263\350\241\241R", nullptr));
        label_whiteBalance_G->setText(QCoreApplication::translate("GY_GenerateBinFile", "\347\231\275\345\271\263\350\241\241G", nullptr));
        label_returnSpeed->setText(QCoreApplication::translate("GY_GenerateBinFile", "\345\233\236\346\212\245\347\216\207", nullptr));
        label_keyMax->setText(QCoreApplication::translate("GY_GenerateBinFile", "\346\214\211\351\224\256\346\234\200\345\244\247\345\200\274", nullptr));
        pushButton_keyMaxorMinValue->setText(QCoreApplication::translate("GY_GenerateBinFile", "\347\241\256\350\256\244\346\214\211\351\224\256\351\273\230\350\256\244\345\200\274", nullptr));
        label_whiteBalance_B->setText(QCoreApplication::translate("GY_GenerateBinFile", "\347\231\275\345\271\263\350\241\241B", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GY_GenerateBinFile", "\351\224\256\350\275\264\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("GY_GenerateBinFile", "\344\277\241\346\201\257\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GY_GenerateBinFile: public Ui_GY_GenerateBinFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GY_GENERATEBINFILE_H
