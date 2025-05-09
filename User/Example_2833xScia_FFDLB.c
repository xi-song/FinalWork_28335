// TI File $Revision: /main/8 $
//###########################################################################


#include"scic.h"
#include"led.h"
#include"key.h"
#include"timer.h"
#include"keyboard.h"
#include"step_motor.h"
#include"DCmotor.h"
#include <stdint.h>
#include <stdio.h>

//�����Ļ� �л�  �̰�˳��ִ��

// Global
extern volatile Uint32 ButtonPressCount; // ����������0-7��
extern Uint16 ErrorCount;
unsigned int Count,Flag;
Uint16 ReceivedChar =0;



interrupt void ScicRxFifoIsr(void);
interrupt void ScicTxFifoIsr(void);
interrupt void XINT1_ISR(void);
interrupt void cpu_timer0_isr(void);
interrupt void cpu_timer1_isr(void);


void HardwareInit(void){
   key_init();
   InitSciGpio();
   InitMotor();
   keyboard_init();
   InitLEDGPIO();
   InitCpuTimers();
}
//interrupt void scicTxifoIsr(void);
void main(void)
{

   InitSysCtrl();
   InitPieCtrl();
   HardwareInit();
    DINT;
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    EALLOW;
    PieVectTable.SCIRXINTC =&ScicRxFifoIsr; //�����жϺ���
    PieVectTable.SCITXINTC =&ScicTxFifoIsr;
    //PieVectTable.XINT1 = &XINT1_ISR;
    PieVectTable.TINT0 = &cpu_timer0_isr;//��ʱ��0�ж�
    PieVectTable.XINT13=&cpu_timer1_isr;//
    EDIS;

    EnableInterrupts();

    scic_fifo_init();
    scic_loopback_init();

    /*���ԡ��������ж� ֮ǰ�Ƿ�while��1������*/
//       if(flag){
//           scic_xmit('A');
//           flag=0;
//       }

    //Ҫ��while���������˳���
    int i=0;
    int keyboard_num=0;
	for(;;){
	    for(i=0;i<=4;i++){
	        keyboard_scan_lie(i);
	        DELAY_US(100);
	        keyboard_num=key_GetKeyBoardNum();
	        switch(keyboard_num){
	        case 5:
	            //key1
	            WriteLED(0);
	            break;
	        case 2:
	            //key2
	            WriteLED(1);
	            break;
	        case 3:
	            //key3
	            WriteLED(2);
	            break;
	        case 4:
	            //key4
	            WriteLED(3);
	            break;
	        default:
	            break;
	        }
	        Setkeybord();
	    }

	}

}


//��ʱ��1�ж�  ��������ʱ��
interrupt void cpu_timer1_isr(void)
{
   EALLOW;
   if(CpuTimer1Regs.TCR.bit.TIF==1){
       KeyBoard_Tick();
       CpuTimer1Regs.TCR.bit.TIF==1;
   }
   EDIS;

}


interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;
   Key_Tick();

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
