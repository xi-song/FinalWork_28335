#include "led.h"


volatile Uint32 ButtonPressCount = 0; // 按键计数（0-7）



// 初始化LED控制GPIO
void InitLEDGPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0; // GPIO13作为普通IO
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;  // 输出模式
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0; // GPIO14作为普通IO
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;  // 输出模式
    writeLEDData(0x00);//初始化灯 全灭
    EDIS;
}
// 更新LED状态
void UpdateLEDs(void)
{
    unsigned char ledPattern = 0;

    if(ButtonPressCount < 4) {
        // 前4次按键：逐个点亮LED
        ledPattern = 0x0F & ((1 << (ButtonPressCount + 1)) - 1);
    } else {
        // 后4次按键：逐个熄灭LED
        ledPattern = 0x0F & (0x0F << (8 - ButtonPressCount));
    }

    writeLEDData(ledPattern);
}

// 写入LED数据
void writeLEDData(unsigned char val)
{
    int i;
    for(i=0; i<8; i++)
    {
        if(val & 0x80)
        {
            LEDSCLK1 = 0;
            LEDSAB1 = 1;
            LEDSCLK1 = 1;
        }
        else
        {
            LEDSCLK1 = 0;
            LEDSAB1 = 0;
            LEDSCLK1 = 1;
        }
        val = val << 1;
    }
}
