// mem.c - Memory Arenas

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/mem.h"

int IsPowerOfTwo(size_t x) {
    if ((x & (x - 1)) == 0) return 1;
    else return 0;
}

size_t AlignForward(size_t type, size_t alignment) {
    size_t p, a, mod;
    int ret = IsPowerOfTwo(alignment);
    if (ret != 1) exit(EXIT_FAILURE);
    p = type;
    a = alignment;
    mod = p & (a - 1);
    if (mod != 0) p += a - mod;
    return p;
}

M_Arena ArenaInitSized(size_t capacity) {
    void* init = calloc(capacity, 1);
    M_Arena arena;
    arena.start = init;
    arena.current = init;
    arena.end = init + capacity;
    return arena;
}

M_Arena ArenaInit(void) {
    M_Arena arena = ArenaInitSized(M_ARENA_DEFAULT);
    return arena;
}

void* ArenaAlloc(M_Arena* arena, size_t size) {
    if (arena == 0) return NULL;
    size_t aligned = AlignForward(size, DEFAULT_ALIGNMENT);
    if (arena->current + aligned >= arena->end) return NULL;
    void* p = arena->current;
    arena->current += aligned;
    return p;
}

void ArenaClear(M_Arena* arena) {
    arena->current = arena->start;
}

void ArenaFree(M_Arena* arena) {
    free(arena->start);
    arena->start = NULL;
    arena->current = NULL;
    arena->end = NULL;
}
