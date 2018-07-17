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
    QVector<uint8_t> rez(1);
    emit signalGetRegResp(true, addressReg, numReg, rez);
}


void informPTransportClass::slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    emit signalSetRegResp(true);
}


void informPTransportClass::slotResetReq()
{
    emit signalResetResp(true);
}
