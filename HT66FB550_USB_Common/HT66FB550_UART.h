#include "HT66FB550.h"
#include "HT66FB550_typedef.h"

/*
	The UART Baudrate is 19200/9600 at MCU_Speed 16MHz/6MHz
	Why didn't i use fast Baudrate?
	It's because The MCU cannot working so fast
	Specailly i use c program rather asm
*/

void UART_ISR(void);
//Must be setting "HT66FB550_MCU_Speed"
void UART_Init(void);
void UART_Start(void);
void UART_Stop(void);
char UART_Put_Char(char ch);

enum UART_state{
	UART_Buffer_Full=1,
	UART_Buffer_Add_Success
};