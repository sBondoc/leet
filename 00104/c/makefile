DIR_SRC := src
DIR_BIN := bin
EXT_SRC := c
EXT_DBG := debug
APP := solution
CC := gcc
CFLAGS = -ansi -std=c99 -Wall -Wextra -pedantic
DFLAGS = -g -DDEBUG

.PHONY: all debug clean $(DIR_BIN)
all: $(DIR_BIN)/$(APP)
debug: $(DIR_BIN)/$(APP).$(EXT_DBG)
$(DIR_BIN):
	mkdir -p $(DIR_BIN)
clean:
	rm -f $(wildcard $(DIR_BIN)/*)
$(DIR_BIN)/$(APP): $(DIR_SRC)/$(APP).$(EXT_SRC) $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(DIR_BIN)/$(APP).$(EXT_DBG): $(DIR_SRC)/$(APP).$(EXT_SRC) $(DIR_BIN)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ $<
