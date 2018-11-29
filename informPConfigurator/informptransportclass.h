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
        RESP_STATUS_PROTOCOL_ERROR,
        RESP_STATUS_COMMINICATION_ERROR
    }RESP_STATUS;

signals:
    void signalGetRegResp(informPTransportClass::RESP_STATUS respStatus, uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void signalSetRegResp(informPTransportClass::RESP_STATUS respStatus);
    void signalResetResp(informPTransportClass::RESP_STATUS respStatus);

public slots:
    void slotGetRegReq(uint16_t addressReg, uint16_t numReg);
    void slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff);
    void slotResetReq();

private:

    const uint8_t messageSize = 64;
    typedef enum
    {
        COMUNICATION_GET_REG = (uint8_t)0x0,
        COMUNICATION_SET_REG = (uint8_t)0x1,
        COMUNICATION_RESET   = (uint8_t)0x2
    }REQ_COMMAND;

    typedef enum
    {
        STATUS_RESP_OK    = (uint8_t)0x0,
        STATUS_RESP_ERROR = (uint8_t)0x1,
    }REQ_STATUS;

    #pragma pack(push,1)
    /****OUTPUT MESSAGE DESCRIPTION*******/
    typedef struct
    {
        uint16_t reAddress;
        uint8_t  numberOfReg;
    }getRegReq_t;

    typedef struct
    {
        uint16_t reAddress;
        uint8_t  numberOfReg;
        uint8_t  payload[];
    }setRegReq_t;

    typedef struct
    {
        uint8_t reqType;
        union
        {
            getRegReq_t getRegReq;
            setRegReq_t setRegReq;
        }payload;
    }headOfReq_t;

    /****INPUT MESSAGE DESCRIPTION*******/
    typedef struct
    {
        uint16_t reAddress;
        uint8_t  numberOfReg;
        uint8_t  payload[];
    }getRegResp_t;


    typedef struct
    {
        uint8_t reqType;
        uint8_t respStatus;
        union
        {
            getRegResp_t getRegResp;
        }payload;
    }headOfRes_t;
    #pragma pack(pop)

    hidInterface *comInterface;
};

Q_DECLARE_METATYPE( informPTransportClass::RESP_STATUS );

#endif // MCSTRANSPORTCLASS_H
