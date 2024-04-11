#include "constVar.h"
void configTMR0interrupt(void)
{
    OPTION_REGbits.TMR0CS = LO; // 8 bit timer mode selected
    OPTION_REGbits.PSA = LO;    // enable the pre-scaler
    
/*  000     1 : 2
    001     1 : 4
    010     1 : 8
    011     1 : 16
    100     1 : 32
    101     1 : 64
    110     1 : 128
    111     1 : 256*/

    OPTION_REGbits.PS2 = HI;    // 1:256 pre-scaling
    OPTION_REGbits.PS1 = HI;
    OPTION_REGbits.PS0 = HI;
    TMR0 = 0x00;// 30ms interrupt
    INTCONbits.TMR0IF = LO; // TMRO did not overflow
    INTCONbits.TMR0IE = HI; //Enables the Timer0 interrupt
    INTCONbits.GIE = HI;                                                                 ;    // Enables all active interrupts
}
