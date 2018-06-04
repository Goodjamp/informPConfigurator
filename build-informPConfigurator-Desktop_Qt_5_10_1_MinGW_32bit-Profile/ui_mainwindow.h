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
#include <QtWidgets/QCheckBox>
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
    QComboBox *comboBoxFrqMeteringState;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelFrqMeteringCorrection;
    QComboBox *comboBoxFrqMeteringCorrection;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_Clock;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelClockStatus;
    QComboBox *comboBoxClockState;
    QSpacerItem *horizontalSpacer_12;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelClockCorrection;
    QComboBox *comboBoxClockCorrection;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelClockCorrection_2;
    QCheckBox *checkBoxClockSetDaylight;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_16;
    QLabel *labelClockCorrection_3;
    QComboBox *comboBoxClockSyncSource;
    QSpacerItem *horizontalSpacer_23;
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
    QWidget *widget;
    QSpacerItem *verticalSpacer_8;
    QWidget *tab_Monitoring;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_25;
    QFrame *line_8;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_22;
    QLineEdit *lineEditDevStatus;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QFrame *line_5;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *lineEditFrqMeteringFrq;
    QLabel *label_27;
    QLineEdit *lineEditFrqMeteringStatus;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_16;
    QFrame *line_6;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *lineEditClockRezMonth;
    QLabel *label_24;
    QLineEdit *lineEditClockRezDay;
    QLineEdit *lineEditClockRezHour;
    QLineEdit *lineEditClockRezMinutes;
    QLabel *label_23;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEditClockRezYear;
    QLabel *label_17;
    QLabel *label_2;
    QLineEdit *lineEditClockStatus;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_18;
    QFrame *line_7;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QLineEdit *lineEditMeteoRezhPa;
    QLineEdit *lineEditMeteoRezPressurePb;
    QLabel *label_4;
    QLabel *label_14;
    QLineEdit *lineEditMeteoRezHumidity;
    QLabel *label_20;
    QLabel *label_19;
    QLineEdit *lineEditMeteoRezTemperature;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_26;
    QLineEdit *lineEditMeteoStatus;
    QSpacerItem *verticalSpacer_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1090, 593);
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
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButtonOpenDevice->setFont(font);

        horizontalLayout_3->addWidget(pushButtonOpenDevice);

        pushButtonCloseDevice = new QPushButton(centralWidget);
        pushButtonCloseDevice->setObjectName(QStringLiteral("pushButtonCloseDevice"));
        pushButtonCloseDevice->setMinimumSize(QSize(100, 0));
        pushButtonCloseDevice->setMaximumSize(QSize(100, 16777215));
        pushButtonCloseDevice->setFont(font);

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
        horizontalLayout_10->setContentsMargins(-1, 7, -1, 7);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(150, 40));
        pushButton->setMaximumSize(QSize(150, 40));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        horizontalLayout_10->addWidget(pushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 40));
        pushButton_2->setMaximumSize(QSize(100, 40));
        pushButton_2->setFont(font1);

        horizontalLayout_10->addWidget(pushButton_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(600, 200));
        tabWidget->setMaximumSize(QSize(2000, 2000));
        tabWidget->setFont(font1);
        tabWidget->setIconSize(QSize(30, 30));
        tab_Modbus = new QWidget();
        tab_Modbus->setObjectName(QStringLiteral("tab_Modbus"));
        verticalLayout_2 = new QVBoxLayout(tab_Modbus);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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
        labelModbusBoadrate->setMinimumSize(QSize(100, 25));
        labelModbusBoadrate->setMaximumSize(QSize(100, 25));
        labelModbusBoadrate->setFont(font);

        horizontalLayout_6->addWidget(labelModbusBoadrate);

        comboBoxModbusBoadrate = new QComboBox(tab_Modbus);
        comboBoxModbusBoadrate->setObjectName(QStringLiteral("comboBoxModbusBoadrate"));
        comboBoxModbusBoadrate->setMinimumSize(QSize(100, 25));
        comboBoxModbusBoadrate->setMaximumSize(QSize(100, 25));
        comboBoxModbusBoadrate->setFont(font);

        horizontalLayout_6->addWidget(comboBoxModbusBoadrate);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelModbusParity = new QLabel(tab_Modbus);
        labelModbusParity->setObjectName(QStringLiteral("labelModbusParity"));
        labelModbusParity->setMinimumSize(QSize(100, 25));
        labelModbusParity->setMaximumSize(QSize(100, 25));
        labelModbusParity->setFont(font);

        horizontalLayout_7->addWidget(labelModbusParity);

        comboBoxModbusParity = new QComboBox(tab_Modbus);
        comboBoxModbusParity->setObjectName(QStringLiteral("comboBoxModbusParity"));
        comboBoxModbusParity->setMinimumSize(QSize(100, 25));
        comboBoxModbusParity->setMaximumSize(QSize(100, 25));
        comboBoxModbusParity->setFont(font);

        horizontalLayout_7->addWidget(comboBoxModbusParity);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelModbusAddress = new QLabel(tab_Modbus);
        labelModbusAddress->setObjectName(QStringLiteral("labelModbusAddress"));
        labelModbusAddress->setMinimumSize(QSize(100, 25));
        labelModbusAddress->setMaximumSize(QSize(100, 25));
        labelModbusAddress->setFont(font);

        horizontalLayout_8->addWidget(labelModbusAddress);

        comboBoxModbusAddress = new QComboBox(tab_Modbus);
        comboBoxModbusAddress->setObjectName(QStringLiteral("comboBoxModbusAddress"));
        comboBoxModbusAddress->setMinimumSize(QSize(100, 25));
        comboBoxModbusAddress->setMaximumSize(QSize(100, 25));
        comboBoxModbusAddress->setFont(font);

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
        labelFrqMeteringStatus->setMinimumSize(QSize(80, 25));
        labelFrqMeteringStatus->setMaximumSize(QSize(80, 25));
        labelFrqMeteringStatus->setFont(font);

        horizontalLayout_11->addWidget(labelFrqMeteringStatus);

        comboBoxFrqMeteringState = new QComboBox(tab_FRQMetering);
        comboBoxFrqMeteringState->setObjectName(QStringLiteral("comboBoxFrqMeteringState"));
        comboBoxFrqMeteringState->setMinimumSize(QSize(100, 25));
        comboBoxFrqMeteringState->setMaximumSize(QSize(100, 25));

        horizontalLayout_11->addWidget(comboBoxFrqMeteringState);

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
        labelFrqMeteringCorrection->setMinimumSize(QSize(100, 25));
        labelFrqMeteringCorrection->setMaximumSize(QSize(100, 25));
        QFont font2;
        font2.setPointSize(10);
        labelFrqMeteringCorrection->setFont(font2);

        horizontalLayout_12->addWidget(labelFrqMeteringCorrection);

        comboBoxFrqMeteringCorrection = new QComboBox(tab_FRQMetering);
        comboBoxFrqMeteringCorrection->setObjectName(QStringLiteral("comboBoxFrqMeteringCorrection"));
        comboBoxFrqMeteringCorrection->setMinimumSize(QSize(100, 25));
        comboBoxFrqMeteringCorrection->setMaximumSize(QSize(100, 25));

        horizontalLayout_12->addWidget(comboBoxFrqMeteringCorrection);

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
        labelClockStatus->setMinimumSize(QSize(80, 25));
        labelClockStatus->setMaximumSize(QSize(80, 2025));
        labelClockStatus->setFont(font2);

        horizontalLayout_13->addWidget(labelClockStatus);

        comboBoxClockState = new QComboBox(tab_Clock);
        comboBoxClockState->setObjectName(QStringLiteral("comboBoxClockState"));
        comboBoxClockState->setMinimumSize(QSize(100, 25));
        comboBoxClockState->setMaximumSize(QSize(100, 2025));
        comboBoxClockState->setFont(font2);

        horizontalLayout_13->addWidget(comboBoxClockState);

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
        labelClockCorrection->setMinimumSize(QSize(230, 25));
        labelClockCorrection->setMaximumSize(QSize(230, 25));
        labelClockCorrection->setFont(font2);

        horizontalLayout_14->addWidget(labelClockCorrection);

        comboBoxClockCorrection = new QComboBox(tab_Clock);
        comboBoxClockCorrection->setObjectName(QStringLiteral("comboBoxClockCorrection"));
        comboBoxClockCorrection->setMinimumSize(QSize(100, 25));
        comboBoxClockCorrection->setMaximumSize(QSize(100, 25));
        comboBoxClockCorrection->setFont(font2);

        horizontalLayout_14->addWidget(comboBoxClockCorrection);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_13);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        labelClockCorrection_2 = new QLabel(tab_Clock);
        labelClockCorrection_2->setObjectName(QStringLiteral("labelClockCorrection_2"));
        labelClockCorrection_2->setMinimumSize(QSize(230, 25));
        labelClockCorrection_2->setMaximumSize(QSize(230, 25));
        labelClockCorrection_2->setFont(font2);

        horizontalLayout_15->addWidget(labelClockCorrection_2);

        checkBoxClockSetDaylight = new QCheckBox(tab_Clock);
        checkBoxClockSetDaylight->setObjectName(QStringLiteral("checkBoxClockSetDaylight"));
        checkBoxClockSetDaylight->setMinimumSize(QSize(0, 25));
        checkBoxClockSetDaylight->setMaximumSize(QSize(16777215, 25));
        checkBoxClockSetDaylight->setFont(font2);

        horizontalLayout_15->addWidget(checkBoxClockSetDaylight);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_16);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        labelClockCorrection_3 = new QLabel(tab_Clock);
        labelClockCorrection_3->setObjectName(QStringLiteral("labelClockCorrection_3"));
        labelClockCorrection_3->setMinimumSize(QSize(230, 25));
        labelClockCorrection_3->setMaximumSize(QSize(230, 25));
        labelClockCorrection_3->setFont(font2);

        horizontalLayout_16->addWidget(labelClockCorrection_3);

        comboBoxClockSyncSource = new QComboBox(tab_Clock);
        comboBoxClockSyncSource->setObjectName(QStringLiteral("comboBoxClockSyncSource"));
        comboBoxClockSyncSource->setMinimumSize(QSize(100, 25));
        comboBoxClockSyncSource->setMaximumSize(QSize(100, 25));
        comboBoxClockSyncSource->setFont(font2);

        horizontalLayout_16->addWidget(comboBoxClockSyncSource);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_23);


        verticalLayout_5->addLayout(horizontalLayout_16);

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
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_17->addWidget(label_3);

        label_7 = new QLabel(frameHeadOfLCD);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(120, 0));
        label_7->setMaximumSize(QSize(120, 16777215));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_7);

        label_9 = new QLabel(frameHeadOfLCD);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(120, 0));
        label_9->setMaximumSize(QSize(120, 16777215));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_9);

        label_11 = new QLabel(frameHeadOfLCD);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(120, 0));
        label_11->setMaximumSize(QSize(120, 16777215));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_11);

        label_8 = new QLabel(frameHeadOfLCD);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(120, 0));
        label_8->setMaximumSize(QSize(120, 16777215));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_8);

        label_13 = new QLabel(frameHeadOfLCD);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(120, 0));
        label_13->setMaximumSize(QSize(120, 16777215));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_13);

        label_10 = new QLabel(frameHeadOfLCD);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(120, 0));
        label_10->setMaximumSize(QSize(120, 16777215));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_10);

        label_12 = new QLabel(frameHeadOfLCD);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(120, 0));
        label_12->setMaximumSize(QSize(120, 16777215));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_12);

        label_6 = new QLabel(frameHeadOfLCD);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(150, 0));
        label_6->setMaximumSize(QSize(150, 16777215));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_6);

        label_5 = new QLabel(frameHeadOfLCD);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(120, 0));
        label_5->setMaximumSize(QSize(120, 16777215));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_5);

        widget = new QWidget(frameHeadOfLCD);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(30, 0));
        widget->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_17->addWidget(widget);


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
        label_25->setMinimumSize(QSize(0, 25));
        label_25->setMaximumSize(QSize(16777215, 25));
        label_25->setFont(font1);
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

        gridLayout_4->addItem(horizontalSpacer_21, 0, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_22, 0, 0, 1, 1);

        lineEditDevStatus = new QLineEdit(tab_Monitoring);
        lineEditDevStatus->setObjectName(QStringLiteral("lineEditDevStatus"));
        lineEditDevStatus->setMinimumSize(QSize(100, 25));
        lineEditDevStatus->setMaximumSize(QSize(100, 25));
        lineEditDevStatus->setReadOnly(true);

        gridLayout_4->addWidget(lineEditDevStatus, 0, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_7);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label = new QLabel(tab_Monitoring);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));
        label->setFont(font1);
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
        label_15 = new QLabel(tab_Monitoring);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(100, 25));
        label_15->setMaximumSize(QSize(20000, 25));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 1, 1, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 1, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 1, 3, 1, 1);

        lineEditFrqMeteringFrq = new QLineEdit(tab_Monitoring);
        lineEditFrqMeteringFrq->setObjectName(QStringLiteral("lineEditFrqMeteringFrq"));
        lineEditFrqMeteringFrq->setMinimumSize(QSize(50, 25));
        lineEditFrqMeteringFrq->setMaximumSize(QSize(50, 25));
        lineEditFrqMeteringFrq->setFont(font);
        lineEditFrqMeteringFrq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFrqMeteringFrq->setReadOnly(true);

        gridLayout->addWidget(lineEditFrqMeteringFrq, 1, 2, 1, 1);

        label_27 = new QLabel(tab_Monitoring);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(0, 25));
        label_27->setMaximumSize(QSize(16777215, 25));
        label_27->setFont(font2);

        gridLayout->addWidget(label_27, 0, 1, 1, 1);

        lineEditFrqMeteringStatus = new QLineEdit(tab_Monitoring);
        lineEditFrqMeteringStatus->setObjectName(QStringLiteral("lineEditFrqMeteringStatus"));
        lineEditFrqMeteringStatus->setMinimumSize(QSize(100, 25));
        lineEditFrqMeteringStatus->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(lineEditFrqMeteringStatus, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_16 = new QLabel(tab_Monitoring);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(0, 25));
        label_16->setMaximumSize(QSize(16777215, 25));
        label_16->setFont(font1);
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
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_19, 1, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 1, 3, 1, 1);

        lineEditClockRezMonth = new QLineEdit(tab_Monitoring);
        lineEditClockRezMonth->setObjectName(QStringLiteral("lineEditClockRezMonth"));
        lineEditClockRezMonth->setMinimumSize(QSize(50, 25));
        lineEditClockRezMonth->setMaximumSize(QSize(50, 25));
        lineEditClockRezMonth->setFont(font);
        lineEditClockRezMonth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClockRezMonth->setReadOnly(true);

        gridLayout_2->addWidget(lineEditClockRezMonth, 2, 2, 1, 1);

        label_24 = new QLabel(tab_Monitoring);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(60, 25));
        label_24->setMaximumSize(QSize(60, 25));
        label_24->setFont(font);

        gridLayout_2->addWidget(label_24, 5, 1, 1, 1);

        lineEditClockRezDay = new QLineEdit(tab_Monitoring);
        lineEditClockRezDay->setObjectName(QStringLiteral("lineEditClockRezDay"));
        lineEditClockRezDay->setMinimumSize(QSize(50, 25));
        lineEditClockRezDay->setMaximumSize(QSize(50, 25));
        lineEditClockRezDay->setFont(font);
        lineEditClockRezDay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClockRezDay->setReadOnly(true);

        gridLayout_2->addWidget(lineEditClockRezDay, 3, 2, 1, 1);

        lineEditClockRezHour = new QLineEdit(tab_Monitoring);
        lineEditClockRezHour->setObjectName(QStringLiteral("lineEditClockRezHour"));
        lineEditClockRezHour->setMinimumSize(QSize(50, 25));
        lineEditClockRezHour->setMaximumSize(QSize(50, 25));
        lineEditClockRezHour->setFont(font);
        lineEditClockRezHour->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClockRezHour->setReadOnly(true);

        gridLayout_2->addWidget(lineEditClockRezHour, 4, 2, 1, 1);

        lineEditClockRezMinutes = new QLineEdit(tab_Monitoring);
        lineEditClockRezMinutes->setObjectName(QStringLiteral("lineEditClockRezMinutes"));
        lineEditClockRezMinutes->setMinimumSize(QSize(50, 25));
        lineEditClockRezMinutes->setMaximumSize(QSize(50, 25));
        lineEditClockRezMinutes->setFont(font);
        lineEditClockRezMinutes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClockRezMinutes->setReadOnly(true);

        gridLayout_2->addWidget(lineEditClockRezMinutes, 5, 2, 1, 1);

        label_23 = new QLabel(tab_Monitoring);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(60, 25));
        label_23->setMaximumSize(QSize(60, 25));
        label_23->setFont(font);

        gridLayout_2->addWidget(label_23, 4, 1, 1, 1);

        label_21 = new QLabel(tab_Monitoring);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(60, 25));
        label_21->setMaximumSize(QSize(60, 25));
        label_21->setFont(font);

        gridLayout_2->addWidget(label_21, 2, 1, 1, 1);

        label_22 = new QLabel(tab_Monitoring);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(60, 25));
        label_22->setMaximumSize(QSize(60, 25));
        label_22->setFont(font);

        gridLayout_2->addWidget(label_22, 3, 1, 1, 1);

        lineEditClockRezYear = new QLineEdit(tab_Monitoring);
        lineEditClockRezYear->setObjectName(QStringLiteral("lineEditClockRezYear"));
        lineEditClockRezYear->setMinimumSize(QSize(50, 25));
        lineEditClockRezYear->setMaximumSize(QSize(50, 25));
        lineEditClockRezYear->setFont(font);
        lineEditClockRezYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClockRezYear->setReadOnly(true);

        gridLayout_2->addWidget(lineEditClockRezYear, 1, 2, 1, 1);

        label_17 = new QLabel(tab_Monitoring);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(60, 25));
        label_17->setMaximumSize(QSize(60, 25));
        label_17->setFont(font);

        gridLayout_2->addWidget(label_17, 1, 1, 1, 1);

        label_2 = new QLabel(tab_Monitoring);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 25));
        label_2->setMaximumSize(QSize(60, 25));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        lineEditClockStatus = new QLineEdit(tab_Monitoring);
        lineEditClockStatus->setObjectName(QStringLiteral("lineEditClockStatus"));
        lineEditClockStatus->setMinimumSize(QSize(100, 25));
        lineEditClockStatus->setMaximumSize(QSize(100, 25));
        lineEditClockStatus->setFont(font);

        gridLayout_2->addWidget(lineEditClockStatus, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_18 = new QLabel(tab_Monitoring);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 25));
        label_18->setMaximumSize(QSize(16777215, 25));
        label_18->setFont(font1);
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

        gridLayout_3->addItem(horizontalSpacer_17, 1, 3, 1, 1);

        lineEditMeteoRezhPa = new QLineEdit(tab_Monitoring);
        lineEditMeteoRezhPa->setObjectName(QStringLiteral("lineEditMeteoRezhPa"));
        lineEditMeteoRezhPa->setMinimumSize(QSize(50, 25));
        lineEditMeteoRezhPa->setMaximumSize(QSize(50, 25));
        lineEditMeteoRezhPa->setFont(font);
        lineEditMeteoRezhPa->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMeteoRezhPa->setReadOnly(true);

        gridLayout_3->addWidget(lineEditMeteoRezhPa, 4, 2, 1, 1);

        lineEditMeteoRezPressurePb = new QLineEdit(tab_Monitoring);
        lineEditMeteoRezPressurePb->setObjectName(QStringLiteral("lineEditMeteoRezPressurePb"));
        lineEditMeteoRezPressurePb->setMinimumSize(QSize(50, 25));
        lineEditMeteoRezPressurePb->setMaximumSize(QSize(50, 25));
        lineEditMeteoRezPressurePb->setFont(font);
        lineEditMeteoRezPressurePb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMeteoRezPressurePb->setReadOnly(true);

        gridLayout_3->addWidget(lineEditMeteoRezPressurePb, 3, 2, 1, 1);

        label_4 = new QLabel(tab_Monitoring);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 25));
        label_4->setMaximumSize(QSize(120, 25));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 2, 1, 1, 1);

        label_14 = new QLabel(tab_Monitoring);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(120, 25));
        label_14->setMaximumSize(QSize(120, 25));
        label_14->setFont(font);

        gridLayout_3->addWidget(label_14, 3, 1, 1, 1);

        lineEditMeteoRezHumidity = new QLineEdit(tab_Monitoring);
        lineEditMeteoRezHumidity->setObjectName(QStringLiteral("lineEditMeteoRezHumidity"));
        lineEditMeteoRezHumidity->setMinimumSize(QSize(50, 25));
        lineEditMeteoRezHumidity->setMaximumSize(QSize(50, 25));
        lineEditMeteoRezHumidity->setFont(font);
        lineEditMeteoRezHumidity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMeteoRezHumidity->setReadOnly(true);

        gridLayout_3->addWidget(lineEditMeteoRezHumidity, 2, 2, 1, 1);

        label_20 = new QLabel(tab_Monitoring);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(120, 25));
        label_20->setMaximumSize(QSize(120, 25));
        label_20->setFont(font);

        gridLayout_3->addWidget(label_20, 4, 1, 1, 1);

        label_19 = new QLabel(tab_Monitoring);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(120, 25));
        label_19->setMaximumSize(QSize(120, 25));
        label_19->setFont(font);

        gridLayout_3->addWidget(label_19, 1, 1, 1, 1);

        lineEditMeteoRezTemperature = new QLineEdit(tab_Monitoring);
        lineEditMeteoRezTemperature->setObjectName(QStringLiteral("lineEditMeteoRezTemperature"));
        lineEditMeteoRezTemperature->setMinimumSize(QSize(50, 25));
        lineEditMeteoRezTemperature->setMaximumSize(QSize(50, 25));
        lineEditMeteoRezTemperature->setFont(font);
        lineEditMeteoRezTemperature->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMeteoRezTemperature->setReadOnly(true);

        gridLayout_3->addWidget(lineEditMeteoRezTemperature, 1, 2, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_20, 1, 0, 1, 1);

        label_26 = new QLabel(tab_Monitoring);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(0, 25));
        label_26->setMaximumSize(QSize(16777215, 25));
        label_26->setFont(font);

        gridLayout_3->addWidget(label_26, 0, 1, 1, 1);

        lineEditMeteoStatus = new QLineEdit(tab_Monitoring);
        lineEditMeteoStatus->setObjectName(QStringLiteral("lineEditMeteoStatus"));
        lineEditMeteoStatus->setMinimumSize(QSize(100, 25));
        lineEditMeteoStatus->setMaximumSize(QSize(100, 25));

        gridLayout_3->addWidget(lineEditMeteoStatus, 0, 2, 1, 1);


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
        menuBar->setGeometry(QRect(0, 0, 1090, 21));
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
        labelModbusBoadrate->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        labelModbusParity->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\270\321\202\320\265\321\202", nullptr));
        labelModbusAddress->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Modbus), QApplication::translate("MainWindow", "Modbus", nullptr));
        labelFrqMeteringStatus->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        labelFrqMeteringCorrection->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_FRQMetering), QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\276\320\274\320\265\321\200", nullptr));
        labelClockStatus->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        labelClockCorrection->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260 \320\275\320\260 \321\207\320\260\321\201\320\276\320\262\320\276\320\271 \320\277\320\276\321\217\321\201", nullptr));
        labelClockCorrection_2->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202. \320\277\320\265\321\200\320\265\321\205\320\276\320\264 \320\275\320\260 \320\273\320\265\321\202\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217", nullptr));
        checkBoxClockSetDaylight->setText(QString());
        labelClockCorrection_3->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\270\320\263\320\275\320\260\320\273\320\260 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Clock), QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213 ", nullptr));
        label_3->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\321\213", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260, \320\241", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\275. \320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\220\321\202\320\274 \320\224\320\260\320\262, \320\274\320\274. \321\200\321\202. \321\201\321\202.", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\220\321\202\320\274 \320\224\320\260\320\262, \320\263\320\237\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_LCD), QApplication::translate("MainWindow", "\320\226\320\232\320\230", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\276\320\274\320\265\321\200", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260, \320\223\321\206", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\320\260", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214 ", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\265\320\276\320\277\320\276\321\201\321\202", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\275. \320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\274\320\274. \321\200\321\202. \321\201\321\202", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265, \320\263\320\237\320\260", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260, \320\241", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Monitoring), QApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
