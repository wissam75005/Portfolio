CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.o biblioLC.o entreeSortieLC.o
	$(CC) $(CFLAGS) -o main main.o biblioLC.o entreeSortieLC.o

main.o: main.c biblioLC.h entreeSortieLC.h
	$(CC) $(CFLAGS) -c main.c

biblioLC.o: biblioLC.c biblioLC.h
	$(CC) $(CFLAGS) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	$(CC) $(CFLAGS) -c entreeSortieLC.c

clean:
	rm -f *.o main