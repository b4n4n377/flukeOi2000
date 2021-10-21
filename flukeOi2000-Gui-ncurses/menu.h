#include <ncurses.h>
#ifndef MENU_H
#define MENU_H

#define NUMBER_OF_STRINGS 3
#define MAX_STRING_SIZE 100

typedef struct {
  int startX;
  char text[MAX_STRING_SIZE];
  char trigger;
  
  int numItems;
  int selectedItem;
  char menuItems[NUMBER_OF_STRINGS][ MAX_STRING_SIZE];
} Menu;

typedef struct {
  // int  id;
  WINDOW *win;
  WINDOW *menuwin;
  Menu *menus;
  int numMenus;
  int selectedMenu;
} MenuBar;

// initialize new Menu struct
Menu createMenu(char *text, char trigger, char *menuItems[], int numItems);

// inititalize new MenuBar struct
MenuBar createMenuBar(WINDOW *win, Menu *menus, int numMenus);

// draw Menubar
void drawMenuBar(MenuBar *menubar);

void drawMenu(Menu *menu, bool isSelected);

void drawMenuItems(Menu *menu);

void handleTrigger(char trigger);

void selectNextItem(Menu *menu);

void selectPreviousItem(Menu *menu);

void handleMenuSelection(Menu *menu);

void reset();
#endif