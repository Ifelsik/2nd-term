CC=gcc
CFLAGS=-Wall
EXECUTABLE=main

a: main.o db_utils.o file_utils.o sha-256.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) main.o db_utils.o file_utils.o sha-256.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

db_utils.o: ./src/db_utils.c
	$(CC) $(CFLAGS) -c ./src/db_utils.c

file_utils.o: ./src/file_utils.c
	$(CC) $(CFLAGS) -c ./src/file_utils.c

sha-256.o: ./sha256/sha-256.c
	$(CC) $(CFLAGS) -c ./sha256/sha-256.c
clear:
	rm -rf *.o $(EXECUTABLE)
