#ifndef __RTC_H__
#define __RTC_H__

#include "types.h"

void RTC_Init(void);

void GetRTCTimeInfo(s32 *,s32 *,s32 *);
void GetRTCDateInfo(s32 *,s32 *,s32 *);
void GetRTCDay(s32 *);

void SetRTCTimeInfo(u32,u32,u32);
void SetRTCDateInfo(u32,u32,u32);
void SetRTCDayinfo(u32);

void DisplayRTCTime(s32,s32,s32);
void DisplayRTCDate(u32,u32,u32);
void DisplayRTCDay(u32);

u32 SetRTCHour(void);
u32 SetRTCMin(void);
u32 SetRTCSec(void);
u32 SetRTCDate(void);
u32 SetRTCMonth(void);
u32 SetRTCYear(void);
u32 SetRTCDay(void);
#endif