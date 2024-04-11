/*
 * File:   main.c
 * Author: User
 *
 * Created on 31 January 2024, 14:59
 */


#include <xc.h>
#include <stdio.h>
#include "constVar.h"
#include "configOsc.h"
#include "configEUSART.h"
#include "putch.h"
#include "configPORTS.h"
#include "configSPI.h"
#include "configADC.h"
#include "writeSPIcommand.h"
#include "writeSPIdata.h"
#include "configSSD1309.h"
#include "clearSSD1309.h"
#include "getYposition.h"
#include "setColAddr.h"
#include "drawPixel.h"
#include "drawArray.h"
#include "rightScroll.h"
#include "interrupt.h"
#include "configTMR0interrupt.h"
#include "setMemoryAddressingMode.h"
#include "math.h"
#include <pic.h>
#include <stdlib.h>


void main(void) 
{
    
    configOsc();
    configPORTS();
    configEUSART();
    configSPI();
    configADC();
    
    
    configSSD1309();
    __delay_ms(1000);
    clearSSD1309();
    
  
  
    
    pix *ptr;
    pix var;
    ptr = &var;
    
    IIRfilter *fptr;
    IIRfilter fvar;
    fptr = &fvar;
    fptr->a = 194;
    fptr->b = 62;
  //  fptr->a = 220;
  //  fptr->b = 35;
    
    fptr->currOut = 0;
    fptr->prevOut = 0;
    
    //ptr->yVal = 45;
    //var.yVal = 1;
    //var.yVal = 37;
    //or
   // ptr->yVal = 8;
    //ptr->yByte = 0xfa;
    //ptr->page = 7;
    //printf("main getPixelPosition %d     %d\n", ptr->yByte, ptr->page);
    //getYposition(&var);
    //printf("second main getPixelPosition %d     %d\n", ptr->yByte, ptr->page); 
   // printf("sizeof %d\n", sizeof(newQuad));//768
   
    /*drawPixel(64,32);
    drawPixel(10,7);
    drawPixel(117,7);
    drawPixel(117,53);
    drawPixel(10,53);*/
    
    drawArray();
   // rightScroll();
    __delay_ms(1500);
    clearSSD1309();
    configTMR0interrupt();
    drawPixel(0,0);
    drawPixel(127,0);
    drawPixel(0,63);
    drawPixel(127,63);
     __delay_ms(500);
    //uint8_t angle = 45;
    uint16_t opposite = 0;
    uint16_t adjacent = 0;
    uint8_t ycoord = 0;
    uint8_t xcoord = 0;
   // bool flag1;
    uint8_t rad = 63;
    clearSSD1309();
    
    
    while(1)
    {
        ADCON0bits.GO_nDONE = HI;
        while(ADCON0bits.GO_nDONE == HI)
        {
          ;  // wait for adc conversion to complete
        }
        adcVal =  ADRESH<<8|ADRESL;
         /*low pass digital filter for adcVal*/
       
        
        PIR1bits.ADIF = LO;
        
       
        
        
           /******needle clamping at lower and upper ranges*/
  /*      if(adcVal <=30)
        {
            adcVal = 30;
        }
        
         if(adcVal >=150)
        {
            adcVal = 150;
        }*/
       /**************LP filter adcVal********/
        fptr->prevOut = fptr->currOut;// shift current output sample into previous output sample
        fptr->currOut = (fptr->a*adcVal>>8) + (fptr->b*fptr->prevOut>>8);  // compute new current output value
        
        /***draw the needle*/
        for(rad = 0; rad < 64; rad++)
        {
            opposite = sineLookUp[fptr->currOut] * rad;
            adjacent = cosineLookUp[fptr->currOut] * rad;
        
        
        ycoord = (opposite>>8)+ 61;
        xcoord = (adjacent>>8) - 4;
      
        drawPixel(ycoord, xcoord);
        }     
        
      __delay_ms(10);
      //printf("%d %d \n", fptr->currOut, fptr->prevOut);
    }
}
           
       
    
   

  

