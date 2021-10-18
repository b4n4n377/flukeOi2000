#include "menu.h"
#include <ncurses.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  box(win, 0, 0);

  // create menu structs and add them to an array
  Menu menus[3] = {createMenu("File", 'F'), createMenu("About", 'A')};

  // create and initialize a menubar struct
  MenuBar menubar = createMenuBar(win, menus, 3);

  drawMenuBar(&menubar, win);

  char ch;
  while (ch = wgetch(win)) {
    handleTrigger(&menubar, ch);
    drawMenuBar(&menubar, win);
  }

  endwin();
  return 0;
}
