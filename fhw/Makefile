CC=gcc
CFLAGS=-g -Wall -fms-extensions
TARGET=hw


all: create_obj_dir build

test: auth.o auth_tests.o sha-256.o 
	$(CC) $(CFLAGS) auth.o auth_tests.o sha-256.o -o test

build: main.o book.o student.o student_book.o auth.o sha-256.o cli.o
	$(CC) $(CFLAGS) main.o book.o student.o student_book.o auth.o sha-256.o cli.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

sha-256.o: sha-2/sha-256.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf *.o $(TARGET) test

create_obj_dir:
	mkdir -p obj