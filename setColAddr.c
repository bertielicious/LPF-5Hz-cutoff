
/*This function allows you t0 set the lower and higher column address when using PAGE ADDRESSING MODE only*/
#include "constVar.h"
#include "sendSPIbyte.h"
#include "writeSPIcommand.h"

void setColAddr(uint8_t colAddr)// colAddr can range from 0 - 127 (SEG = col + 0 - 127)
{
    uint8_t lowNib, hiNib;
    
    lowNib = colAddr & 0x0f;    // low nibble
    hiNib = ((colAddr & 0xf0)>>4 |0x10);    // hi nibble
    writeSPIcommand(lowNib);
    writeSPIcommand(hiNib);
   
}
