#include "step_motor.h"

// 步进电机控制引脚（GPIO7-10）
#define MOTOR_PIN_START 7
//const Uint16 Forward[] = {0x03, 0x05, 0x0C, 0x0A}; // 正转序列
//const Uint16 Backward[] = {0x0A, 0x0C, 0x05, 0x03}; // 反转序列
//const Uint16 ward[] = {0x0A, 0x03, 0x05, 0x0C, 0x05,0x03,0x0A,0x0C}; // 反转序列


const Uint16 Forward[] = {0x0A, 0x03, 0x05, 0x0C}; // 正转序列
const Uint16 Backward[] = {0x05,0x03,0x0A,0x0C}; // 反转序列


// 全局变量

//Uint32 CurrentPhase =1;             // 电机当前相位（0-3）

void InitMotorGPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;
    EDIS;
}


// 初始化XINT1按键中断（GPIO29）
void InitXINT1(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;   // 普通GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;    // 输入模式
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;  // 同步采样
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 29; // GPIO29映射到XINT1
    XIntruptRegs.XINT1CR.bit.POLARITY = 0;  // 下降沿触发
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;    // 启用中断
    EDIS;
}

static Uint32 CurrentPhase =0;



// 正转一步
void StepMotorForward(void)
{

    GpioDataRegs.GPADAT.all = (Forward[CurrentPhase] << MOTOR_PIN_START);
    CurrentPhase = (CurrentPhase + 1) % 4;
    if(CurrentPhase==3) CurrentPhase=4;
  //  DELAY_US(40000);  // 步间延时20ms
}


// 反转一步
void StepMotorBackward(void)
{
//    CurrentPhase = CurrentPhase - 1;
    CurrentPhase = (CurrentPhase + 1) % 4;
    GpioDataRegs.GPADAT.all = (Backward[CurrentPhase] << MOTOR_PIN_START);

 //   DELAY_US(40000);  // 步间延时20ms
}

void InitMotor(void){
       InitMotorGPIO();
       //InitXINT1();

}

void StepMotor(void){
    int isturn=0;
    keynum=key_GetNum();

    //反转的话 用键盘矩阵？
      if(keynum==1){//短按

      }
      if(flag_key){//长按持续旋转

      }

}
