# Makefile for achart

.PHONY: all clean test

TARGET_BIN = achart
TEST_BIN = testachart

ACHART_SRC = $(shell find src -name \*.c)
ACHART_OBJ = $(ACHART_SRC:.c=.o)

ACHART_TEST_SRC = $(shell find src -name \*.c | grep -v achart.c)
ACHART_TESTS = $(shell find test -name *.c)
ACHART_TEST_OBJ = $(ACHART_TEST_SRC:.c=.o) $(ACHART_TESTS:.c=.o)

all: $(TARGET_BIN) $(TEST_BIN)

$(TARGET_BIN): $(ACHART_OBJ)
	gcc $(ACHART_OBJ) -o $@

$(TEST_BIN): $(ACHART_TEST_OBJ)
	gcc $(ACHART_TEST_OBJ) -o $@

clean:
	rm -rf $(ACHART_OBJ) $(TEST_BIN) $(TARGET_BIN)

test: $(TEST_BIN)
	./$<

src/%.o: src/%.c
	gcc -c $< -o $@

test/%.o: test/%.c
	gcc -Isrc -c $< -o $@
