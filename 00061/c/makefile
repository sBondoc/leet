DIR_SRC := src
DIR_BIN := bin
EXT_DBG := debug
APP := solution
CC := gcc
CFLAGS := -ansi -std=c99 -Wall -Wextra -pedantic
COMPILE := $(CC) $(CFLAGS)
DFLAGS := -g -DDEBUG

.PHONY: all run debug rundbg clean
all: $(DIR_BIN)/$(APP)
run: $(DIR_BIN)/$(APP)
	./$<
debug: $(DIR_BIN)/$(APP).$(EXT_DBG)
rundbg: $(DIR_BIN)/$(APP).$(EXT_DBG)
	./$<
clean:
	rm -rf $(DIR_BIN)
$(DIR_BIN):
	mkdir $@
$(DIR_BIN)/$(APP): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) -o $@ $<
$(DIR_BIN)/$(APP).$(EXT_DBG): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $<
