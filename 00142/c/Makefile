CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -fsanitize=address
DFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g
DIR_SRC := src
DIR_BIN := bin
DIR_DBG := debug
APP := solution
EXEC_DBG := $(DIR_DBG)/$(APP)
EXEC := $(DIR_BIN)/$(APP)

.phony: all run dbg rundbg clean force
all: $(EXEC)
run: $(EXEC)
	./$<
dbg: $(EXEC_DBG)
rundbg: $(EXEC_DBG)
	./$<
clean: force
	rm -rf $(DIR_BIN) $(DIR_DBG)
force:
$(DIR_BIN) $(DIR_DBG):
	mkdir $@
$(EXEC): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(EXEC_DBG): $(DIR_SRC)/$(APP).c | $(DIR_DBG)
	$(CC) $(DFLAGS) -o $@ $<
