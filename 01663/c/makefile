DIR_SRC := src
DIR_BIN := bin
EXT_SRC := c h
EXT_APP :=
APP := solution
EXEC := $(DIR_BIN)/$(APP)
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
COMPILE := $(CC) $(CFLAGS)

MT :=
SP := $(MT) $(MT)
EXT_SRC_REGEX := $(subst $(SP),\|,$(EXT_SRC))
PATH_SRC := $(shell find -regex ".*$(DIR_SRC)\/\w+\.\($(EXT_SRC_REGEX)\)")
SRC := $(subst ./,$(MT),$(PATH_SRC))

.phony: all run debug rundbg test clean
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
