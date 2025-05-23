// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:35 $
//###########################################################################
//
// FILE:	DSP2833x_PieCtrl.c
//
// TITLE:	DSP2833x Device PIE Control Register Initialization Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "DSP2833x_CpuTimers.h"
//---------------------------------------------------------------------------
// InitPieCtrl: 
//---------------------------------------------------------------------------
// This function initializes the PIE control registers to a known state.
//
void InitPieCtrl(void)
{
    // Disable Interrupts at the CPU level:
    DINT;

    // Disable the PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

	// Clear all PIEIER registers:
	PieCtrlRegs.PIEIER1.all = 0;
	PieCtrlRegs.PIEIER2.all = 0;
	PieCtrlRegs.PIEIER3.all = 0;	
	PieCtrlRegs.PIEIER4.all = 0;
	PieCtrlRegs.PIEIER5.all = 0;
	PieCtrlRegs.PIEIER6.all = 0;
	PieCtrlRegs.PIEIER7.all = 0;
	PieCtrlRegs.PIEIER8.all = 0;
	PieCtrlRegs.PIEIER9.all = 0;
	PieCtrlRegs.PIEIER10.all = 0;
	PieCtrlRegs.PIEIER11.all = 0;
	PieCtrlRegs.PIEIER12.all = 0;

	// Clear all PIEIFR registers:
	PieCtrlRegs.PIEIFR1.all = 0;
	PieCtrlRegs.PIEIFR2.all = 0;
	PieCtrlRegs.PIEIFR3.all = 0;	
	PieCtrlRegs.PIEIFR4.all = 0;
	PieCtrlRegs.PIEIFR5.all = 0;
	PieCtrlRegs.PIEIFR6.all = 0;
	PieCtrlRegs.PIEIFR7.all = 0;
	PieCtrlRegs.PIEIFR8.all = 0;
	PieCtrlRegs.PIEIFR9.all = 0;
	PieCtrlRegs.PIEIFR10.all = 0;
	PieCtrlRegs.PIEIFR11.all = 0;
	PieCtrlRegs.PIEIFR12.all = 0;


}	

//---------------------------------------------------------------------------
// EnableInterrupts: 
//---------------------------------------------------------------------------
// This function enables the PIE module and CPU interrupts
//
void EnableInterrupts()
{

//1.启动串口中断配置

    // Enable the PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;

    PieCtrlRegs.PIEIER8.bit.INTx5 = 1; // 假设 SCI-C 接收中断属于 Group 8，对应的中断号是 INTx5
    PieCtrlRegs.PIEIER8.bit.INTx6 = 1; // 假设 SCI-C 发送中断属于 Group 8，对应的中断号是 INTx6

	// Enables PIE to drive a pulse into the CPU 
	PieCtrlRegs.PIEACK.all = 0xFFFF;  
	IER=0X100 |M_INT8;



//2. 启动外部按键中断
//
//	 PieCtrlRegs.PIEIER1.bit.INTx4 = 1;  // XINT1
//	 IER |= M_INT1;

//3.定时器中断配置
	 // Configure CPU-Timer 0 to interrupt every 200 milliseconds:
	 // 100MHz CPU Freq, 20 millisecond Period (in uSeconds)
	//定时器0
	 ConfigCpuTimer(&CpuTimer0, 100, 1000);//1ms一次中断
	 CpuTimer0Regs.TCR.all = 0x4001;
	 PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
	 IER |= M_INT1;

	 //定时器1
	 ConfigCpuTimer(&CpuTimer1, 100, 1000);//1ms一次中断
	 IER |= M_INT13;

	 CpuTimer1Regs.TCR.bit.TSS=0;

    EINT;
    ERTM;

}


//===========================================================================
// End of file.
//===========================================================================
