#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "HT66FB550_UART.h"
#include "HT66FB550_Delay.h"
#include "Config.h"

#if HT66FB550_MCU_Speed == HT66FB550_6Mhz

void HT66FB550_Delay_20us(void)
{
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	HT66FB550_Delay_2us();
	asm("nop");
}

void HT66FB550_Delay_100us(void)
{
	_tm2c0 = 0x10;
    _tm2c1 = 0xC0;	
   	_t2af = 0;
	tm2reload(tm2al_reload_100us,tm2ah_reload_100us);
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);
}

void HT66FB550_Delay_1ms(void)
{
	_tm2c0 = 0x30;
    _tm2c1 = 0xC0;	
   	_t2af = 0;
	tm2reload(tm2al_reload_1ms,tm2ah_reload_1ms);
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);
}

void HT66FB550_Delay_10ms(void)
{
	_tm2c0 = 0x40;
    _tm2c1 = 0xC0;	
	tm2reload(tm2al_reload_10ms,tm2ah_reload_10ms);
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
}

void HT66FB550_Delay_100ms(void)
{
	_tm2c0 = 0x40;
    _tm2c1 = 0xC0;
	tm2reload(tm2al_reload_100ms,tm2ah_reload_100ms);
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
}

void HT66FB550_Delay_n_10ms(short n)
{
	while(n--){ HT66FB550_Delay_10ms();}	
}

void HT66FB550_Delay_n_100ms(short n)
{
	while(n--){ HT66FB550_Delay_100ms();}	
}

void HT66FB550_Delay_1s(void)
{
	HT66FB550_Delay_n_100ms(10);
}

void HT66FB550_Delay_n_1s(short n)
{
	while(n--){ HT66FB550_Delay_1s();}	
}

#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz

void HT66FB550_Delay_10us(void)
{
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
	HT66FB550_Delay_1us();
}

void HT66FB550_Delay_100us(void)
{
	_tm2c0 = 0x00;
    _tm2c1 = 0xC0;	
   	_t2af = 0;
	tm2reload(tm2al_reload_100us,tm2ah_reload_100us);
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);
}

void HT66FB550_Delay_n_13us(short n)
{
	while(n--){ HT66FB550_Delay_10us();}	
}

void HT66FB550_Delay_n_103us(short n)
{
	while(n--){ HT66FB550_Delay_100us();}
}

void HT66FB550_Delay_1ms(void)
{
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
	HT66FB550_Delay_100us();
}

void HT66FB550_Delay_10ms(void)
{
	_tm2c0 = 0x40;
    _tm2c1 = 0xC0;	
	tm2reload(tm2al_reload_10ms,tm2ah_reload_10ms);
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
}

void HT66FB550_Delay_100ms(void)
{
	_tm2c0 = 0x40;
    _tm2c1 = 0xC0;
	tm2reload(tm2al_reload_100ms,tm2ah_reload_100ms);
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
	_t2af = 0;
	_t2on = 0;
	_t2on = 1;
	while(!_t2af);	
}

void HT66FB550_Delay_n_10ms(short n)
{
	while(n--){ HT66FB550_Delay_10ms();}	
}

void HT66FB550_Delay_n_100ms(short n)
{
	while(n--){ HT66FB550_Delay_100ms();}	
}

void HT66FB550_Delay_1s(void)
{
	HT66FB550_Delay_n_100ms(10);
}

void HT66FB550_Delay_n_1s(short n)
{
	while(n--){ HT66FB550_Delay_1s();}	
}

#endif


