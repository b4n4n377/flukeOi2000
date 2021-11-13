#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

BUTTON BUTTONS[BTN_SIZE];

BUTTON createButton(int height, int width,int posX, int posY, char strText1[], char strText2[], WINDOW *parent){

  BUTTON button;
  button.height = height;
  button.width = width; 

  strncpy(button.strText1,strText1,6);
  strncpy(button.strText2,strText2,6);
  button.win = derwin(parent,height,width,posX,posY); 

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

void selectButton(int buttonID)
{
      wattron(BUTTONS[buttonID].win, A_REVERSE);
      drawButton(buttonID);
      wattroff(BUTTONS[buttonID].win, A_REVERSE);
}

void createButtons(WINDOW *menuwin) {

  char EMPTY[5] ="    ";

  // column 0 #################################################################################
  BUTTONS[0] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 2, "LEARN", EMPTY, menuwin);
  BUTTONS[1] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 2, "RAM",   EMPTY, menuwin);
  BUTTONS[2] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 2, "AUTO",  EMPTY, menuwin);
  BUTTONS[3] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 2, "BUS",   EMPTY, menuwin);
  BUTTONS[4] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 2, "ROM",   EMPTY, menuwin);
  
  // column 1 #############################################################################################
  BUTTONS[5] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin);
  BUTTONS[6] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "ROM", EMPTY,   menuwin);
  BUTTONS[7] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "LONG",  menuwin);
  BUTTONS[8] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "SHORT", menuwin);
  BUTTONS[9] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin);
  
  // column 2 ###############################################################################################
  BUTTONS[10] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "C",     EMPTY,  menuwin);
  BUTTONS[11] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "8",     EMPTY,  menuwin);
  BUTTONS[12] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "4",     EMPTY,  menuwin);
  BUTTONS[13] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "0",     EMPTY,  menuwin);
  BUTTONS[14] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "ENTER", "/YES", menuwin);

  // column 3 ##############################################################################################
  BUTTONS[15] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "D",     EMPTY, menuwin);
  BUTTONS[16] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "9",     EMPTY, menuwin);
  BUTTONS[17] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "5",     EMPTY, menuwin);
  BUTTONS[18] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "1",     EMPTY, menuwin);
  BUTTONS[19] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "CLEAR", "/NO", menuwin);

  // column 4 ##############################################################################################
  BUTTONS[20] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "E",     EMPTY, menuwin);
  BUTTONS[21] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "A",     EMPTY, menuwin);
  BUTTONS[22] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "6",     EMPTY, menuwin);
  BUTTONS[23] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "2",     EMPTY, menuwin);
  BUTTONS[24] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "PRIOR", EMPTY, menuwin);

  // column 5 #############################################################################################
  BUTTONS[25] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "STS",  "CTL", menuwin);
  BUTTONS[26] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "F",    EMPTY, menuwin);
  BUTTONS[27] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "B",    EMPTY, menuwin);
  BUTTONS[28] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "7",    EMPTY, menuwin);
  BUTTONS[29] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "3",    EMPTY, menuwin);
  BUTTONS[30] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "MORE", EMPTY, menuwin);

  // column 6 ###############################################################################################
  BUTTONS[31] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "READ",  EMPTY,  menuwin);
  BUTTONS[32] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RAMP",  EMPTY,  menuwin);
  BUTTONS[33] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "TOGGL", "ADDR", menuwin);
  BUTTONS[34] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "CONT",  EMPTY,  menuwin);
  BUTTONS[35] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RPEAT", EMPTY,  menuwin);
  BUTTONS[36] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "LOOP",  EMPTY,  menuwin);
  
  // column 7 ###############################################################################################
  BUTTONS[37] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WRITE", EMPTY,  menuwin);
  BUTTONS[38] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WALK",  EMPTY,  menuwin);
  BUTTONS[39] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "TOGGL", "DATA", menuwin);
  BUTTONS[40] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "STOP",  EMPTY,  menuwin);
  BUTTONS[41] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "RUN",   "UUT",  menuwin);
  BUTTONS[42] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "SETUP", EMPTY,  menuwin);

  // column 8 ################################################################################################
  BUTTONS[43] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "PROGM", EMPTY,   menuwin);
  BUTTONS[44] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "IF",    EMPTY,   menuwin);
  BUTTONS[45] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "DISPL", EMPTY,   menuwin);
  BUTTONS[46] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "AND",   EMPTY,   menuwin);
  BUTTONS[47] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "OR",    EMPTY,   menuwin);
  BUTTONS[48] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "READ",  "PROBE", menuwin);

  // column 9 ################################################################################################
  BUTTONS[49] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "EXEC",  EMPTY,   menuwin);
  BUTTONS[50] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 9*BTN_WIDTH+5, ">",     EMPTY,   menuwin);
  BUTTONS[51] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "LABEL", EMPTY,   menuwin);
  BUTTONS[52] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "LEFT",  menuwin);
  BUTTONS[53] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "RIGHT", menuwin);
  BUTTONS[54] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "REG",   EMPTY,   menuwin);

  // column 10 ##############################################################################################
  BUTTONS[55] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "AUX",   "I/F", menuwin);
  BUTTONS[56] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "=",     EMPTY, menuwin);
  BUTTONS[57] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "GOTO",  EMPTY, menuwin);
  BUTTONS[58] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "INCR",  EMPTY, menuwin);
  BUTTONS[59] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "DECR",  EMPTY, menuwin);
  BUTTONS[60] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "COMPL", EMPTY, menuwin);

  // column 11 ###############################################################################################
  BUTTONS[61] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "READ",  "TAPE", menuwin);
  BUTTONS[62] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "WRITE", "TAPE", menuwin);
  BUTTONS[63] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+2, 11*BTN_WIDTH+6, "SYNC",  EMPTY,  menuwin);
  BUTTONS[64] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+3, 11*BTN_WIDTH+6, "HIGH",  EMPTY,  menuwin);
  BUTTONS[65] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "LOW",   EMPTY,  menuwin);

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