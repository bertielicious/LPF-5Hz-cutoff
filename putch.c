#include "constVar.h"
void putch (char ch)
{
    while(PIR1bits.TXIF == LO)   //while TXREG busy transmitting data
    {
        continue;               //wait for transmission to finish
    }
        TXREG = ch;// load character  into TXREG ready for transmission   
}

