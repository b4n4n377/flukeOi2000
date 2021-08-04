CC = gcc
CFLAGS = -Wall -ansi -pedantic -O2 -fomit-frame-pointer -std=c99

all: f9010

tables.h: maketables.c
	$(CC) -Wall $< -o maketables
	./maketables > $@

z80emu.o: z80emu.c z80emu.h z80config.h z80user.h \
	instructions.h macros.h tables.h
	$(CC) $(CFLAGS) -c $<

display.o: display.c display.h
	$(CC) $(CFLAGS) -c $<

keyboard.o: keyboard.c keyboard.h
	$(CC) $(CFLAGS) -c $<

pia.o: pia.c pia.h
	$(CC) $(CFLAGS) -c $<

f9010.o: f9010.c f9010.h z80emu.h z80config.h
	$(CC) -Wall -c $<

OBJECT_FILES = f9010.o z80emu.o pia.o display.o keyboard.o

f9010: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $@

clean:
	rm -f *.o f9010 maketables
