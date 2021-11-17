#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

BUTTON BUTTONS[BTN_SIZE];

BUTTON createButton(int height, int width,int posX, int posY, char strText1[], char strText2[], WINDOW *parent, int buttonAbove, int buttonBelow, int buttonLeft, int buttonRight){

  BUTTON button;
  button.height = height;
  button.width = width; 

  strncpy(button.strText1,strText1,6);
  strncpy(button.strText2,strText2,6);
  button.win = derwin(parent,height,width,posX,posY); 

  button.buttonAbove = buttonAbove;
  button.buttonBelow = buttonBelow;
  button.buttonLeft  = buttonLeft;
  button.buttonRight = buttonRight;  

  return button;
}


void writeOnDisplay(WINDOW *displaywin,char textLine1[], char textLine2[]){

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
  for( int i = 0; (i < strlen(textLine1)) && (i<32); i++ ){

    line1[i]=textLine1[i];
    usleep(40000);
    mvwprintw(displaywin, 1, 24, line1); 
    wrefresh(displaywin);
  }

  for( int i = 0; (i < strlen(textLine2)) && (i<32) ; i++ ){
    line2[i]=textLine2[i];
    usleep(40000);
    mvwprintw(displaywin, 2, 24, line2);
    wrefresh(displaywin);
  }
  
  wattroff(displaywin, A_REVERSE);
}

void drawButton(int buttonID) {
  box(BUTTONS[buttonID].win,0 ,0);
  mvwprintw(BUTTONS[buttonID].win, 0, 1, BUTTONS[buttonID].strText1);
  mvwprintw(BUTTONS[buttonID].win, 1, 1, BUTTONS[buttonID].strText2);
  wrefresh(BUTTONS[buttonID].win);
}

int selectButton(int buttonID, int direction)
{     
      int newButton;

      switch (direction){
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
      }
      wattron(BUTTONS[newButton].win, A_REVERSE);
      drawButton(newButton);
      wattroff(BUTTONS[newButton].win, A_REVERSE);

      return newButton;
}

void createButtons(WINDOW *menuwin) {

  char EMPTY[5] ="    ";

  // column 0 #################################################################################
  BUTTONS[0] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 2, "LEARN", EMPTY, menuwin, 0, 1, 0, 5);
  BUTTONS[1] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 2, "RAM",   EMPTY, menuwin, 0, 2, 1, 6); 
  BUTTONS[2] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 2, "AUTO",  EMPTY, menuwin, 1, 3, 2, 7);
  BUTTONS[3] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 2, "BUS",   EMPTY, menuwin, 2, 4, 3, 8);
  BUTTONS[4] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 2, "ROM",   EMPTY, menuwin, 3, 4, 4, 9);
  
  // column 1 #############################################################################################
  BUTTONS[5] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin, 5, 6, 0, 5);
  BUTTONS[6] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "ROM", EMPTY,   menuwin, 5, 7, 1, 10);
  BUTTONS[7] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "LONG",  menuwin, 6, 8, 2, 12);
  BUTTONS[8] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "SHORT", menuwin, 7, 9, 3, 13);
  BUTTONS[9] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin, 8, 9, 4, 14);
  
  // column 2 ###############################################################################################
  BUTTONS[10] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "C",     EMPTY,  menuwin, 10, 11, 6, 0);
  BUTTONS[11] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "8",     EMPTY,  menuwin, 10, 12, 11, 0);
  BUTTONS[12] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "4",     EMPTY,  menuwin, 11, 13, 7, 0);
  BUTTONS[13] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "0",     EMPTY,  menuwin, 12, 14, 8, 0);
  BUTTONS[14] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "ENTER", "/YES", menuwin, 13, 14, 9, 0);

  // column 3 ##############################################################################################
  BUTTONS[15] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "D",     EMPTY, menuwin, 15, 16, 0, 0);
  BUTTONS[16] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "9",     EMPTY, menuwin, 15, 17, 0, 0);
  BUTTONS[17] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "5",     EMPTY, menuwin, 16, 18, 0, 0);
  BUTTONS[18] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "1",     EMPTY, menuwin, 17, 19, 0, 0);
  BUTTONS[19] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "CLEAR", "/NO", menuwin, 18, 19, 0, 0);

  // column 4 ##############################################################################################
  BUTTONS[20] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "E",     EMPTY, menuwin, 20, 21, 0, 0);
  BUTTONS[21] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "A",     EMPTY, menuwin, 20, 22, 0, 0);
  BUTTONS[22] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "6",     EMPTY, menuwin, 21, 23, 0, 0);
  BUTTONS[23] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "2",     EMPTY, menuwin, 22, 24, 0, 0);
  BUTTONS[24] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "PRIOR", EMPTY, menuwin, 23, 24, 0, 0);

  // column 5 #############################################################################################
  BUTTONS[25] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "STS",  "CTL", menuwin, 25, 26, 0, 0);
  BUTTONS[26] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "F",    EMPTY, menuwin, 25, 27, 0, 0);
  BUTTONS[27] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "B",    EMPTY, menuwin, 26, 28, 0, 0);
  BUTTONS[28] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "7",    EMPTY, menuwin, 27, 29, 0, 0);
  BUTTONS[29] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "3",    EMPTY, menuwin, 28, 30, 0, 0);
  BUTTONS[30] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "MORE", EMPTY, menuwin, 29, 30, 0, 0);

  // column 6 ###############################################################################################
  BUTTONS[31] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "READ",  EMPTY,  menuwin, 31, 32, 0, 0);
  BUTTONS[32] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RAMP",  EMPTY,  menuwin, 31, 33, 0, 0);
  BUTTONS[33] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "TOGGL", "ADDR", menuwin, 32, 34, 0, 0);
  BUTTONS[34] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "CONT",  EMPTY,  menuwin, 33, 35, 0, 0);
  BUTTONS[35] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RPEAT", EMPTY,  menuwin, 34, 36, 0, 0);
  BUTTONS[36] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "LOOP",  EMPTY,  menuwin, 35, 36, 0, 0);
  
  // column 7 ###############################################################################################
  BUTTONS[37] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WRITE", EMPTY,  menuwin, 37, 38, 0, 0);
  BUTTONS[38] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WALK",  EMPTY,  menuwin, 37, 39, 0, 0);
  BUTTONS[39] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "TOGGL", "DATA", menuwin, 38, 40, 0, 0);
  BUTTONS[40] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "STOP",  EMPTY,  menuwin, 39, 41, 0, 0);
  BUTTONS[41] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "RUN",   "UUT",  menuwin, 40, 42, 0, 0);
  BUTTONS[42] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "SETUP", EMPTY,  menuwin, 41, 42, 0, 0);

  // column 8 ################################################################################################
  BUTTONS[43] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "PROGM", EMPTY,   menuwin, 43, 44, 0, 0);
  BUTTONS[44] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "IF",    EMPTY,   menuwin, 43, 45, 0, 0);
  BUTTONS[45] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "DISPL", EMPTY,   menuwin, 44, 46, 0, 0);
  BUTTONS[46] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "AND",   EMPTY,   menuwin, 45, 47, 0, 0);
  BUTTONS[47] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "OR",    EMPTY,   menuwin, 46, 48, 0, 0);
  BUTTONS[48] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "READ",  "PROBE", menuwin, 47, 48, 0, 0);

  // column 9 ################################################################################################
  BUTTONS[49] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "EXEC",  EMPTY,   menuwin, 49, 50, 0, 0);
  BUTTONS[50] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 9*BTN_WIDTH+5, ">",     EMPTY,   menuwin, 49, 51, 0, 0);
  BUTTONS[51] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "LABEL", EMPTY,   menuwin, 50, 52, 0, 0);
  BUTTONS[52] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "LEFT",  menuwin, 51, 53, 0, 0);
  BUTTONS[53] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "RIGHT", menuwin, 52, 54, 0, 0);
  BUTTONS[54] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "REG",   EMPTY,   menuwin, 53, 54, 0, 0);

  // column 10 ##############################################################################################
  BUTTONS[55] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "AUX",   "I/F", menuwin, 55, 56, 0, 0);
  BUTTONS[56] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "=",     EMPTY, menuwin, 55, 57, 0, 0);
  BUTTONS[57] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "GOTO",  EMPTY, menuwin, 56, 58, 0, 0);
  BUTTONS[58] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "INCR",  EMPTY, menuwin, 57, 59, 0, 0);
  BUTTONS[59] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "DECR",  EMPTY, menuwin, 58, 60, 0, 0);
  BUTTONS[60] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "COMPL", EMPTY, menuwin, 59, 60, 0, 0);

  // column 11 ###############################################################################################
  BUTTONS[61] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "READ",  "TAPE", menuwin, 61, 62, 0, 0);
  BUTTONS[62] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "WRITE", "TAPE", menuwin, 61, 63, 0, 0);
  BUTTONS[63] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+2, 11*BTN_WIDTH+6, "SYNC",  EMPTY,  menuwin, 62, 64, 0, 0);
  BUTTONS[64] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+3, 11*BTN_WIDTH+6, "HIGH",  EMPTY,  menuwin, 63, 65, 0, 0);
  BUTTONS[65] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "LOW",   EMPTY,  menuwin, 64, 65, 0, 0);

  for (int i = 0; i < (sizeof BUTTONS / sizeof BUTTONS[0]); ++i)
  {
    drawButton(i);
  }
}

void destroyButtons(void) {

  for (int i = 0; i < (sizeof BUTTONS / sizeof BUTTONS[0]); ++i)
  {
    delwin(BUTTONS[i].win);
  }
}