#include "constVar.h"
#include "writeSPIcommand.h"
#include "writeSPIdata.h"
#include "setGDDRAMPageAddr.h"
#include "setColAddr.h"
void clearSSD1309(void)
{
    uint8_t page = 0;
    uint8_t col = 0;
   
   /* writeSPIcommand(0x20);    // set memory addressing mode
    writeSPIcommand(0x02);    // to Page Addressing Mode
    writeSPIcommand(0x00 + (0 & 0x0f));// low nibble of col is 0
    writeSPIcommand(0x10 + ((127>>4) & 0x0f));// high nibble of col is 127*/
  //  writeSPIcommand(0x00);  //set lower column start address for page addressing mode (column start address is 0))
  //  writeSPIcommand(0x10);  //set higher column start address for page addressing mode - this is the same as the RESET state
    
    
    for(page = 0; page <8; page++)
    {
        setGDDRAMPageAddr(page);   // set page from 0 to 7 for each increment of page
        for(col = 0; col < 128; col++)      
        {
            setColAddr(col);
            writeSPIdata(0x00);       // clear each byte of graphics data from col = 0 to col = 127
        }
    }
}
