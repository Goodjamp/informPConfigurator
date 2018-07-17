#include "stdint.h"
#include "string.h"

#include <QVector>
#include <QDebug>

#include "informptransportclass.h"

informPTransportClass::informPTransportClass(hidInterface *comInterfaceIn)
{
    comInterface = comInterfaceIn;
}

void informPTransportClass::slotGetRegReq(uint16_t addressReg, uint16_t numReg)
{

}


void informPTransportClass::slotSetRegReq(uint16_t addressReg, uint16_t numReg, uint8_t buff[])
{
    emit signalResetResp(RESP_STATUS_OK);
}


void informPTransportClass::slotResetReq()
{
    emit signalResetResp(RESP_STATUS_OK);
}
