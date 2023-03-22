CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -fsanitize=address
DFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g
DIR_SRC := src
DIR_BIN := bin
DIR_DBG := dbg
DIR_BUILD := $(DIR_BIN) $(DIR_DBG)
APP := solution
EXEC := $(DIR_BIN)/$(APP)
EXEC_DBG := $(DIR_DBG)/$(APP)

.phony: all run dbg rundbg clean force
all: $(EXEC)
run: $(EXEC)
	./$<
debug: $(EXEC_DBG)
rundbg: $(EXEC_DBG)
	./$<
clean: force
	rm -rf $(DIR_BUILD)
force:
$(DIR_BUILD):
	mkdir $@
$(EXEC): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(EXEC_DBG): $(DIR_SRC)/$(APP).c | $(DIR_DBG)
	$(CC) $(DFLAGS) -o $@ $<
