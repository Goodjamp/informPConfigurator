#include "stdint.h"

#include "QDebug"
#include "QSpacerItem"
#include "QString"
#include "QMessageBox"
#include "QCheckBox"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "informpmemmap.h"


#include "controlelementdescription.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    initUserUIAdjustments();

    deviceList = new QStringListModel(this);
    //ui->listViewDeviceList->setModel(deviceList);

    userHID = new hidInterface();
    qDebug()<<"sizeof configDescriptionT"<<sizeof(configDescriptionT);
    qDebug()<<"sizeof S_dev_staff"<<sizeof(S_dev_staff)<<"\n";
    qDebug()<<"sizeof BF_date_config"<<sizeof(BF_date_config)<<"\n";
    qDebug()<<"sizeof S_connectmodbus"<<sizeof(S_connectmodbus)<<"\n";
    qDebug()<<"sizeof S_FRQmetter_user_config"<<sizeof(S_FRQmetter_user_config)<<"\n";
    qDebug()<<"sizeof S_TIME_user_config"<<sizeof(S_TIME_user_config)<<"\n";
    qDebug()<<"sizeof S_sensor_user_config"<<sizeof(S_sensor_user_config)<<"\n";
    qDebug()<<"sizeof S_display_user_config"<<sizeof(S_display_user_config)<<"\n";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setDeviseCloseUIState(void)
{
    ui->pushButtonCloseDevice->setDisabled(true);
    ui->pushButtonOpenDevice->setDisabled(false);
    ui->pushButtonRead->setDisabled(true);
    ui->pushButtonWrite->setDisabled(true);
}


void MainWindow::setDeviseOpenUIState(void)
{
    ui->pushButtonCloseDevice->setDisabled(false);
    ui->pushButtonOpenDevice->setDisabled(true);
    ui->pushButtonRead->setDisabled(false);
    ui->pushButtonWrite->setDisabled(false);
}


void MainWindow::messageErrorWindowShow(QString errorString)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",errorString);
    messageBox.setFixedSize(500,200);
    messageBox.setModal(true);
    messageBox.show();
}


void MainWindow::initUserUIAdjustments(void)
{
    // Set main window paramiters
    QRect size = this->geometry();
    this->setFixedWidth(size.width());
    this->setFixedHeight(size.height());

    this->setWindowTitle(WIN_NAME);

    // button activity
    setDeviseCloseUIState();

    // Set state
    QStringList stateList = {LIST_OF_STATE};
    QStringList listOfSign = {LIST_OF_SIGN};

    /*****************************MODBUS ADJUSTMENT PARAMITERS*********************/
    // Set baud rate list items
    QStringList baudRateList = {LIST_OF_RS485_SPEED};
    ui->comboBoxModbusBoadrate->addItems(baudRateList);
    ui->comboBoxModbusBoadrate->setCurrentIndex(4);

    // Set baud rate list items
    QStringList parityList = {LIST_OF_PARITY};
    ui->comboBoxModbusParity->addItems(parityList);
    ui->comboBoxModbusParity->setCurrentIndex(0);

    // Set adress area of device
    for(uint32_t addressIndex = 1;addressIndex < 254; addressIndex++)
    {
        ui->comboBoxModbusAddress->addItem(QString::number(addressIndex), 0);
    }

    /*****************************FREQUENCY METERING  PARAMITERS*********************/


    ui->comboBoxFrqMeteringState->addItems(stateList);
    ui->comboBoxFrqMeteringState->setCurrentIndex(0);

    ui->comboBoxFrqMeteringSign->addItems(listOfSign);
    ui->comboBoxFrqMeteringSign->setCurrentIndex(0);

    for(uint32_t correction = 0; correction < 10; correction++)
    {
        ui->comboBoxFrqMeteringNum1->addItem(QString::number(correction), 0);
        ui->comboBoxFrqMeteringNum01->addItem(QString::number(correction), 0);
        ui->comboBoxFrqMeteringNum001->addItem(QString::number(correction), 0);
    }

    /*****************************LCD ADJUSTMENT PARAMITERS*********************/
    QStringList numIndicatorsList;// = {LIST_MINUTES_CORRECTION};
    for(uint8_t cnt = 1; cnt <= NUMBER_OF_LCD_STRING; cnt++)
    {
        numIndicatorsList.push_back(QString::number(cnt, 10));
    }
    ui->comboBoxLCDNumLSD->addItems(numIndicatorsList);
    ui->comboBoxLCDNumLSD->setCurrentIndex(0);

    updateNumLCDString(0);

    /*****************************CLOCK  PARAMITERS*********************/
    ui->comboBoxClockState->addItems(stateList);
    ui->comboBoxClockState->setCurrentIndex(0);

    ui->comboBoxClockCorrectionSign->addItems(listOfSign);
    ui->comboBoxClockCorrectionSign->setCurrentIndex(0);

    QStringList minutesCorrectionList = {LIST_MINUTES_CORRECTION};
    ui->comboBoxClockCorrectionMinutes->addItems(minutesCorrectionList);
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex(0);

    for(uint32_t correction = 0; correction < 12; correction++)
    {
        ui->comboBoxClockCorrectionHours->addItem(QString::number(correction), 0);
    }

    QStringList syncSourceList = {LIST_SYNC_SOURCE};
    ui->comboBoxClockSyncSource->addItems(syncSourceList);
    ui->comboBoxClockSyncSource->setCurrentIndex(1);

    /*****************************METEO  PARAMITERS*********************/
    ui->comboBoxMeteoState->addItems(stateList);
    ui->comboBoxMeteoState->setCurrentIndex(0);

    QStringList meteoSourceList = {METEO_SOURCE_LIST};
    ui->comboBoxMeteoSourse->addItems(meteoSourceList);
    ui->comboBoxMeteoSourse->setCurrentIndex(0);
}


void MainWindow::updateNumLCDString(uint8_t numString)
{
    QString baseLCDName = "Индикатор №";
    for(uint8_t cnt = 0; cnt < lcdStrVector.size(); cnt++)
    {
        delete(lcdStrVector[cnt]);
    }
    lcdStrVector.clear();
    for(uint8_t cnt = 0; cnt < numString; cnt++)
    {
        lcdStrVector.push_back(new lcdStr());
        ((QHBoxLayout*)ui->tab_LCD->layout())->insertWidget(cnt + 3,lcdStrVector[cnt]);
        lcdStrVector[cnt]->setNameLCD(baseLCDName + QString::number(cnt + 1));
    }
}

void MainWindow::on_pushButtonCloseDevice_clicked()
{
    userHID->closeInterface();
    ui->pushButtonOpenDevice->setEnabled(true);
    ui->pushButtonCloseDevice->setDisabled(true);
}


void MainWindow::on_pushButtonOpenDevice_clicked()
{
    userHID->initUSB();
    if( !userHID->openInterface(VID_INFORM_P, PID_INFORM_P))
    {
        setDeviseCloseUIState();
        messageErrorWindowShow(ERROR_OPEN_DEVICE_NOT_FOUND);
        return;
    }
    setDeviseOpenUIState();
}


void MainWindow::on_pushButtonRead_clicked()
{

}

void MainWindow::on_pushButtonWrite_clicked()
{

}

void MainWindow::on_pushButtonReset_clicked()
{

}


void MainWindow::on_tabWidgetCurrentMode_currentChanged(int index)
{

}

void MainWindow::on_comboBoxLCDNumLSD_currentIndexChanged(int index)
{
    updateNumLCDString(index + 1);
}
