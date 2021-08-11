/* f9010.c
 * This will emulate the Fluke9010 
 * Some Info taken from FlukeEm 
 * Saufen!Oi!
 * Z80emu:
 * Copyright (c) 2012, 2016 Lin Ke-Fong
 * Copyright (c) 2012 Chris Pressey
 *
 * This code is free, do whatever you want with it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/shm.h>
#include <string.h>

#include "f9010.h"
#include "z80emu.h"
#include "display.h"
#include "keyboard.h"
#include "pia.h"

#define Z80_CPU_SPEED           4000000   /* In Hz. */
//#define CYCLES_PER_STEP         (Z80_CPU_SPEED / 50)
#define CYCLES_PER_STEP 100
#define MAXIMUM_STRING_LENGTH   100


static void	emulate (char *filename);




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



int main (void)
{
	time_t	start, stop;


	get_shm();
        Display_Init();
        Display_Reset();

	Pia_Init();
	
	if(shmpointer)
	  strcpy(shmpointer->displaytxt, "hallo shm");
	
	start = time(NULL);
        emulate("rom/f9010.rom");
               
	stop = time(NULL);
	printf("Emulating took a total of %d second(s).\n",
		(int) (stop - start));

	detach_shm();
        return EXIT_SUCCESS;
}


static void emulate (char *filename)
{
        FILE   	*file;
        long   	l;
	F9010	context;
        double 	total;

        printf("Testing \"%s\"...\n", filename);
        if ((file = fopen(filename, "rb")) == NULL) {

                fprintf(stderr, "Can't open file!\n");
                exit(EXIT_FAILURE);

        }
        fseek(file, 0, SEEK_END);
        l = ftell(file);

        fseek(file, 0, SEEK_SET);
        
	fread(context.memory + 0x000, 1, l, file);

        fclose(file);
	
	context.is_done = 0;


        /* Emulate. */

        Z80Reset(&context.state);
        context.state.pc = 0x000;
        total = 0.0;
	do
	  {
	    total += Z80Emulate(&context.state, CYCLES_PER_STEP, &context);
	    usleep(1);  // slow down a bit

	    //printf("pc: %x\n",context.state.pc);
	    
	  }
	while (!context.is_done);

	
	printf("\n%.0f cycle(s) emulated.\n" 
                "For a Z80 running at %.2fMHz, "
                "that would be %d second(s) or %.2f hour(s).\n",
                total,
                Z80_CPU_SPEED / 1000000.0,
                (int) (total / Z80_CPU_SPEED),
                total / ((double) 3600 * Z80_CPU_SPEED));



}




// Info from schematics / FlukeEm

BYTE ReadIOPort(WORD address)
{
  WORD maskedAddress = address & 0x00E0;
  BYTE returnVal;

  if ((maskedAddress >= 0x0000) && (address < 0x0080))
    {
      // read from event cntr or sig gen

      // bit 7 is !(Fuse blown)
      returnVal = 0x80;
    }
  else if (maskedAddress == 0x0080)
    {
      // read from keyboard/display unit
      returnVal = 0; 

      if(shmpointer)
	{
	  if (address == 0x0080)
	    return Keyboard_Read();
	  else if (address == 0x0081)
	    return Display_GetStatus() | Keyboard_GetStatus();
	  else
	    return 0x00;
	}
      
    }
  else if (maskedAddress == 0x00A0)
    {
      // read from tape drive
      returnVal = 0; // myTapeUnit->Read(address);
    }
  else if (maskedAddress == 0x00C0) // read from to POD/Probe PIA
    {
      returnVal = Pia_Read(address);
      Pia_Print();
      //returnVal=0b11100000;
    }
  else if (maskedAddress == 0x00E0)
    {
      // read from RS232
      returnVal = 0; // myRS232->Read(address);
    }
  else
    {
      returnVal = 0x00;
    }


  //  if( maskedAddress != 0x0000)
  //if( maskedAddress != 0x0080)
  //  if(maskedAddress != 0x00c0)
  //       printf("in port,v: %X \n",address);

  if(address == 0x0080)
    printf("in port,v: %X \n",address);
      
  return returnVal;
  

}

void WriteIOPort(WORD address, BYTE data)
{
  WORD maskedAddress = address & 0x00E0;

  if ((maskedAddress >= 0x0000) && (address < 0x0080))
    {
      // write to event cntr or sig gen
    }
  else if (maskedAddress == 0x0080)
    {
      // write to keyboard/display unit
      Display_Write(address, data);
      Display_Print();
    }
  else if (maskedAddress == 0x00A0)
    {
      // write to tape drive
    }
  else if (maskedAddress == 0x00C0) // write to POD/Probe PIA
    {
      Pia_Write(address, data);
      Pia_Print();
    }
  else if (maskedAddress == 0x00E0)
    {
      // write to RS232
    }
  else
    {
    }

    if( maskedAddress != 0x0080)
      if(maskedAddress != 0x00c0)
       printf("out port,v: %X,%X \n",address,data);
}


