#include "constVar.h"
#include "setGDDRAMPageAddr.h"
#include "setColAddr.h"
#include "writeSPIdata.h"
void drawArray(void)
{
    uint16_t col;
    
    
     uint8_t page = 0;
    setGDDRAMPageAddr(page);
    for(col = 0; col < 128; col++)
    {
        setColAddr(col);
        writeSPIdata(newQuad[col]);
       
    }
    page = 1;
    setGDDRAMPageAddr(page);
    for(col = 128; col < 256; col++)
    {
        setColAddr(col-128);
        writeSPIdata(newQuad[col]);
       
    }
    
    page = 2;
    setGDDRAMPageAddr(page);
    for(col = 256; col < 384; col++)
    {
        setColAddr(col-256);
        writeSPIdata(newQuad[col]);
       
    }
    
    page = 3;
    setGDDRAMPageAddr(page);
    for(col = 384; col < 512; col++)
    {
        setColAddr(col-384);
        writeSPIdata(newQuad[col]);
       
    }
    
    page = 4;
    setGDDRAMPageAddr(page);
    for(col = 512; col < 640; col++)
    {
        setColAddr(col-512);
        writeSPIdata(newQuad[col]);
       
    }
    
    page = 5;
    setGDDRAMPageAddr(page);
    for(col = 640; col < 768; col++)
    {
        setColAddr(col-640);
        writeSPIdata(newQuad[col]);
       
    }
    /*page = 6;
    setGDDRAMPageAddr(page);
    for(col = 768; col < 896; col++)
    {
        setColAddr(col-768);
        writeSPIdata(newQuad[col]);
       
    }
    page = 7;
    setGDDRAMPageAddr(page);
    for(col = 896; col < 934; col++)
    {
        setColAddr(col-896);
        writeSPIdata(newQuad[col]);
       
    }*/
}
