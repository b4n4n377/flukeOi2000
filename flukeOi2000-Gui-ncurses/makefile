OBJS	= gui.o menu.o
SOURCE	= gui.c menu.c
HEADER	= menu.h
OUT	    = gui
CC   	= gcc
FLAGS	= -g -c -Wall
LFLAGS	= -lncurses -lwiringPi

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

gui.o: src/gui.c
	$(CC) $(FLAGS) src/gui.c 

menu.o: src/menu.c
	$(CC) $(FLAGS) src/menu.c 

clean:
	rm -f $(OBJS)

cleaner:
	rm -f $(OBJS) $(OUT)  

