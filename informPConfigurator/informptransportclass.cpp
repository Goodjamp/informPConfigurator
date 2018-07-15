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
    uint8_t cnt;
    while(1)
    {
        cnt++;
    }
}


void informPTransportClass::slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{

}


void informPTransportClass::slotResetReq()
{
    uint8_t cnt;
    while(1)
    {
        cnt++;
    }
}
