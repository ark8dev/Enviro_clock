#ifndef __KPM_DEFINES_H__
#define __KPM_DEFINES_H__

#define ROW0 16 // pin 1.16
#define ROW1 17
#define ROW2 18
#define ROW3 19

#define COL0 20  //pin 1.20
#define COL1 21
#define COL2 22
#define COL3 23

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
#endif