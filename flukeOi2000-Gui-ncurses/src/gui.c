#include "menu.h"
#include "i2clcd.c"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {


  // LCDKram definiert in i2clcd.c
  if (wiringPiSetup () == -1) exit (1);
  fd = wiringPiI2CSetup(I2C_ADDR);
  //printf("fd = %d ", fd);
  lcd_init(); // setup LCD


  // initialize ncurses
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  cbreak();

  if ((LINES < 24) || (COLS < 80)) {
    endwin();
    puts("Your terminal needs to be at least 80x24");
    exit(2);
  }

  clear();

  // create display window above
  WINDOW *displaywin = newwin(4, 80, 0, 0);
  box(displaywin, 0, 0);
  refresh();

  // create menu window below
  WINDOW *menuwin = newwin(20, 80, 4, 0);
  box(menuwin, 0, 0);
  wrefresh(menuwin);

  createButtons(menuwin);

  writeOnDisplay(displaywin, "Welcome to FlukeOi!2000 Emulator",
                 "Copyright not by Arcadeforge!");

  // browse through the button menu
  int key;
  int buttonID = 0;
  selectButton(buttonID, KEY_UP, displaywin);

  do {
    key = getch();
    drawButton(buttonID);
    buttonID = selectButton(buttonID, key, displaywin);
  } while (key != '/');  //quit 

  // clean up and exit
  delwin(displaywin);
  delwin(menuwin);
  destroyButtons();
  endwin();
  exit(0);
}
