#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stdbool.h"
#include "stdint.h"

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include <QTimer>
#include <QLineEdit>
#include <QList>
#include <QGroupBox>

#include "waitform.h"
#include <lcdstr.h>
#include <clockconfig.h>
#include <clockmonitor.h>
#include "hidInterface.h"
#include "communicationclass.h"
#include "informptransportclass.h"
#include "informpmemmap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();  

private slots:

    void on_pushButtonOpenDevice_clicked();

    void on_pushButtonCloseDevice_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonReset_clicked();

    void on_tabWidgetCurrentMode_currentChanged(int index);

    void on_comboBoxLCDNumLSD_currentIndexChanged(int index);

    /***********USER SLOTS*****************/

    void communicatioTimeout();
    void statusRequestTimeout();

    /************RX COMMAND SLOTS**********/
    void slotSetRegResp(informPTransportClass::RESP_STATUS responseStatus);
    void slotResetResp (informPTransportClass::RESP_STATUS responseStatus);
    void slotGetRegResp(informPTransportClass::RESP_STATUS responseStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void on_pushButtonDocLink_clicked();

    void on_pushButtonSetTime_clicked();

    void on_checkBoxSyncPC_stateChanged(int arg1);

    void on_comboBoxClockSyncSource_currentIndexChanged(const QString &arg1);

    void on_radioButtonBui_toggled(bool checked);

private:
    typedef enum
    {
        SW_CONNECTION_STATUS_OK           = static_cast<uint8_t>(0),
        SW_CONNECTION_STATUS_DISCONNECTED = static_cast<uint8_t>(1),
        SW_CONNECTION_STATUS_ERROR_OPEN   = static_cast<uint8_t>(2),
        SW_CONNECTION_STATUS_ERROR_SW     = static_cast<uint8_t>(3),
        SW_CONNECTION_STATUS_ERROR_FW     = static_cast<uint8_t>(4),
        SW_CONNECTION_STATUS_ERROR_RESP   = static_cast<uint8_t>(5),
        SW_CONNECTION_STATUS_ERROR_DATA   = static_cast<uint8_t>(6),
    }SW_CONNECTION_STATUS;

    QStringListModel   *deviceList;
    hidInterface       *userHID;
    communicationClass *communicatioStack;
    QTimer             *timerCommunicatioControl;
    QTimer             *timerStatusUpdate;
    QList<QString>     *listOfConnectinStatus;
    waitForm           *communicatioWaitWindow;
    QGroupBox          *modbusBUiGroupBox;

    /*widjets*/
    QVector<lcdStr*> lcdStrVector;
    /*Clocks*/
    QVector<clockConfig*> clockConfigVector = QVector<clockConfig*>(4);
    QVector<clockMonitor*> clockMonitorVector = QVector<clockMonitor*>(4);
    clockConfig* myClock;
    /*connunication in process flag*/
    bool communicationInProcess;

    QList<QString> statusModulList;
    QList<QString> statusDeviceList;
    QVector<uint8_t> statusDevise;//(sizeof(statusDescriptionT));

private:
    Ui::MainWindow *ui;

    void initUISetings(void);
    void setDeviseCloseUIState(void);
    void setDeviseOpenUIState(void);
    void updateConnectionStatus(SW_CONNECTION_STATUS inStatus);
    void updateNumLCDString(uint8_t numString);
    void communicatioIndicationStart();
    void communicationComplited();
    void getConfigurationSettings(QVector<uint8_t> &configBuff);
    bool checkConfiguratinSettings(QVector<uint8_t> &configBuff);
    bool checkLCDConfiguration(QVector<uint8_t> &configBuff);
    bool setConfigurationSettings(QVector<uint8_t> &config);
    void setStatusState(QVector<uint8_t> &configBuff);
    bool getUint16FromStringInt(uint16_t *rezConvertOut, QString inString);
    bool getInt16FromStringInt(int16_t *rezConvertOut, QString inString);
    void setModuleStatusLineEdit(QLineEdit *statuSlineEdit, uint16_t statusIndex);
    void setMeteoStatusLineEdit(uint16_t meteoStatus);
    void setDeviceStatusLineEdit(uint16_t statusIndex);
    void setDateAndTimeDisable(bool isDiasble);
    void getDateAndTimeSettings(QVector<uint8_t> &buff);

};

#endif // MAINWINDOW_H
