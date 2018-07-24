#include "stdint.h"
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <informptransportclass.h>

//Q_DECLARE_METATYPE( informPTransportClass::RESP_STATUS );

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //--------open style file
    QFile styleF;
    styleF.setFileName(QString( QCoreApplication::applicationDirPath())+"/style.css");
    styleF.open(QFile::ReadOnly | QIODevice::Text);
    QString qssStr = styleF.readAll();
    qApp->setStyleSheet(qssStr);
    //----------------------------------------------

    MainWindow w;
    w.show();

    qRegisterMetaType< QVector<uint8_t> >();
    return a.exec();
}
