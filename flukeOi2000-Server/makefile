CC = gcc
CFLAGS = -Wall -ansi -pedantic -O2 -fomit-frame-pointer -std=c99

all: flukeOi2000-Server

tables.h: maketables.c
	$(CC) -Wall $< -o maketables
	./src/maketables > $@

z80emu.o: src/z80emu.c src/z80emu.h src/z80config.h src/z80user.h \
	src/instructions.h src/macros.h src/tables.h
	$(CC) $(CFLAGS) -c $<

display.o: src/display.c src/display.h
	$(CC) $(CFLAGS) -c $<

keyboard.o: src/keyboard.c src/keyboard.h
	$(CC) $(CFLAGS) -c $<

pia.o: src/pia.c src/pia.h
	$(CC) $(CFLAGS) -c $<

f9010.o: src/f9010.c src/f9010.h src/z80emu.h src/z80config.h
	$(CC) -Wall -c $<

OBJECT_FILES = f9010.o z80emu.o pia.o display.o keyboard.o

flukeOi2000-Server: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $@
	rm -f *.o maketables

clean:
	rm -f *.o flukeOi2000-Server maketables
