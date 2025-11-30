#include<lpc214x.h>
#include"types.h"
#include"delay.h"
#include"lcd_defines.h"
#include"defines.h"
void WriteLCD(u8 byte)
{
        IOCLR0=1<<LCD_RW;
        WRITEBYTE(IOPIN0,LCD_DATA,byte);
        IOSET0=1<<LCD_EN;
        delayUS(1);
        IOCLR0=1<<LCD_EN;
        delayMS(2);
}
void CmdLCD(u8 cmdbyte)
{
        IOCLR0=1<<LCD_RS;
        WriteLCD(cmdbyte);
}
void Init_LCD(void)
{
        IODIR0 |=((0XFF<<LCD_DATA)|(1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN));
        delayMS(15);
        CmdLCD(0x30);
        delayMS(4);
        delayUS(100);
        CmdLCD(0x30);
        CmdLCD(MODE_8BIT_2LINE);
        CmdLCD(DSP_ON_CUR_OFF);
        CmdLCD(CLEAR_LCD);
        CmdLCD(SHIFT_CUR_RIGHT);
}
void CharLCD(u8 asciiVal)
{
        IOSET0=1<<LCD_RS;
        WriteLCD(asciiVal);
}
void StrLCD(s8 *str)
{
        while(*str)
                CharLCD(*str++);
}
void u32LCD(u32 n)
{
        s32 i=0;
        u8 a[10];
        if(n==0)
        {
                CharLCD('0');
        }
        else
        {
                while(n>0)
                {
                  a[i++]=(n%10)+48;
                  n/=10;
                }
                for(--i;i>=0;i--)
                        CharLCD(a[i]);
        }
}
void s32LCD(s32 num)
{
        if(num<0)
        {
                CharLCD('-');
                num=-num;
        }
        u32LCD(num);
}

void Build_Char_LCD(u8 *p,u8 nbytes)
{
        u32 i;
        CmdLCD(GOTO_CGRAM_START);//0X40
        IOSET0=1<<LCD_RS;
        for(i=0;i<nbytes;i++)
        {
                WriteLCD(p[i]);
        }
        CmdLCD(GOTO_LINE1_POS0);
}
