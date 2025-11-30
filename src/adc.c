//#ifndef __ADC__
//#define __ADC__
#include<lpc214x.h>
#include"types.h"
#include"delay.h"
#include"adc_defines.h"
#include"pin_connect_block.h"
#include"pin_function_defines.h"

void Init_ADC()
{
        cfgportpinfunc(0,28,PIN_FUNC2);// ADC CHN 1
        AD0CR|=1<<PDN_BIT|CLKDIV<<CLKDIV_BITS;
}
void READ_ADC(u32 chno,u32 *adcval)
{
        AD0CR|=1<<chno|1<<ADC_START_BITS;
        delayUS(3);
        while(((AD0GDR>>DONE_BIT)&1)==0);
        AD0CR&=~(1<<ADC_START_BITS);
        *adcval=(AD0GDR>>RESULT_BITS)&1023;
}