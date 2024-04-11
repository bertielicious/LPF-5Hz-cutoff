/*Function to find the page (vertical) and byte (position within page) for a corresponding
 y value from 0 to 63.The columns position (0-127) is directly configured*/
#include "constVar.h"
#include "getYposition.h"
#include "setColAddr.h"
#include "setGDDRAMPageAddr.h"
#include "writeSPIdata.h"
void drawPixel(uint8_t col, uint8_t row)
{
    pix pixel;
    pix *p;
    p = &pixel;
    p->yVal = row;
    p->xVal = col;
    getYposition(&pixel);
    setColAddr(p->xVal);
    setGDDRAMPageAddr(p->page);
    writeSPIdata(p->yByte); // write a pixel
  
}
