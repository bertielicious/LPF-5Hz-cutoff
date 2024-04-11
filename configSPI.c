#include "constVar.h"
void configSPI(void)
{
    SSPCON1bits.SSP1M3 = LO;    // SPI Master mode, clock = FOSC/4
    SSPCON1bits.SSP1M2 = LO;
    SSPCON1bits.SSP1M1 = LO;
    SSPCON1bits.SSP1M0 = HI;
    SSPCON1bits.CKP = LO;      // Idle state for clock is a low level
    SSPCON1bits.SSPEN = HI;   // Enables serial port and configures SCK, SDO, SDI and SS as the source of the serial port pins.
                              // When enabled, these pins must be properly configured as input or output
    SSPCON1bits.SSPOV = LO;     // no overflow of SSPBUF register
    SSPCON1bits.WCOL = LO;  // no collision

    SSP1STATbits.CKE = HI;  //Transmit occurs on transition from idle to active clock state (positive going clock edge))
    SSP1STATbits.SMP = HI;    // input data sampled at middle of output data
    SSP1STATbits.BF = LO;       // Receive not complete, SSPBUF is empty
    CS = HI;    // disable SSD1309
}
