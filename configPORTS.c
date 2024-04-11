#include "constVar.h"
void configPORTS(void)
{
    CM1CON0 = 0x00; // all comparators off
    CM2CON0 = 0x00;
    
    TRISCbits.TRISC6 = LO;  //CS pin 8 active low
    TRISCbits.TRISC7 = LO;  //SDO pin 9
    TRISBbits.TRISB6 = LO;  // SCK pin 11
    TRISAbits.TRISA4 = LO;  //RST pin 3
    TRISAbits.TRISA5 = LO;  //DC pin 2
    TRISCbits.TRISC4 = LO;  // LED pin 6 is and output
}
