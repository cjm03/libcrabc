# Makefile

CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -pedantic -std=c99
SRC=src/mem.c src/stdstr.c src/str.c
TARGETOBJS=mem.o stdstr.o str.o
TARGETLIB=libcrabc.a
TESTBIN=test

all: clean build

.PHONY: test
test:
	@if [ -f $(TESTBIN) ]; then \
		rm -f $(TESTBIN); \
	fi
	$(CC) $(SRC) tests/test.c $(CFLAGS) -o test

build:
	@echo "Compiling objects..."
	$(CC) -c $(SRC) $(CFLAGS)
	@echo "Compiled objects"
	@echo "Bundling..."
	ar rcs $(TARGETLIB) $(TARGETOBJS)
	@echo "Bundling complete, generated $(TARGETLIB)"
	rm -f $(TARGETOBJS)

.PHONY: clean
clean:
	@echo "Checking for existing library..."
	@if [ -f $(TARGETLIB) ]; then \
		echo "Removing old library file $(TARGETLIB)..."; \
		rm -f $(TARGETLIB); \
	else \
		echo "$(TARGETLIB) not found"; \
	fi
