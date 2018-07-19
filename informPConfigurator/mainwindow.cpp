#include "stdint.h"

#include "QDebug"
#include "QSpacerItem"
#include "QString"
#include "QMessageBox"
#include "QCheckBox"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waitform.h"

#include "informpmemmap.h"
#include "controlelementdescription.h"
#include "communicationclass.h"


/*
Receive new data  -> Read all controls -> copy new data -> write controls :
Read all controls -> Send :
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUserUIAdjustments();

    deviceList        = new QStringListModel(this);
    userHID           = new hidInterface();
    communicatioStack = new communicationClass(userHID);
    timerCommunicatioControl = new QTimer();
    timerStatusUpdate  = new QTimer();
    communicatioWaitWindow = new waitForm(this);

    connect(timerCommunicatioControl, &QTimer::timeout, this, &MainWindow::communicatioTimeout,  Qt::QueuedConnection);
    connect(timerStatusUpdate,  &QTimer::timeout, this, &MainWindow::statusRequestTimeout, Qt::QueuedConnection);
    /*rx response connectin*/
    connect(communicatioStack, &communicationClass::signalGetRegResp, this, &MainWindow::slotGetRegResp);
    connect(communicatioStack, &communicationClass::signalSetRegResp, this, &MainWindow::slotSetRegResp);
    connect(communicatioStack, &communicationClass::signalResetResp,  this, &MainWindow::slotResetResp );
    communicatioStack->start();
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
    ui->tabWidgetCurrentMode->setDisabled(true);
}


void MainWindow::setDeviseOpenUIState(void)
{
    ui->pushButtonCloseDevice->setDisabled(false);
    ui->pushButtonOpenDevice->setDisabled(true);
    ui->pushButtonRead->setDisabled(false);
    ui->pushButtonWrite->setDisabled(false);
    ui->pushButtonReset->setDisabled(false);
    ui->tabWidgetCurrentMode->setDisabled(false);
}


void MainWindow::messageErrorWindowShow(QString errorString)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Ошибка",errorString);
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
    updateNumLCDString(1);

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
    ui->comboBoxClockSyncSource->setCurrentIndex(0);

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
        ((QHBoxLayout*)ui->tab_LCD->layout())->insertWidget(cnt + 3,lcdStrVector[cnt]);
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


void MainWindow::getConfigurationFromUI(QVector<uint8_t> &configBuff)
{
    configBuff.resize(sizeof(configDescriptionT));
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    //read all configuration fields
    /*********************read FRQ configuration*****************************/
    config->configFrqMetering.state = ui->comboBoxFrqMeteringState->currentIndex();
    config->configFrqMetering.frqCorrection  = ui->comboBoxFrqMeteringNum1->currentIndex();
    config->configFrqMetering.frqCorrection *= 10;
    config->configFrqMetering.frqCorrection += ui->comboBoxFrqMeteringNum01->currentIndex();
    config->configFrqMetering.frqCorrection *= 10;
    config->configFrqMetering.frqCorrection += ui->comboBoxFrqMeteringNum001->currentIndex();
    if( ui->comboBoxFrqMeteringSign->currentIndex() == 1 )
    {
        config->configFrqMetering.frqCorrection *= -1;
    }

    /*********************read CLOCK configuration*****************************/
    config->configClock.state = ui->comboBoxFrqMeteringState->currentIndex();
    config->configClock.timeCorection = ui->comboBoxClockCorrectionHours->currentIndex() * 60;
    if(ui->comboBoxClockCorrectionMinutes->currentIndex() == 1)
    {
        config->configClock.timeCorection += 30;
    }
    if(ui->comboBoxClockCorrectionSign == 0)
    {
        config->configClock.timeCorection *= (-1);
    }
    config->configClock.isDaylightSaving      = (ui->checkBoxClockSetDaylight->isChecked()) ? (1) : (0);
    config->configClock.synchronizationSource = (ui->comboBoxClockSyncSource == 0) ? (SYNC_SOURCE_GPS) : (SYNC_SOURCE_SERVER);

    /*********************read METEO configuration*****************************/
    config->configMeteo.state  = (ui->comboBoxMeteoState->currentIndex() == 0) ? (1) : (0);
    config->configMeteo.source = (ui->comboBoxMeteoSourse->currentIndex() == 0) ? (METEO_SOURCE_LOCAL) : (METEO_SOURCE_REMOTE);

    /*********************read MODBUS configuration*****************************/
     config->configModbus.adress_kp                = ui->comboBoxModbusAddress->currentIndex() + 1;
     config->configModbus.s_port_config.baudrate   = ui->comboBoxModbusBoadrate->currentText().toUInt();
     config->configModbus.s_port_config.parity     = ui->comboBoxModbusParity->currentIndex();
     config->configModbus.type                     = PROTOCOL_MODBUS_SLAVE;
     config->configModbus.state                    = 1;
     config->configModbus.s_port_config.stopbits   = 0;
     config->configModbus.s_port_config.amountbyte = 0;

    /*********************read LCD configuration*****************************/
    config->configLCD.state  = 1;
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
            }
            flag <<= 1;
        }
    }
}


bool MainWindow::checkConfiguratin(QVector<uint8_t> &configBuff)
{
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    /*check all configuration fields*/

    /*********************check FRQ configuration*****************************/
    if( (config->configFrqMetering.state >=  ui->comboBoxFrqMeteringState->count()) ||
        (config->configFrqMetering.frqCorrection > 999)  )
    {
        return false;
    }

    /*********************check CLOCK configuration*****************************/
    if((config->configClock.state >=  ui->comboBoxClockState->count())                                ||
       ((uint16_t)std::abs(config->configClock.timeCorection) % 30 != 0) || ((uint16_t)std::abs(config->configClock.timeCorection ) > 11* 60) ||
       (config->configClock.synchronizationSource >= ui->comboBoxClockSyncSource->count()))

    {
        return false;
    }

    /*********************check METEO configuration*****************************/
    if((config->configMeteo.state >=  ui->comboBoxMeteoState->count()) ||
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
        if(config->configLCD.screenConfig[cnt++].numParamiterPerScreen > NUMBER_OF_VALUE)
        {
            return false;
        }
    }
    return true;
}


bool MainWindow::setConfigurationToUI(QVector<uint8_t> &configBuff)
{
    if( !checkConfiguratin(configBuff))
    {
        return false;
    }
    configDescriptionT *config = (configDescriptionT*)configBuff.begin();

    uint8_t tempIndex = 0;
    /*********************set FRQ configuration*****************************/
    uint16_t tempN;
    uint16_t tempP;

    ui->comboBoxFrqMeteringState->setCurrentIndex(config->configFrqMetering.state);
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
    ui->comboBoxClockState->setCurrentIndex(config->configClock.state);
    if(config->configClock.isDaylightSaving)
    {
         ui->checkBoxClockSetDaylight->setChecked(true);
    }
    else
    {
         ui->checkBoxClockSetDaylight->setChecked(false);
    }
    ui->comboBoxClockSyncSource->setCurrentIndex(config->configClock.synchronizationSource);
    if(config->configClock.timeCorection < 0)
    {
        ui->comboBoxClockCorrectionSign->setCurrentIndex(1);
    }
    else
    {
        ui->comboBoxClockCorrectionSign->setCurrentIndex(0);
    }

    uint16_t restTimeCorrection = (uint16_t)std::abs(config->configClock.timeCorection) % 60;
    if(restTimeCorrection)
    {
        tempIndex = 1;
    }
    ui->comboBoxClockCorrectionMinutes->setCurrentIndex(tempIndex);
    tempIndex = 0;
    ui->comboBoxClockCorrectionHours->setCurrentIndex( (std::abs(config->configClock.timeCorection) - restTimeCorrection) / 60 );

    /*********************set METEO configuration*****************************/
    ui->comboBoxMeteoState->setCurrentIndex(config->configMeteo.state);
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
    return true;
}


void MainWindow::communicatioTimeout()
{
    communicationComplited();
    messageErrorWindowShow(ERROR_COMMUNICATION);
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
    //Read all configuration registers
    communicatioStack->getRegReq(USER_ADDRESS_CONFIG_DATA, CONFIGURATION_NUM_REG);
    communicatioIndicationStart();
}


void MainWindow::on_pushButtonRead_clicked()
{
    communicatioStack->getRegReq(USER_ADDRESS_CONFIG_DATA, CONFIGURATION_NUM_REG);
    communicatioIndicationStart();
}


void MainWindow::on_pushButtonWrite_clicked()
{
    QVector<uint8_t> buff(sizeof(configDescriptionT));

    getConfigurationFromUI(buff);

    // start transaction
    communicatioStack->setRegReq(USER_ADDRESS_CONFIG_DATA, CONFIGURATION_NUM_REG, buff);
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
    updateNumLCDString(index + 1);
}


void MainWindow::slotGetRegResp(bool responseStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    communicationComplited();
    if(!responseStatus){
        messageErrorWindowShow(ERROR_COMMUNICATION);
        on_pushButtonCloseDevice_clicked();
    }
    if( (addressReg >= USER_ADDRESS_STATUS_DATA) &&
        (addressReg + numReg <= USER_ADDRESS_STATUS_DATA + STATUS_NUM_REG))
    {
        qDebug()<<"StatusRequest resp";
        /*TODO correct combine new dara and present data*/
        /*TODO update status part of UI*/
    }
    else if( (addressReg >= USER_ADDRESS_CONFIG_DATA) &&
             (addressReg + numReg <= USER_ADDRESS_CONFIG_DATA + CONFIGURATION_NUM_REG))
    {
        qDebug()<<"ConfigRequest resp";
        QVector<uint8_t> configurationFromUI;
        getConfigurationFromUI(configurationFromUI);
        uint8_t cnt = (addressReg - USER_ADDRESS_CONFIG_DATA) * 2;
        foreach (uint8_t val, buff) {
            configurationFromUI[cnt++] = val;
        }
        if( !setConfigurationToUI(configurationFromUI))
        {
            messageErrorWindowShow(ERROR_RX_DATA_FORMAT);
        }
    }
    else
    {
        messageErrorWindowShow(ERROR_RX_DATA_ADDRESS);
    }
}


void MainWindow::slotSetRegResp(bool responseStatus)
{
    communicationComplited();
    if(!responseStatus){
        messageErrorWindowShow(ERROR_COMMUNICATION);
        on_pushButtonCloseDevice_clicked();
    }
}

void MainWindow::slotResetResp(bool responseStatus)
{
    communicationComplited();
    if(!responseStatus){
        messageErrorWindowShow(ERROR_COMMUNICATION);
        on_pushButtonCloseDevice_clicked();
    }
}
