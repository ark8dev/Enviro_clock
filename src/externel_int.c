#include<lpc214x.h>
#include "types.h"
#include "pin_connect_block.h"
#include "pin_function_defines.h"
extern s32 flag;

void clock_eint_isr()__irq
{
         flag=1;
        EXTINT=1<<0;
        VICVectAddr=0;
}
#define EINT0_CHN0 14
void extint_INIT()
{
        cfgportpinfunc(0,1,PIN_FUNC4);
        VICIntEnable=1<<EINT0_CHN0;
        VICVectCntl0=(1<<5)|EINT0_CHN0;
        VICVectAddr0 =(u32)clock_eint_isr;
        EXTINT=0;
        EXTMODE=1<<0;
        EXTPOLAR=0;
}