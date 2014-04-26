MOCKED = src/main.c
SOURCE := $(shell find src -name '*.c')
TESTED := $(filter-out $(MOCKED), $(SOURCE))
TESTS := $(shell find test -name '*.c')

SOURCE_OBJECTS = $(SOURCE:.c=.o)
TEST_OBJECTS = $(TESTS:.c=.o) $(TESTED:.c=.o)

CC = gcc
CFLAGS = -Wall -std=c99
CHECK = -lcheck
INCLUDE = -I include/test -I include/src -c

all: spec main

spec: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(CHECK) -o spec $(addprefix bin/, $(TEST_OBJECTS))

main: $(SOURCE_OBJECTS)
	$(CC) $(CFLAGS) -o main $(addprefix bin/, $(SOURCE_OBJECTS))

%.o: %.c
	mkdir -p bin/$(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o bin/$@ $<

clean:
	rm -rf bin

