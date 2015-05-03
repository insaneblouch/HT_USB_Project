#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "Config.h"

/*  HT66FB550 INIT
    step:
        1.setting PLL(configure by config.h)
        2.cancel WDT
    Notification: This function is also cancel USB-related config
*/
//#ifndef HT66FB550_MCU_Speed
	//#define HT66FB550_MCU_Speed HT66FB550_16Mhz
//#endif

#if HT66FB550_MCU_Speed == HT66FB550_6Mhz
void HT66FB550_MCU_Init(void)
{
	//1.setting PLL source(6Mhz) -> PLL -> Fh=16Mhz -> Fsys=16Mhz (It seem like little error in here, try later)
    _ucc    = 0x60;         //sysclk=6MHz,Fsys16MHz=1
    _usc    = 0x20;         //pll=on
    _smod   = 0xE1;         //Fsys_clock_divider=none;direct come for Fh
    //2.cancel WDT
    _wdtc   = 0xAC;
}
#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz
void HT66FB550_MCU_Init(void)
{
    //1.setting PLL source(6Mhz) -> PLL -> Fh=16Mhz -> Fsys=16Mhz (It seem like little error in here, try later)
    _ucc    = 0x60;         //sysclk=6MHz,Fsys16MHz=1
    _usc    = 0x00;         //pll=on
    _smod   = 0xE1;         //Fsys_clock_divider=none;direct come for Fh
    //2.cancel WDT
    _wdtc   = 0xAC;
}

#endif