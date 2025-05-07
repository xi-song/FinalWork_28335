#ifndef __LED_H
#define __LED_H
#include "DSP2833x_Device.h"


// LED¿ØÖÆÒý½Å
#define LEDSAB1 GpioDataRegs.GPADAT.bit.GPIO13
#define LEDSCLK1 GpioDataRegs.GPADAT.bit.GPIO14

void InitLEDGPIO(void);
void UpdateLEDs(void);
void writeLEDData(unsigned char val);


#endif
