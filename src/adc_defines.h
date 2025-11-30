#ifndef __ADC_DEFINES_H__
#define __ADC_DEFINES_H__

#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)

// ADC
#define  ADCCLK 3000000// <4.5MHZ
#define CLKDIV ((PCLK/ADCCLK)-1)
// AD0CR BITS
#define CLKDIV_BITS 8
#define PDN_BIT 21
#define ADC_START_BITS 24
// ADCR
#define RESULT_BITS 6
#define DONE_BIT 31
#endif