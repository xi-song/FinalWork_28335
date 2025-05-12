#include "key.h"
int key_num=0;//��������ֵ ȷ������
int long_press=0;
int double_press=0,double_cnt=0;
#define LONG_PRESS_TIME  3 //3*20=60ms
#define DOUBLE_PRESS_TIME  900


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

Uint16* key_GetDoubleNum(Uint16 dir1[],Uint16 dir2[]){
    Uint16 *p=NULL;
    if(double_press){
        double_cnt++;
        double_press=0;
        if(double_cnt%2) p=dir1;
        else p=dir2;
        return p;
    }
    return NULL;
}

int key_GetTimeDoubleNum(void){
    int tmp;
    if(double_press){
        tmp=double_press;
        double_press=0;
        return tmp;
    }
    return 0;
}


void Key_Tick(void){
    //t ���ڼ���˫����ʱ��
    static int count,t=0;
    static int pre=0,cur=0;
    static int flag=0;
    static int short_time=0,cnt=0;
    count++;
    cnt++;

    if(count>=20){
        count=0;
        if(flag){//���ǵ��ǳ�������ĵ���
            pre=0;
            flag=0;
        }else pre=cur;
        cur=Key_GetState();

        if(!long_press){
            if(cur==0 && pre!=0){
                if((cnt-short_time)<DOUBLE_PRESS_TIME){
                    double_press=pre;               //�������ΰ���
                    cnt=0;
                    short_time=0;
                }else{
                    key_num=pre;
                    short_time=cnt;
                }
                t=0;
            }
            else if(cur!=0 && pre!=0){
                t++;
            }else t=0;
        }

        if(t>=60){//��55*20 ms��ʱ��
            long_press=cur;
            flag=1;
        }

    }



}
