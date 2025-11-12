// mem.c - Memory Arenas

#include <stddef.h>
#include <stdint.h>
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

void ArenaInitSized(M_Arena* arena, size_t capacity) {
    if (capacity > 0) {
        uint8_t* init = calloc(capacity, 1);
        if (!init) {
            arena->capacity = 0;
            arena->offset = 0;
        } else {
            arena->base = init;
            arena->capacity = capacity;
            arena->offset = 0;
        }
    }
}

void ArenaInit(M_Arena* arena) {
    ArenaInitSized(arena, M_ARENA_DEFAULT);
}

void* ArenaAlloc(M_Arena* arena, size_t size) {
    if (arena == 0) return NULL;
    size_t aligned = AlignForward(size, DEFAULT_ALIGNMENT);
    if (arena->offset + aligned >= arena->capacity) return NULL;
    void* p = arena->base + arena->offset;
    arena->offset += aligned;
    return p;
}

size_t ArenaGetMarker(M_Arena* arena) {
    return arena->offset;
}

void ArenaRestoreToMarker(M_Arena* arena, size_t marker) {
    if (marker >= arena->offset) exit(EXIT_FAILURE);
    arena->offset = marker;
}

void ArenaClear(M_Arena* arena) {
    arena->offset = 0;
}

void ArenaFree(M_Arena* arena) {
    if (arena->base) free(arena->base);
    arena->base = NULL;
    arena->capacity = 0;
    arena->offset = 0;
}
