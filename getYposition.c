/* This function accepts a pointer to a struct containing the pixel y position (vertical from 1 to 63
 and returns an 8 bit yByte and page from 0 - 7*/

#include "constVar.h"
void getYposition( pix *p)
{
    
    switch(p->yVal)
    {
        case 63:
            p->yByte = 0x00;
            p->page = 0;
            break;
            
        case 62:
            p->yByte = 0x02;
            p->page = 0;
            break;
            
        case 61:
            p->yByte = 0x04;
            p->page = 0;
            break;
            
        case 60:
            p->yByte = 0x08;
            p->page = 0;
            break;
            
        case 59:
            p->yByte = 0x10;
            p->page = 0;
            break;
            
        case 58:
            p->yByte = 0x20;
            p->page = 0;
            break;
            
        case 57:
            p->yByte = 0x40;
            p->page = 0;
            break;
            
        case 56:
            p->yByte = 0x80;
            p->page = 0;
            break;
            
        case 55:
            p->yByte = 0x01;
            p->page = 1;
            break;
            
        case 54:
            p->yByte = 0x02;
            p->page = 1;
            break;
            
        case 53:
            p->yByte = 0x04;
            p->page = 1;
            break;
            
        case 52:
            p->yByte = 0x08;
            p->page = 1;
            break;
            
        case 51:
            p->yByte = 0x10;
            p->page = 1;
            break;
            
        case 50:
            p->yByte = 0x20;
            p->page = 1;
            break;
            
        case 49:
            p->yByte = 0x40;
            p->page = 1;
            break;
            
        case 48:
            p->yByte = 0x80;
            p->page = 1;
            break;       
            
        case 47:
            p->yByte = 0x01;
            p->page = 2;
            break;
            
        case 46:
            p->yByte = 0x02;
            p->page = 2;
            break;
            
        case 45:
            p->yByte = 0x04;
            p->page = 2;
            break;
            
        case 44:
            p->yByte = 0x08;
            p->page = 2;
            break;
            
        case 43:
            p->yByte = 0x10;
            p->page = 2;
            break;
            
        case 42:
            p->yByte = 0x20;
            p->page = 2;
            break;
            
        case 41:
            p->yByte = 0x40;
            p->page = 2;
            break;
            
        case 40:
            p->yByte = 0x80;
            p->page = 2;
            break;
            
        case 39:
            p->yByte = 0x01;
            p->page = 3;
            break;
            
        case 38:
            p->yByte = 0x02;
            p->page = 3;
            break;
            
        case 37:
            p->yByte = 0x04;
            p->page = 3;
            break;
            
        case 36:
            p->yByte = 0x08;
            p->page = 3;
            break;
            
        case 35:
            p->yByte = 0x10;
            p->page = 3;
            break;
            
        case 34:
            p->yByte = 0x20;
            p->page = 3;
            break;
            
        case 33:
            p->yByte = 0x40;
            p->page = 3;
            break;
            
        case 32:
            p->yByte = 0x80;
            p->page = 3;
            break;
       
        case 31:
            p->yByte = 0x01;
            p->page = 4;
            break;
            
        case 30:
            p->yByte = 0x02;
            p->page = 4;
            break;
            
        case 29:
            p->yByte = 0x04;
            p->page = 4;
            break;
            
        case 28:
            p->yByte = 0x08;
            p->page = 4;
            break;
            
        case 27:
            p->yByte = 0x10;
            p->page = 4;
            break;
            
        case 26:
            p->yByte = 0x20;
            p->page = 4;
            break;
            
        case 25:
            p->yByte = 0x40;
            p->page = 4;
            break;
            
        case 24:
            p->yByte = 0x80;
            p->page = 4;
            break;
            
        case 23:
            p->yByte = 0x01;
            p->page = 5;
            break;
            
        case 22:
            p->yByte = 0x02;
            p->page = 5;
            break;
            
        case 21:
            p->yByte = 0x04;
            p->page = 5;
            break;
            
        case 20:
            p->yByte = 0x08;
            p->page = 5;
            break;
            
        case 19:
            p->yByte = 0x10;
            p->page = 5;
            break;
            
        case 18:
            p->yByte = 0x20;
            p->page = 5;
            break;
            
        case 17:
            p->yByte = 0x40;
            p->page = 5;
            break;
            
        case 16:
            p->yByte = 0x80;
            p->page = 5;
            break;   
            
        case 15:
            p->yByte = 0x01;
            p->page = 6;
            break;
            
        case 14:
            p->yByte = 0x02;
            p->page = 6;
            break;
            
        case 13:
            p->yByte = 0x04;
            p->page = 6;
            break;
            
        case 12:
            p->yByte = 0x08;
            p->page = 6;
            break;
            
        case 11:
            p->yByte = 0x10;
            p->page = 6;
            break;
            
        case 10:
            p->yByte = 0x20;
            p->page = 6;
            break;
            
        case 9:
            p->yByte = 0x40;
            p->page = 6;
            break;
            
        case 8:
            p->yByte = 0x80;
            p->page = 6;
            break;         
            
         case 7:
            p->yByte = 0x01;
            p->page = 7;
            break;
            
        case 6:
            p->yByte = 0x02;
            p->page = 7;
            break;
            
        case 5:
            p->yByte = 0x04;
            p->page = 7;
            break;
            
        case 4:
            p->yByte = 0x08;
            p->page = 7;
            break;
            
        case 3:
            p->yByte = 0x10;
            p->page = 7;
            break;
            
        case 2:
            p->yByte = 0x20;
            p->page = 7;
            break;
            
        case 1:
            p->yByte = 0x40;
            p->page = 7;
            break;
            
        case 0:
            p->yByte = 0x80;
            p->page = 7;
            break;
            
        default:
            p->yByte = 0x00;
            p->page = 8;
    }
   // printf("getPixelPosition %d     %d\n", p->yByte, p->page);
}
