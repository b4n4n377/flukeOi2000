#include <ncurses.h>

#define BTN_HEIGHT 3
#define BTN_WIDTH 6
#define BTN_SIZE 66

#define EMTPY_DISPLAY_LINE1                                                    \
  "                                  "; // 34 empty characters
#define EMPTY_DISPLAY_LINE2                                                    \
  "                                  "; // 34 empty characters

typedef enum {
  BTN_0 = '0',
  BTN_1 = '1',
  BTN_2 = '2',
  BTN_3 = '3',
  BTN_4 = '4',
  BTN_5 = '5',
  BTN_6 = '6',
  BTN_7 = '7',
  BTN_8 = '8',
  BTN_9 = '9',
  BTN_10 = 'q',
  BTN_11 = 'w',
  BTN_12 = 'e',
  BTN_13 = 'r',
  BTN_14 = 't',
  BTN_15 = 'z',
  BTN_16 = 'u',
  BTN_17 = 'i',
  BTN_18 = 'o',
  BTN_19 = 'p',
  BTN_20 = 'a',
  BTN_21 = 's',
  BTN_22 = 'd',
  BTN_23 = 'f',
  BTN_24 = 'g',
  BTN_25 = 'h',
  BTN_26 = 'j',
  BTN_27 = 'k',
  BTN_28 = 'l',
  BTN_29 = 'y',
  BTN_30 = 'x',
  BTN_31 = 'c',
  BTN_32 = 'v',
  BTN_33 = 'b',
  BTN_34 = 'n',
  BTN_35 = 'm',
  BTN_36 = 'Q',
  BTN_37 = 'W',
  BTN_38 = 'E',
  BTN_39 = 'R',
  BTN_40 = 'T',
  BTN_41 = 'Z',
  BTN_42 = 'U',
  BTN_43 = 'I',
  BTN_44 = 'O',
  BTN_45 = 'P',
  BTN_46 = 'A',
  BTN_47 = 'S',
  BTN_48 = 'D',
  BTN_49 = 'F',
  BTN_50 = 'G',
  BTN_51 = 'H',
  BTN_52 = 'J',
  BTN_53 = 'K',
  BTN_54 = 'L',
  BTN_55 = 'Y',
  BTN_56 = 'X',
  BTN_57 = 'C',
  BTN_58 = 'V',
  BTN_59 = 'B',
  BTN_60 = 'N',
  BTN_61 = 'M',
  BTN_62 = '+',
  BTN_63 = '-',
  BTN_64 = '#',
  BTN_65 = '?'
} BTN_PRESSED;

typedef struct {
  int height;
  int width;
  int posX;
  int posY;

  int buttonAbove;
  int buttonBelow;
  int buttonLeft;
  int buttonRight;

  char strText1[10];
  char strText2[10];
  WINDOW *win;
} BUTTON;

void createButtons(WINDOW *menuwin);
void destroyButtons(void);

void drawButton(int buttonID);
int selectButton(int buttonID, int keyPressed, WINDOW *displaywin);

void handleButton(WINDOW *win, int buttonID);

BUTTON createButton(int height, int width, int posX, int posY, char strText1[],
                    char strText2[], WINDOW *parent, int buttonAbove,
                    int buttonBelow, int buttonLeft, int buttonRight);

void writeOnDisplay(WINDOW *displaywin, char textLine1[], char textLine2[]);
