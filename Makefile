# Makefile for achart

TARGET_BIN = achart

SRC = $(shell find . -name \*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET_BIN)

$(TARGET_BIN): $(OBJ)
	gcc $(OBJ) -o $@

clean:
	rm -rf $(OBJ) $(TARGET_BIN)
