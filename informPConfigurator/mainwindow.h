#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include <lcdstr.h>
#include "hidInterface.h"

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

private:
    Ui::MainWindow *ui;

    void initUserUIAdjustments(void);
    void setDeviseCloseUIState(void);
    void setDeviseOpenUIState(void);
    void messageErrorWindowShow(QString errorString);
    void updateNumLCDString(uint8_t numString);

private:
    QStringListModel *deviceList;
    hidInterface     *userHID;

    /*widjets*/
    QVector<lcdStr*> lcdStrVector;
};

#endif // MAINWINDOW_H
