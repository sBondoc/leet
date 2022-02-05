CC = gcc
CFLAGS = -ansi -std=c99 -Wall
DFLAGS = -ansi -std=c99 -Wall -g

all: src/solution.c
	$(CC) $(CFLAGS) src/solution.c -o bin/solution
debug: src/solution.c
	$(CC) $(DFLAGS) src/solution.c -o bin/solution
clean:
	rm bin/*
