#include<lpc214x.h>
#include "headers.h"
s32 choice,alarm_hour,alarm_min,alarm_sec,option,\
flag=0,flag1=0,flag2=0,alarm_option,buz_time,clk_set;

extern s32 hour,min;


u8 LCD_userdef_symbol[24]={0x00,0x04,0x0E,0x15,0x04,0x04,0x04,0x04,       //uparrow
                                                        0x04,0x04,0x04,0x04,0x15,0x0E,0x04,0x00,  //downarrow
                                                        0x04,0x0E,0X15,0X15,0X17,0X11,0X11,0X0E}; // buzz
void alarmcheck()
{
        if(flag1)
        {
                CmdLCD(GOTO_LINE2_POS0+15);
                CharLCD(2);
        }
        if(hour==alarm_hour && min==alarm_min)
        {
                if(flag1)
                {
                        WRITEBIT(IOPIN0,BUZZER_PIN,1);
                        CmdLCD(GOTO_LINE2_POS0+15);
                        CharLCD(2);
                        delayMS(100);
                        CmdLCD(GOTO_LINE2_POS0+15);
                        StrLCD(" ");
                        flag2=1;
                }
        }
        if(flag2)
        {
                if(READBIT(IOPIN0,BUZZER_STOP_SW_PIN)==0)
                {
                        WRITEBIT(IOPIN0,BUZZER_PIN,0);
                        CmdLCD(GOTO_LINE2_POS0+15);
                                CharLCD(2);
                                flag1=0;
                                flag2=0;

                }
                else if(hour==alarm_hour&& min==alarm_min+1)
                {
                        WRITEBIT(IOPIN0,BUZZER_PIN,0);
                        CmdLCD(GOTO_LINE2_POS0+15);
                                CharLCD(2);
                                flag1=0;
                                flag2=0;
                }
        }
}

void clock_setting()
{
        if(flag)
        {
                option=0;
                flag=0;
                while(1)
                {
                        if(option==0)
                        {
                                CmdLCD(CLEAR_LCD);
                                CmdLCD(GOTO_LINE1_POS0);
                                StrLCD("1 clkinfoedit");
                                Build_Char_LCD(LCD_userdef_symbol,24);
                                CmdLCD(GOTO_LINE1_POS0+14);
                                CharLCD(0);
                                CmdLCD(GOTO_LINE2_POS0);
                                StrLCD("2 alarm info");
                                CmdLCD(GOTO_LINE2_POS0+14);
                                CharLCD(1);
                        }
                        else if(option==1)
                        {
                                CmdLCD(CLEAR_LCD);
                                CmdLCD(GOTO_LINE1_POS0);
                                StrLCD("2 alarm info");
                                CmdLCD(GOTO_LINE1_POS0+14);
                                CharLCD(0);
                                CmdLCD(GOTO_LINE2_POS0);
                                StrLCD("3 exit");
                                CmdLCD(GOTO_LINE2_POS0+14);
                                CharLCD(1);
                        }
                        choice=KEYSCAN_KPM();
                        delayMS(200);
                        while((COLSCAN_KPM())==0);

                        if(choice==100)//up scroll value
                                option=1;
                        else if(choice==102)// down scroll arrow
                                option=0;
                        else if(choice==3 && option==1)
                        {
                                CmdLCD(CLEAR_LCD);
                                //break;
                                return ;
                        }
                        else if(choice==2)// alarm setting
                        {
                                 while(1)
                                 {
                                        CmdLCD(CLEAR_LCD);
                                        CmdLCD(GOTO_LINE1_POS0);
                                        StrLCD("1 alarm setting");
                                        CmdLCD(GOTO_LINE2_POS0);
                                        StrLCD("2alarmtime 3exit");
                                        alarm_option=KEYSCAN_KPM();
                                        delayMS(200);
                                        while(COLSCAN_KPM()==0);
                                        if(alarm_option==1)
                                        {
                                                flag1=1;
                                                alarm_hour=SetRTCHour();
                                                alarm_min=SetRTCMin();
                                                alarm_sec=SetRTCSec();
                                        }
                                        else if(alarm_option==2)
                                        {
                                                if(flag1==1)
                                                {
                                                        CmdLCD(CLEAR_LCD);
                                                        DisplayRTCTime(alarm_hour,alarm_min,alarm_sec);
                                                        delayS(2);
                                                }
                                                else
                                                {
                                                        CmdLCD(CLEAR_LCD);
                                                        CmdLCD(GOTO_LINE1_POS0);
                                                        StrLCD("No alarm set");
                                                        delayS(1);
                                                        CmdLCD(CLEAR_LCD);
                                                }
                                        }
                                        else if(alarm_option==3)
                                                break;
                                }
                        }


                        else if(choice==1 && option==0)
                        {
                                CmdLCD(0x01);
                                while(1)
                                {
                                        CmdLCD(GOTO_LINE1_POS0);
                                        StrLCD("1:H2:M3:S 4:EXIT");
                                        CmdLCD(GOTO_LINE2_POS0);
                                        StrLCD("5:D 6:M 7:Y 8:DY");
                                        clk_set=KEYSCAN_KPM();
                                        delayMS(200);
                                        while(COLSCAN_KPM()==0);
                                        if(clk_set==1)
                                                HOUR=SetRTCHour();

                                        else if(clk_set==2)
                                                MIN=SetRTCMin();
                                        else if(clk_set==3)
                                                SEC=SetRTCSec();
                                        else if(clk_set==5)
                                                DOM=SetRTCDate();
                                else if(clk_set==6)
                                                MONTH=SetRTCMonth();
                                        else if(clk_set==7)
                                                YEAR=SetRTCYear();
                                        else if(clk_set==8)
                                                DOW=SetRTCDay();
                                        else if(clk_set==4)
                                                break;
                                }



                        }

                }

        }

}
void KEYVAL(s32* h,u32 size)
{
        u32 val=0,keyval=0,flag=0,keypresscnt=0;
        while(1)
        {
                label:keyval=KEYSCAN_KPM();
                delayMS(100);
                while((COLSCAN_KPM())==0);
                        if((keyval==99)&& (flag==1))
                        {
                                *h=val;
                                break;
                        }
                        else if((keyval==99) && (flag==0))
                                goto label;
                        else if(keyval==88)
                        {
                                if(val<10)
                                {
                                        val=0;
                                        CmdLCD(GOTO_LINE2_POS0);
                                        StrLCD("                ");
                                        flag=0;
                                        keypresscnt=0;
                                }
                                else
                                {
                                        val=val/10;
                                        CmdLCD(GOTO_LINE2_POS0);
                                        StrLCD("                ");
                                        CmdLCD(GOTO_LINE2_POS0);
                                        u32LCD(val);
                                        keypresscnt--;
                                        delayMS(500);
                                }
                        }
                        else
                        {
                                if(keyval<10)
                                {
                                        keypresscnt++;
                                        if(keypresscnt>size)
                                        {
                                                val=0;
                                                CmdLCD(GOTO_LINE2_POS0);
                                                StrLCD("out of range");
                                                delayS(1);
                                                CmdLCD(GOTO_LINE2_POS0);
                                                StrLCD("              ");
                                                keypresscnt=0;
                                                flag=0;

                                        }
                                        else
                                        {
                                                flag=1;
                                                val=val*10+keyval;
                                                CmdLCD(GOTO_LINE2_POS0);
                                                u32LCD(val);
                                        }
                                }
                        }

        }
}
void DISPLAY_ADC_VAL(u32 adcval)
{
        CmdLCD(GOTO_LINE1_POS0+9);
        StrLCD("T:");
        s32LCD(adcval/10);
        s32LCD(adcval%10);
        CharLCD(0xDF);
        CmdLCD(GOTO_LINE1_POS0+14);
        CharLCD('C');
}
