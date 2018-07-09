#ifndef CONTROLELEMENTDESCRIPTION_H
#define CONTROLELEMENTDESCRIPTION_H

#define LIST_OF_STATE "ВКЛ",\
                      "ВЫКЛ"

/***********MODBUS UI DESCRIPTION************************/
#define LIST_OF_RS485_SPEED "1200",\
                            "2400",\
                            "4800",\
                            "7200",\
                            "9600",\
                            "4800",\
                            "14400",\
                            "19200",\
                            "38400",\
                            "57600"

#define LIST_OF_PARITY  { "None",\
                          "Even",\
                          "Odd"}

/***********FREQUENCY METERING UI DESCRIPTION*************/

#define LIST_OF_SIGN "+",\
                     "-"
/***********CLOCK UI DESCRIPTION**************************/

#define LIST_SYNC_SOURCE " CЕРВЕР ",\
                         " GPS "

#define LIST_MINUTES_CORRECTION "0",\
                                "30"

#endif // CONTROLELEMENTDESCRIPTION_H
