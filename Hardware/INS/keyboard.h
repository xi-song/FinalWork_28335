#ifndef __KEYBOARD_H
#define __KEYBOARD_H
#include "DSP2833x_Device.h"
#include "DSP2833x_Xintf.h"
#include "DSP2833x_Examples.h"
#include <stdio.h>
extern unsigned int led_choose[8];
extern int keyboard_num;
#define KEY0 GpioDataRegs.GPADAT.bit.GPIO3
#define KEY4 GpioDataRegs.GPADAT.bit.GPIO2
#define KEY8 GpioDataRegs.GPADAT.bit.GPIO1
#define KEY12 GpioDataRegs.GPADAT.bit.GPIO0



#define KEY52 GpioDataRegs.GPBDAT.bit.GPIO52
#define KEY51 GpioDataRegs.GPBDAT.bit.GPIO51
#define KEY50 GpioDataRegs.GPBDAT.bit.GPIO50
#define KEY49 GpioDataRegs.GPBDAT.bit.GPIO49
#define KEY53 GpioDataRegs.GPBDAT.bit.GPIO53

#define LEDSAB    GpioDataRegs.GPADAT.bit.GPIO24
#define LEDSCLK   GpioDataRegs.GPADAT.bit.GPIO12


void Initled_choose(unsigned int * index,int choice);
void Init_Digital(unsigned int * index,int choice);
void keyboard_scan_lie(int i);
int key_GetKeyBoardNum(void);
void KeyBoard_Tick(void);
int Board_GetState(void);
void keyboard_scan(int i);
void Setkeybord(void);
void InitXintf16Gpio(void);
void keyboard_init(void);
void WriteLED(unsigned int index);
void WriteLEDs(unsigned int * index);
void control_motor(unsigned int state);
void configtestled(void);
void InsertArray1(unsigned int * index,unsigned int num);
void InsertArray(unsigned int * index,unsigned int num);
void SelectDigitalLed(unsigned int * index,unsigned int pos,unsigned int num);
#endif
