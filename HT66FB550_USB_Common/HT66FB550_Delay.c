#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "HT66FB550_UART.h"
#include "HT66FB550_Delay.h"
#include "Config.h"

void HT66FB550_Delay_1us(void);
void HT66FB550_Delay_10us(void);
void HT66FB550_Delay_100us(void);
void HT66FB550_Delay_n_10us(short n)
{
	while(n--){ HT66FB550_Delay_10us();}	
}

void HT66FB550_Delay_n_100us(short n)
{
	while(n--){ HT66FB550_Delay_100us();}
}

void HT66FB550_Delay_1ms(void);

void HT66FB550_Delay_10ms(void)
{
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
	HT66FB550_Delay_1ms();
}

void HT66FB550_Delay_100ms(void);

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




