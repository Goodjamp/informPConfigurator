#include "QVector"

#include "communicationclass.h"
#include "informptransportclass.h"

communicationClass::communicationClass(hidInterface *userInterfaceIn)
{
    userInterface = userInterfaceIn;
}


void communicationClass::run()
{
    informPTransport = new informPTransportClass(userInterface);

    // tx request signal
    connect(this, &communicationClass::signalGetRegReq, informPTransport, &informPTransportClass::slotGetRegReq );
    connect(this, &communicationClass::signalSetRegReq, informPTransport, &informPTransportClass::slotSetRegReq );
    connect(this, &communicationClass::signalResetReq,  informPTransport, &informPTransportClass::slotResetReq  );
    // retransmit response signal
    connect(informPTransport, &informPTransportClass::signalGetRegResp, this, &communicationClass::signalGetRegResp );
    connect(informPTransport, &informPTransportClass::signalSetRegResp, this, &communicationClass::signalSetRegResp );
    connect(informPTransport, &informPTransportClass::signalResetResp,  this, &communicationClass::signalResetResp  );

    exec();
}


void communicationClass::getRegReq(uint16_t addressReg, uint16_t numReg)
{
    emit signalGetRegReq(addressReg, numReg);
}


void communicationClass::setRegReq(uint16_t addressReg, uint16_t numReg, uint8_t buff[])
{
    emit signalSetRegReq(addressReg, numReg, buff);
}


void communicationClass::resetReq()
{
    emit signalResetReq();
}
