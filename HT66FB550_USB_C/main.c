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
	//UART_Init();
	
	
	loop:
	
	HT66FB550_Delay_10us();
	_pb1 = 0;
	HT66FB550_Delay_10us();
	_pb1 = 1;
	HT66FB550_Delay_10us();
	_pb1 = 0;
	
	goto loop;
}