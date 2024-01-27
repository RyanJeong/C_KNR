#ifndef __BASEBALL_BASEBALL_H__
#define __BASEBALL_BASEBALL_H__

#define RANGE 10  /* allowed input range: 0-9*/
#define INNINGS 9 /* baseball is usually composed of nine innings */
#define PITCHES 3 /* pitches per inning */

void init(void);
void play(void);
void setAnswer(void);
void setGuess(void);

#endif /* __BASEBALL_BASEBALL_H__ */
