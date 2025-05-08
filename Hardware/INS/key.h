#ifndef __KEY_H
#define __KEY_H
#include "DSP2833x_Device.h"


extern int long_press;
extern int double_press;


void key_init(void);
int Key_GetState(void);
void Key_Tick(void);
int key_GetNum(void);
int key_GetLongNum(void);


#endif
