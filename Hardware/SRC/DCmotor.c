#include "DCmotor.h"


void DC_Moter(void){
    int i=0,m=0;
    for(m=0; m <4; m++){
       DAC_CSn = 0;
       DAC_WRn = 1;
       for(i=0; i<10000;i++); //��ʱ

       GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff<<8))) | (0x1<<(m+8));

       DAC_CSn = 0;
       DAC_WRn = 0;
       for(i=0; i<1000000;i++); //��ʱ
       DAC_CSn = 0;
       DAC_WRn = 1;

       for(i=0; i<100000;i++); //��ʱ
    }
}

void control_motor(unsigned int state)
{
    unsigned long long int  m=0;

    if(state == 1) // �������
    {
        for(m = 0; m < 4; m++)
        {
            DAC_CSn = 0;
            DAC_WRn = 0;
            GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff << 8))) | (0x1 << (m + 8));

        }
    }
    else // ֹͣ���
    {
        DAC_CSn = 1;
        DAC_WRn = 1;
        GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff << 8)));
    }
}
