#include<lpc214x.h>
#include"types.h"
#include"kpm_defines.h"
u32 kpmlut[4][4]={{1,2,3,4},
                  {5,6,7,8},
                  {9,0,0,100},// 100 up arrow keyval
                  {99,0,88,102}};// 99 enter keyvalue.88 backspace key value,102 down arrow key value
void INIT_KPM()
{
        WRITENIBBLE(IODIR1,ROW0,0x0f);
}
u32 COLSCAN_KPM()
{
        // reading the status of col pins if any pin status is 0, state that some pin is pressed
        return ((READNIBBLE(IOPIN1,COL0)<15))?0:1;
}
u32 ROWCHECK_KPM()
{
        u32 i;
        for(i=0;i<4;i++)
        {
                WRITENIBBLE(IOPIN1,ROW0,(~(1<<i)));
                if(COLSCAN_KPM()==0)
                {
                      break;
                }
        }
    //cfging row pins as gpio out, col pins as gpio input, default all pins are inpu
     WRITENIBBLE(IOPIN1,ROW0,0);
    return i;
}
u32 COLCHECK_KPM()
{
        u32 i;
        for(i=0;i<4;i++)
        {
                if(READBIT(IOPIN1,COL0+i)==0)
                     break;
        }
        return i;
}

u32 KEYSCAN_KPM()
{
        u32 row,col,keyval;
        while(COLSCAN_KPM());
        row=ROWCHECK_KPM();
        col=COLCHECK_KPM();
        keyval=kpmlut[row][col];
        return keyval;
}
