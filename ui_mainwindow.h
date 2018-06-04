/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonGetDevice;
    QPushButton *pushButtonOpenDevice;
    QPushButton *pushButtonCloseDevice;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonReceive;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QListView *listViewDeviceList;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QListView *listVieInterfaceList;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *labelVID;
    QLabel *labelPID;
    QLabel *labelDeviceString;
    QLabel *labelInterfaceString;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *labelVIDstring;
    QLabel *labelPIDString;
    QLabel *labelDevDescrString;
    QLabel *labelInterfaceDescrString;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *tab_4;
    QListView *listViewDeviceList_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(840, 552);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 821, 526));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonGetDevice = new QPushButton(verticalLayoutWidget_2);
        pushButtonGetDevice->setObjectName(QStringLiteral("pushButtonGetDevice"));
        pushButtonGetDevice->setMinimumSize(QSize(100, 0));
        pushButtonGetDevice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonGetDevice);

        pushButtonOpenDevice = new QPushButton(verticalLayoutWidget_2);
        pushButtonOpenDevice->setObjectName(QStringLiteral("pushButtonOpenDevice"));
        pushButtonOpenDevice->setMinimumSize(QSize(100, 0));
        pushButtonOpenDevice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonOpenDevice);

        pushButtonCloseDevice = new QPushButton(verticalLayoutWidget_2);
        pushButtonCloseDevice->setObjectName(QStringLiteral("pushButtonCloseDevice"));
        pushButtonCloseDevice->setMinimumSize(QSize(100, 0));
        pushButtonCloseDevice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonCloseDevice);

        pushButtonSend = new QPushButton(verticalLayoutWidget_2);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        pushButtonSend->setMinimumSize(QSize(100, 0));
        pushButtonSend->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonSend);

        pushButtonReceive = new QPushButton(verticalLayoutWidget_2);
        pushButtonReceive->setObjectName(QStringLiteral("pushButtonReceive"));
        pushButtonReceive->setMinimumSize(QSize(100, 0));
        pushButtonReceive->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonReceive);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        listViewDeviceList = new QListView(verticalLayoutWidget_2);
        listViewDeviceList->setObjectName(QStringLiteral("listViewDeviceList"));

        verticalLayout_6->addWidget(listViewDeviceList);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_7->addWidget(label_2);

        listVieInterfaceList = new QListView(verticalLayoutWidget_2);
        listVieInterfaceList->setObjectName(QStringLiteral("listVieInterfaceList"));

        verticalLayout_7->addWidget(listVieInterfaceList);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        labelVID = new QLabel(verticalLayoutWidget_2);
        labelVID->setObjectName(QStringLiteral("labelVID"));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        labelVID->setFont(font);

        verticalLayout->addWidget(labelVID);

        labelPID = new QLabel(verticalLayoutWidget_2);
        labelPID->setObjectName(QStringLiteral("labelPID"));
        labelPID->setFont(font);

        verticalLayout->addWidget(labelPID);

        labelDeviceString = new QLabel(verticalLayoutWidget_2);
        labelDeviceString->setObjectName(QStringLiteral("labelDeviceString"));
        labelDeviceString->setFont(font);

        verticalLayout->addWidget(labelDeviceString);

        labelInterfaceString = new QLabel(verticalLayoutWidget_2);
        labelInterfaceString->setObjectName(QStringLiteral("labelInterfaceString"));
        labelInterfaceString->setFont(font);

        verticalLayout->addWidget(labelInterfaceString);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        labelVIDstring = new QLabel(verticalLayoutWidget_2);
        labelVIDstring->setObjectName(QStringLiteral("labelVIDstring"));
        labelVIDstring->setMinimumSize(QSize(200, 0));
        labelVIDstring->setMaximumSize(QSize(200, 16777215));
        labelVIDstring->setFont(font);

        verticalLayout_5->addWidget(labelVIDstring);

        labelPIDString = new QLabel(verticalLayoutWidget_2);
        labelPIDString->setObjectName(QStringLiteral("labelPIDString"));
        labelPIDString->setMinimumSize(QSize(200, 0));
        labelPIDString->setMaximumSize(QSize(200, 16777215));
        labelPIDString->setFont(font);

        verticalLayout_5->addWidget(labelPIDString);

        labelDevDescrString = new QLabel(verticalLayoutWidget_2);
        labelDevDescrString->setObjectName(QStringLiteral("labelDevDescrString"));
        labelDevDescrString->setMinimumSize(QSize(100, 0));
        labelDevDescrString->setMaximumSize(QSize(200, 16777215));
        labelDevDescrString->setFont(font);

        verticalLayout_5->addWidget(labelDevDescrString);

        labelInterfaceDescrString = new QLabel(verticalLayoutWidget_2);
        labelInterfaceDescrString->setObjectName(QStringLiteral("labelInterfaceDescrString"));
        labelInterfaceDescrString->setMinimumSize(QSize(200, 0));
        labelInterfaceDescrString->setMaximumSize(QSize(200, 16777215));
        labelInterfaceDescrString->setFont(font);

        verticalLayout_5->addWidget(labelInterfaceDescrString);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_4->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(verticalLayoutWidget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(200, 150));
        tabWidget->setMaximumSize(QSize(1000, 200));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_4->addWidget(tabWidget);

        listViewDeviceList_2 = new QListView(verticalLayoutWidget_2);
        listViewDeviceList_2->setObjectName(QStringLiteral("listViewDeviceList_2"));
        listViewDeviceList_2->setMinimumSize(QSize(0, 50));
        listViewDeviceList_2->setMaximumSize(QSize(16777215, 150));

        verticalLayout_4->addWidget(listViewDeviceList_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonGetDevice->setText(QApplication::translate("MainWindow", "Get Device List", nullptr));
        pushButtonOpenDevice->setText(QApplication::translate("MainWindow", "Open Device", nullptr));
        pushButtonCloseDevice->setText(QApplication::translate("MainWindow", "Close Device", nullptr));
        pushButtonSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        pushButtonReceive->setText(QApplication::translate("MainWindow", "Read", nullptr));
        label->setText(QApplication::translate("MainWindow", "Device List", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Interface List", nullptr));
        label_3->setText(QString());
        labelVID->setText(QApplication::translate("MainWindow", "VID:", nullptr));
        labelPID->setText(QApplication::translate("MainWindow", "PID:", nullptr));
        labelDeviceString->setText(QApplication::translate("MainWindow", "String Descriptor:", nullptr));
        labelInterfaceString->setText(QApplication::translate("MainWindow", "Interface Descriptor:", nullptr));
        label_4->setText(QString());
        labelVIDstring->setText(QApplication::translate("MainWindow", "--", nullptr));
        labelPIDString->setText(QApplication::translate("MainWindow", "--", nullptr));
        labelDevDescrString->setText(QApplication::translate("MainWindow", "--", nullptr));
        labelInterfaceDescrString->setText(QApplication::translate("MainWindow", "--", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
