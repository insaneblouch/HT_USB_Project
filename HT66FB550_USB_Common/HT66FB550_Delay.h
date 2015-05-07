#include "HT66FB550.h"
#include "HT66FB550_typedef.h"
#include "Config.h"

#if HT66FB550_MCU_Speed == HT66FB550_6Mhz
    #define tm2al_reload_1us  0x04; 
    #define tm2ah_reload_1us  0x02;
    #define tm2al_reload_100us  0x04; 
    #define tm2ah_reload_100us  0x02;
    #define tm2al_reload_1ms  0x04; 
    #define tm2ah_reload_1ms  0x02;
    #define tm2al_reload_100ms  0x04; 
    #define tm2ah_reload_100ms  0x02;
#elif HT66FB550_MCU_Speed == HT66FB550_16Mhz
    #define tm2al_reload_1us  0xD8;
    #define tm2ah_reload_1us  0x02;
    #define tm2al_reload_100us  0x04; 
    #define tm2ah_reload_100us  0x02;
    #define tm2al_reload_1ms  0x04; 
    #define tm2ah_reload_1ms  0x02;
    #define tm2al_reload_100ms  0x04; 
    #define tm2ah_reload_100ms  0x02;
#endif

void HT66FB550_Delay_1us(void);
void HT66FB550_Delay_10us(void);
void HT66FB550_Delay_100us(void);
void HT66FB550_Delay_n_10us(short n);
void HT66FB550_Delay_n_100us(short n);
void HT66FB550_Delay_1ms(void);
void HT66FB550_Delay_10ms(void);
void HT66FB550_Delay_100ms(void);
void HT66FB550_Delay_n_10ms(short n);
void HT66FB550_Delay_n_100ms(short n);
void HT66FB550_Delay_1s(void);
void HT66FB550_Delay_n_1s(short n);