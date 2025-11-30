#ifndef __DEFINES_H__
#define __DEFINES_H__

#define WRITEBYTE(word,bytestartpos,val)\
                (word=((word&~(0xff<<bytestartpos))|(val<<bytestartpos)))
#define READBIT(word,bitpos)\
                ((word>>bitpos)&1)
#define WRITEBIT(word,bitpos,val)\
                (word=((word&~(1<<bitpos))|(val<<bitpos)))
#define WRITENIBBLE(word,nibblestartpos,val)\
                   (word=((word&~(0xf<<nibblestartpos))|(val<<nibblestartpos)))

#define READNIBBLE(word,nibblestartpos)\
                 ((word>>nibblestartpos)&0xf)


// external ineterrupts
#define EINT0_CHN0 14
#define BUZZER_PIN 16
#define BUZZER_STOP_SW_PIN 17
#endif