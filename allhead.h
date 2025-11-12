#ifndef ALLHEAD_H
#define ALLHEAD_H

#include <stddef.h>
#include <stdint.h>

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
#define ArraySize(a) (sizeof(a) / sizeof(a[0]))

/////////////////
// mem.h

typedef struct M_Arena {
    uint8_t* base;
    size_t capacity;
    size_t offset;
} M_Arena;
#define DEFAULT_ALIGNMENT sizeof(void*)
#define M_ARENA_DEFAULT Kilobytes(16)
int IsPowerOfTwo(size_t x);
size_t AlignForward(size_t type, size_t alignment);
void ArenaInitSized(M_Arena* arena, size_t capacity);
void ArenaInit(M_Arena* arena);
void* ArenaAlloc(M_Arena* arena, size_t size);
size_t ArenaGetMarker(M_Arena* arena);
void ArenaRestoreToMarker(M_Arena* arena, size_t marker);
void ArenaClear(M_Arena* arena);
void ArenaFree(M_Arena* arena);

/////////////////
// str.h

typedef struct String {
    char* str;
    size_t size;
} String;
char* Strndup(char* buffer, size_t n);
char* SubstringReturn(char* str, int idx1, int idx2);
void SubstringReplace(char* str, int idx1, int idx2);
void StringUppercase(char* str, size_t n);
void StringLowercase(char* str, size_t n);
String* CreateString(char* string);
String* CreateSlicedString(String* s, size_t start_idx, size_t end_idx);
void SliceString(String* s, size_t start_idx, size_t end_idx);
String* DuplicateString(String* s);
char* GetStringData(String* s);
void PrintString(String* s);
size_t GetStringSize(String* s);
void ClearString(String* s);
void DeleteString(String* s);
String M_CreateString(M_Arena* arena, char* string);
String M_CreateSlicedString(M_Arena* arena, String* s, size_t start_idx, size_t end_idx);
char* M_GetStringData(M_Arena* arena, String* s);


#endif // ALLHEAD_H
