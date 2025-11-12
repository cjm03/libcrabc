#ifndef MEM_H
#define MEM_H

#include <stddef.h>
#include "../include/define.h"

#define DEFAULT_ALIGNMENT sizeof(void*)
#define M_ARENA_DEFAULT Kilobytes(16)

typedef struct M_Arena {
    void* start;
    void* current;
    void* end;
} M_Arena;

// Determine if x is a power of two
int IsPowerOfTwo(size_t x);
// Get the alignment for type aligned to alignment
size_t AlignForward(size_t type, size_t alignment);
// Allocate size bytes of memory in arena arena
void* ArenaAlloc(M_Arena* arena, size_t size);
// Create an arena of custom size
M_Arena ArenaInitSized(size_t capacity);
// Create an arena of default size (16 Kilobytes);
M_Arena ArenaInit(void);
// Clear the arena
void ArenaClear(M_Arena* arena);
// Deallocate the arena
void ArenaFree(M_Arena* arena);

#endif // MEM_H
