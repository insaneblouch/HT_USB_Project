#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "HT66FB550_UART.h"
#include "Config.h"

#define UART_TX_PIN _pb1
#if HT66FB550_MCU_Speed == HT66FB550_6Mhz
    #define tm3al_reload  0x04; 
    #define tm3ah_reload  0x02;
#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz
    #define tm3al_reload  0xD8;
    #define tm3ah_reload  0x02;
#endif

#define tm3reload()	_tm3al=tm3al_reload;_tm3ah=tm3ah_reload;

void __attribute((interrupt(0x24)))	ISR_timer3(void)
{
	if(_t3af){
		_t3af = 0;
		_t3on = 0;
		_t3on = 1;
		UART_ISR();
	}		
	return;
}

void UART_ISR(void)
{
	UART_TX_PIN = !UART_TX_PIN;
	return;
}
void UART_Init(void)
{
    _tm3c0 = 0x10;
    _tm3c1 = 0xC0;
	tm3reload();
}

void UART_Start(void)
{
    _mf3e = 1;
    _t3ae = 1;
    _emi = 1;
    _t3on = 1;
}