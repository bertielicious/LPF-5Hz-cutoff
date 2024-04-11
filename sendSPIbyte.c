#include "constVar.h"
void sendSPIbyte(uint8_t SPIbyte)
{
   SSP1BUF = SPIbyte; // load byte data into SSP1BUF
   while(SSPSTATbits.BF != HI) // transmit bitsd MSB first until buffer SSP1BUF is empty
   {
       ;// wait for all 8 bits to be transmitted
   }
}
