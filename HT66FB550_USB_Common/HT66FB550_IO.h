#include "HT66FB550.h"
#include "HT66FB550_typedef.h"

#ifndef HT66FB550_IO_H
#define HT66FB550_IO_H


//be careful, this function will clear all ADC port
void HT66FB550_IO_INIT(void);
void HT66FB550_IO_DIR(char port, char pin, char direction);
void HT66FB550_IO_Data(char port, char pin, char data);
void HT66FB550_IO_Pull_High(char port, char pin, char data);

//port-A provide high current control each pin independent
void HT66FB550_IO_High_Current(char port, char data);


//i didn't write it yet
//you can try to modified "_paoi" to control it
void HT66FB550_IO_Slew_Rate(void);
void HT66FB550_IO_Port_A_Output_Power_Control(char pin, char power_source);


enum 
{
	HT66FB550_MCU_IO_PA=0,
	HT66FB550_MCU_IO_PB,
	HT66FB550_MCU_IO_PC,
	HT66FB550_MCU_IO_PD,
	HT66FB550_MCU_IO_PE
};

enum
{
	HT66FB550_MCU_IO_PIN0=0,
	HT66FB550_MCU_IO_PIN1,
	HT66FB550_MCU_IO_PIN2,
	HT66FB550_MCU_IO_PIN3,
	HT66FB550_MCU_IO_PIN4,
	HT66FB550_MCU_IO_PIN5,
	HT66FB550_MCU_IO_PIN6,
	HT66FB550_MCU_IO_PIN7,
	HT66FB550_MCU_IO_PINALL=0xff
};

enum
{
	HT66FB550_MCU_IO_OUTPUT=0x00,
	HT66FB550_MCU_IO_INPUT=0xFF	
};

enum
{
	HT66FB550_MCU_IO_DATA_SET=0x01,
	HT66FB550_MCU_IO_DATA_CLEAR=0x00	
};
/*
	¡°you must type full data if it set all pins
	ex : HT66FB550_IO_DATA(HT66FB550_MCU_IO_PA,HT66FB550_MCU_IO_PINALL,0xAA)
	ex : HT66FB550_IO_PULL_HIGH(HT66FB550_MCU_IO_PA,HT66FB550_MCU_IO_PINALL,0xAA)
*/


#endif