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

#include "waitform.h"
#include <lcdstr.h>
#include "hidInterface.h"
#include "communicationclass.h"
#include "informptransportclass.h"

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

private:
    typedef enum
    {
        SW_CONNECTION_STATUS_OK           = (uint8_t)0,
        SW_CONNECTION_STATUS_DISCONNECTED = (uint8_t)1,
        SW_CONNECTION_STATUS_ERROR_OPEN   = (uint8_t)2,
        SW_CONNECTION_STATUS_ERROR_SW     = (uint8_t)3,
        SW_CONNECTION_STATUS_ERROR_FW     = (uint8_t)4,
        SW_CONNECTION_STATUS_ERROR_RESP   = (uint8_t)5,
        SW_CONNECTION_STATUS_ERROR_DATA   = (uint8_t)6,
    }SW_CONNECTION_STATUS;

    QStringListModel   *deviceList;
    hidInterface       *userHID;
    communicationClass *communicatioStack;
    QTimer             *timerCommunicatioControl;
    QTimer             *timerStatusUpdate;
    QList<QString>     *listOfConnectinStatus;
    waitForm           *communicatioWaitWindow;

    /*widjets*/
    QVector<lcdStr*> lcdStrVector;
    /*connunication in process flag*/
    bool communicationInProcess;

private:
    Ui::MainWindow *ui;

    void initUISetings(void);
    void setDeviseCloseUIState(void);
    void setDeviseOpenUIState(void);
    void swUpdateConnectionStatus(SW_CONNECTION_STATUS inStatus);
    void updateNumLCDString(uint8_t numString);
    void communicatioIndicationStart();
    void communicationComplited();
    void getConfigurationSettings(QVector<uint8_t> &configBuff);
    bool checkConfiguratinSettings(QVector<uint8_t> &configBuff);
    bool setConfigurationSettings(QVector<uint8_t> &config);
    void getStatusState(QVector<uint8_t> &configBuff);
    void setStatusState(QVector<uint8_t> &configBuff);
    bool getUint16FromStringInt(uint16_t *rezConvertOut, QString inString);
    bool getInt16FromStringInt(int16_t *rezConvertOut, QString inString);
    void setModuleStatusLineEdit(QLineEdit *statuSlineEdit, uint16_t statusIndex);
    void setMeteoStatusLineEdit(uint16_t meteoStatus);
    void setDeviceStatusLineEdit(uint16_t statusIndex);


};

#endif // MAINWINDOW_H
