# Makefile

CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -pedantic -std=c99
SRC=src/mem.c src/str.c
TARGETOBJS=mem.o str.o
TARGETLIB=libcrabc.a
ATESTBIN=arenatest
STESTBIN=strtest

all: clean build

.PHONY: arenatest
arenatest:
	@if [ -f $(ATESTBIN) ]; then \
		rm -f $(ATESTBIN); \
	fi
	$(CC) $(SRC) tests/arenatest.c $(CFLAGS) -o arenatest

.PHONY: strtest
strtest:
	@if [ -f $(STESTBIN) ]; then \
		rm -f $(STESTBIN); \
	fi
	$(CC) $(SRC) tests/stringtest.c $(CFLAGS) -o strtest

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
