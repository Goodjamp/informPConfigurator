#ifndef MCSTRANSPORTCLASS_H
#define MCSTRANSPORTCLASS_H


#include <stdint.h>

#include <QObject>
#include <QVector>

#include "hidInterface.h"

class informPTransportClass: public QObject
{
    Q_OBJECT
public:
    informPTransportClass(hidInterface *comInterfaceIn);

    typedef enum{
        RESP_STATUS_OK,
        RESP_STATUS_ERROR
    }RESP_STATUS;

signals:
    void signalGetRegResp(bool respStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void signalSetRegResp(bool respStatus);
    void signalResetResp(bool respStatus);

public slots:
    void slotGetRegReq(uint16_t addressReg, uint16_t numReg);
    void slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void slotResetReq();

private:
    enum{
        REQ_TYPE_GET_REG,
        REQ_TYPE_SET_REG,
        REQ_TYPE_RESET,
    }REQ_TYPE;
    hidInterface *comInterface;
};

#endif // MCSTRANSPORTCLASS_H
