// external interrupts defination
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
        // cfg port 0 pin 1 as external intterupt pin
        cfgportpinfunc(0,1,PIN_FUNC4);
        // cfg interrupt as fiq
        //VICIntSelect=0;
        // enabling interrupt
        VICIntEnable=1<<EINT0_CHN0;
        VICVectCntl0=(1<<5)|EINT0_CHN0;
        VICVectAddr0 =(u32)clock_eint_isr;
        // external interrupt peripheral sfrs
        // enabling external interrupts
        EXTINT=0;// default enable
        // cfg intterupt as edge or level triggering
        EXTMODE=1<<0;
        // raising edge or falling edge
        EXTPOLAR=0;

}
