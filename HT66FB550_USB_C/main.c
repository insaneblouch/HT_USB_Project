#include "HT66FB550.h"
#include "HT66FB550_MCU.h"
#include "HT66FB550_IO.h"
#include "HT66FB550_typedef.h"

void main()
{
	HT66FB550_MCU_Init();
	HT66FB550_IO_INIT();
	//_acer0 = 0;
	//_acer1 = 0;
	//_pbc = 0;
	UART_Init();
	UART_Start();
	_pb1 = 1;
	loop:
	goto loop;
}