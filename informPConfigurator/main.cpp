#include "stdint.h"
#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qRegisterMetaType< QVector<uint8_t> >();
    qRegisterMetaType< uint16_t >();
    qRegisterMetaType< bool >();
    return a.exec();
}
