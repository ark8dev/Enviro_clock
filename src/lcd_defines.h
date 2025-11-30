#ifndef __LCD_DEFINES_H__
#define __LCD_DEFINES_H__
//HD44780 commands

#define CLEAR_LCD        0x01
#define RET_CUR_HOME     0x02

#define SHIFT_CUR_RIGHT  0x06
#define SHIFT_CUR_LEFT   0x07

#define DSP_OFF          0x08
#define DSP_ON_CUR_OFF   0x0C
#define DSP_ON_CUR_ON    0x0E
#define DSP_ON_CUR_BLINK 0x0F

#define SHIFT_DISP_LEFT  0X10
#define SHIFT_DISP_RIGHT 0X14

#define MODE_8BIT_1LINE  0X30
#define MODE_4BIT_1LINE  0X20
#define MODE_8BIT_2LINE  0X38
#define MODE_4BIT_2LINE  0X28

#define GOTO_LINE1_POS0  0X80
#define GOTO_LINE2_POS0  0XC0
#define GOTO_LINE3_POS0  0X94
#define GOTO_LINE4_POS0  0XD4
#define GOTO_CGRAM_START 0X40

//LPC2129 port pin connection to lcd
#define LCD_DATA  8 //Pin 0.1 TO P0.7
#define LCD_RS    5     //pin 0.5
#define LCD_EN    6     //pin 0.6
#define LCD_RW    7     //pin 0.7
#endif