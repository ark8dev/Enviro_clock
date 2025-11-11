// adc defines
#define FOSC 12000000  // frequency oscillator
#define CCLK (5*FOSC)  // cpu clock
#define PCLK (CCLK/4)  // peripheral clock

// ADC
#define  ADCCLK 3000000// <4.5MHZ   //adc clock
#define CLKDIV ((PCLK/ADCCLK)-1)    // clock divider value for adc clock
// AD0CR BITS
#define CLKDIV_BITS 8    
#define PDN_BIT 21
#define ADC_START_BITS 24
// ADCR
#define RESULT_BITS 6

#define DONE_BIT 31
