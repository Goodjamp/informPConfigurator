#ifndef CONTROLELEMENTDESCRIPTION_H
#define CONTROLELEMENTDESCRIPTION_H


#define  PID_INFORM_P       0X1245
#define  VID_INFORM_P       0X1245

/*************LIST OF ERROR MRSAGES***/
#define WIN_NAME                           (QString)"- informP -"
#define ERROR_OPEN_DEVICE_NOT_FOUND        (QString)"informP не найден "


#define LIST_OF_STATE "ВКЛ",\
                      "ВЫКЛ"

#define LIST_OF_SIGN "+",\
                     "-"

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


/***********CLOCK UI DESCRIPTION**************************/

#define LIST_SYNC_SOURCE " CЕРВЕР ",\
                         " GPS "

#define LIST_MINUTES_CORRECTION "0",\
                                "30"

/***********LCD DESCRIPTION**************************/
#define QUANTITY_LCD_STR       4

/***********LCD DESCRIPTION**************************/
#define METEO_SOURCE_LIST       "Локальный",\
                                "Удаленный"

/**********DEVICE STATUS LIST********/
#define LIST_DEVICE_STATUS "РАБОТА",\
                           "ПРЕДУПРЕДИТЕЛЬНАЯ",\
                           "АВАРИЙНАЯ"

#endif // CONTROLELEMENTDESCRIPTION_H
