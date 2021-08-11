/* f9010.h
 * Header for f9010 example.
 *
 * Copyright (c) 2012, 2016 Lin Ke-Fong
 *
 * This code is free, do whatever you want with it.
 */

#ifndef __F9010_INCLUDED__
#define __F9010_INCLUDED__

#include "z80emu.h"

typedef unsigned char  BYTE;
typedef unsigned short WORD;


typedef struct F9010 {

	Z80_STATE	state;
	unsigned char	memory[1 << 16];
	int 		is_done;

} F9010;

#if 1 
struct shmstruct {
  WORD count;
  char displaytxt[32+2]; // +2 wegen string terminierung
  BYTE key;
  BYTE key_consumed;
};
#endif

extern void     SystemCall (F9010 *f9010);

#endif
