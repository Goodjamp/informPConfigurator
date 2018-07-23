#include "stdint.h"
#include "string.h"

#include <QVector>
#include <QDebug>

#include "informptransportclass.h"
/*Test*/
#include "informpmemmap.h"

informPTransportClass::informPTransportClass(hidInterface *comInterfaceIn)
{
    comInterface = comInterfaceIn;
}

QVector<uint8_t> buffTemp;

void informPTransportClass::slotGetRegReq(uint16_t addressReg, uint16_t numReg)
{
    QVector<uint8_t> respArray(numReg*2);
    uint8_t *communicationBuff =  (uint8_t*)malloc(messageSize);
    union{
        uint8_t     *requestBuff;
        headOfReq_t *requestData;
    }request =
    {
        .requestBuff = communicationBuff
    };
    request.requestData->reqType                       = COMUNICATION_GET_REG;
    request.requestData->payload.getRegReq.reAddress   = addressReg;
    request.requestData->payload.getRegReq.numberOfReg = numReg;
    //send Request
    if( comInterface->write(request.requestBuff, messageSize,500) != messageSize)
    {
        emit signalGetRegResp(false, addressReg, numReg, respArray);
        free(communicationBuff);
        return;
    }
    //receive response
    union{
        uint8_t     *respBuff;
        headOfRes_t *respData;
    }respons =
    {
        .respBuff = communicationBuff
    };
    if(comInterface->read(respons.respBuff, messageSize, 500) != messageSize)
    {
        emit signalGetRegResp(false, addressReg, numReg, respArray);
        free(communicationBuff);
        return;
    }
    // copy payload of response
    memcpy(respArray.begin(), respons.respData->payload.getRegResp.payload, numReg*2);
    emit signalGetRegResp((respons.respData->respStatus == STATUS_RESP_OK) ? true : false, addressReg, numReg, respArray);
    free(communicationBuff);
}


void informPTransportClass::slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    uint8_t *communicationBuff =  (uint8_t*)malloc(messageSize);
    union{
        uint8_t     *requestBuff;
        headOfReq_t *requestData;
    }request =
    {
        .requestBuff = communicationBuff
    };
    request.requestData->reqType                       = COMUNICATION_SET_REG;
    request.requestData->payload.getRegReq.reAddress   = addressReg;
    request.requestData->payload.getRegReq.numberOfReg = numReg;
    // copy payload of request
    memcpy(request.requestData->payload.setRegReq.payload, buff.begin(), buff.size());
    //send Request
    if( comInterface->write(request.requestBuff, messageSize,500) != messageSize)
    {
        emit signalSetRegResp(false);
        free(communicationBuff);
        return;
    }
    //receive response
    union{
        uint8_t     *respBuff;
        headOfRes_t *respData;
    }respons =
    {
        .respBuff = communicationBuff
    };
    if(comInterface->read(respons.respBuff, messageSize, 500) != messageSize)
    {
        emit signalSetRegResp(false);
        free(communicationBuff);
        return;
    }
    emit signalSetRegResp((respons.respData->respStatus == STATUS_RESP_OK) ? true : false);
    free(communicationBuff);
}


void informPTransportClass::slotResetReq()
{
    emit signalResetResp(true);
}
