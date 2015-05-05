#include "HT66FB550.h"
#include "HT66FB550_MCU.h"
#include "HT66FB550_IO.h"
#include "HT66FB550_typedef.h"
#include "HT66FB550_UART.h"

void main()
{
	volatile int a;
	HT66FB550_MCU_Init();
	HT66FB550_IO_INIT();
	//_acer0 = 0;
	//_acer1 = 0;
	//_pbc = 0;
	UART_Init();
	
	_pb1 = 1;
	loop:
	UART_Put_Char(0x42);
	UART_Put_Char(0x42);
	UART_Put_Char(0x42);
	UART_Put_Char(0x43);
	UART_Put_Char(0x42);
	UART_Put_Char(0x41);
	UART_Put_Char(0x41);
	UART_Put_Char('\n');
	UART_Start();
	for(a=0; a<10000; a++);
	goto loop;
}