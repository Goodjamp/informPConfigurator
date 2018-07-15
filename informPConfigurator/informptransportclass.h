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
    void signalGetRegResp(RESP_STATUS respStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void signalSetRegResp(RESP_STATUS respStatus);
    void signalResetResp(RESP_STATUS respStatus);

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
