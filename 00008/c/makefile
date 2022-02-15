DIR_SRC := src
DIR_BIN := bin
EXT_SRC := c
EXT_DBG := debug
CC := gcc
CFLAGS = -ansi -std=c99 -Wall -Wextra -pedantic
DFLAGS = -g -DDEBUG

.PHONY: all debug clean $(DIR_BIN)
all: $(DIR_BIN)/solution
debug: $(DIR_BIN)/solution.$(EXT_DBG)
clean:
	rm -f $(wildcard $(DIR_BIN)/*)
$(DIR_BIN):
	mkdir -p $@
$(DIR_BIN)/solution: $(DIR_SRC)/solution.$(EXT_SRC) $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(DIR_BIN)/solution.$(EXT_DBG): $(DIR_SRC)/solution.$(EXT_SRC) $(DIR_BIN)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ $<
