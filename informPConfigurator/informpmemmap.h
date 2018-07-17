#ifndef INFORMPMEMMAP_H
#define INFORMPMEMMAP_H

#include "stdint.h"

//address of first statys register
#define USER_ADDRESS_STATUS_DATA  500

//address of first configuration register
#define USER_ADDRESS_CONFIG_DATA  1000


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
    uint16_t device_statys;	         // device status register
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


#pragma pack(push,1)
typedef struct{
    uint16_t  status_TIME; // status register TIME module
    uint16_t  date_year;    // date: year
    uint16_t  date_month;   // date: month
    uint16_t  date_day;     // date: day
    uint16_t  time_honour;  // time: honour
    uint16_t  time_minute;  // time: minute
    uint16_t  time_second;  // time: second
    uint16_t  DATE;
    uint16_t  TIME;
} S_TIME_oper_data;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct{
    uint16_t  status_sensor;     // ñòàòóñ ðåãèñòðû sensor
    uint16_t  rezTemperature;    // address in memory map rez measure temperature*10
    uint16_t  rezHumidity;       // address in memory map rez measure humidity *10
    uint16_t  rezPressure_mmHg;  // measurement result Pressure mmHg
    uint16_t  rezPressure_GPasc; // measurement result Pressure GPasc
} S_sensor_address;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
    S_devise_reset_status  statusDevice;
    S_modbus_oper_data     statusModbus;
    S_FRQmetter_oper_data  statusFrqMetering;
    S_TIME_oper_data       staqtusClock;
    S_sensor_address       statusMeteo;
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
    uint16_t             num_use_uart;        // quantity of UARTS for MODBUS
    uint16_t             num_reg_data;        // not use
    uint16_t             modbus_req_user;     // not use
    uint16_t             program_version;     // FW version
    uint16_t             CRC_dev;             // total CRC
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

/*************MODBUS MODULE DESCRIPTION****************/
typedef enum {
    PROTOCOL_MODBUS_MASTER,
    PROTOCOL_MODBUS_SLAVE,
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
    uint16_t state;
    S_port_config s_port_config;   //
    PORT_PROTOCOL type;
    uint16_t waitresp;
    uint8_t number_of_pribor;
    uint8_t number_no_answer;
    uint8_t adress_kp;
} S_connectmodbus;
#pragma pack(pop)

/*************FRQ METERING MODULE DESCRIPTION**********/
#pragma pack(push,1)
typedef struct{
    uint16_t state;           // state of module ENABLE/DISABLE
    int16_t  frqCorrection;   // correction of measured frequency: 1 = 1/100 Hz
}S_FRQmetter_user_config;
#pragma pack(pop)

/*************CLOCK MODULE DESCRIPTION****************/
typedef enum
{
    SYNC_SOURCE_GPS    = 0,
    SYNC_SOURCE_SERVER = 1,
}SYNC_SOURCE;

#pragma pack(push,1)
typedef struct{
    uint16_t  state;          // state of module ENABLE/DISABLE
    uint16_t  timeCorection;  // time correction in hours
    uint16_t  isDaylightSaving:1;
    uint16_t  synchronizationSource:15;  // time correction in hours
}S_TIME_user_config;
#pragma pack(pop)

/*************METEO MODULE DESCRIPTION****************/
typedef enum
{
    METEO_SOURCE_LOCAL,
    METEO_SOURCE_REMOTE
}METEO_SOURCE;

#pragma pack(push,1)
typedef struct{
    uint16_t state;         // state of module ENABLE/DISABLE
    uint16_t source;  // pressure sensitivity
}S_sensor_user_config;
#pragma pack(pop)

/*************DISPLAY MODULE DESCRIPTION**************/
#define NUMBER_OF_VALUE      7
#define NUMBER_OF_LCD_STRING 4

#pragma pack(push,1)
typedef struct{
    uint16_t state;                           // state of module: ENABLE/DISABLE
    uint16_t numScreen;                       // number of screen connected to device
    struct{                                   // configuration parameters of every screen
       uint16_t numParamiterPerScreen: 3;
       uint16_t bitsOfParamiters:      16 - 3;
    }screenConfig[NUMBER_OF_LCD_STRING];
}S_display_user_config;
#pragma pack(pop)

/********TOTAL MEMORY MAP DESCRIPTION***************/
#pragma pack(push,1)
typedef struct
{
    S_dev_staff              configStaff;
    BF_date_config           configDate;
    S_connectmodbus          configModbus;
    S_FRQmetter_user_config  configFrqMetering;
    S_TIME_user_config       configClock;
    S_sensor_user_config     confifgMeteo;
    S_display_user_config    configLCD;
}configDescriptionT;
#pragma pack(pop)

#pragma pack(push,1)
typedef union{
    configDescriptionT configDescription;
    uint8_t memBuff[sizeof(configDescriptionT)];
}transactionBufferT;
#pragma pack(pop)

#define CONFIGURATION_NUM_REG (uint16_t)(sizeof(configDescriptionT)/2)

#endif // INFORMPMEMMAP_H
