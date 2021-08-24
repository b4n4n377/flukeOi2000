
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "f9010.h"
#include "display.h"

/* Variables */
BYTE DISPLAY_charReg[32];           // 32 positoin character register
BYTE DISPLAY_position;              // current position within this regester
bool DISPLAY_flashMode;
BYTE DISPLAY_flashPosition;
BYTE DISPLAY_status;
bool DISPLAY_scanSkipMode;
int DISPLAY_scans;

BYTE DISPLAY_annunciator;


extern struct shmstruct *shmpointer;



void Display_Clear(void)
{
  int i;
  for (i=0;i<32;i++)
    DISPLAY_charReg[i] = ' ';
  DISPLAY_position = 0;
}

// Return the status byte of the display
BYTE Display_GetStatus(void)
{
  return DISPLAY_status;
}


void Display_Reset(void)
{
  DISPLAY_position = 0;
  DISPLAY_flashMode = false;
  DISPLAY_flashPosition = 0;
  DISPLAY_scanSkipMode = false;
  DISPLAY_scans = 0;
  DISPLAY_annunciator = 0x00;
  Display_Clear();
}



void Display_Init(void)
{
  // clear LEDs
  DISPLAY_annunciator = 0x00;

  // init reg index
  DISPLAY_position = 0;

  // init status
  DISPLAY_status = 0x00;

  // init scans variable
  DISPLAY_scanSkipMode = false;
  DISPLAY_scans = 0;

  // clear the display
  Display_Clear();
  
}

void Display_Print(void)
{
  int i;
  printf("DISPLAY: ");
  for (i=0;i<32;i++)
    printf("%c",DISPLAY_charReg[i]);
  printf("\n");

  if(shmpointer)
    strncpy(shmpointer->displaytxt, (const char *)DISPLAY_charReg, 32);

  //printf("\n annunciator: %x\n",DISPLAY_annunciator);
}





// Write a byte to the display unit
void Display_Write(WORD address, BYTE data)
{
  BYTE DISPLAY_tag;

  // if address == 0080, write to register pointed to by position pointer
  //Write_Debug(fp_debug,"address is %X \n");
  if (address == 0x0080)
    {
      // if buffer isn't full, write data
      if (DISPLAY_position < 31)
	{
	  DISPLAY_charReg[DISPLAY_position++] = data;
	  // last write was data
	  DISPLAY_status = DISPLAY_status & (!LAST_WRITE_CONTROL);
	}
      else
	{
	  // if display buffer is full, set status bit accordingly
	  // something doesn't add up ?
	  DISPLAY_status = DISPLAY_status | LAST_WRITE_CONTROL;
	}
      return;
    }

  // else address should == 0081 so handle accordingly

  // save tag for use later
  DISPLAY_tag = data & 0xE0;

  if (data == 0x00)
    {
      // reset test mode
    }
  else if (data == 0x01)
    {
      // display segment self test
    }
  else if (data == 0x02)
    {
      // digit drivers self test
    }
  else if (data == 0x04)
    {
      // annunciator self test
    }
  else if (data == 0x08)
    {
      // keyboard self test
    }
  else if (DISPLAY_tag == 0x20)
    DISPLAY_position = data & 0x1F;
  else if (DISPLAY_tag == 0x40)
    {
      DISPLAY_annunciator = data;
    }
  else if (DISPLAY_tag == 0x60)
    {
      // turns on flash mode
      DISPLAY_flashPosition = (data & 0x1F);
      DISPLAY_flashMode = true;
    }
  else if (data == 0x80)
    {
      // turns of flah mode
      DISPLAY_flashMode = false;
    }
  else if (DISPLAY_tag == 0xC0)
    {
      // clears the display
      Display_Clear();
    }
  else if (DISPLAY_tag == 0xE0)
    {
      // turns of display for N scans of the display
      DISPLAY_scans = data & 0x1F;
    }
  else if (data == 0xFF)
    Display_Reset();
  else
    {
      printf("Wrote %x to address: %x in display unit.\n",data,address);
      // ?? Check for this
    }

  // last write was control
  DISPLAY_status = DISPLAY_status | LAST_WRITE_CONTROL;


        printf("Wrote %x to address: %x in display unit.\n",data,address);
}







