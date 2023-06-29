CC=gcc
CFLAGS=-Wall -g
EXECUTABLE=a

a: main.o tools.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) main.c tools.o 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

tools.o: ./src/tools.c
	$(CC) $(CFLAGS) -c ./src/tools.c

clear:
	rm -rf *.o $(EXECUTABLE)
