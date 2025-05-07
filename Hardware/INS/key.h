#ifndef __KEY_H
#define __KEY_H
#include "DSP2833x_Device.h"
int flag_key=0;
void key_init(void);
int Key_GetState(void);
void Key_Tick(void);
int key_GetNum(void);
#endif
