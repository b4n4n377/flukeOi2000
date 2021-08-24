# change application name here (executable output name)
TARGET=flukeOi2000-GUI

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
LDLIBS= -lwiringPi


# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) $(LDLIBS) -export-dynamic

OBJS=    main.o GUI_resources.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
	rm -f *.o
    
main.o:	src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) $(LDLIBS) -o main.o

GUI_resources.o:	src/GUI_resources.c
					$(CC) -c $(CCFLAGS) src/GUI_resources.c $(GTKLIB) -o GUI_resources.o
    
clean:
	rm -f *.o $(TARGET)
