
typedef unsigned char  BYTE;
typedef unsigned short WORD;

BYTE Pia_Read(WORD address);
BYTE Pia_Write(WORD address, BYTE data);


void Pia_Init(void);
void Pia_Print(void);



