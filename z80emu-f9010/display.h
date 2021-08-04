

//typedef unsigned char  BYTE;
//typedef unsigned short WORD;




#define OUTPUT_BUFF_FULL   0x01
#define INPUT_BUFF_FULL    0x02
#define LAST_WRITE_CONTROL 0x04
#define OVERRUN_ERROR      0x80


void Display_Clear(void);
BYTE Display_GetStatus(void);
void Display_Reset(void);
void Display_Init(void);
void Display_Print(void);
void Display_Write(WORD address, BYTE data);


