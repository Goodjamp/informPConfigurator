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
/*    QVector<uint8_t> rez(sizeof(configDescriptionT));
    configDescriptionT *config = (configDescriptionT*)rez.begin();

    config->configClock.isDaylightSaving      = 0;
    config->configClock.state                 = 1;
    config->configClock.synchronizationSource = 1;
    config->configClock.timeCorection         = (-1)*(2*60 + 0);

    config->configFrqMetering.frqCorrection   = -892;
    config->configFrqMetering.state           = 1;

    config->configLCD.screenConfig[0].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[0].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[1].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[1].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[2].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[2].numParamiterPerScreen = 7;
    config->configLCD.screenConfig[3].bitsOfParamiters      = 0xAA >> 1;
    config->configLCD.screenConfig[3].numParamiterPerScreen = 7;
    config->configLCD.numScreen                             = 2;
    config->configLCD.state                                 = 0;

    config->configMeteo.source = 1;
    config->configMeteo.state  = 1;

    config->configModbus.adress_kp = 12;
    config->configModbus.s_port_config.baudrate = 38400;
    config->configModbus.s_port_config.parity   = 2;
*/
    QVector<uint8_t> rez(sizeof(statusDescriptionT));
    statusDescriptionT *status = (statusDescriptionT*)rez.begin();
    static uint8_t cnt = 0;
    status->statusDevice.device_statys = cnt;

    status->statusMeteo.status_sensor  = cnt;
    status->statusMeteo.rezTemperature = -12;
    status->statusMeteo.rezHumidity    = 68;
    status->statusMeteo.rezPressure_mmHg = 768;
    status->statusMeteo.rezPressure_GPasc = 1235;

    status->statusClock.date_year  = 1;
    status->statusClock.date_month = 2;
    status->statusClock.date_day   = 3;
    status->statusClock.time_honour= 4;
    status->statusClock.time_minute= 5;
    status->statusClock.status_TIME=cnt;

    status->statusFrqMetering.rez_FRQmetter = 49950;
    status->statusFrqMetering.status_FRQmetter = cnt;


    if(cnt == 2 )
    {
        cnt = 0;
    }
    else
    {
        cnt++;
    }

    emit signalGetRegResp(true, addressReg, numReg, rez);
}


void informPTransportClass::slotSetRegReq(uint16_t addressReg, uint16_t numReg, QVector<uint8_t> buff)
{
    buffTemp = buff;
    emit signalSetRegResp(true);
}


void informPTransportClass::slotResetReq()
{
    emit signalResetResp(true);
}
