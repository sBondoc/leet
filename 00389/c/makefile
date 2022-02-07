CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
DFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g -DDEBUG

all: src/solution.c
	$(CC) $(CFLAGS) $< -o bin/solution
debug: src/solution.c
	$(CC) $(DFLAGS) $< -o bin/solution
clean:
	rm $(wildcard bin/*)
