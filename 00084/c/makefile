DIR_SRC := src
DIR_BIN := bin
CC := gcc
CFLAGS := -ansi -std=c99 -Wall -Wextra -pedantic
DFLAGS := -g -DDEBUG

.PHONY: all debug clean bin
all: $(DIR_BIN)/solution
debug: $(DIR_BIN)/solution.debug
$(DIR_BIN)/solution: $(DIR_SRC)/solution.c $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(DIR_BIN)/solution.debug: $(DIR_SRC)/solution.c $(DIR_BIN)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ $<
$(DIR_BIN):
	mkdir -p $@
clean:
	rm bin/*
