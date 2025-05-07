#include "key.h"
int key_num;//按键返回值 确定按键

void key_init(void){

    EALLOW;
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;   // 普通GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;    // 输入模式
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;  // 同步采样
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0; //上拉输入
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

#define LONG_PRESS_TIME  200
void Key_Tick(void){
    static int count,t;
    static int pre,cur;
    static unsigned int longPressCount = 0;
    count++;
    t++;
    if(count>=20){
        count=0;
        pre=cur;
        cur=Key_GetState();
        if(cur==0 && pre!=0){
            key_num=pre;
        }
}
