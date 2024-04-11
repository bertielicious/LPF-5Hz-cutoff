#include "constVar.h"
#include "writeSPIcommand.h"
void rightScroll(void)
{
    writeSPIcommand(0x2e);  //deactivate scroll
    writeSPIcommand(0x27);  // horizontal scrolling
    writeSPIcommand(0x00);  //dummy byte
    writeSPIcommand(0x00);  //Define start page address = 0
    writeSPIcommand(0x00);  //Set time interval between each scroll step in terms of frame frequency = 5 frames
    writeSPIcommand(0x05);  //Define end page address = 5
    writeSPIcommand(0x00);  //dummy byte
    writeSPIcommand(0x00); //Define the start column (RESET = 00h) = 0
    writeSPIcommand(0x7f); //Define the end column address (RESET =7Fh) = 127
    
    writeSPIcommand(0x2f); //activate scroll
}
