#include "menu.h"
#include <ncurses.h>
#include "i2clcd.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

BUTTON BUTTONS[BTN_SIZE];
char buttonIDstr[3];
BTN_PRESSED btn;
int newButton;

BUTTON createButton(int height, int width, int posX, int posY, char strText1[],
                    char strText2[], WINDOW *parent, int buttonAbove,
                    int buttonBelow, int buttonLeft, int buttonRight)
{

  BUTTON button;
  button.height = height;
  button.width = width;

  strncpy(button.strText1, strText1, 6);
  strncpy(button.strText2, strText2, 6);
  button.win = derwin(parent, height, width, posX, posY);

  button.buttonAbove = buttonAbove;
  button.buttonBelow = buttonBelow;
  button.buttonLeft = buttonLeft;
  button.buttonRight = buttonRight;

  return button;
}

void writeOnDisplay(WINDOW *displaywin, char textLine1[], char textLine2[])
{

  wattron(displaywin, A_REVERSE);

  // clear display before writing
  char line1[] = EMTPY_DISPLAY_LINE1;
  mvwprintw(displaywin, 1, 23, line1);
  char line2[] = EMPTY_DISPLAY_LINE2;
  mvwprintw(displaywin, 2, 23, line2);
  wrefresh(displaywin);

  line1[33] = '\0'; // shorten line to 32 characters for the actual text
  line2[33] = '\0'; // shorten line to 32 characters for the actual text

  // insert the new strings into the line strings
  for (int i = 0; (i < strlen(textLine1)) && (i < 32); i++)
  {

    line1[i] = textLine1[i];
    usleep(20000);
    mvwprintw(displaywin, 1, 24, line1);
    wrefresh(displaywin);
  }

  for (int i = 0; (i < strlen(textLine2)) && (i < 32); i++)
  {
    line2[i] = textLine2[i];
    usleep(20000);
    mvwprintw(displaywin, 2, 24, line2);
    wrefresh(displaywin);
  }

  wattroff(displaywin, A_REVERSE);
}

void drawButton(int buttonID)
{
  box(BUTTONS[buttonID].win, 0, 0);
  mvwprintw(BUTTONS[buttonID].win, 0, 1, BUTTONS[buttonID].strText1);
  mvwprintw(BUTTONS[buttonID].win, 1, 1, BUTTONS[buttonID].strText2);
  wrefresh(BUTTONS[buttonID].win);
}

int selectButton(int buttonID, int keyPressed, WINDOW *displaywin)
{

  switch (keyPressed)
  {

  // up, down, left, right and ENTER ----------
  case KEY_UP:
    newButton = BUTTONS[buttonID].buttonAbove;
    break;
  case KEY_DOWN:
    newButton = BUTTONS[buttonID].buttonBelow;
    break;
  case KEY_LEFT:
    newButton = BUTTONS[buttonID].buttonLeft;
    break;
  case KEY_RIGHT:
    newButton = BUTTONS[buttonID].buttonRight;
    break;
  case 10:
    handleButton(displaywin, buttonID);
    newButton = buttonID;
    break;

  // actual button mappings ------------------
  case BTN_0:
    newButton = 0;
    handleButton(displaywin, newButton);

    ClrLcd();
    lcdLoc(LINE1);
    typeln("Button");
    lcdLoc(LINE2);
    typeln("0");

    break;
  case BTN_1:
    newButton = 1;
    handleButton(displaywin, newButton);
    break;
  case BTN_2:
    newButton = 2;
    handleButton(displaywin, newButton);
    break;
  case BTN_3:
    newButton = 3;
    handleButton(displaywin, newButton);
    break;
  case BTN_4:
    newButton = 4;
    handleButton(displaywin, newButton);
    break;
  case BTN_5:
    newButton = 5;
    handleButton(displaywin, newButton);
    break;
  case BTN_6:
    newButton = 6;
    handleButton(displaywin, newButton);
    break;
  case BTN_7:
    newButton = 7;
    handleButton(displaywin, newButton);
    break;
  case BTN_8:
    newButton = 8;
    handleButton(displaywin, newButton);
    break;
  case BTN_9:
    newButton = 9;
    handleButton(displaywin, newButton);
    break;
  case BTN_10:
    newButton = 10;
    handleButton(displaywin, newButton);
    break;
  case BTN_11:
    newButton = 11;
    handleButton(displaywin, newButton);
    break;
  case BTN_12:
    newButton = 12;
    handleButton(displaywin, newButton);
    break;
  case BTN_13:
    newButton = 13;
    handleButton(displaywin, newButton);
    break;
  case BTN_14:
    newButton = 14;
    handleButton(displaywin, newButton);
    break;
  case BTN_15:
    newButton = 15;
    handleButton(displaywin, newButton);
    break;
  case BTN_16:
    newButton = 16;
    handleButton(displaywin, newButton);
    break;
  case BTN_17:
    newButton = 17;
    handleButton(displaywin, newButton);
    break;
  case BTN_18:
    newButton = 18;
    handleButton(displaywin, newButton);
    break;
  case BTN_19:
    newButton = 19;
    handleButton(displaywin, newButton);
    break;
  case BTN_20:
    newButton = 20;
    handleButton(displaywin, newButton);
    break;
  case BTN_21:
    newButton = 21;
    handleButton(displaywin, newButton);
    break;
  case BTN_22:
    newButton = 22;
    handleButton(displaywin, newButton);
    break;
  case BTN_23:
    newButton = 23;
    handleButton(displaywin, newButton);
    break;
  case BTN_24:
    newButton = 24;
    handleButton(displaywin, newButton);
    break;
  case BTN_25:
    newButton = 25;
    handleButton(displaywin, newButton);
    break;
  case BTN_26:
    newButton = 26;
    handleButton(displaywin, newButton);
    break;
  case BTN_27:
    newButton = 27;
    handleButton(displaywin, newButton);
    break;
  case BTN_28:
    newButton = 28;
    handleButton(displaywin, newButton);
    break;
  case BTN_29:
    newButton = 29;
    handleButton(displaywin, newButton);
    break;
  case BTN_30:
    newButton = 30;
    handleButton(displaywin, newButton);
    break;
  case BTN_31:
    newButton = 31;
    handleButton(displaywin, newButton);
    break;
  case BTN_32:
    newButton = 32;
    handleButton(displaywin, newButton);
    break;
  case BTN_33:
    newButton = 33;
    handleButton(displaywin, newButton);
    break;
  case BTN_34:
    newButton = 34;
    handleButton(displaywin, newButton);
    break;
  case BTN_35:
    newButton = 35;
    handleButton(displaywin, newButton);
    break;
  case BTN_36:
    newButton = 36;
    handleButton(displaywin, newButton);
    break;
  case BTN_37:
    newButton = 37;
    handleButton(displaywin, newButton);
    break;
  case BTN_38:
    newButton = 38;
    handleButton(displaywin, newButton);
    break;
  case BTN_39:
    newButton = 39;
    handleButton(displaywin, newButton);
    break;
  case BTN_40:
    newButton = 40;
    handleButton(displaywin, newButton);
    break;
  case BTN_41:
    newButton = 41;
    handleButton(displaywin, newButton);
    break;
  case BTN_42:
    newButton = 42;
    handleButton(displaywin, newButton);
    break;
  case BTN_43:
    newButton = 43;
    handleButton(displaywin, newButton);
    break;
  case BTN_44:
    newButton = 44;
    handleButton(displaywin, newButton);
    break;
  case BTN_45:
    newButton = 45;
    handleButton(displaywin, newButton);
    break;
  case BTN_46:
    newButton = 46;
    handleButton(displaywin, newButton);
    break;
  case BTN_47:
    newButton = 47;
    handleButton(displaywin, newButton);
    break;
  case BTN_48:
    newButton = 48;
    handleButton(displaywin, newButton);
    break;
  case BTN_49:
    newButton = 49;
    handleButton(displaywin, newButton);
    break;
  case BTN_50:
    newButton = 50;
    handleButton(displaywin, newButton);
    break;
  case BTN_51:
    newButton = 51;
    handleButton(displaywin, newButton);
    break;
  case BTN_52:
    newButton = 52;
    handleButton(displaywin, newButton);
    break;
  case BTN_53:
    newButton = 53;
    handleButton(displaywin, newButton);
    break;
  case BTN_54:
    newButton = 54;
    handleButton(displaywin, newButton);
    break;
  case BTN_55:
    newButton = 55;
    handleButton(displaywin, newButton);
    break;
  case BTN_56:
    newButton = 56;
    handleButton(displaywin, newButton);
    break;
  case BTN_57:
    newButton = 57;
    handleButton(displaywin, newButton);
    break;
  case BTN_58:
    newButton = 58;
    handleButton(displaywin, newButton);
    break;
  case BTN_59:
    newButton = 59;
    handleButton(displaywin, newButton);
    break;
  case BTN_60:
    newButton = 60;
    handleButton(displaywin, newButton);
    break;
  case BTN_61:
    newButton = 61;
    handleButton(displaywin, newButton);
    break;
  case BTN_62:
    newButton = 62;
    handleButton(displaywin, newButton);
    break;
  case BTN_63:
    newButton = 63;
    handleButton(displaywin, newButton);
    break;
  case BTN_64:
    newButton = 64;
    handleButton(displaywin, newButton);
    break;
  case BTN_65:
    newButton = 65;
    handleButton(displaywin, newButton);
    break;

  default:
    newButton = buttonID;
    break;
  }

  wattron(BUTTONS[newButton].win, A_REVERSE);
  drawButton(newButton);
  wattroff(BUTTONS[newButton].win, A_REVERSE);

  return newButton;
}

void handleButton(WINDOW *win, int buttonID)
{
  sprintf(buttonIDstr, "%d", buttonID);
  writeOnDisplay(win, buttonIDstr, "");
}

void createButtons(WINDOW *menuwin)
{

  char EMPTY[5] = "    ";

  // column 0
  // #################################################################################
  BUTTONS[0] = createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 2,
                            "LEARN", EMPTY, menuwin, 0, 1, 0, 5);
  BUTTONS[1] = createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 2, "RAM",
                            EMPTY, menuwin, 0, 2, 1, 6);
  BUTTONS[2] = createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 2,
                            "AUTO", EMPTY, menuwin, 1, 3, 2, 7);
  BUTTONS[3] = createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 2, "BUS",
                            EMPTY, menuwin, 2, 4, 3, 8);
  BUTTONS[4] = createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 2, "ROM",
                            EMPTY, menuwin, 3, 4, 4, 9);

  // column 1
  // #############################################################################################
  BUTTONS[5] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 1 * BTN_WIDTH + 2,
                   "I/O", EMPTY, menuwin, 5, 6, 0, 25);
  BUTTONS[6] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 1 * BTN_WIDTH + 2,
                   "ROM", EMPTY, menuwin, 5, 7, 1, 10);
  BUTTONS[7] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 1 * BTN_WIDTH + 2,
                   "RAM", "LONG", menuwin, 6, 8, 2, 12);
  BUTTONS[8] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 1 * BTN_WIDTH + 2,
                   "RAM", "SHORT", menuwin, 7, 9, 3, 13);
  BUTTONS[9] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 1 * BTN_WIDTH + 2,
                   "I/O", EMPTY, menuwin, 8, 9, 4, 14);

  // column 2
  // ###############################################################################################
  BUTTONS[10] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 2 * BTN_WIDTH + 3,
                   "C", EMPTY, menuwin, 10, 11, 6, 15);
  BUTTONS[11] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 2 * BTN_WIDTH + 3,
                   "8", EMPTY, menuwin, 10, 12, 7, 16);
  BUTTONS[12] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 2 * BTN_WIDTH + 3,
                   "4", EMPTY, menuwin, 11, 13, 7, 17);
  BUTTONS[13] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 2 * BTN_WIDTH + 3,
                   "0", EMPTY, menuwin, 12, 14, 8, 18);
  BUTTONS[14] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 2 * BTN_WIDTH + 3,
                   "ENTER", "/YES", menuwin, 13, 14, 9, 19);

  // column 3
  // ##############################################################################################
  BUTTONS[15] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 3 * BTN_WIDTH + 3,
                   "D", EMPTY, menuwin, 15, 16, 10, 20);
  BUTTONS[16] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 3 * BTN_WIDTH + 3,
                   "9", EMPTY, menuwin, 15, 17, 11, 21);
  BUTTONS[17] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 3 * BTN_WIDTH + 3,
                   "5", EMPTY, menuwin, 16, 18, 12, 22);
  BUTTONS[18] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 3 * BTN_WIDTH + 3,
                   "1", EMPTY, menuwin, 17, 19, 13, 23);
  BUTTONS[19] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 3 * BTN_WIDTH + 3,
                   "CLEAR", "/NO ", menuwin, 18, 19, 14, 24);

  // column 4
  // ##############################################################################################
  BUTTONS[20] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 4 * BTN_WIDTH + 3,
                   "E", EMPTY, menuwin, 20, 21, 15, 26);
  BUTTONS[21] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 4 * BTN_WIDTH + 3,
                   "A", EMPTY, menuwin, 20, 22, 16, 27);
  BUTTONS[22] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 4 * BTN_WIDTH + 3,
                   "6", EMPTY, menuwin, 21, 23, 17, 28);
  BUTTONS[23] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 4 * BTN_WIDTH + 3,
                   "2", EMPTY, menuwin, 22, 24, 18, 29);
  BUTTONS[24] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 4 * BTN_WIDTH + 3,
                   "PRIOR", EMPTY, menuwin, 23, 24, 19, 30);

  // column 5
  // #############################################################################################
  BUTTONS[25] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "STS ", "CTL ", menuwin, 25, 26, 5, 31);
  BUTTONS[26] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "F", EMPTY, menuwin, 25, 27, 20, 32);
  BUTTONS[27] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "B", EMPTY, menuwin, 26, 28, 21, 33);
  BUTTONS[28] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "7", EMPTY, menuwin, 27, 29, 22, 34);
  BUTTONS[29] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "3", EMPTY, menuwin, 28, 30, 23, 35);
  BUTTONS[30] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 5 * BTN_WIDTH + 3,
                   "MORE", EMPTY, menuwin, 29, 30, 24, 36);

  // column 6
  // ###############################################################################################
  BUTTONS[31] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "READ", EMPTY, menuwin, 31, 32, 25, 37);
  BUTTONS[32] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "RAMP", EMPTY, menuwin, 31, 33, 26, 38);
  BUTTONS[33] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "TOGGL", "ADDR", menuwin, 32, 34, 27, 39);
  BUTTONS[34] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "CONT", EMPTY, menuwin, 33, 35, 28, 40);
  BUTTONS[35] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "RPEAT", EMPTY, menuwin, 34, 36, 29, 41);
  BUTTONS[36] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 6 * BTN_WIDTH + 4,
                   "LOOP", EMPTY, menuwin, 35, 36, 30, 42);

  // column 7
  // ###############################################################################################
  BUTTONS[37] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "WRITE", EMPTY, menuwin, 37, 38, 31, 43);
  BUTTONS[38] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "WALK", EMPTY, menuwin, 37, 39, 32, 44);
  BUTTONS[39] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "TOGGL", "DATA", menuwin, 38, 40, 33, 45);
  BUTTONS[40] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "STOP", EMPTY, menuwin, 39, 41, 34, 46);
  BUTTONS[41] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "RUN", "UUT ", menuwin, 40, 42, 35, 47);
  BUTTONS[42] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 7 * BTN_WIDTH + 4,
                   "SETUP", EMPTY, menuwin, 41, 42, 36, 48);

  // column 8
  // ################################################################################################
  BUTTONS[43] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "PROGM", EMPTY, menuwin, 43, 44, 37, 49);
  BUTTONS[44] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "IF ", EMPTY, menuwin, 43, 45, 38, 50);
  BUTTONS[45] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "DISPL", EMPTY, menuwin, 44, 46, 39, 51);
  BUTTONS[46] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "AND", EMPTY, menuwin, 45, 47, 40, 52);
  BUTTONS[47] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "OR", EMPTY, menuwin, 46, 48, 41, 53);
  BUTTONS[48] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 8 * BTN_WIDTH + 5,
                   "READ", "PROBE", menuwin, 47, 48, 42, 54);

  // column 9
  // ################################################################################################
  BUTTONS[49] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   "EXEC", EMPTY, menuwin, 49, 50, 43, 55);
  BUTTONS[50] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   ">", EMPTY, menuwin, 49, 51, 44, 56);
  BUTTONS[51] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   "LABEL", EMPTY, menuwin, 50, 52, 45, 57);
  BUTTONS[52] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   "SHIFT", "LEFT", menuwin, 51, 53, 46, 58);
  BUTTONS[53] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   "SHIFT", "RIGHT", menuwin, 52, 54, 47, 59);
  BUTTONS[54] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1, 9 * BTN_WIDTH + 5,
                   "REG", EMPTY, menuwin, 53, 54, 48, 60);

  // column 10
  // ##############################################################################################
  BUTTONS[55] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "AUX", "I/F ", menuwin, 55, 56, 49, 61);
  BUTTONS[56] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "=", EMPTY, menuwin, 55, 57, 50, 62);
  BUTTONS[57] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "GOTO", EMPTY, menuwin, 56, 58, 51, 63);
  BUTTONS[58] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "INCR", EMPTY, menuwin, 57, 59, 52, 63);
  BUTTONS[59] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 4 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "DECR", EMPTY, menuwin, 58, 60, 53, 64);
  BUTTONS[60] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1,
                   10 * BTN_WIDTH + 5, "COMPL", EMPTY, menuwin, 59, 60, 54, 65);

  // column 11
  // ###############################################################################################
  BUTTONS[61] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 0 * BTN_HEIGHT + 1,
                   11 * BTN_WIDTH + 6, "READ", "TAPE", menuwin, 61, 62, 55, 61);
  BUTTONS[62] = createButton(BTN_HEIGHT, BTN_WIDTH, 1 * BTN_HEIGHT + 1,
                             11 * BTN_WIDTH + 6, "WRITE", "TAPE", menuwin, 61,
                             63, 56, 62);
  BUTTONS[63] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 2 * BTN_HEIGHT + 2,
                   11 * BTN_WIDTH + 6, "SYNC", EMPTY, menuwin, 62, 64, 57, 63);
  BUTTONS[64] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 3 * BTN_HEIGHT + 3,
                   11 * BTN_WIDTH + 6, "HIGH", EMPTY, menuwin, 63, 65, 59, 64);
  BUTTONS[65] =
      createButton(BTN_HEIGHT, BTN_WIDTH, 5 * BTN_HEIGHT + 1,
                   11 * BTN_WIDTH + 6, "LOW", EMPTY, menuwin, 64, 65, 60, 65);

  for (int i = 0; i < (sizeof BUTTONS / sizeof BUTTONS[0]); ++i)
  {
    drawButton(i);
  }
}

void destroyButtons(void)
{

  for (int i = 0; i < (sizeof BUTTONS / sizeof BUTTONS[0]); ++i)
  {
    delwin(BUTTONS[i].win);
  }
}
