#include "led.h"


volatile Uint32 ButtonPressCount = 0; // ����������0-7��



// ��ʼ��LED����GPIO
void InitLEDGPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0; // GPIO13��Ϊ��ͨIO
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;  // ���ģʽ
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0; // GPIO14��Ϊ��ͨIO
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;  // ���ģʽ
    writeLEDData(0x00);//��ʼ���� ȫ��
    EDIS;
}
// ����LED״̬
void UpdateLEDs(void)
{
    unsigned char ledPattern = 0;

    if(ButtonPressCount < 4) {
        // ǰ4�ΰ������������LED
        ledPattern = 0x0F & ((1 << (ButtonPressCount + 1)) - 1);
    } else {
        // ��4�ΰ��������Ϩ��LED
        ledPattern = 0x0F & (0x0F << (8 - ButtonPressCount));
    }

    writeLEDData(ledPattern);
}

// д��LED����
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
