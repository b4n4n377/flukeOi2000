#include <ncurses.h>
#ifndef MENU_H
#define MENU_H

typedef struct {
  int startX;
  char text[10];
  char trigger;
} Menu;

typedef struct {
  // int  id;
  WINDOW *win;
  Menu *menus;
  int numMenus;
  int selectedMenu;
} MenuBar;

// initialize new Menu struct
Menu createMenu(char *text, char trigger);

// inititalize new MenuBar struct
MenuBar createMenuBar(WINDOW *win, Menu *menus, int numMenus);

// draw Menubar
void drawMenuBar(MenuBar *menubar, WINDOW *win);

void handleTrigger(MenuBar *menubar, char trigger);
#endif