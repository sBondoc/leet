DIR_SRC := src
DIR_BIN := bin
EXT_SRC := c h
APP := solution
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG

MT :=
SP := $(MT) $(MT)

EXEC := $(DIR_BIN)/$(APP)
COMPILE := $(CC) $(CFLAGS)
EXT_SRC_REGEX := \($(subst $(SP),\|,$(EXT_SRC))\)
SRC_REGEX := $(shell find -regex ".*$(DIR_SRC)\/\w+\.$(EXT_SRC_REGEX)")
SRC := $(subst ./,,$(SRC_REGEX))

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
	$(COMPILE) -o $@ $^
