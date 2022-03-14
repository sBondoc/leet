DIR_SRC := src
DIR_BIN := bin
NAME := solution
EXT_APP :=
EXT_DBG := _debug
APP := $(NAME)$(EXT_APP)
DBG := $(NAME)$(EXT_DBG)

CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
COMPILE := $(CC) $(CFLAGS)

.phony: all run debug rundbg clean
all: $(DIR_BIN)/$(APP)
run: $(DIR_BIN)/$(APP)
	./$<
debug: $(DIR_BIN)/$(DBG)
rundbg: $(DIR_BIN)/$(DBG)
	./$<
clean:
	rm -rf $(DIR_BIN)
$(DIR_BIN):
	mkdir $@
$(DIR_BIN)/$(APP): $(DIR_SRC)/$(NAME).c | $(DIR_BIN)
	$(COMPILE) -o $@ $<
$(DIR_BIN)/$(DBG): $(DIR_SRC)/$(NAME).c | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $<
