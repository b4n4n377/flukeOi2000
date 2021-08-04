

#include "pia.h"

#include <stdio.h>


#define CHECK_BIT(x, pos) (x & (1UL << pos) )

//#define PIA_REG_


BYTE PIA_ORA;   // Periphal Output Register A
BYTE PIA_ORB;   // Periphal Output Register B
BYTE PIA_DDRA;  //Data Direction Register A
BYTE PIA_DDRB;  //Data Direction Register B
BYTE PIA_PIBA;
BYTE PIA_PIBB;
BYTE PIA_CRA;   // Control Register A
BYTE PIA_CRB;   // Control Register B

WORD registerindex;

void Pia_Init(void)
{
  PIA_ORA=0;
  PIA_ORB=0;
  PIA_DDRA=0;
  PIA_DDRB=0;
  PIA_PIBA=0;
  PIA_PIBB=0;
  PIA_CRA=0;
  PIA_CRB=0;
}


void Pia_Print(void)
{
  printf("PIA: CRA,DDRA,ORA,PIBA: %X %X %X %X\n", PIA_CRA,PIA_DDRA,PIA_ORA,PIA_PIBA);
  printf("PIA: CRB,DDRB,ORB,PIBB: %X %X %X %X\n", PIA_CRB,PIA_DDRB,PIA_ORB,PIA_PIBB);
}


// from Datasheet Rockwell R6520
// IRQ features not in use

BYTE Pia_Read(WORD address)
{
  registerindex = address & 0x03 ;
  
  switch (registerindex)
    {
    case 0x00:
	printf("PiaR 00\n");
	if(CHECK_BIT(PIA_CRA,2))
	  {
	    return PIA_PIBA;
	  }
	else
	  return PIA_DDRA;
	
	break ;
      
    case 0x01:
	printf("PiaR 01\n");
	return PIA_CRA;
	
	break ;      

    case 0x02:
	printf("PiaR 10\n");

	if(CHECK_BIT(PIA_CRB,2))
	  {
	    return PIA_PIBB;
	  }
	else
	  return PIA_DDRB;
	
	break ;      

    case 0x03:
	printf("PiaR 11\n");
	return PIA_CRB;
	
	break ;
      

    default:
      return 0; // wird nicht erreicht
    }
  
}

BYTE Pia_Write(WORD address, BYTE data)
{
  registerindex = address & 0x03 ;

  switch (registerindex)
    {
    case 0x00:
      printf("PiaW 00, %x\n",data);

      if(CHECK_BIT(PIA_CRA,2))
	{
	  PIA_ORA=data;
	}
      else
	PIA_DDRA=data;

      break ;

      
    case 0x01:
      printf("PiaW 01,%X\n",data);
      PIA_CRA=data;
      
      break ;

    case 0x02:
      printf("PiaW 10,%X\n",data);

      if(CHECK_BIT(PIA_CRB,2))
	{
	  PIA_ORB=data;
	}
      else
	PIA_DDRB=data;

       break ;

       
    case 0x03:
      printf("PiaW 11,%X\n",data);
      PIA_CRB=data;
      
      break ;


    }
  return 0; // wird nie erreicht  
}

