#ifndef __LCD_H__
#define __LCD_H__
#include"types.h"
void Init_LCD(void);
void WriteLCD(u8 byte);
void CmdLCD(u8 cmd);
void CharLCD(u8 asciival);
void StrLCD(s8 *);
void u32LCD(u32);
void s32LCD(s32);
void f32LCD(f32,u32);
void Build_Char_LCD(u8 *,u8);
#endif