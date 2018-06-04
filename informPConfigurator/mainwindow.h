#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include <lcdstr.h>
#include "userhidinterfaces.h"

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
    void on_pushButtonGetDevice_clicked();

    void on_listViewDeviceList_clicked(const QModelIndex &index);

    void on_pushButtonOpenDevice_clicked();

    void on_pushButtonCloseDevice_clicked();

    void on_pushButtonReceive_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void initUserUIAdjustments(void);

private:
    QStringListModel *deviceList;
    userHIDInterfaces *hidWorkspace;

    bool isDeviceSelected;
    uint selVID;
    uint selPID;
    uint index;
    /*widjets*/
    QVector<lcdStr*> lcdStrVector;

    const uint8_t NumberOdLCD = 4;
};

#endif // MAINWINDOW_H
