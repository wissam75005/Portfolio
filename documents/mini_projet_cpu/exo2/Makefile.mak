CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o biblioH.o entreeSortieH.o
	gcc -Wall -g -o main main.o biblioH.o entreeSortieH.o -lm

main.o: main.c biblioH.h
	$(CC) $(CFLAGS) -c main.c

biblioH.o: biblioH.c biblioH.h
	$(CC) $(CFLAGS) -c biblioH.c

clean:
	rm -f *.o main
