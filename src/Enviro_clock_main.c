#include <lpc214x.h>
#include "headers.h"
s32 hour,min,sec,date,month,year,day;
u32 adcval,adceqval,chno=1;
int main()
{
                extint_INIT();
        RTC_Init();
        Init_LCD();
                INIT_KPM();
                Init_ADC();
        SetRTCTimeInfo(11,22,4);
        SetRTCDateInfo(2,9,2003);
        SetRTCDayinfo(2);
                WRITEBIT(IODIR0,BUZZER_PIN,1);


                while (1)
        {
                GetRTCTimeInfo(&hour,&min,&sec);
                DisplayRTCTime(hour,min,sec);
                GetRTCDateInfo(&date,&month,&year);
                DisplayRTCDate(date,month,year);
                GetRTCDay(&day);
                DisplayRTCDay(day);

                                READ_ADC(chno,&adcval);
                                adcval=(((adcval*3.3)/1023)*100);
                                DISPLAY_ADC_VAL(adcval);

                                alarmcheck();
                                clock_setting();
                }
}

