
/*Internal Oscillator Frequency p62 of data sheet
Selection Using the PLL
The Internal Oscillator Block can be used with the PLL
associated with the External Oscillator Block to
produce a 24 MHz, 32 MHz or 48 MHz internal system
clock source. The following settings are required to use
the PLL internal clock sources:
? The FOSC bits of the Configuration Words must
be set to use the INTOSC source as the device
system clock (FOSC<2:0> = 100).
? The SCS bits of the OSCCON register must be
cleared to use the clock determined by
FOSC<2:0> in Configuration Words
(SCS<1:0> = 00).
? For 24 MHz or 32 MHz, the IRCF bits of the
OSCCON register must be set to the 8 MHz
HFINTOSC set to use (IRCF<3:0> = 1110).
? For 48 MHz, the IRCF bits of the OSCCON register
must be set to the 16 MHz HFINTOSC set to
use (IRCF<3:0> = 1111).
? For 24 MHz or 48 MHz, the 3x PLL is required.
The SPLLMULT of the OSCCON register must be
set to use (SPLLMULT = 1).
? For 32 MHz, the 4x PLL is required. The
SPLLMULT of the OSCCON register must be
clear to use (SPLLMULT = 0).
? The SPLLEN bit of the OSCCON register must be
set to enable the PLL, or the PLLEN bit of the
Configuration Words must be programmed to a
?1?.
The PLL is not available for use with the internal oscillator
when the SCS bits of the OSCCON register are
set to ?1x?. The SCS bits must be set to ?00? to use the
PLL with the internal oscillator.*/
#include "constVar.h"
void configOsc(void)
{
    #pragma config  FOSC = INTOSC

    OSCCONbits.SPLLMULT = HI;     /*By setting the SPLLMULT bit of the
                                    OSCCON register, 3x PLL is selected
                                   */
                                   /*   Write the SPLLEN bit in the OSCCON register to
                                   a ?1?. If the PLLEN bit in Configuration Words is
                                    programmed to a ?1?, then the value of SPLLEN
                                    is ignored.*/  
    OSCCONbits.SPLLEN = HI;
    


                                    
    /*Internal Oscillator Frequency Select 
     * bits  1111 = 16 MHz*/
    OSCCONbits.IRCF3 = HI;
    OSCCONbits.IRCF2 = HI;
    OSCCONbits.IRCF1 = HI;
    OSCCONbits.IRCF0 = HI;
    
    /*System Clock Select bits
    1x = Internal oscillator block*/
    OSCCONbits.SCS1 = LO;
    OSCCONbits.SCS0 = LO;
  
}
