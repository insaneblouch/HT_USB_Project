#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "Config.h"

/*----------------------------------------
The Delay is complete with 16Mhz,6Mhz by James
Before you Use this all functionality, 
must know the notification write down here

1.This code is write by "C"-code that is mean that 
	we could not be developing a delay function 
	with very correct timing

2.Functions which named without "n" were corrected
	by scope
	
3.Another functions they are all with a little
	mismatch because i use the loop-function & func_call 

4.Functions timing deviation will increasing with delay-time

5.The "n"-function with stanger Multiple is because considered 
	loop-function & func_call at (16Mhz)

i.e HT66FB550_Delay_n_103us(5) = 515us
	HT66FB550_Delay_n_13us(5) = 65.7us
------------------------------------------*/

#if HT66FB550_MCU_Speed == HT66FB550_6Mhz
    #define tm2al_reload_100us  0x10; 
    #define tm2ah_reload_100us  0x02;
    #define tm2al_reload_1ms  	0x5E; 
    #define tm2ah_reload_1ms  	0x00;
    #define tm2al_reload_10ms  	0x3C; 
    #define tm2ah_reload_10ms  	0x01;
    #define tm2al_reload_100ms  0x18; 
    #define tm2ah_reload_100ms  0x03;
#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz
    #define tm2al_reload_100us  0x80; 
    #define tm2ah_reload_100us  0x01;
    #define tm2al_reload_10ms  	0x3C; 
    #define tm2ah_reload_10ms  	0x01;
    #define tm2al_reload_100ms  0x18; 
    #define tm2ah_reload_100ms  0x03;
#endif

#define tm2reload(x,y)	_tm2al=x;_tm2ah=y;
	
#if HT66FB550_MCU_Speed == HT66FB550_6Mhz
	#define HT66FB550_Delay_2us()		asm("nop");asm("nop");asm("nop");
	void HT66FB550_Delay_20us(void);
	void HT66FB550_Delay_100us(void);
	void HT66FB550_Delay_1ms(void);
	void HT66FB550_Delay_10ms(void);
	void HT66FB550_Delay_100ms(void);
	void HT66FB550_Delay_1s(void);
	void HT66FB550_Delay_n_10ms(short n);
	void HT66FB550_Delay_n_100ms(short n);
	void HT66FB550_Delay_n_1s(short n);

#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz

	#define HT66FB550_Delay_1us()	asm("nop");asm("nop");asm("nop");asm("nop");
	void HT66FB550_Delay_10us(void);
	void HT66FB550_Delay_100us(void);
	void HT66FB550_Delay_1ms(void);
	void HT66FB550_Delay_10ms(void);
	void HT66FB550_Delay_100ms(void);
	void HT66FB550_Delay_1s(void);
	void HT66FB550_Delay_n_13us(short n);
	void HT66FB550_Delay_n_103us(short n);
	void HT66FB550_Delay_n_10ms(short n);
	void HT66FB550_Delay_n_100ms(short n);
	void HT66FB550_Delay_n_1s(short n);

#endif