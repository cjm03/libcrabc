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
#define M_ARENA_MAX Gigabytes(1)
#define M_ARENA_COMMIT_SIZE Kilobytes(8)
#define ArenaAllocArray(arena, elem_type, count) ArenaAllocArraySized(arena, sizeof(elem_type), count)
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

/////////////////
// stdstr.h

char* Strndup(char* buffer, size_t n);
char* SubstringReturn(char* str, int idx1, int idx2);
void SubstringReplace(char* str, int idx1, int idx2);
void StringUppercase(char* str, size_t n);
void StringLowercase(char* str, size_t n);

/////////////////
// str.h

typedef struct String {
    char* str;
    size_t size;
} String;
String* CreateString(char* string);
String* CreateSlicedString(String* s, size_t start_idx, size_t end_idx);
void SliceString(String* s, size_t start_idx, size_t end_idx);
String* DuplicateString(String* s);
char* GetStringData(String* s);
void PrintString(String* s);
size_t GetStringSize(String* s);
void ClearString(String* s);
void DeleteString(String* s);


#endif // ALLHEAD_H
