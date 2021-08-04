

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <sys/shm.h>
#include <string.h>


typedef unsigned char  BYTE;
typedef unsigned short WORD;


struct shmstruct {
  WORD count;
  char displaytxt[32+2]; //+2 wegen string terminierung
  BYTE key;
  BYTE key_consumed;
};


bool use_shm;
int shm_id;
char* shmaddr, *ptr;
struct shmstruct *shmpointer;

int get_shm(void)
{
  key_t shm_key = 6166529; //VOODOO :D
  int shm_size = 1024 ; // hrmm

  use_shm=false;
  shmpointer=(struct shmstruct *)0;

  /* get the shared memory segment. */
  shm_id = shmget (shm_key, shm_size, IPC_CREAT |0775);
  printf("shm_id: %i\n",shm_id);
  if(shm_id==-1)
    return 0;

  /* Attach the shared memory segment. */
  shmaddr = (char*) shmat (shm_id, 0, 0);
  if((int)shmaddr==-1)
    {
      return 0;
    }
  else
    {
      printf ("shared memory attached at address %p\n", shmaddr);
      use_shm=true;
      shmpointer=(struct shmstruct *)shmaddr;
      return 1;
    }
}


void detach_shm(void)
{
  if(use_shm)
    shmdt (shmaddr);
}


