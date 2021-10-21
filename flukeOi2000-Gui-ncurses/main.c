#include "menu.h"
#include <ncurses.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  initscr();
  noecho();
  curs_set(0);

  if (!has_colors()) {
    return -1;
  }

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_GREEN);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax , xMax , 0, 0);
  box(win, 0, 0);

  WINDOW *displaywin = derwin(win, yMax/2 , xMax/2 , yMax/4 , xMax/4);
  box(displaywin, 0,0);
  wrefresh(displaywin);

  char *menuItems1[] = {"This is FlukeOi!2000 - not by ArcadeForge", "(E)xit"};
  //char *menuItems2[] = {"This is FlukeOi!2000 - not by ArcadeForge"};

  // create menu structs and add them to an array
  Menu menus[1] = {createMenu("(F)ile", 'F', menuItems1, 2)};
  //createMenu("About", 'A',menuItems2, 1)

  // create and initialize a menubar struct
  MenuBar menubar = createMenuBar(win, menus, 1);

  drawMenuBar(&menubar);
  wrefresh(displaywin);

  char ch;
  while (ch = wgetch(win)) {
    handleTrigger(ch);
    drawMenuBar(&menubar);
    wrefresh(displaywin);
  }


  endwin();
  return 0;
}
