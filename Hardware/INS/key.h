#ifndef __KEY_H
#define __KEY_H
#include "DSP2833x_Device.h"
#include <stdio.h>

extern int long_press;
extern int double_press;
int key_GetTimeDoubleNum(void);
void key_init(void);
int Key_GetState(void);
void Key_Tick(void);
int key_GetNum(void);
int key_GetLongNum(void);
Uint16* key_GetDoubleNum(Uint16 dir1[],Uint16 dir2[]);

#endif
