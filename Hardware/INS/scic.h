#ifndef __SCIC_H
#define __SCIC_H
#include "DSP2833x_Device.h"

void scib_loopback_init(void);
void scib_fifo_init(void);
void scib_xmit(int a);
void scic_loopback_init(void);
void scic_fifo_init(void);
void scic_xmit(int a);
void error(int);

#endif
