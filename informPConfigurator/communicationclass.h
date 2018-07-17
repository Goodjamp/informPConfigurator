#ifndef COMMUNICATIONCLASS_H
#define COMMUNICATIONCLASS_H

#include <QObject>
#include <QThread>
#include <QVector>

#include "informptransportclass.h"
#include "hidInterface.h"


class communicationClass: public QThread
{
    Q_OBJECT
public:
    communicationClass(hidInterface *userInterfaceIn);

/********INFORM_P COMMUNICATION PROTOCOL USER INTEFACE USER INTERFACE ****************/
    void getRegReq(uint16_t addressReg, uint16_t numReg);
    void setRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void resetReq ();
signals:
    void signalGetRegResp(bool respStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void signalSetRegResp(bool respStatus);
    void signalResetResp (bool respStatus);

private:
    void run();
    hidInterface *userInterface;
    informPTransportClass *informPTransport;

signals:
    void signalGetRegReq(uint16_t addressReg, uint16_t numReg);
    void signalSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void signalResetReq ();

};

//Q_DECLARE_METATYPE(QVector<uint8_t>)

#endif // COMMUNICATIONCLASS_H
