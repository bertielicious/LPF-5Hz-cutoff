/*This function allows the setting of three addressing modes, page addressing mode, horizontal
 addressing mode and vertical addressing mode*/

#include "constVar.h"
#include "writeSPIcommand.h"
void setMemoryAddressingMode(uint8_t mode)
{
    writeSPIcommand(0x20);
    if(mode==0x00)
    {
        writeSPIcommand(0x00);     //Horizontal addressing mode
    }
    else if(mode == 0x01)
    {
        writeSPIcommand(0x01);     //Vertical addressing mode
    }
    
    else if(mode == 0x02)
    {
        writeSPIcommand(0x02);     //Page addressing mode
    }
    
    
}
