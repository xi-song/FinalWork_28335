#include "timer.h"
const   Uint16  LedCode1[9]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE,0xFF};
Uint16 mytime[3]={0,0,0};
Uint16 datetime[3]={0,0,0};

//��ʱ��1�ж�  ��������ʱ��
interrupt void cpu_timer1_isr(void)
{
   EALLOW;
   if(CpuTimer1Regs.TCR.bit.TIF==1){
        UpdateTime(mytime);
       CpuTimer1Regs.TCR.bit.TIF==1;
   }
   EDIS;

}


interrupt void cpu_timer0_isr(void)
{
   CpuTimer0.InterruptCount++;
   Key_Tick();
   KeyBoard_Tick();
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



void UpdateTime(Uint16 time[]){
    static Uint16 cnt;
    static Uint16 hour,min,sec;
    hour=time[0],min=time[1],sec=time[2];
    cnt++;

    if(cnt==999){
        cnt=0;
        if(sec==0){
            sec=59;
            if(min==0){
                min=59;
                if(hour==0){
                    CpuTimer1Regs.TCR.bit.TSS=1;//��ͣ��ʱ��1
                }else hour--;
            }else{
                min--;
            }
        }else sec--;
        time[0]=hour,time[1]=min,time[2]=sec;
        ShowDigitalNum(time);
    }

}
void ShowDigitalNum(Uint16 a[]){
    //��ʾʱ �� ��
    Uint16 hour,min,sec;
    Uint16 sw,gw=0;
    hour=a[0],min=a[1],sec=a[2];
    SelectDigitalLed(led_choose,2,hour);

    gw=min%10;
    sw=min/10;
    SelectDigitalLed(led_choose,4,sw);
    SelectDigitalLed(led_choose,5,gw);


    gw=sec%10;
    sw=sec/10;
    SelectDigitalLed(led_choose,7,sw);
    SelectDigitalLed(led_choose,8,gw);

    WriteLEDs(led_choose);
}



void TimeSelect(Uint16 mytime[],int a){
    //˫��-ȷ�� ����-ѡ��
//    int a=key_GetNum();

    static Uint16 cnt=0;
    Init_Digital(led_choose,1);
    if(a)  cnt++;
    switch(cnt%5){
        case 1:{
            //30min
            mytime[0]=0;
            mytime[1]=30;
            mytime[2]=0;
            break;
        }
        case 2:{
            //1h
            mytime[0]=1;
            mytime[1]=0;
            mytime[2]=0;
            break;
        }
        case 3:{
            mytime[0]=1;
            mytime[1]=30;
            mytime[2]=0;
            break;
        }
        case 4 :{
            mytime[0]=2;
            mytime[1]=0;
            mytime[2]=0;
            break;
        }
        case 0:{
           mytime[0]=2;
           mytime[1]=30;
           mytime[2]=0;
           break;
        }
    }
    ShowDigitalNum(mytime);


}


void Time1Tick(Uint16 mytime[]){

    //time һ����30 1 1.5 2 2.5
    static int count;
    count++;
    if(count==1000){
        mytime[2]--;
        count=0;
    }
    if(mytime[2]==0){
        mytime[2]=59;
        mytime[1]--;
    }
    if(mytime[1]==0){
        mytime[1]--;
        mytime[1]=59;
    }

    if(mytime[1]==0 && mytime[2]==0 && mytime[1]==0){

    }
}
