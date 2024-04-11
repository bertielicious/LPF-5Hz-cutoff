
#include "constVar.h"
void configADC(void)
{
     /*Enable the ADC module*/
    ADCON0bits.ADON = HI;
   
    ANSELCbits.ANSC7 = LO;  /* disable the ADC inputs on RC6, RC7 and RA4 as there are used
                             as digital output pins for the SPI interface*/
    ANSELCbits.ANSC6 = LO;
    ANSELAbits.ANSA4 = LO;
    
    /*****PORT CONFIGURATION******/
    TRISCbits.TRISC3 = HI;  // RC3 pin 7 is our ADC analogue input pin 7 - Disable output driver
    ANSELCbits.ANSC3 = HI;  // set ANSC3 to enable ADC input
    
    /*****CHANNEL SELECTION********
    The CHS bits of the ADCON0 register determine which
    channel is connected to the sample and hold circuit 
     00011 = AN3*/
  
    ADCON0bits.CHS0 = HI;// AN7 channel selected for ADC input
    ADCON0bits.CHS1 = HI;
    ADCON0bits.CHS2 = HI;
    ADCON0bits.CHS3 = LO;
    ADCON0bits.CHS4 = LO;
    
    /******Enable the Fixed Voltage Reference module**********
     The FVR can be enabled by setting the FVREN bit of
    the FVRCON register.*/
    FVRCONbits.FVREN = HI; // FVR module is enabled
    
    /*******ADC voltage reference selection******
    The ADPREF bits of the ADCON1 register provides
    control of the positive voltage reference. The positive
    voltage reference can be:
    ? VREF+ pin
    ? VDD
    See Section 14.0 ?Fixed Voltage Reference (FVR)
     for more details on the Fixed Voltage Reference.*/
    
   // FVRCONbits.ADFVR1 = LO; // ADC ref voltage = 1.024V = 1024 or 2^10
   // FVRCONbits.ADFVR0 = HI; 
    /*ADFVR<1:0>: ADC Fixed Voltage Reference Selection bit
     * ADFVR1    ADFVR0
        1           1       = ADC Fixed Voltage Reference Peripheral output is 4x (4.096V)(2)
        1           0       = ADC Fixed Voltage Reference Peripheral output is 2x (2.048V)(2)
        0           1       = ADC Fixed Voltage Reference Peripheral output is 1x (1.024V)
        0           0       = ADC Fixed Voltage Reference Peripheral output is off*/
   ADCON1bits.ADPREF1 = LO; //
   ADCON1bits.ADPREF0 = HI;
   
   FVRCONbits.CDAFVR1 = LO;
   FVRCONbits.CDAFVR0 = HI;
    /********CONVERSION CLOCK source
    Fosc/16 101
     The source of the conversion clock is software selectable
    via the ADCS bits of the ADCON1 register.*/
    ADCON1bits.ADCS2 = HI;
    ADCON1bits.ADCS1 = HI;
    ADCON1bits.ADCS0 = LO;
    
    /*******RESULT FORMATTING
The 10-bit A/D conversion result can be supplied in two
formats, left justified or right justified.
     We are going for right justified, so ADFM bit of ADCON1 register = HI*/
    ADCON1bits.ADFM = HI;// high byte    low byte
                     //     bit10|bit9  |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0
    
   
    PIR1bits.ADIF = LO;
   /*****CLEAR THE ADC RESULT REGISTER PAIR*****/
    ADRESH = 0x00;
    ADRESL = 0x00;
}
