DIR_SRC := src
DIR_BIN := bin
APP := solution
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG

EXEC := $(DIR_BIN)/$(APP)
COMPILE := $(CC) $(CFLAGS)

SRC := $(shell find -regex ".*\/$(DIR_SRC)\/.*\.c")
SRC := $(subst ./,,$(SRC))

.phony: all run debug rundbg clean
all: $(EXEC)
run: $(EXEC)
	./$<
debug: $(EXEC)_debug
rundbg: $(EXEC)_debug
	./$<
clean:
	rm -rf $(DIR_BIN)
$(DIR_BIN):
	mkdir $@
$(EXEC): $(SRC) | $(DIR_BIN)
	$(COMPILE) -o $@ $^
$(EXEC)_debug: $(SRC) | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $^
