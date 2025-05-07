#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "key.h"
extern int flag_key;
// º¯ÊýÉùÃ÷
void InitMotorGPIO(void);
void InitLEDGPIO(void);
void InitXINT1(void);
void StepMotorForward(void);
void StepMotorBackward(void);
void InitMotor(void);
//void forward(int flag);
void StepMotor(void);
#endif
