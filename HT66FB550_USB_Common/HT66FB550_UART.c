#ifndef HT66FB550_UART_H
#define HT66FB550_UART_H

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

char uart_step,uart_out_buf,uart_pin_buf,uart_head,uart_tail;
volatile static unsigned char uart_buf[100]__attribute__((at(0x480)));

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
	UART_TX_PIN = uart_pin_buf;
	switch(uart_step)
	{
		case 0:
			uart_pin_buf=0;
			break;	
		case 1:
		case 3:
		case 5:
		case 7:
		case 2:
		case 4:
		case 6:
		case 8:
            uart_pin_buf = uart_out_buf & 0x01;
            uart_out_buf = uart_out_buf >> 1;
			break;
		case 9:		//stop bit
		case 10:	//stop bit hold
		case 11:	//stop bit hold
			uart_pin_buf = 1;
			break;
		case 12:
            if((uart_head==uart_tail) & (uart_buf[uart_head]==0)){
                UART_Stop();
                return;
            }
            uart_step = -1;
            uart_pin_buf=1;
            uart_out_buf = uart_buf[uart_tail];
            //uart_out_buf = 0x41;
            uart_buf[uart_tail] = 0;
            uart_tail++;
            uart_tail = uart_tail & 0x7f;
			break;		
	}
	uart_step++;
	return;
}
void UART_Init(void)
{
    _tm3c0 = 0x10;
    _tm3c1 = 0xC0;
    uart_head = 0;
    uart_tail = 0;
	tm3reload();
    _mf3e = 1;
    _t3ae = 1;
    _emi = 1;
}

void UART_Start(void)
{
	if(_t3on)
		return;
    if(uart_head!=uart_tail){
        uart_out_buf = uart_buf[uart_tail];
        uart_buf[uart_tail] = 0;
        uart_tail++;
        uart_tail = uart_tail & 0x7f; 
    }else if(uart_buf[uart_head]!=0){
        uart_out_buf = uart_buf[uart_tail];
        uart_buf[uart_tail] = 0;
        uart_tail++;
        uart_tail = uart_tail & 0x7f; 
    }else{
        return;
    }
    uart_step = 0;
	uart_pin_buf = 1;
    _t3on = 1;
}

void UART_Stop(void)
{
    _t3on = 0;
}

char UART_Put_Char(char ch)
{
    if(uart_head==uart_tail){
        if(uart_buf[uart_head]==0){
            uart_buf[uart_head] = ch;
            uart_head++;
            uart_head = uart_head & 0x7f; 
        }
        else{
            return UART_Buffer_Full;
        }
    }else{
        uart_buf[uart_head] = ch;
        uart_head++;
        uart_head = uart_head & 0x7f; 
    }
    return UART_Buffer_Add_Success;
}

#endif