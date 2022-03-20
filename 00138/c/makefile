DIR_SRC := src
DIR_BIN := bin
APP := solution
EXEC := $(DIR_BIN)/$(APP)
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
COMPILE := $(CC) $(CFLAGS)

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
$(EXEC): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) -o $@ $<
$(EXEC)_debug: $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $<
