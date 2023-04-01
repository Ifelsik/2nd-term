CC=gcc
CFLAGS=-c -Wall
EXTERNAL_LIB=-lncurses
TEST=file.c

rk1: main.o file.o game.o
	$(CC) main.o file.o game.o -o rk1 $(EXTERNAL_LIB)

main.o: main.c
	$(CC) $(CFLAGS) main.c

file.o: src/file.c
	$(CC) $(CFLAGS) src/file.c

game.o: src/game.c
	$(CC) $(CFLAGS) src/game.c

test: $(TEST)
	$(CC) $(TEST) -o test

clear:
	rm -rf *.o rk1 test
