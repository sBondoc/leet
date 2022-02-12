CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic
DFLAGS := -g -DDEBUG
DIR_SRC := src
DIR_BIN := bin

.PHONY: all clean
all: $(DIR_BIN)/solution

debug: $(DIR_BIN)/solution.debug

$(DIR_BIN)/solution: $(DIR_SRC)/solution.c
	$(CC) $(CFLAGS) $< -o $@

$(DIR_BIN)/solution.debug: $(DIR_SRC)/solution.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm $(wildcard $(DIR_BIN)/*)
