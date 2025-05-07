#include "keyboard.h"
unsigned char LedCode[] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0xEE,0x3E,0x9C,0x7A,0x9E,0x8E, 0x01, 0x02, 0x04, 0x08 };
unsigned int LedResult[8];
unsigned int count;
unsigned int keypress = 0;
unsigned int keyx, keyy;
unsigned int key_value;
unsigned int motor_state = 0; // 0:停止, 1:转动

// 键盘映射
//0x000 c; 0x100 D;  0x200 E;  0x300 F;  0x400  NXET;
//0x001 8; 0x101 9;  0x201 A;  0x301 B;  0x401  LAST
//0x002 4; 0x102 5;  0x202 6;  0x302 7;  0x402  MON
//0x003 0; 0x103 1;  0x203 2;  0x303 3;  0x403 RST


void configtestled(void)
{
    EALLOW;

    // 键盘输出
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO53 = 1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO51 = 1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO50 = 1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;

    // 键盘输入
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 0;

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;

    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 0;

    // 数码管
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO24 = 1;

    // DAC控制 (电机控制)
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO25 = 1;

    // D0-D7
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO79 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO78 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO77 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO76 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO75 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO74 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO73 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO72 = 1;

    EDIS;
}

void WriteLED(unsigned int index)
{
    unsigned int i, j;

    for(j = 0; j < 8; j++)
    {
        for(i = 0; i < 8; i++)
        {
            if(LedCode[index] & (0x01 << i))
                LEDSAB = 1;
            else
                LEDSAB = 0;

            LEDSCLK = 0;
            LEDSCLK = 1;
        }
    }
}

void control_motor(unsigned int state)
{
    unsigned long long int  m=0;

    if(state == 1) // 启动电机
    {
        for(m = 0; m < 4; m++)
        {
            DAC_CSn = 0;
            DAC_WRn = 0;
            GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff << 8))) | (0x1 << (m + 8));

        }
    }
    else // 停止电机
    {
        DAC_CSn = 1;
        DAC_WRn = 1;
        GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff << 8)));
    }
}
