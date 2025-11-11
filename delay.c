#include"types.h"
void delayUS(u32 dlyUs)
{
     dlyUs*=12;
         while(dlyUs--);
}
void delayMS(u32 dlyMs)
{
         dlyMs*=12000;
         while(dlyMs--);
}
void delayS(u32 dlyS)
{
         dlyS*=12000000;
         while(dlyS--);
}