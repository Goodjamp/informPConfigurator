#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QSpacerItem"
#include "QString"

#include "controlelementdescription.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    initUserUIAdjustments();

    deviceList = new QStringListModel(this);
    //ui->listViewDeviceList->setModel(deviceList);

    hidWorkspace = new userHIDInterfaces();

    ui->pushButtonOpenDevice->setDisabled(true);
    ui->pushButtonCloseDevice->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonGetDevice_clicked()
{

    QStringList List;
    deviceList->removeRows(0,deviceList->rowCount());

    hidWorkspace->hidWPathList.clear();
    hidWorkspace->initUSB();

    for(uint8_t k = 0; k < hidWorkspace->hidWPathList.size(); k++ )
    {
        List.push_back( QString::fromStdWString(hidWorkspace->hidWPathList[k]) );
    }

    deviceList->setStringList(List);
    ui->pushButtonOpenDevice->setDisabled(true);
}

void MainWindow::on_listViewDeviceList_clicked(const QModelIndex &index)
{
    std::wstring VID;
    std::wstring PID;
    std::wstring Manufactor;
    std::wstring Product;

    if( !hidWorkspace->getDInterfaceInfo( index.row(), VID, PID, Manufactor, Product))
    {
        return;
    }
    qDebug()<<"SelectedRow"<<index.row()<<"\n";

   // ui->labelPIDString->setText(QString::fromStdWString(PID));
    //ui->labelVIDstring->setText(QString::fromStdWString(VID));
   // ui->labelDevDescrString->setText(QString::fromStdWString(Manufactor));
   // ui->labelInterfaceDescrString->setText(QString::fromStdWString(Product));
    if(!hidWorkspace->isHIDOpen() )
    {
        ui->pushButtonOpenDevice->setEnabled(true);
    }
}


void MainWindow::on_pushButtonOpenDevice_clicked()
{

    uint selVID;
    uint selPID;
   // uint selRow = ui->listViewDeviceList->selectionModel()->currentIndex().row();
    /*.
    hidWorkspace->getDInterfaceVidPid(selRow, selVID, selPID);
    if( hidWorkspace->openInterface(selVID, selPID))
    {
        ui->pushButtonOpenDevice->setDisabled(true);
        ui->pushButtonCloseDevice->setEnabled(true);
    }

    if( hidWorkspace->openInterface(selRow))
    {
        ui->pushButtonOpenDevice->setDisabled(true);
        ui->pushButtonCloseDevice->setEnabled(true);
    }
    qDebug()<<"SelectedIndex = "<<selRow<<"\n VID = "<<selVID<<"\n PID = "<<selPID ;*/
}


uint8_t writeBuff[32 + 1] = {0,21,31,41,51,61};
uint8_t readBuff[32 + 1];
uint32_t numRead = 0;


void MainWindow::on_pushButtonSend_clicked()
{
     hidWorkspace->writeHIDInterface(writeBuff, 60 + 1);
}


void MainWindow::on_pushButtonReceive_clicked()
{
    numRead = hidWorkspace->readHIDInterface(writeBuff, 61);
    qDebug()<<"Reaz Read "<< numRead<<"\n";
    qDebug()<<"data: "<< writeBuff[0]<<" "<< writeBuff[1]<<" "<< writeBuff[2]<<" "<< writeBuff[3]<<" "<<"\n";
}


void MainWindow::on_pushButtonCloseDevice_clicked()
{
    hidWorkspace->closeInterface();
    ui->pushButtonOpenDevice->setEnabled(true);
    ui->pushButtonCloseDevice->setDisabled(true);
}


void MainWindow::initUserUIAdjustments(void)
{
    // Set main window paramiters
    QRect size = this->geometry();
    this->setFixedWidth(size.width());
    this->setFixedHeight(size.height());

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
    QString baseLCDName = "Индикатор №";
    for(uint8_t cnt = 0; cnt < NumberOdLCD; cnt++)
    {
        lcdStrVector.push_back(new lcdStr());
        ((QHBoxLayout*)ui->tab_LCD->layout())->insertWidget(cnt + 1,lcdStrVector[cnt]);
        lcdStrVector[cnt]->setNameLCD(baseLCDName + QString::number(cnt + 1));
    }
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

}


void MainWindow::on_pushButton_clicked()
{

}
