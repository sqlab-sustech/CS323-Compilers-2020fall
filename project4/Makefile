CC=gcc
BIN=bin
SRC=main.c tac.c mips32.c

splc: clean
	@mkdir -p $(BIN)
	$(CC) $(SRC) -o $(BIN)/$@
clean:
	@rm -rf $(BIN)
.PHONY: clean
