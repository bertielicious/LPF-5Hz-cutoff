#include "constVar.h"
#include "clearSSD1309.h"
void __interrupt()phil_isr(void)
{ 
    if(INTCONbits.TMR0IF == HI)
    {  
        clearSSD1309();
        LED = ~LED;// update screen buffer with current needle position and write to oled *30 per second
    }
    TMR0 = 0x00;                                        
    INTCONbits.TMR0IF = LO;
}
