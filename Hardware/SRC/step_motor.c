#include "step_motor.h"

// ��������������ţ�GPIO7-10��
#define MOTOR_PIN_START 7
//const Uint16 Forward[] = {0x03, 0x05, 0x0C, 0x0A}; // ��ת����
//const Uint16 Backward[] = {0x0A, 0x0C, 0x05, 0x03}; // ��ת����
//const Uint16 ward[] = {0x0A, 0x03, 0x05, 0x0C, 0x05,0x03,0x0A,0x0C}; // ��ת����
static int CurrentPhase =-1;
Uint16* p = NULL;
Uint16 Forward[] = {0x0A, 0x03, 0x05, 0x0C}; // ��ת����
Uint16 Backward[] = {0x05,0x03,0x0A,0x0C}; // ��ת����


// ȫ�ֱ���


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


// ��ʼ��XINT1�����жϣ�GPIO29��
void InitXINT1(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;   // ��ͨGPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;    // ����ģʽ
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;  // ͬ������
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 29; // GPIO29ӳ�䵽XINT1
    XIntruptRegs.XINT1CR.bit.POLARITY = 0;  // �½��ش���
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;    // �����ж�
    EDIS;
}




void StepForward(Uint16 *dir,int flag){

    CurrentPhase = (CurrentPhase + 1) % 4;
    GpioDataRegs.GPADAT.all = (dir[CurrentPhase] << MOTOR_PIN_START);

    if(flag) DELAY_US(2000);  // ������ʱ20ms
}


// ��תһ��
void StepMotorForward(int flag)
{

    GpioDataRegs.GPADAT.all = (Forward[CurrentPhase] << MOTOR_PIN_START);
    CurrentPhase = (CurrentPhase + 1) % 4;
   // if(CurrentPhase==3) CurrentPhase=4;

    if(flag)DELAY_US(2000);  // ������ʱ20ms
}


// ��תһ��
void StepMotorBackward(void)
{
//    CurrentPhase = CurrentPhase - 1;
    CurrentPhase = (CurrentPhase + 1) % 4;
    GpioDataRegs.GPADAT.all = (Backward[CurrentPhase] << MOTOR_PIN_START);

    DELAY_US(20000);  // ������ʱ20ms
}

void InitMotor(void){
       InitMotorGPIO();
       //InitXINT1();

}

void MotorTest(void){
        //��ʱ������ɨ��
      int i;
      for( i=0;i<20000;i++){
            GpioDataRegs.GPADAT.all = 0xa<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0x3<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0x5<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0xc<<7;
            DELAY_US(20000);
      }

      for(i=0;i<20000;i++){
            GpioDataRegs.GPADAT.all = 0x5<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0x3<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0xa<<7;
            DELAY_US(20000);
            GpioDataRegs.GPADAT.all = 0xc<<7;
            DELAY_US(20000);
      }
}


void StepMotor(int a){
    //��Ҷ��
    //˫��-��ת ����-����  ����-һֱ
//    int keynum=key_GetNum();

    if(double_press){
        p = key_GetDoubleNum(Forward,Backward);
    }


    if(a)
        StepForward(p,0);

    while(key_GetLongNum()){
        StepForward(p,1);
    }

}


