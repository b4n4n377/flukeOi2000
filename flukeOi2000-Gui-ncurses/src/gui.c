#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  // initialize ncurses
  initscr();
  noecho();
  curs_set(0);
  keypad (stdscr, TRUE);
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

  // browse through the button menu
  int buttonID = 0;
  selectButton(buttonID,KEY_UP);

  writeOnDisplay(displaywin, "Welcome to FlukeOi!2000 Emulator",
                 "Copyright not by Arcadeforge!");

  int key;

  do {
    key = getch();
  
    switch (key) {
    case KEY_UP:
        drawButton(buttonID);
        buttonID = selectButton(buttonID, KEY_UP);
    case KEY_DOWN:
        drawButton(buttonID);
        buttonID = selectButton(buttonID, KEY_DOWN);
    case KEY_LEFT:
        drawButton(buttonID);
        buttonID = selectButton(buttonID, KEY_LEFT);
    case KEY_RIGHT:
        drawButton(buttonID);
        buttonID = selectButton(buttonID, KEY_RIGHT);
    case 10:
        handleButton(displaywin,buttonID);
      break;
    }
  } while ((key != 'q') && (key != 'Q'));

  // clean up and exit
  delwin(displaywin);
  delwin(menuwin);
  destroyButtons();
  endwin();
  exit(0);
}