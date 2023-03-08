CC := gcc
CFLAGS := -std=c11 -fsanitize=address -Wall -Wextra -Wpedantic
DFLAGS := -std=c11 -Wall -g -Wextra -Wpedantic
DIR_SRC := src
DIR_BIN := bin
APP := solution
EXEC := $(DIR_BIN)/$(APP)
SFX_DBG := _dbg
EXEC_DBG :=  $(EXEC)$(SFX_DBG)

.phony: all run dbg rundbg clean
all: $(EXEC)
run: $(EXEC)
	./$<
dbg: $(EXEC_DBG)
rundbg: $(EXEC_DBG)
	./$<
clean: FORCE
FORCE:
$(DIR_BIN):
	mkdir $@
$(EXEC): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(CC) $(CFLAGS) -o $@ $<
$(EXEC_DBG): $(DIR_SRC)/$(APP).c | $(DIR_BIN)
	$(CC) $(DFLAGS) -o $@ $<
