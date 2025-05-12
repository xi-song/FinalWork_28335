#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "key.h"
#include <stdio.h>
extern int flag_key;
extern Uint16 Forward[];
extern Uint16 Backward[]; // ��ת����
extern Uint16* p ;
// ��������
void InitMotorGPIO(void);
void InitLEDGPIO(void);
void InitXINT1(void);
void StepMotorForward(int flag);
void StepMotorBackward(void);
void InitMotor(void);
void MotorTest(void);
void StepForward(Uint16 *dir,int flag);
//void forward(int flag);
void StepMotor(int a);

#endif
