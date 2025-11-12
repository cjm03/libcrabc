#ifndef ALLHEAD_H
#define ALLHEAD_H

#include <stddef.h>

////////////////
// define.h

typedef unsigned    char u8; 
typedef unsigned    short u16;
typedef unsigned    int u32; 
typedef unsigned    long long u64;
typedef signed      char s8; 
typedef signed      short s16;
typedef signed      int s32; 
typedef signed      long long s64;
typedef char        i8; 
typedef short       i16;
typedef int         i32; 
typedef long long   i64;
typedef float       f32; 
typedef double      f64;
typedef u8          b8;
typedef u32         b32;
#define true 1
#define false 0
#define Gigabytes(count) (u64) (count * 1024 * 1024 * 1024)
#define Megabytes(count) (u64) (count * 1024 * 1024)
#define Kilobytes(count) (u64) (count * 1024)
#define Min(a, b) (((a)<(b))?(a):(b))
#define Max(a, b) (((a)>(b))?(a):(b))
#define MemoryCopy(d, s, z) memmove((d), (s), (z))
#define MemoryCopyStruct(d, s) MemoryCopy((d), (s), Min(sizeof(*(d)), sizeof(*(s))))
#define MemoryZero(d, z) memset((d), 0, (z))
#define MemoryZeroStruct(d, s) MemoryZero((d), sizeof(s))
#define ArraySize(a) (sizeof(a) / sizeof(a[0]))

/////////////////
// mem.h

typedef struct M_Arena {
    u8* memory;
    u64 max;
    u64 alloc_position;
    u64 commit_position;
    b8 static_size;
} M_Arena;
typedef struct M_ArenaTemp {
    M_Arena* arena;
    u64 pos;
} M_ArenaTemp;
typedef struct M_PoolFreeNode M_PoolFreeNode;
struct M_PoolFreeNode { M_PoolFreeNode* next; };
typedef struct M_Pool {
    u8* memory;
    u64 max;
    u64 commit_position;
    u64 element_size;

    M_PoolFreeNode* head;
} M_Pool;
#define M_ARENA_MAX Gigabytes(1)
#define M_ARENA_COMMIT_SIZE Kilobytes(8)
#define ArenaAllocArray(arena, elem_type, count) ArenaAllocArraySized(arena, sizeof(elem_type), count)
#define M_POOL_MAX Gigabytes(1)
#define M_POOL_COMMIT_CHUNK 32
void* ArenaAlloc(M_Arena* arena, u64 size);
void* ArenaAllocZero(M_Arena* arena, u64 size);
void ArenaDealloc(M_Arena* arena, u64 size);
void ArenaDeallocTo(M_Arena* arena, u64 pos);
void* ArenaRaise(M_Arena* arena, void* ptr, u64 size);
void* ArenaAllocArraySized(M_Arena* arena, u64 elem_size, u64 count);
void ArenaInit(M_Arena* arena);
void ArenaInitSized(M_Arena* arena, u64 max);
void ArenaClear(M_Arena* arena);
void ArenaFree(M_Arena* arena);
M_ArenaTemp ArenaBeginTemp(M_Arena* arena);
void ArenaEndTemp(M_ArenaTemp temp);
void PoolInit(M_Pool* pool, u64 element_size);
void PoolClear(M_Pool* pool);
void PoolFree(M_Pool* pool);
void* PoolAlloc(M_Pool* pool);
void PoolDealloc(M_Pool* pool, void* ptr);
void PoolDeallocRange(M_Pool* pool, void* ptr, u64 count);

/////////////////
// stdstr.h

char* Strndup(char* buffer, size_t n);
char* SubstringReturn(char* str, int idx1, int idx2);
void SubstringReplace(char* str, int idx1, int idx2);
void StringUppercase(char* str, size_t n);
void StringLowercase(char* str, size_t n);

////////////////
// str.h

typedef struct String {
    u8* str;
    u64 size;
} String;
typedef struct StringListNode {
    String str;
    struct StringListNode* next;
} StringListNode;
typedef struct StringList {
    StringListNode* first;
    StringListNode* last;
    i32 nodecount;
    u64 totalsize;
} StringList;
typedef struct StringArray {
    u32 cap;
    u32 len;
    String* elements;
} StringArray;
#define StrLit(s) (String){ .str = (u8*)(s), .size = sizeof(s) - 1 }
#define StrMake(s) (String){ .str = (u8*)(s), .size = sizeof(s) }
#define StrExpand(s) (i32)(s).size, (s).str
void StringArrayAdd(StringArray* array, String data);
String StringArrayRemove(StringArray* array, int index);
void StringArrayFree(StringArray* array);
String StrAlloc(M_Arena* arena, u64 size);
String StrCopy(M_Arena* arena, String other);
String StrConcat(M_Arena* arena, String a, String b);
String StrFromFormat(M_Arena* arena, const char* format, ...);
u64 StrSubstringReplace(String str, String needle);
u64 StrFindFirst(String str, String needle, u32 offset);
u64 StrFindLast(String str, String needle, u32 offset);
u32 StrHash(String str);

#endif // ALLHEAD_H
