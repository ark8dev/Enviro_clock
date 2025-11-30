#ifndef __KPM_H__
#define __KPM_H__
#include"types.h"

void INIT_KPM(void);
u32 KEYSCAN_KPM(void);
u32 COLSCAN_KPM(void);
u32 ROWCHECK_KPM(void);
u32 COLCHECK_KPM(void);
#endif