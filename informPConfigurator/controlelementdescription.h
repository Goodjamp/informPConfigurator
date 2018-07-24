#ifndef CONTROLELEMENTDESCRIPTION_H
#define CONTROLELEMENTDESCRIPTION_H

#define  VID_INFORM_P          0x0483
#define  PID_INFORM_P          0x5711

#define  COMMUNICATION_TIMEOUT  2000
#define  STATUS_REQUEST_TIMEOUT 1000


#define WIN_NAME                              (QString)"- informP -"



/*************LIST OF ERROR MRSAGES***/
#define COMMUNICATION_STATUIS_LIST    {\
                                      "Соединение установленно",\
                                      "Активное соединение отсутствует",                                           /*in case of MANUALLY go to disconnected state*/\
                                      "Устройство не найдено",                                                     /*in case of after press connect device was not found*/\
                                      "Ошибка програмы. Перезапустите программу",                                  /*in case of timeout transaction*/\
                                      "Ошибка обменна данными с устройством. Закройте затем откройте соединение",  /*in case of timeout HID read HID write*/\
                                      "Ошибка устройства. Перегрузите устройство",                                 /*in case of RECEIVE response with error status */\
                                      "Ошибка данных. При частом возникновении перегрузите устройство "            /*in case of receive unexpected data*/\
                                      }



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
#define DEVICE_STATUS_FREQUENCY_METERING_MASK   (uint16_t)(1<<1)
#define DEVICE_STATUS_CLOCK_MASK                (uint16_t)(1<<2)
#define DEVICE_STATUS_METEO_DATA_MASK           (uint16_t)(1<<3)

#define LIST_DEVICE_STATUS "РАБОТА",\
                           "АВАРИЯ"

/**********MODULE SATTUS DESCRIPTION*********/
#define LIST_MODULE_STATUS "РАБОТА",\
                           "ПРЕДУПРЕЖДЕНИЕ",\
                           "АВАРИЯ"


/***************************STYLE DESCRIPTIONS**************/
#define STYLE_STATUS_TEXT              "font: bold 16px;"


#endif // CONTROLELEMENTDESCRIPTION_H
