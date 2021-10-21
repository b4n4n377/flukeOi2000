#include "menu.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

MenuBar *thisMenubar;

Menu createMenu(char text[], char trigger, char *menuItems[], int numItems) {
  Menu menu;
  strcpy(menu.text, text);
  menu.trigger = trigger;
  menu.numItems = numItems;
  menu.selectedItem = 0;

  for (int i = 0; i < numItems; i++) {
    strcpy(menu.menuItems[i], menuItems[i]);
  }

  return menu;
}

MenuBar createMenuBar(WINDOW *win, Menu *menus, int numMenus) {
  MenuBar menubar;

  menubar.win = win;
  menubar.menus = menus;
  menubar.numMenus = numMenus;
  menubar.selectedMenu = -1;

  int yMax, xMax, yBeg, xBeg;
  getmaxyx(win, yMax, xMax);
  getbegyx(win, yBeg, xBeg);
  WINDOW *menuwin = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1);
  menubar.menuwin = menuwin;

  keypad(menuwin, true);
  wrefresh(menuwin);

  int currentPosition = 2;

  for (int i = 0; i < numMenus; i++) {
    menus[i].startX = currentPosition;
    currentPosition = currentPosition + strlen(menus[i].text) + 1;
  }

  return menubar;
}

void drawMenuBar(MenuBar *menubar) {

  thisMenubar = menubar;

  for (int i = 0; i < thisMenubar->numMenus; i++) {

    drawMenu(&thisMenubar->menus[i], thisMenubar->selectedMenu == i);
  }

  menubar->selectedMenu = -1;
}

void drawMenu(Menu *menu, bool isSelected) {

  int startX = menu->startX;

  if (isSelected)
    wattron(thisMenubar->win, A_STANDOUT);
  mvwprintw(thisMenubar->win, 0, startX, menu->text);
  wattroff(thisMenubar->win, A_STANDOUT);
  wrefresh(thisMenubar->win);

  int ch;

  drawMenuItems(menu);
  wrefresh(thisMenubar->menuwin);
  while (isSelected && (ch = wgetch(thisMenubar->menuwin))) {
    switch (ch) {
    case KEY_DOWN:
      selectNextItem(menu);
      break;
    case KEY_UP:
      selectPreviousItem(menu);
      break;
    case 10:
      handleMenuSelection(menu);
      break;
    default:
      isSelected = false;
    }
    drawMenuItems(menu);
  }
  werase(thisMenubar->menuwin);
  wrefresh(thisMenubar->menuwin);
  reset();
}

void drawMenuItems(Menu *menu) {

  int yMax, xMax;
  getmaxyx(thisMenubar->menuwin, yMax, xMax);

  for (int i = 0; i < menu->numItems; i++) {

    mvwprintw(thisMenubar->menuwin, i, 0, menu->menuItems[i]);

    if (menu->selectedItem == i) {
      mvwchgat(thisMenubar->menuwin, i, 0, xMax, A_NORMAL, 1, NULL);
    } else {
      mvwchgat(thisMenubar->menuwin, i, 0, xMax, A_STANDOUT, 1, NULL);
    }
  }
}

void handleTrigger(char trigger) {
  for (int i = 0; i < thisMenubar->numMenus; i++) {
    if (trigger == thisMenubar->menus[i].trigger) {
      thisMenubar->selectedMenu = i;
    }
  }
}

void selectNextItem(Menu *menu) {
  menu->selectedItem++;
  if (menu->selectedItem >= menu->numItems) {
    menu->selectedItem = 0;
  }
}

void selectPreviousItem(Menu *menu) {
  menu->selectedItem--;
  if (menu->selectedItem < 0) {
    menu->selectedItem = menu->numItems - 1;
  }
}

void handleMenuSelection(Menu *menu) {

  if (strcmp(menu->menuItems[menu->selectedItem], "(E)xit") == 0) {
    endwin();
    exit(0);
  } else if (strcmp(menu->menuItems[menu->selectedItem], "B1") == 0) {
    // mvwprintw(thisMenubar->win, 0, 40, );
    wrefresh(thisMenubar->win);
  } else /* default: */
  {
  }
}

void reset() {
  for (int i = 0; i < thisMenubar->numMenus; i++) {
    int startX = thisMenubar->menus[i].startX;
    mvwprintw(thisMenubar->win, 0, startX, thisMenubar->menus[i].text);
  }
  wrefresh(thisMenubar->win);
}