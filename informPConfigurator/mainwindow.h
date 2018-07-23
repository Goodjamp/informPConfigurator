#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stdbool.h"
#include "stdint.h"

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include <QTimer>
#include <QLineEdit>

#include "waitform.h"
#include <lcdstr.h>
#include "hidInterface.h"
#include "communicationclass.h"

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
    void slotSetRegResp(bool responseStatus);
    void slotResetResp (bool responseStatus);
    void slotGetRegResp(bool responseStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);

private:
    Ui::MainWindow *ui;

    void initUISetings(void);
    void setDeviseCloseUIState(void);
    void setDeviseOpenUIState(void);
    void messageErrorWindowShow(QString errorString);
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
    void setDeviceStatusLineEdit(QLineEdit *statuSlineEdit, uint16_t statusIndex);

private:
    QStringListModel   *deviceList;
    hidInterface       *userHID;
    communicationClass *communicatioStack;
    QTimer             *timerCommunicatioControl;
    QTimer             *timerStatusUpdate;
    waitForm           *communicatioWaitWindow;

    /*widjets*/
    QVector<lcdStr*> lcdStrVector;
    /*connunication in process flag*/
    bool communicationInProcess;
};

#endif // MAINWINDOW_H
