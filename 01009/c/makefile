CC = gcc
CFLAGS = -std=c99 -Wall
DFLAGS = -std=c99 -Wall -g -DDEBUG

all: src/solution.c
	$(CC) $(CFLAGS) src/solution.c -o bin/solution
debug: src/solution.c
	$(CC) $(DFLAGS) src/solution.c -o bin/solution
clean:
	rm bin/*
