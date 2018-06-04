#ifndef USERHIDINTERFACES_H
#define USERHIDINTERFACES_H

#include <QObject>
#include <string.h>


#include "WinDef.h"

class userHIDInterfaces
{
public:
    userHIDInterfaces();

public:
   void initUSB(void);
   bool getDInterfaceInfo(uint index ,std::wstring &VID, std::wstring &PID, std::wstring &Manufacturer, std::wstring &Product );
   bool getInterfaceVidPid(uint index ,uint &VID, uint &PID);
   bool openInterface(uint index);
   bool openInterface(uint &VID, uint &PID);
   bool closeInterface(void);
   bool getDInterfaceVidPid(uint index, uint &VID, uint &PID);
   bool isHIDOpen(void);
   uint32_t readHIDInterface(uint8_t *buff, uint32_t numToRead);
   uint32_t writeHIDInterface(uint8_t *buff, uint32_t numToWrite);


   std::vector<std::wstring> hidWPathList;

private:
    HANDLE hidInterface;

};

#endif // USERHIDINTERFACES_H
