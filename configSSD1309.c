#include "constVar.h"
#include "writeSPIcommand.h"
void configSSD1309(void)
{
   // writeSPIcommand(0xDB);  // set VcomH
   // writeSPIcommand(0x34);  // RESET
  __delay_ms(500);  // wait for 3.3V to stabilize
   CS = LO;             // select OLED chip (active LOW)   
   RST = HI;
   __delay_ms(100);
   RST = LO;
     __delay_ms(300);
   RST = HI;
   __delay_ms(100);
  // Vcc1309 = LO;        // enable 3.3V power rail to SSD1309 OLED7
    __delay_ms(10);
    
   writeSPIcommand(0xAE);     //0xAE  Set OLED Display Off
   writeSPIcommand(0xD5);     //0xD5  Set Display Clock Divide Ratio/Oscillator Frequency
   writeSPIcommand(0x80);     // sets SSD1306 internal oscillator to it's value as if RESET
   writeSPIcommand(0xa8);     //0xA8  Set Multiplex Ratio
   writeSPIcommand(0x3f);     //lines COM0 to COM63 for 128 x 64 display. 63 = 0x3f
   writeSPIcommand(0xd3);     //0xD3  Set Display Offset
   writeSPIcommand(0x00);     //affects the line characters are displayed
   writeSPIcommand(0x40);     //0x40  Set Display Start Line
 
   writeSPIcommand(0x8d);     //0x8D  Set Charge Pump
   writeSPIcommand(0x14);     //0x14  Enable Charge Pump
   writeSPIcommand(0xc8);     //0xC8  Set COM Output Scan Direction
   writeSPIcommand(0xda);     //0xDA  Set COM Pins Hardware Configuration
   writeSPIcommand(0x12);
   writeSPIcommand(0x81);     //0x81   Set Contrast Control
   writeSPIcommand(0xAF);
   writeSPIcommand(0xd9);     //0xD9   Set Pre-Charge Period
   writeSPIcommand(0x25);
   writeSPIcommand(0xdb);     //0xDB   Set VCOMH Deselect Level
   writeSPIcommand(0x20);
   writeSPIcommand(0xa4);     //0xA4   Set Entire Display On/Off
   writeSPIcommand(0xa6);     //0xA6   Set Normal/0xA7 Inverse Display
   
   writeSPIcommand(0xA1);     // mirror image of normal display selected
   //write_command(SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION);
   writeSPIcommand(0xaf);              //0xAF   Set OLED Display On  
}
