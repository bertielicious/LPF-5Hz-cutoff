/* 
 * File:   IFX_EMA.h
 * Author: User
 *
 * Created on 05 April 2024, 18:27
 */

#ifndef IFX_EMA_H
#define	IFX_EMA_H

typedef struct{
    /*filter coefficient 0 to 1*/
    float alpha;
    
    /*filter output*/
    float out;
    
}IFX_EMA;

void IFX_EMA_Init(IFX_EMA *filt, float alpha);   /*function definition of IFX_EMA Init*/
void IFX_EMA_SetAlpha(IFX_EMA *filt, float alpha);
float IFX_EMA_Update(IFX_EMA *filt, float inp);
#endif	/* IFX_EMA_H */

