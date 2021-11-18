#include <ncurses.h>

#define BTN_HEIGHT 3
#define BTN_WIDTH 6
#define BTN_SIZE 66

#define EMTPY_DISPLAY_LINE1 "                                  "; // 34 empty characters
#define EMPTY_DISPLAY_LINE2 "                                  "; // 34 empty characters

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
int selectButton(int buttonID, int direction);

void handleButton(WINDOW *win, int buttonID);

BUTTON createButton(int height, int width,int posX, int posY, char strText1[], char strText2[], WINDOW *parent, int buttonAbove, int buttonBelow, int buttonLeft, int buttonRight);

void writeOnDisplay(WINDOW *displaywin,char textLine1[], char textLine2[]);
