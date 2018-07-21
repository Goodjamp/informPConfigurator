#ifndef CONTROLELEMENTDESCRIPTION_H
#define CONTROLELEMENTDESCRIPTION_H

#define  VID_INFORM_P          0x0483
#define  PID_INFORM_P          0x5711

#define  COMMUNICATION_TIMEOUT  1000
#define  STATUS_REQUEST_TIMEOUT 1000

/*************LIST OF ERROR MRSAGES***/
#define WIN_NAME                           (QString)"- informP -"
#define ERROR_OPEN_DEVICE_NOT_FOUND        (QString)"Устройство не найдено"
#define ERROR_COMMUNICATION                (QString)"Устройство не отвечает"
#define ERROR_RX_DATA_FORMAT               (QString)"Приннятые данные имеют неправильный формат"
#define ERROR_RX_DATA_ADDRESS                   (QString)"Приннятые данные имеют неправильный адрес"


#define LIST_OF_STATE "ВЫКЛ",\
                      "ВКЛ"

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
                          "Odd",\
                          "Even"}

/***********FREQUENCY METERING UI DESCRIPTION*************/


/***********CLOCK UI DESCRIPTION**************************/

#define LIST_SYNC_SOURCE " GPS ",\
                         " CЕРВЕР "

#define LIST_MINUTES_CORRECTION "0",\
                                "30"

/***********LCD DESCRIPTION**************************/
#define QUANTITY_LCD_STR       4

/***********LCD DESCRIPTION**************************/
#define METEO_SOURCE_LIST       "Локальный",\
                                "Удаленный"

/**********DEVICE STATUS LIST********/
#define LIST_DEVICE_STATUS "РАБОТА",\
                           "АВАРИЙНАЯ"

/**********MODULE SATTUS DESCRIPTION********/
#define LIST_MODULE_STATUS "РАБОТА",\
                           "ПРЕДУПРЕДИТЕЛЬНАЯ",\
                           "АВАРИЙНАЯ"


/***************************STYLE DESCRIPTIONS**************/
#define STYLE_STATUS_TEXT              "font: bold 16px;"


#endif // CONTROLELEMENTDESCRIPTION_H
