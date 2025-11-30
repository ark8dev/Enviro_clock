
#include<lpc214x.h>
#include "headers.h"
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
s32 h;
void RTC_Init(void)
{
                CCR=RTC_RESET;
        PREINT=PREINT_VAL;
                PREFRAC=PREFRAC_VAL;
                CCR=RTC_ENABLE|RTC_CLKSRC;
}

void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
        *hour = HOUR;
        *minute = MIN;
        *second = SEC;

}
void DisplayRTCTime(s32 hour, s32 minute, s32 second)
{
                CmdLCD(GOTO_LINE1_POS0);
                CharLCD((hour/10)+48);
                CharLCD((hour%10)+48);
                CharLCD(':');
                CharLCD((minute/10)+0x30);
                CharLCD((minute%10)+0x30);
                CharLCD(':');
                CharLCD((second/10)+'0');
                CharLCD((second%10)+'0');

}
void SetRTCTimeInfo(u32 hour,u32 min,u32 sec)
{
                HOUR=hour;
                MIN=min;
                SEC=sec;

}
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)
{
        *date = DOM;
        *month = MONTH;
        *year = YEAR;
}
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
                CmdLCD(GOTO_LINE2_POS0);
                CharLCD((date/10)+48);
                CharLCD((date%10)+48);
                CharLCD('/');
                CharLCD((month/10)+0x30);
                CharLCD((month%10)+0x30);
                CharLCD('/');
                                u32LCD(year);

}
void SetRTCDateInfo(u32 date,u32 month,u32 year)
{
        DOM=date;
        MONTH=month;
        YEAR=year;

}
void GetRTCDay(s32 *dayofweek)
{
        *dayofweek = DOW;
}
void DisplayRTCDay(u32 dayofweek)
{
        CmdLCD(GOTO_LINE2_POS0+11);
        StrLCD(week[dayofweek]);
}
void SetRTCDayinfo(u32 day)
{
                         DOW=day;
}
u32 SetRTCHour(void)
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter hour(0-23)");
                KEYVAL(&h,2);
                if(h>=24 || h<0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayS(1);
                        goto label;
                }
                return h;
}
u32 SetRTCMin(void)
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter min(0-59)");
                KEYVAL(&h,2);
                if(h>=60 || h<0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(1000);
                        goto label;
                }
                return h;
}
u32 SetRTCSec()
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter sec(0-59)");
                KEYVAL(&h,2);
                if(h>60 || h<0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(1000);
                        goto label;
                }
                return h;
}
u32 SetRTCDate()
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter date(1-31)");
                KEYVAL(&h,2);
                if(h>31 || h<=0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(1000);
                        goto label;
                }
                return h;
}
u32 SetRTCMonth()
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter month 1-12");
                KEYVAL(&h,2);
                if(h>12 || h<=0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(1000);
                        goto label;
                }
                return h;
}
u32 SetRTCYear()
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("enter year <6025");
                KEYVAL(&h,4);
                if(h>2024 && h<=6025)
                {
                        return  h;
                }
                else
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(1000);
                        goto label;
                }
}
u32 SetRTCDay()
{
        label:CmdLCD(CLEAR_LCD);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("ent dy0:su-6:sat");
                KEYVAL(&h,1);
                if(h>6 || h<0)
                {
                        CmdLCD(CLEAR_LCD);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("invalid");
                        delayMS(500);
                        goto label;
                }
                return h;
}
