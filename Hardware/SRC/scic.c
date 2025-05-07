#include "scic.h"

Uint16 ErrorCount;
void error(int ErrorFlag)
{
      Uint16 Error;
      Error = ErrorFlag;
      ErrorCount++;
      Error++;
      asm("     ESTOP0");  // Uncomment to stop the test here
      for (;;);

}


// Test 1,SCIB  DLB, 8-bit word, baud rate 9.6K, default, 1 STOP bit, no parity
void scib_loopback_init()
{
    // Note: Clocks were turned on to the SCIB peripheral
    // in the InitSysCtrl() function

    ScibRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    ScibRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
    ScibRegs.SCICTL2.all =0x0003;
    ScibRegs.SCICTL2.bit.TXINTENA =1;
    ScibRegs.SCICTL2.bit.RXBKINTENA =1;
    ScibRegs.SCIHBAUD    =0x0001;//0x0001;
    ScibRegs.SCILBAUD    =0x00e7;//0x00e7;44
    ScibRegs.SCICCR.bit.LOOPBKENA =0; // enable loop back
    ScibRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset
}


// Transmit a character from the SCI'
void scib_xmit(int a)
{
    ScibRegs.SCITXBUF=a;
}

// Initalize the SCI FIFO
void scib_fifo_init()
{
    ScibRegs.SCIFFTX.bit.TXFIFOXRESET=0;
    ScibRegs.SCIFFRX.bit.RXFIFORESET=0;

    ScibRegs.SCIFFTX.all=0xE040;
    ScibRegs.SCIFFRX.all=0x204f;
    ScibRegs.SCIFFCT.all=0x0;

}

// Test 1,SCIC  DLB, 8-bit word, baud rate 9.6k, default, 1 STOP bit, no parity
void scic_loopback_init()
{
    // Note: Clocks were turned on to the SCIC peripheral
    // in the InitSysCtrl() function

    ScicRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    ScicRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
    ScicRegs.SCICTL2.all =0x0003;
    ScicRegs.SCICTL2.bit.TXINTENA =1;
    ScicRegs.SCICTL2.bit.RXBKINTENA =1;
    ScicRegs.SCIHBAUD    =0x0001;
    ScicRegs.SCILBAUD    =0x00E7;
    ScicRegs.SCICCR.bit.LOOPBKENA =0;// enable loop back
    ScicRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset
}



// Transmit a character from the SCI'
void scic_xmit(int a)
{
    ScicRegs.SCITXBUF=a;
}

// Initalize the SCI FIFO
void scic_fifo_init()
{

        ScicRegs.SCIFFTX.bit.TXFIFOXRESET=0;
        ScicRegs.SCIFFRX.bit.RXFIFORESET=0;

//        ScicRegs.SCIFFTX.all=0xE040;
//    //    ScicRegs.SCIFFRX.all=0x204f;
//        ScicRegs.SCIFFRX.all=0x2021;
//        ScicRegs.SCIFFCT.all=0x0;


        ScicRegs.SCIFFTX.all = 0xC028;
           ScicRegs.SCIFFRX.all = 0x0028;
           ScicRegs.SCIFFCT.all=0x0;
}



//===========================================================================
// No more.
//===========================================================================

