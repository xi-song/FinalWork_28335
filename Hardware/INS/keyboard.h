#ifndef __KEYBOARD_H
#define __KEYBOARD_H
#include "DSP2833x_Device.h"
#include "DSP2833x_Xintf.h"



#define LEDSAB    GpioDataRegs.GPADAT.bit.GPIO24
#define LEDSCLK   GpioDataRegs.GPADAT.bit.GPIO12
#define DAC_CSn   GpioDataRegs.GPADAT.bit.GPIO26
#define DAC_WRn   GpioDataRegs.GPADAT.bit.GPIO25






void WriteLED(unsigned int index);
void control_motor(unsigned int state);
void configtestled(void);


#endif
