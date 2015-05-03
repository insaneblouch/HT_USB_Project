#include "HT66FB550.h"

/*  HT66FB550 INIT
    step:
        1.cancel WDT
        2.setting PLL(configure by config.h)
    Notification: This function is also cancel USB-related config
*/

#if (HT66FB550_6Mhz==HT66FB550_MCU_Speed)
void HT66FB550_MCU_Init(void)
{
	
}
#elif (HT66FB550_16Mhz==HT66FB550_MCU_Speed)
void HT66FB550_MCU_Init(void)
{
	//1.cancel WDT
    _wdtc   = 0xAC;
    //2.setting PLL source(6Mhz) -> PLL -> Fh=16Mhz -> Fsys=16Mhz (It seem like little error in here, try later)
    _ucc    = 0x60;         //sysclk=6MHz,Fsys16MHz=1
    _usc    = 0x20;         //pll=on
    _smod   = 0xE1;         //Fsys_clock_divider=none;direct come for Fh
}

#endif