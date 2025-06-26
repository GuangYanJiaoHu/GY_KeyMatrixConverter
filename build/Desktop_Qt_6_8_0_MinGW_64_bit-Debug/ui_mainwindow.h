/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_keyboardLayout;
    QWidget *widget_tools;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QWidget *widget_KeyboardSetting;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QWidget *widget_Animation;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QWidget *widget_GenerateBinFile;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QWidget *widget_ConvertBinFile;
    QWidget *tab_5;
    QGridLayout *gridLayout_7;
    QWidget *widget_Customize;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(953, 766);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget_keyboardLayout = new QWidget(centralwidget);
        widget_keyboardLayout->setObjectName("widget_keyboardLayout");
        widget_keyboardLayout->setMinimumSize(QSize(0, 350));
        widget_keyboardLayout->setStyleSheet(QString::fromUtf8("background-color: rgb(147, 147, 147);"));

        gridLayout->addWidget(widget_keyboardLayout, 0, 0, 1, 1);

        widget_tools = new QWidget(centralwidget);
        widget_tools->setObjectName("widget_tools");
        gridLayout_2 = new QGridLayout(widget_tools);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget = new QTabWidget(widget_tools);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        font.setBold(true);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_KeyboardSetting = new QWidget(tab);
        widget_KeyboardSetting->setObjectName("widget_KeyboardSetting");

        gridLayout_3->addWidget(widget_KeyboardSetting, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_Animation = new QWidget(tab_2);
        widget_Animation->setObjectName("widget_Animation");

        gridLayout_4->addWidget(widget_Animation, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_GenerateBinFile = new QWidget(tab_3);
        widget_GenerateBinFile->setObjectName("widget_GenerateBinFile");

        gridLayout_5->addWidget(widget_GenerateBinFile, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_ConvertBinFile = new QWidget(tab_4);
        widget_ConvertBinFile->setObjectName("widget_ConvertBinFile");

        gridLayout_6->addWidget(widget_ConvertBinFile, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_7 = new QGridLayout(tab_5);
        gridLayout_7->setObjectName("gridLayout_7");
        widget_Customize = new QWidget(tab_5);
        widget_Customize->setObjectName("widget_Customize");

        gridLayout_7->addWidget(widget_Customize, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget_tools, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 953, 24));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\351\224\256\347\233\230\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\212\250\347\224\273\346\223\215\344\275\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Bin\346\226\207\344\273\266\347\224\237\346\210\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Bin\346\226\207\344\273\266\350\275\254\346\215\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\345\212\250\347\224\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
