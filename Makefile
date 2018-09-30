CC = gcc
CFLAGS  = -Wall -Wextra -pedantic -std=c99

all: milo

milo.o: milo.c syntax.h
	$(CC) -c milo.c $(CFLAGS)

milo: milo.o
	$(CC) milo.o -o milo

clean:
	rm -rf *.o milo
