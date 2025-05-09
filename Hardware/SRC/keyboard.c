#include "keyboard.h"
int keyboard_num=0;
//存储数码管显示字符的段码，共20个元素，对应0-9、A-F及特殊符号
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
//行引脚：连接到矩阵的行，通常设置为输出模式。
//列引脚：连接到矩阵的列，通常设置为输入模式，并启用上拉电阻。
void Setkeybord(void){
    GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
}
int Board_GetState(void){
    if(KEY1==0) return 5;
    else if(KEY2==0) return 2;
    else if(KEY3==0) return 3;
    else if(KEY4==0) return 4;
    else return 0;
}
int key_GetKeyBoardNum(void){
    int tmp;
    if(keyboard_num){
        tmp=keyboard_num;
        keyboard_num=0;
        return tmp;
    }
    return 0;
}


void KeyBoard_Tick(void){
    //t 用于计数双击的时间
    static int count;
    static int pre=0,cur=0;
    count++;

    if(count>=20){
        count=0;
        pre=cur;
        cur=Board_GetState();
        if(cur==0 && pre!=0){
            keyboard_num=pre;
        }
    }

}


//明天去测
void KeyBoard_Tick1(void){
    static int count=0,i=0;
    static int pre=0,cur=0;
    count++;
    if(count>20){
        count=0;
        pre=cur;
        Setkeybord();
        for(i=0;i<4;i++){
            switch(i){
                case 1:
                    KEY53=0;
                    cur=Board_GetState();
                    if(cur==0 && pre!=0){
                        keyboard_num=pre;
                    }
                case 2:
                    KEY53=0;
                    cur=Board_GetState();
                    if(cur==0 && pre!=0){
                        keyboard_num=pre;
                    }

            }
        }

    }


}




void keyboard_scan_lie(int i){
    //循环扫描按键列（GPIO49到GPIO53），每次只将其中一列设置为低电平（接地），其他列保持高电平。
        switch(i){
           case 0:
               GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO53 = 0;
               break;

           case 1:
               GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO52 = 0;
               break;

           case 2:
               GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO51 = 0;
               break;

           case 3:
               GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO49 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO50 = 0;
               break;

           case 4:
               GpioDataRegs.GPBDAT.bit.GPIO53 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO52 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO51 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO50 = 1;
               GpioDataRegs.GPBDAT.bit.GPIO49 = 0;
               break;

         }

}





void InitXintf16Gpio(void)
{
     EALLOW;
     GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;  // XD15
     GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;  // XD14
     GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3;  // XD13
     GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3;  // XD12
     GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3;  // XD11
     GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3;  // XD10
     GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3;  // XD19
     GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3;  // XD8
     GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3;  // XD7
     GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3;  // XD6
     GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3;  // XD5
     GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3;  // XD4
     GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3;  // XD3
     GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3;  // XD2
     GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3;  // XD1
     GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3;  // XD0

     GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 3;  // XA0/XWE1n
     GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 3;  // XA1
     GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;  // XA2
     GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;  // XA3
     GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 3;  // XA4
     GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 3;  // XA5
     GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 3;  // XA6
     GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 3;  // XA7

     GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3;  // XA8
     GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3;  // XA9
     GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3;  // XA10
     GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3;  // XA11
     GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 3;  // XA12
     GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 3;  // XA13
     GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 3;  // XA14
     GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 3;  // XA15
     GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3;  // XA16
     GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3;  // XA17
     GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3;  // XA18
     GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // XA19

     GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 3;  // XREADY
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 3;  // XRNW
     GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3;  // XWE0

     GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 3;  // XZCS0
     GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3;  // XZCS7
     GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // XZCS6

     EDIS;
}

void configtestled(void)//键盘和电机的都有了
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

void keyboard_init(void){
    configtestled();
    InitXintf16Gpio();
}

//向数码管写入指定索引的段码
//通过LEDSAB和LEDSCLK模拟串行数据传输（类似SPI）
//循环8次，将LedCode[index]的每一位依次输出到数据线，并通过时钟线触发移位。
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

