                       #include "constVar.h"
#include "sendSPIbyte.h"
void writeSPIcommand(uint8_t command)
{
    CS = LO;      // enable SSD1309 chip
    DC = LO;     // interpret data as command by SSD1309
    sendSPIbyte(command);
   
    CS = HI;    // disable SSD1309 chip
}
