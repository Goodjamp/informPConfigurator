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

void informPTransportClass::slotGetRegReq(uint16_t addressReg, uint16_t numReg)
{
    QVector<uint8_t> rez(sizeof(configDescriptionT));
    configDescriptionT *config = (configDescriptionT*)rez.begin();

    config->configClock.isDaylightSaving      = 1;
    config->configClock.state                 = 1;
    config->configClock.synchronizationSource = 1;
    config->configClock.timeCorection         = (-1)*(5*60 + 30);

    config->configFrqMetering.frqCorrection   =-123;
    config->configFrqMetering.state           = 1;

    config->configLCD.screenConfig[0].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[0].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[1].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[1].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[2].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[2].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[3].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[3].numParamiterPerScreen = 7;
    config->configLCD.numScreen                             = 4;
    config->configLCD.state                                 = 1;

    config->configMeteo.source = 1;
    config->configMeteo.state  = 1;

    config->configModbus.adress_kp = 12;
    config->configModbus.s_port_config.baudrate = 38400;
    config->configModbus.s_port_config.parity   = 2;

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
