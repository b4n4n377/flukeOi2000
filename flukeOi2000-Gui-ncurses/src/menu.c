#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

BUTTON BUTTONS[BTN_SIZE];
char buttonIDstr[3];

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
    usleep(20000);
    mvwprintw(displaywin, 1, 24, line1); 
    wrefresh(displaywin);
  }

  for( int i = 0; (i < strlen(textLine2)) && (i<32) ; i++ ){
    line2[i]=textLine2[i];
    usleep(20000);
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


int selectButton(int buttonID, int keyPressed, WINDOW *displaywin)
{     
      int newButton;

      switch (keyPressed){

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
          handleButton(displaywin,buttonID);
          newButton = buttonID;
        break;

        // actual button mappings ------------------
        case '1':
          newButton = 0;
        break;
        case '2':
          newButton = 1;
        break;
        case '3':
          newButton = 2;
        break;
        case '4':
          newButton = 3;
        break;
        case '5': 
          newButton = 4;
        break;
        case '6':
          newButton = 5;
        break;
        case '7':
          newButton = 6;
        break;
        case '8':
          newButton = 7;
        break;
        case '9':
          newButton = 8;
        break;
        case '0':
          newButton = 9;
        break;
        case 'q':
          newButton = 10;
        break;
        case 'w':
          newButton = 11;
        break;
        case 'e':
          newButton = 12;
        break;
        case 'r':
          newButton = 13;
        break;
        case 't':
          newButton = 14;
        break;
        case 'z':
          newButton = 15;
        break;
        case 'u':
          newButton = 16;
        break;
        case 'i':
          newButton = 17;
        break;
        case 'o':
          newButton = 18;
        break;
        case 'p':
          newButton = 19;
        break;
        case 'a':
          newButton = 20;
        break;
        case 's':
          newButton = 21;
        break;
        case 'd':
          newButton = 22;
        break;
        case 'f':
          newButton = 23;
        break;
        case 'g':
          newButton = 24;
        break;
        case 'h':
          newButton = 25;
        break;
        case 'j':
          newButton = 26;
        break;
        case 'k':
          newButton = 27;
        break;
        case 'l':
          newButton = 28;
        break;
        case 'y':
          newButton = 29;
        break;
        case 'x':
          newButton = 30;
        break;
        case 'c':
          newButton = 31;
        break;
        case 'v':
          newButton = 32;
        break;
        case 'b':
          newButton = 33;
        break;
        case 'n':
          newButton = 34;
        break;
        case 'm':
          newButton = 35;
        break;
        case '!':
          newButton = 36;
        break;
        case '$':
          newButton = 37;
        break;
        case '%':
          newButton = 38;
        break;
        case '&':
          newButton = 39;
        break;
        case '/':
          newButton = 40;
        break;
        case '(':
          newButton = 41;
        break;
        case ')':
          newButton = 42;
        break;
        case '=':
          newButton = 43;
        break;
        case 'Q':
          newButton = 44;
        break;
        case 'W':
          newButton = 45;
        break;
        case 'E':
          newButton = 46;
        break;
        case 'R':
          newButton = 47;
        break;
        case 'T':
          newButton = 48;
        break;
        case 'Z':
          newButton = 49;
        break;
        case 'U':
          newButton = 50;
        break;
        case 'I':
          newButton = 51;
        break;
        case 'O':
          newButton = 52;
        break;
        case 'P':
          newButton = 53;
        break;
        case 'A':
          newButton = 54;
        break;
        case 'S':
          newButton = 55;
        break;
        case 'D':
          newButton = 56;
        break;
        case 'F':
          newButton = 57;
        break;
        case 'G':
          newButton = 58;
        break;
        case 'H':
          newButton = 59;
        break;
        case 'J':
          newButton = 60;
        break;
        case 'K':
          newButton = 61;
        break;
        case 'L':
          newButton = 62;
        break;
        case 'Y':
          newButton = 63;
        break;
        case 'X':
          newButton = 64;
        break;
        case 'C':
          newButton = 65;
        break;
    
        default:
          newButton = buttonID;
        break;
      }

      wattron(BUTTONS[newButton].win, A_REVERSE);
      drawButton(newButton);
      wattroff(BUTTONS[newButton].win, A_REVERSE);

      // handle button if eventButton
      char eventButtons[] = "1234567890qwertzuiopasdfghjklyxcvbnm!%&/()=QWERTZUIOPASDFGHJKLYXC";
      for(int i = 0; eventButtons[i] != '\0'; ++i)
      {
        if(eventButtons[i] == keyPressed)
        {
          handleButton(displaywin,newButton);
          break;
        }
      }

      return newButton;
}

void handleButton(WINDOW *win, int buttonID){
      sprintf(buttonIDstr, "%d", buttonID);
      writeOnDisplay(win, buttonIDstr, "");
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
  BUTTONS[5] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin, 5, 6, 0, 25);
  BUTTONS[6] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "ROM", EMPTY,   menuwin, 5, 7, 1, 10);
  BUTTONS[7] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "LONG",  menuwin, 6, 8, 2, 12);
  BUTTONS[8] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "RAM", "SHORT", menuwin, 7, 9, 3, 13);
  BUTTONS[9] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 1*BTN_WIDTH+2, "I/O", EMPTY,   menuwin, 8, 9, 4, 14);
  
  // column 2 ###############################################################################################
  BUTTONS[10] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "C",     EMPTY,  menuwin, 10, 11, 6, 15);
  BUTTONS[11] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "8",     EMPTY,  menuwin, 10, 12, 7, 16);
  BUTTONS[12] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "4",     EMPTY,  menuwin, 11, 13, 7, 17);
  BUTTONS[13] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "0",     EMPTY,  menuwin, 12, 14, 8, 18);
  BUTTONS[14] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 2*BTN_WIDTH+3, "ENTER", "/YES", menuwin, 13, 14, 9, 19);

  // column 3 ##############################################################################################
  BUTTONS[15] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "D",     EMPTY, menuwin, 15, 16, 10, 20);
  BUTTONS[16] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "9",     EMPTY, menuwin, 15, 17, 11, 21);
  BUTTONS[17] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "5",     EMPTY, menuwin, 16, 18, 12, 22);
  BUTTONS[18] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "1",     EMPTY, menuwin, 17, 19, 13, 23);
  BUTTONS[19] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 3*BTN_WIDTH+3, "CLEAR","/NO ", menuwin, 18, 19, 14, 24);

  // column 4 ##############################################################################################
  BUTTONS[20] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "E",     EMPTY, menuwin, 20, 21, 15, 26);
  BUTTONS[21] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "A",     EMPTY, menuwin, 20, 22, 16, 27);
  BUTTONS[22] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "6",     EMPTY, menuwin, 21, 23, 17, 28);
  BUTTONS[23] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "2",     EMPTY, menuwin, 22, 24, 18, 29);
  BUTTONS[24] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 4*BTN_WIDTH+3, "PRIOR", EMPTY, menuwin, 23, 24, 19, 30);

  // column 5 #############################################################################################
  BUTTONS[25] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "STS ", "CTL ", menuwin, 25, 26, 5, 31);
  BUTTONS[26] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "F",    EMPTY, menuwin, 25, 27, 20, 32);
  BUTTONS[27] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "B",    EMPTY, menuwin, 26, 28, 21, 33);
  BUTTONS[28] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "7",    EMPTY, menuwin, 27, 29, 22, 34);
  BUTTONS[29] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "3",    EMPTY, menuwin, 28, 30, 23, 35);
  BUTTONS[30] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 5*BTN_WIDTH+3, "MORE", EMPTY, menuwin, 29, 30, 24, 36);

  // column 6 ###############################################################################################
  BUTTONS[31] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "READ",  EMPTY,  menuwin, 31, 32, 25, 37);
  BUTTONS[32] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RAMP",  EMPTY,  menuwin, 31, 33, 26, 38);
  BUTTONS[33] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "TOGGL", "ADDR", menuwin, 32, 34, 27, 39);
  BUTTONS[34] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "CONT",  EMPTY,  menuwin, 33, 35, 28, 40);
  BUTTONS[35] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "RPEAT", EMPTY,  menuwin, 34, 36, 29, 41);
  BUTTONS[36] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 6*BTN_WIDTH+4, "LOOP",  EMPTY,  menuwin, 35, 36, 30, 42);
  
  // column 7 ###############################################################################################
  BUTTONS[37] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WRITE", EMPTY,  menuwin, 37, 38, 31, 43);
  BUTTONS[38] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "WALK",  EMPTY,  menuwin, 37, 39, 32, 44);
  BUTTONS[39] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "TOGGL", "DATA", menuwin, 38, 40, 33, 45);
  BUTTONS[40] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "STOP",  EMPTY,  menuwin, 39, 41, 34, 46);
  BUTTONS[41] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "RUN",  "UUT ",  menuwin, 40, 42, 35, 47);
  BUTTONS[42] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 7*BTN_WIDTH+4, "SETUP", EMPTY,  menuwin, 41, 42, 36, 48);

  // column 8 ################################################################################################
  BUTTONS[43] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "PROGM", EMPTY,   menuwin, 43, 44, 37, 49);
  BUTTONS[44] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "IF ",   EMPTY,   menuwin, 43, 45, 38, 50);
  BUTTONS[45] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "DISPL", EMPTY,   menuwin, 44, 46, 39, 51);
  BUTTONS[46] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "AND",   EMPTY,   menuwin, 45, 47, 40, 52);
  BUTTONS[47] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "OR",    EMPTY,   menuwin, 46, 48, 41, 53);
  BUTTONS[48] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 8*BTN_WIDTH+5, "READ",  "PROBE", menuwin, 47, 48, 42, 54);

  // column 9 ################################################################################################
  BUTTONS[49] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "EXEC",  EMPTY,   menuwin, 49, 50, 43, 55);
  BUTTONS[50] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 9*BTN_WIDTH+5, ">",     EMPTY,   menuwin, 49, 51, 44, 56);
  BUTTONS[51] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "LABEL", EMPTY,   menuwin, 50, 52, 45, 57);
  BUTTONS[52] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "LEFT",  menuwin, 51, 53, 46, 58);
  BUTTONS[53] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "SHIFT", "RIGHT", menuwin, 52, 54, 47, 59);
  BUTTONS[54] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 9*BTN_WIDTH+5, "REG",   EMPTY,   menuwin, 53, 54, 48, 60);

  // column 10 ##############################################################################################
  BUTTONS[55] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "AUX",  "I/F ", menuwin, 55, 56, 49, 61);
  BUTTONS[56] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "=",     EMPTY, menuwin, 55, 57, 50, 62);
  BUTTONS[57] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "GOTO",  EMPTY, menuwin, 56, 58, 51, 63);
  BUTTONS[58] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "INCR",  EMPTY, menuwin, 57, 59, 52, 63);
  BUTTONS[59] = createButton(BTN_HEIGHT, BTN_WIDTH, 4*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "DECR",  EMPTY, menuwin, 58, 60, 53, 64);
  BUTTONS[60] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 10*BTN_WIDTH+5, "COMPL", EMPTY, menuwin, 59, 60, 54, 65);

  // column 11 ###############################################################################################
  BUTTONS[61] = createButton(BTN_HEIGHT, BTN_WIDTH, 0*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "READ",  "TAPE", menuwin, 61, 62, 55, 61);
  BUTTONS[62] = createButton(BTN_HEIGHT, BTN_WIDTH, 1*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "WRITE", "TAPE", menuwin, 61, 63, 56, 62);
  BUTTONS[63] = createButton(BTN_HEIGHT, BTN_WIDTH, 2*BTN_HEIGHT+2, 11*BTN_WIDTH+6, "SYNC",  EMPTY,  menuwin, 62, 64, 57, 63);
  BUTTONS[64] = createButton(BTN_HEIGHT, BTN_WIDTH, 3*BTN_HEIGHT+3, 11*BTN_WIDTH+6, "HIGH",  EMPTY,  menuwin, 63, 65, 59, 64);
  BUTTONS[65] = createButton(BTN_HEIGHT, BTN_WIDTH, 5*BTN_HEIGHT+1, 11*BTN_WIDTH+6, "LOW",   EMPTY,  menuwin, 64, 65, 60, 65);

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