#include "stdint.h"
#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qRegisterMetaType< QVector<uint8_t> >();
    return a.exec();
}
