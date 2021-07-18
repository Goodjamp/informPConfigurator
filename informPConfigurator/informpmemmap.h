#ifndef INFORMPMEMMAP_H
#define INFORMPMEMMAP_H

#include "stdint.h"

//address of first statys register
#define USER_ADDRESS_STATUS_DATA  static_cast<uint16_t>(500)

//address of first configuration register
#define USER_ADDRESS_CONFIG_DATA  static_cast<uint16_t>(1000)


/*******************************************************************/
/************INFORMP USER DATA MEMORY MAP DESCRIPTION***********/
/*******************************************************************/
typedef enum{
    STATUS_OK,
    STATUS_ALLARM,
    STATUS_ERROR,
    STATUS_NOT_SET
}FRQ_STATUS;


#pragma pack(push,1)
typedef struct{
    uint16_t device_rcr;              // device reset_control_register
    uint16_t device_statys;	          // device status register
} S_devise_reset_status;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct{
    uint16_t status_PORT[1];
} S_modbus_oper_data;
#pragma pack(pop)


/*************FRQ METERING MODULE STATUS**********/

#pragma pack(push,1)
typedef struct{
    uint16_t  status_FRQmetter; // ñòàòóñ ðåãèñòðû FRQmetter
    uint16_t  rez_FRQmetter;    // measurement result
} S_FRQmetter_oper_data;
#pragma pack(pop)


/*************TIME MODULE STATUS**********/
#define CLOCK_QUANTITY   4
#pragma pack(push,1)
typedef struct
{
    uint16_t Year;
    uint16_t Month;
    uint16_t Day;
    uint16_t Hour;
    uint16_t Minutes;
    uint16_t Seconds;
}serverSetTime;

typedef struct{
    uint16_t  date_year;    // date: year
    uint16_t  date_month;   // date: month
    uint16_t  date_day;     // date: day
    uint16_t  time_hour;    // time: honour
    uint16_t  time_minute;  // time: minute
    uint16_t  time_second;  // time: second
    uint16_t  DATE;
    uint16_t  TIME;
}S_Clock;

typedef struct{
    uint16_t  status_TIME;  // status register TIME module addtres
    S_Clock   clock[CLOCK_QUANTITY];
    serverSetTime serverTime;
} S_TIME_oper_data;
#pragma pack(pop)


/*************METEO MODULE STATUS**********/
#pragma pack(push,1)
typedef struct{
    uint16_t  status_sensor;
    uint16_t  rezTemperature;    // address in memory map rez measure temperature*10
    uint16_t  rezHumidity;       // address in memory map rez measure humidity *10
    uint16_t  rezPressure_mmHg;  // address in memory map rez Pressure mmHg
    uint16_t  rezPressure_GPasc; // address in memory map rez Pressure GPasc
    uint16_t  rezRain;           // address in memory map rez rain
} S_sensor_address;
#pragma pack(pop)

/*************BUI OPER DATA**********/
#pragma pack(push,1)
typedef struct{
    uint16_t  buiStatus;
    uint16_t  buiMatrixSymbol;
    uint16_t  buiSegmentSymbol0;
    uint16_t  buiSegmentSymbol1;
    uint16_t  buiSegmentSymbol2;
    uint16_t  buiSegmentSymbol3;
} S_bui_oper_data;
#pragma pack(pop)

/********TOTAL  STATUS  DESCRIPTION***************/

#pragma pack(push,1)
typedef struct
{
    S_devise_reset_status  statusDevice;
    S_modbus_oper_data     statusModbus;
    S_FRQmetter_oper_data  statusFrqMetering;
    S_TIME_oper_data       statusClock;
    S_sensor_address       statusMeteo;
    S_bui_oper_data        statusBui;
}statusDescriptionT;
#pragma pack(pop)




/*******************************************************************/
/************INFORMP CONFIGURATION MEMORY MAP DESCRIPTION***********/
/*******************************************************************/

/*************GENERAL CONFIGURATION INFORMATION DESCRIPTION*******/
#pragma pack(push,1)
typedef struct{
    uint16_t MODULE_0:1;
    uint16_t MODULE_1:1;
    uint16_t MODULE_2:1 ;
    uint16_t MODULE_3:1 ;
    uint16_t MODULE_4:1 ;
    uint16_t MODULE_5:1 ;
    uint16_t MODULE_6:1 ;
    uint16_t MODULE_7:1 ;
    uint16_t MODULE_8:1 ;
    uint16_t MODULE_9:1 ;
    uint16_t MODULE_10:1 ;
    uint16_t MODULE_11:1 ;
    uint16_t MODULE_12:1 ;
    uint16_t MODULE_13:1 ;
    uint16_t MODULE_14:1 ;
    uint16_t MODULE_15:1 ;
}BF_dev_staff;

typedef struct{
    BF_dev_staff    bf_dev_staff;        // list of moduls
    uint16_t        num_use_uart;        // quantity of UARTS for MODBUS
    uint16_t        num_reg_data;        // not use
    uint16_t        modbus_req_user;     // not use
    uint16_t        program_version;     // FW version
}S_dev_staff;

typedef struct{
    uint32_t day:5;      //31 -  0b11111   5 bit
    uint32_t mounth:4;   //12 -  0b1100    4 bit
    uint32_t year:6 ;    //63 -  0b111111  6 bit
    uint32_t hour:5 ;    //23    0b10111   5 bit
    uint32_t minute:6;   //60 -  0b111100  6 bit
    uint32_t second:6;   //60 -  0b111100  6 bit
}BF_date_config;
#pragma pack(pop)

/*************MODBUS MODULE CONFIGURARION DESCRIPTION****************/
typedef enum {
    PROTOCOL_MODBUS_MASTER = (uint8_t)0,
    PROTOCOL_MODBUS_SLAVE  = (uint8_t)1,
} PORT_PROTOCOL;

#pragma pack(push,1)
typedef struct {
    uint16_t baudrate;
    uint8_t stopbits;
    uint8_t parity;
    uint8_t amountbyte;
    uint8_t controlpotok;
 } S_port_config;

typedef struct {
    uint8_t state;
    S_port_config s_port_config;   //
    uint8_t type;
    uint16_t waitresp;
    uint8_t number_of_pribor;
    uint8_t number_no_answer;
    uint8_t adress_kp;
} S_connectmodbus;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct {
    uint8_t state;
    uint16_t baudrate;
    uint8_t parity;
    uint8_t address;
} S_bui_config;
#pragma pack(pop)

/*************FRQ METERING MODULE CONFIGURARION DESCRIPTION**********/
#pragma pack(push,1)
typedef struct{
    uint8_t state;           // state of module ENABLE/DISABLE
    int16_t  frqCorrection;   // correction of measured frequency: 1 = 1/100 Hz
}S_FRQmetter_user_config;
#pragma pack(pop)

/*************CLOCK MODULE CONFIGURARION DESCRIPTION****************/
typedef enum
{
    SYNC_SOURCE_GPS    = 0,
    SYNC_SOURCE_SERVER = 1,
}SYNC_SOURCE;

#pragma pack(push,1)
typedef struct
{
    uint16_t  timeCorection:14;  // time correction in minutes
    uint16_t  isMinusCorrection:1;
    uint16_t  isDaylightSaving:1;
}clockIndConfigT;

typedef struct{
    uint8_t state;                               // state of module ENABLE/DISABLE
    uint16_t synchronizationSource;
    clockIndConfigT clockConfig[CLOCK_QUANTITY];
}S_TIME_user_config;
#pragma pack(pop)

/*************METEO MODULE CONFIGURARION  DESCRIPTION****************/
typedef enum
{
    METEO_SOURCE_LOCAL,
    METEO_SOURCE_REMOTE
}METEO_SOURCE;

#pragma pack(push,1)
typedef struct{
    uint8_t state;    // state of module ENABLE/DISABLE
    uint16_t source;  // pressure sensitivity
}S_sensor_user_config;
#pragma pack(pop)

/*************DISPLAY MODULE CONFIGURARION DESCRIPTION**************/
typedef enum {
    LCD_VALUE_DATE_1,
    LCD_VALUE_TIME_1,
    LCD_VALUE_DATE_2,
    LCD_VALUE_TIME_2,
    LCD_VALUE_DATE_3,
    LCD_VALUE_TIME_3,
    LCD_VALUE_DATE_4,
    LCD_VALUE_TIME_4,
    LCD_VALUE_FRQ,
    LCD_VALUE_TEMPERATURE,
    LCD_VALUE_HUMIDITY,
    LCD_VALUE_PRESSURE,
    LCD_VALUE_PRESSURE_GPA,
    LCD_VALUE_PRESSURE_BUI,
    LCD_VALUE_CNT
} LcdValue;
#define QUANTITY_LCD_STRING 4


#pragma pack(push,1)
typedef struct{
    uint8_t state;                           // state of module: ENABLE/DISABLE
    uint16_t numScreen;                       // number of screen connected to device
    struct{                                   // configuration parameters of every screen
       uint32_t numParamiterPerScreen: 8;
       uint32_t bitsOfParamiters:     (32 - 8);
    }screenConfig[QUANTITY_LCD_STRING];
}S_display_user_config;
#pragma pack(pop)

/********TOTAL  CONFIGURARION  DESCRIPTION***************/

/*this type use only for calculate offset of user configuration registers*/
#pragma pack(push,1)
typedef struct
{
    S_dev_staff              configStaff;
    BF_date_config           configDate;
    S_connectmodbus          configModbus;
    S_FRQmetter_user_config  configFrqMetering;
    S_TIME_user_config       configClock;
    S_sensor_user_config     configMeteo;
    S_display_user_config    configLCD;
    S_bui_config             configBui;
}configAddressFields;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
    BF_date_config           configDate;
    S_connectmodbus          configModbus;
    S_FRQmetter_user_config  configFrqMetering;
    S_TIME_user_config       configClock;
    S_sensor_user_config     configMeteo;
    S_display_user_config    configLCD;
    S_bui_config             configBui;
}configDescriptionT;
#pragma pack(pop)

#pragma pack(push,1)
typedef union{
    configDescriptionT configDescription;
    uint8_t memBuff[sizeof(configDescriptionT)];
}transactionBufferT;
#pragma pack(pop)

#define ALL_CONFIG_NUM_REG    static_cast<uint16_t>((sizeof(configAddressFields) + 1) / 2 )
#define USER_CONDFIG_ADDRESS  static_cast<uint16_t>(USER_ADDRESS_CONFIG_DATA + (offsetof(configAddressFields, configDate) / 2))
#define USER_CONFIG_NUM_REG   static_cast<uint16_t>((sizeof(configDescriptionT) + 1) / 2 )
#define STATUS_NUM_REG        static_cast<uint16_t>((sizeof(statusDescriptionT) + 1) / 2)


#endif // INFORMPMEMMAP_H
