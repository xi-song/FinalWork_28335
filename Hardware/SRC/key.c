#include "key.h"

int key_num=0;//��������ֵ ȷ������
int long_press=0;
#define LONG_PRESS_TIME  3 //3*20=60ms
#define DOUBLE_PRESS_TIME  35

int double_press=0;
void key_init(void){

    EALLOW;
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;   // ��ͨGPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;    // ����ģʽ
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;  // ͬ������
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0; //��������
    EDIS;
}


int Key_GetState(void){
    if(GpioDataRegs.GPADAT.bit.GPIO29 == 0)
        return 1;
    return 0;
}


int key_GetNum(void){
    int tmp;
    if(key_num){
        tmp=key_num;
        key_num=0;
        return tmp;
    }
    return 0;
}

int key_GetLongNum(void){
    int tmp;
    if(long_press){
        tmp=long_press;
        long_press=0;
        return tmp;
    }
    return 0;
}

void Key_Tick(void){
    //t ���ڼ���˫����ʱ��
    static int count,longpress_time=0,t=0,pre_t;
    static int pre=0,cur=0;
    static int flag=0;
    static int cnt=0,longflag=0;

    count++;
    if(count>=20){
        count=0;
        if(flag){
            pre=0;
            flag=0;
        }
        else pre=cur;
        cur=Key_GetState();
        if(!long_press){
            if(cur==0 && pre!=0){
                key_num=pre;
                t=0;
            }
            else if(cur!=0 && pre!=0){
                t++;
            }else t=0;

        }
        if(t>=50){
            long_press=cur;
            flag=1;

        }

    }



}
