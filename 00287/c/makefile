DIR_SRC := src
DIR_BIN := bin
APP := solution
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
EXEC := $(DIR_BIN)/$(APP)
COMPILE := $(CC) $(CFLAGS)

SRC := $(shell find -regex ".*$(DIR_SRC)\/.*\.c")
SRC := $(subst ./,,$(SRC))

.phony: all run debug rundbg clean FORCE
all: $(EXEC)
run: $(EXEC)
	./$<
debug: $(EXEC)_debug
rundbg: $(EXEC)_debug
	./$<
clean: FORCE
	rm -rf $(DIR_BIN)
FORCE:
$(DIR_BIN):
	mkdir $@
$(EXEC): $(SRC) | $(DIR_BIN)
	$(COMPILE) -o $@ $^
$(EXEC)_debug: $(SRC) | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $^
