#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stdbool.h"
#include "stdint.h"

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include <QTimer>

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

    void initUserUIAdjustments(void);
    void setDeviseCloseUIState(void);
    void setDeviseOpenUIState(void);
    void messageErrorWindowShow(QString errorString);
    void updateNumLCDString(uint8_t numString);
    void communicatioIndicationStart();
    void communicationComplited();
    void getConfigurationFromUI(QVector<uint8_t> &configBuff);
    bool checkConfiguratin(QVector<uint8_t> &configBuff);
    bool setConfigurationToUI(QVector<uint8_t> &config);

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
