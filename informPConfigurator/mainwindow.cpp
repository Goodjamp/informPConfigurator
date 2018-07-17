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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUserUIAdjustments();

    deviceList        = new QStringListModel(this);
    userHID           = new hidInterface();
    communicatioStack = new communicationClass(userHID);
    communicatioTimer = new QTimer();
    communicatioWaitWindow = new waitForm(this);

    connect(communicatioTimer, &QTimer::timeout, this, &MainWindow::communicatioTimeout, Qt::QueuedConnection);
    /*rx response connectin*/
    connect(communicatioStack, &communicationClass::signalGetRegResp, this, &MainWindow::slotGetRegResp);
    connect(communicatioStack, &communicationClass::signalSetRegResp, this, &MainWindow::slotSetRegResp);
    connect(communicatioStack, &communicationClass::signalResetResp,  this, &MainWindow::slotResetResp );
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
    //ui->pushButtonWrite->setDisabled(true);
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

void MainWindow::communicatioIndicationStart()
{
    communicationInProcess = true;
    communicatioWaitWindow->show();
    communicatioTimer->start(COMMUNICATION_TIMEOUT);
}


void MainWindow::communicationComplited()
{
    communicatioTimer->stop();
    communicatioWaitWindow->close();
    communicationInProcess = false;
}


void MainWindow::communicatioTimeout()
{
    communicationComplited();
    messageErrorWindowShow(ERROR_COMMUNICATION);
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
    communicatioStack->start();
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
    QVector<uint8_t>    buff(sizeof(configDescriptionT));
    configDescriptionT *config = (configDescriptionT*)buff.begin();

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
    config->configClock.isDaylightSaving      = (ui->checkBoxClockSetDaylight->isChecked()) ? (1) : (0);
    config->configClock.synchronizationSource = (ui->comboBoxClockSyncSource == 0) ? (SYNC_SOURCE_GPS) : (SYNC_SOURCE_SERVER);

    /*********************read METEO configuration*****************************/
    config->confifgMeteo.state  = (ui->comboBoxMeteoState == 0) ? (1) : (0);
    config->confifgMeteo.source = (ui->comboBoxMeteoSourse == 0) ? (SYNC_SOURCE_GPS) : (SYNC_SOURCE_SERVER);

    /*********************read MODBUS configuration*****************************/
     config->configModbus.adress_kp                = ui->comboBoxModbusAddress->currentIndex();
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

}

void MainWindow::on_comboBoxLCDNumLSD_currentIndexChanged(int index)
{
    updateNumLCDString(index + 1);
}


void MainWindow::slotGetRegResp(bool responseStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    communicationComplited();
}


void MainWindow::slotSetRegResp(bool responseStatus)
{
    communicationComplited();
}

void MainWindow::slotResetResp(bool responseStatus)
{
    communicationComplited();
}
