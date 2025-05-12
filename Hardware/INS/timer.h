#ifndef __TIMER_H
#define __TIMER_H
#include "DSP2833x_Device.h"
#include <stdio.h>
#include "key.h"
#include "keyboard.h"
extern Uint16 mytime[];

#define LED *((Uint16 *)0x4400)
// Prototype statements for functions found within this file.


/////////////////对应位低电平点亮该位发光二极管
void Time1Tick(Uint16 mytime[]);
void TimeSelect(Uint16 mytime[],int a);
void ShowDigitalNum(Uint16 a[]);
interrupt void cpu_timer0_isr(void);
interrupt void cpu_timer1_isr(void);
void UpdateTime(Uint16 time[]);
void GetTime(Uint16 a[]);

#endif
