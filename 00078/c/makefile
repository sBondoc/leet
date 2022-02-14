CC = gcc
CFLAGS = -ansi -std=c99 -Wall -Wextra -pedantic
DFLAGS = -g -DDEBUG

.PHONY: all debug clean
all: bin/solution
debug: bin/solution.debug
bin/solution: src/solution.c
	$(CC) $(CFLAGS) -o $@ $<
bin/solution.debug: src/solution.c
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ $^
clean:
	rm $(wildcard bin/*)
