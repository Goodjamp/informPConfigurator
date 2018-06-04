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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonOpenDevice;
    QPushButton *pushButtonCloseDevice;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_8;
    QTabWidget *tabWidget;
    QWidget *tab_Modbus;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelModbusStatus;
    QLineEdit *lineEditModbusStatus;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelModbusBoadrate;
    QComboBox *comboBoxModbusBoadrate;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelModbusParity;
    QComboBox *comboBoxModbusParity;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelModbusAddress;
    QComboBox *comboBoxModbusAddress;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QWidget *tab_FRQMetering;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelFrqMeteringStatus;
    QLineEdit *lineEditFrqMeteringStatus;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelFrqMeteringCorrection;
    QComboBox *comboBoxMeteringCorrection;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_Clock;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelClockStatus;
    QLineEdit *lineEditClockStatus;
    QSpacerItem *horizontalSpacer_12;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelClockCorrection;
    QComboBox *comboBoxClockCorrection;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_LCD;
    QVBoxLayout *verticalLayout_6;
    QFrame *frameHeadOfLCD;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_8;
    QWidget *tab_Monitoring;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_25;
    QFrame *line_8;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_21;
    QLabel *label_26;
    QLineEdit *lineEdit_11;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QFrame *line_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_15;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_16;
    QFrame *line_6;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLabel *label_23;
    QLineEdit *lineEdit_10;
    QLabel *label_24;
    QLabel *label_21;
    QLabel *label_17;
    QLineEdit *lineEdit_2;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_18;
    QFrame *line_7;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QLineEdit *lineEdit_4;
    QLabel *label_20;
    QLabel *label_4;
    QLabel *label_19;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(984, 607);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonOpenDevice = new QPushButton(centralWidget);
        pushButtonOpenDevice->setObjectName(QStringLiteral("pushButtonOpenDevice"));
        pushButtonOpenDevice->setMinimumSize(QSize(100, 0));
        pushButtonOpenDevice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonOpenDevice);

        pushButtonCloseDevice = new QPushButton(centralWidget);
        pushButtonCloseDevice->setObjectName(QStringLiteral("pushButtonCloseDevice"));
        pushButtonCloseDevice->setMinimumSize(QSize(100, 0));
        pushButtonCloseDevice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButtonCloseDevice);

        horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(150, 40));
        pushButton->setMaximumSize(QSize(150, 40));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);

        horizontalLayout_10->addWidget(pushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 40));
        pushButton_2->setMaximumSize(QSize(100, 40));
        pushButton_2->setFont(font);

        horizontalLayout_10->addWidget(pushButton_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(600, 200));
        tabWidget->setMaximumSize(QSize(2000, 2000));
        tabWidget->setIconSize(QSize(30, 30));
        tab_Modbus = new QWidget();
        tab_Modbus->setObjectName(QStringLiteral("tab_Modbus"));
        verticalLayout_2 = new QVBoxLayout(tab_Modbus);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelModbusStatus = new QLabel(tab_Modbus);
        labelModbusStatus->setObjectName(QStringLiteral("labelModbusStatus"));
        labelModbusStatus->setMinimumSize(QSize(80, 20));
        labelModbusStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_5->addWidget(labelModbusStatus);

        lineEditModbusStatus = new QLineEdit(tab_Modbus);
        lineEditModbusStatus->setObjectName(QStringLiteral("lineEditModbusStatus"));
        lineEditModbusStatus->setMinimumSize(QSize(80, 20));
        lineEditModbusStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_5->addWidget(lineEditModbusStatus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line = new QFrame(tab_Modbus);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 20));
        line->setMaximumSize(QSize(16777215, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelModbusBoadrate = new QLabel(tab_Modbus);
        labelModbusBoadrate->setObjectName(QStringLiteral("labelModbusBoadrate"));
        labelModbusBoadrate->setMinimumSize(QSize(100, 20));
        labelModbusBoadrate->setMaximumSize(QSize(100, 20));

        horizontalLayout_6->addWidget(labelModbusBoadrate);

        comboBoxModbusBoadrate = new QComboBox(tab_Modbus);
        comboBoxModbusBoadrate->setObjectName(QStringLiteral("comboBoxModbusBoadrate"));
        comboBoxModbusBoadrate->setMinimumSize(QSize(100, 20));
        comboBoxModbusBoadrate->setMaximumSize(QSize(100, 20));

        horizontalLayout_6->addWidget(comboBoxModbusBoadrate);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelModbusParity = new QLabel(tab_Modbus);
        labelModbusParity->setObjectName(QStringLiteral("labelModbusParity"));
        labelModbusParity->setMinimumSize(QSize(100, 20));
        labelModbusParity->setMaximumSize(QSize(100, 20));

        horizontalLayout_7->addWidget(labelModbusParity);

        comboBoxModbusParity = new QComboBox(tab_Modbus);
        comboBoxModbusParity->setObjectName(QStringLiteral("comboBoxModbusParity"));
        comboBoxModbusParity->setMinimumSize(QSize(100, 20));
        comboBoxModbusParity->setMaximumSize(QSize(100, 20));

        horizontalLayout_7->addWidget(comboBoxModbusParity);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelModbusAddress = new QLabel(tab_Modbus);
        labelModbusAddress->setObjectName(QStringLiteral("labelModbusAddress"));
        labelModbusAddress->setMinimumSize(QSize(100, 20));
        labelModbusAddress->setMaximumSize(QSize(100, 20));

        horizontalLayout_8->addWidget(labelModbusAddress);

        comboBoxModbusAddress = new QComboBox(tab_Modbus);
        comboBoxModbusAddress->setObjectName(QStringLiteral("comboBoxModbusAddress"));
        comboBoxModbusAddress->setMinimumSize(QSize(100, 20));
        comboBoxModbusAddress->setMaximumSize(QSize(100, 20));

        horizontalLayout_8->addWidget(comboBoxModbusAddress);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_Modbus, QString());
        tab_FRQMetering = new QWidget();
        tab_FRQMetering->setObjectName(QStringLiteral("tab_FRQMetering"));
        verticalLayout_3 = new QVBoxLayout(tab_FRQMetering);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelFrqMeteringStatus = new QLabel(tab_FRQMetering);
        labelFrqMeteringStatus->setObjectName(QStringLiteral("labelFrqMeteringStatus"));
        labelFrqMeteringStatus->setMinimumSize(QSize(80, 20));
        labelFrqMeteringStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_11->addWidget(labelFrqMeteringStatus);

        lineEditFrqMeteringStatus = new QLineEdit(tab_FRQMetering);
        lineEditFrqMeteringStatus->setObjectName(QStringLiteral("lineEditFrqMeteringStatus"));
        lineEditFrqMeteringStatus->setMinimumSize(QSize(80, 20));
        lineEditFrqMeteringStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_11->addWidget(lineEditFrqMeteringStatus);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_11);

        line_3 = new QFrame(tab_FRQMetering);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setMinimumSize(QSize(0, 20));
        line_3->setMaximumSize(QSize(16777215, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelFrqMeteringCorrection = new QLabel(tab_FRQMetering);
        labelFrqMeteringCorrection->setObjectName(QStringLiteral("labelFrqMeteringCorrection"));
        labelFrqMeteringCorrection->setMinimumSize(QSize(100, 20));
        labelFrqMeteringCorrection->setMaximumSize(QSize(100, 20));

        horizontalLayout_12->addWidget(labelFrqMeteringCorrection);

        comboBoxMeteringCorrection = new QComboBox(tab_FRQMetering);
        comboBoxMeteringCorrection->setObjectName(QStringLiteral("comboBoxMeteringCorrection"));
        comboBoxMeteringCorrection->setMinimumSize(QSize(100, 20));
        comboBoxMeteringCorrection->setMaximumSize(QSize(100, 20));

        horizontalLayout_12->addWidget(comboBoxMeteringCorrection);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);


        verticalLayout_3->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_FRQMetering, QString());
        tab_Clock = new QWidget();
        tab_Clock->setObjectName(QStringLiteral("tab_Clock"));
        verticalLayout_5 = new QVBoxLayout(tab_Clock);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        labelClockStatus = new QLabel(tab_Clock);
        labelClockStatus->setObjectName(QStringLiteral("labelClockStatus"));
        labelClockStatus->setMinimumSize(QSize(80, 20));
        labelClockStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_13->addWidget(labelClockStatus);

        lineEditClockStatus = new QLineEdit(tab_Clock);
        lineEditClockStatus->setObjectName(QStringLiteral("lineEditClockStatus"));
        lineEditClockStatus->setMinimumSize(QSize(80, 20));
        lineEditClockStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_13->addWidget(lineEditClockStatus);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);


        verticalLayout_5->addLayout(horizontalLayout_13);

        line_4 = new QFrame(tab_Clock);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setMinimumSize(QSize(0, 20));
        line_4->setMaximumSize(QSize(16777215, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        labelClockCorrection = new QLabel(tab_Clock);
        labelClockCorrection->setObjectName(QStringLiteral("labelClockCorrection"));
        labelClockCorrection->setMinimumSize(QSize(100, 20));
        labelClockCorrection->setMaximumSize(QSize(100, 20));

        horizontalLayout_14->addWidget(labelClockCorrection);

        comboBoxClockCorrection = new QComboBox(tab_Clock);
        comboBoxClockCorrection->setObjectName(QStringLiteral("comboBoxClockCorrection"));
        comboBoxClockCorrection->setMinimumSize(QSize(100, 20));
        comboBoxClockCorrection->setMaximumSize(QSize(100, 20));

        horizontalLayout_14->addWidget(comboBoxClockCorrection);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_13);


        verticalLayout_5->addLayout(horizontalLayout_14);

        verticalSpacer_3 = new QSpacerItem(20, 317, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        tabWidget->addTab(tab_Clock, QString());
        tab_LCD = new QWidget();
        tab_LCD->setObjectName(QStringLiteral("tab_LCD"));
        verticalLayout_6 = new QVBoxLayout(tab_LCD);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        frameHeadOfLCD = new QFrame(tab_LCD);
        frameHeadOfLCD->setObjectName(QStringLiteral("frameHeadOfLCD"));
        frameHeadOfLCD->setFrameShape(QFrame::StyledPanel);
        frameHeadOfLCD->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frameHeadOfLCD);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, -1, 0, -1);
        label_3 = new QLabel(frameHeadOfLCD);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_17->addWidget(label_3);

        label_7 = new QLabel(frameHeadOfLCD);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(80, 0));
        label_7->setMaximumSize(QSize(80, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_7);

        label_9 = new QLabel(frameHeadOfLCD);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(80, 0));
        label_9->setMaximumSize(QSize(80, 16777215));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_9);

        label_11 = new QLabel(frameHeadOfLCD);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(80, 0));
        label_11->setMaximumSize(QSize(80, 16777215));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_11);

        label_8 = new QLabel(frameHeadOfLCD);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setMaximumSize(QSize(80, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_8);

        label_13 = new QLabel(frameHeadOfLCD);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(80, 0));
        label_13->setMaximumSize(QSize(80, 16777215));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_13);

        label_10 = new QLabel(frameHeadOfLCD);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(80, 0));
        label_10->setMaximumSize(QSize(80, 16777215));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_10);

        label_12 = new QLabel(frameHeadOfLCD);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(80, 0));
        label_12->setMaximumSize(QSize(80, 16777215));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_12);

        label_6 = new QLabel(frameHeadOfLCD);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setMaximumSize(QSize(80, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_6);

        label_5 = new QLabel(frameHeadOfLCD);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setMaximumSize(QSize(80, 16777215));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_5);


        verticalLayout_6->addWidget(frameHeadOfLCD);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_8);

        tabWidget->addTab(tab_LCD, QString());
        tab_Monitoring = new QWidget();
        tab_Monitoring->setObjectName(QStringLiteral("tab_Monitoring"));
        horizontalLayout = new QHBoxLayout(tab_Monitoring);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_25 = new QLabel(tab_Monitoring);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_25);

        line_8 = new QFrame(tab_Monitoring);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_8);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_21, 0, 3, 1, 1);

        label_26 = new QLabel(tab_Monitoring);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(100, 20));
        label_26->setMaximumSize(QSize(20000, 20));

        gridLayout_4->addWidget(label_26, 0, 1, 1, 1);

        lineEdit_11 = new QLineEdit(tab_Monitoring);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMinimumSize(QSize(50, 20));
        lineEdit_11->setMaximumSize(QSize(50, 20));
        lineEdit_11->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_11, 0, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_22, 0, 0, 1, 1);


        verticalLayout_8->addLayout(gridLayout_4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_7);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label = new QLabel(tab_Monitoring);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label);

        line_5 = new QFrame(tab_Monitoring);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 0, 3, 1, 1);

        label_15 = new QLabel(tab_Monitoring);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(100, 20));
        label_15->setMaximumSize(QSize(20000, 20));

        gridLayout->addWidget(label_15, 0, 1, 1, 1);

        lineEdit = new QLineEdit(tab_Monitoring);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(50, 20));
        lineEdit->setMaximumSize(QSize(50, 20));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_16 = new QLabel(tab_Monitoring);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_16);

        line_6 = new QFrame(tab_Monitoring);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_7 = new QLineEdit(tab_Monitoring);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setMinimumSize(QSize(50, 20));
        lineEdit_7->setMaximumSize(QSize(50, 20));
        lineEdit_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_7->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_7, 1, 2, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 0, 3, 1, 1);

        lineEdit_8 = new QLineEdit(tab_Monitoring);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMinimumSize(QSize(50, 20));
        lineEdit_8->setMaximumSize(QSize(50, 20));
        lineEdit_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_8->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_8, 2, 2, 1, 1);

        lineEdit_9 = new QLineEdit(tab_Monitoring);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(50, 20));
        lineEdit_9->setMaximumSize(QSize(50, 20));
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_9->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_9, 3, 2, 1, 1);

        label_23 = new QLabel(tab_Monitoring);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(60, 20));
        label_23->setMaximumSize(QSize(60, 20));

        gridLayout_2->addWidget(label_23, 3, 1, 1, 1);

        lineEdit_10 = new QLineEdit(tab_Monitoring);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setMinimumSize(QSize(50, 20));
        lineEdit_10->setMaximumSize(QSize(50, 20));
        lineEdit_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_10->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_10, 4, 2, 1, 1);

        label_24 = new QLabel(tab_Monitoring);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(60, 20));
        label_24->setMaximumSize(QSize(60, 20));

        gridLayout_2->addWidget(label_24, 4, 1, 1, 1);

        label_21 = new QLabel(tab_Monitoring);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(60, 20));
        label_21->setMaximumSize(QSize(60, 20));

        gridLayout_2->addWidget(label_21, 1, 1, 1, 1);

        label_17 = new QLabel(tab_Monitoring);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(60, 20));
        label_17->setMaximumSize(QSize(60, 20));

        gridLayout_2->addWidget(label_17, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(tab_Monitoring);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(50, 20));
        lineEdit_2->setMaximumSize(QSize(50, 20));
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_2, 0, 2, 1, 1);

        label_22 = new QLabel(tab_Monitoring);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(60, 20));
        label_22->setMaximumSize(QSize(60, 20));

        gridLayout_2->addWidget(label_22, 2, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_19, 0, 0, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_18 = new QLabel(tab_Monitoring);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_18);

        line_7 = new QFrame(tab_Monitoring);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_17, 0, 3, 1, 1);

        lineEdit_6 = new QLineEdit(tab_Monitoring);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(50, 20));
        lineEdit_6->setMaximumSize(QSize(50, 20));
        lineEdit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_6->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_6, 3, 2, 1, 1);

        lineEdit_5 = new QLineEdit(tab_Monitoring);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(50, 20));
        lineEdit_5->setMaximumSize(QSize(50, 20));
        lineEdit_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_5->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_5, 2, 2, 1, 1);

        label_14 = new QLabel(tab_Monitoring);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(120, 20));
        label_14->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_14, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(tab_Monitoring);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(50, 20));
        lineEdit_4->setMaximumSize(QSize(50, 20));
        lineEdit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_4->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_4, 1, 2, 1, 1);

        label_20 = new QLabel(tab_Monitoring);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(120, 20));
        label_20->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_20, 3, 1, 1, 1);

        label_4 = new QLabel(tab_Monitoring);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 20));
        label_4->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_4, 1, 1, 1, 1);

        label_19 = new QLabel(tab_Monitoring);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(120, 20));
        label_19->setMaximumSize(QSize(120, 20));

        gridLayout_3->addWidget(label_19, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(tab_Monitoring);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(50, 20));
        lineEdit_3->setMaximumSize(QSize(50, 20));
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_3->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_3, 0, 2, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_20, 0, 0, 1, 1);


        verticalLayout_11->addLayout(gridLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_6);


        horizontalLayout->addLayout(verticalLayout_11);

        tabWidget->addTab(tab_Monitoring, QString());

        verticalLayout_4->addWidget(tabWidget);


        verticalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 984, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonOpenDevice->setText(QApplication::translate("MainWindow", "Open Device", nullptr));
        pushButtonCloseDevice->setText(QApplication::translate("MainWindow", "Close Device", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        labelModbusStatus->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        labelModbusBoadrate->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        labelModbusParity->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\270\321\202\320\265\321\202", nullptr));
        labelModbusAddress->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Modbus), QApplication::translate("MainWindow", "Modbus", nullptr));
        labelFrqMeteringStatus->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        labelFrqMeteringCorrection->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_FRQMetering), QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\276\320\274\320\265\321\200", nullptr));
        labelClockStatus->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        labelClockCorrection->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Clock), QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213 ", nullptr));
        label_3->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\321\213", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260, \320\241", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\275. \320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\274\320\274. \321\200\321\202. \321\201\321\202.", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\263\320\237\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_LCD), QApplication::translate("MainWindow", "\320\226\320\232\320\230", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\276\320\274\320\265\321\200", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\320\260", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214 ", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\265\320\276\320\277\320\276\321\201\321\202", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\274\320\274. \321\200\321\202. \321\201\321\202", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\263\320\237\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\275. \320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260, \320\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Monitoring), QApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
