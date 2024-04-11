#include "constVar.h"
#include "writeSPIcommand.h"
void setGDDRAMPageAddr(uint8_t page)
{
    int16_t pageAddr = 0;
    int16_t pageOffset = 0xb0;
    pageAddr =  pageOffset|page;
    writeSPIcommand(pageAddr);
}
