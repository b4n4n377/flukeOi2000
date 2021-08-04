
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "f9010.h"
#include "display.h"
#include "keyboard.h"

extern struct shmstruct *shmpointer;

BYTE Keyboard_Read(void)
{
  BYTE key;
  
  if ( shmpointer->key_consumed==0 )
    {
      shmpointer->key_consumed=1;    //verbraucht
      key=shmpointer->key;
      return key;
    }
  else
    {
      shmpointer->key=0xff;  //hm
      return 0xFF;
    }
}


BYTE Keyboard_GetStatus(void)
{
  if (shmpointer->key_consumed==0)
    return OUTPUT_BUFF_FULL;
  else
    return 0x00;
}

