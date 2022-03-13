DIR_SRC := src
DIR_BIN := bin
APP := solution
CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
COMPILE := $(CC) $(CFLAGS)

.phony: all run debug rundbg clean
all: $(DIR_BIN)/$(APP)
run: $(DIR_BIN)/$(APP)
	./$<
debug: $(DIR_BIN)/$(APP)_debug
rundbg: $(DIR_BIN)/$(APP)_debug
	./$<
clean:
	rm -rf $(DIR_BIN)
$(DIR_BIN):
	mkdir $@
$(DIR_BIN)/$(APP): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) -o $@ $<
$(DIR_BIN)/$(APP)_debug: $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(COMPILE) $(DFLAGS) -o $@ $<
