#ifndef MEM_H
#define MEM_H

#include "define.h"

// Arenas

typedef struct M_Arena {
    u8* memory;
    u64 max;
    u64 alloc_position;
    u64 commit_position;
    b8 static_size;
} M_Arena;

#define M_ARENA_MAX Gigabytes(1)
#define M_ARENA_COMMIT_SIZE Kilobytes(8)

void* ArenaAlloc(M_Arena* arena, u64 size);
void* ArenaAllocZero(M_Arena* arena, u64 size);
void ArenaDealloc(M_Arena* arena, u64 size);
void ArenaDeallocTo(M_Arena* arena, u64 pos);
void* ArenaRaise(M_Arena* arena, void* ptr, u64 size);
void* ArenaAllocArraySized(M_Arena* arena, u64 elem_size, u64 count);

#define ArenaAllocArray(arena, elem_type, count) ArenaAllocArraySized(arena, sizeof(elem_type), count)

void ArenaInit(M_Arena* arena);
void ArenaInitSized(M_Arena* arena, u64 max);
void ArenaClear(M_Arena* arena);
void ArenaFree(M_Arena* arena);

typedef struct M_ArenaTemp {
    M_Arena* arena;
    u64 pos;
} M_ArenaTemp;

M_ArenaTemp ArenaBeginTemp(M_Arena* arena);
void ArenaEndTemp(M_ArenaTemp temp);

// Pools

typedef struct M_PoolFreeNode M_PoolFreeNode;
struct M_PoolFreeNode { M_PoolFreeNode* next; };

typedef struct M_Pool {
    u8* memory;
    u64 max;
    u64 commit_position;
    u64 element_size;

    M_PoolFreeNode* head;
} M_Pool;

#define M_POOL_MAX Gigabytes(1)
#define M_POOL_COMMIT_CHUNK 32

void PoolInit(M_Pool* pool, u64 element_size);
void PoolClear(M_Pool* pool);
void PoolFree(M_Pool* pool);

void* PoolAlloc(M_Pool* pool);
void PoolDealloc(M_Pool* pool, void* ptr);
void PoolDeallocRange(M_Pool* pool, void* ptr, u64 count);

#endif // MEM_H
