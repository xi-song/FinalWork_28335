#ifndef __DCMOTOR_H
#define __DCMOTOR_H
#include "DSP2833x_Device.h"
#define DAC_CSn GpioDataRegs.GPADAT.bit.GPIO26
#define DAC_WRn GpioDataRegs.GPADAT.bit.GPIO25


void DC_Moter(void);
void control_motor(unsigned int state);
/////////////////对应位低电平点亮该位发光二极管





#endif
