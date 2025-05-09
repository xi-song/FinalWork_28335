#ifndef __KEYBOARD_H
#define __KEYBOARD_H
#include "DSP2833x_Device.h"
#include "DSP2833x_Xintf.h"
#include "DSP2833x_Examples.h"
#include <stdio.h>
#define KEY1 GpioDataRegs.GPADAT.bit.GPIO3
#define KEY2 GpioDataRegs.GPADAT.bit.GPIO2
#define KEY3 GpioDataRegs.GPADAT.bit.GPIO1
#define KEY4 GpioDataRegs.GPADAT.bit.GPIO0



#define KEY52 GpioDataRegs.GPBDAT.bit.GPIO52
#define KEY51 GpioDataRegs.GPBDAT.bit.GPIO51
#define KEY50 GpioDataRegs.GPBDAT.bit.GPIO50
#define KEY49 GpioDataRegs.GPBDAT.bit.GPIO49
#define KEY53 GpioDataRegs.GPBDAT.bit.GPIO53

#define LEDSAB    GpioDataRegs.GPADAT.bit.GPIO24
#define LEDSCLK   GpioDataRegs.GPADAT.bit.GPIO12


extern int keyboard_num;
void KeyBoard_Tick1(void);
void keyboard_scan_lie(int i);
int key_GetKeyBoardNum(void);
void KeyBoard_Tick(void);
int Board_GetState(void);
void keyboard_scan(int i);
void Setkeybord(void);
void InitXintf16Gpio(void);
void keyboard_init(void);
void WriteLED(unsigned int index);
void control_motor(unsigned int state);
void configtestled(void);


#endif
