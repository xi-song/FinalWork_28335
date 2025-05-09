#include "DCmotor.h"


void DC_Moter(void){
    int i=0,m=0;
    for(m=0; m <4; m++){
       DAC_CSn = 0;
       DAC_WRn = 1;
       for(i=0; i<10000;i++); //延时

       GpioDataRegs.GPCDAT.all = (GpioDataRegs.GPCDAT.all & (~(0xff<<8))) | (0x1<<(m+8));

       DAC_CSn = 0;
       DAC_WRn = 0;
       for(i=0; i<1000000;i++); //延时
       DAC_CSn = 0;
       DAC_WRn = 1;

       for(i=0; i<100000;i++); //延时
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
