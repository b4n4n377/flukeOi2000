#include "menu.h"
#include <string.h>

Menu createMenu(char text[], char trigger) {
  Menu menu;
  strcpy(menu.text, text);
  menu.trigger = trigger;

  return menu;
}

MenuBar createMenuBar(WINDOW *win, Menu *menus, int numMenus) {
  MenuBar menubar;

  menubar.win = win;
  menubar.menus = menus;
  menubar.numMenus = numMenus;
  menubar.selectedMenu = -1;

  int currentPosition = 2;

  for (int i = 0; i < numMenus; i++) {
    menus[i].startX = currentPosition;
    currentPosition = currentPosition + strlen(menus[i].text) + 1;
  }

  return menubar;
}

void drawMenuBar(MenuBar *menubar, WINDOW *win) {
  for (int i = 0; i < menubar->numMenus; i++) {
    int startX = menubar->menus[i].startX;

    if (menubar->selectedMenu == i)
      wattron(win, A_STANDOUT);
    mvwprintw(win, 0, startX, menubar->menus[i].text);
    wattroff(win, A_STANDOUT);
  }
}

void handleTrigger(MenuBar *menubar, char trigger) {
  for (int i = 0; i < menubar->numMenus; i++) {
    if (trigger == menubar->menus[i].trigger) {
      menubar->selectedMenu = i;
    }
  }
}
