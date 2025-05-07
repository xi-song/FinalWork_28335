// TI File $Revision: /main/8 $
//###########################################################################


#include"scic.h"
#include"led.h"
#include"key.h"
#include"timer.h"
#include"keyboard.h"
#include"step_motor.h"
#include <stdint.h>
#include <stdio.h>

//�����Ļ� �л�  �̰�˳��ִ��
extern int flag_key;
// Global
extern volatile Uint32 ButtonPressCount; // ����������0-7��
extern Uint16 ErrorCount;
unsigned int Count,Flag;
Uint16 ReceivedChar =0;



interrupt void ScicRxFifoIsr(void);
interrupt void ScicTxFifoIsr(void);
interrupt void XINT1_ISR(void);
interrupt void cpu_timer0_isr(void);

//interrupt void scicTxifoIsr(void);
void main(void)
{

   InitSysCtrl();
   key_init();
   InitSciGpio();
   InitMotor();
   InitLEDGPIO();

    DINT;
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    EALLOW;   // This is needed to write to EALLOW protected registers
    PieVectTable.SCIRXINTC =&ScicRxFifoIsr;         //�����жϺ���
    PieVectTable.SCITXINTC =&ScicTxFifoIsr;
    //PieVectTable.XINT1 = &XINT1_ISR;
    PieVectTable.TINT0 = &cpu_timer0_isr;//��ʱ���ж�
    EDIS;   // This is needed to disable write to EALLOW protected registers

    EnableInterrupts();


    ErrorCount = 0;

    scic_fifo_init();
    scic_loopback_init();

    /*���ԡ��������ж� ֮ǰ�Ƿ�while��1������*/
//       if(flag){
//           scic_xmit('A');
//           flag=0;
//       }

    int keynum=0;
    int presscount=0;
    int i=0;
	for(;;){

    //��ʱ������ɨ��
	    for( i=0;i<20000;i++){
            GpioDataRegs.GPADAT.all = 0xa<<7;
            GpioDataRegs.GPADAT.all = 0x3<<7;
            GpioDataRegs.GPADAT.all = 0x5<<7;
            GpioDataRegs.GPADAT.all = 0xc<<7;
	    }

	    for(i=0;i<20000;i++){
            GpioDataRegs.GPADAT.all = 0x5<<7;
            GpioDataRegs.GPADAT.all = 0x3<<7;
            GpioDataRegs.GPADAT.all = 0xa<<7;
            GpioDataRegs.GPADAT.all = 0xc<<7;
	    }





       keynum=key_GetNum();
       if(keynum==1){//�̰�

       }
       if(flag_key)//����

    }

}

extern const   Uint16  LedCode1[9];
interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;
  // GpioDataRegs.GPBTOGGLE.bit.GPIO55 = 1; // Toggle GPIO55 once per 500 milliseconds
   Key_Tick();


   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



interrupt void ScicRxFifoIsr(void)
{

//      ReceivedChar = ScicRegs.SCIRXBUF.all;
//      scic_xmit(ReceivedChar);
//
//       ScicRegs.SCIFFRX.bit.RXFFINTCLR = 1;
//     //  ScicRegs.SCIFFTX.bit.TXFFINTCLR=1;
//       PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

}


interrupt void ScicTxFifoIsr(void){
    scic_xmit(ReceivedChar);
    ScicRegs.SCIFFTX.bit.TXFFINTCLR=1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;
//    PieCtrlRegs.PIEACK.all|=0x100;      // Issue PIE ACK
    EINT;

}


// XINT1�жϷ�����
interrupt void XINT1_ISR(void)
{
//       DELAY_US(30000);
//        // ԭ�е����LED�����߼�
//        if (ButtonPressCount < 4) {
//            StepMotorForward();
//        } else {
//            StepMotorBackward();
//        }
//        UpdateLEDs();
//        ButtonPressCount = (ButtonPressCount + 1) % 8;
//
//
//    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
