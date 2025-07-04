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
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
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
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 10, 0, 0);
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::West);
        tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(tab);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 868, 535));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_6->addWidget(scrollArea_3, 0, 0, 1, 1);

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
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 868, 535));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setObjectName("gridLayout_7");
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(220, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(9);
        font.setBold(true);
        groupBox->setFont(font);
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
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        font1.setBold(true);
        label_shaftInfo_2->setFont(font1);
        label_shaftInfo_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_shaftInfo_2);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(comboBox);


        gridLayout_4->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_keyMin = new QLabel(groupBox);
        label_keyMin->setObjectName("label_keyMin");
        label_keyMin->setFont(font1);
        label_keyMin->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_keyMin);

        doubleSpinBox_keyMin = new QDoubleSpinBox(groupBox);
        doubleSpinBox_keyMin->setObjectName("doubleSpinBox_keyMin");
        doubleSpinBox_keyMin->setFont(font1);
        doubleSpinBox_keyMin->setValue(0.200000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_keyMin);


        gridLayout_4->addLayout(horizontalLayout_3, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_whiteBalance_R = new QLabel(groupBox);
        label_whiteBalance_R->setObjectName("label_whiteBalance_R");
        label_whiteBalance_R->setMaximumSize(QSize(250, 16777215));
        label_whiteBalance_R->setFont(font1);

        horizontalLayout_6->addWidget(label_whiteBalance_R);

        spinBox_whiteBalance_R = new QSpinBox(groupBox);
        spinBox_whiteBalance_R->setObjectName("spinBox_whiteBalance_R");
        spinBox_whiteBalance_R->setFont(font1);
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
        label_whiteBalance_G->setFont(font1);

        horizontalLayout_5->addWidget(label_whiteBalance_G);

        spinBox_whiteBalance_G = new QSpinBox(groupBox);
        spinBox_whiteBalance_G->setObjectName("spinBox_whiteBalance_G");
        spinBox_whiteBalance_G->setFont(font1);
        spinBox_whiteBalance_G->setMaximum(255);
        spinBox_whiteBalance_G->setValue(117);

        horizontalLayout_5->addWidget(spinBox_whiteBalance_G);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_returnSpeed = new QLabel(groupBox);
        label_returnSpeed->setObjectName("label_returnSpeed");
        label_returnSpeed->setMaximumSize(QSize(250, 16777215));
        label_returnSpeed->setFont(font1);

        horizontalLayout_7->addWidget(label_returnSpeed);

        spinBox_returnSpeed = new QSpinBox(groupBox);
        spinBox_returnSpeed->setObjectName("spinBox_returnSpeed");
        spinBox_returnSpeed->setFont(font1);
        spinBox_returnSpeed->setMinimum(1);
        spinBox_returnSpeed->setMaximum(2);

        horizontalLayout_7->addWidget(spinBox_returnSpeed);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_keyMax = new QLabel(groupBox);
        label_keyMax->setObjectName("label_keyMax");
        label_keyMax->setFont(font1);
        label_keyMax->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_keyMax);

        doubleSpinBox_keyMax = new QDoubleSpinBox(groupBox);
        doubleSpinBox_keyMax->setObjectName("doubleSpinBox_keyMax");
        doubleSpinBox_keyMax->setFont(font1);
        doubleSpinBox_keyMax->setValue(1.200000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_keyMax);


        gridLayout_4->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        pushButton_keyMaxorMinValue = new QPushButton(groupBox);
        pushButton_keyMaxorMinValue->setObjectName("pushButton_keyMaxorMinValue");

        gridLayout_4->addWidget(pushButton_keyMaxorMinValue, 8, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_whiteBalance_B = new QLabel(groupBox);
        label_whiteBalance_B->setObjectName("label_whiteBalance_B");
        label_whiteBalance_B->setMaximumSize(QSize(250, 16777215));
        label_whiteBalance_B->setFont(font1);

        horizontalLayout_4->addWidget(label_whiteBalance_B);

        spinBox_whiteBalance_B = new QSpinBox(groupBox);
        spinBox_whiteBalance_B->setObjectName("spinBox_whiteBalance_B");
        spinBox_whiteBalance_B->setFont(font1);
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

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

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
