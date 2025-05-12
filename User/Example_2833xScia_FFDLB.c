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


// Global
extern volatile Uint32 ButtonPressCount; // ����������0-7��
extern Uint16 ErrorCount;
unsigned int Count,Flag;




interrupt void XINT1_ISR(void);


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
    CpuTimer1Regs.TCR.bit.TSS=1;//�رն�ʱ��1
    /*���ԡ��������ж� ֮ǰ�Ƿ�while��1������*/
//       if(flag){
//           scic_xmit('A');
//           flag=0;
//       }


    int keyboard_num=0;
    int keynum=0;
    Init_Digital(led_choose,0);

	for(;;){
	        keyboard_num=key_GetKeyBoardNum();
	        CpuTimer1Regs.TCR.bit.TSS=1;//�رն�ʱ��1
	        switch(keyboard_num){
	        case 3:
	            //�������
	            while(1){
	                keynum=key_GetNum();
	                StepMotor(keynum);
	                if(key_GetKeyBoardNum()==3) break;
	            }
	            break;
	        case 4:
	            //ֱ�����
	            while(1){
	                control_motor(keyboard_num);
	                if(key_GetKeyBoardNum()==4) break;
	            }
	            break;
	        case 8:
	            //�յ�
	            mytime[0]=0;
	            mytime[1]=0;
	            mytime[2]=0;
	            Init_Digital(led_choose,1);
	            while(1){
	                if(key_GetKeyBoardNum()==4){
                       CpuTimer1Regs.TCR.bit.TSS=0;//������ʱ��1
                   }
	                keynum=key_GetNum();
                    if(keynum){
                       TimeSelect(mytime,keynum);
                       CpuTimer1Regs.TCR.bit.TSS=1;
                   }
	                if(key_GetKeyBoardNum()==8) break;
	            }
	            CpuTimer1Regs.TCR.bit.TSS=1;//�رն�ʱ��1
	            Init_Digital(led_choose,0);
	            break;
	        case 12:

	            break;
	        default:
	            break;
	        }

	}

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
