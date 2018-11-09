#include "stdint.h"

#include "QDebug"
#include "QString"
#include "QMessageBox"
#include "QCheckBox"
#include "QList"
#include "QLineEdit"
#include "QDate"
#include "QProcess"
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waitform.h"

#include "informpmemmap.h"
#include "controlelementdescription.h"
#include "communicationclass.h"
#include <clockconfig.h>


/*
Receive new data  -> Read all controls -> copy new data -> write controls :
Read all controls -> Send :
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<uint8_t> qwe;
    getStatusState(qwe);

    deviceList        = new QStringListModel(this);
    userHID           = new hidInterface();
    communicatioStack = new communicationClass(userHID);
    timerCommunicatioControl = new QTimer();
    timerStatusUpdate  = new QTimer();
    communicatioWaitWindow = new waitForm(this);
    listOfConnectinStatus    = new QList<QString>(COMMUNICATION_STATUIS_LIST);

    //listOfConnectinStatus-> (COMMUNICATION_STATUIS_LIST


    connect(timerCommunicatioControl, &QTimer::timeout, this, &MainWindow::communicatioTimeout,  Qt::QueuedConnection);
    connect(timerStatusUpdate,  &QTimer::timeout, this, &MainWindow::statusRequestTimeout, Qt::QueuedConnection);
    /*rx response connectin*/
    connect(communicatioStack, &communicationClass::signalGetRegResp, this, &MainWindow::slotGetRegResp,  Qt::QueuedConnection);
    connect(communicatioStack, &communicationClass::signalSetRegResp, this, &MainWindow::slotSetRegResp,  Qt::QueuedConnection);
    connect(communicatioStack, &communicationClass::signalResetResp,  this, &MainWindow::slotResetResp );
    communicatioStack->start();

    initUISetings();
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
    ui->pushButtonReset->setDisabled(true);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidgetCurrentMode->setCurrentIndex(0);
    //ui->tabWidgetCurrentMode->setDisabled(true);
}


void MainWindow::setDeviseOpenUIState(void)
{
    ui->pushButtonCloseDevice->setDisabled(false);
    ui->pushButtonOpenDevice->setDisabled(true);
    ui->pushButtonRead->setDisabled(false);
    ui->pushButtonWrite->setDisabled(false);
    ui->pushButtonReset->setDisabled(false);
    //ui->tabWidgetCurrentMode->setDisabled(false);
}


void MainWindow::swUpdateConnectionStatus(SW_CONNECTION_STATUS inStatus)
{
    ui->lineEditConnectionStatus->setText(listOfConnectinStatus->at(inStatus));
    switch(inStatus)
    {
    case SW_CONNECTION_STATUS_OK:
        ui->lineEditConnectionStatus->setProperty("statusConnection",1);
        break;
    case SW_CONNECTION_STATUS_DISCONNECTED:
        ui->lineEditConnectionStatus->setProperty("statusConnection",0);
        break;
    case SW_CONNECTION_STATUS_ERROR_OPEN:
    case SW_CONNECTION_STATUS_ERROR_SW:
    case SW_CONNECTION_STATUS_ERROR_FW:
    case SW_CONNECTION_STATUS_ERROR_RESP:
        ui->lineEditConnectionStatus->setProperty("statusConnection",2);
        break;    
    case SW_CONNECTION_STATUS_ERROR_DATA:
        ui->lineEditConnectionStatus->setProperty("statusConnection",3);
        break;
    }
    ui->lineEditConnectionStatus->style()->unpolish(ui->lineEditConnectionStatus);
    ui->lineEditConnectionStatus->style()->polish(ui->lineEditConnectionStatus);
}


void MainWindow::initUISetings(void)
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

    /******************CONNECTION STATUS ADJUSTMENT PARAMITERS*********************/
    swUpdateConnectionStatus(SW_CONNECTION_STATUS_DISCONNECTED);

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
    updateNumLCDString(1);

    /*****************************CLOCK  PARAMITERS*********************/
    ui->comboBoxClockState->addItems(stateList);
    ui->comboBoxClockState->setCurrentIndex(0);

    QStringList minutesCorrectionList = {LIST_MINUTES_CORRECTION};
    ui->comboBoxClockCorrectionMinutes->addItems(minutesCorrectionList);
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex(0);

    for(uint32_t correction = 0; correction < 12; correction++)
    {
        ui->comboBoxClockCorrectionHours->addItem(QString::number(correction), 0);
    }

    QStringList syncSourceList = {LIST_SYNC_SOURCE};
    ui->comboBoxClockSyncSource->addItems(syncSourceList);
    ui->comboBoxClockSyncSource->setCurrentIndex(0);

    ui->tabWidgetClockConfig->removeTab(0);
    QString tabName = "Часы №";
    for(uint8_t cnt = 0; cnt < clockConfigVector.size(); cnt++)
    {
        clockConfigVector[cnt] = new clockConfig();
        ui->tabWidgetClockConfig->addTab(clockConfigVector[cnt], tabName + QString::number(cnt + 1));

    }

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
    foreach(lcdStr *tempStr, lcdStrVector)
    {
        delete(tempStr);
    }

    lcdStrVector.clear();
    for(uint8_t cnt = 0; cnt < numString; cnt++)
    {
        lcdStrVector.push_back(new lcdStr());
        static_cast<QHBoxLayout*>(ui->scrollAreaWidgetContents_3->layout())->insertWidget(cnt + 1,lcdStrVector[cnt]);
        lcdStrVector[cnt]->setNameLCD(baseLCDName + QString::number(cnt + 1));
    }
    ui->comboBoxLCDNumLSD->setCurrentIndex(numString - 1);
}

void MainWindow::communicatioIndicationStart()
{
    communicationInProcess = true;
    communicatioWaitWindow->show();
    timerCommunicatioControl->start(COMMUNICATION_TIMEOUT);
}


void MainWindow::communicationComplited()
{
    timerCommunicatioControl->stop();
    communicatioWaitWindow->close();
    communicationInProcess = false;
}


void MainWindow::getConfigurationSettings(QVector<uint8_t> &configBuff)
{
    configBuff.resize(sizeof(configDescriptionT));
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    //read all configuration fields
    /*********************read FRQ configuration*****************************/
    config->configFrqMetering.state = (ui->comboBoxFrqMeteringState->currentIndex() == 0) ? 0 : (1);
    config->configFrqMetering.frqCorrection  = static_cast<uint16_t>(ui->comboBoxFrqMeteringNum1->currentIndex());
    config->configFrqMetering.frqCorrection *= 10;
    config->configFrqMetering.frqCorrection += ui->comboBoxFrqMeteringNum01->currentIndex();
    config->configFrqMetering.frqCorrection *= 10;
    config->configFrqMetering.frqCorrection += ui->comboBoxFrqMeteringNum001->currentIndex();
    if( ui->comboBoxFrqMeteringSign->currentIndex() == 1 )
    {
        config->configFrqMetering.frqCorrection *= -1;
    }

    /*********************read CLOCK configuration*****************************/
    config->configClock.state = (ui->comboBoxClockState->currentIndex() == 0) ? 0 : (1);
    config->configClock.timeCorection = ui->comboBoxClockCorrectionHours->currentIndex() * 60;
    if(ui->comboBoxClockCorrectionMinutes->currentIndex() == 1)
    {
        config->configClock.timeCorection += 30;
    }

    config->configClock.isDaylightSaving      = (ui->checkBoxClockSetDaylight->isChecked()) ? (1) : (0);
    config->configClock.synchronizationSource = (ui->comboBoxClockSyncSource->currentIndex() == 0) ? (SYNC_SOURCE_GPS) : (SYNC_SOURCE_SERVER);

    /*********************read METEO configuration*****************************/
    config->configMeteo.state  = (ui->comboBoxMeteoState->currentIndex() == 0) ? 0 : (1);
    config->configMeteo.source = ui->comboBoxMeteoSourse->currentIndex();

    /*********************read MODBUS configuration*****************************/
     config->configModbus.state                      = 1;

     config->configModbus.s_port_config.baudrate     = ui->comboBoxModbusBoadrate->currentText().toUInt();
     config->configModbus.s_port_config.stopbits     = 1;
     config->configModbus.s_port_config.parity       = ui->comboBoxModbusParity->currentIndex();
     config->configModbus.s_port_config.amountbyte   = 8;
     config->configModbus.s_port_config.controlpotok = 0;
     config->configModbus.type                       = PROTOCOL_MODBUS_SLAVE;
     config->configModbus.adress_kp                  = ui->comboBoxModbusAddress->currentIndex() + 1;

    /*********************read LCD configuration*****************************/
    config->configLCD.state  = (1);
    config->configLCD.numScreen = lcdStrVector.size();
    for(uint8_t k = 0; k < lcdStrVector.size(); k++)
    {
        uint16_t flag = 0x1;
        config->configLCD.screenConfig[k].numParamiterPerScreen = 0;
        config->configLCD.screenConfig[k].bitsOfParamiters      = 0;
        for(uint8_t m = 0; m < NUMBER_OF_VALUE; m++)
        {
            if(lcdStrVector[k]->listOfCheckbox[m]->isChecked())
            {
                config->configLCD.screenConfig[k].bitsOfParamiters |= flag;
                config->configLCD.screenConfig[k].numParamiterPerScreen++;
            }
            flag <<= 1;
        }
    }

    // Set date and time configuration
    config->configDate.year   = static_cast<uint32_t>(QDate::currentDate().year() - 2000);
    config->configDate.mounth = static_cast<uint32_t>(QDate::currentDate().month());
    config->configDate.day    = static_cast<uint32_t>(QDate::currentDate().day());
    config->configDate.hour   = static_cast<uint32_t>(QTime::currentTime().hour());
    config->configDate.minute = static_cast<uint32_t>(QTime::currentTime().minute());
    config->configDate.second = static_cast<uint32_t>(QTime::currentTime().second());
}


bool MainWindow::checkConfiguratinSettings(QVector<uint8_t> &configBuff)
{
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();
    /*check all configuration fields*/
    /*********************check FRQ configuration*****************************/
    if( (config->configFrqMetering.state != 0 && config->configFrqMetering.state != (1)) ||
        (config->configFrqMetering.frqCorrection > 999)  )
    {
        return false;
    }

    /*********************check CLOCK configuration*****************************/
    if((config->configClock.state != 0 && config->configClock.state != (1))                                                                   ||
       ((uint16_t)std::abs(config->configClock.timeCorection) % 30 != 0) || ((uint16_t)std::abs(config->configClock.timeCorection ) > 11* 60) ||
       (config->configClock.synchronizationSource >= ui->comboBoxClockSyncSource->count()))

    {
        return false;
    }

    /*********************check METEO configuration*****************************/
    if((config->configMeteo.state != 0 && config->configMeteo.state != (1)) ||
       (config->configMeteo.source >=  ui->comboBoxMeteoSourse->count()))
     {
         return false;
     }

    /*********************check MODBUS configuration*****************************/
    if((config->configModbus.s_port_config.parity >= ui->comboBoxModbusParity->count()) ||
       (config->configModbus.adress_kp == 0)     )
    {
      return false;
    }
    QString boudrate = QString::number(config->configModbus.s_port_config.baudrate);
    uint8_t brIndex = 0;
    for(; brIndex < ui->comboBoxModbusBoadrate->count(); brIndex++ )
    {
       if( boudrate.compare( ui->comboBoxModbusBoadrate->itemText(brIndex)) == 0)
       {
           break;
       }
    }
    if(brIndex == ui->comboBoxModbusBoadrate->count())
    {
        return false;
    }

    /*********************check LCD configuration*****************************/
    if(config->configLCD.numScreen > NUMBER_OF_LCD_STRING)
    {
        return false;
    }
    for(uint8_t cnt = 0; cnt < config->configLCD.numScreen;)
    {
        if(config->configLCD.screenConfig[cnt++].numParamiterPerScreen > NUMBER_OF_VALUE )
        {
            return false;
        }
    }
    return true;
}


bool MainWindow::checkLCDConfiguration(QVector<uint8_t> &configBuff)
{

    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    for(uint8_t cnt = 0; cnt < config->configLCD.numScreen; cnt++)
    {
        if(config->configLCD.screenConfig[cnt].numParamiterPerScreen > NUMBER_OF_VALUE || config->configLCD.screenConfig[cnt].numParamiterPerScreen == 0)
        {
            QMessageBox lcdErrorMessage(QMessageBox::Warning,
                                        " ",
                                        static_cast<QString>(LCD_ERROR_STRING_NAME) + '\n' + static_cast<QString>(LCD_ERROR_STRING) + QString::number(cnt, 10),
                                        QMessageBox::Ok, this,
                                        Qt::FramelessWindowHint);
            lcdErrorMessage.setStyleSheet(MESSAGEBOX_BUTTON_STYLE);
            lcdErrorMessage.exec();
            return false;
        }
    }
    return true;
}


bool MainWindow::setConfigurationSettings(QVector<uint8_t> &configBuff)
{
    if( !checkConfiguratinSettings(configBuff))
    {
        return false;
    }
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    uint8_t tempIndex = 0;
    /*********************set FRQ configuration*****************************/
    uint16_t tempN;
    uint16_t tempP;

    ui->comboBoxFrqMeteringState->setCurrentIndex((config->configFrqMetering.state == 0) ? 0 : 1);
    if( config->configFrqMetering.frqCorrection < 0 )
    {
        tempN = (-1) * config->configFrqMetering.frqCorrection;
        tempIndex = 1;
    }
    else
    {
       tempN = config->configFrqMetering.frqCorrection;
    }
    ui->comboBoxFrqMeteringSign->setCurrentIndex(tempIndex);
    tempIndex = 0;

    tempP = tempN;
    tempN /= 10;
    tempN *= 10;
    ui->comboBoxFrqMeteringNum001->setCurrentIndex(tempP - tempN);
    tempP = tempN / 10;
    tempN /= 100;
    tempN *= 10;
    ui->comboBoxFrqMeteringNum01->setCurrentIndex(tempP - tempN);
    tempP = tempN / 10;
    tempN /= 100;
    tempN *= 10;
    ui->comboBoxFrqMeteringNum1->setCurrentIndex(tempP - tempN);

    /********************set CLOCK configuration*****************************/
    ui->comboBoxClockState->setCurrentIndex((config->configClock.state == 0) ? 0 : 1);
    if(config->configClock.isDaylightSaving)
    {
         ui->checkBoxClockSetDaylight->setChecked(true);
    }
    else
    {
         ui->checkBoxClockSetDaylight->setChecked(false);
    }
    ui->comboBoxClockSyncSource->setCurrentIndex(config->configClock.synchronizationSource);

    uint16_t restTimeCorrection = (uint16_t)std::abs(config->configClock.timeCorection) % 60;
    if(restTimeCorrection)
    {
        tempIndex = 1;
    }
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex(tempIndex);
    tempIndex = 0;
    ui->comboBoxClockCorrectionHours->setCurrentIndex( (std::abs(config->configClock.timeCorection) - restTimeCorrection) / 60 );

    /*********************set METEO configuration*****************************/
    ui->comboBoxMeteoState->setCurrentIndex((config->configMeteo.state == 0) ? 0 : 1);
    ui->comboBoxMeteoSourse->setCurrentIndex(config->configMeteo.source);

    /*********************set MODBUS configuration*****************************/
    ui->comboBoxModbusAddress->setCurrentIndex(config->configModbus.adress_kp - 1);
    QString boudrate = QString::number(config->configModbus.s_port_config.baudrate);
    uint8_t brIndex = 0;
    for(; brIndex < ui->comboBoxModbusBoadrate->count(); brIndex++ )
    {
        if( boudrate.compare( ui->comboBoxModbusBoadrate->itemText(brIndex)) == 0)
        {
            break;
        }
    }
    ui->comboBoxModbusBoadrate->setCurrentIndex(brIndex);

    ui->comboBoxModbusParity->setCurrentIndex(config->configModbus.s_port_config.parity);

    /*********************read LCD configuration*****************************/
    updateNumLCDString(config->configLCD.numScreen);

    //foreach(lcdStr *tempLcdStr, lcdStrVector)
    for(uint8_t cnt = 0; cnt < lcdStrVector.size(); cnt++)
    {
        uint16_t flag = 0x1;
        for(uint k = 0; k < NUMBER_OF_VALUE; k++)
        {
            if(flag & config->configLCD.screenConfig[cnt].bitsOfParamiters)
            {
                lcdStrVector[cnt]->listOfCheckbox[k]->setChecked(true);
            }
            else
            {
                lcdStrVector[cnt]->listOfCheckbox[k]->setChecked(false);
            }
           flag <<= 1;
        }       
    }

    /***************SET DATE AND TIME OF LAST CONFIGURATION********/
    ui->labelConfigurationYear->setText(QString::number(config->configDate.year,   10));
    ui->labelConfigurationMounth->setText(QString::number(config->configDate.mounth, 10));
    ui->labelConfigurationDay->setText(QString::number(config->configDate.day,    10));
    ui->labelConfigurationHour->setText(QString::number(config->configDate.hour,   10));
    ui->labelConfigurationMinutes->setText(QString::number(config->configDate.minute, 10));
    return true;
}


bool MainWindow::getUint16FromStringInt(uint16_t *rezConvertOut, QString inString)
{
    uint rezValue;
    bool rezConver;
    rezValue = inString.toUInt(&rezConver, 10);
    if(rezConver)
    {
        *rezConvertOut = (uint16_t)(0xFFFF & rezValue);
        return true;
    }
    return false;
}


bool MainWindow::getInt16FromStringInt(int16_t *rezConvertOut, QString inString)
{
    uint rezValue;
    bool rezConver;
    rezValue = inString.toInt(&rezConver, 10);
    if(rezConver)
    {
        *rezConvertOut = (uint16_t)(0xFFFF & rezValue);
        return true;
    }
    return false;
}


void MainWindow::getStatusState(QVector<uint8_t> &configBuff)
{
    configBuff.resize(sizeof(statusDescriptionT));
    statusDescriptionT *status      = (statusDescriptionT*)configBuff.begin();
    QList<QString> statusDeviceList = {LIST_DEVICE_STATUS};
    QList<QString> statusModulList  = {LIST_MODULE_STATUS};

    if( statusDeviceList.indexOf(ui->lineEditDevStatus->text()) >=0 )
    {
        status->statusDevice.device_statys  = statusDeviceList.indexOf(ui->lineEditDevStatus->text());
    }

    /*********************read FRQ configuration*****************************/
    if(statusModulList.indexOf(ui->lineEditFrqMeteringStatus->text()) >= 0)
    {
        status->statusFrqMetering.status_FRQmetter = statusModulList.indexOf(ui->lineEditFrqMeteringStatus->text());
    }  

    {
        double rezValue;
        bool rezConver;
        rezValue = ui->lineEditFrqMeteringFrq->text().toDouble(&rezConver);
        if(rezConver)
        {
            status->statusFrqMetering.rez_FRQmetter = (uint16_t)(rezValue * 1000);
        }
    }


    /*********************read CLOCK configuration*****************************/
    if(statusModulList.indexOf(ui->lineEditClockStatus->text()) >= 0)
    {
        status->statusClock.status_TIME = statusModulList.indexOf(ui->lineEditClockStatus->text());
    }
    getUint16FromStringInt(&status->statusClock.date_year,   ui->lineEditClockRezYear->text()   );
    getUint16FromStringInt(&status->statusClock.date_month,  ui->lineEditClockRezMonth->text()  );
    getUint16FromStringInt(&status->statusClock.date_day,    ui->lineEditClockRezDay->text()    );
    getUint16FromStringInt(&status->statusClock.time_honour, ui->lineEditClockRezHour->text()   );
    getUint16FromStringInt(&status->statusClock.time_minute, ui->lineEditClockRezMinutes->text());

    /*********************read METEO configuration*****************************/
    if(statusModulList.indexOf(ui->lineEditMeteoStatus->text()) >= 0)
    {
        status->statusMeteo.status_sensor = statusModulList.indexOf(ui->lineEditMeteoStatus->text());
    }
    getInt16FromStringInt(&status->statusMeteo.rezTemperature,     ui->lineEditMeteoRezTemperature->text());
    getUint16FromStringInt(&status->statusMeteo.rezHumidity,       ui->lineEditMeteoRezHumidity->text()   );
    getUint16FromStringInt(&status->statusMeteo.rezPressure_mmHg,  ui->lineEditMeteoRezPressurePb->text() );
    getUint16FromStringInt(&status->statusMeteo.rezPressure_GPasc, ui->lineEditMeteoRezhPa->text()        );
}


void MainWindow::setModuleStatusLineEdit(QLineEdit *statusLineEdit, uint16_t statusIndex)
{
    QList<QString> statusModulList  = {LIST_MODULE_STATUS};
    if(statusIndex >= statusModulList.size())
    {
        return;
    }
    statusLineEdit->setText(statusModulList[statusIndex]);
    statusLineEdit->setProperty("statusPr",statusIndex);
    statusLineEdit->style()->unpolish(statusLineEdit);
    statusLineEdit->style()->polish(statusLineEdit);
}


void MainWindow::setMeteoStatusLineEdit(uint16_t meteoStatus)
{
    QList<QString> statusModulList  = {LIST_MODULE_STATUS};
    if( meteoStatus == 0)
    {
         ui->lineEditMeteoStatus->setText(statusModulList[0]);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_LOCAL))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_LOCAL_RECEIVER_STR);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_RECEIVER))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_REM_RECEIVER_STR);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_REM_RX_TIMEOUT))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_REM_RX_TIMEOUT_STR);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_REM_SENSOR))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_REM_SENSOR_STR);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_REM_MES))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_REM_MES_STR);
    }
    if( meteoStatus & static_cast<uint16_t>(1 << SENSOR_STATUS_ERROR_REM_BATARY))
    {
         ui->lineEditMeteoStatus->setText(METEO_ERROR_REM_BATARY_STR);
    }
    ui->lineEditMeteoStatus->setProperty("statusPr",(meteoStatus == 0) ? (0) : (2));
    ui->lineEditMeteoStatus->style()->unpolish(ui->lineEditMeteoStatus);
    ui->lineEditMeteoStatus->style()->polish(ui->lineEditMeteoStatus);

}



void MainWindow::setDeviceStatusLineEdit(uint16_t statusIndex)
{
    QList<QString> statusDeviceList = {LIST_DEVICE_STATUS};
    //statusDeviceList.size()
    uint8_t statusTextIndex = (statusIndex > 0) ? 1 : 0;
    //Set global device status
    ui->lineEditDevStatus->setText(statusDeviceList[statusTextIndex]);
    ui->lineEditDevStatus->setProperty("statusPr",((statusTextIndex == 0)?0:2) );
    ui->lineEditDevStatus->style()->unpolish(ui->lineEditDevStatus);
    ui->lineEditDevStatus->style()->polish(ui->lineEditDevStatus);

    //Analyse module status for frequency metering module
    ui->lineEditDevStatusFrqMetering->setText((statusIndex & DEVICE_STATUS_FREQUENCY_METERING_MASK) ? statusDeviceList[1] : statusDeviceList[0]);
    ui->lineEditDevStatusFrqMetering->setProperty("statusPr",(((statusIndex & DEVICE_STATUS_FREQUENCY_METERING_MASK)) ? 2 : 0));
    ui->lineEditDevStatusFrqMetering->style()->unpolish(ui->lineEditDevStatusFrqMetering);
    ui->lineEditDevStatusFrqMetering->style()->polish(ui->lineEditDevStatusFrqMetering);

    //Analyse module status for Clock module
    ui->lineEditDevStatusClock->setText((statusIndex & DEVICE_STATUS_CLOCK_MASK) ? statusDeviceList[1] : statusDeviceList[0]);
    ui->lineEditDevStatusClock->setProperty("statusPr",(((statusIndex & DEVICE_STATUS_CLOCK_MASK)) ? 2 : 0));
    ui->lineEditDevStatusClock->style()->unpolish(ui->lineEditDevStatusClock);
    ui->lineEditDevStatusClock->style()->polish(ui->lineEditDevStatusClock);

    //Analyse module status for meteo module
    ui->lineEditDevStatusMeteo->setText((statusIndex & DEVICE_STATUS_METEO_DATA_MASK) ? statusDeviceList[1] : statusDeviceList[0]);
    ui->lineEditDevStatusMeteo->setProperty("statusPr",(((statusIndex & DEVICE_STATUS_METEO_DATA_MASK)) ? 2 : 0));
    ui->lineEditDevStatusMeteo->style()->unpolish(ui->lineEditDevStatusMeteo);
    ui->lineEditDevStatusMeteo->style()->polish(ui->lineEditDevStatusMeteo);

}


void MainWindow::setStatusState(QVector<uint8_t> &configBuff)
{
    configBuff.resize(sizeof(statusDescriptionT));
    statusDescriptionT *status      = (statusDescriptionT*)configBuff.begin();

    /*********************set device status*****************************/
    setDeviceStatusLineEdit(status->statusDevice.device_statys);

    /*********************set FRQ configuration*****************************/
    setModuleStatusLineEdit(ui->lineEditFrqMeteringStatus, status->statusFrqMetering.status_FRQmetter);
    ui->lineEditFrqMeteringFrq->setText(QString::number(double(status->statusFrqMetering.rez_FRQmetter)/1000));

    /*********************set CLOCK configuration*****************************/
    setModuleStatusLineEdit(ui->lineEditClockStatus, status->statusClock.status_TIME);

    ui->lineEditClockRezYear->setText(QString::number(status->statusClock.date_year));
    ui->lineEditClockRezMonth->setText(QString::number(status->statusClock.date_month));
    ui->lineEditClockRezDay->setText(QString::number(status->statusClock.date_day));
    ui->lineEditClockRezHour->setText(QString::number(status->statusClock.time_honour));
    ui->lineEditClockRezMinutes->setText(QString::number(status->statusClock.time_minute));

    /*********************set METEO configuration*****************************/
    setMeteoStatusLineEdit(status->statusMeteo.status_sensor);
    double tempDouble = status->statusMeteo.rezTemperature;
    tempDouble /= 10;
    ui->lineEditMeteoRezTemperature->setText(QString::number(tempDouble));
    tempDouble = status->statusMeteo.rezHumidity;
    tempDouble /= 10;
    ui->lineEditMeteoRezHumidity->setText(QString::number(tempDouble));
    ui->lineEditMeteoRezPressurePb->setText(QString::number(status->statusMeteo.rezPressure_mmHg));
    ui->lineEditMeteoRezhPa->setText(QString::number(status->statusMeteo.rezPressure_GPasc));
}


void MainWindow::communicatioTimeout()
{
    communicationComplited();
    swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_SW);
}


void MainWindow::statusRequestTimeout()
{
    communicatioStack->getRegReq(USER_ADDRESS_STATUS_DATA, STATUS_NUM_REG);
}


void MainWindow::on_pushButtonCloseDevice_clicked()
{
    userHID->closeInterface();
    timerStatusUpdate->stop();
    setDeviseCloseUIState();
    swUpdateConnectionStatus(SW_CONNECTION_STATUS_DISCONNECTED);
}


void MainWindow::on_pushButtonOpenDevice_clicked()
{
    userHID->initUSB();
    if( !userHID->openInterface(VID_INFORM_P, PID_INFORM_P))
    {
        setDeviseCloseUIState();
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_OPEN);
        return;
    }
    setDeviseOpenUIState();
    //Read all configuration registers
    communicatioStack->getRegReq(USER_CONDFIG_ADDRESS, USER_CONFIG_NUM_REG);
    swUpdateConnectionStatus(SW_CONNECTION_STATUS_OK);
}


void MainWindow::on_pushButtonRead_clicked()
{
    communicatioStack->getRegReq(USER_CONDFIG_ADDRESS, USER_CONFIG_NUM_REG);
    communicatioIndicationStart();
}


void MainWindow::on_pushButtonWrite_clicked()
{
    QVector<uint8_t>   buff(sizeof(configDescriptionT));
    //configDescriptionT *confiData = (configDescriptionT *)buff.data();
    getConfigurationSettings(buff);
    if(!checkLCDConfiguration(buff))
    {
        return;
    }
    // start transaction
    communicatioStack->setRegReq(USER_CONDFIG_ADDRESS,
                                 USER_CONFIG_NUM_REG,
                                 buff);
    communicatioIndicationStart();
}

void MainWindow::on_pushButtonReset_clicked()
{
   communicatioStack->resetReq();
   communicatioIndicationStart();
}


void MainWindow::on_tabWidgetCurrentMode_currentChanged(int index)
{
    if(index == 0)
    {
        timerStatusUpdate->stop();
    }
    else if(index == 1)
    {
        timerStatusUpdate->start(STATUS_REQUEST_TIMEOUT);
    }
}

void MainWindow::on_comboBoxLCDNumLSD_currentIndexChanged(int index)
{
    if( ui->comboBoxLCDNumLSD->currentIndex()+1 == lcdStrVector.size() )
    {
        return;
    }
    updateNumLCDString(static_cast<uint8_t>(index + 1));
}


void MainWindow::slotGetRegResp(informPTransportClass::RESP_STATUS responseStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    communicationComplited();

    switch(responseStatus)
    {
    case informPTransportClass::RESP_STATUS_COMMINICATION_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_FW);
        return;
    case informPTransportClass::RESP_STATUS_PROTOCOL_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_RESP);
        return;
    }

    if( (addressReg >= USER_ADDRESS_STATUS_DATA) &&
        (addressReg + numReg <= USER_ADDRESS_STATUS_DATA + STATUS_NUM_REG))
    {
        qDebug()<<"StatusRequest resp";
        QVector<uint8_t> statusFromUI(sizeof(statusDescriptionT));
        getStatusState(statusFromUI);
        uint8_t cnt = (addressReg - USER_ADDRESS_STATUS_DATA) * 2;
        // copy new status data to current status buffer
        foreach (uint8_t val, buff) {
            statusFromUI[cnt++] = val;
        }
        setStatusState(statusFromUI);
    }
    else if( (addressReg >= USER_ADDRESS_CONFIG_DATA) &&
             (addressReg + numReg <= USER_ADDRESS_CONFIG_DATA + ALL_CONFIG_NUM_REG))
    {
        qDebug()<<"ConfigRequest resp";
        //QVector<uint8_t> configurationFromUI;
        //getConfigurationSettings(configurationFromUI);
        if( !setConfigurationSettings(buff))
        {
            swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_DATA);
            return;
        }

    }
    else
    {
        //swUpdateConnectionStatus(ERROR_RX_DATA_ADDRESS);
    }
    swUpdateConnectionStatus(SW_CONNECTION_STATUS_OK);
}


void MainWindow::slotSetRegResp(informPTransportClass::RESP_STATUS responseStatus)
{
    communicationComplited();    
    //in case of error response
    switch(responseStatus)
    {
    case informPTransportClass::RESP_STATUS_COMMINICATION_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_FW);
        return;
    case informPTransportClass::RESP_STATUS_PROTOCOL_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_RESP);
        return;
    }
}

void MainWindow::slotResetResp(informPTransportClass::RESP_STATUS responseStatus)
{
    communicationComplited();
    //in case of error response
    switch(responseStatus)
    {
    case informPTransportClass::RESP_STATUS_OK:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_OK);
        return;
    case informPTransportClass::RESP_STATUS_COMMINICATION_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_FW);
        return;
    case informPTransportClass::RESP_STATUS_PROTOCOL_ERROR:
        swUpdateConnectionStatus(SW_CONNECTION_STATUS_ERROR_RESP);
        return;
    }
}


void MainWindow::on_pushButtonDocLink_clicked()
{
    QString documentation = QString("file:///" + QCoreApplication::applicationDirPath()) + "/" + DOCUMENTATION_FILE_NAME;
    qDebug()<<documentation;
    QDesktopServices::openUrl(QUrl(documentation));
}
