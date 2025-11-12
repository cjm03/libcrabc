#ifndef STR_H
#define STR_H

#include "mem.h"

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

#endif //STR_H
